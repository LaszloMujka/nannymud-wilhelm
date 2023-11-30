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

  add_property("forest");
  add_light(1);
  add_exit("south", "gardens2");
  add_exit("west", "gardens2");
  add_exit("east", "gardens2");
  
// -- Description and settings -------------------------------------------

  set_short("hedge maze");
  set_long("You are standing inside what seems to be a labyrinth of thorny hedges. "+
  "The paths twist and turn to make it hard to find a way out.");    

// -- Items and Commands -------------------------------------------------
  
  add_item(({ "path","paths"}), 
    "These paths twist and turn and end and begin again countless times.");
  add_item(({ "hedge" }), 
    "The labyrinth of thorney hedges grow high above you in all directions. "+
	"Covered in vines and beautiful flowers. The north side seems to have grown "+
	"even thicker and the south side is lower, there might be a way out.");
  add_item(({ "vines","vines" }), 
    "Flowering rose vines encircle the hedges, almost seeming to strangle them.");  	
  add_item(({ "flower","flowers","rose","roses" }), 
    "The brightness of the flowers are unnerving, the colors are downright unnatural.");  
  add_item(({ "ground","blood","pool","pools" }), 
    "Scattered throughout the gardens are patches of ground damp with blood.");  	
  add_item(({ "wind chimes","wind chime","chime","chimes" }), 
    "Wind chimes are placed throughout the gardens and create ethernal music with "+
	"every heavily scented breeze.");	
	
  add_item_cmd("cut", "hedge", 
	"You can't cut your way through the hedge.\n");	
  add_item_cmd("enter", "hedge", 
	"There aren't any openings in the hedge to enter.\n");	
  add_item_cmd("jump", "hedge", "The hedge is too high to jump.");
  add_item_cmd("search", "hedge", 
	"You search around the hedge, but find nothing of interest.\n");	
  add_item_cmd("climb", "hedge", "@cmd_climb_hedge()");	
	
	
	}






// -- Commands output --------------------------------------------------------

cmd_climb_hedge()
	{
  object obj,eq;
  eq=this_player()->query_worn();  
  if (eq)  
    obj=eq["glove"];
	if (obj && obj -> id("wilhelm_gardener_gloves")) {
    return line_break ("Even with the protective gloves, the hedge is too full of sharp thorns to be "+
	"able to climb. Maybe you can jump high enough to jump over the hedge ?");}	
  else
	return line_break("The hedge is too full of sharp thorns to be able to climb. If you can jump high enough you might be able to return. ");
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
