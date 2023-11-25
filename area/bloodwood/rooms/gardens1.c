/*BloodWood entrance*/

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
#define TD "/obj/util/timed"
#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_property("road");
  add_property("forest");
  add_light(1);
  add_exit("north", "gardens3");
  add_exit("southeast", "courtyard", "southeast", "check_exit");
  
// -- Description and settings -------------------------------------------

  set_short("gardens");
  set_long("You are standing behind the forest palace in front of a garden "+
  "area. A labyrinth of thorny hedges winds around the garden, forming a "+
  "small maze.");    

// -- Items and Commands -------------------------------------------------
  

  add_item(({ "sky" }),"@make_sky()");
  add_item( ({ "palace" }),
    "The palace rises high up in the sky, even reaching above the forest trees. "+
	"It stands within a circle of enormous oak trees, whose trunks and branches "+
	"both shape and support it. At the top you can se a balcony.");
  add_item( ({ "labyrinth","maze" }),
  "You can enter the labyrinth to the north. Large thorny hedges stretch around the area. ");
  add_item( ({ "hedge","hedges","thorny hedge","thorny hedges" }),
    "Large thorny hedges that winds all around the garden. ");
  add_item( ({ "balcony" }),
    "On top of the palace, you see a balcony surveilling the gardens. If it wasn't "+
	"for the thorny wall, you might be able to climb up.");
  add_item( ({ "thorn","thorns" }),
    "Sharp spiky thorns. They are everywhere.");		
  add_item( ({ "wall","walls","palace wall","palace walls" }),
    "Like the rest of the forest, the palace wall is filled with sharp thorns.");	
  add_item( ({ "north","opening" }),
    "There is an opening in the hedge wall to the north, making it possible to enter the maze.");
  add_item( ({ "tree", "trees" }),
    "Large dark green trees, with a shade of reddish tint, covers the courtyard. "+
	"They stretch up far into the sky. Tendrils of hanging moss hang down from "+
	"the branches and large vines are entangled between the trees.");
  add_item(({ "forest" }), 
    "The enormous forest is made up of huge towering trees, growing tightly "+
	"together between the underbrush. ");
  add_item(({ "vine","vines" }), 
    "The trees are overgrown with thick looping coils of vines, that "+
	"stretches down from the high tree branches down to the ground.");	
  add_item(({ "moss","tendril","tendrils" }), 
    "Large tendrils of red-tinged moss cover the trees. ");	
  add_item(({ "southeast" }),
		"@exa_southeast()");	
	
  add_command("enter courtyard","@cmd_enter()"); 
  add_item_cmd("climb","palace","@cmd_climb_palace()");
  add_item_cmd("climb","wall","@cmd_climb_palace()");
  add_item_cmd("climb", "hedge", "@cmd_climb_hedge()");	
  
  add_object("/players/wilhelm/area/bloodwood/monsters/gardener");	
}

// -- Night and Day time descriptions ---------------------------------------



make_sky() {
  if (TD -> query_daytime()) {
  return line_break(" You can the blue sky above the forest trees.");
  }
    
  return line_break(" You can see the night sky above the forest trees.");
}

// -- Commands output --------------------------------------------------------

cmd_enter() 
{
    this_player()->move_player("southeast",
      "/players/wilhelm/area/bloodwood/rooms/courtyard"); 
  return 1;
}

check_exit() {
	
  if (this_player()-> query_property("wilhelm_bloodwood_quest")){
    this_player()->move_player("southeast",
    "/players/wilhelm/area/bloodwood/rooms/courtyard");	  
  return;
  }		
  if (!this_player()-> query_property("wilhelm_bloodwood_horn")){
  return line_break("The palace walls are right in front of you. You have managed to get "+
  "this far without any of the bloodelfs noticing your presence. If you enter the "+
  "courtyard you will surely get caught. Do enter courtyard if you are sure. ");
  }
}

exa_southeast() {
  write("You peek down the path southeast. You see: \n"); 
  write("/obj/look"->describe_inventory(load_object
  ("/players/wilhelm/area/bloodwood/rooms/courtyard"), 1, this_player()));
  return "";
}
	
cmd_climb_palace() {
  object obj,eq;

  eq=this_player()->query_worn();
  if (eq)  
    obj=eq["glove"];
	if (obj && obj -> id("wilhelm_gardener_gloves")) {
	write ("With protection from your gloves, you manage to climb the tree.\n");
	this_player()->move_player("up",
    "/players/wilhelm/area/bloodwood/rooms/palace_b");
    return 1;}	
  else
	"/std/msg"->msg("You try to climb up the palace wall, but cut yourself on the sharp thorns.\n\b|" +
	"\bPRON tries to climb up the palace wall, but fails.\n");	  
  this_player()->add_hp(-2);
	write ("The blood from your cut is quickly absorbed by the ground. \n");
  return 1;
} 

cmd_climb_hedge()
	{
  object obj,eq;
  eq=this_player()->query_worn();  
  if (eq)  
    obj=eq["glove"];
	if (obj && obj -> id("wilhelm_gardener_gloves")) {
    return line_break ("Even with the protective gloves, the hedge is too full of sharp thorns to be "+
	"able to climb. You could just enter the maze by walking north.");}	
  else
	return line_break("The hedge is too full of sharp thorns to be able to climb. You could just "+
	"enter the maze by walking north.");
}

// -- Random happenings -------------------------------------------------------


