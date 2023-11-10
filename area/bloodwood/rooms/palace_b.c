/*The Chamber of Voices*/

inherit "/std/room";
#define TD "/obj/util/timed"
#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_property("no_tree");
  add_property("indoors");
  add_light(1);
  add_exit("east", "palace3");
  
  
// -- Description and settings -------------------------------------------

  set_short("balcony");
  set_long("You are standing on a balcony on the top of the Bloodwood palace. "+
  "Thick rose vines entwine the balcony and the walls below it. You have a "+
  "beautiful view over the palace gardens.");    

// -- Items and Commands -------------------------------------------------
  
  add_item( ({ "floor" }),
    "The floor are made out vines and forest branches.");
  add_item( ({ "walls","walls" }),
    "The walls are made out vines and forest branches.");	
  add_item( ({ "tree","trees" }),
    "You see the treetops of the large forest around you.");	
  add_item( ({ "vine","vines","rose vines" }),
    "The vines are magically constructed and make of most of the walls and floor.");
  add_item( ({ "door" }),
    "The door between the  balcony and the palace is made out of rose bushes grown "+
	"thick enough to become solid.");		
  add_item( ({ "balcony" }),
    "The balcony is made out of thick rose vines and branches. It overlooks the grounds "+
	"below and the enormous forest.");
  add_item( ({ "palace", "bloodwood palace" }),
    "You can't see much of the palace from here.");	
  add_item( ({ "view","gaden","gardens" }),
    "Surrounding the palace are the queen's gardens oases of beauty that also act as the "+
	"palace's last line of defense. A labyrinth of thorny hedges winds around the entire "+
	"perimeter of the gardens, forming a thorny maze.");
	
}

// -- Night and Day time descriptions ---------------------------------------



// -- Commands output --------------------------------------------------------



// -- Random happenings -------------------------------------------------------
