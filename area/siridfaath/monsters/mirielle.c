#include "../../macros.h"
inherit MONSTER;

#define WSAY(X) tell_room(environment(), line_break(X, "Mirielle says: ", 78))

//child does not respond to the text - say, or the add_response actions
// -- This line is 78 characters long ----------------------------------------
void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;

  set_short("a small child");
  set_long("A short and stocky dwarf child, no more than 3 feet high. Her "+
  "skin is pinkish white and long bushy blond hair. ");

  set_name("mirielle");
  set_def_name("Mirielle");
  set_indef_name("Mirielle");
  add_alias("dwarf");
  add_alias("girl");
  add_alias("child");
  add_alias("wilhelm_mirielle");
  set_race("dwarf");
  set_gender(2);
  set_level(2);
  // set_wimpy(80); To much hassel! 
  set_al(50);
  add_soul();
  
  
  set_chat_chance(2);

  add_response("ALL","%1 smiles %2 at you","!smile %L1");
  add_response("ALL","SAY(%1,%2)","$said(%1,%2)");
  add_response("ALL","GOT(%1,%2)", "$handle_give(%1,%2)");
  
  add_object("/players/wilhelm/area/siridfaath/obj/doll");
  add_object("/players/wilhelm/area/siridfaath/obj/stone");
  
  add_attack("Mirielle says: Dad! Help!", 7, 0, 1);
  add_attack("\b1PRON slaps \b2PRON with her doll. Tibbers attack! ", 7, 0, 1);
  add_attack("\b1PRON hits \b2PRON with a small rock.", 7, 0, 1);
  
  
// -- Chats --------------------------------------------------------------

  add_chat("ALL","Mirielle dances around the well.");
  add_chat("ALL","Mirielle peeks down into the well.");
  add_chat("ALL","Mirielle throws a small rock down the well.");
  add_chat("ALL","Mirielle plays with her doll.");
  
  
}
said (who, word) {
  if (sscanf(lower_case(word),"%*shelp%*s") == 2) {
    WSAY("I lost fathers key down the well.");
	this_player()->add_property("wilhelm_cave_key");
    return 1;
  }
  if (sscanf(lower_case(word),"%*sdad%*s") == 2 ||
      sscanf(lower_case(word),"%*sfather%*s") == 2) {
    WSAY("He is working, outside the tavern.");
    return 1;
  }
  if (sscanf(lower_case(word),"%*skey%*s") == 2) {
    WSAY("It's down there, can you help me get it?");
	this_player()->add_property("wilhelm_cave_key");
    return 1;
  }
  if (sscanf(lower_case(word),"%*swell%*s") == 2) {
    WSAY("I wonder what kind of treasure is down there.");
    return 1;
  }
}

handle_give(what_name,  who_name) {
  int rand;
  object what_obj, obj, next_obj,who_obj;

  what_obj = find_object(what_name);
  who_obj=find_object(who_name);
  
  if (this_player()->query_puzzle("wilhelm_merchant_key") && (what_obj -> id("wilhelm_mkey"))) {
    WSAY("I don't think this is my fathers key, but thank you.\n");
	destruct(what_obj);
    return;
  }
  
  if (what_obj -> id("wilhelm_mkey")) {
    WSAY("My fathers key! Thank you!\n");
    destruct(what_obj);
	this_player()->set_puzzle("wilhelm_merchant_key");
	this_player() -> add_exp(1000);
	//LOGGER -> log("puzzle", "Merchant key", this_player());
	write("You feel a little more experienced.\n");
    return;
  }
}


