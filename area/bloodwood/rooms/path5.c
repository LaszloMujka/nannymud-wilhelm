/*Path towards BloodWood*/

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
#define TD "/obj/util/timed"
#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_property("road");
  add_light(1);
  add_exit("west", "forest_p1");
  add_exit("east", "path4");
  
// -- Description and settings -------------------------------------------

  set_short("a small path");
  set_long("You are standing on a narrow path on the outskirts of a "+
  "large forest. The path leads into the forest to the west and "+
  "continues along endless fields to the east. The grass land around "+
  "the forest is barren and dying.");    

// -- Items and Commands -------------------------------------------------

  add_item( ({ "forest" }),
    "An oasis of dark green, shining like a vast emerald beside the barren "+
	"plains.");
  add_item(({ "mountain", "mountains", "mountain range" }),"@make_mountain()");
  add_item(({ "path","trail" }), 
    "A small trail between the large fields, it leads into the forest in the "+
	"west and follows the endless fields to the east. The ground is dry and "+
	"lifeless.");
  add_item( ({ "grass" }),
    "The grass is barren and dying. Looks like it hasn't seen rainwater for weeks.");
  add_item( ({ "ground","soil" }),
    "The soil under your feet is dry and lifeless.");	
  add_item( ({ "field","fields","meadow",",meadows","plain","plains"}),
    "Hugh lifeless fields beside the lush green forest.");
 
  add_command("search %s", "@cmd_search()");
 
}

// -- Night and Day time descriptions ---------------------------------------

make_mountain() {
  if (TD -> query_daytime()) {
  return line_break("Far off in the east, you can still see the huge mountain "+
  "range that stretches far up in the sky.");
  }
    
  return line_break("A black wall far off in the east.");
} // Reset make_mountain

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
    case "fields" : return  "You search around in the grass, but all you "+
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
    "A gust of wind blows over the dead fields.",
    "A flock of birds flies's by over your head, into the forest in the west.",
    "The sun shines through the clouds, lighting up the small path.",
    "The warm sun rays kissed your skin lightly, warming you from the inside out."});
  night_message = ({
    "A cold night breeze blows our the dead fields.",
    "You hear the sound of a strange animal echoing towards you in the twilight.",
    "Stars illuminated the darkness around you.",
    "The sun has gone to rest, the moon takes his place as the darkness begins to surround you."});
  if(TD->query_daytime()) 
    tell_room(this_object(), day_message[random(sizeof(day_message))] + "\n");
  else
    tell_room(this_object(), 
      night_message[random(sizeof(night_message))] + "\n");
}
