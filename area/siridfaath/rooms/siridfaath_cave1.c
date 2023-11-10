/*A cave under Siridfath*/


inherit "/std/room";
#define LOGGER load_object("/players/wilhelm/simple_logger")

int where_is_key;
mapping seen_key;
string name;


void reset(int arg)
{
  ::reset(arg);
    where_is_key = random(3) + 1;
    seen_key = ([]);
  if (arg)
    return;
    
// -- Properties ---------------------------------------------------------

  add_light(1);
  add_property("no_tree");
  add_property("inside");
  add_property("cave");
  add_exit("east", "siridfaath_cave2");
  add_hidden_exit("west", "siridfaath_cave1", 0, "west");

// -- Description and settings -------------------------------------------

  set_short("a cave");
  set_long("The well sent you down into a dim cavern beneath the town. "+
  "Water dribbles from the ceiling of the grotto. It's a small path "+
  "sliding further down east and to the west, a stream of freezing water "+
  "flows in. ");
 
// -- Items --------------------------------------------------------------
 
  add_item( ({ "cave","cavern","grotto" }),
  "It's a small cave path that slides down east. The walls are covered "+
  "with stone and dirt.");
  
  add_item( ({ "town","village" }),
  "You can't see it, but you guess you are beneath the village.");
  
  add_item( ({ "ceiling","roof" }),
  "Roots from trees and plants hang down from the ceiling and walls. ");
  
  add_item( ({ "wall","walls" }),
  "The walls are covered in roots and dirt. ");
  
  add_item( ({ "dirt","mud" }),
  "The cave is filled with dirt and mud. ");
  
  add_item( ({ "water" }),
  "There is water all around you. It drips down from the ceiling and "+
  "walls. A big lake to the west and a small river flows down east.");

  add_item( ({ "river" }),
  "It is a small river with ice cold water, that flows out of the lake "+
  "down east.");
  
  add_item( ({ "stream" }),
  "A large stream water rushes in from the west into the lake.");
  
  add_item(({ "lake","shore" }), "@exa_lake()");
  add_item(({ "root", "roots" }), "@exa_roots()");
  add_item(({ "path", "trail" }), "@exa_path()");
  add_item(({ "key" }), "@exa_key()");
  
  add_item_cmd(({ "get", "take" }), "key", "@cmd_get_key()");
  
  add_command("swim", "The water is ice cold and you can't get out in that direction. \n");
  add_command("enter %s", "@cmd_enter()");
  }

west()
{
  return "You can't swim back out in that direction.";
}


exa_roots() {
  if (where_is_key == 1) {
    name = this_player() -> query_real_name();
    seen_key[name] = 1;
    return line_break("Long twisting roots hang down from the ceiling and walls. "+
	"Behind one of the large roots, you see a small key.");
  }
  return line_break("Long twisting roots hang down from the ceiling and walls.");
}

exa_lake() {
  if (where_is_key == 2) {
    name = this_player() -> query_real_name();
    seen_key[name] = 1;
    return line_break("The lake is large and dark, filled with ice cold water. "+
	"There is no way you can get out the same way you got in. At the shore, "+
	"you can see a small key. ");
  }
  return line_break("The lake is large and dark, filled with ice cold water. "+
  "There is no way you can get out the same way you got in.");
}

exa_path() {
  if (where_is_key == 3) {
    name = this_player() -> query_real_name();
    seen_key[name] = 1;
    return line_break("It's a muddy path sliding town to the east. Stuck in "+
	"the mud beside you, you see a small key.");
  }
  return line_break("It's a muddy path sliding town to the east.");
}

exa_key() {
  name = this_player() -> query_real_name();
  if (seen_key[name]) {
    if (where_is_key == 1) {
      return "A small golden key is lying behind of the large roots.\n";
    }
    if (where_is_key == 2) {
      return "A small golden key is lying at the shore a little under the water. \n";
    }
	if (where_is_key == 3) {
      return "A small golden key is stuck in the mud beside you.\n";
    }
    return "The key is not here anymore. Someone took it.\n";

  }
  return "Huh? Is there a key here somewhere?\n";
}

cmd_get_key() {
  object wmkey;
  if (where_is_key == 0) {
    notify_fail("There is no key here.\n");
    return;
  }
  name = this_player() -> query_real_name();
  if (!seen_key[name]) {
    notify_fail("What key? You haven't seen any keys around here.\n");
    return;
  }
  wmkey = clone_object("/players/wilhelm/area/siridfaath/obj/merchant_key");
  if (!transfer(wmkey, this_player())) {
    where_is_key = 0;
    return "You pick up the key.\n";
  }
  notify_fail("You can't take the key. Maybe it's too heavy for you?\n");
} 

string cmd_enter(int arg, string e) {
  if(!e) return "Enter what?\n";
  else switch(e) {
    case "path" : return "You are standing on the path.\n";
    case "lake" :
    case "water" : return "The water is ice cold and you can't get out "+
	"in that direction.\n";
    case "river" : return "It's a small river you can't enter it.\n";

  } 
}