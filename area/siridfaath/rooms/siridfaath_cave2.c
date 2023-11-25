/*A cave under Siridfath*/


inherit "/std/room";
//#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;
    
// -- Properties ---------------------------------------------------------

  add_light(1);
  add_property("no_tree");
  add_property("inside");
  add_property("cave");
  add_exit("west", "siridfaath_cave1");

// -- Description and settings -------------------------------------------

  set_short("a cave");
  set_long("The small path turns into a larger room inside the cavern. "+
  "The walls and ceiling are covered with roots and spider web. A small "+
  "river of water flows near you down into a pit on the east side of the "+
  "cave. ");
  
// -- Items --------------------------------------------------------------

  add_item( ({ "town","village" }),
  "You can't see it, but you guess you are beneath the village.");
  
  add_item( ({ "cave","cavern","grotto" }),
  "It's a dark and moist cave, with roots and spider webs hanging from the "+
  "ceiling.");  
  
  add_item( ({ "path" }),
  "It's a small muddy path inside the cave, leading further up west.");
  
  add_item( ({ "ceiling","roof" }),
  "Spider web and roots hang down from the ceiling. ");
  
  add_item( ({ "roots","root" }),
  "Roots from trees and plants hang down the ceiling. Small trickles "+
  "of water, slide down along the roots.");
  
  add_item( ({ "web","spiderweb","spider web" }),
  "Large and sticky, this can't have been made from a normal sized spider.");
  
  add_item( ({ "water" }),
  "The small river of water flows down beside you into a small pit on the "+
  "east side of the room.");  

  add_item( ({ "pit" }),
  "The pit is filled with cold water, that flows further to the east.");  
  
  
// -- Objects ------------------------------------------------------------

	add_object("/players/wilhelm/area/siridfaath/monsters/spider");
	
    add_command(({ "enter %s" }), "@cmd_enter()");
  
  
}

cmd_enter(int arg, string c) {
  if(!c) return "Enter what?\n";
  switch(c) {
    case "pit" :
    case "hole" :
    case "water" : 
	write("You jump down into the cold water and swim toward the light in \n"+
	"the tunnel. After a few strokes, you find yourself again dragged by \n"+
	"the current of the water. Struggling for air you swim up towards the \n"+
	"surface and find yourself in the huge serpent river.  With your last \n"+
	"strength, you manage to swim ashore and find yourself back at the \n"+
	"docks in the small village.\n"+
	"\n");
      this_player()->move_player("into the pit",
      "/players/wilhelm/area/siridfaath/rooms/siridfaath_dock");
  }
  return 1;
} // Reset enter



