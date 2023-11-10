/*BloodWood entrance*/

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
#define TD "/obj/util/timed"
#define LOGGER load_object("/players/wilhelm/simple_logger")
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

  add_exit("down", "gardens4"); 
  

  
// -- Description and settings -------------------------------------------

  set_short("hedge maze tree");
  set_long("You have climbed up a tree inside what seems to be a labyrinth of "+
  "thorny hedges. The paths twist and turn in all directions, but strangely "+
  "you can see the exit to the south, was it there before?");    

// -- Items and Commands -------------------------------------------------
  
  add_item(({ "path","paths"}), 
    "These paths twist and turn and end and begin again countless times.");
  add_item(({ "hedge" }), 
    "The labyrinth os thorney hedges grow high above you in all directions. "+
	"Covered in vines and beautiful flowers. There is an exit in the south hedge.");
  add_item(({ "vines","vines" }), 
    "Flowering rose vines encircle the hedges, almost seeming to strangle them.");  	
  add_item(({ "flower","flowers","rose","roses" }), 
    "The brightness of the flowers are unnerving, the colors are downright unnatural.");  
  add_item(({ "ground","blood","pool","pools" }), 
    "Scattered throughout the gardens are patches of ground damp with blood.");  	
  add_item(({ "wind chimes","wind chime","chime","chimes" }), 
    "Wind chimes are placed throughout the gardens and create ethernal music with "+
	"every heavily scented breeze.");	
  add_item(({ "tree","oak tree" }), 
    "It's a large oak tree inside the garden maze. ");	
   add_item( ({ "palace" }),
    "The palace to the south rises high up in the sky. Enormous oak trees, whose "+
	"trunks an branches both shape and support it.");
   add_item( ({ "exit","south" }),
    "You are sure it wasn't there before, but to the south, you can see the exit out "+
	"of this strange maze that leads up to a palace in the forest.");			
  }





// -- Commands output --------------------------------------------------------



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
    "You can hear something move down bellow.",
    "You hear a twig snap somewhere inside the maze.",
	"The strong perfume of the flowers seems to assault your senses, making you nauseous.",
    "You hear wind chimes ringing somewhere in the garden."});
  night_message = ({
    "You see something move down in the darkness bellow you.",
    "You hear a twig snap somewhere inside the maze.",
	"The strong perfume of the flowers seems to assault your senses, making you nauseous.",
    "You hear wind chimes from somewhere in the darkness."});
  if(TD->query_daytime()) 
    tell_room(this_object(), day_message[random(sizeof(day_message))] + "\n");
  else
    tell_room(this_object(), 
      night_message[random(sizeof(night_message))] + "\n");
}
