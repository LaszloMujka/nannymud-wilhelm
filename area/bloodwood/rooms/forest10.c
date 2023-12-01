/*BloodWood*/

inherit "/players/wilhelm/area/bloodwood/rooms/forest_rooms";


void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_exit("south", "forest9");
  add_exit("north", "forest_p6", "north", "check_exit");
  add_exit("northwest", "forest_p7", "northwest", "check_exit");
  add_exit("northeast", "forest_p5", "northeast", "check_exit");

  add_hidden_exit("east",      "forest_rooms", 0, "exit");
  add_hidden_exit("southeast", "forest_rooms", 0, "exit"); 
  add_hidden_exit("southwest", "forest_rooms", 0, "exit");
  add_hidden_exit("west",      "forest_rooms", 0, "exit");
  
  
  add_object("/players/wilhelm/area/bloodwood/monsters/assasin_vine");
  
  
// -- Description and settings -------------------------------------------

  

// -- Items and Commands -------------------------------------------------
  
	
}

// -- Night and Day time descriptions ---------------------------------------



// -- Commands output --------------------------------------------------------

exit()
{
  return "The forest is too overgrown for you to be able to explore in that direction.";
}

// check_exit_n() {

//   if (this_player()-> query_property("wilhelm_bloodwood_quest")){
//       this_player()->move_player("north",
//       "/players/wilhelm/area/bloodwood/rooms/forest_p6");	  
//   return;
//   }	
//   if (!this_player()-> query_property("wilhelm_bloodwood_horn")){
//        this_player()->move_player("north",
//       "/players/wilhelm/area/bloodwood/rooms/forest_p6");
//   return 
//   line_break("You feel unsafe walking onto the forest path, someone might see you.");	  
//   }

// }

// check_exit_ne() {

//   if (this_player()-> query_property("wilhelm_bloodwood_quest")){
//       this_player()->move_player("northeast",
//       "/players/wilhelm/area/bloodwood/rooms/forest_p5");	  
//   return;
//   }	
//   if (!this_player()-> query_property("wilhelm_bloodwood_horn")){
//        this_player()->move_player("northeast",
//       "/players/wilhelm/area/bloodwood/rooms/forest_p5");
//   return 
//   line_break("You feel unsafe walking onto the forest path, someone might see you.");	  
//   }

// }

// check_exit_nw() {

//   if (this_player()-> query_property("wilhelm_bloodwood_quest")){
//       this_player()->move_player("northwest",
//       "/players/wilhelm/area/bloodwood/rooms/forest_p7");	  
//   return;
//   }	
//   if (!this_player()-> query_property("wilhelm_bloodwood_horn")){
//        this_player()->move_player("northwest",
//       "/players/wilhelm/area/bloodwood/rooms/forest_p7");
//   return 
//   line_break("You feel unsafe walking onto the forest path, someone might see you.");	  
//   }

// }

// -- Random happenings -------------------------------------------------------
