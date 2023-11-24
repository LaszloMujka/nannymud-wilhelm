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

  set_short("assasin vine"),
  set_long("This vine looks just like the rest of the long twisted vines in "+
  "the forest, just that this one is alive. It twists and turns trying to loop "+
  "itself around you.");  
  
  set_name("assasin vine");
  add_alias("vine");
  
  set_race("plant");
  set_gender(1);
  set_level(9);
  set_al(-225);
  set_state("init"); 
  
  
  
// -- Responses -------------------------------------------------------------
  
// -- Items -----------------------------------------------------------------
// -- Attacks  --------------------------------------------------------------

  add_attack("\b1PRON wraps around \b2PRON.",15,8);
 
// -- Equipment ----------------------------------------------------------


}


