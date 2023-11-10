// -- This line is 78 characters long ----------------------------------------
inherit "/std/state_monster";

#define WSAY(X) tell_room(environment(), line_break(X, "Gardener says: ", 78))
#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;

// -- Settings -------------------------------------------------------------- 

  set_short("a royal groundskeeper");
  set_long("A long slender elf, working as a gardener in the royal gardens. "+
  "Every inch of his body is covered in sharp thorns.");
  
  set_name("the groundskeeper");
  add_alias("gardener");
  add_alias(({"groundskeeper", "keeper", "grounds keeper"})); //danny 2022-08-13 
  set_race("elf");
  set_gender(1);
  set_level(8);
  set_al(-150);
  add_money(random(40) + 15);
  set_state("INIT");
  add_soul();

  add_hook("die_hook", this_object());
  add_hook("kill_hook", this_object());   

// -- Responses -------------------------------------------------------------  
  
  add_response("ALL", "%1 smiles %2 at you","!smile %L1");
  add_response("INIT","SAY(%1,%2)","$said_i(%1,%2)");
  add_response("GLOVE","SAY(%1,%2)","$said_g(%1,%2)");
  add_response("ALL","GOT(%1,%2)", "$handle_give(%1,%2)");
  add_response("INIT","ARRIVE(%1)","$arrive(%1)");
  
  add_hook("die_hook", this_object());
  add_hook("kill_hook", this_object());
}

said_i (who, word) {
  if (sscanf(lower_case(word),"%*shelp%*s") == 2) {
    WSAY("Have you seen my gloves? I can't find them anywhere.");
    return 1;
  }
  if (sscanf(lower_case(word),"%*sbuy%*s") == 2) {
    WSAY("I got nothing for you.");
    return 1;
  }
  if (sscanf(lower_case(word),"%*sgloves%*s") == 2) {
    WSAY("I seem to have misplaced them, I can't work without them.");
    return 1;
  }
  
}

said_g (who, word) {
  if (sscanf(lower_case(word),"%*shelp%*s") == 2) {
    WSAY("I'm busy. Ask someone else.");
    return 1;
  }
  if (sscanf(lower_case(word),"%*sbuy%*s") == 2) {
    WSAY("I got nothing for you.");
    return 1;
  }
  if (sscanf(lower_case(word),"%*sgloves%*s") == 2) {
    WSAY("I love my gloves, so glad I have them back.");
    return 1;
  }
  
}

arrive(who) {
  object w;

  if (!stringp(who))
    return;
  w = present(who, environment(this_object()));
  if (objectp(w) && this_player()-> query_property("wilhelm_bloodwood_quest")) {
    return 1;  
	}
  if (objectp(w) && this_player()-> query_puzzle("wilhelm_bloodwood_quest")) {
    return 1;  
	}
  if (objectp(w) && !this_player()-> query_property("wilhelm_bloodwood_horn") ) {
	  tell_room(environment(this_object()), "Luckily the gardener doesn't appear to care about you being here.\n");
    return 1;  
	}
}

handle_give(what_name,  who_name) {
  int rand;
  object what_obj, obj, next_obj,who_obj;

  what_obj = find_object(what_name);
  who_obj=find_object(who_name);
  
  if (this_player()->query_puzzle("wilhelm_bloodwood_gloves") && (what_obj -> id("wilhelm_gardener_gloves"))) {
    WSAY("I don't think this is my gloves\n");
  	transfer(what_obj, environment());
    return;
  }
  
  if (what_obj -> id("wilhelm_gardener_gloves")) {
    WSAY("My gloves! Thank you!\n");
    command("wear gloves");
    this_player()->set_puzzle("wilhelm_bloodwood_gloves");
    this_player() -> add_exp(500);
    set_state("GLOVE");
    LOGGER -> log("puzzle", "Returned gloves", this_player());
    write("You feel a little more experienced.\n");
    return;
  }
}

die_hook(data, who) {
  LOGGER -> log("kills", "killed gardener ", data[0]);
}

kill_hook(data, who) {
  LOGGER -> log("deaths", "killed by gardener ", data[0]);
}
