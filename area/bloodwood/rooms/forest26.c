/*BloodWood*/

inherit "/players/wilhelm/area/bloodwood/rooms/forest_rooms";


void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_exit("northeast", "forest25");
  add_exit("west", "forest_p3", "west", "check_exit");
 
  add_hidden_exit("north",     "forest_rooms", 0, "exit");
  add_hidden_exit("east",      "forest_rooms", 0, "exit");
  add_hidden_exit("southeast", "forest_rooms", 0, "exit");
  add_hidden_exit("south",     "forest_rooms", 0, "exit");
  add_hidden_exit("southwest", "forest_rooms", 0, "exit");
  add_hidden_exit("northwest", "forest_rooms", 0, "exit");
 
  
// -- Description and settings -------------------------------------------

  set_long("You are standing in an enormous forest. Huge trees loom above "+
	"you, covering up the sky. Large and thick vines hang between the towering "+
	"trees. You can see a path to the west.");

// -- Items and Commands -------------------------------------------------
  
    add_item(({ "path" }), 
    "It's a small path leading through the forest.");
	
	add_object("/players/wilhelm/area/bloodwood/monsters/bloodraven");	
	
}

// -- Night and Day time descriptions ---------------------------------------



// -- Commands output --------------------------------------------------------

exit()
{
  return "The forest is too overgrown for you to be able to explore in that direction.";
}

check_exit() {

  if (this_player()-> query_property("wilhelm_bloodwood_quest")){
      // this_player()->move_player("west",
      // "/players/wilhelm/area/bloodwood/rooms/forest_p3");	  
  return;
  }	
  if (!this_player()-> query_property("wilhelm_bloodwood_horn")){
      //  this_player()->move_player("west",
      // "/players/wilhelm/area/bloodwood/rooms/forest_p3");
      write("You feel unsafe walking onto the forest path, someone might see you.\n");	  
      return ;
  }

}

// -- Random happenings -------------------------------------------------------
