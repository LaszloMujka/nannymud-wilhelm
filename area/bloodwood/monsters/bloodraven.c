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

  set_short("a blood raven");

  set_long("The blood raven can be distinguished from normal ravens by his "+
  "much larger size and reddish legs. It is observing your every move with "+
  "dark red eyes. ");
  
  set_name("blood raven");
  set_def_name("the blood raven");
  set_indef_name("a blood raven");
  add_alias("raven");
  
  set_race("raven");
  set_gender(1);
  set_level(8);
  set_al(-200);
  set_state("init");
  
  
  
  
// -- Responses -------------------------------------------------------------
  
// -- Items -----------------------------------------------------------------
// -- Attacks  --------------------------------------------------------------

  add_attack("\b1PRON pecks \b2PRON eyes.",15,8);
 
// -- Equipment ----------------------------------------------------------


}


