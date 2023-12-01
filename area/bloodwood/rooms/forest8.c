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
  add_exit("southeast", "forest5");
  add_exit("southwest", "forest7");
  add_exit("south", "forest6");
  add_exit("north", "forest_p3", "north", "check_exit");

  add_hidden_exit("northeast", "forest_rooms", 0, "exit");
  add_hidden_exit("east",      "forest_rooms", 0, "exit");
  add_hidden_exit("west",      "forest_rooms", 0, "exit");
  add_hidden_exit("northwest", "forest_rooms", 0, "exit");
  
// -- Description and settings -------------------------------------------

   set_long("You are standing in an enormous forest. Huge trees loom above "+
  "you, covering up the sky. Large and thick vines hang between the towering "+
  "trees. You can see a path to the north.");  

// -- Items and Commands -------------------------------------------------
  
    add_item(({ "path" }), 
    "It's a small path leading through the forest.");
		
}

// -- Night and Day time descriptions ---------------------------------------



// -- Commands output --------------------------------------------------------

exit()
{
  return "The forest is too overgrown for you to be able to explore in that direction.";
}

// check_exit() {

//   if (this_player()-> query_property("wilhelm_bloodwood_quest")){
//       this_player()->move_player("north",
//       "/players/wilhelm/area/bloodwood/rooms/forest_p3");	  
//   return;
//   }	
//   if (!this_player()-> query_property("wilhelm_bloodwood_horn")){
//        this_player()->move_player("north",
//       "/players/wilhelm/area/bloodwood/rooms/forest_p3");
//   return 
//   line_break("You feel unsafe walking onto the forest path, someone might see you.");	  
//   }

// }

// -- Random happenings -------------------------------------------------------
