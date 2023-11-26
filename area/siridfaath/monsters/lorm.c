// -- This line is 78 characters long ----------------------------------------
#include "../../macros.h"
inherit MONSTER;

#define WSAY(X) tell_room(environment(), line_break(X, "Lorm says: ", 78))

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;

// -- Settings -------------------------------------------------------------- 

  set_short("lorm the puzzle keeper");
  set_long("A small stocky dwarf, hired by Wilhelm to keep track of the puzzles "+
  "activities in the realm. He looks grumpy even for dwarf standards.");
  
  set_name("lorm");
  set_def_name("Lorm");
  set_indef_name("Lorm");
  add_alias("dwarf");
  set_race("dwarf");
  set_gender(1);
  set_level(1);
  set_al(-50);
  add_soul();

  set_chat_chance(1);
  
// -- Responses -------------------------------------------------------------  
  
  add_response("ALL","%1 smiles %2 at you","!smile %L1");
  add_response("ALL","SAY(%1,%2)","$said(%1,%2)");
  
	
  add_chat("ALL","Lorm notes something down on the blackboard.");
  add_chat("ALL","Lorm writes something down on the blackboard.");
  add_chat("ALL","Lorm scribbles something down on the blackboard.");
  add_chat("ALL","Lorm writes something down on a small notepad.");
  add_chat("ALL","Lorm sighs.");
  add_chat("ALL","Lorm looks bored.");
  add_chat("ALL","Lorm says: I hate this job!");
  add_chat("ALL","Lorm says: Don't you have anything better to do?");
  add_chat("ALL","Lorm erases something down on the blackboard.");

}

/*
	Puzzles:
	wilhelm_merchant_key
	wilhelm_puzzle_bone
	wilhelm_bloodwood_sneak
  
*/


said (who, word) {
  if (sscanf(lower_case(word),"%*shelp%*s") == 2) {
    WSAY("With what? Be more specific, I got things to do.");
    return 1;
  }
  if (sscanf(lower_case(word),"%*sbuy%*s") == 2) {
    WSAY("Does this look like a store!?");
    return 1;
  }
  if (sscanf(lower_case(word),"%*ssiridfaath%*s") == 2) {
    WSAY("That's the small village right outside.");
    return 1;
  } 
  if (sscanf(lower_case(word),"%*sbloodwood%*s") == 2) {
    WSAY("Bloodwood is the forest far off to the west.");
    return 1;
  }
  if ((sscanf(lower_case(word),"%*skey%*s") == 2) ||
      sscanf(lower_case(word),"%*slost%*s") == 2){
  	if(this_player()->query_puzzle("wilhelm_merchant_key")) {
	WSAY("I see you found the lost key. Good work!");
	return 1;}
	else
	WSAY("Someone in the village has lost a key, ask around!");
	return 1;
  }
  if ((sscanf(lower_case(word),"%*sork%*s") == 2) ||
      sscanf(lower_case(word),"%*sangry%*s") == 2){
  	if(this_player()->query_puzzle("wilhelm_puzzle_bone")) {
	WSAY("Did you see his face?! Haha, nice work!");
	return 1;}
	else
	WSAY("Nothing more fun the pissing off and ork! Try the one in the tavern.");
	return 1;
  }
    if ((sscanf(lower_case(word),"%*spath magic%*s") == 2) ||
      sscanf(lower_case(word),"%*smagic%*s") == 2){
  	if(this_player()->query_puzzle("wilhelm_bloodwood_quest")) {
	WSAY("Wow, your like a ninja! Good work!");
	return 1;}
	else
	WSAY("I can't help you. The captain on the dock might know something.");
	return 1;
  }
      if ((sscanf(lower_case(word),"%*sgloves%*s") == 2) ||
      sscanf(lower_case(word),"%*sglove%*s") == 2){
  	if(this_player()->query_puzzle("wilhelm_bloodwood_glove")) {
	WSAY("I can't believe you helped a bloodelf!");
	write("Lorm spits.");
	return 1;}
	else
	WSAY("A bloodelf lost his gloves, do we even care?.");
	return 1;
  }
      if (sscanf(lower_case(word),"%*swilhelm%*s") == 2) {
    WSAY("Don't mention that name!");
    "/std/msg"->msg("Lorm throws a pie in \bposs face.\n");
    return 1;
  } // Say wilhelm 
}  




	
	


