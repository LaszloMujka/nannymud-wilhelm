// -- This line is 78 characters long ----------------------------------------

inherit "/std/state_monster";

#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;

// -- Settings --------------------------------------------------------------

  set_short("a blood raven"),
  set_long("The blood raven can be distinguished from normal ravens by his "+
  "much larger size and reddish legs. It is observing your every move with "+
  "dark red eyes. "),
  
  set_name("blood raven");
  add_alias("raven");
  
  set_race("raven");
  set_gender(1);
  set_level(8);
  set_al(-200);
  set_state("init");
  
  add_hook("die_hook", this_object());
  add_hook("kill_hook", this_object());   
  
  
  
// -- Responses -------------------------------------------------------------
  
// -- Items -----------------------------------------------------------------
// -- Attacks  --------------------------------------------------------------

  add_attack("\b1PRON pecks \b2PRON eyes.",15,8);
 
// -- Equipment ----------------------------------------------------------


}

// -- LOGGER ----------------------------------------------------------------

die_hook(data, who) {
  LOGGER -> log("kills", "killed a blood raven", data[0]);
}
kill_hook(data, who) {
  LOGGER -> log("deaths", "killed by a blood raven", data[0]);
}

