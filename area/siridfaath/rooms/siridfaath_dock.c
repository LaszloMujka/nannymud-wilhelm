/*A dock at the serpent river*/
// -- This line is 78 characters long ----------------------------------------
inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
#define TD "/obj/util/timed"
#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties -------------------------------------------------------------

  add_property("plain");
  add_light(1);
  add_property("no_tree");
  add_property("floor", "wood");
  add_property("waterside");
  add_exit("northwest", "siridfaath_road2");

// -- Description and settings -----------------------------------------------

  set_short("a dock at the Serpent river");
  set_long("This is an old wooden dock at the bank of the enormous Serpent "+
  "River. Here trade boats often stop to sell and buy new cargo on their "+
  "travels. The wide river passes the dock and flows with great speed to "+
  "the east. You can follow a gravel path back up to the village. Far north "+
  "there is a huge mountain and to the east, the grass fields turn into a "+
  "forest.");


// -- Items and Commands -----------------------------------------------------

  add_item( ({ "dock","docks" }),
    "The dock you are standing on is made of lumber. It looks rather old "+
	"and the boards creak under your foot when you walk.  ");
  add_item( ({ "boards", "board", "old boards", "plank", "planks","lumber" }),
    "The boards on the dock are old. Some of the boards makes creaking sounds "+ 
    "when you walk on them.");
  add_item( ({ "river", "serpent river" }),
    "The huge river stretch of to the northwest and east. It look's like "+
	"it's almost four miles wide. The strong current in the water flows "+
	"to the east.");
  add_item( ({ "water" }), 
    "The water is cold and clear, and the strong current makes the water flow "+
    "with great speed to the east.");

  add_item( ({ "path","small path","road","small road" }),
    "A gravel path leaving the dock to the northwest leading up to the "+
    "small village");
  add_item( ({ "village","town" }), 
    "You can see alot of small houses filling up the landscape to the "+
    "northwest");
  add_item( ({ "forest" }),
    "About two miles of to the east a small forest starts. It continues along "+
    "the mountain range and the river.");	
  add_item( ({ "grass" }),
    "The grass is long and thick.");	
	
  add_command("enter %s", "@cmd_enter()");
  
// -- Objects ----------------------------------------------------------------


add_object("/players/wilhelm/area/siridfaath/obj/breeton");

}

string cmd_enter(int arg, string e) {
  if(!e) return "Enter what?\n";
  else switch(e) {
    case "road" : return "You are standing on the road.\n";
    case "ship" :
	case "boat" :
	case "breeton": 
	this_player()->move_player("onto the riverboat",
    "/players/wilhelm/area/siridfaath/rooms/breeton");
	return "";
    case "mountain" : return "The mountain is to far away.\n";
    case "forest" :
    case "trees" :  return "Entering the forest without a path to follow will "+
	     "just make you end up lost..\n"; 

  } 
} // Reset enter


init() {
  :: init();
  if (find_call_out("weather") == -1)
    call_out("weather", 30);
} 


weather() 
{
  string *day_message, *night_message;
  
call_out("weather", 180);
  day_message = ({
    "The old boards on the dock, creaks under your feet.",
    "Water splashes up on the dock.",
    "Someone is shouting orders aboard the ship.",
    "Some goods are carried off the ship, by the crew.",
    "A cold wind blows in from the river." });
  night_message = ({
    "The old boards on the dock, creaks under your feet.",
    "Water splashes up on the dock.",
    "A cold wind blows in from the river.",
    "The stars glimmer in the night sky.",
    "You hear an owl hooting far in the distance." });
  if(TD->query_daytime()) 
    tell_room(this_object(), day_message[random(sizeof(day_message))] + "\n");
  else
    tell_room(this_object(), 
      night_message[random(sizeof(night_message))] + "\n");
}
