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

  set_short("a whirlclaw");
  set_long("A small, exceptionally quick and nimble creature. The shaggy "+
  "creature is about two feet in height, with long spindly arms that end "+
  "in sharp, wickedly curved claws.");
  
  set_name("whirlclaw");
  set_def_name("the whirlclaw");
  set_indef_name("a whirlclaw");
  add_alias("creature");
  
  set_race("monster");
  set_gender(1);
  set_level(12);
  set_al(-250);
  set_state("init");
   
  
  
// -- Responses -------------------------------------------------------------
  
// -- Items -----------------------------------------------------------------
// CLAWS that can be sold
    
// -- Equipment ----------------------------------------------------------


}

