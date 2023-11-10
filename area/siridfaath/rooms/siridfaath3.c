/*A road in the village Siridfaath*/

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
  add_exit("west", "siridfaath1");
  add_exit("south", "siridfaath2");
  add_exit("east", "siridfaath4");

// -- Description and settings -------------------------------------------

  set_short("middle of Siridfaath");
  set_long("You're walking on the main road through Siridfaath. Wooden "+
  "buildings are scattered all around the road that splits up here. One of "+
  "the buildings has a sign with 'Library' on it. To the west there are a "+
  "lot of rundown homes, to the south you can see a well and to the east, "+
  "the road passes a tavern before leading down to the Serpent river. "+
  "The huge mountain towers over the houses to the north.");

// -- Items --------------------------------------------------------------

  add_item( ({ "mountain", "mountan range","rock" }),
    "A gigantic rock, leaning on the heaven above. It looks dark and "+
    "soulless.");
  add_item( ({ "river" }),
    "The huge Serpent river flows past the village further to the south.");
  add_item( ({ "library" }),
    "The library looks much newer than the rest of the buildings. It's "+
    "two floors high and has a small set of stairs leading up to the front "+
    "doors. A sign hangs above the door with the letters 'Siridfaath Library'");
  add_item( ({ "door","doors" }),
    "It's a big double door leading into the library.");
  add_item( ({ "sign" }),
    "The sign hangs over the library doors.*");
  add_item( ({ "well" }),
    "It's a stone well, you can't see much more from here.");
  add_item( ({ "road","path","gravel road" }),
    "It's an old dusty gravel road that goes trough the village to the "+
    "east and west. To the south, it leads down to a well.");
  add_item( ({ "house","houses","building","buildings"  }),
    "There are many buildings around here, but the only one that looks "+
    "interesting is a library.");
  add_item( ({ "rundown homes","rundown home","rundown house","rundown houses" }),
    "The houses on the west side of town seems to be in desperate need of repair.");  	
  add_item( ({ "tavern" }),
    "The tavern is down the road to the east.");
  add_item(({ "village","town","siridfaath" }),"@make_town()");

    
  add_item_cmd("enter","library","@cmd_enter()");  
  add_item_cmd("read","sign","@cmd_sign()");
  
// -- Objects ------------------------------------------------------------

}

cmd_enter() {
  this_player()->move_player("into the library","/players/wilhelm/area/siridfaath/rooms/"+
  "siridfaath_library");
  return 1;
}

cmd_sign() {
write("  ++---------------------++  \n");
write("  || Siridfaath Library  ||  \n");
write("  ||        and          ||  \n");
write("  || Tourist information ||  \n");
write("  ++---------------------++  \n");
  return 1;
}

init() {
  :: init();
  if (find_call_out("weather") == -1)
    call_out("weather", 30);
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
  "different races, some that you have never seen before.");
  }
  return line_break("There isn't many people out in the streets at this "+
  "late hour.");
}

make_drunk() {
  if (TD -> query_daytime()) {
  return line_break("You can see different people in the street, but "+
  "none that look drunk.");
  }
  return line_break("A drunken man stumbles down the street, looking "+
  "a little lost.");
}


// -- Random weather --------------------------------------------------------

weather() 
{
  string *day_message, *night_message;
  
call_out("weather", 180);
  day_message = ({
    "A cat runs over the streets and disappears behind some houses.",
    "The sun shines through the clouds.",
    "A group of children runs past you in the street.",
    "A villager walks by you." });
  night_message = ({
    "A cat runs over the streets and disappears behind some houses.",
    "The stars glimmer in the night sky.",
    "Far away you hear the sound of a dog barking, in the night.",
    "A drunk man walks by you." });
  if(TD->query_daytime()) 
    tell_room(this_object(), day_message[random(sizeof(day_message))] + "\n");
  else
    tell_room(this_object(), 
       night_message[random(sizeof(night_message))] + "\n");
}
