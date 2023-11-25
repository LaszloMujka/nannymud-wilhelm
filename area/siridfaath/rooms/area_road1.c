/*Road towards Siridfaath*/

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
#define TD "/obj/util/timed"
//#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_property("road");
  add_light(1);
  add_property("no_tree");
  add_exit("north", "area_entry");
  add_exit("south", "area_road2");
  
  
// -- Description and settings -------------------------------------------

  set_short("a small gravel road");
  set_long("The repeating sound of your feet hitting the gravel is almost "+
    "all you hear when walking down the old road. It starts to feel like it "+
    "leads on forever. Around you, open fields stretch on for miles. To the "+
	"southeast, you can see a large mountain range and far off to the west the "+
	"beginning of a forest.");    

// -- Items and Commands -------------------------------------------------

  add_item( ({ "road","path","gravel road" }),
    "The gravel road leads on along the mountain range in the south and to more "+
    "familiar lands to the north.");
  add_item( ({ "field","fields","meadow",",meadows","plain","plains"}),
    "The fields around the road are made almost entirely out of long grass. "+
	"It stretches on for miles. ");
  add_item( ({ "grass" }),
    "The grass is long and thick.");
  add_item( ({ "north" }),
    "Far to the north you can travel back home.");
  add_item( ({ "south" }),
    "The road leads on to the south, alongside a huge mountain. ");
  add_item( ({ "west" }),
    "Open fields covered in green grass goes on for miles, before it turns "+
    "into a forest.");
  add_item( ({ "east" }),
    "Miles upon miles with high grass, following along the large mountain "+
    "range.");
  add_item( ({ "mountain", "mountan range" }),
    "The huge mountain range to the southeast stretch up far into the sky, "+
    "crashing into the clouds. It goes on for miles to the east as far as you "+
    "can see.");
  add_item( ({ "bird","birds" }),
    "Now and then birds fly by over your head, but they are to far away to "+
    "see what kind it is.");   	

  add_item("forest", "@make_forest()");
  add_item("east", "@make_east()");
  
  add_hidden_exit("west", "area_road1", 0, "west");
  add_hidden_exit("east", "area_entry", 0, "east");
 
  
}

// -- Night and Day time descriptions ---------------------------------------

make_forest() {
  if (TD -> query_daytime()) {
  return line_break("The forest begins far off to the west on the other side "+
  "of the open fields. You can't see much more at this distance.");
  }
    
  return line_break("You can hardly see the forest in this dark, it glides in "+
  "with the fields looking more like a hill in the distance.");
}

// -- Commands output --------------------------------------------------------

west()
{
  return "Traveling to the forest in the high grass, would take forever.";
}

east()
{
  return "Traveling in the high grass, would take forever.";
} //Reset east


// -- Random happenings -------------------------------------------------------

init() {
  :: init();
  if (find_call_out("weather") == -1)
    call_out("weather", 30);
} 


weather() 
{
  string *day_message, *night_message;
  
call_out("weather", 120);
  day_message = ({
    "A cold wind blows over the fields, making you shiver.",
    "A flock of birds flies by over your head, towards the forest in " +
    "the west.",
    "Suddenly some birds, flies up from the fields beside you and " +
    "head for the mountains.",
    "Rocks tumble town the mountain side, far off to the southeast.",
    "A strong gust blows in from the south, making the grass on " +
    "the open plains sway back and forth." });
  night_message = ({
    "A cold wind blows over the fields, making you shiver.",
    "A flock of birds flies by over your head, towards the forest in " +
    "the west.",
    "Rocks tumble town the mountain side, far off to the south.",
    "Suddenly some birds, flies up from the fields beside you and " +
    "head for the mountains.",
    "A strong gust blows in from the south, making the grass on " +
    "the open plains sway back and forth." });
  if(TD->query_daytime()) 
    tell_room(this_object(), day_message[random(sizeof(day_message))] + "\n");
  else
    tell_room(this_object(), 
      night_message[random(sizeof(night_message))] + "\n");
}
