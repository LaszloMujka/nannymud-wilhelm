/*BloodWood*/

inherit "/players/wilhelm/area/bloodwood/rooms/forest_rooms";

mapping search_hedge;
string name;

void reset(int arg) 
{
  ::reset(arg);
    search_hedge = ([]);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_exit("west", "forest19");
  add_exit("east", "forest21");
  add_hidden_exit("south", "forest20", 0, "do_south");

  add_hidden_exit("north",     "forest_rooms", 0, "exit");
  add_hidden_exit("northeast", "forest_rooms", 0, "exit");
  add_hidden_exit("southeast", "forest_rooms", 0, "exit");
  add_hidden_exit("southwest", "forest_rooms", 0, "exit");
  add_hidden_exit("northwest", "forest_rooms", 0, "exit");
	
	
	
	set_long("You are standing in an enormous forest. Huge trees loom above "+
	"you, covering up the sky. Large and thick vines hang between the towering "+
	"trees. The path to the south is obstructed by a large thorny hedge. ");
  
  
// -- Description and settings -------------------------------------------

    add_item(({ "hedge", "thorny hedge" }), 
    "The hedge reaches high up and is covered with sharp thorns. Not making it "+
	"possible to see what's on the other side. Maybe a more thorough search is "+
	"in order?");
	
	add_item(({ "thorns", "sharp thornes","thorn" }), 
    "Like the rest of the forest, the hedge is covered in sharp thorns, "+
	"making it hard to go anywhere.");
  

// -- Items and Commands -------------------------------------------------
  
    add_item_cmd(({"climb","ascend"}),"hedge","@cmd_climb()");
	add_item_cmd("jump", "hedge", 
	"The hedge is too high to jump, you might be able to climb it.\n");
	add_item_cmd("enter", "hedge", 
	"There aren't any openings in the hedge to enter.\n");
	add_item_cmd("cut", "hedge", 
	"You can't cut your way through the hedge.\n");
	add_item_cmd("search", "hedge", "@cmd_search()");
}

// -- Night and Day time descriptions ---------------------------------------



// -- Commands output --------------------------------------------------------

exit()
{
  return "The forest is too overgrown for you to be able to explore in that direction.";
}

cmd_search() {
    name = this_player() -> query_real_name();
    search_hedge[name] = 1;
    return line_break("You carefully search along the hedge and manage to "+
	"find a part in the hedge with practically no thorns. You should be able "+
	"to scale the hedge from here.");

}

cmd_climb() {
  name = this_player() -> query_real_name();
  if (search_hedge[name]) {
	this_player()->move_player("climbs, the thorny hedge",
    "/players/wilhelm/area/bloodwood/rooms/gardens3");	  
    return 1; 
  }
  return line_break("You consider climbing the large hedge, but you can't find "+
  "anywhere to hold on to without being cut to pieces. Maybe if you search for a better "+
  "spot to climb.");
}

do_south()
{
  this_player()->add_hp(-2);
  "/std/msg"->msg("\bPRON walk\b$, right into the thorny hedge, getting a nasty cut.\n");
  return line_break("The hedge seems to devour up your blood, growing denser by each drop.");
}

// -- Random happenings -------------------------------------------------------
