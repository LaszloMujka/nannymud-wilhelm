/*BloodWood*/

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
inherit "/players/wilhelm/area/bloodwood/rooms/forest_rooms";
#define TD "/obj/util/timed"
//#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_property("road");
  add_property("forest");
  add_light(1);
  add_exit("southeast", "forest_p2");
  add_exit("north", "forest_p4");
  add_hidden_exit("south", "forest8", "into the forest","check_exit_s");
  add_hidden_exit("east", "forest26", "east, into the forest","check_exit_e");
  
// -- Description and settings -------------------------------------------

  set_short("bloodwood path");
  set_long("You are standing on a small trail inside the enormous forest. "+
  "Huge trees loom above you, covering up the sky. Large and thick vines "+
  "hang between the towering trees. ");    

// -- Items and Commands -------------------------------------------------
  
  add_item(({ "tree", "trees" }),"@make_tree()");
  add_item(({ "sky" }),"@make_sky()");
  add_item(({ "path","trail" }), 
    "A faint path through the underbrush.");
  add_item(({ "forest" }), 
    "The enormous forest is made up of huge towering trees, growing tightly "+
	"together between the underbrush. ");
  add_item(({ "plant","plants","small tree","small trees" }), 
    "Low-growing plants that seem to twine about your feet at their "+
	"own accord.");
  add_item(({ "vine","vines" }), 
    "The trees are overgrown with thick looping coils of vines, that "+
	"stretches down from the high tree branches down to the ground.");
  add_item( ({ "underbrush" }),
    "Small trees and plants that are growing beneath the larger trees, "+
	"some of the plants have large flowers.");
  add_item( ({ "ground" }),
    "The ground beneath your feet is soft. Like hard soaking rain has "+
	"passed through mere minutes ago ... not like the dry plains outside "+
	"the forest.");	
  add_item(({ "flowers" }), 
    "Some of the plants have flowers as large as dinner plates, all in red "+
	"and blue and purples so bright you almost feel dizzy looking at them.");
  add_item(({ "moss","tendril","tendrils" }), 
    "Large tendrils of red-tinged moss cover the trees. ");	
	
}

// -- Night and Day time descriptions ---------------------------------------

make_tree() {
  if (TD -> query_daytime()) {
  return line_break("Large dark green trees, with a shade of reddish tint. "+
  "They stretch up far into the sky. Tendrils of hanging moss hang down "+
  "from the branches and large vines are entangled between the trees.");
  }
    
  return line_break("Large dark green trees, with a shade of reddish tint. "+
  "They stretch up far into the night sky. Tendrils of hanging moss hang down "+
  "from the branches and large vines are entangled between the trees.");
}

make_sky() {
  if (TD -> query_daytime()) {
  return line_break(" You can barely see the sky between all the trees.");
  }
    
  return line_break(" You can barely see the night sky between all the trees.");
}

// -- Commands output --------------------------------------------------------

check_exit_e() {
  if (this_player()->query_npc() && creator(this_player())=="wilhelm"){
    return 1;
  }
  if ((this_player()-> query_property("wilhelm_bloodwood_quest")) ||
     (this_player()-> query_puzzle("wilhelm_bloodwood_quest")))
  {
    // this_player()->move_player("east",
    // "/players/wilhelm/area/bloodwood/rooms/forest26");	  
  return;
  }	
  if (this_player()-> query_property("wilhelm_bloodwood_horn")){
  return line_break("The plants and trees around you seem to shift and sway "+
  "blocking the path east.");
  }
}
check_exit_s() {
  if (this_player()->query_npc() && creator(this_player())=="wilhelm"){
    return 1;
  }
  if ((this_player()-> query_property("wilhelm_bloodwood_quest")) ||
     (this_player()-> query_puzzle("wilhelm_bloodwood_quest")))
  {
    // this_player()->move_player("south",
    // "/players/wilhelm/area/bloodwood/rooms/forest8");	  
  return;
  }	
  if (this_player()-> query_property("wilhelm_bloodwood_horn")){
  return line_break("The plants and trees around you seem to shift and sway "+
  "blocking the path south.");
  }
}

// -- Random happenings -------------------------------------------------------
