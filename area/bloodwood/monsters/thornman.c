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

  set_short("a thorn man"),
  set_long("An animated bundle of thorns. It has a vaguely human-like "+
  "appearance, that stands roughly six feet tall.");
  
  set_name("thorn man");
  set_def_name("the thorn man");
  set_indef_name("a thorn man");
  add_alias("thornman");
  add_alias("thorn");
  add_alias("man");
  
  set_race("magic");
  set_gender(1);
  set_level(10);
  set_al(-250);
  set_state("init"); 
  
   
  
// -- Responses -------------------------------------------------------------
  
// -- Items -----------------------------------------------------------------

// -- Attacks  --------------------------------------------------------------

// -- Equipment ----------------------------------------------------------
  add_object("/players/wilhelm/area/bloodwood/weapons/thorn_spear");
  command("wield spear");

}


