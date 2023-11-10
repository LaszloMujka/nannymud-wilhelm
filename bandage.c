inherit "/std/line/line_inherit";
#define QRN query_real_name()
#define RNAME TP->QRN
#define TO this_object()
#define TP this_player()
#include "/players/readis/defines.h"

#define FILE(X,Y,Z) write(sprintf("%-20.19s%-10s%-45s",X,Y,Z) + "\n")
#define FULL(V,W,X,Y,Z) write(sprintf("%-20.19s%-8s%-9d%-9d%-9d",V,W,X,Y,Z)+"\n")
#define SPACER(X) write(sprintf("%|75'====='s"," " + X + " ") + "\n")
#define GAP(X,Y) write(sprintf("%-6s%-20s%-1s%-48s","      ",X,":",Y)+"\n")
#define OK (member_array(RNAME,use) != -1)
#define DATE "08/09/98"
#define WIZARD "readis"

#define HOME "players/wilhelm/area/"
#define DIVIDER sprintf("%75'=='s","") + "\n"

string player;
int watching;
string loc,*use;

drop() { return 1; }

init() {
  /* Only for Readis and Firelight. Noone else should have access to
     this tool.
     Banshee */

  ::init();
  init_ihelp(ENV());
}

init_ihelp(object ob) {
  object ihelp; 
  if (!interactive(ob)) return;
  ihelp = present("ihelp",ob);
  if(objectp(ihelp))  
  { 
    ihelp->add_hook("ihelp_new_help_hook",this_object()); 
  } 
}

ihelp_new_help_hook(array,ihelp) 
{ 
    ihelp -> add_help("/players/readis/help",
    "clubs/bandage");
}

reset(arg) {
   object ob;
   ::reset(arg);
   if (arg) return;
   if (!watching) watching = 1;
   use = ({});
   use = ({"readis","firelight","diarmuid"});
   set_name("bandage");
   add_alias(({"healer","readis_bandage"}));
   set_short("the Dragon Bandage");
   set_long("@check_long()");
   add_command("cure","@heal_read()");
   add_command("curee %s","@set_heal()");
   add_command("toggle %s","@set_watching()");
   add_property("ALLOW_KHORNE_HEAL");
   add_property("never_wet");
   add_command("store %s","@store_location()");
   add_command("return","@return_location()");
   add_command("O %s","@i_check()");
   add_command("X","@exit_check()");
   add_command("IT","@item_map()");
   add_command("Open %s","@open_door()");
   add_command("Close %s","@close_door()");
   add_command("Dcount","@death_count()");
   add_command("inarea","@inarea()");
   add_command("locate","@locate()");
   add_command("GO %s","@go()");
   add_command("puzwho","@puzcheck()");
   add_command("questwho","@questcheck()");
   add_command("ww","@ww()");
   if (OK) {
      ob = clone_object("/players/readis/objects/bandage/extra_line");
      if (ob && objectp(ob)) {
         move_object(ob,TP);
       }
   }
   catch(set_line_control("/players/readis/objects/bandage/lcontrol"));
}

init_arg(string arg) {
   ::init_arg(arg);
   watching = atoi(arg);
   return 1;
}


inform_owner(string who, int priority) {
   object cl;
   
   // The priority int sets the people who
   // will hear the message.
   // Priority 1 is everyone owning a bandage.
   //           2 is everyone on the use list.
   //           3 is anything Firelight wants to be informed about.
   //           4 is anything Readis wants to be informed about.
   // I would appreciate it if you would add the arg 3 to any
      // inform notices you add, and mention them to me.
   
   cl = _next_clone(TO);
   while (cl != TO) {
      
      if (cl -> query_watching() == 2) {
         cl = _next_clone(cl);
         continue;
         }
      
      if (priority == 1) {
         tell_object(ENV(cl),"[Bandage] "+who);
         cl = _next_clone(cl);
         continue;
         }
      
      if (member_array(ENV(cl)->QRN,use) == -1) {
         cl = _next_clone(cl);
         continue;
         }
      
      if (priority == 2) {
         tell_object(ENV(cl),"[Bandage] "+who);
         cl = _next_clone(cl);
         continue;
         }
         
      
      if (priority == 3) {
         if (ENV(cl)->QRN == "wilhelm" 
               || ENV(cl)->query_watching() == 3) {
            tell_object(ENV(cl),"[Bandage] "+who);
          }
         cl = _next_clone(cl);
         continue;
         }
      
      if (priority == 4) {
         if (ENV(cl)->QRN == "firelight" || ENV(cl)->QRN == "readis") {
            tell_object(ENV(cl),"[Bandage] "+who);
          }
          }
      
      cl = _next_clone(cl);
   }
   return 1;
}


ww() {
   object player,*players;
   string name,temp,idle,away,lvl;
   int n;
   
   players = filter_array(users(),"wiz_only",TO);
   players = sort_array(players,"level_order",TO);
   
   temp = sprintf("%|75'**'s"," The Bandage Wizlist ")+"\n\n";
   
   foreach(player,players) {
      lvl = lvl_title(player->query_level());
      name = capitalize(player->QRN);
      if (player -> is_hard_invis()) {
         name = "["+name+"]";
         }
      else {
         name = (player->query_invis() ? "("+name+")" : name);
         }
      idle = idle_time(query_idle(player));
      if (stringp(player->query_away())) {
         away = player->query_away();
         }
      else away = "";
      
      temp += sprintf("  %-3s %-15s %12s %-34.34s",
         lvl,name,idle,away)+"\n";
   }
   temp += "\n";
   temp += sprintf("%|75'**'s",
      " No. of wizards logged on: "+sizeof(players)+" ")+"\n";
   write(temp);
   return 1;
}

wiz_only(object ob) {
   if (ob->query_level() < 20) return 0;
   return 1;
}

level_order(object arg1,object arg2) {
   int n,o;
   
   n = arg1->query_level();
   o = arg2->query_level();
   
   if (o>n) return 1;
   return 0;
}

lvl_title(int n) {
   string title;
   switch(n) { 
      case 1..19: 
      title = "[Mor]"; 
      break; 
      case 20: 
      title = "[Ap0]"; 
      break; 
      case 21: 
      title = "[Ap1]"; 
      break; 
      case 22: 
      title = "[Ap2]";  
      break; 
      case 23: 
      title = "[Wiz]"; 
      break; 
      case 24: 
      title = "[FWz]"; 
      break; 
      case 25: 
      title = "[SWz]"; 
      break; 
      case 26..29: 
      title = "[SkW]"; 
      break; 
      case 30: 
      title = "[RHW]"; 
      break; 
      case 33:  
      title = "[RAW]"; 
      break; 
      case 35: 
      title = "[Hig]"; 
      break; 
      case 40: 
      title = "[Arc]"; 
      break; 
      case 42: 
      title = "[Dri]"; 
      break; 
      case 50: 
      title = "[God]"; 
      break; 
      default: 
      title = "[Bug]"; 
   }
   return title;
}

idle_time(int time) {
   int days, hours, minutes, seconds;  
   string t;
   
   days = time / 86400; 
   time %= 86400; 
   
   hours = time / 3600; 
   time %= 3600; 
   
   minutes = time / 60; 
   seconds = time % 60;
   
   t = "";
   if (days) t = days+":";
   if (!hours && days) t += "00:";
   if (hours && hours <10) t += "0"+hours+":";
   if (hours > 9) t += hours+":";
   if (!minutes) t += "00:";
   if (minutes && minutes < 10) t += "0"+minutes+":";
   if (minutes > 9) t += minutes+":";
   if (!seconds) t += "00";
   if (seconds && seconds < 10) t += "0"+seconds;
   if (seconds > 9) t += seconds;
   return t;
}

open_door(foo, arg) {
   object ob;
   if (!arg) {
      notify_fail("[Bandage] Open what?\n");
      return 0;
   }
   ob = present(arg,ENV(TP));
   if (!ob) {
      notify_fail("[Bandage] Door with that name not present.\n");
      return 0;
   }
   if (!ob->id("door")) {
      notify_fail("[Bandage] Object is not a door.\n");
      return 0;
   }
   write("[Bandage] You unlock and open the door.\n");
   write("[Bandage] The code for the door is: " +
      ob->query_code() + "\n");
   ob -> set_unlocked(1);
   ob -> set_opened(1);
   return 1;
}

close_door(foo, arg) {
   object ob;
   if (!arg) {
      notify_fail("[Bandage] Close what?\n");
      return 0;
   }
   ob = present(arg,ENV(TP));
   if (!ob) {
      notify_fail("[Bandage] Door with that name not present.\n");
      return 0;
   }
   if (!ob->id("door")) {
      notify_fail("[Bandage] Object is not a door.\n");
      return 0;
   }
   write("[Bandage] You close and lock the door.\n");
   write("[Bandage] The code for the door is: " +
      ob->query_code() + "\n");
   ob -> set_unlocked(0);
   ob -> set_opened(0);
   return 1;
}

item_map() {
   mapping items;
   string tmp,item,*args;
   
   items = ([]);
   tmp = "";
   items = ENV(TP)->query_item_map();
   SPACER("The Dragon Bandage Item List");
   write("\n");
   if (!items) return 1;
   
   args = m_indices(items);
   foreach(item,args) {
      item = item+"\n";
      tmp += item;
   }
   write(sprintf("%#-75s",tmp)+"\n\n");
   SPACER("Room = "+file_name(ENV(TP)));
   return 1;
}

heal_read() {
   object read;
   if (!player) {
      player = ENV()->QRN;
   }
   write("[Bandage] You heal " + capitalize(player) + ".\n");
   read=find_player(player);
   read->heal_self(202);
   return 1;
}

set_heal(foo,arg) {
   if (!player) { player = ENV()->QRN; }
   if (!arg) {
      write("The curer is set to: " + player + ".\n");
      return 1;
   }
   player = arg;
   write("The curer is set to: " + player + ".\n");
   return 1;
}



set_watching(foo,arg) {
   string tp;
   tp = RNAME;
   if (arg == "watch") {
      if (OK) {
         if (tp != "readis") {
            if (watching == 1) { watching = 2; }
            else if (watching == 2) { watching = 1; }
          }
         else {
            if (watching < 3) watching++;
            else watching = 1;
          }
         write("You toggle the area watch state.\n");
         return 1;
       }
      
      notify_fail("You are not permitted to use this command.\n");
      return 0;
   }
   if (arg == "air") {
      if (TO->query_property("air_supply")) {
         TO->remove_property("air_supply");
         write("You toggle the air supply off.\n");
         return 1;
       }
      add_property("air_supply");
      write("You toggle the air supply on.\n");
      return 1;
   }
   if (arg == "light") {
     if (!TP->query_property("night_vision")) {
     TP->add_property("night_vision");
     write("You toggle the bandage light on.\n");
     return 1;
     }
     TP->remove_property("night_vision");
     write("You toggle the bandage light off.\n");
     return 1;
     }
   notify_fail("Toggle what?\n");
   return 0;
}

go(foo,arg) {
   string exit;
   mapping exits;
   
   exit = arg;
   if (!exit) {
      notify_fail("[Bandage] GO where?\n");
      return 0;
   }
   switch(exit) {
      case "e":
      exit = "east";
      break;
      case "n":
      exit = "north";
      break;
      case "w":
      exit = "west";
      break;
      case "s":
      exit = "south";
      break;
      case "ne":
      exit = "northeast";
      break;
      case "nw":
      exit = "northwest";
      break;
      case "se":
      exit = "southeast";
      break;
      case "sw":
      exit = "southwest";
      break;
      case "u":
      exit = "up";
      break;
      case "d":
      exit = "down";
      break;
      default:
      break;
   }
   exits = ENV(TP)->query_exits();
   if (!exits[exit]) {
      notify_fail("[Bandage] You cannot GO in that direction.\n");
      return 0;
   }
   
   write("[Bandage] Moving you "+exit+".\n");
   tell_room(ENV(TP),TPNAME + " leaves "+exit+".\n",({TP}));
   if (stringp(exits[exit][0])) {
      exit = exits[exit][0];
   }
   else {
      exit = exits[exit];
   }
   move_object(TP,load_object(exit));
   TP->look(0);
   return 1;
}

query_watching() { return watching; }

check_long() {
   string state,tp;
   state = (watching == 2 ? "are not" : "are");
   state = (watching == 3 ? "really are" : state);
   SPACER("The Dragon Bandage");
   write("   The general commands for this tool can be " +
   "found in help clubs/bandage/\n");
   if (OK) {
      write("\n");
      GAP("toggle watch","Toggle the Pern entrance check");
      GAP("Dcount","See the Pern Death Log");
      GAP("inarea","Check who is in Pern");
      GAP("locate","Find all Pernese objects on players");
      GAP("puzwho","Check which players have solved Pern puzzles");
      GAP("questwho","Check which players have solved the quest");
      write(
         "   You " + state + " watching all entrances to Pern.\n");
   }
   SPACER("Last updated: "+DATE);
   return "";
}

puzcheck() {
   string *puzzles,*puz,*done,data,p,d;
   mapping puzwho;
   int i,n,*num,s;
   object ob;
   
   puzwho = ([
         "Test":({"",0}),
         "Beds":({"",0}),
         "Boil":({"",0}),
         "Catacombs":({"",0}),
         "Eggbag":({"",0}),
         "Green poison":({"",0}),
         "Painting":({"",0}),
         "Red poison":({"",0}),
         "Serpent":({"",0}),
         "Steal egg":({"",0}),
         "Help Holdless":({"",0}),
         "Tea":({"",0})
         ]);
   
   foreach(ob,users()) {
      if (ob->query_puzzles() == 0) { continue; }
      if (ob->query_level() > 19) { continue; }
      puzzles = explode(ob->query_puzzles(),"#");
      

      if (member_array("readis_beds",puzzles) != -1) {
         puzwho["Beds"][0] += CAP(ob->QRN) + ", ";
         puzwho["Beds"][1] += 1;
         }
      if (member_array("readis_boil",puzzles) != -1) {
         puzwho["Boil"][0] += CAP(ob->QRN) + ", ";
         puzwho["Boil"][1] += 1;
         }
      if (member_array("readis_help_holdless",puzzles) != -1) {
         puzwho["Help Holdless"][0] += CAP(ob->QRN) + ", ";
         puzwho["Help Holdless"][1] += 1;
         }
      if (member_array("readis_firelight_catacombs",puzzles) != -1) {
         puzwho["Catacombs"][0] += CAP(ob->QRN) + ", ";
         puzwho["Catacombs"][1] += 1;
         }
      if (member_array("readis_firelight_eggbag",puzzles) != -1) {
         puzwho["Eggbag"][0] += CAP(ob->QRN) + ", ";
         puzwho["Eggbag"][1] += 1;
         }
      if (member_array("readis_firelight_green_poison",puzzles) != -1) {
         puzwho["Green poison"][0] += CAP(ob->QRN) + ", ";
         puzwho["Green poison"][1] += 1;
         }
      if (member_array("readis_firelight_reappraise_paintings",puzzles) != -1){
         puzwho["Painting"][0] += CAP(ob->QRN) + ", ";
         puzwho["Painting"][1] += 1;
         }
      if (member_array("readis_firelight_red_poison",puzzles) != -1) {
         puzwho["Red poison"][0] += CAP(ob->QRN) + ", ";
         puzwho["Red poison"][1] += 1;
         }
      if (member_array("readis_firelight_serpent",puzzles) != -1) {
         puzwho["Serpent"][0] += CAP(ob->QRN) + ", ";
         puzwho["Serpent"][1] += 1;
         }
      if (member_array("readis_firelight_steal_egg",puzzles) != -1) {
         puzwho["Steal egg"][0] += CAP(ob->QRN) + ", ";
         puzwho["Steal egg"][1] += 1;
         }
      
      if (member_array("readis_tea",puzzles) != -1) {
         puzwho["Tea"][0] += CAP(ob->QRN) + ", ";
         puzwho["Tea"][1] += 1;
         }
   }
   
   data = sprintf("%|75'====='s"," The Bandage Puzzle List ") + "\n";
   data += sprintf("%-20s%-=50s%-5s","Puzzle","Players","Total")+"\n";
   data += DIVIDER+"\n";
   
   puzwho = map_mapping(puzwho,"map_puz",TO);
   puz = m_indices(puzwho);
   done = m_values(puzwho);
   num = map_array(done,"map_num",TO);
   done = map_array(done,"map_done",TO);
   
   foreach(p,puz) {
      d = done[member_array(p,puz)];
      s = num[member_array(p,puz)];
      data += sprintf("%-20s%-=50s%-5d",p,d,s) + "\n";
   }
   data += DIVIDER;
   
   write(data);
   return 1;
}

questcheck() {
   object ob;
   int n;
   string who,data;
   
   who = "";
   
   foreach (ob,users()) {
   if (ob->query_level() > 19) { continue; }
      if (!ob->query_quests("readis+firelight_steal_the_golden_egg")) {
         continue;
         }
      who += CAP(ob->QRN) + ", ";
      n++;
   }
   
   if (who == "") { who = "None"; }
   data = sprintf("%|75'====='s"," The Egg Quest List ") + "\n";
   data += sprintf("%-=70s%-5s","Players","Total") + "\n";
   data += DIVIDER+"\n";
   data += sprintf("%-=65s     %-5d",who,n) + "\n";
   data += DIVIDER;
   write(data);
   
   who = "";
   n = 0;
   
   foreach (ob,users()) {
   if (ob->query_level() > 19) { continue; }
      if (!ob->query_quests("readis+firelight_retrieve_aquarians_son")) {
         continue;
         }
      who += CAP(ob->QRN) + ", ";
      n++;
   }
   
   if (who == "") { who = "None"; }
   write("\n");
   data = sprintf("%|75'====='s"," The Aquarian Quest List ") + "\n";
   data += sprintf("%-=70s%-5s","Players","Total") + "\n";
   data += DIVIDER+"\n";
   data += sprintf("%-=65s     %-5d",who,n) + "\n";
   data += DIVIDER;
   write(data);
   return 1;
}

map_puz(mixed *arg) {
   if (arg[1] == 0) return ({"None",0});
   return arg;
}   

map_num(string *arg) {
   return arg[1];
}

map_done(string *arg) {
   return arg[0];
}

extra_look() {
   if (ENV()->QRN == "readis") {
      return ENV()->QN + " is thinking of a way his dragon "+
      "could eat " + TPNAME;
   }
   return ENV()->QN + " likes frottage";
}

store_location(foo,arg) {
   if (!arg) {
      notify_fail("[Bandage] Store where?\n");
      return 0;
   }
   if (arg == "list") {
      if (!loc) {
         write("[Bandage] No location stored.\n");
         return 1;
       }
      write("[Bandage] Location stored:\n" +
         "          " + loc->short() + "\n          " +
         "File name: " + file_name(loc) + ".\n");
      return 1;
   }
   if (arg == "loc") {
      loc = file_name(ENV(TP));
      write("[Bandage] Location stored.\n");
      return 1;
   }
   notify_fail("[Bandage] Store where?\n");
   return 0;
}

return_location() {
   if (!loc) {
      notify_fail("[Bandage] No location stored.\n");
      return 0;
   }
   write("[Bandage] Moving you to your stored location.\n");
   TP->move_player("X",load_object(loc));
   return 1;
}

i_check(foo,arg) {
   inventory_checker(arg);
   return 1;
}

inventory_checker(string arg) {
   string flag,name,type,a,c,str;
   int n,class,val,wt;
   mixed *inv,obj;
   if (!arg) { 
      obj = TP;
      name = RNAME;
   }
   else {
      n = sscanf(arg,"-%s %s",flag,name);
      if (n != 2) name = arg;
      if (flag == "f" || flag == "fl") {
         obj = find_object(expand_file_name(name));
         if (!obj) {
            write("[Bandage] Object not found!\n");
            return 1;
          }
      }
      else { 
         obj = find_player(name); 
         if (!obj) {
            write("[Bandage] Player not found!\n");
            return 1;
         }
      }
   }
   inv = deep_inventory(obj);
   inv = map_array(inv,"inv_map",TO) - ({0});
   if (sizeof(inv) < 1) {
      str = (name == RNAME ? "You are " : capitalize(name)+" is ");
      write("[Bandage] "+str+"not carrying any interesting " +
         "objects.\n");
      return 1;
   }
   name = (obj == TP ? "Your" : obj->QN+"'s");
   SPACER(name+" inventory");
   if (flag == "l" || flag == "fl") { 
      FILE("Name","Type","Filename"); 
   }
   else {
      write(sprintf("%-20s%-8s%-9s%-9s%-9s",
            "Name","Type","Class","Value","Weight")+"\n");
      write("\n");
   }
   for (n=0; n<sizeof(inv); n++) {
      if (inv[n]->is_armour()) {
         type = "Armour";
         class = inv[n]->armour_class();
         val = inv[n]->query_value();
         wt = inv[n]->query_weight();
        }      
      else if (inv[n]->is_weapon()) {
         type = "Weapon";
         class = inv[n]->weapon_class();
         val = inv[n]->query_value();
         wt = inv[n]->query_weight();      
        }
      else {
         type = "Object";
         class = 0;
         val = inv[n]->query_value();
         wt = inv[n]->query_weight();
        } 
      a = inv[n]->QN;
      if (!stringp(a)) continue;
      if (class == 0 && val == 0 && wt == 0) continue;
      if (flag == "l" || flag == "fl") {
         c = file_name(inv[n]);
         FILE(a,type,c);
         continue;
        }
      FULL(a,type,class,val,wt);
      continue;
   }
   SPACER(ctime(time()));
   return 1;
}

inv_map(object ob) {
   int n;
   string *list;
   list = ({"chaos helmet","xan_f_special","chaos boots",
         "chaos gloves","chaos platemail","skin"});
   if (function_exists("query_auto_load",ob)) { return 0; }
   for (n=0; n<sizeof(list); n++) {
      if (ob->id(list[n])) return 0;
      continue;
   }
   if (!stringp(ob->QN)) return 0;
   return ob;
}

exit_check() {
   mapping ex;
   mixed *val;
   string dir;
   ex = ([]);
   ex = ENV(TP)->query_exits();
   SPACER("The Dragon Bandage Exit Check");
   write("\n");
   if (!mappingp(ex) || !m_sizeof(ex)) {  // Titleist was here 990815
      write("[Bandage] There are no exits from this room.\n");
   }
   else {
      foreach(dir,m_indices(ex)) {
         if (!stringp(dir)) continue;
         if (!stringp(ex[dir])) {
            GAP(dir,ex[dir][0]);
            continue;
            }
         
         GAP(dir,ex[dir]);
      }
   }
   write("\n");
   SPACER("Room = "+file_name(ENV(TP)));
   return 1;
}

death_count() {
   string dead;
   if (!OK) {
      write("You are not allowed to use this command.\n");
      remove_command("Dcount");
      return 1;
   }
   dead = read_file("/players/readis/logger/logs/deaths.log");
   write("[Bandage] The following have died in Pern:\n");
   write(DIVIDER);
   write(dead);
   write(DIVIDER);
   return 1;
}

inarea() 
{
   object *arr, player;
   string guild;
   
   arr = filter_array(users(), "local_only", this_object(), HOME + "%*s");
   
   if (!sizeof(arr)) 
      {
      write("[Bandage] The area is empty at the moment.\n");
      return 1;
   }
   
   else 
      {
      write("[Bandage] The following people are in Pern:\n");
      write(DIVIDER);
      write(sprintf("  %-18s%-37s%-10s","Name","Location","Guild")+
         "\n");
      write(DIVIDER);
      
      foreach (player, arr) 
      {
         guild = player->getenv("GUILD");
         if (!guild) {
            guild = "None";
            }
         if (player->query_level() > 19) {
            guild = "Wizard";
            }
         guild = capitalize(guild);
         write(sprintf("  %-18s%-37s%-10s",
               capitalize(player->query_real_name()),
               replace(file_name(environment(player)),HOME,"~/"),
               guild)+"\n");
      }
   }
   
   write("\n");
   return 1;
}

int local_only(mixed player, string match) 
{
   if (!objectp(player)) return 0;
   
   if (sscanf(file_name(environment(player)),match))
      return 1;
}

locate()
{  
   object user, items, it, item;
   int n_found;
   string founditems, fn;
   
   if (!OK) {
      write("You are not allowed to use this command.\n");
      remove_command("locate");
      return 1;
   }
   
   founditems = "[Bandage] These items were found on Players:\n";
   founditems += DIVIDER;
   
   foreach (user, users())
   {
      items = deep_inventory(user);
      
      foreach(it, items)
      {
         if (WIZARD != "" && creator(it) != WIZARD) continue;
         if (user -> query_level() >= 20) continue;
         
         founditems += sprintf("<%d>  ", user->query_level());
         founditems += sprintf("%-14s", capitalize(user->query_real_name()));
         founditems += sprintf("%-20s", (it->query_name()||it->short())[0..12]);
         
         fn = file_name(it);
         fn = replace(fn, HOME, "~/");
         founditems += sprintf("%-20s\n", fn);
         
         n_found++;
         }
   }  
   
   founditems += DIVIDER;
   
   if (!n_found)
      {
      founditems = "";
   }
   
   founditems+="\n[Bandage] These items have been sold in the Shop:\n";
   founditems += DIVIDER;
   
   foreach (item, all_inventory(load_object("/room/store")))
   {
      
      if (creator(item) == WIZARD)
         {
         founditems += sprintf("%-20s", item->query_name());
         founditems += sprintf("%-20s",(item -> query_value()+"")[0..10]);
         
         fn = file_name(item);
         fn = replace(fn, "players/"+WIZARD, "~");
         founditems += sprintf("%-20s\n", fn);      
         }
   }
   
   founditems += DIVIDER + "\n";
   
   this_player() -> simplemore(founditems);
   this_player() -> flush();
   return 1;
}
