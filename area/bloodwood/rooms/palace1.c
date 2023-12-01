/*The Chamber of Voices*/

inherit "/std/room";
#define TD "/obj/util/timed"
//#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_property("no_tree");
  add_property("indoors");
  add_light(1);
  add_exit("south", "courtyard");
  add_exit("up", "palace2", "up","@check_exit()");
  
// -- Description and settings -------------------------------------------

  set_short("the chamber of voices");
  set_long("This is the first floor of the elven palace, used for important "+
  "political functions.  A large rose throne is centered in the room. ");    

// -- Items and Commands -------------------------------------------------
  
  add_item( ({ "floor" }),
    "The floor is covered in woven vines intertwined with large tree branches.");
  add_item( ({ "wall","walls" }),
    "Between the trees grow tightly knit flowering vines that make up the palace "+
	"walls. The walls sport several window openings, all covered in delicate "+
	"spiderwebs.");
  add_item( ({ "tree","trees" }),
    "The palace is built in between many large trees, making them part of the "+
	"palace walls.");	
  add_item( ({ "vine","vines" }),
    "The vines are magically constructed and make of most of the walls and floor.");
  add_item( ({ "window","windows" }),
    "The chamber has several windows, all covered in delicate spiderweb.");	
  add_item( ({ "spiderweb","spiderwebs","spider web","spider webs" }),
    "Small delicate spiderweb cover up the windows.");	
  add_item( ({ "door","doors","rose bushes" }),
    "The doors between rooms are rose bushes grown thick enough to become solid.");		
	
  add_item( ({ "throne","rose throne" }),
    "A towering, wickedly beautiful piece of furniture.  The throne is covered with "+
	"delicately carved blossoms and the hundreds of thorny points protruding from "+
	"between them seem to claw at the air.  ");
	
  add_object("/players/wilhelm/area/bloodwood/monsters/alachia");	
}

// -- Night and Day time descriptions ---------------------------------------



// -- Commands output --------------------------------------------------------

check_exit() {
  if (present("queen", this_object())) {
    write("The queen blocks the path.\n");
    return 1;
  }
  this_player()->add_property("wilhelm_bloodwood_horn");	
  write ("You feel cursed and the palace walls seem to shift around you.\n");
  return;
}



// -- Random happenings -------------------------------------------------------
