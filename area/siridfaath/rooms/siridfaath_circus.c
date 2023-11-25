/*A circus outside Siridfaath*/
//Mortal players will not have access to this room.
// -- This line is 78 characters long ----------------------------------------

inherit "/std/room";
//#define LOGGER load_object("/players/wilhelm/simple_logger")


void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;
    
// -- Properties -------------------------------------------------------------

  add_light(1);
  add_property("no_tree");
  add_property("no_fight");
  add_property("inside");
  add_exit("out", "siridfaath_road2");
  add_hidden_exit("east", "/players/wilhelm/workroom", "east, into the wall", "check_wiz");
  

// -- Description and settings -----------------------------------------------

  set_short("inside a circus");
  set_long("You are standing inside a large circus tent. The room is mostly "+
  "empty, except for a large blackboard dangling on the north wall. The ground is "+
  "covered with sawdust. ");

// -- Items ------------------------------------------------------------------

  add_item( ({ "board","blackboard"}),
    "The large blackboard is dangling on the north wall. It used to keep track "+
	"of all the puzzles in Wilhelms realm. You should read it.");
  add_item( ({ "sawdust"}),
    "The ground is covered with soft sawdust. "); 
  add_item( ({ "wall","walls"}),
    "Normal tent walls, except for the east wall. It seems to ripple like water, "+
	"how strange."); 
  add_item( ({ "east wall","portal","magical portal","magic portal"}),
    "The east wall ripples like water, it seems to be a magical portal."); 	
  
  add_object("/players/wilhelm/area/siridfaath/monsters/lorm");
  
  add_item_cmd("read",({"board","blackboard"}),"@read_blackboard()");
  
}

// -- Commands ---------------------------------------------------------------

read_blackboard() {
  mapping puzz = ([
    "Siridfaath:": ([
      "wilhelm_merchant_key": "Lost key:               ",
      "wilhelm_puzzle_bone": "Angry ork:              "
    ]),
    "Bloodwood:": ([
      "wilhelm_bloodwood_quest": "The curse of path magic:",
      "wilhelm_bloodwood_glove": "Find the missing gloves:"
    ])
  ]);

  string res, z, p;
  res = " +-------------------------------------+\n "+
      "|  Wilhelm's puzzle and quest board!  |\n"+
        " +-------------------------------------+\n";
  foreach(z, m_indices(puzz)) {
    res += " |                                     |\n";
    res +=sprintf(" | %-11s %-23s |\n", z, " ");
    foreach(p, m_indices(puzz[z])) {
      res += " | "+puzz[z][p]+(this_player()->query_puzzle(p)? " ":" not ")+"solved |\n";
    }
  }
  res += " +-------------------------------------+\n";
  write(res);
  return 1;
	  
}

check_wiz()
{
  if (this_player()->query_level() < 20) 
    return "You bang your head into an invisible wall. Wizards only!\n";
  return 0;
}


