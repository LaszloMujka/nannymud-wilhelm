// -- This line is 78 characters long ----------------------------------------

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
#define TD "/obj/util/timed"
#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties -------------------------------------------------------------

  add_light(1);
  add_property("no_teleport");
  add_exit("out", "siridfaath_dock");
  

// -- Description ------------------------------------------------------------

  set_short("a riverboat");
  set_long("You are standing on the deck of a T'skrang riverboat. It has two "+
  "masts and captain's cabin at the back.");

// -- Items ------------------------------------------------------------------

  add_item(({ "mast","masts" }), 
    "Two large masts used for sailing the boat. The middle one has a crow's nest "+
	"at the top.");
  add_item(({ "nest","crow's nest","lookout" }), 
    "The crow's nest is high up the main mast, a structure used as a lookout point.");


  add_item(({ "vine","vines" }), 
		"@exa_vine()");
  add_item(({ "deck" }), 
		"@exa_vine()");
  add_item(({ "cabin","stern","captain's cabin","captains cabin","back" }), 
		"@exa_cabin()");			
	
  add_item( ({ "river", "serpent river" }),
    "The huge river stretch of to the northwest and east. It look's like "+
	"it's almost four miles wide. The strong current in the water flows "+
	"to the east.");	

  add_item_cmd("climb","mast","@cmd_climb()");
  add_item_cmd("enter", "cabin", "The cabin is locked.\n");
	
// -- Objects ----------------------------------------------------------------

	
  add_object("/players/wilhelm/area/siridfaath/monsters/captain");
  
}


exa_vine() {
  if (this_player()-> query_puzzle("wilhelm_bloodwood_quest")) {
  return line_break("You can still see the scratch marks on the ship, but the vines "+
  "are gone.");
  }
  return line_break("Large thick vines with sharp thorns are coiled around "+
  "the ship");
}

exa_deck() {
  if (this_player()-> query_puzzle("wilhelm_bloodwood_quest")) {
  return line_break("The wooden deck is full of scratch marks.");
  }
  return line_break("The wooden deck is full of scratch marks. Large vines "+
  "are coiled around the deck, keeping the riverboat in place.");
}

exa_cabin() {
  if (this_player()-> query_puzzle("wilhelm_bloodwood_quest")) {
  return line_break("The captain's cabin is at the stern of the ship. ");
  }
  return line_break("The captain's cabin is at the stern of the ship. "+
  "The entrance is blocked by a large vine.");
}	

cmd_climb(){
	if((this_player() -> short() && present("captain")) &&
	this_player()->query_property("wilhelm_captain_spyglass"))
	{
	this_player()->move_player("up, the mast",
    "/players/wilhelm/area/siridfaath/rooms/breeton_nest");
	return 1;
	}
	if(this_player() -> short() && present("captain"))
	{
	return "The captain will not let you go up there.";	
	}
	this_player()->move_player("up, the mast",
    "/players/wilhelm/area/siridfaath/rooms/breeton_nest");
	return 1;
}		
