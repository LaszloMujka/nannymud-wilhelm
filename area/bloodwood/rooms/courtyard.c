/*BloodWood entrance*/

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
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

  add_exit("north", "palace1", 0,
	     "@check_exolasher_n()");
  add_exit("northwest", "gardens1", 0,
	     "@check_exolasher_nw()");		 
  add_exit("south", "forest_p4");
  
// -- Description and settings -------------------------------------------

  set_short("courtyard");
  set_long("You are standing in a courtyard in front of the Bloodwood palace.");    

// -- Items and Commands -------------------------------------------------
  

  add_item(({ "sky" }),"@make_sky()");
  add_item( ({ "palace" }),
    "The palace rises high up in the sky, even reaching above the forest trees. "+
	"It stands within a circle of enormous oak trees, whose trunks and branches "+
	"both shape and support it. A staircase leads up to the entrance.");
  add_item( ({ "stair","stairs","staircase" }),
    "The staircase is built from bones of elves and leads up to the palace entrance.");
  add_item( ({ "entrance" }),
    "The entrance is made out of rose bushes grown thick enough to become solid.");
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
	
  add_object("/players/wilhelm/area/bloodwood/monsters/exolasher");	
  
}

// -- Night and Day time descriptions ---------------------------------------



make_sky() {
  if (TD -> query_daytime()) {
  return line_break(" You can the blue sky above the forest trees.");
  }
    
  return line_break(" You can see the night sky above the forest trees.");
}

// -- Commands output --------------------------------------------------------

check_exolasher_n() {
  if(this_player() -> short() && present("exolasher")) {
    return "The guard blocks the path.\b|" +
      "\bPRON tries to go into the palace, but the exolasher blocks the way!";
  }
}

check_exolasher_nw() {
  if(this_player()-> query_property("wilhelm_bloodwood_quest")) {
	this_player()->move_player("northwest",
      "/players/wilhelm/area/bloodwood/rooms/gardens1");
    return 0;
  }	
  if(this_player() -> short() && present("exolasher")) {
    return "The guard blocks the path.\b|" +
      "\bPRON tries to enter the gardens, but the exolasher blocks the way!";
  }
}

// -- Random happenings -------------------------------------------------------


