/*A gravel road north of siridfaath*/

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
#define TD "/obj/util/timed"
#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;
    
// -- Properties ---------------------------------------------------------

  add_light(1);
  add_property("no_tree");
  add_property("no_walkers");
  add_exit("north", "area_road2");
  add_exit("southeast", "siridfaath1");
  

// -- Description and settings -------------------------------------------

  set_short("a turn in the road");
  set_long("You can see the green grass dancing in the wind everywhere around "+
    "you. The road you're on continues to the north and the southeast towards "+
    "a small village. To the east the large mountain is reaching for the sky. "+
	"And far off in the west, you see a dark mysterious forest.");

// -- Objects ------------------------------------------------------------

  add_item( ({ "village","town" }), 
    "Far off to the southeast houses fills up the landscape.");
  add_item( ({ "road","path","boring road" }), 
    "The long road seems never ending. It turns of to the southeast towards a "+
	"village, and it goes back home to the north.");
  add_item( ({ "mountain","mountain range","mountains","gigantic rock" }), 
    "A gigantic rock, leaning on the heaven above. It looks dark and "+
    "soulless.");
  add_item( ({ "north" }),
    "All you can see is open fields and the road leading back home.");
  add_item( ({ "east" }),
    "To the east on the other side of the grass field, there is a huge "+
    "mountain.");
  add_item( ({ "south" }),
    "You stop and scout over the fields to the south. Nothing but grass as "+
    "far as you can see, but you think you can hear some sounds coming from "+
    "that direction. Maybe if you try to listen, you hear what it is.");
  add_item( ({ "west" }),
    "Open fields covered in green grass goes on for miles, before it turns "+
    "into a dark forest.");
  add_item( ({ "river" }),
    "You can't see any river here.");
  add_item( ({ "field","fields","meadow",",meadows","plain","plains"}),
    "The fields around the road are made almost entirely out of long grass. "+
	"It stretches on for miles. ");
  add_item( ({ "water" }),
    "You can't see any water here.");
  add_item( ({ "bird","birds" }),
    "Now and then birds fly by over your head, but they are to far away to "+
    "see what kind it is.");   	
  add_item( ({ "village","town","house","houses" }),
	"The village is to the southeast.");
    
  add_item("grass", "@make_grass()");
  add_item("forest", "@make_forest()");
  add_item("river", "@make_river()");
  
  add_hidden_exit("west", "sirdfaath_road1", 0, "west");
  add_command(({ "listen" }), "@listen()");
 
  
}

// -- Night and Day time descriptions ---------------------------------------

make_grass() {
  if (TD -> query_daytime()) {
  return line_break("The sun is feasting on the green grass, that are "+
  "dancing in the wind everywhere around you.");
  }
    
  return line_break("The moon shines on the grass, making it look like "+
  "silver.");
  
}

make_forest() {
  if (TD -> query_daytime()) {
  return line_break("The dark forest begins far off to the west on the other "+
  "side of the open fields. You can't see much more at this distance.");
  }
    
  return line_break("You can hardly see the forest in this dark, it glides in "+
  "with the fields looking more like a hill in the distance.");
}

make_river() {
  if(this_player()->query_property("wilhelm_listen_river")) {
  return line_break("You can't see any river from here. Maybe if you follow "+
  "the road further southeast.");
  }
    
  return line_break("You can't see any river here.");
  
}

// -- Commands output --------------------------------------------------------

west()
{
  return "Traveling to the forest in the high grass, would take forever.";
}

listen()
{
"/std/msg"->msg("\bPRON stop\b$ and listens to the surroundings.\n");
write("When you listen carefully you hear the sound of running water of to\n"); 
write("the south. Maybe there is a river on the other side of the field?\n");
this_player()->add_property("wilhelm_listen_river");
return 1;
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
  
call_out("weather", 120);
  day_message = ({
    "A cold wind blows over the fields, making you shiver.",
    "A flock of birds flies by over your head, towards the forest in " +
    "the west.",
    "Suddenly some birds, flies up from the fields beside you and " +
    "head for the mountains.",
    "A strong gust blows in from the south, making the grass on " +
    "the open plains sway back and forth." });
  night_message = ({
    "A cold wind blows over the fields, making you shiver.",
    "A flock of birds flies by over your head, towards the forest in " +
    "the west.",
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
