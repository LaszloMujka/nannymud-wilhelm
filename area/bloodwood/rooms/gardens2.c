/*BloodWood entrance*/

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
#define TD "/obj/util/timed"
#define LOGGER load_object("/players/wilhelm/simple_logger")
int glovesf;
mapping seen_prints;
string name;

void reset(int arg) 
{
  ::reset(arg);
  seen_prints = ([]);
  glovesf = 1;
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_property("forest");
  add_light(1);

  add_exit("east", "gardens2"); 
  add_exit("north", "gardens2");
  add_exit("south", "gardens2");
  add_exit("west", "gardens2");


  
  
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
  
  add_object("@make_bush()");
	
  add_item_cmd("cut", "hedge", 
	"You can't cut your way through the hedge.\n");	
  add_item_cmd("enter", "hedge", 
	"There aren't any openings in the hedge to enter.\n");	
  add_item_cmd("jump", "hedge", 
	"The hedge is too high to jump.\n");
  add_item_cmd("climb", "hedge", 
	"The hedge is too full of sharp thorns to be able to climb.\n");
  add_command("search %s", "@cmd_search()");		
  add_command("search bush", "@cmd_search_bush()");
  add_command(({ "follow", "follow prints", "follow footprints" }), "@do_path()");
  
  add_item_cmd("climb", "hedge", "@cmd_climb_hedge()");	
  }


make_bush()
{
  object bush;

  bush = clone_object("/std/stationary"); 
  bush -> set_name("bush");
  bush -> set_short("A rose bush");
  bush -> set_long("A rose bush stands in the middle of the labyrinth path, "+
  "covered in beautiful petals. The ground around it is damp with blood."); 
  bush -> add_item("petals","Large dark red rose petals cover the bush.");
  return bush; 
} 




// -- Commands output --------------------------------------------------------

exa_print() {
  if (this_player()-> query_property("wilhelm_bloodwood_lost")) {
    name = this_player() -> query_real_name();
    seen_prints[name] = 1;
    return line_break("Some of the smaller pools of blood have been made by "+
	"someone's footprints. Maybe you can follow them?");
  }
  return line_break("You can't see any footprints here.");
}

cmd_search_bush() {
  object gloves;
		if (glovesf == 0){
		return  "You search around in the rose bush, but find nothing of interest.\n"; }
		if (glovesf == 1){
		"std/msg"->msg("\bcapPRON search\b{,es} through the rose bush, and find\b$ a pair of gloves.\n");	
		gloves = clone_object("/players/wilhelm/area/bloodwood/armour/gardner_gloves");
		glovesf = 0;
		if (transfer(gloves,this_player())) {
		"std/msg"->msg("\bPRON \bis carrying too much and drop the gloves on the ground.\n");
		move_object(gloves, this_object());}
		return "Wonder who lost them?";
		}

}

do_path() {
  name = this_player() -> query_real_name();
  if (seen_prints[name]){
    this_player()->move_player("further into the maze",
  "/players/wilhelm/area/bloodwood/rooms/gardens4");
  return 1;
  }
  return "Follow what?\n";	  
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
	return "You find nothing but puddles of blood on the ground.\n";
    case "blood" :
    case "pool" :
    case "pools" : 
	case "puddle" :
	case "puddles" :
	this_player()-> add_property("wilhelm_bloodwood_lost");
	return "Some of the smaller pools of blood look like footprints.\n";
	case "wind chimes" :
	case "chimes" :
	case "chime" : return "You can't reach any of the wind chimes.\n";
 }
}

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
