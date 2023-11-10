/*Inside the well in Siridfath*/
// -- This line is 78 characters long ----------------------------------------

#define BUCKET "/players/wilhelm/area/siridfaath/obj/bucket"
#define LOGGER load_object("/players/wilhelm/simple_logger")

inherit "/std/water_room";
object bucket = load_object("/players/wilhelm/area/siridfaath/obj/bucket");

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;
    
// -- Properties ---------------------------------------------------------

  add_light(1);
  add_property("inside");
  add_property("no_teleport");
  set_bottom("/players/wilhelm/area/siridfaath/siridfaath_cave1");
  enable_commands();
  
// -- Exits -----------------------------------------------------------------

//  add_exit("up", "siridfaath2");
//  add_exit("south", "siridfaath_cave1"); 
  
// -- Description -----------------------------------------------------------

  set_short("inside a well");
  set_long("Ice cold water reaches up to your chest. You are standing on an "+
    "iron grate, your feet slip through sometimes making it hard to stand "+
    "upright. The dark stone walls feel like they are creeping towards you, "+
    "making you feel almost claustrophobic.");
 
// -- Items and Commands ----------------------------------------------------
 
  add_item(({ "well" }),
    "The well is dark and slippery in here, filled up with ice cold water."+
    "High up the stone walls you can see the opening, back out to  the "+
    "village of Siridfaath.");
  add_item(({ "wall","walls","stone wall","stone walls","dark stone walls" }),
    "The dark walls in the well is made up by laid stones. High above, you "+
    "can see the opening leading back out to Siridfaath.");
  add_item(({ "stone","stones","laid stone","laid stones" }),
    "The stones are cold and slippery.");
  add_item(({ "opening" }),
    "The only source of light down here, is the small opening high above you.");
  add_item(({ "light" }),
    "A little light pours down from the opening in the well high above you.");
  add_item(({ "water" }),
    "The water you are standing in is dark and ice cold. You can hardly see "+
    "anything under it.");
  add_item(({ "grate" }),
    "You can't see it trough the dark water. You have to dive under to see "+
    "more.");
  
  add_item("rope", "@make_rope()");
  add_item("hole", "@make_hole()");
      
  add_command(({ "dive", "dive under", "dive under water" }), "@cmd_dive()");
  add_command(({ "climb %s" }), "@cmd_climb()");
  //add_command(({ "enter hole" }), "@cmd_enter()");
  add_command(({ "enter %s" }), "@cmd_enter()");
  
}

// -- Commands output --------------------------------------------------------

cmd_dive() {
  "/std/msg"->msg("\bPRON dive\b$ under the water.\n");
  write("Searching around on the bottom of the well, you notice a small hole "+
    "in the grate.\n");
  this_player()->add_property("wilhelm_well_hole");
  return 1;
} // Reset cmd_dive

make_hole() {
  if(this_player()->query_property("wilhelm_well_hole")) {
  return"It seems some bars in the grate are broken, making a small hole. \n"+
    "You might be able to force your way trough it.\n"; }
  else
  return"There is no hole here.\n";
} // Reset make_hole


make_rope() {
  bucket = load_object(BUCKET);
  if(bucket->query_raised())
    return line_break("There is no rope here.");
  if(environment(bucket)->is_player())
    return line_break("The rope is tied to the bucket held by " + 
      environment(bucket)->query_name() + ".");
  else
    return line_break("The rope is tied around the old wooden bucket " +
      "and goes straight up in the air.");
} //Reset make_rope
/*
string old_cmd_climb(int arg, string c) {
  object o;
  if(!c) return "Climb what?\n";
  else switch(c) {
    case "wall" :
    case "stone wall" :
    case "stone walls" : 
    case "walls" : return "The stone wall is so slippery, it is impossible to "+
      "climb.\n";
    case "rope" :
    foreach(o, all_inventory(this_player())) {
    if(file_name(o)[0..25] == "players/wilhelm/obj/bucket")
    return "You can't climb the rope, while holding the bucket.";
    }
    if(!present("wilhelm_bucket", this_object())) {
    return "You can't find any rope to climb.";}
      else{
      this_player()->move_player("up the rope","/players/wilhelm/area/siridfaath/rooms/"+
      "siridfaath2");
      return "";
      }
    }     
} // Reset climb
*/

cmd_climb(int arg, string c) {
  bucket = load_object(BUCKET);
  object o;
  if(!c) return "Climb what?\n";
  switch(c) {
    case "wall" :
    case "stone wall" :
    case "stone walls" : 
    case "walls" : 
      return "The stone wall is so slippery, it is impossible to climb.\n";
    case "rope" :
      if(bucket->query_raised())
        return "You can't find any rope to climb.";
      if(environment(bucket)->is_player())
        return "You can't climb the rope while the bucket is being held.";
      this_player()->move_player("up the rope",
        "/players/wilhelm/area/siridfaath/rooms/siridfaath2");
  }
  return 1;
} // Reset climb

catch_tell(str) {
  if(sscanf(str, "%*s says: %s", str) != 2) return;

  tell_room("/players/wilhelm/area/siridfaath/rooms/siridfaath2", 
    "You hear someone talking from inside the well: " + str);
} // Reset catch_tell 

// -- Enter hole  ------------------------------------------------------------

cmd_enter(int arg, string c) {
  bucket = load_object(BUCKET);
  object o;
  if(!c) return "Enter what?\n";
  switch(c) {
    case "well" : 
      return "You are already inside the well.\n";
    case "hole" :     
	  if(environment(bucket)->is_player())
      return "You can't go anywhere while holding this bucket.";
	  if (this_player()-> query_property("wilhelm_well_hole") 
      && this_player()-> query_property("wilhelm_cave_key")) {
      write("You dive down into the cold water, towards the small hole in the \n"+ 
	  "grate. With force, you push your body through and swim further down \n"+
	  "into the cold dark. A strong current in the water drags you away into \n"+
	  "a damp freezing cave.  \n");
      this_player()->move_player("into the water",
      "/players/wilhelm/area/siridfaath/rooms/siridfaath_cave1");
	  return 1;
	}	
	  if(this_player()->query_property("wilhelm_well_hole"))
      return 
    "You dive down into the cold water, towards the small hole in the grate. \n"+
	"The water is extremely dark and the opening so small. You simply can't force \n"+
	"yourself to go down there without a good reason. \n";
      return "What hole?\n";
    }
  return 1;
}