// -- This line is 78 characters long ----------------------------------------

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
#define TD "/obj/util/timed"
//#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg) 
{
  ::reset(arg);
  if (arg) 
    return;

// -- Properties -------------------------------------------------------------

  add_light(1);
  add_property("no_teleport");
  add_exit("down", "breeton");
  

// -- Description ------------------------------------------------------------

  set_short("crows nest");
  set_long("You are standing on top of the crows nest of the riverboat breeton. "+
  "It gives you a good view of the surroundings.");

// -- Items ------------------------------------------------------------------

  add_item(({ "mast","masts" }), 
    "The riverboat has two masts, you are standing on top of the main mast.");
  add_item(({ "village","siridfaath" }), 
    "It is a small cozy village, northwest of you.");
  add_item( ({ "mountain", "mountan range","gigantic rock" }),
    "A gigantic rock, leaning on the heavens above. It looks dark and "+
    "soulless.");	
  add_item(({ "nest","crow's nest","lookout" }), 
    "It's a small wooden platform on top of the riverboat. It gives you a good view.");
  add_item(({ "view","surroundings","surrounding" }), 
    "The riverboat is docked at the village Siridfaath.  The small village is up to the "+
	"northwest in front of a large mountain range. ");
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

// -- Objects ----------------------------------------------------------------
	
  add_object("/players/wilhelm/area/siridfaath/obj/spyglass");
  
}


exa_vine() {
  if (this_player()-> query_property("wilhelm_bloodwood_quest")) {
  return line_break("You can't see any vines.");
  }
  return line_break("Large thick vines with sharp thorns are coiled around "+
  "the ship");
}

exa_deck() {
  if (this_player()-> query_property("wilhelm_bloodwood_quest")) {
  return line_break("The wooden deck of the boat is below you. ");
  }
  return line_break("The wooden deck of the boat is below you.  "+
  "It is covered in large vines.");
}

exa_cabin() {
  if (this_player()-> query_property("wilhelm_bloodwood_quest")) {
  return line_break("The captain's cabin is at the stern of the ship below you.");
  }
  return line_break("The captain's cabin is at the stern of the ship. "+
  "The entrance is blocked by a large vine.");
}


