#include "../../macros.h"
inherit MONSTER;

#define WSAY(X) tell_room(environment(), line_break(X, "Patrochian says: ", 78))
//#define LOGGER load_object("/players/wilhelm/simple_logger")

reset(arg) {

  ::reset(arg);
  if (arg)
    return;

  set_name("patrochian");
  set_def_name("Patrochian");
  set_indef_name("Patrochian");
  add_alias("lizard");
  add_alias("captain");
  set_race("lizardman");
  set_short("captain Patrochian");
  set_long("You are looking at the captain of the ship Breeton. She is of " +
		      "the name-giver race t'skrang. A huge human sized lizard with " +
		      "green skin. Her tail is swinging back and forth while she watches "+
			    "you thoughtfully.");
  set_level(8);
  set_gender(2);
	set_al(175);
	add_money(random(15) + 15);
  add_object("/players/wilhelm/area/siridfaath/weapons/sword");
  command("wield sword");
	
  add_response("ALL","SAY(%1,%2)","$said(%1,%2)");	 
  add_response("ALL","GOT(%1,%2)", "$handle_give(%1,%2)");

  
} 

said (who, word) {

  if ((sscanf(lower_case(word),"%*shelp%*s") == 2) && (!this_player()->query_puzzle("wilhelm_bloodwood_quest")))  {
    WSAY("Yes, I could really use the help from a brave adventurer!");
	  WSAY("Are you up for the task?");
	  this_player()->add_property("wilhelm_captain_task");
    return;
  }
  if ((sscanf(lower_case(word),"%*syes%*s") == 2) && this_player()->query_property("wilhelm_captain_task")){
    this_player()->add_property("wilhelm_captain_message", 1);
	  this_player()->add_property("wilhelm_captain_spyglass");
    call_out("help",2);
    return;
  }
  if ((sscanf(lower_case(word),"%*syes%*s") == 2)){
    WSAY("Yes, what?");
    return;
  }
  if ((sscanf(lower_case(word),"%*ssteal%*s") == 2) && (!this_player()->query_puzzle("wilhelm_bloodwood_quest"))) {
    WSAY("Yes, we need to steal it, the witch would never give it away freely.");
    return;
  }
  if ((sscanf(lower_case(word),"%*sbloodelf%*s") == 2) ||
	    (sscanf(lower_case(word),"%*sbloodelves%*s") == 2) ||
	    (sscanf(lower_case(word),"%*sblood elves%*s") == 2) ||
	    (sscanf(lower_case(word),"%*sblood elf%*s") == 2)){
        WSAY("They live in the bloodwood forest west of here.");
        return;
  }
  if (sscanf(lower_case(word),"%*sbloodwood%*s") == 2){
    WSAY("The bloodwood is a large forest west of here. ");
    return;
  }
  if ((sscanf(lower_case(word),"%*scurse%*s") == 2) || (sscanf(lower_case(word),"%*scursed%*s") == 2)){
    WSAY("They use something called path magic, blocking off access to the forest.");
    return;
  }
  if ((sscanf(lower_case(word),"%*spath magic%*s") == 2) || (sscanf(lower_case(word),"%*smagic%*s") == 2)){
    WSAY("It said that the queen has a powerful item that removes the curse. ");
	  WSAY("You only have to touch it and you can never be cursed again. Bring it to me!");
    return;
  }
  if (sscanf(lower_case(word),"%*squeen%*s") == 2){
    WSAY("Queen Alachia a bloodelf witch!");
    return;
  }
  if (sscanf(lower_case(word),"%*spalace%*s") == 2){
    WSAY("The palace is inside the bloodwood forest.");
    return;
  }
  if ((sscanf(lower_case(word),"%*sremove%*s") == 2) && (!this_player()->query_puzzle("wilhelm_bloodwood_quest"))) {
    WSAY("Moving far away from the bloodwood, should remove the curse!");
    return;
  }
  if ((sscanf(lower_case(word),"%*sexolashers%*s") == 2) || (sscanf(lower_case(word),"%*sexolasher%*s") == 2)){
    WSAY("They are the Queen's guard in the forest. Stay away from them.");
    return;
  }
  if ((sscanf(lower_case(word),"%*sblood warder%*s") == 2) || (sscanf(lower_case(word),"%*sblood warders%*s") == 2)){
    WSAY("They are the guards of the blood wood forest. Stay away from them.");
    return;
  }
  if ((sscanf(lower_case(word),"%*sitem%*s") == 2) || (sscanf(lower_case(word),"%*spowerful%*s") == 2)){
    WSAY("You only have to touch the item and you can never be cursed again.");
	  WSAY("But you need to touch it without the curse upon you.");
    return;
  }
  if ((sscanf(lower_case(word),"%*ssneak%*s") == 2) && (!this_player()->query_puzzle("wilhelm_bloodwood_quest"))) {
	  WSAY("Find a way into the forest, keeping of the path as much as you can.");
    return;
  }
}  

help() 
{
  string *chat_message;
  int i;

  if(!present(this_player())) 
    return;

  chat_message = ({
    "The blood elves have cursed my ship, making me unable to sail!",
    "I need you to steal an item for me inside the bloodwood palace.",
    "A simple touch would lift the curse!",
    "",
    "The problem is the item only works so long you not cursed yourself, and",
	  "they curse everyone who tries to set foot in their forest.",
	  "",
	  "So I need someone to sneak into the forest and steal the item for me.",
	  "",
	  "If you get caught by the Blood warders, Exolashers or for some other reason ",
	  "get cursed. Move far away from the forest and you should be able to try again.",
	  "The other occupants of the forest shouldn't be a problem. ",
	  "",
	  "Take my spyglass from top of the crows nest, it might be helpful.",
  });

  i = this_player()->query_property("wilhelm_captain_message");
  if(sizeof(chat_message) >= i ) {
    write(chat_message[i-1] + "\n");
    i++;
    this_player()->add_property("wilhelm_captain_message", i);
    call_out("help", 2);
  }
} 

handle_give(what_name,  who_name) {
  int rand;
  object what_obj, who_obj;

  what_obj = find_object(what_name);
  who_obj=find_object(who_name);
  
  if (!what_obj -> id("wilhelm_bloodwood_rose")) {
    WSAY("I am looking for a special rose. I heard it can be found close to the queen. Please bring it to me when you find it. \n");
    transfer(what_obj, this_player());
    return;
  }

  if (this_player()->query_puzzle("wilhelm_bloodwood_quest")) {
    WSAY("You have already done this quest, but thank you for doing it again. If I could, I would do it over and over again. \n");
	  transfer(what_obj, this_player());
    return;
  }
  if (this_player()->query_property("wilhelm_bloodwood_quest") && (what_obj -> id("wilhelm_bloodwood_rose"))) {
	  this_player()->set_puzzle("wilhelm_bloodwood_quest");
	  this_player() -> add_exp(2500);
	  destruct(what_obj);
	  //LOGGER -> log("puzzle", "Stole rose", this_player());
	 // write("Thank you for BETA testing!\n");
    "std/msg" -> msg("As captain Patrochian receives the magic rose, the large vines "+
	  "entangling the riverboats starts to twist and turn. Slowly seeping back into the "+
	  "water freeing the boat from the magic curse.");
    return;
  }
  if (!this_player()->query_property("wilhelm_bloodwood_quest")) {	  
	  "std/msg" -> msg("Oh NO! It seems that someone gave you this rose. You have to steal it with your bare hands! Here is the rose, make sure to give it to your loved one. \n");
    WSAY(this_player()->query_name() + ", this rose was given to you and you did not steal it yourself! Have it back.");
    transfer(what_obj, this_player());
  }
}
