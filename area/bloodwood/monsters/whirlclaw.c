// -- This line is 78 characters long ----------------------------------------

inherit "/std/state_monster";

#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;

// -- Settings --------------------------------------------------------------

  set_short("a whirlclaw"),
  set_long("A small, exceptionally quick and nimble creature. The shaggy "+
  "creature is about two feet in height, with long spindly arms that end "+
  "in sharp, wickedly curved claws."),
  
  set_name("whirlclaw");
  add_alias("creature");
  
  set_race("monster");
  set_gender(1);
  set_level(12);
  set_al(-250);
  set_state("init");
  
  add_hook("die_hook", this_object());
  add_hook("kill_hook", this_object());   
  
  
// -- Responses -------------------------------------------------------------
  
// -- Items -----------------------------------------------------------------
// CLAWS that can be sold
    
// -- Equipment ----------------------------------------------------------


}

// -- LOGGER ----------------------------------------------------------------

die_hook(data, who) {
  LOGGER -> log("kills", "killed a whirlclaw", data[0]);
}
kill_hook(data, who) {
  LOGGER -> log("deaths", "killed by a whirlclaw", data[0]);
}

