/*The Chamber of Voices*/

inherit "/std/room";
#define TD "/obj/util/timed"
//#define LOGGER load_object("/players/wilhelm/simple_logger")
#define PEDESTAL "/players/wilhelm/area/bloodwood/obj/pedestal"

int rose;


void reset(int arg) 
{
  ::reset(arg);
  rose = 1;
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_property("no_tree");
  add_property("indoors");
  add_light(1);
  add_exit("down", "palace2");
  add_exit("west", "palace_b");
  
// -- Description and settings -------------------------------------------

  set_short("the queens chamber");
  set_long("You are standing in the top of the palace that seems to be the "+
  "queens private suite. One wall is completely open and leads out to a balcony.");    

// -- Items and Commands -------------------------------------------------
  
  add_item( ({ "floor" }),
    "The floor are thick mats of flowering vines.");
  add_item( ({ "wall","walls" }),
    "The walls are covered with shelves and beautiful paintings.");
  add_item( ({ "tree","trees" }),
    "The palace is built in between many large trees, making them part of the "+
	"palace walls.");	
  add_item( ({ "vine","vines" }),
    "The vines are magically constructed and make of most of the walls and floor.");
  add_item( ({ "door","doors","rose bushes" }),
    "The doors between rooms are rose bushes grown thick enough to become solid.");		
  add_item( ({ "shelves","shelf" }),
    "The shelves are formed out of the tree branches.");	
  add_item( ({ "balcony" }),
    "The balcony is to the south.");
	
  add_object(load_object(PEDESTAL));
}


// -- Commands output --------------------------------------------------------



// -- Random happenings -------------------------------------------------------
