/*Path towards BloodWood*/

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
#define TD "/obj/util/timed"
#define LOGGER load_object("/players/wilhelm/simple_logger")
#define BOULDER "/players/wilhelm/area/bloodwood/obj/boulder"
#define ROOT "/players/wilhelm/area/bloodwood/obj/root"
#include "/players/wilhelm/area/macros.h";

object boulder = load_object("/players/wilhelm/area/bloodwood/obj/boulder");

int boulder_stuck_path, root_in_path;


void reset(int arg) 
{
  ::reset(arg);
  boulder_stuck_path = 1;
  root_in_path = 6;
  
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_property("road");
  add_property("outdoors");
  add_property("wilhelm_path4");
  add_light(1);
  add_exit("west", "path5", "west", "do_west");
  add_exit("east", "path3");
  add_exit("southwest", "meadow1");
  add_exit("north", "meadow2");
 
  
// -- Description and settings -------------------------------------------

  set_short("a small path");
  set_long("You are standing on a narrow path in the middle of a large "+
  "meadow. To the west of you stands a massive forest and to the "+
  "east, the path continues along endless fields of grass. The fields around "+
  "you seem to be withering.");    

// -- Items and Commands -------------------------------------------------

  add_item( ({ "forest" }),
    "An oasis of dark green, shining like a vast emerald beside the plains.");
  add_item(({ "mountain", "mountains", "mountain range" }),"@make_mountain()");
  add_item( ({ "grass" }),
    "The grass is brown and seems to be withering. ");
  add_item( ({ "ground","soil" }),
    "The soil under your feet is dry and lifeless.");	
  add_item( ({ "field","fields","meadow",",meadows","plain","plains"}),
    "Hugh fields of withering grass that are waving and rustling the breeze.");
  add_item(({ "path", "track","trail" }),"@make_path()");	
  add_item(({ "root", "tree root" }),"@make_root()");
 
  add_command("search %s", "@cmd_search()");
  add_command("cut root", "@cmd_root()");
  add_command(({ "push boulder", "push large boulder" }), "@cmd_push()");
  
}


make_path() {
  if (root_in_path > 4) {
    return line_break("It's a narrow track between the grass field. A large tree "+
	"root sticks up from the ground, crossing the trail.");
  }
  if (root_in_path == 4) {
    return line_break("It's a narrow track between the grass field. A large tree root "+
	"sticks up from the ground, crossing the trail. It has small cuts in it. ");
  }
  if (root_in_path == 3) {
    return line_break("It's a narrow track between the grass field. A large half "+
	"chopped tree root sticks up from the ground, crossing the trail. ");
  }
  if (root_in_path == 2) {
    return line_break("It's a narrow track between the grass field. A large half "+
	"chopped tree root sticks up from the ground, crossing the trail. ");
  }
  if (root_in_path == 1) {
    return line_break("It's a narrow track between the grass field. A large tree "+
	"root sticks up from the ground, crossing the trail. It has almost been chopped "+
	"off.");
  }
    if (root_in_path < 1) {
    return line_break("It's a narrow track between the grass field. ");
  }
  return line_break("It's a narrow track between the grass field.");
}


make_root() {
	boulder = load_object(BOULDER);
  if(present("boulder", this_object())&& (root_in_path > 4)) {
    return line_break("It's a long tree root crossing the path you are walking on, "+
	"holding a large boulder in place.");
  }
  if (root_in_path > 4) {
    return line_break("It's a long tree root crossing the path you are walking on. ");
  }
  if(present("boulder", this_object())&& (root_in_path == 4)) {
    return line_break("It's a long tree root crossing the path you are walking on. "+
	"It has filled with small cuts. A large boulder is held in place by the root.");
  }
  if (root_in_path == 4) {
    return line_break("It's a long tree root crossing the path you are walking on. "+
	"It has filled with small cuts. ");
  }
    if(present("boulder", this_object())&& (root_in_path == 3)) {
    return line_break("It's a half chopped off the tree root, crossing the small "+
	"path. A large boulder is held in place by the root.");
  }
  if (root_in_path == 3) {
    return line_break("It's a half chopped off the tree root, crossing the small path.");
  }
  if(present("boulder", this_object())&& (root_in_path == 2)) {
    return line_break("It's a half chopped off the tree root, crossing the small "+
	"path. A large boulder is held in place by the root.");
  }
  if (root_in_path == 2) {
    return line_break("It's a half chopped off the tree root, crossing the small path.");
  }
  if(present("boulder", this_object())&& (root_in_path == 1)) {
    return line_break("It's a long tree root crossing the path you are walking on. It "+
	"has almost been chopped off. It is barely stopping a large boulder from rolling "+
	"off.");
  }
  if (root_in_path == 1) {
    return line_break("It's a long tree root crossing the path you are walking on. "+
	"It has almost been chopped off. ");
  }
    if (root_in_path < 1) {
    return line_break("A tree root is barely sticking up from the ground, it has been "+
	"chopped off. ");
  }
  return line_break("A tree root is barely sticking up from the ground, it has been "+
  "chopped off.");
}

// -- Commands output --------------------------------------------------------

cmd_push()
	{
  boulder = load_object(BOULDER);
  if(present("boulder", this_object())&& (boulder_stuck_path == 1)) {
    "/std/msg"->msg("\bPRON push\b{,es} the large boulder.\n");
	write ("It's stuck. \n");
    return 1;
	}
  if(present("boulder", this_object())&& (boulder_stuck_path == 0)){   
    "/std/msg"->msg("\bPRON push\b{,es} the large boulder.\n"+
	"The large boulder rolls of to the southwest.\n");
	boulder->move_boulder2();
	return 1;
	}
  return "The boulder isn't here.\n";
}



do_west() {
  string genus;
  
  if (   !this_player()-> query_property("wilhelm_bloodwood_horn")
  && !this_player()-> query_property("wilhelm_bloodwood_quest")
  && !this_player()-> query_puzzle("wilhelm_bloodwood_quest")) {
    this_player()->add_property("wilhelm_bloodwood_horn");

    "/std/msg"->msg("As \bPRON walk\b$ along the path toward the forest, you hear the sound of a horn. Someone has detected \bnewobj.\n", this_player());
  }
return 0;
	  
}


string cmd_root() {
  object *wep;
  boulder = load_object(BOULDER);
  
  wep=this_player()->query_wielded_objects();
  if (pointerp(wep)) {
    if (root_in_path < 1) { return "The root has already been removed."; }
	if (sizeof(wep) == 0) { return "You don't have anything to cut the root with."; }
    switch (wep[0]->query_type()) {
      case "chop" :
		if(root_in_path > 2)
		{root_in_path = root_in_path - 2;	
			return "You chop down with your weapon, making a large wound in "+
	        "the root. \n";}
		if(root_in_path < 3)
		{root_in_path = root_in_path - 2;
		boulder->cut_boulder();
		boulder_stuck_path  = 0;
		add_object(ROOT);
			return "With a mighty swing, you chop off the last of the root.\n";}
	  case "slash" :
		if(root_in_path > 1)
		{root_in_path = root_in_path - 1;	
			return "You slash at the root with your weapon, making a small wound "+
			"in the root.\n";}
		if(root_in_path < 2)
		{root_in_path = root_in_path - 1;	
	    boulder->cut_boulder();
		boulder_stuck_path  = 0;
		add_object(ROOT);
			return "With a hard swing, you manage to cut off the last of the root.\n";}
			boulder->cut_boulder();
	  case "pierce" : return "You stab at the root with your weapon. You will not manage "+
	  "to remove the root with this weaponry.\n";
      case "hand-to-hand" :
	  		if(root_in_path > 3)
		{root_in_path = root_in_path - 3;	
			return "With a powerful karate chop, you nearly cut the root in half.\n";}
		if(root_in_path < 4)
		{root_in_path = root_in_path - 3;
		boulder->cut_boulder();	
		boulder_stuck_path  = 0;
		add_object(ROOT);
			return "With a mighty karate chop, you easily cut off the last of the root.\n";}
	  case "crush" :
      case "fire" : 
      case "electricity" : 
      case "cold" : 
	  case "drain" : 
	  case "acid" : return "Your wielded weapon is not really suited for the job.\n"+
	  "Try to find a better weapon to remove the root.\n";
      default : return "Your wielded weapon is not really suited for the job.\n"+
	  "Try to find a better weapon to remove the root.\n";
    }
  }
  else return "foo";
  return "bar";
}

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




// -- Night and Day time descriptions ---------------------------------------

make_mountain() {
  if (TD -> query_daytime()) {
  return line_break("The huge mountain range to the east stretch up far into "+
  "the sky, crashing into the clouds.");
  }
    
  return line_break("In the dark night the mountain to the east just looks "+
  "like a dark black wall.");
} // Reset make_mountain

// -- Commands output --------------------------------------------------------




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
    "The dry meadow grass rustles in the breeze.",
    "A flock of birds flies's by over your head, towards the forest in the west.",
    "The sun shines through the clouds, lighting up the small path.",
    "The warm sun rays kissed your skin lightly, warming you from the inside out."});
  night_message = ({
    "The dry meadow grass rustles in the cold night breeze.",
    "You hear the sound of a strange animal echoing towards you in the twilight.",
    "Stars illuminated the darkness around you.",
    "The sun has gone to rest, the moon takes his place as the darkness begins to surround you."});
  if(TD->query_daytime()) 
    tell_room(this_object(), day_message[random(sizeof(day_message))] + "\n");
  else
    tell_room(this_object(), 
      night_message[random(sizeof(night_message))] + "\n");
}
