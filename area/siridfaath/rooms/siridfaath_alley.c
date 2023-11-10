/*A dark alley in Siridfath*/
// -- This line is 78 characters long ----------------------------------------

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
#define TD "/obj/util/timed"
#define LOGGER load_object("/players/wilhelm/simple_logger")

int rat_found = 0;

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;
    
  // -- Properties ----------------------------------------------------------

  add_light(1);
  
  // -- Exits ---------------------------------------------------------------

  add_exit("south", "siridfaath1"); 
  
// -- Description -----------------------------------------------------------

  set_short("a dark alley");
  set_long("You try not to vomit from the awful smell in this alley. The "+
  "villagers seem to use this area as a garbage dump. Heaps of trash flow "+
  "all around you. To the south the alley leaves back to the main road.");
 
  // -- Items and Commands --------------------------------------------------
 
  add_item( ({ "grabage", "trash" }),
    "You are standing in it. There is no way to tell what you can find here. "+
	"But a good guess, would be rotten food.");
  add_item( ({ "food", "rotten food" }),
    "Most of the trash here, smells like rotten food.");
  add_item( ({ "alley", "back alley" }),
    "It's a small dark alley, between to rundown houses. The villagers seems to "+
	"use this place as a garbage dumb.");
	
  add_command("search %s", "@cmd_search()");
}

string cmd_search(int arg, string s) {
  object rat;
  if(!s) return "You should be more specific.\n";
  else switch(s) {
  case "wall" :
	case "walls" :
	case "house" :
  case "houses" :
	case "building" :
  case "buildings" : return  "You search around the house walls, but  "+
          "find nothing of interest.\n";
  case "mountain" :
  case "mountain range" : return "It is too far away to search.\n";
  case "road" :
  case "gravel road" :
  case "path" : return "You find nothing, but trash.\n";

  case "trash" :
  case "garbage" :
	  if(rat_found)
	    return line_break("You find nothing of interest.");
    if(this_player()->query_property("wilhelm_listen_ork")) {
	    rat = clone_object("/players/wilhelm/area/siridfaath/obj/sewer_rat");
		  rat_found = 1;
      if(!transfer(rat, this_player()))
        add_object(rat);
		  return line_break("You search around in the stinking garbage "+
		    "heap. Between all the rotten food you find the corpse of a "+
		    "dead rat! Great just what you need.");
    }  
    else
      return line_break ("You carefully search around in the stinking garbage "+
    		"heap. There isen't much of interest here, mostly just rotten "+
    		"food. You also notice a dead rat. Who on earth would need a "+
    		"dead rat?");
  } // switch
} // Reset search

