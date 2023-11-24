// -- This line is 78 characters long ----------------------------------------

#include "../../macros.h"
inherit MONSTER;

#define WSAY(X) tell_room(environment(), line_break(X, "Blood warder says: ", 78))
//#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;

// -- Settings --------------------------------------------------------------

  set_short("a blood warder"),
  set_long("A long slender elf, standing guard in the forest. Every inch of "+
  "his body is covered in sharp thorns."),
  
  set_name("blood warder");
  add_alias("warder");
  
  set_race("elf");
  set_gender(1);
  set_level(14);
  set_al(-350);
  set_state("init");
    
// -- Responses -------------------------------------------------------------
  
  add_response("init","ARRIVE(%1)","$arrive(%1)", "aggressive");
  add_response("aggressive","ARRIVE(%1)","$arrive2(%1)");
  
 add_timeout("aggressive", 20, "Bloodwarder says: Strangers are not welcome here.\n",
   "init");
  
// -- Items -----------------------------------------------------------------

  add_item( ({ "thorn","thorns" }), 
    "Almost every inch of his skin is covered with thorns. Hard and sharp, "+
	"the thorns pierce his face and body with hundreds of tiny gashes.");  

	
// -- Equipment ----------------------------------------------------------
  
  add_object("/players/wilhelm/area/bloodwood/armour/hunt_boots");
  command("wear boots");
  add_object("/players/wilhelm/area/bloodwood/armour/hardened_leather");
  command("wear armour");
  add_object("/players/wilhelm/area/bloodwood/weapons/thorn_sword");
  command("wield sword");


}

arrive(who) {
  object w;

  if (!stringp(who))
    return;
  w = present(who, environment(this_object()));
  if (objectp(w) && this_player()-> query_property("wilhelm_bloodwood_quest") ) {
      return 1;      
	  }
  if (objectp(w) && this_player()-> query_property("wilhelm_bloodwood_horn") ) {
      return line_break("Warder says: You are not welcome in our forest, leave now!");      
	  }
	else
      tell_room(environment(),"Warder says: How did you sneak into our forest!\n");		
	  this_player()->add_property("wilhelm_bloodwood_horn");	
      write ("You feel cursed and the forest seems to shift.\n");
  return 1;
}




arrive2(who) {
  object w;

  if (!stringp(who))
    return;
  w = present(who, environment(this_object()));
  if (objectp(w) && this_player()-> query_property("wilhelm_bloodwood_horn") ) {
    write ("Warder says: I told you to leave!\n");
	attack_object(w);
  }
  else
	this_player()->add_property("wilhelm_bloodwood_horn");	
    attack_object(w);	  
} 


