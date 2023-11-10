// -- This line is 78 characters long ----------------------------------------
inherit "/std/stationary";
int rose_is_here,rose;

reset(arg) {
  ::reset(arg);
  rose_is_here = 1;
  rose = 1;
  if (arg) return;

  set_name("pedestal");
  add_alias("chest");
  add_alias("wilhelm_bloodwood_pedestal");
  set_short("a pedestal");
  set_long("The pedestal is made out of branches stretching up from "+
  "the floor. On top, a single rose is hovering.");
  set_long("@get_long()");
  add_property("wooden");
  add_property("colour", "brown");
  
  add_command("take rose", "@cmd_take_rose()");
  add_command("touch rose", "@cmd_take_rose()");
  
} 

get_long() {
  
  if (rose == 1) {
  return line_break ("The pedestal is made out of branches stretching up from "+
  "the floor. On top, a single rose is hovering.");
  }
  return line_break ("The pedestal is made out of branches stretching up from "+
  "the floor. It's empty.");

}

cmd_take_rose() {
  object item;
  
  if (rose == 0){
  return line_break("The pedestal is empty.");	  
  }		  
  if (this_player()-> query_puzzle("wilhelm_bloodwood_quest")){
  return line_break("You have already absorbed the power of the rose. Leave it "+
  "for someone else.");
  }		
  if (this_player()-> query_property("wilhelm_bloodwood_horn")){
  this_player()->add_hp(-2);	  
  return line_break("The curse of path magic hangs over you. When you stretch "+
  "out to touch the rose, sharp thorn grow out of the rose, driving into your hand. ");
  }
  this_player()-> add_property("wilhelm_bloodwood_quest");
  rose = 0;
  item = clone_object("/players/wilhelm/area/bloodwood/obj/magic_rose");
  transfer(item,this_player());
  return line_break("You stretch out and take the rose in front of you. The powerful "+
  "blood magic of the rose seems to pulsate through you, welcoming you to its forest.");
}

