/*A small road leading up to a small village.*/
// Note, maybe add a command to to cut the circus tent ropes for fun?

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
  add_property("no_walkers");
  add_exit("southeast", "siridfaath_dock");
  add_exit("west", "siridfaath4");

// -- Description ------------------------------------------------------------

  set_short("a small gravel road");
  set_long("A massive circus tent stands next to the road. The small road "+
  "turns southeast and ends down at a dock. To the west, you can walk back "+
  "into the village. A little off to the south there is a huge river. "+
  "Eastwards the plains turn into a small forest that follows the mountain "+
  "range and the river.");

// -- Items ------------------------------------------------------------------

  add_item( ({ "circus","tent" }),
    "The large circus tent is colored by red and yellow stripes. It's kept "+
	"up by ropes, securely attached by pegs in the ground. It seems to be "+
	"open. An old sign is planted into the ground next to the opening.");
  add_item( ({ "sign" }),
    "It's an old wooden sign. Seems to have been here for a long time.");
  add_item( ({ "rope" }),
    "Thick and strong ropes, that keeps the large circus tent up.");
  add_item( ({ "peg","pegs" }),
    "The pegs are stuck in the ground all around the tent. Helping the tent "+
    "stay up.");
  add_item( ({ "river","serpent river","serpent" }),
    "The huge Serpent river flows past further to the south.");
  add_item( ({ "road","path","gravel road" }),
    "A normal gravel road that goes between the village and the docks.");
  add_item( ({ "mountain", "mountan range","gigantic rock" }),
    "A gigantic rock, leaning on the heavens above. It looks dark and "+
    "soulless.");
  add_item( ({ "field","fields" }),
    "High grass grows on each side of the road. ");
  add_item( ({ "grass" }),
    "The grass is green and thick and goes up to your knees. ");
  add_item( ({ "forest" }),
    "The forest starts about two miles off to the east. It continues along the mountain range and the river.");
  add_item( ({ "village","town" }), 
    "The small village of Siridfaath is tou your west.");
    
  add_item_cmd("enter","circus","@cmd_enter()"); 
  add_item_cmd("read","sign","@cmd_sign()");
}

cmd_enter() 
{
    this_player()->move_player("into the circus",
      "/players/wilhelm/area/siridfaath/rooms/siridfaath_circus"); 
  return 1;
}
cmd_sign() {
write("  *------------------*  \n");
write("  | Circus is OPEN!  |  \n");
write("  |     Welcome!     |  \n");
write("  *------------------*  \n");
write("            ||          \n");
write("            ||          \n");
write("            ||          \n");
write("     ////////////////   \n");
  return 1;
}


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
    "You hear talking from inside the circus tent.",
    "A gust of wind blows over the fields.",
    "A flock of birds flyes up from the trees to the east.",
    "You hear strange animal sounds from inside the tent.",
    "Some villagers pass you on the road, carrying goods from the dock." });
  night_message = ({
    "You hear an owl hooting far in the distance.",
    "A gust of wind blows over the fields.",
    "The stars glimmer in the night sky.",
    "You hear strange animal sounds from inside the tent."});
  if(TD->query_daytime()) 
    tell_room(this_object(), day_message[random(sizeof(day_message))] + "\n");
  else
    tell_room(this_object(), 
      night_message[random(sizeof(night_message))] + "\n");
}
