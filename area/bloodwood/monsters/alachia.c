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

  set_short("alachia, the elf queen"),
  set_long("A long slender elf, watching you carefully. Her beauty is "+
  "legendary undiminished by the tiny thorns that pierce her delicate skin."),
  
  set_name("alachia");
  add_alias("queen");
  
  set_race("elf");
  set_gender(2);
  set_level(20);
  set_al(-500);
  set_state("init");
  
  add_hook("die_hook", this_object());
  add_hook("kill_hook", this_object());
  add_response("init","ARRIVE(%1)","$arrive(%1)");  
  
 
  
// -- Responses -------------------------------------------------------------
  
// -- Items -----------------------------------------------------------------

  add_item( ({ "thorn","thorns" }), 
    "Almost every inch of her skin is covered with thorns. Hard and sharp, "+
	"the thorns pierce her face and body with hundreds of tiny gashes.");  

	
// -- Equipment ----------------------------------------------------------
  add_object("/players/wilhelm/area/bloodwood/armour/blood_amulet");
  command("wear amulet");
  add_object("/players/wilhelm/area/bloodwood/armour/thorn_ring");
  command("wear ring");

}


arrive(who) {
  object ob,w;
  w = present(who, environment(this_object()));
  foreach (ob, deep_inventory(this_player())) 
    if (ob -> id("wilhelm_bloodwood_rose")) {
	attack_object(w);	  	
	return line_break(" Queen says: How did you steal my rose! Guards!");}
    }


