#define NAME "wilhelm"
#define DEST "room/castle_room"
#define AREAD "/obj/daemon/area_d"
#define ENTRANCE ("/room/west_road/road7")
#define START ("/players/wilhelm/area/siridfaath/rooms/area_entry")
#include <puzzled.h>

// -- This line is 78 characters long ---------------------------------------

inherit "std/stationary";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  if (AREAD->query_open("/players/wilhelm"))
  move_object(this_object(), ENTRANCE);
  ENTRANCE->add_exit("south", START);
  
  set_name("road");
  add_alias(({"path","small road"}));
  add_property("in_long_short","A small path leads south");
  
  set_long("A small gravel road leads down from the hillside towards large "+
  "open plains to the south. It stretches on far into the distance.");
  add_item(({"road","path","small road","small gravel road"}),
    "It's a small road filled up with gravel that leads off in the distance "+
	"southwards. ");
  add_item( ({ "field","fields","plain","plains"}),
    "The fields around the south road stretch on for miles in all directions. ");
  add_item(({"gravel"}),
    "It is plain small rocks that fill up the south road.");
  



// -- PUZZLES ---------------------------------------------------------------

  PUZZLED -> add_puzzle("wilhelm_merchant_key");
  PUZZLED -> add_puzzle("wilhelm_puzzle_bone");
  PUZZLED -> add_puzzle("wilhelm_bloodwood_gloves");
  PUZZLED -> add_puzzle("wilhelm_bloodwood_quest");

}