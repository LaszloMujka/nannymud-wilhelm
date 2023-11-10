/*BloodWood*/

inherit "/players/wilhelm/area/bloodwood/rooms/forest_rooms";


void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_exit("south", "forest11");
  add_exit("west", "forest12");
  
  add_hidden_exit("north",     "forest_rooms", 0, "exit");
  add_hidden_exit("northeast", "forest_rooms", 0, "exit");
  add_hidden_exit("east",      "forest_rooms", 0, "exit");
  add_hidden_exit("southeast", "forest_rooms", 0, "exit");
  add_hidden_exit("southwest", "forest_rooms", 0, "exit");
  add_hidden_exit("northwest", "forest_rooms", 0, "exit");
  
  
// -- Description and settings -------------------------------------------



// -- Items and Commands -------------------------------------------------
     
	
	add_object("/players/wilhelm/area/bloodwood/monsters/assasin_vine");
	
}

// -- Night and Day time descriptions ---------------------------------------



// -- Commands output --------------------------------------------------------

exit()
{
  return "The forest is too overgrown for you to be able to explore in that direction.";
}

check_exit() {

  if (this_player()-> query_property("wilhelm_bloodwood_quest")){
      this_player()->move_player("east",
      "/players/wilhelm/area/bloodwood/rooms/forest_p4");	  
  return;
  }	
  if (!this_player()-> query_property("wilhelm_bloodwood_horn")){
       this_player()->move_player("east",
      "/players/wilhelm/area/bloodwood/rooms/forest_p4");
  return 
  line_break("You feel unsafe walking onto the forest path, someone might see you.");	  
  }

}

// -- Random happenings -------------------------------------------------------
