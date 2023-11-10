/*West side of the village Siridfaath*/

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
  add_property("road");
  add_exit("northwest", "siridfaath_road1");
  add_exit("east", "siridfaath3");

// -- Description and settings -------------------------------------------

  set_short("west side of Siridfaath");
  set_long("You have entered a small village called Siridfaath. Wooden houses "+
  "fill up the countryside around you. The road leads back out in the "+
  "grass fields to the northwest and deeper into the village to the east. "+
  "The huge mountain towers over the houses to the north.");

// -- Items --------------------------------------------------------------

  add_item( ({ "mountain", "mountan range","gigantic rock" }),
    "A gigantic rock, leaning on the heaven above. It looks dark and "+
    "soulless.");
  add_item( ({ "field","fields" }),
    "The grass fields surround the small village.");
  add_item( ({ "grass" }),
    "There isn't much grass here inside the village.");
  add_item( ({ "road","path","gravel road","street" }),
    "It's an old dusty gravel road that goes through the village to the "+
	"east and out towards the fields to the northwest. Waste fills up "+
	"the side of the street.");
  add_item( ({ "houses", "buildings", "wooden houses", "house" }),
    "This seems to be the poor side of the village. All the houses around "+
    "look old and rundown, some worse than others.");    
  add_item( ({ "trash","garbage","waste" }),
    "Foul waste that has been thrown on the road, making this part of "+
	"town stink.");
  add_item( ({ "alley","dark alley","small alley", "hidden alley" }),
    "It's small and dark, going in between to old houses.");   
  add_item( ({ "cat","cats" }),
    "The small village seems to be sprawling with cats, at least they "+
    "shouldn’t have a rat problem.");
  add_item( ({ "window","windows" }),
    "There is nothing particular about them.");
  
  add_item(({ "village","town","siridfaath" }),"@make_town()");
  add_item(({ "villager","villagers","people"}),"@make_villager()");
  add_item(({ "child","child's","childs","kid","kids" }),"@make_child()");
  add_item(({ "drunk man","drunk" }),"@make_drunk()");
  
  add_command(({ "enter %s" }), "@cmd_enter()");
  add_command(({ "listen" }), "@listen()");
  add_command(({ "smell","sniff" }), "@smell()");
  add_command("search %s", "@cmd_search()");

// -- Objects ---------------------------------------------------------------

  add_object("/players/wilhelm/area/siridfaath/monsters/siridfaath_guard");

}

// -- Commands output --------------------------------------------------------

cmd_enter(int arg, string c) {
  if(!c) return "Enter what?\n";
  switch(c) {
    case "house" :
    case "houses" :
    case "wooden house" : 
    case "wooden houses" :
    case "building" :
    case "buildings" : 
      return "They are all private homes, you can't enter any of them.\n";
    case "alley" :
    case "dark alley" :
      this_player()->move_player("into the dark alley",
      "/players/wilhelm/area/siridfaath/rooms/siridfaath_alley");
  }
  return 1;
} // Reset enter

listen()
{
  if (TD -> query_daytime()) {
  "/std/msg"->msg("\bPRON stop\b$ and listens to the surroundings.\n");
  return line_break("The village sure is noisy and full of life during the "+
  "day. ");
  }
  "/std/msg"->msg("\bPRON stop\b$ and listens to the surroundings.\n");
  return line_break("The street is empty and quiet. You hear a dog barking "+
  "from somewhere in the village..");
return 1;
}

smell()
{
"/std/msg"->msg("\bPRON sniff\b$.\n");
write("Eww, this part of the town, sure smells terrible.\n"); 
return 1;
}

// -- Night and Day time descriptions ---------------------------------------

make_town() {
  if (TD -> query_daytime()) {
  return line_break("The village looks old and worn down.");
  }
  return line_break("The small village feels lifeless during the night.");
}

make_child() {
  if (TD -> query_daytime()) {
  return line_break("Small children are playing around in the street.");
  }
  return line_break("It's late, they are probably all in bed.");
}

make_villager() {
  if (TD -> query_daytime()) {
  return line_break("The small village is filled up with people of many "+
  "diffrent races, some that you never seen before.");
  }
  return line_break("There aren't many people out in the streets at this "+
  "late hour.");
}

make_drunk() {
  if (TD -> query_daytime()) {
  return line_break("You can see different people in the street, but "+
  "none that look drunk.");
  }
  return line_break("The drunken man stumbles down the street, looking "+
  "a little lost.");
}

// e-- Random weather --------------------------------------------------------

init() {
  :: init();
  if (find_call_out("weather") == -1)
    call_out("weather", 30);
} 

string cmd_search(int arg, string s) {
 
  if(!s) return "You should be more specific.\n";
  else switch(s) {
  case "houses" :
  case "buildings" :
  case "building" : return  "You find nothing but trash around the houses.\n";
  case "mountain" :
  case "mountain range" : return "It is too far away to search.\n";
  case "road" :
  case "gravel road" :
  case "street" :
  case "path" : 
    return "You search around the street for something interesting, but all you "+
	"find is trash.\n";
  case "trash" :
  case "garbage" : 
  case "waste" : 
    return "Like a true detective, you search around the trash. It leads up to a hidden alley \n"+
	"behind two old houses.\n";
  case "alley" : 
  case "dark alley" : 
  case "small alley" : 
  case "hidden alley" : 
    return "You can't find anything from here.\n";
   	}
 } // Reset search  

weather() 
{
  string *day_message, *night_message;
  
call_out("weather", 180);
  day_message = ({
    "A cat runs over the streets and into a dark alley.",
    "The sun shines through the clouds.",
	"A foul smell blows through the street, coming from a dark alley behind "+
	"the houses.",
    "Someone throws trash right out of the window, almost "+
    "landing at your feet.",
    "You're past by some villagers on street." });
  night_message = ({
    "A cat runs over the streets and into a dark alley.",
    "The stars glimmer in the night sky.",
    "Far away you hear the sound of a dog barking, in the night.",
    "A drunk man walks by you." });
  if(TD->query_daytime()) 
    tell_room(this_object(), day_message[random(sizeof(day_message))] + "\n");
  else
    tell_room(this_object(), 
      night_message[random(sizeof(night_message))] + "\n");
}

