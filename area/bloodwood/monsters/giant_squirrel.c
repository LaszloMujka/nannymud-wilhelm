// -- This line is 78 characters long ----------------------------------------

inherit "/std/state_monster";

#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;

// -- Settings --------------------------------------------------------------

  set_short("a giant carnivorous squirrel"),
  set_long("A massive rodent, nearly five times the size of an ordinary squirrel."),
  
  set_name("carnivorous squirrel");
  add_alias("squirrel");
  add_alias("giant carnivorous squirrel");
  
  set_race("squirrel");
  set_gender(1);
  set_level(8);
  set_al(-200);
  set_state("init");
  
  add_hook("die_hook", this_object());
  add_hook("kill_hook", this_object());   
  
  
  
// -- Responses -------------------------------------------------------------
  
// -- Items -----------------------------------------------------------------

    
// -- Equipment ----------------------------------------------------------


}

// -- LOGGER ----------------------------------------------------------------

die_hook(data, who) {
  LOGGER -> log("kills", "killed a carnivorous squirrel", data[0]);
}
kill_hook(data, who) {
  LOGGER -> log("deaths", "killed by a carnivorous squirrel", data[0]);
}

