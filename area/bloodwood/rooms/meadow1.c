/*Path towards BloodWood*/

inherit "/players/wilhelm/area/siridfaath/rooms/outdoor_rooms";
#define TD "/obj/util/timed"
//#define LOGGER load_object("/players/wilhelm/simple_logger")
#define BOULDER "/players/wilhelm/area/bloodwood/obj/boulder"

object boulder = load_object("/players/wilhelm/area/bloodwood/obj/boulder");

void reset(int arg)
{
  ::reset(arg);
  
  if (arg)
    return;

// -- Properties ---------------------------------------------------------

  add_property("outdoors");
  add_property("wilhelm_meadow1");
  add_light(1);
  
  add_exit("northeast", "path4", 1, "do_northeast");
  add_hidden_exit("west", "meadow2", 0, "forest");
  add_hidden_exit("east", "meadow2", 0, "lost");
  
// -- Description and settings -------------------------------------------

  set_short("a meadow");
  set_long("You are standing in a meadow of decaying grass close to an "+
  "enormous forest.  A large tree stands alone in the middle of the meadow.");       

// -- Items and Commands -------------------------------------------------

  add_item( ({ "forest" }),
    "An oasis of dark green, shining like a vast emerald beside the plains. "+
	"It grows thick, not making you able to enter it from here.");
  add_item(({ "mountain", "mountains", "mountain range" }),"@make_mountain()");
  add_item(({ "path","trail","track" }), 
    "The small path is back to the northeast.");
  add_item( ({ "grass" }),
    "The grass around you is withering and much shorter here closer to the forest.");
  add_item( ({ "ground","soil" }),
    "The soil under your feet is dry and lifeless.");	
  add_item( ({ "field","fields","meadow",",meadows","plain","plains"}),
    "Hugh fields of withering grass that are waving and rustling the breeze. "+
	"The grass seems to gain more life the further away from the forest. ");
  
  add_item( ({ "tree","large tree" }),
    "The tree reaches far up into the sky, with large branches stretching out in "+
	"all directions. The tree is covered in dark green leaves and long vines hang "+
	"down around the trunk. Long tree roots span out from the trunk of the tree.");
  add_item( ({ "branches","branch" }),
    "The tree has many large sturdy branches high up in the tree.");
  add_item( ({ "trunk","tree trunk" }),
    "It's a think tree trunk covered in sharp thorns and green moss.");
  add_item( ({ "thorns","thorn","sharp thorn,","sharp thorns" }),
    "The tree is covered in large sharp torns, making it unclimbable."); 
  add_item( ({ "trunk","tree trunk" }),
    "Long vines hang down from the tree branches, twisting around the trunk of "+
	"the tree."); 
  add_item( ({ "branches","branch" }),
    "The tree is covered in dark green leaves, rustling gently in the breeze.");
  add_item( ({ "moss" }),
    "Moss is clinging to the tree trunk between the thorns and vines.");
  add_item( ({ "root","roots","tree root","tree roots" }),
    "Think tree roots stretch out from the tree into the ground in the meadow. "+
	"It seems to be siphoning the life out of the nearby grass.");
 
  add_item_cmd("climb","tree","@cmd_climb_tree()"); 
  add_command("climb boulder","@cmd_climb_boulder()"); 
  
  add_command("search %s", "@cmd_search()");
  add_command(({ "enter %s" }), "@cmd_enter()");
}

cmd_climb_boulder()
	{
  boulder = load_object(BOULDER);
  if(present("boulder", this_object()) && 
    (this_player()-> query_property("wilhelm_climb_boulder"))){
	write ("You are already standing on the boulder. \n");
    return 1;}
  if(present("boulder", this_object())){
    "/std/msg"->msg("\bPRON climb\b$ up on the large boulder.\n");
	write ("You manage to climb up on the large boulder using the tree trunk as support. \n");
	this_player()->add_property("wilhelm_climb_boulder");
    return 1;}
	
  return "Climb what?\n";
}

cmd_climb_tree()
	{
  object obj,eq;
  eq=this_player()->query_worn();  
  boulder = load_object(BOULDER);
  if(present("boulder", this_object()) && 
    (this_player()-> query_property("wilhelm_climb_boulder"))){
	write ("You manage to reach one of the trees lowest branches and climb up the tree.\n");
	this_player()->move_player("up",
    "/players/wilhelm/area/bloodwood/rooms/tree1");
    this_player()->remove_property("wilhelm_climb_boulder");
    return 1;}
  if (eq)  
    obj=eq["glove"];
	if (obj && obj -> id("wilhelm_gardener_gloves")) {
	write ("With protection from your gloves, you manage to climb the tree.\n");
	this_player()->move_player("up",
    "/players/wilhelm/area/bloodwood/rooms/tree1");
    this_player()->remove_property("wilhelm_climb_boulder");
    return 1;}	
  else
      "/std/msg"->msg("You try to climb up the tree, but cut yourself on the sharp thorns.\n\b|" +
		  "\bPRON tries to climb up the tree, but fails.\n");
	this_player()->add_hp(-2);
	write ("The blood from your cut is quickly absorbed by the tree. \n");
    return 1;}
	

do_northeast() {
  
  if (this_player()-> query_property("wilhelm_climb_boulder")){
    this_player()->remove_property("wilhelm_climb_boulder");
	// this_player()->move_player("northeast",
  // "/players/wilhelm/area/bloodwood/rooms/path4");
  write("You jump down from the large boulder and walk northeast.\n");
  return;
  }
  else
  this_player()->move_player("northeast",
  "/players/wilhelm/area/bloodwood/rooms/path2");	
	return;
}



/*
cmd_climb(int arg, string c) {
  if(!c) return "Climb what?\n";
  switch(c) {
    case "forest" :
      return "You can't climb the forest.\n";
    case "tree" :
    case "large tree" :
	  return "The braches are to high up, you can't reach them from the ground.\n";
	case "rock" :
         "/std/msg"->msg("\bPRON climb\b$ onto the rock.\n");
    this_player()->add_property("wilhelm_climb_rock");
	
  }
  return 1;
}
*/


// -- Hidden Exits -------------------------------------------------------

forest()
{
  return "The forest is to thick to enter from here.";
} 

lost()
{
  return "Traveling into the high grass will just get you lost.";
} 


// -- Night and Day time descriptions ---------------------------------------

make_mountain() {
  if (TD -> query_daytime()) {
  return line_break("The huge mountain range to the east stretch up far into "+
  "the sky, crashing into the clouds.");
  }
    
  return line_break("In the dark night the mountain to the east just looks "+
  "like a dark black wall.");
} // Reset make_mountain

// -- Commands output --------------------------------------------------------

string cmd_search(int arg, string s) {
  object note;
  if(!s) return "You should be more specific.\n";
  else switch(s) {
    case "grass" :
	case "meadow" :
	case "meadows" :
	case "plain" :
	case "plains" :
	case "field" :
    case "fields" : return  "You search around in the grass, but all you "+
            "can find is more grass.\n";
    case "forest" : return "You search around the edge of the forest, but "+
	"find nothing of interest. \n";
    case "tree" : return  "You search around the tree trunk, but find "+
	"nothing of interest.\n";
    case "mountain" :
    case "mountain range" : return "It is too far away to search.\n";
    case "trail" :
    case "path" : return "You can't search the path from here.\n";

  }
}

cmd_enter(int arg, string c) {
  if(!c) return "Enter what?\n";
  switch(c) {
    case "forest" :
      return "The forest is to thick to enter from here.\n";
    case "tree" :
      return "There is no way to enter the tree.\n";
  }
  return 1;
}


// -- Random happenings -------------------------------------------------------

init() {
  :: init();
  if (find_call_out("weather") == -1)
    call_out("weather", 30);
} 

weather() 
{
  string *day_message, *night_message;
  
call_out("weather", 180);
  day_message = ({
    "The dry meadow grass rustles in the breeze.",
    "A flock of birds flies's by over your head, towards the forest in the west.",
    "The sun shines through the clouds.",
    "The warm sun rays kissed your skin lightly, warming you from the inside out."});
  night_message = ({
    "The dry meadow grass rustles in the cold night breeze.",
    "You hear the sound of a strange animal echoing towards you in the twilight.",
    "Stars illuminated the darkness around you.",
    "The sun has gone to rest, the moon takes his place as the darkness begins to surround you."});
  if(TD->query_daytime()) 
    tell_room(this_object(), day_message[random(sizeof(day_message))] + "\n");
  else
    tell_room(this_object(), 
      night_message[random(sizeof(night_message))] + "\n");
}
