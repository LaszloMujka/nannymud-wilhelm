/*The Amberglass, a tavern in Siridfaath*/

/*
Working on adding a puzzle with the ork in this room.
*/

// -- This line is 78 characters long ---------------------------------------
inherit "/std/room";
#define TD "/obj/util/timed"
#define LOGGER load_object("/players/wilhelm/simple_logger")

int number_of_ale;
int errormessage;


void reset(int arg)
{
  number_of_ale = 6;
  ::reset(arg);
  if (arg)
    return;
    
	 
	
// -- Properties ------------------------------------------------------------

  add_light(1);
  add_property("no_tree");
  add_property("indoors");
  add_property("no_fight");
  add_property("healing_place");
  // add_exit("out", "siridfaath4", 0, "door_out");
  add_exit("out", "siridfaath4", 0, "@check_drinks()");

// -- Description -----------------------------------------------------------

  set_short("The Amberglass");
  set_long("While not lavishly decorated or burdened with frivolities, the "+ 
    "Amberglass is very quiet and comfortable. A strong smell of ale covers "+
    "the tavern. Four tables covers most of the space here, together with a "+
    "bar and a fireplace.");

// -- Items -----------------------------------------------------------------

  add_item( ({ "tavern","inn","amberglass" }),
    "It's a comfy tavern. The room has four tables a bar and a fireplace.");
  add_item( ({ "floor" }),
    "A clean wooden floor.");
  add_item( ({ "ale" }),
    "The scent of ale cover the room.");
  add_item( ({ "table","tables" }),
    "Four plain wooden tables. All but one table is empty.");
  add_item( ({ "door","entrance" }),
    "The door leads back out to the streets of Siridfaath.");
  add_item( ({ "wall","walls" }),
    "Plain wooden walls.");
  add_item( ({ "bar" }),
    "A small bar in the north side of the tavern. It's mostly empty, just "+
    "some mugs, used for serving the customers. You notice a sign on the wall "+
    "behind it.");
  add_item( ({ "mug","mugs" }),
    "The mugs are used to serve ale in.");
  add_item( ({ "sign" }),
    "Its a sign with prices for the ale, you should read it.");
    
  add_item("fireplace", "@make_fireplace()");
//  add_item(({ "customers", "customer", "locals", "villagers" }),"@make_cust()"); (Removed 29.12.2017)
// Reported bug by yoshy. @make_cust isen't made
  add_item(({ "ashes", "ash" }),"@make_ash()");
  add_item(({ "logs", "logs", "wood" }),"@make_log()");
  
  add_item_cmd("read","sign","@cmd_sign()");
  add_item_cmd(({ "get","take" }), "mug", "You should order some ale "+
  "instead.\n");
  add_item_cmd("buy", "ale", "@buy_ale()");
  add_item_cmd("order", "ale", "@buy_ale()");
 
  add_command("buy 1", "@buy_ale()");
  add_command(({ "buy 2","buy amber" }), "@amber()"); 
  add_command("steal sword","@cmd_steal()");
  add_command(({ "sit", "sit table", "sit at table" }), "@cmd_sit()");
  add_command(({ "smell", "smell ale", "sniff","sniff ale" }), "@cmd_smell()");
  add_command(({ "stand" }), "@cmd_stand()");
  add_command(({ "listen" }), "@cmd_listen()");
  
// -- Objects ---------------------------------------------------------------

  add_object("/players/wilhelm/area/siridfaath/monsters/xendri");
  add_object("/players/wilhelm/area/siridfaath/monsters/bone");
}

// -- Night and Day time descriptions ---------------------------------------

make_ash() {
  if (TD -> query_daytime()) {
    return line_break("Dark ash covers the bottom of the fireplace, probably "+
      "from last time it was lit.");
  }
  return line_break("The ash is the fireplace is glowing red and hot.");
}

make_log() {
  if (TD -> query_daytime()) {
    return line_break("The fireplace is filled up with logs ready to be lit, "+
      "but its not really needed, as the tavern already is warm and comfy.");
  }
    
  return line_break("The logs in the fireplace are burning, keeping the "+
    "tavern warm and light.");
}

make_fireplace() {
  if (TD -> query_daytime()) {
    return line_break("A comfy looking fireplace in the east corner of the "+
      "tavern. It has a long mantel on top and the fireplace itself is filled "+
      "up with fresh logs and old ash.");
  }
  return line_break("A comfy looking fireplace in the east corner of the "+
    "tavern. It has a long mantel on top and the fireplace itself is filled "+
    "up with burning logs, keeping the tavern warm."); 
}

// -- Random weather --------------------------------------------------------

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
    "Xendri sweeps the tavern floor.",
    "You hear the sound of a wagon rolling by." });
  night_message = ({
    "Xendri adds some new logs to the fireplace.",
    "Xendri yawns tiredly.",
    "Sparks fly out of the burning fireplace." });
  if(TD->query_daytime()) 
    tell_room(this_object(), day_message[random(sizeof(day_message))] + "\n");
  else
    tell_room(this_object(), 
      night_message[random(sizeof(night_message))] + "\n");
}
// -- Commands --------------------------------------------------------------

cmd_sign() {
  write("  +------------------------+  \n" +
        "  | The Amberglass         |  \n" +
        "  +------------------------+  \n" +
        "  | 1. Dwarf ale :50 gold  |  \n" +
        "  | 2. Amber     :ALL OUT  |  \n" +
        "  |                        |  \n" +
        "  +------------------------+  \n");
  return 1;
} // Read sign

cmd_steal() {
  if(present("wilhelm_ork", this_object()) &&  
     this_player()->query_property("wilhelm_tavern_sword")) {
    "/std/msg"->msg("\bPRON think\b$ carefully.\n");
    write(line_break("There is no way to approach him unseen, with him " +
      "sitting against the wall like that. The only way to get that sword " +
      "will be to fight him, to bad you can't do that in here."));
  }
  else
    write("What sword would that be?\n");
  return 1;
} //Cmd_steal sword

cmd_stand()
{
  if(this_player()->query_property("wilhelm_tavern_sit")) {
    "/std/msg"->msg("\bPRON stand\b$ up from the table.\n");
    this_player()->remove_property("wilhelm_tavern_sit");
  }
  else
    write("You are already standing.\n");
  return 1;
} // Cmd_stand



cmd_smell() {
  "/std/msg"->msg("\bPRON draw\b$ in the smell of ale.\n");
  write("Mmmmmm.\n");
  return 1;
} // Cmd_smell

cmd_sit()
{
  if(this_player()->query_property("wilhelm_tavern_sit"))
    return "You are already sitting.\n";
  if(present("wilhelm_ork", this_object())) {
    this_player()->add_property("wilhelm_tavern_sit");
    "/std/msg"->msg("\bPRON sit\b$ down at one of the empty tables.\n");
    write("Close by the windeling and the ork is in the middle of a "+
      "converastion.\n" +
      "Maybe you can listen in?\n");
  }
  else {
    this_player()->add_property("wilhelm_tavern_sit");
    "/std/msg"->msg("\bPRON sit\b$ down at one of the empty tables.\n");
    write("It sure is nice to relax a little after a long day of travel.\n");
  }
  return 1;
} // Cmd_sit

cmd_listen()
{
  if(!present("wilhelm_ork", this_object()))
    return "You listen to the villagers at the next table.\n";
  if(!this_player()->query_property("wilhelm_tavern_sit"))
    return "You can hear the ork and the windeling in a deep converastion. \n" +
	  "But you are to far away to make out what they are talking about. \n";
  if(!this_player()->query_property("wilhelm_ork_gahad"))
    return "You listen in on the conversation but most of it dosen't make sense.\n" +
	  "Maybe the local library could help you understand more about this \n" +
	  "people and their customs.";
  if(this_player()->query_property("wilhelm_listen_ork"))
    return "The ork has stopped talking and is just sipping his ale. " +
      "While the windeling just goes on with teasing him, about rats.";
  else {
    this_player()->add_property("wilhelm_message", 1);
    call_out("chat",2);
  }
  return 1;
} // Cmd_listen

chat() 
{
  string *chat_message;
  int i;

  // test if ork gets killed or player leaves
  if(!present("wilhelm_ork", this_object()) ||
     !present(this_player(), this_object())) 
    return;

  chat_message = ({
    "You listen in on the conversation.",
    "Janith says: Haha, you're scared of rats!?.",
    "Bone sighs.",
    "Bone says: NO, that's not what I'm saying.",
    "Janith giggles teasingly.",
    "Bone says: What I'm trying to say is, you freaking ujnort!",
    "Janith laughs and takes a sip of her mug of ale.",
    "Janith says: Mmmm, I love this amber ale.",
    "Bone says: You should try some hurlg, now that's a good drink.",
    "Janith goes 'like I'm falling for that again.'",
    "Bone says: Unjort! Now let me get back to my story.",
    "Janith says: Yes yes, your rat fear, go on.",
    "Bone arghs.",
    "Bone says: My gahad has nothing to do about fear of rats.",
    "Bone says: When I was enslaved by the damn Therans, they didn't feed us.",
    "Janith fakes falling to sleep.",
    "Bone says: Listen!",
    "Janith laughs so hard, she almost falls of the table.",
    "Bone says: The dungeon they kept us in at night was crawling with " +
      "sick rats.",
    "Bone says: Sewer water and raw rats, really changes an ork!",
    "Janith says: Yes! Sewer water, that's what hurlg taste like.",
    "Bone says: Shut it, unjort! What I'm trying to say here, is that " +
      "rats triggers my gahad.",
    "Janith says: Why do you orks always have to get so angry.",
    "The wideling Janith goes on teasing Bone.",
  });

  i = this_player()->query_property("wilhelm_message");
  if(sizeof(chat_message) >= i ) {
    write(chat_message[i-1] + "\n");
    i++;
    this_player()->add_property("wilhelm_message", i);
    call_out("chat", 2);
  }
  else
    this_player()->add_property("wilhelm_listen_ork");
} // Chat

buy_ale() {
  object product;
  if (!present("barkeeper", this_object())) {
    return "It seems as if the barkeeper isn't here.\n";
  }
  if (number_of_ale < 1) {
    return line_break("I'm sorry, we are all out!", "Xendri says: ", 78);
  }
  if (this_player() -> query_money() < 50) {
    return line_break("The dwarf ale costs 50 gold coins, and you look as " +
           "if you can't afford it.",);
  }
  number_of_ale = number_of_ale - 1;
  this_player() -> add_money(-50);
  product = clone_object("/players/wilhelm/area/siridfaath/obj/dwarf_ale");
  errormessage = transfer(product, this_player());
  if (errormessage == 1) {
    transfer(product, this_object());
    return line_break("The barkeeper fills up a mug of dwarf ale leaves "+
	"it on the bar. You pay 50 coins for it.");
  }
  return line_break("The barkeeper fills up a mug of dwarf ale and gives "+
  "it to you. \nYou pay 50 coins for it.");
}

check_drinks() {
  object ob;
  
  foreach (ob, deep_inventory(this_player())) 
    if (ob -> id("wilhelm_drink")) {
      if (this_player() -> query_npc()) {
	transfer(ob,"room/void");
	destruct(ob);
      } else {
	return "You are not allowed to leave with drinks!";
      }
	}  
	if(this_player()->query_property("wilhelm_tavern_sit")) {
    notify_fail("You need to stand up, before you can leave the tavern.\n");
    return 1;
	}
}

amber()
{
write("Xendri says: I'm sorry, we are all out. \n");
return 1;
}