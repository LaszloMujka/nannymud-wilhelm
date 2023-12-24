/*The Chamber of Voices*/

inherit "/std/room";
#define TD "/obj/util/timed"
//#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_property("no_tree");
  add_property("indoors");
  add_light(1);
  add_exit("up", "palace3");
  add_exit("up", "palace3", "up","check_exit");
  add_exit("down", "palace1");
  
// -- Description and settings -------------------------------------------

  set_short("the portrait gallery");
  set_long("This long, high-ceilinged room is amply furnished with low "+
  "couches from which to comfortably view the portraits of past and present "+
  "consortis and elven queens. ");    

// -- Items and Commands -------------------------------------------------
  
  add_item( ({ "floor" }),
    "The floor is covered in woven vines intertwined with large tree branches.");
  add_item( ({ "wall","walls" }),
    "The north and south wall are hung with tapestries depicting the palace and "+
	"the gardens, formal portraits grace the walls on the east and west.");
  add_item( ({ "tapestri","tapestries" }),
    "The north and south wall are hung with tapestries depicting the palace and "+
	"the gardens.");
  add_item( ({ "portraits","portrait" }),
    "The portraits are of elven queens stretching back for generations. All the "+
	"queens are depicted with thorns.");
  add_item( ({ "tree","trees" }),
    "The palace is built in between many large trees, making them part of the "+
	"palace walls.");	
  add_item( ({ "vine","vines" }),
    "The vines are magically constructed and make of most of the walls and floor.");
  add_item( ({ "door","doors","rose bushes" }),
    "The doors between rooms are rose bushes grown thick enough to become solid.");			
  add_item( ({ "couch","couches" }),
    "The couches form a circle in the middle of the gallery, offering spectators "+
	"a good view of every artwork in the room.  ");
	
}

// -- Night and Day time descriptions ---------------------------------------



// -- Commands output --------------------------------------------------------

check_exit() {
  if ((this_player()-> query_property("wilhelm_bloodwood_quest")) ||
     (this_player()-> query_puzzle("wilhelm_bloodwood_quest")))
  {
    // this_player()->move_player("up",
    // "/players/wilhelm/area/bloodwood/rooms/palace3");	  
  return;
  }	
  if (this_player()-> query_property("wilhelm_bloodwood_horn")){
  return line_break("The plants and trees around you seem to shift and sway "+
  "blocking the path up.");
  }
}

// -- Random happenings -------------------------------------------------------
