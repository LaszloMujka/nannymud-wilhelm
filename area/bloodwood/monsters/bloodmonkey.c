// -- This line is 78 characters long ----------------------------------------

inherit "/std/state_monster";

#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;

// -- Settings --------------------------------------------------------------

  set_short("a blood monkey"),
  set_long("A small simian thickly covered in fur of a deep red color. "+
  "Sharp claws grow from the ends of their five fingers, and it sports a "+
  "mouthful of long, needle-sharp teeth."),
  
  set_name("blood monkey");
  add_alias("monkey");
  
  set_race("monkey");
  set_gender(1);
  set_level(10);
  set_al(-250);
  set_state("init");
 
  add_hook("die_hook", this_object());
  add_hook("kill_hook", this_object());   
  
  
  
  
// -- Responses -------------------------------------------------------------
  
// -- Items -----------------------------------------------------------------
// blood pelt 100g. How to make it hidden?
    
// -- Equipment ----------------------------------------------------------


}

// -- LOGGER ----------------------------------------------------------------

die_hook(data, who) {
  LOGGER -> log("kills", "killed a blood monkey", data[0]);
}
kill_hook(data, who) {
  LOGGER -> log("deaths", "killed by a blood monkey", data[0]);
}

