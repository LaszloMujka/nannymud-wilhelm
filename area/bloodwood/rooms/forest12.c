/*BloodWood*/

inherit "/players/wilhelm/area/bloodwood/rooms/forest_rooms";


void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_exit("east", "forest13");
  add_exit("southeast", "forest11");
  add_exit("north", "forest_p8", "north", "check_exit");

  add_hidden_exit("northeast", "forest_rooms", 0, "exit");
  add_hidden_exit("south",     "forest_rooms", 0, "exit");
  add_hidden_exit("southwest", "forest_rooms", 0, "exit");
  add_hidden_exit("west",      "forest_rooms", 0, "exit");
  add_hidden_exit("northwest", "forest_rooms", 0, "exit");
  
  set_long("You are standing in an enormous forest. Huge trees loom above you, "+
  "covering up the sky. Large and thick vines hang between the towering trees. "+
  "A river flows by to the west and you can see a path to the north.");  
  
  
// -- Description and settings -------------------------------------------

   add_item(({ "path","trail" }), 
    "North of here you can see a path going through the underbrush."); 
   add_item(({ "river" }), 
    "A wide river flows through the forest the currents too strong to pass.");	

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
      this_player()->move_player("north",
      "/players/wilhelm/area/bloodwood/rooms/forest_p8");	  
  return;
  }	
  if (!this_player()-> query_property("wilhelm_bloodwood_horn")){
       this_player()->move_player("north",
      "/players/wilhelm/area/bloodwood/rooms/forest_p8");
  return 
  line_break("You feel unsafe walking onto the forest path, someone might see you.");	  
  }

}

// -- Random happenings -------------------------------------------------------
