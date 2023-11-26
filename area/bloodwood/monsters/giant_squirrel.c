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

  set_short("a giant carnivorous squirrel");
  set_def_name("the giant carnivorous squirrel");
  set_indef_name("a giant carnivorous squirrel");
  set_long("A massive rodent, nearly five times the size of an ordinary squirrel.");
  
  set_name("carnivorous squirrel");
  set_def_name("the carnivorous squirrel");
  set_indef_name("a carnivorous squirrel");
  add_alias("squirrel");
  add_alias("giant carnivorous squirrel");
  
  set_race("squirrel");
  set_gender(1);
  set_level(8);
  set_al(-200);
  set_state("init");
// -- Responses -------------------------------------------------------------
  
// -- Items -----------------------------------------------------------------

    
// -- Equipment ----------------------------------------------------------


}


