/*BloodWood*/

inherit "/players/wilhelm/area/bloodwood/rooms/forest_rooms";


void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_exit("west", "forest15");
  add_exit("north", "forest17");
  add_exit("northwest", "forest16");
  add_exit("south", "forest_p7", "south", "check_exit");
  
  add_hidden_exit("northeast", "forest_rooms", 0, "exit");
  add_hidden_exit("east",      "forest_rooms", 0, "exit");
  add_hidden_exit("southeast", "forest_rooms", 0, "exit");
  add_hidden_exit("southwest", "forest_rooms", 0, "exit");
  
// -- Description and settings -------------------------------------------

  

// -- Items and Commands -------------------------------------------------
  
	
}

// -- Night and Day time descriptions ---------------------------------------



// -- Commands output --------------------------------------------------------

exit()
{
  return "The forest is too overgrown for you to be able to explore in that direction.";
}

check_exit() {

  if (this_player()-> query_property("wilhelm_bloodwood_quest")){
      this_player()->move_player("south",
      "/players/wilhelm/area/bloodwood/rooms/forest_p7");	  
  return;
  }	
  if (!this_player()-> query_property("wilhelm_bloodwood_horn")){
       this_player()->move_player("south",
      "/players/wilhelm/area/bloodwood/rooms/forest_p7");
  return 
  line_break("You feel unsafe walking onto the forest path, someone might see you.");	  
  }

}

// -- Random happenings -------------------------------------------------------
