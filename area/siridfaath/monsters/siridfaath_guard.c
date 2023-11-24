#include "../../macros.h"

//inherit "/std/state_monster";
inherit MONSTER;

#define WSAY(X) tell_room(environment(), line_break(X, "Guard says: ", 78))
#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;

  set_short("A troll guard");
  set_long("This giant of a troll is towering over you, at least nine feet "+
  "tall. His long brown hair is standing out in all directions, but his beard "+
  "is nicely braided. In his forehead two horns is twisting out in different "+
  "directions. He is wearing a large leather armour and has firm grip on a "+
  "sword that is hanging on his side. As soon as you entered the village he "+
  "has been watching your every move.");

  set_name("guard");
  add_alias("kern");
  add_alias("troll");
  set_race("troll");
  set_gender(1);
  set_level(15);
  add_property ("no_die_message");
  set_al(150);
  set_state("init");
  add_soul();
  start_walking(45);
  
  // add_hook("die_hook", this_object());
  // add_hook("kill_hook", this_object());
  
  add_object("/players/wilhelm/area/siridfaath/armour/hardened_leather");
  add_object("/players/wilhelm/area/siridfaath/weapons/troll_sword");
  
  command("wield sword");
  command("wear armour");

  add_response("ALL", "%1 smiles %2 at you","!watch %L1");
  add_response("ALL","SAY(%1,%2)","$said(%1,%2)");
  add_response("init","ARRIVE(%1)","@start_attack(%1)");
}
said (who, word) {
  if (sscanf(lower_case(word),"%*shelp%*s") == 2) {
    WSAY("I'm not here to help you, go bug someone else.");
    return 1;
  }
}


// die_hook(data, who) {
//   LOGGER -> log("kills", "killed Guard", data[0]);
// }
// kill_hook(data, who) {
//   LOGGER -> log("deaths", "killed by Guard", data[0]);
// }

start_attack(who) {
  object w;

  if (!stringp(who))
    return;
  w = present(who, environment(this_object()));
  if (objectp(w) && this_player()-> query_property("wilhelm_call_guards") ) {
    tell_room(environment(this_object()),"Someone called the guards on "+
	      capitalize(who)+".\n", ({w}));
    tell_object(w,"Someone called the guards on you!\n");
	attack_object(w);
  }
} 

