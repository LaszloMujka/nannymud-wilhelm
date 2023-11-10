/*BloodWood*/

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

  
// -- Description and settings -------------------------------------------

  set_short("bloodwood forest");
  set_long("You are standing in an enormous forest. Huge trees loom above "+
  "you, covering up the sky. Large and thick vines hang between the towering "+
  "trees.");    

// -- Items and Commands -------------------------------------------------
  
  add_item(({ "tree", "trees" }),"@make_tree()");
  add_item(({ "blood", "pool","pools","pool of blood","pools of blood" }),"@make_blood()");
  add_item(({ "sky" }),"@make_sky()");   
  add_item(({ "plains","fields" }), 
    "Large dry fields to the east, outside the forest.");
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
  add_item(({ "thorns", "sharp thornes","thorn" }), 
    "The entire unusual forest seems to be covered in this sharp thorns. "+
	"Expanding from the trees and plants.");
	
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
  return line_break("You can barely see the sky between all the trees.");
  }
    
  return line_break("You can barely see the night sky between all the trees.");
}

make_blood() {
  if (TD -> query_daytime()) {
  return line_break("The moist ground is filled with small pools of blood.");
  }
    
  return line_break("The moist ground is filled with small pools of blood.");
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
    "You hear a loud scream from somewhere in the forest.",
    "The wind blows through the forest, bringing along the scent of hundreds of different flowers.",
    "A tree branch seems to grope toward you like fingers.",
	"You almost step in a pool of blood.",
	"You hear birdsong from somewhere in the forest, it's feels filled with pain.",
    "Low-growing plants seem to twine about your feet of their own accord."});
  night_message = ({
    "You hear a loud scream from somewhere in the forest.",
    "A tendril of hanging moss brushes against your face as you walk along the forest.",
    "Low-growing plants seem to twine about your feet of their own accord.",
	"Your step in something wet in the dark.",
    "In the darkness of the night, the trees seem to close in on you, making you feel caged by the forest."});
  if(TD->query_daytime()) 
    tell_room(this_object(), day_message[random(sizeof(day_message))] + "\n");
  else
    tell_room(this_object(), 
      night_message[random(sizeof(night_message))] + "\n");
}