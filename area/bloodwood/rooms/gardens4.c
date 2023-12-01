/*BloodWood entrance*/

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
#define TD "/obj/util/timed"
//#define LOGGER load_object("/players/wilhelm/simple_logger")
int glovesf;

void reset(int arg) 
{
  ::reset(arg);
  glovesf = 1;
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_property("forest");
  add_light(1);

  add_exit("east", "gardens4"); 
  add_exit("north", "gardens4");
  add_hidden_exit("south", "gardens1","out of the maze","do_south");

  
// -- Description and settings -------------------------------------------

  set_short("hedge maze");
  set_long("You are standing inside what seems to be a labyrinth of thorny hedges. "+
  "The paths twist and turn to make it hard to find a way out.");    

// -- Items and Commands -------------------------------------------------
  
  add_item(({ "path","paths"}), 
    "These paths twist and turn and end and begin again countless times.");
  add_item(({ "hedge" }), 
    "The labyrinth os thorney hedges grow high above you in all directions. "+
	"Covered in vines and beautiful flowers.");
  add_item(({ "vines","vines" }), 
    "Flowering rose vines encircle the hedges, almost seeming to strangle them.");  	
  add_item(({ "flower","flowers","rose","roses" }), 
    "The brightness of the flowers are unnerving, the colors are downright unnatural.");  
  add_item(({ "ground","blood","pool","pools" }), 
    "Scattered throughout the gardens are patches of ground damp with blood.");  	
  add_item(({ "wind chimes","wind chime","chime","chimes" }), 
    "Wind chimes are placed throughout the gardens and create ethernal music with "+
	"every heavily scented breeze.");	
  add_item(({ "prints", "footprints","print" }), "@exa_print()");
  add_item(({ "south", "s","south wall", "south hedge"}), "@exa_south()");	
  add_object("@make_tree()");
	
  add_item_cmd("cut", "hedge", 
	"You can't cut your way through the hedge.\n");	
  add_item_cmd("enter", "hedge", 
	"There aren't any openings in the hedge to enter.\n");	
  add_item_cmd("jump", "hedge", 
	"The hedge is too high to jump.\n");
  add_item_cmd("climb", "hedge", "@cmd_climb_hedge()");
	
  add_command("search %s", "@cmd_search()");		
  add_command(({ "follow", "follow prints", "follow footprints" }), "@do_path()");	
  //add_command(({ "south", "s"}), "@do_south()");
  
  add_command("climb tree","@cmd_climb_tree()"); 
  
  }

exa_print() {
  if (this_player()-> query_property("wilhelm_bloodwood_lost")){
    return line_break("You can still see the bloody footprints in the ground. "+
	"You can follow them back.");
  }
  return line_break("You can't see any footprints.");
}  

exa_south() {
  if (this_player()-> query_property("wilhelm_bloodwood_tree")){
    return line_break("Like some magic spell that has been broken, you can see "+
	"the exit of the maze straight to the south, it leads out to a large palace.");
  }
  return line_break("The south hedge is thick and high, there is no way you can "+
  "go that way.");
}  

do_south() {
	
  if (!this_player()-> query_property("wilhelm_bloodwood_tree")){
  return line_break("You can't go that way.");
  }
}


make_tree()
{
  object tree;

  tree = clone_object("/std/stationary"); 
  tree -> set_name("tree");
  tree -> set_short("A large tree");
  tree -> set_long("A large oak tree stands in the middle of the labyrinth "+
  "path reaching above the hedge walls. It covered in large twisting vines and sharp thorns."); 
  return tree; 
} 




// -- Commands output --------------------------------------------------------




do_path() {
  if (this_player()-> query_property("wilhelm_bloodwood_lost")) {
    this_player()->move_player("further into the maze",
  "/players/wilhelm/area/bloodwood/rooms/gardens2");
  return 1;
  }
  return "You can't see the prints anymore.\n";	  
}

string cmd_search(int arg, string s) {
  object note;
  if(!s) return "You should be more specific.\n";
  else switch(s) {
    case "path" :
	case "paths" : 
	return "You search around for a way out, but can't find any.\n";
	case "hedge" : 
	return "You search around the hedge for a way out, but can't find any.\n";
	case "vine" :
	case "vines" : 
	return "You find nothing.\n";
	case "flower" :
    case "flowers" : 
    case "rose" :
    case "roses" : 
	return "You look around the strange flowers, but find nothing of interest.\n";
    case "ground" : 
	return "You find nothing on the ground.\n";
    case "blood" :
    case "pool" :
    case "pools" :
	return "The ground is soaked with blood but holds nothing of interest.\n";
	case "wind chimes" :
	case "chimes" :
	case "chime" : return "You can't reach any of the wind chimes.\n";
  }
}

cmd_climb_tree()
	{
  object obj,eq;
  eq=this_player()->query_worn();  
  if (eq)  
    obj=eq["glove"];
	//if(obj && obj->query_name()=="gardener gloves"){
	if (obj && obj -> id("wilhelm_gardener_gloves")) {
	write ("With protection from your gloves, you manage to climb the tree.\n");
	this_player()-> add_property("wilhelm_bloodwood_tree");
	this_player()->move_player("up the tree",
    "/players/wilhelm/area/bloodwood/rooms/maze_tree");
    return 1;}	
  else
      "/std/msg"->msg("You try to climb up the tree, but cut yourself on the sharp thorns.\n\b|" +
		  "\bPRON tries to climb up the tree, but fails.\n");
	this_player()->add_hp(-2);
	write ("If you only had some gloves to protect you from the thorns.\n");
    return 1;}

cmd_climb_hedge()
	{
  object obj,eq;
  eq=this_player()->query_worn();  
  if (eq)  
    obj=eq["glove"];
	if (obj && obj -> id("wilhelm_gardener_gloves")) {
    return line_break ("Even withe protective gloves, the hedge is too full of sharp thorns to be "+
	"able to climb.");}	
  else
	return line_break("The hedge is too full of sharp thorns to be able to climb.");
  }	
	

// -- Random happenings -------------------------------------------------------

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
    "You can hear something move from the other side of the hedge.",
    "You hear a twig snap somewhere inside the maze.",
    "The ground seems to well up and a new pool of blood appears on the ground.",
	"The strong perfume of the flowers seems to assault your senses, making you nauseous.",
    "You hear wind chimes ringing somewhere in the garden."});
  night_message = ({
    "You can hear something move from the other side of the hedge.",
    "You hear a twig snap somewhere inside the maze.",
	"The strong perfume of the flowers seems to assault your senses, making you nauseous.",
    "The darkness of the night makes it hard to see, and you step in a pool of blood.",
    "You hear wind chimes from somewhere in the darkness."});
  if(TD->query_daytime()) 
    tell_room(this_object(), day_message[random(sizeof(day_message))] + "\n");
  else
    tell_room(this_object(), 
      night_message[random(sizeof(night_message))] + "\n");
}
