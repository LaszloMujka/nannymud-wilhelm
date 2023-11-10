/*BloodWood*/

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
#define TD "/obj/util/timed"
#define LOGGER load_object("/players/wilhelm/simple_logger")
#include "/players/wilhelm/area/macros.h";

int exa_forest,cut_vine,enter_opening,rope;
mapping seen_forest;
string name;

void reset(int arg) 
{
  ::reset(arg);
  enter_opening=1;  // 1 Opening is there, 0 = Opening is ued, need to wait for reset
  rope=2;  // 2 = No rope, 1 = rope tied to branch 0 = branch broken, no rope
  cut_vine = 2;  // 2 = Vine stuck on branch  1 = Vine cut loose, ready to swing  0 = Someone elsed used it, need to wait for reset
  exa_forest = random(3) + 1;
//  exa_forest = 3;  // 1 = vine 2 = opening 3 = branch
  seen_forest = ([]);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_property("forest");
  add_light(1);
  add_exit("southeast", "tree1");
  //set_bottom("/players/wilhelm/area/bloodwood/forest1");
  

  
// -- Description and settings -------------------------------------------

  set_short("on a large branch");
  set_long("@get_long()");    

// -- Items and Commands -------------------------------------------------
  
	add_item(({"tree"}),
		"It's a large tree with long thick branches stretching out in all "+
		"directions. Dark green leaves cover the tree beside you. ");
	add_item(({ "plain","plains","feild","fields" }), 
		"You can see the large dry fields below you.");  
    add_item(({ "vine","vines" }), 
		"@exa_vine()");
    add_item(({ "moss","tendril","tendrils" }), 
		"Large tendrils of red-tinged moss cover the tree. ");	
	add_item(({ "thorn","thorns","large thorns","big thorns" }), 
		"Most of the tree is encased in big spiky thorns. ");	
	add_item(({ "leaves" }), 
		"@exa_leaves()");
	add_item(({ "branch","branches" }), 
		"@exa_branch()");
	add_item(({ "small branch" }), 
		"@exa_small_branch()");
	add_item(({ "ground", "entrance","floor" }),
		"@make_ground()");
	add_item(({ "forest" }),
		"@exa_forest()");
	add_item(({ "opening","hole" }),
		"@exa_opening()");
		
	add_command(({ "tie rope", "tie rope to branch" }), "@cmd_tie()");
	add_command(({ "hang", "hang down","hang in branch" }), "@cmd_hang()");
	add_item(({ "rope" }),"@exa_rope()");
	add_item_cmd("climb","rope","@cmd_rope()");
	add_item_cmd("use","rope","@cmd_rope()");
}
// NOT DONE

cmd_rope() {
	if ((exa_forest == 3) && (rope == 1)) {
	  "/std/msg"->msg
	("You climb down the rope to reach the branch below. When you are almost \n"+
	"down, you can hear a big cracking sound from the branch you are dangling \n"+
	"from.  You barely manage to catch the branch under you and climb onto the \n"+
	"forest tree.\n\b|" +
	"\bPRON climbs down the rope towards the branch below. KRAAAAAAKK!!!\n"+
	"\bcapposs weight makes the branch you are standing on break in half. \n"+
	"You almost fall off.\n");
	this_player()->move_player("into the forest",
    "/players/wilhelm/area/bloodwood/rooms/tree2");
	rope = rope = 0;
	return line_break("You will not be able to get back that way!");
  }
  	if ((rope == 2)){
	write ("What rope?\n");
    return 1;
  }
	if ((rope == 1)){
		"/std/msg"->msg
	("You climb down the rope that hangs freely in the air.. When you few feet \n"+
	"down, you can hear a big cracking sound from the branch you are dangling \n"+
	"from. WOOOOOOOSJJJ!! \n"+
	"The ground is approaching fast, this will hurt!\n\b|" +
	"\bPRON climbs down the rope. KRAAAAAAKK!!!\n"+
	"\bcapposs weight makes the branch you are standing on break in half. \n"+
	"You almost fall off. Wonder what happend to \bPRON?\n");
	rope = rope = 0;
	this_player()->move_player("down, with great speed",
    "/players/wilhelm/area/bloodwood/rooms/forest_p1");
	this_player()->add_hp(-8);
    return 1;
  }
  	if ((rope == 0)){
	write ("rope in blace, but no branch\n");
    return 1;
  }
  return line_break ("You consider it, but there is nothing to reach underneath you.");
  }


cmd_hang() {
	if ((exa_forest == 3) && (rope == 2)) {
    "/std/msg"->msg
	("You carefully pull yourself down from the branch, trying to reach the branch \n"+
	"beneath you. It is still to far down, perhaps if you had a rope.\n\b|" +
	"\bPRON suspends \bobj down from the branch, but fails to reach the branch below.\n");
	return 1;
  }
	if ((exa_forest == 3)){
	write ("It might be safer to use the rope attached to the branch.\n");
    return 1;
  }
  return line_break ("You consider it, but there is nothing to reach underneath you.");
  }
	
cmd_tie(){
	object obj;
	obj=present("rope",this_player());
	{
  if((present("rope", TP)) && (rope == 2)){
    "/std/msg"->msg("\bPRON tie\b$ a rope to the branch.\n");
	rope = rope = 1;
	destruct(obj);
    return 1;
	}
  if((present("rope", TP)) && (rope == 1)){
	write ("There is already a rope tied to the branch.\n");
    return 1;
	} 	
  if((present("rope", TP)) && (rope == 0)){
	write ("The branch is to short for that to help.\n");
    return 1;
	} 
  return "You don't have a rope.\n";
}}

exa_rope() {
	if ((exa_forest == 3) && (rope == 1)) {
    return line_break("The rope is tied around the branch you are standing on, "+
	"leading down to another branch beneath it.");
  }
  	if (rope == 1) {
    return line_break("The rope is tied around the branch you are standing on, "+
	"dangling down to nothing.");
  }
  return line_break("You can't see any rope.");
  }


exa_branch() {
    
	if ((exa_forest == 3) && (rope == 1)) {
	return line_break("It's a long branch far above the forest entrance with a rope "+
	"tied to it. A smaller branch sticks out from the forest a few feet below. Maybe "+
	"you can reach it with the rope.");
	}
	if ((exa_forest == 3) && (rope == 0)) {
	return line_break("It's a long broken branch far above the forest entrance. A "+
	"smaller branch sticks out from the forest a few feet below.  If the branch wasn't "+
	"broken you might have been able to climb down. Try again later.");
	}	
    if (exa_forest == 3) {
	return line_break("It's a long branch far above the forest entrance. It sways "+
	"up and down. A smaller branch sticks out from the forest below it. Maybe you "+
	"can hang down to it.");
	}
	if (rope == 1) {
	return line_break("It's a long branch far above the forest entrance with a rope "+
	"tied to it. The rope doesn't seem to have any use.");
	}
	if (rope == 0) {
	return line_break("It's a broken branch far above the forest entrance.");
	}
	return line_break("It's a branch far above the forest entrance. It sways "+
	"up and down. ");
}
 

// -- Commands output --------------------------------------------------------

exa_forest() {
  if ((exa_forest == 1) && (cut_vine == 0)) {
    name = this_player() -> query_real_name();
    seen_forest[name] = 1;
    return line_break("You can almost touch the canopy of the forest beside you.  "+
	"There might have been a way to enter the forest from here, but not anymore. "+
	"Try again later.");
   }
    if (exa_forest == 1) {
    name = this_player() -> query_real_name();
    seen_forest[name] = 1;
	
	add_item_cmd("swing","vine","@swing_vine()");
	add_command("swing over","@swing_vine()");
	add_item_cmd("cut","vine","@cut_vine()");
	
    return line_break("You can almost touch the canopy of the forest beside you. "+
	"A long vine hangs out from one of the trees and swings our the branch you "+
	"are standing on.");
  }
    if ((exa_forest == 2) && (enter_opening == 0)) {
    name = this_player() -> query_real_name();
    seen_forest[name] = 1;
    return line_break("You can almost touch the canopy of the forest beside you. "+
	"There might have been a way to enter the forest from here, but not anymore. "+
	"Try again later.");
  }
    if (exa_forest == 2){
    name = this_player() -> query_real_name();
    seen_forest[name] = 1;
	
	add_item_cmd("enter","hole","@enter_opening()");
	add_item_cmd("enter","opening","@enter_opening()");
	
    return line_break("You can almost touch the canopy of the forest beside you. "+
	"There is a small opening in the wall of leaves.");
  }
     if (exa_forest == 3) {
    name = this_player() -> query_real_name();
    seen_forest[name] = 1;
    return line_break("You can almost touch the canopy of the forest beside you. "+
	"A small branch sticks out from the forest just a few feet below.");
  }
  return line_break("You can almost touch the canopy of the forest beside you.");
}

swing_vine() {
	if (cut_vine == 2){
    return line_break("The long vine is tangled around the tree, you need to "+
	"cut it loose first.");
	}
	if (cut_vine == 1){
	cut_vine = cut_vine = 0;
	call_out("swing_vine",2);
	write ("You take a firm grip of the vine, and swing yourself toward the forest. \n"+
	"This might not have been the smartest thing to do, it's a long way down. \n"+
	"You meet the forest wall at great speed, slamming into a tree branch. \n");
	this_player()->move_player("into the forest",
    "/players/wilhelm/area/bloodwood/rooms/tree2");
    return line_break("You will not be able to get back that way!");;
	}
  return line_break("The long vine that used to be here is gone. Someone "+
	"has already used it to enter the forest.");
  }
  
 
enter_opening() {
  name = this_player() -> query_real_name();
  if (seen_forest[name]) {
    if ((exa_forest == 2) && (enter_opening == 1)) {
	enter_opening = enter_opening = 0;
	"/std/msg"->msg("You carefully climb into the small opening.\n\b|" +
	"\bPRON climbs into a small opening in the leaves.\n"+
	"Like magic, the hole disappears.\n");
	this_player()->move_player("into the forest",
    "/players/wilhelm/area/bloodwood/rooms/tree2");
	return line_break("Like magic, the hole behind you disappears. "+
	"You will not be able to get back that way!");
	}
	return line_break("Opening gone HAHAHA. ");
	}
 	return line_break("No opening to enter. ");	
}
 
  

string cut_vine() {
  object *wep;

  wep=this_player()->query_wielded_objects();
  if (pointerp(wep)) {
    if (cut_vine == 1) { return "The vine has already been cut loose."; }
	if (cut_vine == 0) { return "There isen't any vines to cut."; }
	if (sizeof(wep) == 0) { return "You don't have anything to cut the vine with."; }
    switch (wep[0]->query_type()) {
      case "chop" :
	  case "slash" :
	  case "pierce" :
	  cut_vine = cut_vine = 1;
	  "/std/msg"->msg("\bPRON cut\b$ off the entangled vine.\n");
			return "";
	  case "hand-to-hand" :
	  cut_vine = cut_vine = 1;
			return "With a powerful karate chop, you cut the vine loose.\n";
	  case "crush" :
      case "fire" : 
      case "electricity" : 
      case "cold" : 
	  case "drain" : 
	  case "acid" : return "Your wielded weapon is not really suited for the job.\n"+
	  "Try to find a better weapon to cut the vine.\n";
      default : return "Your wielded weapon is not really suited for the job.\n"+
	  "Try to find a better weapon to cut the vine.\n";
    }
  }
  else return "foo";
  return "bar";
}



exa_leaves() {
	name = this_player() -> query_real_name();
	if (seen_forest[name]) {
	if ((exa_forest == 2) && (enter_opening == 1)) {
    return line_break("You can see an opening in the wall of leaves to the west.");
  }
  return line_break("The trees is covered in dark green leaves.");
  }
  return line_break("The trees is covered in dark green leaves.");
}


exa_opening() {
	name = this_player() -> query_real_name();
	if (seen_forest[name]) {
	if ((exa_forest == 2) && (enter_opening == 1)) {
    return line_break("It's a small opening in the wall of leaves. You might be "+
	"able to enter it.");
  }
  return line_break("You can't see any openings.");
  }
  return line_break("You can't see any openings.");
}



exa_small_branch() {
	name = this_player() -> query_real_name();
	if (seen_forest[name]) {
	if (exa_forest == 3) {
    return line_break("The smaller branch is a few feet below you. You might "+
	"be able to reach it by dangling down from the branch you are standing on.");
	}
	return line_break("You can only see the branch you are standing on and it "+
	"doesn't qualify as small.");
	}
	return line_break("You can only see the branch you are standing on and it "+
	"doesn't qualify as small.");
}




exa_vine() {
	name = this_player() -> query_real_name();
	if (seen_forest[name]) {	
	if ((exa_forest == 1) && (cut_vine == 2)) {
    return line_break("A long vine sticks out from one of the forest trees, "+
	"looping around the branch you are standing on. You might be able to swing "+
	"over to the forest tree with it.");
	}
	if ((exa_forest == 1) && (cut_vine == 1)) {
    return line_break("A long vine sticks out from one of the forest trees "+
	"and hangs loosely over the branch you are standing on. You might be able "+
	"to swing over to the forest tree with it.");
	}
	if ((exa_forest == 1) && (cut_vine == 0)) {
    return line_break("The long vine that used to be here is gone. Someone "+
	"has already used it to enter the forest.");
	}
	return line_break("The tree is overgrown with thick looping coils of vines, "+
	"that stretches down from the tree branches down to the ground.");
	}
	return line_break("The tree is overgrown with thick looping coils of vines, "+
	"that stretches down from the tree branches down to the ground.");
}


make_ground() {
  write("You peek down on the ground. You see: \n"); 
  write("/obj/look"->describe_inventory(load_object
  ("/players/wilhelm/area/bloodwood/rooms/forest1"), 1, this_player()));
  return "";
}

get_long() {
  string caught;
  
  if (this_player()-> query_property("wilhelm_bloodwood_horn")) {
    caught = "You can feel someone watching you from inside the forest.";
  }
  else {
	caught = "You have almost managed to sneak inside, without the forest "+
	"residents catching you.";
  }
  return line_break("You are standing on a large branch far above the ground. "+
  "The massive forest looms beside you to the west. The branch waves gently up "+
  "and down in the breeze, making this feel like an unsafe place to linger "+
  "in. " + caught + "");

}

// -- Night and Day time descriptions ---------------------------------------





// -- Random happenings -------------------------------------------------------
