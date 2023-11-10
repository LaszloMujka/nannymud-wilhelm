/* Bone and Janith an Ork and a windeling in the Amberglass */
//This monster will be a part of a puzzle. 

// -- This line is 78 characters long ----------------------------------------

inherit "/std/state_monster";

#define XSAY(X) tell_room(environment(), line_break(X, "Bone says: ", 78))
#define SAY(X)       tell_room(environment(), X)
#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;

// -- Settings --------------------------------------------------------------

  set_short("@my_short()"),
  set_long("@my_long()"),
  set_name("bone");
  add_alias("janith");
  add_alias("wilhelm_ork");
  add_property("no_die_message");
  add_property("__remote", this_object());
  add_alias("ork");
  set_race("orc");

  set_gender(1);
  set_level(16);
  set_al(-250);
  set_state("init");
  add_soul();
  
  add_hook("die_hook", this_object());
  add_hook("kill_hook", this_object());
  
  add_attack("The windeling flies down from above and stabs \b2PRON with "+
  "her spear!\n",30,0,1);
  add_attack("\b1PRON slices a gash across the face of \b2PRON with \b1poss "
  + "sword.",15,8);
  
// -- Responses -------------------------------------------------------------

  add_response("init","GOT(%1,%2)", "$handle_give(%1,%2)");

  

// -- Items -----------------------------------------------------------------

  add_item(({ "windeling", "janith"}),"@windeling()");
  add_item(({ "spear"}),"@spear()");
  add_item(({ "cloak"}),"@cloak()");
  add_item(({ "sword", "glimmer"}),"@sword()");
    
// -- Equipment ----------------------------------------------------------

  add_object("/players/wilhelm/area/siridfaath/armour/bone_cloak");
  command("wear cloak");
  add_object("/players/wilhelm/area/siridfaath/armour/hardened_leather");
  command("wear armour");
  add_object("/players/wilhelm/area/siridfaath/weapons/crystal_sword");
  command("wield sword");
}

// -- Descriptions ----------------------------------------------------------

my_short(){
  if(environment() &&
  (environment()->query_property("indoors"))){
  return ("An ork and a windeling");
  }
  return ("A really mad ork");
} // Short description

my_long(){
  if(environment() &&
  (environment()->query_property("indoors"))){
  return ("He is sitting at one of the tavern's tables furthest away from "+
  "the entrance, \n"+
  "chatting with a windeling. The fearsome ork looks right back at you with \n"+
  "a cold stare. He is sitting on a chair with his back against the wall, \n"+
  "dressed in dark green. You notice a small glimmer from under his cloak.\n");
  }
  return ("The ork is standing in the middle of the street outside the "+
  "tavern. Something \n"+
  "must have really set him of, his eyes seems to be burning with fire. He is \n"+
  "holding a sword in his hand, ready for battle. You notice a small windeling \n"+
  "flying over his head with a sharp spear in her hand.\n");
} // Long description

windeling(){
  if(environment() &&
  (environment()->query_property("indoors"))){
  return ("She is sitting on top of the table. The small windeling is "+
  "probably not \n"+
  "higher then fifteen inches. Her skin is green like the grass fields and \n"+
  "on her back she has wings like a butterfly. She is drinking from a mug of \n"+
  "ale about half her size, and chatting with an ork. Her hair is in a bright \n"+
  "red colour standing out in all directions. \n");
  }
  return ("She is flying high up in the air, keeping out of your reach. She "+
  "is holding \n"+
  "a sharp spear in her hand.\n");
} //Janith windeling
 
spear(){
  if(environment() &&
  (environment()->query_property("indoors"))){
  return ("Almost impossible to notice, the windeling has a small, but "+
  "sharp spear tucked behind her cloak.\n");
  }
  return ("The short spear looks sharp in her hands. She is holding it \n"+
  "with a hard grip, ready to thrust it at you.\n");
} //Janith spear

cloak(){
  {
  return ("The dark green cloak looks thick and warm. \n");
  }
} //cloak

sword(){
  if(environment() &&
  (environment()->query_property("indoors"))){
  this_player()->add_property("wilhelm_tavern_sword");
  return ("Half covered under his dark cloak, you can see a beautiful sword "+
  "glimmering. \n"+
  "It looks like it's made out of crystal. Now this is a sword you would like \n"+
  "to try out. But how can you get your hands on it, you can't just steal it?\n");
  }
  return ("The ork is holding the sharp crystal sword firmly in his hand, "+
  "ready to \n"+
  "slice you up. It looks almost like fragile glass.\n");
} //Bone's sword


handle_give(what_name,  who_name) {
  int rand;
  object what_obj, obj, next_obj,who_obj;

  what_obj = find_object(what_name);
  who_obj=find_object(who_name);
  
  if (this_player()->query_puzzle("wilhelm_puzzle_bone") && (what_obj -> id("wilhelm_rat"))) {
    XSAY("Time for you to die! Again!\n");
	destruct(what_obj);
	command("out",this_object());
	set_aggressive(5);
    return;
  }
  
  if (what_obj -> id("wilhelm_rat")) {
    XSAY("Time for you to die!\n");
    destruct(what_obj);
	command("out",this_object());
	set_aggressive(5); 
	this_player()->set_puzzle("wilhelm_puzzle_bone");
	this_player() -> add_exp(500);
	LOGGER -> log("puzzle", "Crystal sword", this_player());
	write("You feel a little more experienced.\n");
    return;
  }
  
  
}

int remote_real_monster_died(object monster) {
  tell_room(environment(), "When the ork dies, the windeling flies off to "+
    "plot her revenge.\n");
} // death msg

// -- LOGGER -----------------------------------------------------------------

die_hook(data, who) {
  LOGGER -> log("kills", "killed Bone", data[0]);
}
kill_hook(data, who) {
  LOGGER -> log("deaths", "killed by Bone", data[0]);
}

