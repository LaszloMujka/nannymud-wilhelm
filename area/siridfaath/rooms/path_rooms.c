#include "/players/astrodeath/macros.h"


inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
int search,axe;

reset(arg)
{
  //search = random(3) + 1;
  search = 1
  axe = 1;
  ::reset(arg);
  if (arg) return;
  
  add_property("road");
  add_light(1);
  add_hidden_exit("north", "path1", 0, "lost");
  add_hidden_exit("south", "path1", 0, "lost");
  add_command("test", "@cmd_test()");
  
  
  add_item("forest", "@make_forest()");
  add_item(({ "mountain", "mountains", "mountain range" }),"@make_mountain()");
}


lost()
{
  return "Traveling off the path into the high grass will just get you lost.";
} //

// -- Night and Day time descriptions ---------------------------------------


make_forest() {
  if (TD -> query_daytime()) {
  return line_break("The forest begins far off to the west on the other side "+
  "of the open fields. You can't see much more at this distance.");
  }
    
  return line_break("You can hardly see the forest in this dark, it glides in "+
  "with the fields looking more like a hill in the distance.");
}

make_mountain() {
  if (TD -> query_daytime()) {
  return line_break("The huge mountain range to the east stretch up far into "+
  "the sky, crashing into the clouds. ");
  }
    
  return line_break("In the dark night the mountain to the east just looks "+
  "like a dark black wall.");
} // Reset make_mountain

