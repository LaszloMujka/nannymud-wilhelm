/*BloodWood*/

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
#define TD "/obj/util/timed"
#define BRANCH "/players/wilhelm/area/bloodwood/branch1"
#define LOGGER load_object("/players/wilhelm/simple_logger")

int where_is_branch;
mapping seen_branch;
string name;

void reset(int arg) 
{
  ::reset(arg);
    where_is_branch = random(3) + 1;
    seen_branch = ([]);
  if (arg) 
    return;

// -- Properties ---------------------------------------------------------

  add_property("forest");
  add_light(1);
  add_exit("down", "meadow1");
  
  add_hidden_exit("west", "@check_west()");
  add_hidden_exit("north", "@check_north()");
  add_hidden_exit("northwest", "@check_northwest()");
  //set_bottom("/players/wilhelm/area/bloodwood/meadow1");
  //add_exit("up","hole1",0,"@hole_check()");
  
// -- Description and settings -------------------------------------------

  set_short("up a tree");
  set_long("You are up in a large tree, holding on to a nearby branch. "+
  "The tree branches are covered in sharp thorns, making movement "+
  "difficult.");    

// -- Items and Commands -------------------------------------------------
  
	add_item(({"tree"}),
		"It's a large tree with long thick branches stretching out in all "+
		"directions. Dark green leaves cover up the sky above you. ");
	add_item(({ "plain","plains","feild","fields" }), 
		"You can see the large dry fields below you.");  
    add_item(({ "vine","vines" }), 
		"The tree is overgrown with thick looping coils of vines, that "+
		"stretches down from the tree branches down to the ground.");
    add_item(({ "moss","tendril","tendrils" }), 
		"Large tendrils of red-tinged moss cover the tree. ");	
	add_item(({ "thorn","thorns","large thorns","big thorns" }), 
		"Most of the tree is encased in big spiky thorns. ");	
	add_item(({ "leaves" }), 
		"The tree is covered in dark green leaves.	 ");	
	add_item(({ "branch", "branches" }), "@exa_branch()");
	
}


// -- Commands output --------------------------------------------------------
/*
occupied() {
  object obj;
  
  foreach(obj,all_inventory())
    if(interactive(obj)) 
      return obj->query_name();
  return 0;
}

branch_check() {
  string name;
  name=BRANCH->occupied();
  if (name) {
    write("You find the branch occupied by "+name+".\n");
    return 1;
  }
  return;
}
*/
exa_branch() {
  if (where_is_branch == 1) {
    name = this_player() -> query_real_name();
    seen_branch[name] = 1;
    return line_break("Long branches stretch out from the tree trunk in all "+
	"directions. They are covered in sharp thorns and long vines. One of the "+
	"branches seems more sturdy than the others, heading to the north.");
  }
    if (where_is_branch == 2) {
    name = this_player() -> query_real_name();
    seen_branch[name] = 1;
    return line_break("Long branches stretch out from the tree trunk in all "+
	"directions. They are covered in sharp thorns and long vines.One of the "+
	"branches seems more sturdy than the others, heading to the northwest.");
  }
     if (where_is_branch == 3) {
    name = this_player() -> query_real_name();
    seen_branch[name] = 1;
    return line_break("Long branches stretch out from the tree trunk in all "+
	"directions. They are covered in sharp thorns and long vines. One of the "+
	"branches seems more sturdy than the others, heading to the west.");
  }
  return line_break("Long branches stretch out from the tree trunk in all "+
  "directions. They are covered in sharp thorns and long vines.");
}

check_north() {
  name = this_player() -> query_real_name();
    if (seen_branch[name]) {
    if (where_is_branch == 1) {
    write("You crawl out on the large branch.\n");
    this_player()->move_player("onto a branch",
      "/players/wilhelm/area/bloodwood/rooms/branch1");
      return 1;}
  else
     write("You cut yourself on a large thorn, when you try to "+
	"move onto one of the branches..\n");
	this_player()->add_hp(-2);
	write("The tree absorbs the blood, from your cut.\n");
  return 1;}
}

check_northwest() {
  name = this_player() -> query_real_name();
    if (seen_branch[name]) {
    if (where_is_branch == 2) {
    write("You crawl out on the large branch.\n");
    this_player()->move_player("onto a branch",
      "/players/wilhelm/area/bloodwood/rooms/branch1");
      return 1;}
  else
     write("You cut yourself on a large thorn, when you try to "+
	"move onto one of the branches..\n");
	this_player()->add_hp(-2);
	write("The tree absorbs the blood, from your cut.\n");
  return 1;}
}

check_west() {
  name = this_player() -> query_real_name();
    if (seen_branch[name]) {
    if (where_is_branch == 3) {
    write("You crawl out on the large branch.\n");
    this_player()->move_player("onto a branch",
      "/players/wilhelm/area/bloodwood/rooms/branch1");
      return 1;}
  else
    write("You cut yourself on a large thorn, when you try to "+
	"move onto one of the branches..\n");
	this_player()->add_hp(-2);
	write("The tree absorbs the blood, from your cut.\n");
  return 1;}
}


// -- Night and Day time descriptions ---------------------------------------





// -- Random happenings -------------------------------------------------------
