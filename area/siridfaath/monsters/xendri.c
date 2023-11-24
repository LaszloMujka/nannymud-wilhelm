/* Xendri is the barkeeper in the Amberglass */

// -- This line is 78 characters long ----------------------------------------

#include "../../macros.h"
inherit MONSTER;

#define XSAY(X) tell_room(environment(), line_break(X, "Xendri says: ", 78))

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;

// -- Descriptions ----------------------------------------------------------

  set_short("Xendri the barkeeper");
  set_long("Standing behind the bar, the short but beautiful dwarf smiles at "+
  "you, when she notices you are looking her way. Her blond hair is long and "+
  "curly and she is wearing a bright red dress.");


// -- Settings --------------------------------------------------------------

  set_name("xendri");
  add_alias("barkeeper");
  set_race("dwarf");
  set_gender(2);
  set_level(12);
  set_al(150);
  set_state("init");
  add_soul();

  add_response("ALL", "%1 smiles %2 at you","!smile %L1");
  add_response("ALL","SAY(%1,%2)","$said(%1,%2)");
  

  add_item( ({ "hair","curly hair","blond hair" }), 
    "Xendri got long and beautiful hair. The curly hair reaches down to her "+
    "shoulders.");
  
  add_item( ({ "dress","red dress" }), 
    "The bright red dress, sits tightly around her bosom and flows out from "+
    "her waist and down.");
  add_item("bosom", "@make_bosom()");
}

make_bosom()
{
"/std/msg"->msg("\bPRON foolishly stare\b$ at Xendris bosom.\n");
return "They are huge.\n";
}
// -- Responses -------------------------------------------------------------


said (who, word) {
  if (sscanf(lower_case(word),"%*shelp%*s") == 2) {
    XSAY("What you need help with stranger? Try some ale, that helps for me. ");
    return 1;
  }
  if (sscanf(lower_case(word),"%*sale%*s") == 2) {
    XSAY("What kind do you want?");
    "/std/msg"->msg("Xendri points on the sign behind her.\n");
    return 1;
  }
    if (sscanf(lower_case(word),"%*samber%*s") == 2) {
    XSAY("My finest ale, I brew it myself. Only fit for the finest "+
    "of adventurers. To bad I'm all out!");
    return 1;
  }
      if (sscanf(lower_case(word),"%*samberglass%*s") == 2) {
    XSAY("I named the tavern after my finest ale, brewed right here in "+
    "Siridfaath.");
    return 1;
  }
}
