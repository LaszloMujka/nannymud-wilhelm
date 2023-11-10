/*BloodWood*/

inherit "/players/wilhelm/area/bloodwood/rooms/forest_rooms";


void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------


  add_exit("southeast", "forest7");
  add_exit("north", "forest10");
  add_exit("west", "forest11");
 
  add_hidden_exit("northeast", "forest_rooms", 0, "exit");
  add_hidden_exit("east",      "forest_rooms", 0, "exit");
  add_hidden_exit("south",     "forest_rooms", 0, "exit");
  add_hidden_exit("southwest", "forest_rooms", 0, "exit");
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
