/*Path towards BloodWood*/


inherit "/players/wilhelm/area/bloodwood/rooms/path_rooms";
#define TD "/obj/util/timed"
//#define LOGGER load_object("/players/wilhelm/simple_logger")

object axe_f = load_object("/players/wilhelm/area/bloodwood/rooms/path_rooms");

void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_property("road");
  add_light(1);
  add_exit("west", "path3");
  add_exit("east", "path1");

  
// -- Description and settings -------------------------------------------

  set_short("a small path");
  set_long("You are standing on a narrow path in the middle of a large "+
  "grassy meadow. Far off in the distance to the west, you can see the "+
  "start of a large forest and to the east, the path continues along "+
  "endless fields of grass. ");    

// -- Items and Commands -------------------------------------------------


  add_item(({ "path","trail" }), 
    "A small trail between the large grassy fields, it leads toward a "+
	"forest in the west and follows the endless fields to the east.");
  add_item( ({ "grass" }),
    "Rough and shaggy like uncombed hair, stretching up to your waist.");
  add_item( ({ "field","fields","meadow",",meadows","plain","plains"}),
    "Hugh fields of grass that are waving and rustling the breeze.");
 
  add_command("search %s", "@cmd_search()");
 
 
}


// -- Night and Day time descriptions ---------------------------------------



// -- Commands output --------------------------------------------------------

string cmd_search(int arg, string s) {
  object note;
  if(!s) return "You should be more specific.\n";
  else switch(s) {
    case "grass" :
	case "meadow" :
	case "meadows" :
	case "plain" :
	case "plains" :
	case "field" :
    case "fields" : return  "You search around in the high grass, but all you "+
            "can find is more grass.\n";
    case "forest" :
    case "trees" :
    case "mountain" :
    case "mountain range" : return "It is too far away to search.\n";
    case "trail" :
    case "path" : return "The small path holds nothing of interest.\n";

  }
}

// -- Random happenings -------------------------------------------------------

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
    "The long meadow grass rustles in the breeze.",
    "A flock of birds flies's by over your head, towards the forest in the west.",
    "The sun shines through the clouds, lighting up the small path.",
    "The warm sun rays kisses your skin lightly, warming you from the inside out."});
  night_message = ({
    "The long meadow grass rustles in the cold night breeze.",
    "You hear the sound of a strange animal echoing towards you in the twilight.",
    "Stars illuminated the darkness around you.",
    "The sun has gone to rest, the moon takes his place as the darkness begins to surround you."});
  if(TD->query_daytime()) 
    tell_room(this_object(), day_message[random(sizeof(day_message))] + "\n");
  else
    tell_room(this_object(), 
      night_message[random(sizeof(night_message))] + "\n");
}
