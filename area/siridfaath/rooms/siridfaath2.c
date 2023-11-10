/*A well in the village Siridfaath*/
/*
Plans for this room

The well should be able to:
Lower a bucket into the water.
Raise it up again if its down.
Be able to get water from the bucket.
Be able to climb into the well, only when the bucket is down.

If someone raise it when your down there you can't get up.
Says in this room will be heard inside the well and the other way around.

You can look down into the well and see who is in there.
The well is over a underground river, with a grind between, so 
dropped items will be lost.

*/

#define TD "/obj/util/timed"
#define BUCKET "/players/wilhelm/area/siridfaath/obj/bucket"
#define LOGGER load_object("/players/wilhelm/simple_logger")

int where_is_bucket;
inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
object bucket = load_object("/players/wilhelm/area/siridfaath/obj/bucket");

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;

// -- Properties ---------------------------------------------------------

  add_light(1);
  add_property("no_tree");
  add_property("road");
  add_property("no_teleport");
  add_property("no_walkers");
  add_exit("north", "siridfaath3", 0, "@holding_bucket()");
  where_is_bucket = 0;
  enable_commands();

// -- Description and settings -------------------------------------------

  set_short("in front of a well");
  set_long("Having traveled a little away from the main road, you come to a "+
    "deep stone well in the middle of a small clearing. This is where the "+
    "inhabitants of the village get their fresh water. The area is surrounded "+
    "by houses of all sizes. Behind the buildings to the south the huge "+
    "Serpent river coils by and to the north the large mountain towers "+
    "up in the sky.");

// -- Items --------------------------------------------------------------

  add_item( ({ "road","path" }),
    "The small path ends up at the well. If you follow it north it leads back "+
    "to the main road");
  add_item( ({ "clearing" }),
    "The small clearing around the well, is covered with trampled grass.");
  add_item( ({ "grass" }),
    "The short grass around the well is heavily trampled by all the villagers "+
    "that use the well.");
  add_item( ({ "crank" }),
    "The crank can be turned to raise and lower the bucked, into the well.");
  add_item( ({ "pole","windlass" }),
    "The thick wooden pole is fasted under the well roof. A long rope is twisted "+
    "around it. It has a small crank at the end.");   
  add_item( ({ "beam","beams"  }),
    "Four sturdy beams around the well, holds the well roof in place.");
  add_item( ({ "rope" }),
    "The rope is tied to the bucket in one end and goes around the thick "+
    "windlass.");
  add_item( ({ "roof","well roof" }),
    "Four beams caries the roof around the well.");
  add_item( ({ "house","houses","building","buildings"  }),
    "Private homes for the more wealthy inhabitants of Siridfaath.");
  add_item( ({ "mountain", "mountan range" }),
    "A gigantic rock, leaning on the heaven above. It looks dark and "+
    "soulless.");
  add_item( ({ "river","serpent river","huge river" }),
    "The huge Serpent river flows past the village further to the south.");
  add_item( ({ "cat","cats" }),
    "This small village seems to be sprawling with cats, at least they "+
    "they shouldn’t have a rat problem.");
  
  add_item(({ "village","town","siridfaath" }),"@make_town()");
  add_item( ({ "well", "stone well" }), "@make_well()");
  add_item(({ "villager", "villagers", "inhabitants","people" }),
  "@make_villagers()"); 
  
  add_item_cmd("cut","rope","@cmd_rope()");
  add_item_cmd("enter","well","@cmd_enter()");
  add_item_cmd( ({ "turn", "rotate" }), ({ "crank" }), "@cmd_crank()"); 

// -- Objects ------------------------------------------------------------

  add_object(load_object(BUCKET));
  add_object("/players/wilhelm/area/siridfaath/monsters/mirielle"); 

}
make_well() {
  write("The well is made of stone and has a roof over it. It has a wooden "+
  "windlass in \n"); 
  write("the middle with a rope around, tied to a bucket.\n");
  write("When you look down into the dark well you see.\n");
  write("/obj/look"->describe_inventory(load_object("/players/wilhelm/area/siridfaath/rooms/siridfaath_well"), 1, this_player()));
  return "";
}

// -- Night and Day time descriptions ---------------------------------------

make_town() {
  if (TD -> query_daytime()) {
  return line_break("This part of the village is much less crowded then the main "+
  "road.");
  }
  return line_break("The small village of Siridfaath feels lifeless during "+
  "the night.");
}

make_child() {
  if (TD -> query_daytime()) {
  return line_break("You can't see any children this close to the well.");
  }
  return line_break("It's late, they are probably all in bed.");
}

make_wagon() {
  if (TD -> query_daytime()) {
  return line_break("Ordinary wagons, used to move goods in.");
  }
  return line_break("There isn't any wagons here this late.");
}

make_villager() {
  if (TD -> query_daytime()) {
  return line_break("The small village is filled up with people of many "+
  "diffrent races, some that you never seen before.");
  }
  return line_break("There aren't many people out in the streets at this "+
  "late hour.");
}

// -- Commands --------------------------------------------------------------

cmd_rope() {
  write("The old bucket is for better use tied to the well.\n");
  return 1;
}
/*
old_cmd_crank() {
  if (where_is_bucket == 0) {
    if(environment(bucket) != load_object("players/wilhelm/rooms/siridfaath2")) 
      return "The bucket can't be lowered while it's being held.";
    "/std/msg"->msg("\bPRON lower\b$ the bucket into the well.\n");
    where_is_bucket = 1;
    move_object(bucket, "players/wilhelm/rooms/siridfaath_well");
    tell_room ("/players/wilhelm/area/siridfaath/rooms/siridfaath_well",
               "A bucket lands beside you with a loud splash.\n");
    bucket->set_water(3); 
    return 1;
  }
  if (where_is_bucket == 1) {
    if(environment(bucket) != load_object
    ("/players/wilhelm/area/siridfaath/rooms/siridfaath_well"))
      return "The bucket seems to be stuck in the well.";
    "/std/msg"->msg("\bPRON raise\b$ the bucket from the well. It's filled "+
      "with water.\n");
    move_object(bucket, "/players/wilhelm/area/siridfaath/rooms/siridfaath2");
    tell_room ("/players/wilhelm/area/siridfaath/rooms/siridfaath_well",
               "Someone raised the bucket from outside the well.\n");
    where_is_bucket = 0;
    return 1;
  }
}
*/
cmd_crank() {
  bucket = load_object(BUCKET);
  if(bucket->query_raised()) {
    if(environment(bucket)->is_player())
      return "The bucket can't be lowered while it's being held.";
    if(bucket->lower_bucket())
      "/std/msg"->msg("\bPRON lower\b$ the bucket into the well.\n");
  }
  else {
    if(environment(bucket)->is_player())
      return "The bucket seems to be stuck in the well.";
    if(bucket->raise_bucket())
      "/std/msg"->msg("\bPRON raise\b$ the bucket from the well. It's filled "+
        "with water.\n");
  }
  return 1;
}
/*
old_cmd_enter() {
  if (where_is_bucket == 0) {
  write("You need something to hold on to. If you jump down you never get up "+
  "again.\n");
  return 1;}
    if (where_is_bucket == 1) {
  this_player()->move_player("down the well","/players/wilhelm/area/siridfaath/rooms/"+
  "siridfaath_well");
  return 1;}
}  
*/
cmd_enter() {
  bucket = load_object(BUCKET);
  if(bucket->query_raised()) {
    write("You need something to hold on to. If you jump down you never " +
      "get up again.\n");
    return 1;
  }
  else {
    this_player()->move_player("down the well",
      "/players/wilhelm/area/siridfaath/rooms/siridfaath_well");
    return 1;
  }
}  

holding_bucket() {
  object o;
  foreach(o, all_inventory(this_player())) {
    if(o == load_object(BUCKET))
      return "The bucket is tied to the well, you can't leave while holding it.";
  }
}

// -- Catch talk from inside the well ---------------------------------------

catch_tell(str) {
  if(sscanf(str, "%*s says: %s", str) != 2) return;

  tell_room("/players/wilhelm/area/siridfaath/rooms/siridfaath_well", 
    "You hear someone talking from outside the well: " + str);
}

// -- Random weather --------------------------------------------------------
 
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
    "A cat runs over the streets and disappears behind some houses.",
    "A villager throws a coin down the well, wonder what he wished for.",
    "Some kids playfully dance around the street.",
    "The sun shines through the clouds.",
    "You hear someone shouting from the main road.",
    "You hear something splash from inside the well, is there something down "+
    "there?",});
  night_message = ({
    "A cat runs over the streets and disappears behind some houses.",
    "The stars glimmer in the night sky.",
    "Far away you hear the sound of a dog barking, in the night.",
    "You hear something splash from inside the well, is there something down "+
    "there?",
    "A drunk man walks by you." });
  if(TD->query_daytime()) 
    tell_room(this_object(), day_message[random(sizeof(day_message))] + "\n");
  else
    tell_room(this_object(), 
       night_message[random(sizeof(night_message))] + "\n");
}




