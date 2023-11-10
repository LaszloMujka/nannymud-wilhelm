/*The library in Siridfaath*/

// -- This line is 78 characters long ---------------------------------------

inherit "/std/room";
#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;
    
// -- Properties ------------------------------------------------------------

  add_light(1);
  add_property("no_tree");
  add_property("inside");
  add_property("no_fight");

// -- Exits -----------------------------------------------------------------

  add_exit("out", "siridfaath3");               
               
// -- Description -----------------------------------------------------------

  set_short("siridfaaths library");
  set_long("The smell of old books fills up the large library. Shelves upon "+
    "shelves are stacked up around the walls, covered with books and scrolls. "+
    "An elderly man is sitting behind the small oaken desk and over him a "+
    "large map covers the wall.");

// -- Items -----------------------------------------------------------------

  add_item(({ "shelf", "shelves" }),
    "They cover most of the library and are filled up with books and scrolls.");
  add_item(({ "book", "books","scroll","scrolls" }),
    "They are all filled up with information about the strange land you are "+
    "in. This could keep you busy for years.");
  add_item(({ "map" }),
    "It's a large map over Barsaive. It's covered with many interesting "+
    "locations, like the forgotten city of Parlainth, and the Blood Wood. "+
    "You find Siridfaath far up in the northeast side of the map, between "+
    "the Serpent river and the Caucavic mountains.");
  add_item(({ "desk" }),
    "The small desk is also filled up with books, like the rest of this room.");
  add_item(({ "chair" }),
    "A small but comfy chair made for a dwarf.");
  add_item(({ "wall","walls"}),
    "You can hardly see the walls between all the shelves.");
  add_item(({ "floor"}),
    "Strangely there isn't any books on the floor. The librarian must be good "+
    "at keeping things in order.");
  add_item(({ "door" }),
    "It's a big double door leading out of the library.");
    
  add_command(({ "listen" }), "@listen()");

// -- Objects ---------------------------------------------------------------

  add_object("/players/wilhelm/area/siridfaath/monsters/issaren");

}

listen()
{
"/std/msg"->msg("\bPRON stop\b$ and listens to the surroundings.\n");
write("In the library, only the quiet sound of the librarian turning the \n");
write("pages of his book can be heard.\n");
return 1;
}
