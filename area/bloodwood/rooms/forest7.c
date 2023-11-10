/*BloodWood*/

inherit "/players/wilhelm/area/bloodwood/rooms/forest_rooms";


void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;
// -- Properties ---------------------------------------------------------

  add_property("forest");
  add_light(1);
  add_exit("east", "forest6");
  add_exit("northeast", "forest8");
  add_exit("northwest", "forest9");
  
  add_hidden_exit("north",     "forest_rooms", 0, "exit");
  add_hidden_exit("southeast", "forest_rooms", 0, "exit");
  add_hidden_exit("south",     "forest_rooms", 0, "exit");
  add_hidden_exit("southwest", "forest_rooms", 0, "exit");
  add_hidden_exit("west",      "forest_rooms", 0, "exit");
  
  add_object("/players/wilhelm/area/bloodwood/monsters/bloodraven");	
  
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
