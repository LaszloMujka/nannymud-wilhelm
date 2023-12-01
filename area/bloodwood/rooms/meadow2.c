/*Path towards BloodWood*/

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
#define TD "/obj/util/timed"
//#define LOGGER load_object("/players/wilhelm/simple_logger")
#define BOULDER "/players/wilhelm/area/bloodwood/obj/boulder"
#include "/players/wilhelm/area/macros.h";

//object boulder = load_object("/players/wilhelm/area/bloodwood/obj/boulder");

int dig,boulder,boulder_stuck,boulder_is_here,mat_is_here;

reset(arg) {
  object boulder, mat;
  boulder_stuck = 1;
  boulder_is_here = 1;
  ::reset(arg);
  
  
  if(!arg) {	
    

// -- Properties ---------------------------------------------------------
// -- Hidden Exits -------------------------------------------------------

  add_property("outdoors");
  add_property("wilhelm_meadow2");
  add_light(1);
  add_exit("south", "path4");
  add_hidden_exit("west", "meadow2", 0, "forest");
  add_hidden_exit("east", "meadow2", 0, "lost");
  
  
  
// -- Description and settings -------------------------------------------

  set_short("a meadow");
  set_long("You are standing in a large meadow of decaying grass, it "+
  "continues on along the large forest west of you. To the south, you "+
  "can walk back to the small path.");    

// -- Items and Commands -------------------------------------------------

  add_item( ({ "forest" }),
    "An oasis of dark green, shining like a vast emerald beside the plains. "+
	"It grows thick, not making you able to enter it from here.");
  add_item(({ "mountain", "mountains", "mountain range" }),"@make_mountain()");
  add_item(({ "path","trail","track" }), 
    "The small path is back to the south.");
  add_item( ({ "grass" }),
    "The grass around you is withering and much shorter here closer to the forest.");
  add_item( ({ "field","fields","meadow",",meadows","plain","plains"}),
    "Hugh fields of withering grass, that are waving and rustling by the gentle breeze.");
  add_item(({ "ground", "soil","dirt" }),"@make_ground()");	
  add_item(({ "rock", "rocks","small rock","small rocks" }),"@make_rocks()");	
 
  add_command("search %s", "@cmd_search()");
  add_item_cmd("enter","forest","@cmd_enter()"); 
  
  add_command("remove rocks", "@cmd_dig()");
  add_command("take rocks", "@cmd_dig()");
  add_command("take rock", "@cmd_dig()");
  add_command("dig rocks", "@cmd_dig()");
  add_command("dig ground", "@cmd_dig()");
  add_command("dig", "@cmd_dig()");
  add_command(({ "push boulder", "push large boulder" }), "@cmd_push()");
  add_object(load_object(BOULDER));
  
 }

  if(!mat_is_here) {
    mat = find_object("/players/wilhelm/area/bloodwood/obj/boulder");
    if(!mat || !environment(mat) || 
       (environment(mat) -> is_room() && 
	environment(mat) != this_object())) {
      mat_is_here = 1;
      if (mat)
	destruct(mat);
    }
  }

} 


make_ground() {
  if(present("wilhelm_boulder", this_object()) &&(boulder_stuck == 1))  {
    return line_break("The ground under your feet is dry and lifeless. "+
	"Compact soil and rocks are stacked around a large boulder.");
  }
  if(present("wilhelm_boulder", this_object()) &&(boulder_stuck == 0))  {
    return line_break("The ground under your feet is dry and lifeless. "+
	"Compact soil and rocks are scattered around the meadow.");
  }
  else
   return line_break("The ground under your feet is dry and lifeless. "+
   "Small rocks are scattered around the field.");
} 

make_rocks() {
  if(present("wilhelm_boulder", this_object()))  {
    
    return line_break("Small rocks are tucked around the large boulder, "+
	"keeping it in place.");
  }
  else
   return line_break("Small rocks are scattered around the field.");
} 

// -- Hidden Exits -------------------------------------------------------

forest()
{
  return "The forest is to thick to enter.";
} 

lost()
{
  return "Traveling into the high grass will just get you lost.";
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

cmd_dig()
	{
  boulder = load_object(BOULDER);
  if(present("boulder", this_object())&& (boulder_stuck == 1)&& (present("shovel", TP))){
    "/std/msg"->msg("\bPRON dig\b$ up the ground around the large boulder.\n");
	boulder_stuck = 0;
	boulder->dig_boulder();
    return 1;
	}
  if(present("boulder", this_object())&& (boulder_stuck == 1)){
	write ("You try to remove the rocks and dirt with your hands, but soon figure out \n"+
    "that its a foolish task without the right tool.\n");
    return 1;
	} 	
  if(present("boulder", this_object())&& (boulder_stuck == 0)){   
    write ("The ground around the boulder has already been cleaned up. \n");
	return 1;
	}
  return "You see no reason to dig here.\n";
}

cmd_push()
	{
  boulder = load_object(BOULDER);
  if(present("boulder", this_object())&& (boulder_stuck == 1)) {
      "/std/msg"->msg("You try to push the large boulder.\n\b|" +
		  "\bPRON tries to push the boulder, but fails.\n");
	write ("It's stuck, you need to remove the rocks around it first. \n");
    return 1;
	}
  if(present("boulder", this_object())&& (boulder_stuck == 0)){   
    "/std/msg"->msg("\bPRON push\b{,es} the large boulder.\n"+
	"The large boulder rolls of to the south.");
	boulder_is_here = 0;
	"/obj/daemon/reclaimd" -> register(boulder,15,"@return_boulder()");
	boulder->move_boulder();
	boulder->reset(1);
	return 1;
	}
  return "The boulder isn't here.\n";
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
    case "path" : return "You can't search the path from here.\n";

  }
}

cmd_enter() {
return "The forest is to thick to enter from here.\n";
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
    "The dry meadow grass rustles in the breeze.",
    "A flock of birds flies's by over your head, towards the forest in the west.",
    "The sun shines through the clouds.",
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

