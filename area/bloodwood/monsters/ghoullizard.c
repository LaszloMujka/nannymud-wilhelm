// -- This line is 78 characters long ----------------------------------------

inherit "/std/state_monster";

#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;

// -- Settings --------------------------------------------------------------

  set_short("a ghoul lizard"),
  set_long("The lizard has pale green-white scales and raised bony ridges "+
  "around the eyes. The top of the snout resembles the upper half of a human "+
  "skull. About nine feet long including its tail. ");
  
  set_name("ghoul lizard");
  add_alias("lizard");

  set_race("lizard");
  set_gender(1);
  set_level(10);
  set_al(-250);
  set_state("init");
  
  add_hook("die_hook", this_object());
  add_hook("kill_hook", this_object());   
  
   
  
// -- Responses -------------------------------------------------------------
  
// -- Items -----------------------------------------------------------------

// -- Attacks  --------------------------------------------------------------

  add_attack("\b1PRON swaps \b2PRON with his tail.",15,8);
 
// -- Equipment ----------------------------------------------------------


}

// -- LOGGER ----------------------------------------------------------------

die_hook(data, who) {
  LOGGER -> log("kills", "killed a ghoul lizard", data[0]);
}
kill_hook(data, who) {
  LOGGER -> log("deaths", "killed by a ghoul lizard", data[0]);
}
