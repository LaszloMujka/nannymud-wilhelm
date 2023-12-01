/*Path towards BloodWood*/


inherit "/players/wilhelm/area/bloodwood/rooms/path_rooms";
#define TD "/obj/util/timed"
//#define LOGGER load_object("/players/wilhelm/simple_logger")
int axef;

void reset(int arg) 
{
  ::reset(arg);
  axef = 1;
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------


  add_exit("west", "path2");
  add_exit("east", "/players/wilhelm/area/siridfaath/rooms/area_road2");


  
// -- Description and settings -------------------------------------------

  set_short("a small path");
  set_long("You are standing on a small path. The large plain stretch "+
  "off inn all directions. Far off in the distance, you can see the "+
  "start of a large forest and to the east, you can walk back to the "+
  "road. ");    

// -- Items and Commands -------------------------------------------------


  add_item(({ "path","trail" }), 
    "A small trail between the large grassy fields, it leads toward a "+
	"forest in the west and back to the road to the east.");
  add_item(({ "road" }), 
    " You can just see the road from here, it towards the east. Behind "+
	"towers a huge mountain range. ");
  add_item( ({ "grass" }),
    "Rough and shaggy like uncombed hair, stretching up to your waist.");
  add_item( ({ "field","fields","meadow",",meadows","plain","plains"}),
    "Hugh fields of grass that are waving and rustling the breeze.");
 
  add_command("search %s", "@cmd_search()");
 
}



// -- Night and Day time descriptions ---------------------------------------



// -- Commands output --------------------------------------------------------

string cmd_search(int arg, string s) {
  object axe;
  if(!s) return "You should be more specific.\n";
  else switch(s) {
    case "grass" :
	case "meadow" :
	case "meadows" :
	case "plain" :
	case "plains" :
	case "field" :
    case "fields" :
		if (axef == 0){
		return  "You search around in the high grass, but all you "+
        "can find is more grass.\n"; }
		if (axef == 1){
		"std/msg"->msg("\bcapPRON search\b{,es} through the grass, and find\b$ an old axe.\n");	
		axe = clone_object("/players/wilhelm/area/bloodwood/weapons/old_axe");
		axef = 0;
		if (transfer(axe,this_player())) {
		"std/msg"->msg("\bPRON \bis carrying too much to hold it, so \bpron drop\b$ it.\n");
		move_object(axe, this_object());}
		
		
		return "That might be useful.";
		}
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
    "The warm sun rays kissed your skin lightly, warming you from the inside out."});
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
