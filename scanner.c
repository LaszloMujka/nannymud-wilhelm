#ifdef 0
// ~vincent/obj/scanner, dlm: 6/14/98
inherit "std/basic_thing";

object loc,target,owner;
string cname,file;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("scanner");
  set_short("A magic life-form scanner");
  set_long("This scanner lets you monitor living characters.\n"+
        "Commands:\n"+
	" clean		    - clean the room of getable objects\n"+
	" clones <object>   - locate all the clones of an object\n"+
	" find/findl <name> - locate a player/npc\n"+
	" guild <name>      - player locations in guild <name>\n"+
	" input <filename>  - append text lines to a file\n"+
	" lighting <n>	    - adjust light level by <n>\n"+
	" props <object>    - list the properties of an object\n"+
	" puzzles <player>  - list puzzles solved by player.\n"+
	" quests <player>   - list quests solved by player.\n"+
	" room [<area>]     - player locations [only in <area>]\n"+
	" stats [host]      - player stats [ip/hostname]\n"+
	" track <name>      - track player movements\n");
  set_value(0);
} /* reset */

void init() {

  add_action("clean","clean");
  add_action("clones","clones");
  add_action("find","find");
  add_action("find","findl");
  add_action("input","input");
  add_action("light","lighting");
  add_action("props","props");
  add_action("quest","puzzles");
  add_action("quest","quests");
  add_action("room","guild");
  add_action("room","room");
  add_action("stat","stats");
  add_action("track","track");
  */
} 

// string query_auto_load() {return "/players/vincent/obj/scanner:";}

int drop() { return 1; }

int sort_lvl(object arg1, object arg2) {
  int l1,l2;
  l1= arg1->query_level(); l2= arg2->query_level();
  if(l1<l2) return 1;
  if(l1>l2) return 0;
  return arg1->query_real_name() > arg2->query_real_name();
} /* sort_lvl */

int clean(string arg) {
object *inv,obj;
int cnt;
  if(arg) return 0;
  inv= all_inventory(environment(this_player())); /* Room contents */
  cnt= 0;
  foreach(obj,inv) if(obj->get()) {destruct(obj); cnt++;}
  write("Cleaned "+cnt+" objects.\n");
  return 1;
} /* clean */

int clones(string arg) {
object first,obj,env;
string path;
int n;
  if(!arg) return notify_fail("Clones of what?\n"),0;
  if((obj=present(arg,this_player())) ||
	(obj=present(arg,environment(this_player())))) {
    obj= find_object(path=explode(file_name(obj),"#")[0]);
  }
  else obj= find_object(path=expand_file_name(arg));
  if(!obj) return write(arg+" not found.\n"),1;
  write("Clones of "+path+" :");
  for(n=0,first=obj;(obj=_next_clone(obj)) && obj!=first;n++) {
    if(!(path=obj->query_name())) path=obj->short();
    write("\n#"+explode(file_name(obj),"#")[1]+" "+path);
    for(env=obj;env=environment(env);) {
      if(!(path=env->query_name())) path=file_name(env);
      write("->"+path);
    }
  }
  write("\n"+n+" clones found.\n");
  return 1;
} /* clones */

int find(string arg) {
object chr,loc;
  if(!arg) return notify_fail("Find who?\n"),0;
  chr= find_living(lower_case(arg));
  if(!chr) return write(arg+" not found.\n"),1;
  loc= environment(chr);       /* Get current location */
  if(!loc) return write(arg+" is no longer here.\n"),1;
  write(capitalize(arg)+" found in "+loc->short()+".\n");
  write("("+file_name(loc)+")\n");
  if(query_verb()=="findl") this_player()->display_look(loc,1);
  return 1;
} /* find */

void heart_beat() {
object loc2;
  if(!target) {
    set_heart_beat(0);
    tell_object(owner,cname+" is no longer living here.\n");
    return;
    }
  loc2= environment(target);       /* Get current location */
  if(loc2!=loc) tell_object(owner,
        "("+file_name(loc2)+") "+loc2->short()+".\n");
  loc= loc2;
} /* heart_beat */

void input_line(string arg) {
  if(arg=="**") return;	/* EOF? */
  write_file(file,arg+"\n");
  write("] ");
  input_to("input_line");
}

int input(string arg) {
  if(!arg) return notify_fail("Input file?\n"),0;
  file= expand_file_name(arg);	/* Save the filename */
  write("Appending to "+file+"\nEnd input with '**':\n] ");
  input_to("input_line");
  return 1;
} /* input */

int light(string arg) {
int lvl;
 lvl= stringp(arg) ? atoi(arg) : 0; /* Change lighting? */
  lvl= add_light(lvl);	/* Set new lighting and get result */
  write("Lighting is now "+lvl+".\n");
  return 1;
} /* light */

int props(string arg) {
string p,*plist,l;
object obj,env;
mixed v,i;
  notify_fail("Props of what?\n");
  env= environment(this_player());
  if(!arg) obj=env;
  else if(!(obj=present(arg)) && !(obj=present(arg,env))) return 0;
  write("Properties of "+obj->short()+":\n");
  plist= obj->query_property();
  if(plist && sizeof(plist)>0) foreach(p,plist) {
    v= obj->query_property(p);
    if(objectp(v)) v= "("+(v->query_name())+")";
    else if(pointerp(v)) {
      l= "";
      foreach(i,v) l+= (l=="") ? "({"+i : ","+i ;
      v= l+"})";
    }
    write("  "+p+": "+v+"\n");
  } else write("  <none>\n");
  return 1;
} /* props */

int quest(string arg) {
object player;
string list,*elist,*name;
  if(!arg) return notify_fail("Check what player?\n"),0;
  name= explode(arg," "); /* There may be a second argument */
  if(!(player=find_player(lower_case(name[0]))))
	return write(arg+" not found.\n"),1;
  if(query_verb()=="quests") list=player->query_quests();
  else list=player->query_puzzles();
  if(!list) write(capitalize(name[0])+" hasn't solved any "+query_verb()+".\n");
  else {
    elist= explode(list,"#");
    if(sizeof(name)>1) elist= regexp(elist,name[1]);
    if(!sizeof(elist)) write(capitalize(name[0])+" hasn't solved any "+
	query_verb()+" containing '"+name[1]+"'.\n");
    else write(capitalize(name[0])+" has solved these "+query_verb()+":\n"+
	line_break(implode(elist,", "),"  "));
  }
  return 1;
} /* quest */

int room(string arg) {
int nbr,i,len;
string lname,guild,gname;
object *usr,chr,loc,go;
  if(query_verb()=="guild") {if(!(gname=arg)) return 0;}
  else if(arg) len= strlen(arg);
  usr= users();		/* Get array of current users */
  usr= sort_array(usr,"sort_lvl",this_object()); /* Sort by level/name */
  foreach(chr,usr) {	/* Process list */
    if(!(loc=environment(chr))) continue; /* Get current location */
    lname= file_name(loc);	/* Get location name */
    if(lname[0..7]=="players/") lname= lname[8..99]; /* Abbreviate? */
    if(len && arg!=extract(lname,0,len-1)) continue; /* Skip user? */
    go= present("guild_mark",chr); /* Got guild object? */
    guild= go ? go->query_guild() : "none"; /* Guild name */
    if(gname && guild!=gname) continue; /* Select by guild? */
    write(sprintf("%02d %-11s %-10s %s\n",chr->query_level(),
	capitalize(chr->query_real_name()),guild,lname));
  }
  return 1;
} /* room */

/* patch users.guild_mark query_guild
   mktable users present("guild_mark",x)
*/

int stat(string arg) {
  int nbr,i,lvl,pl,sl;
  string wname,name;
  object *usr,chr,loc;

  sl= arg ? atoi(arg) : 0;
  usr= users();		/* Get array of current users */
  usr= sort_array(usr,"sort_lvl",this_object()); /* Sort by level/name */
  nbr= sizeof(usr);	/* User count */
  if(arg=="host") write("Lvl Name       IP number        Host\n");
  else write("Lv G Name(*=pk)  Str Dex Con Int  HP/max  SP/max"+
		"   QP     Exp    Gold T/2/Par\n");
  for(i=0;i<nbr;i++) {	/* Process list */
    if(!(chr=usr[i])) continue; /* Get next user */
    lvl= chr->query_level();
    name= capitalize(chr->query_real_name());
    if(arg=="host") write(sprintf(" %02d %-10s %-16s %s\n",
	lvl, name, query_ip_number(chr), query_ip_name(chr)));
    else {
      if(wname=chr->query_secondchar()) {if(!stringp(wname)) wname= "2nd";}
      else if(chr->query_testchar()) wname= "test";
      else wname= "";
      pl= chr->query_paragon();
      if(!arg || (arg=="s" && wname!="" && wname!="test") ||
		(arg=="t" && wname=="test") || (arg=="p" && pl) ||
		(arg=="w" && (wname!="" || lvl>19)) ||
		(sl && lvl>=sl && lvl<20)) {
	if(pl) wname+= "("+chr->query_paragon_level()+")";
	write(sprintf(
	"%02d %s %-12s %2d  %2d  %2d  %2d %3d/%3d %3d/%3d %4d %7d %7d %s\n",
	lvl, extract(chr->query_gender_string(),0,0),
	name+(chr->query_playerkilling()?"*":" "),
	chr->query_str(), chr->query_dex(), chr->query_con(), chr->query_int(),
	chr->query_hp(),chr->query_max_hp(),chr->query_sp(),chr->query_max_sp(),
	chr->query_cached_quest_points(),chr->query_exp(),
	chr->query_money(), wname));
  } } }
  return 1;
} /* stat */

int track(string arg) {
  set_heart_beat(0);
  if(!arg) return write("Tracking cancelled\n"),1;
  target= find_living(lower_case(arg));
  if(!target) return write(arg+" not found.\n"),1;
  owner= this_player();
  cname= target->query_name();
  write("Tracking "+cname+":\n");
  heart_beat();
  set_heart_beat(1);
  return 1;
} /* track */

