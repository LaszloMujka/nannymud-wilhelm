// -- This line is 78 characters long ----------------------------------------

inherit "/std/state_monster";

#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;

// -- Settings --------------------------------------------------------------

  set_short("a thorn man"),
  set_long("An animated bundle of thorns. It has a vaguely human-like "+
  "appearance, that stands roughly six feet tall.");
  
  set_name("thorn man");
  add_alias("thornman");
  add_alias("thorn");
  
  set_race("magic");
  set_gender(1);
  set_level(10);
  set_al(-250);
  set_state("init");
  
  add_hook("die_hook", this_object());
  add_hook("kill_hook", this_object());   
  
   
  
// -- Responses -------------------------------------------------------------
  
// -- Items -----------------------------------------------------------------

// -- Attacks  --------------------------------------------------------------

// -- Equipment ----------------------------------------------------------
  add_object("/players/wilhelm/area/bloodwood/weapons/thorn_spear");
  command("wield spear");

}

// -- LOGGER ----------------------------------------------------------------

die_hook(data, who) {
  LOGGER -> log("kills", "killed a thorn man", data[0]);
}
kill_hook(data, who) {
  LOGGER -> log("deaths", "killed by a thorn man", data[0]);
}

