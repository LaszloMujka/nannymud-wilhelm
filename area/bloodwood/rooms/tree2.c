/*BloodWood*/

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
#define TD "/obj/util/timed"
//#define LOGGER load_object("/players/wilhelm/simple_logger")

int exa_trunk,climb_vine;
mapping seen_trunk;
string name;



void reset(int arg) 
{
  ::reset(arg);
  climb_vine = 1;
  exa_trunk = 1;
  seen_trunk = ([]);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_property("forest");
  add_light(1);
  
  
// -- Description and settings -------------------------------------------

  set_short("up a tree");
  set_long("You are stuck up in a large tree, just inside the Bloodwood "+
  "forest. The tree is overgrown with long twisting vines and sharp thorns. ");    

// -- Items and Commands -------------------------------------------------
  
	add_item(({"tree"}),
		"You are hanging on to the large strange tree many meters above the "+
		"ground. Its trunk and branches are covered in twisting vines and "+
		"thorns.");
	add_item(({"trees","forest"}),
		"The enormous forest is made up of huge towering trees, growing "+
		"tightly together between the underbrush.");
	add_item(({"branch","branches"}),
		"Her far up, the tree has many long firm branches covered in thorns "+
		"and vines. Unfortunately, they don't continue all the way down.");		
	add_item(({"underbrush"}),
		"You can see the underbrush far below you, small trees and plants "+
		"that are growing beneath the larger trees.");	
	add_item(({"thorn","thorns"}),
		"The tree is covered in sharp pointy thorns.");		
	add_item(({"plant","plants"}),
		"The forest floor is covered in large plants, but you can't see much "+
		"more from up here.");

	add_item(({"field","fields","meadow"}),
		"The forest is so dense, you can't see the fields from here.");	
	add_item(({ "trunk","tree trunk" }),
		"@exa_trunk()");
	add_item(({ "vine","vines" }),
		"@exa_vine()");	
	add_item_cmd("climb","vine","@cmd_vine()");
	add_item_cmd("climb","vines","@cmd_vine()");
	add_item_cmd("jump","vines","@cmd_vine()");
	add_item_cmd("jump","vine","@cmd_vine()");
	
}

exa_vine() {
  if (climb_vine == 1) {
  return line_break("The tree is filled with long twisting vines expanding down to "+
  "the forest floor. Unfortanly all the vines around you seem sturdy enough to "+
  "climb on. ");
   }

  return line_break("The tree is filled with long twisting vines expanding down to "+
  "the forest floor. Just out of your arms reach a large vine dangles down to the "+
  "forest floor.");
}

exa_trunk() {
  if ((exa_trunk == 1) && (climb_vine == 1)) {
    name = this_player() -> query_real_name();
    seen_trunk[name] = 1;
	add_item_cmd("climb","thorns","@cmd_thorns()");
    return line_break("The trunk of the tree seems to have even larger thorns "+
	"than on the branches. If you are careful you might be able to climb on them "+
	"to get down.");
   }

  return line_break("The trunk of the tree seems to have even larger thorns than "+
  "on the branches.  You managed to use them as a ladder this far, but now you can't "+
  "find anymore suitable to hold your weight.");
}

cmd_vine() {
  if (climb_vine == 1) {
    return line_break("All the vines that might be able to hold your weight are "+
	"out of reach.");
   }
	this_player()->move_player("down",
    "/players/wilhelm/area/bloodwood/rooms/forest3");
  return line_break("A large vine hangs just out of your arms reach. Not seeing any "+
  "other options to get down, you jump out to the vine. Luckily it holds your weight "+
  "and you manage to climb down.");
}

cmd_thorns() {
  name = this_player() -> query_real_name();
  if (seen_trunk[name]) {
    if ((exa_trunk == 1) && (climb_vine == 1)) {
	climb_vine = climb_vine = 0;
	return line_break("You carefully climb down the large tree trunk using the thorns as "+
	"footholds. When you are about halfway down you can't find anymore large enough "+
	"to step on. You need to find something else before you can continue.");
	}
 	return line_break("There is no reason to climb back up, and you can't find any thorns "+
	"suitable to climb down. Try something else.");	
}}

// -- Commands output --------------------------------------------------------

// -- Night and Day time descriptions ---------------------------------------





// -- Random happenings -------------------------------------------------------
