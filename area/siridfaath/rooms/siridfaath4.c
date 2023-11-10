/*A road in the village Siridfaath*/
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

  add_light(1);
  add_property("no_tree");
  add_property("road");
  add_exit("east", "siridfaath_road2");
  add_exit("west", "siridfaath3");

// -- Description and settings -----------------------------------------------

  set_short("east side of Siridfaath");
  set_long("This is the east side of the small village Siridfaath. There "+
  "is a tavern on the north side of the road. To the east, the road "+
  "leads out of town towards the river and to the west further into the "+
  "village. The enormous mountain towers over the houses to the north.");


// -- Items and Commands -----------------------------------------------------

  add_item( ({ "house","houses","building","buildings"  }),
    "There is many buildings around here, but the only one that looks "+
    "iteresting is the tavern.");
  add_item( ({ "inn","tavern","amberglass" }),
    "It's a large building on the north side of the road. A sign is "+
	"hanging over the front door. ");
  add_item( ({ "sign" }),
    "A beautifully carved sign,  with big letters.");
  add_item( ({ "mountain", "mountan range","gigantic rock","rock" }),
    "A gigantic rock, leaning on the heavens above. It looks dark and "+
    "soulless.");
  add_item( ({ "river" }),
    "The huge Serpent river flows past the village further to the south.");
  add_item(({ "village","town","siridfaath" }),"@make_town()");
  add_item(({ "wagon","cart" }),"@make_wagon()");
  add_item(({ "chest","box" }),"@make_chest()");

  add_command("search %s", "@cmd_search()");
  
  add_item_cmd("enter", ({"tavern","inn","amberglass" }), "@cmd_enter()");
  add_item_cmd("enter", ({"wagon","cart" }),"@cmd_enter_wagon()");
  add_item_cmd("read","sign","@cmd_sign()");
  add_item_cmd("open","chest","@cmd_chest()");

// -- Objects ----------------------------------------------------------------

add_object("/players/wilhelm/area/siridfaath/monsters/lucien");

}

cmd_enter() {
  this_player()->move_player("into the tavern","/players/wilhelm/area"+
  "/siridfaath/rooms/siridfaath_tavern");
  return 1;
}

cmd_enter_wagon() {
  if (present("merchant"))	  
      return line_break("You can't when the merchant is here.");      
	else 
	  this_player()->move_player("into the wagon",
      "/players/wilhelm/area/siridfaath/rooms/siridfaath_wagon");
	return 1;
}
   	


cmd_sign() {
write("AMBERGLASS\n");
  return 1;
}

init() {
  :: init();
  if (find_call_out("weather") == -1)
    call_out("weather", 180);
} 

// -- Night and Day time descriptions ----------------------------------------

make_town() {
  if (TD -> query_daytime()) {
  return line_break("The village of Siridfaath is small in size, but feels "+
  "like a crowded city with all the wagons and people comming in from the east.");
  }
  return line_break("The small village of Siridfaath feels lifeless during "+
  "the night.");
}

make_child() {
  if (TD -> query_daytime()) {
  return line_break("During the day, the streets are filled up with kids "+
  "playing in the streets.");
  }
  return line_break("It's late, they are probably all in bed.");
}

make_villager() {
  if (TD -> query_daytime()) {
  return line_break("The small village is filled up with people of many "+
  "diffrent races, some that you never seen before.");
  }
  return line_break("There isne't many people out in the streets at this "+
  "late hour.");
}

make_wagon() {
  if (present("merchant")) {
  return line_break("The wagon is packed up with different goods, but it "+
  "is hard to see what from here.The merchant is protecting his wagon. ");
  }
  return line_break("The wagon is packed up with different goods, but it "+
  "is hard to see what from here.");
}

make_chest() {
  if(this_player()->query_property("wilhelm_found_chest")) {
  return"It's a small wooden chest, concealed inside the wagon.\n"; }
  else
  return"What chest?\n";
}

open_chest() {
  if(this_player()->query_property("wilhelm_found_chest")) {
  return"It's inside the wagon, you can't reach it from here.\n"; }
  else
  return"What chest?\n";
}

string cmd_search(int arg, string s) {
 
  if(!s) return "You should be more specific.\n";
  else switch(s) {
  case "tavern" :
  case "inn" :
  case "building" : return  "You find nothing of interest.\n";
  case "mountain" :
  case "mountain range" : return "It is too far away to search.\n";
  case "road" :
  case "gravel road" :
  case "path" : return "You find nothing of interest.\n";

  case "wagon" :
  case "cart" : 
    if (this_player()-> query_property("wilhelm_call_guards") && present("merchant"))	  
      return line_break("Lucien shouts: GUARDS GUARDS!");
      this_player()->add_property("wilhelm_guards_guards");
	if(present ("merchant"))
	{
	  this_player()->add_property("wilhelm_call_guards");
	  return line_break("Lucien looks at you with anger in his eyes. Stop that "+
	  "or I will call the guards!");
	}
	else 
	  this_player()->add_property("wilhelm_found_chest");	
      return "Unfortunately, you find nothing of real use except a small chest "+
	  "in the back.\n";
   	}
 } // Reset search



 

// -- Random weather ---------------------------------------------------------

weather() 
{
  string *day_message, *night_message;
  
call_out("weather", 180);
  day_message = ({
    "A cat runs over the street and disappears behind a house wall.",
    "Some villagers enters the tavern.",
    "You hear laughter from inside the tavern.",
    "A wagon filled with goods, roll trough the street.",
    "You're past by some villagers on street, on their way to work." });
  night_message = ({
    "A cat runs over the street and disappears behind a house wall.",
    "The stars glimmer in the night sky.",
    "You hear people talking from inside the tavern.",
    "You can hear a dog howling far off in the distance.",
    "A drunk man staggers out from the tavern, seemingly heading home "+
	"at this late hour.",
    "A cold gust of wind blows over the roof tops." });
  if(TD->query_daytime()) 
    tell_room(this_object(), day_message[random(sizeof(day_message))] + "\n");
  else
    tell_room(this_object(), 
      night_message[random(sizeof(night_message))] + "\n");
}

