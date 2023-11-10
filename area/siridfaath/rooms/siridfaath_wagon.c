// -- This line is 78 characters long ----------------------------------------
inherit "/std/room";
#define LOGGER load_object("/players/wilhelm/simple_logger")

int lantern_found = 1;

reset(arg) {

  ::reset(arg);
  if (!arg) {

// -- Properties -------------------------------------------------------------

    add_property("indoors");
    add_light(1);
	add_exit("out", "siridfaath4");
	
// -- Description and settings -----------------------------------------------

	set_short("inside a wagon");
    set_long("You are hiding under the wagon covers. The wagon is filled with "+
    "wooden boxes filled with merchant goods. You can climb out again into the "+
    "streets of Siridfaath.");
	
    add_item( ({ "wooden box", "wooden boxes", "box", "boxes" }),
	      "There are many boxes in the wagon, filled with goods the merchant "+
		  "is selling");
    add_item( ({ "goods" }),
	  "The boxes are filled with different goods, but nothing that has real "+
	  "value to you.");		  
	add_item( ({ "cover","covers" }),
	  "The covers are pulled over the wagon, to protect the goods from the "+
	  "rain. You are hiding under it.");
    add_item( ({ "floor" }),
	  "It's a plain wooden floor.");
    add_item(({ "out", "outside", "siridfaath" }),
    "@make_outside()"); 	  
	  
	add_item_cmd("search", ({"boxes","box","wooden boxes" }), "@cmd_search()");
	  
//	add_command("search %s", "@cmd_search()");

// -- Objects ----------------------------------------------------------------		  
		  
    add_object("/players/wilhelm/area/siridfaath/obj/merchant_chest");
  }
}

make_outside() {
  write("You peek out from the wagon covers. You see: \n"); 
  write("/obj/look"->describe_inventory(load_object
  ("/players/wilhelm/area/siridfaath/rooms/siridfaath4"), 1, this_player()));
  return "";
}

cmd_search() {
  object lantern;
  if (lantern_found == 0) {
    notify_fail("You search thoroughly through all the boxes, but find "+
	"nothing of value.\n");
    return;
  }
  lantern = clone_object("players/earendil/obj/lantern");
  if (!transfer(lantern, this_player())) {
    lantern_found = 0;
    return "You search thoroughly through all the boxes. All you find "+
	"is a lantern and pick it up.\n";
  }
  notify_fail("You search thoroughly through all the boxes. All you "+
  "find is a lantern but it's too heavy for you to pick up.\n");
}