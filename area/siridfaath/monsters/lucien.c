// -- This line is 78 characters long ----------------------------------------
inherit "/std/state_monster";

#define WSAY(X) tell_room(environment(), line_break(X, "Lucien says: ", 78))
#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;

// -- Settings -------------------------------------------------------------- 

  set_short("lucien the dwarf merchant");
  set_long("This is Lucien an old dwarf merchant that travels around Barasive, "+
  "selling goods. He has stopped outside this village tavern and is unloading "+
  "goods from his wagon.");
  
  set_name("lucien");
  add_alias("dwarf");
  add_alias("merchant");
  set_race("dwarf");
  set_gender(1);
  set_level(8);
  set_al(150);
  add_money(random(40) + 15);
  set_state("init");
  add_soul();

// -- Responses -------------------------------------------------------------  
  
  add_response("ALL", "%1 smiles %2 at you","!smile %L1");
  add_response("ALL","SAY(%1,%2)","$said(%1,%2)");
  add_response("ALL","GOT(%1,%2)", "$handle_give(%1,%2)");
  
  add_hook("die_hook", this_object());
  add_hook("kill_hook", this_object());
}
said (who, word) {
  if (sscanf(lower_case(word),"%*shelp%*s") == 2) {
    WSAY("Ask someone else! Can't you see I'm busy?");
    return 1;
  }
  if (sscanf(lower_case(word),"%*sbuy%*s") == 2) {
    WSAY("I got nothing for you.");
    return 1;
  }
  if (sscanf(lower_case(word),"%*skey%*s") == 2) {
    WSAY("I seem to have misplaced it, have you seen any keys around?");
	this_player()->add_property("wilhelm_cave_key");
    return 1;
  }
  if (sscanf(lower_case(word),"%*swagon%*s") == 2 ||
      sscanf(lower_case(word),"%*scart%*s") == 2) {
    WSAY("Please don't touch anything.");
    return 1;
  }  
  if (sscanf(lower_case(word),"%*smirielle%*s") == 2 ||
      sscanf(lower_case(word),"%*schild%*s") == 2) {
    WSAY("She sure is beautiful, just like her mother.");
    return 1;
  }    
}

handle_give(what_name,  who_name) {
  int rand;
  object what_obj, obj, next_obj,who_obj;

  what_obj = find_object(what_name);
  who_obj=find_object(who_name);
  
  if (this_player()->query_puzzle("wilhelm_merchant_key") && (what_obj -> id("wilhelm_mkey"))) {
    WSAY("I don't think this is my key, but thank you.\n");
	destruct(what_obj);
    return;
  }
  
  if (what_obj -> id("wilhelm_mkey")) {
    WSAY("My key! Thank you!\n");
    destruct(what_obj);
	this_player()->set_puzzle("wilhelm_merchant_key");
	this_player() -> add_exp(1000);
	LOGGER -> log("puzzle", "Merchant key", this_player());
	write("You feel a little more experienced.\n");
    return;
  }
}

die_hook(data, who) {
  LOGGER -> log("kills", "killed Lucien", data[0]);
}
kill_hook(data, who) {
  LOGGER -> log("deaths", "killed by Lucien", data[0]);
}
