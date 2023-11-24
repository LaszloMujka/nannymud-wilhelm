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

  set_short("a ethandrille"),
  set_long("A wolf-like native to the Blood Wood. It resembles a small "+
  "wolf, with brown-gray fur. Thorns grow around its mouth, and more thorns "+
  "stretch its fur. It looks like it's in pain from the brambles. ");
  
  set_name("ethandrille");
  add_alias("wolf");
  
  set_race("wolf");
  set_gender(1);
  set_level(12);
  set_al(-300);
  set_state("init");
   
// -- Responses -------------------------------------------------------------
  
// -- Items -----------------------------------------------------------------

// -- Attacks  --------------------------------------------------------------

  add_attack("\b1PRON bites \b2PRON.",15,8);
 
// -- Equipment ----------------------------------------------------------


}


