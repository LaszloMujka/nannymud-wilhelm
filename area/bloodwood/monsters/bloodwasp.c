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

  set_short("a swarm of blood wasps");

  set_long("Blood wasps are aggressive insects that attack in swarms to "+
  "gather the blood they feed on. Slightly larger than ordinary wasps.");
  
  set_name("blood wasps");
  set_def_name("the blood wasps");
  set_indef_name("a blood wasps");
  add_alias("wasps");
  
  set_race("insect");
  set_gender(1);
  set_level(8);
  set_al(-200);
  set_state("init");
  

   
  
// -- Responses -------------------------------------------------------------
  
// -- Items -----------------------------------------------------------------

// -- Attacks  --------------------------------------------------------------

  add_attack("\b1PRON sting \b2PRON arm.",10,8);
 
// -- Equipment ----------------------------------------------------------


}


