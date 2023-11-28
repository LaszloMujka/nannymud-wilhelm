// -- This line is 78 characters long ----------------------------------------
#include "../../macros.h"
inherit MONSTER;

#define WSAY(X) tell_room(environment(), line_break(X, "Gardener says: ", 78))
//#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;

// -- Settings -------------------------------------------------------------- 

  set_short("a royal gardener");
  set_long("A long slender elf, working as a gardener in the royal gardens. "+
  "Every inch of his body is covered in sharp thorns.");
  
  set_name("gardener");
  set_def_name("the gardener");
  set_indef_name("a gardener");
  add_alias(({"groundskeeper", "keeper", "grounds keeper"})); //danny 2022-08-13 
  set_race("elf");
  set_gender(1);
  set_level(8);
  set_al(-150);
  add_money(random(40) + 15);
  set_state("INIT");
  add_soul(); 

// -- Responses -------------------------------------------------------------  
  
  add_response("ALL", "%1 smiles %2 at you","!smile %L1");
  add_response("INIT","SAY(%1,%2)","$said_i(%1,%2)");
  add_response("GLOVE","SAY(%1,%2)","$said_g(%1,%2)");
  add_response("ALL","GOT(%1,%2)", "$handle_give(%1,%2)");
  add_response("INIT","ARRIVE(%1)","$arrive(%1)");
  
}

said_i (who, word) {
  if (sscanf(lower_case(word),"%*shelp%*s") == 2) {
    WSAY("Have you seen my gloves? I can't find them anywhere.");
  }
  if (sscanf(lower_case(word),"%*sbuy%*s") == 2) {
    WSAY("I got nothing for you.");
  }
  if (sscanf(lower_case(word),"%*sglove%*s") == 2) {
    WSAY("I seem to have misplaced them, I can't work without them.");
  }
  
}

said_g (who, word) {
  if (sscanf(lower_case(word),"%*shelp%*s") == 2) {
    WSAY("I'm busy. Ask someone else.");
  }
  if (sscanf(lower_case(word),"%*sbuy%*s") == 2) {
    WSAY("I got nothing for you.");
  }
  if (sscanf(lower_case(word),"%*sglove%*s") == 2) {
    WSAY("I love my gloves, so glad I have them back.");
  }
  
}

arrive(who) {
  object w = present(who, environment(this_object()));

  if (!objectp(w))
    return;

  if (!this_player()-> query_property("wilhelm_bloodwood_horn") ) {
	  tell_room(environment(this_object()), "Luckily the gardener doesn't appear to care about you being here.\n");
	}

}

handle_give(what_name,  who_name) {
  int rand;
  object what_obj, who_obj;

  what_obj = find_object(what_name);
  who_obj=find_object(who_name);
  
  if (!what_obj -> id("wilhelm_gardener_gloves")) {
    WSAY("Thank you but I am looking for a specific set of gloves. \n");
    transfer(what_obj, this_player());
    return;
  }


  if (this_player()->query_puzzle("wilhelm_bloodwood_gloves"))  {
    WSAY("I do remember you. Once you have found my precious gloves. Here, have them back and use them wisely. \n");
    transfer(what_obj, this_player());
    return;
  }
  
  WSAY("My gloves! Thank you!\n");
  command("wear gloves");
  this_player()->set_puzzle("wilhelm_bloodwood_gloves");
  this_player() -> add_exp(500);
  set_state("GLOVE");
    //LOGGER -> log("puzzle", "Returned gloves", this_player());
  write("You feel a little more experienced.\n");

}

