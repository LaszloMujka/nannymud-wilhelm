/*BloodWood*/

inherit "/players/wilhelm/area/bloodwood/rooms/forest_rooms";


void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------


  add_exit("northeast", "forest3");
  add_exit("north", "forest5");
  add_exit("east", "forest4");
  add_exit("south", "forest2");

  add_hidden_exit("southeast", "forest_rooms", 0, "exit");
  add_hidden_exit("southwest", "forest_rooms", 0, "exit");
  add_hidden_exit("west",      "forest_rooms", 0, "exit");
  add_hidden_exit("northwest", "forest_rooms", 0, "exit");  
  
  
// -- Description and settings -------------------------------------------


// -- Items and Commands -------------------------------------------------
  
	
}

// -- Night and Day time descriptions ---------------------------------------



// -- Commands output --------------------------------------------------------

exit()
{
  return "The forest is too overgrown for you to be able to explore in that direction.";
}

// -- Random happenings -------------------------------------------------------
