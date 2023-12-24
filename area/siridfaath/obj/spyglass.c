#define TP this_player()

// -- Description and settings -------------------------------------------

inherit "std/basic_thing";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("spyglass");
    add_alias("wilhelm_spyglass");
    set_short("a spyglass");
    set_long("A cylinder-shaped device for making objects that are far away "+
	"look closer and larger. You should be able to scout with it.");
    add_property("quest_item");
    set_weight(1);
    set_value(25);
   add_command("scout %s","@scout()");
  }
}



scout(foo,arg) {
   string exit;
   mapping exits;
   
   exit = arg;
   if (!exit) {
      notify_fail("Scout where?\n");
      return 0;
   }
   switch(exit) {
      case "e":
      exit = "east";
      break;
      case "n":
      exit = "north";
      break;
      case "w":
      exit = "west";
      break;
      case "s":
      exit = "south";
      break;
      case "ne":
      exit = "northeast";
      break;
      case "nw":
      exit = "northwest";
      break;
      case "se":
      exit = "southeast";
      break;
      case "sw":
      exit = "southwest";
      break;
      default:
      break;
   }
   exits = environment(this_player())->query_exits();
   if (!exits[exit]) {
      notify_fail("You can't scout in that direction\n");
      return 0;
   }
      
   "/std/msg"->msg("\bPRON look\b$ through the spyglass.\n");
   if (stringp(exits[exit][0])) {
      exit = exits[exit][0];
   }
   else {
      exit = exits[exit];
   }
   write ("You see:\n");
   write("/obj/look"->describe_inventory(load_object
  (exit), 1, this_player()));
  
   return 1;
}

