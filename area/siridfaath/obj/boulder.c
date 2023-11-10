// -- This line is 78 characters long ----------------------------------------
inherit "/std/basic_thing";
int boulder_moved = 1;
int boulder_moved2 = 1;
int boulder_dig = 1;
int boulder_root = 1;

reset(arg) {
  ::reset(arg);
//  where_is_boulder = 1;
  if (arg) return;

  set_name("boulder");
  add_alias("chest");
  add_alias("large boulder");
  add_alias("wilhelm_boulder");
  set_short("a boulder");
  set_long("@long_desc()");
  set_weight(50);
  

  add_property("colour", "grey");
  add_property("non-gettable", "It's way too heavy.\n");
  
 // add_command("push %s","@cmd_push()");
 // add_command("climb %s","@cmd_climb()");
  
  if(!environment()) 
    move_object(this_object(), "players/wilhelm/area/bloodwood/rooms/meadow2");
  
} // reset

  query_boulder() { return boulder_moved; }
  query_boulder4() { return boulder_moved2; }
  query_boulder2() { return boulder_dig; }
  query_boulder3() { return boulder_root; }
  
long_desc(){
  if(environment() && (environment()->query_property("wilhelm_meadow2")) && (boulder_dig == 1)){
  return ("It's a large relatively round boulder, in the middle of the extensive meadow. \n"+
  "The ground under it is packed up with small rocks and compact dirt, \n"+
  "making it stand steady in the terrain.\n");
  }
  if(environment() && (environment()->query_property("wilhelm_meadow2")) && (boulder_dig == 0)){
  return ("It's a large relatively round boulder, in the middle of the extensive meadow. \n"+
  "The ground under it is has been cleared of rubble making the chance for it to roll away \n"+
  "considerable. It might just take a push.\n");
  }
  if(environment() && (environment()->query_property("wilhelm_path4")) && (boulder_root == 1)){
  return ("It's a large relatively round boulder, in the middle of the path. It seems to be \n"+
  "stuck on a root, stopping it from rolling away.\n");
  }
  if(environment() && (environment()->query_property("wilhelm_path4")) && (boulder_root == 0)){
  return ("It's a large relatively round boulder, in the middle of the path.\n "+
  "Nothing is holding the big rock in place. A small push would make it roll off.\n");
  }
  return ("It's a large boulder, stuck somewhere it should not be. BUG it. \n");
  }

  

int move_boulder() {
  if (!query_boulder()) return 0;

  move_object(this_object(), "players/wilhelm/area/bloodwood/rooms/path4");
  tell_room ("players/wilhelm/area/bloodwood/rooms/path4",
             "You are almost hit by a large boulder, that comes "+
			 "rolling in from the north.\n");
  boulder_moved = 0;
  return 1;
}

int move_boulder2() {
  if (!query_boulder4()) return 0;
                              
  move_object(this_object(), "players/wilhelm/area/bloodwood/rooms/meadow1");
  tell_room ("players/wilhelm/area/bloodwood/rooms/meadow1",
             "A large boulder rolls into the field, slamming into the tree.\n");
  boulder_moved2 = 0;
  return 1;
}


int dig_boulder() {
  if (!query_boulder2()) return 0;
  tell_room ("players/wilhelm/area/bloodwood/rooms/meadow2",
  "The large boulder wobbles back and forth.\n");
  boulder_dig = 0;
  return 1;
}

int cut_boulder() {
  if (!query_boulder3()) return 0;
  tell_room ("players/wilhelm/area/bloodwood/rooms/path4",
  "The large boulder wobbles back and forth.\n");
  boulder_root = 0;
  return 1;
}
