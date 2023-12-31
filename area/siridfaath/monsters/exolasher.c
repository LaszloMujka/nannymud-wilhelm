// -- This line is 78 characters long ----------------------------------------

#include "../../macros.h"
inherit MONSTER;

//#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;

// -- Settings --------------------------------------------------------------

  set_short("exolasher");

  set_long("The exolashers serve as personal guards for Qheen Alachia. Every inch "+
  "of his body is covered in sharp thorns.");
  
  set_name("exolasher");
  set_def_name("Exolasher");
  set_indef_name("Exolasher");
  add_alias("guard");
  
  set_race("elf");
  set_gender(1);
  set_level(16);
  set_al(-400);
  set_state("init");
   
  
   
  
  
// -- Responses -------------------------------------------------------------
  add_response("init","ARRIVE(%1)","$arrive(%1)");
  //add_response("aggressive","ARRIVE(%1)","$arrive(%1)");

  
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

// arrive(who) {
//   object ob,w;

//   if (!stringp(who))
//     return;
//   w = present(who, environment(this_object()));
//   foreach (ob, deep_inventory(this_player())) 
//   if (ob -> id("wilhelm_bloodwood_rose")) {
// 	attack_object(w);	  	
// 	return line_break(" Exolasher says: Thief!");
//     }
//   if (objectp(w) && this_player()-> query_property("wilhelm_bloodwood_quest") ) {
//       return 1;      
// 	  }
//   if (objectp(w) && this_player()-> query_property("wilhelm_bloodwood_horn") ) {
//       return line_break("Exolasher says: You are not welcome in our forest, leave now!");      
// 	  }
// 	else 
// 	  tell_room(environment(),"Exolasher says: How did you sneak into our forest!\n");
// 	  this_player()->add_property("wilhelm_bloodwood_horn");	
//       write ("You feel cursed and the forest seems to shift.\n");
//   return 1;
// }

arrive(who) {
  object  w = present(who, environment(this_object()));
  object ob;

  if (!objectp(w))
    return;

  foreach (ob, deep_inventory(this_player())) 
  if (ob -> id("wilhelm_bloodwood_rose")) { 	
	  "std/msg" -> msg("Exolasher yells: Thief!\n");
    attack_object(w);
    return;
  }

  if (this_player()-> query_puzzle("wilhelm_bloodwood_quest") ) {
    return;      
	}
  if (this_player()-> query_property("wilhelm_bloodwood_horn") ) {
    write("Exolasher says: You are not welcome in our forest, leave now! \n");  
    return;
	}
  tell_room(environment(),"Exolasher says: How did you sneak into our forest!\n");		
	this_player()->add_property("wilhelm_bloodwood_horn");	
  write ("You feel cursed and the forest seems to shift.\n");
}