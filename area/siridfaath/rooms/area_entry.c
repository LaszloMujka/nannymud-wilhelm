/*Entrance to my realm*/
// -- This line is 78 characters long ---------------------------------------

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
#define TD "/obj/util/timed"
#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties ------------------------------------------------------------

  add_light(1);
  add_property("no_tree");
  add_property("no_walkers");//danny 2022-08-13 to prevent padrone's castle to enter the rosebush
  add_property("road");
  add_exit("south", "area_road1");
  add_exit("north", "/room/west_road/road7");
  add_hidden_exit("west", "area_entry", 0, "west");
  add_hidden_exit("east", "area_entry", 0, "east");
  
// -- Description and settings ----------------------------------------------

  set_short("a small gravel road");
  set_long("The small gravel road moves along north and south between the "+
	"large grass fields. The open plain seems to stretch on for miles in "+
	"all directions. Far off to the west the grassy meadow turns into a "+
	"forest and to the southeast a huge mountain range climbs up into "+
	"the sky.");
    
// -- Help here -------------------------------------------------------------

  add_property("help_string","You can leave Wilhelm's realm by traveling "+
    "north.");

// -- Items and Commands ----------------------------------------------------

  add_item( ({ "road","path","gravel road", "small road","gravel" }),
    "It�s a small gravel road that continues to the north and south "+
	"between the grass fields. You notice a small rock beside the road. ");
  add_item( ({ "field","fields","meadow",",meadows","plain","plains"}),
    "The fields around the road are made almost entirely out of long grass. "+
	"It stretches on for miles in all directions. ");
  add_item( ({ "grass" }),
    "The grass is long and thick.");
  add_item( ({ "north" }),
    "To the north you can travel back home.");
  add_item( ({ "south" }),
    "The road leads on to the south, alongside a huge mountain. ");
  add_item( ({ "west" }),
    "Open fields covered in green grass goes on for miles, before it turns "+
    "into a forest.");  
  add_item( ({ "lightning","light" }),
    "Luckily it doesn't look like its moving towards you. ");
  add_item( ({ "rock" }),
    "The small rock seems to be the perfect size to sit down and rest on.");    
  add_item( ({ "bird","birds" }),
    "Now and then birds fly by over your head, but they are to far away to "+
    "see what kind it is.");   
  
  
  add_item(({ "mountain", "mountains", "mountain range" }),"@make_mountain()");
  add_item("forest", "@make_forest()");
  add_item("east", "@make_east()");
  
  add_command(({ "sit", "sit rock", "rest", "relax" }), "@rest()");
  add_command("enter %s", "@cmd_enter()");
  add_command("search %s", "@cmd_search()");
  
  // add_object("/players/wilhelm/area/siridfaath/obj/killerlist");
  // commented by danny since there is no point of having an outdated list
  // use another kind of logger if you wish to keep a toplist like this
}
 
// -- Night and Day time descriptions ---------------------------------------

make_mountain() {
  if (TD -> query_daytime()) {
  return line_break("The huge mountain range to the southeast stretch up far into "+
  "the sky, crashing into the clouds. It goes on for miles to the east as far "+
  "as you can see. ");
  }
    
  return line_break("In the dark night the mountain to the southeast just looks "+
  "like a dark black wall.");
} // Reset make_mountain

make_forest() {
  if (TD -> query_daytime()) {
  return line_break("The forest begins far off to the west on the other side "+
  "of the grass fields. You can't see much more at this distance.");
  }
    
  return line_break("You can hardly see the forest in this dark, it glides in "+
  "with the fields looking more like a hill in the distance.");
} // Reset make_forest

make_east() {
  if (TD -> query_daytime()) {
  return line_break("Scouting out on the east you notice that the sky turns "+
  "dark far off in the distance. Now and then flashes from lighting lights "+
  "up the sky. ");
  }
    
  return line_break("Far of in the distance to the east lightning lights up "+
  "the night sky. ");
} // Reset make_east

// -- Commands output --------------------------------------------------------

west()
{
  return "Traveling to the forest in the high grass, would take forever.";
} //Reset west

east()
{
  return "Traveling in the high grass, would take forever.";
} //Reset east

rest()
{
  object note;

  if(this_player()->query_property("wilhelm_welcome_note")) {
  "/std/msg"->msg("\bPRON sit\b$ down on a rock beside the road to rest.\n");
  return "It sure was nice to catch your breath after this long walk.\n";
  }
  else { 
        this_player()->add_property("wilhelm_welcome_note");
        note = clone_object("/players/wilhelm/area/siridfaath/obj/welcome_note");
        if(!transfer(note, this_player()))
          return "When you sit down to relax, you find a old piece of paper "+
		  "and pick it up.\n"; 
        else {
          add_object(note);
          return line_break("When you sit down to relax, you find an old "+
		  "piece of paper, but your hands are so full you set it on the "+
		  "ground.");
  }
  return 1;
  }
} //Reset rest

string cmd_enter(int arg, string e) {
  if(!e) return "Enter what?\n";
  else switch(e) {
    case "road" : return "You are standing on the road.\n";
    case "field" :
    case "grass" : return "You would just end up getting lost in the high."+
          "grass\n";
    case "mountain" : return "You are miles away from the mountain.\n";
    case "forest" :
    case "trees" :  return "You are miles away from the forest.\n"; 

  } 
} // Reset enter

string cmd_search(int arg, string s) {
  object note;
  if(!s) return "You should be more specific.\n";
  else switch(s) {
    case "grass" :
    case "field" :
    case "fields" : return  "You search around in the high grass, but all you "+
            "can find is more grass.\n";
    case "forest" :
    case "trees" :
    case "mountain" :
    case "mountain range" : return "It is too far away to search.\n";
    case "road" :
    case "gravel road" :
    case "path" : return "You find nothing.\n";
  
    case "rock" :
    case "rocks" :
      if(this_player()->query_property("wilhelm_welcome_note")) {
        return "You find nothing.\n";
      } 
      else { 
        this_player()->add_property("wilhelm_welcome_note");
        note = clone_object("/players/wilhelm/area/siridfaath/obj/welcome_note");
        if(!transfer(note, this_player()))
          return "You find a old piece of paper and pick it up.\n"; 
        else {
          add_object(note);
          return line_break("You find an old piece of paper, but your " +
            "hands are so full you set it on the ground.");
        }
      }
  }
} // Reset search

// -- Random weather --------------------------------------------------------

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
    "You hear the sound of thunder echo towards you from the east.",
    "Suddenly a flock of birds, flies up from the geass fields beside you and " +
    "head for the mountains.",
    "A strong gust blows in from the south, making the grass on " +
    "the open plains sway back and forth." });
  night_message = ({
    "A cold wind blows over the fields, making you shiver.",
    "A flock of birds flies by over your head, towards the forest in " +
    "the west.",
    "You hear the sound of thunder echo towards you from the east.",
    "Stars glimmer in the night sky above you.",
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
