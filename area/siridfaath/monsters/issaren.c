/*
*Issaren is a dwarf in the library of siridfaath.
*He will have information about my area and about the rpg Earthdawn.
*I will add more responses here as my area expand.
*
*If possible I would like to log says from the same room as this monster
*for ideas to what more responses I might add.
*
*/

// -- This line is 78 characters long ----------------------------------------
#include "../../macros.h"
inherit MONSTER;

#define HSAY(X) tell_room(environment(), line_break(X, "Issaren says: ", 78))

reset(arg)
{
  ::reset(arg);
  if (arg) return;
  
// -- Descriptions ----------------------------------------------------------

  set_short("Issaren the librarian");
  set_long("The old dwarf is sitting behind his desk reading from a book. "+
    "He has a large white beard and big reading glasses.");

// -- Settings --------------------------------------------------------------

  set_name("issaren");
  add_alias("librarian");
  add_alias("man");
  add_alias("elderly man");
  set_race("dwarf");
  set_gender(1);
  set_level(12);
  set_al(150);
  add_soul();
  set_chat_chance(1);


// -- Chats -----------------------------------------------------------------

  add_chat("Issaren pulls down a new book from one of the shelves and sits "+
    "down to read it, at his desk.");
  add_chat ("A villager walks in and delivers a book to Issaren, then walks "+
    "out to the streets again.");
  add_chat ("Issaren coughs loudly, after dusting of one of his books.");
  add_chat ("Issaren mumbles something you can't make out.");
  
  
// -- Responses -------------------------------------------------------------

  add_response("%1 smiles %2 at you","!smile %L1");
  add_response("SAY(%1,%2)","$said(%1,%2)");

} // reset

said (who, word) {
  if (sscanf(lower_case(word),"%*shelp%*s") == 2) {
    HSAY("I can help you with information, not much else.");
    return 1;
  }
    if (sscanf(lower_case(word),"%*slibrary%*s") == 2) {
    HSAY("The library here has become large over the year. Today it really "+
    "works more like a tourist information, with all the new people arriving.");
    return 1;
  }
  if (sscanf(lower_case(word),"%*sinformation%*s") == 2) {
    HSAY("What do you need information about? Please be a little more "+
    "specific.");
    return 1;
  }
  if (sscanf(lower_case(word),"%*ssiridfaath%*s") == 2) {
    HSAY("Yes, that's what this small village is called. It was founded by "+
    "members of a former adventuring group. It is located between the "+
    "Caucavic mountain ranges to the north and the Serpent River to the "+
    "south. It started as a small caravan stop between the route from Haven "+
    "to Throal, but today in also gets a lot of visitors from strange new "+
    "lands like you.");
    return 1;
  }
  
  if (sscanf(lower_case(word),"%*swindeling%*s") == 2) {
    HSAY("They sure can be annoying, let me see what I can find for you.");
    "/std/msg"->msg("Issaren finds a scroll on the shelf behind him and hands "+
    "it over to \bPRON.\n");
    write("+--------------------------------------------------------------+\n");
    write("| Windelings                                                   |\n");
    write("|                                                              |\n");
    write("| Windlings are a winged race of wilderness dwellers. They     |\n");
    write("| are fast, but their size means they are neither strong nor   |\n");
    write("| tough. They have a quick wit, street smarts, and are         |\n");
    write("| naturally charismatic. They are 18 inches in height and      |\n");
    write("| weigh 13 pounds. They live to be 170 years on average.       |\n");
    write("| They have a pair of double wings, like a dragonfly. Their    |\n");
    write("| skin color matches the brightest dominant color in their     |\n");
    write("| environment. It takes 2 to 3 months of habitation in a       |\n");
    write("| environment before their skin will change.                   |\n");
    write("|                                                              |\n");
    write("+--------------------------------------------------------------+\n");
    "/std/msg"->msg("After reading the scroll \bPRON hand\b$ it back to "+
    "Issaren.\n");
    return 1;
  } //Say windeling
  if (sscanf(lower_case(word),"%*stroll%*s") == 2) {
    HSAY("Let me see what I can find for you.");
    "/std/msg"->msg("Issaren finds a scroll on one of the shelves and hands "+
    "it over to \bPRON.\n");
    write("+--------------------------------------------------------------+\n");
    write("| Trolls                                                       |\n");
    write("|                                                              |\n");
    write("| Trolls are very tall humanoids, with a hardened skin and     |\n");
	write("| horns. Socially, they form clans to which they are fiercely  |\n");
	write("| loyal. Troll clans often raid one another, and a significant |\n");
	write("| subset of the troll race are crystal raiders, which command  |\n");
	write("| many of the airships of Barsaive. Other trolls, known as     |\n");
	write("| lowland trolls, have merged with mixed communities around    |\n");
	write("| Barsaive, although most retain the fierce cultural and       |\n");
	write("| personal pride of their less-civilized cousins.              |\n");
	write("|                                                              |\n");
    write("+--------------------------------------------------------------+\n");
    "/std/msg"->msg("After reading the scroll \bPRON hand\b$ it back to "+
    "Issaren.\n");
    return 1;
  } //Say troll
   if (sscanf(lower_case(word),"%*st'skrang%*s") == 2) {
    HSAY("Let me see what I can find for you.");
    "/std/msg"->msg("Issaren finds a scroll on one of the shelves and hands "+
    "it over to \bPRON.\n");
    write("+--------------------------------------------------------------+\n");
	write("| T'skrang                                                     |\n");
	write("| The t'skrang are lizard-like amphibian humanoids with long   |\n");
	write("| tails and a flair for dramatics. Many of them exhibit the    |\n");
	write("| behaviors and characteristics which are stereotypical to a   |\n");
	write("| 'swashbuckler'. T'skrang are often sailors, and many         |\n");
	write("| t'skrang families run ships up and down the rivers of        |\n");
	write("| Barsaive. t'skrang families run ships up and down the rivers |\n");
	write("| of Barsaive.                                                 |\n");
	write("|                                                              |\n");
    write("+--------------------------------------------------------------+\n");
    "/std/msg"->msg("After reading the scroll \bPRON hand\b$ it back to "+
    "Issaren.\n");
    return 1;
  } //Say t'skrang 
   if (sscanf(lower_case(word),"%*sobsidimen%*s") == 2) {
    HSAY("Let me see what I can find for you.");
    "/std/msg"->msg("Issaren finds a scroll on one of the shelves and hands "+
    "it over to \bPRON.\n");
    write("+--------------------------------------------------------------+\n");
	write("| Obsidimen                                                    |\n");
	write("|                                                              |\n");
	write("| Obsidimen are a race of large, rock-based humanoids. They    |\n");
	write("| stand over 7 feet tall and weigh over 900 pounds. Their      |\n");
	write("| primary connection is to their Liferock, which is a large    |\n");
	write("| formation of stone within four hours of their place of       |\n");
	write("| birth.formation of stone within four hours of their place    |\n");
	write("| of birth.                                                    |\n");
	write("|                                                              |\n");
	write("| Obsidimen can live around 500 years away from their          |\n");
	write("| Liferock, and their ultimate lifespan is unknown.            |\n");
	write("|                                                              |\n");
    write("+--------------------------------------------------------------+\n");
    "/std/msg"->msg("After reading the scroll \bPRON hand\b$ it back to "+
    "Issaren.\n");
    return 1;
  } //Say t'skrang  
  if (sscanf(lower_case(word),"%*sork%*s") == 2) {
    HSAY("Be careful not to anger them.");
    "/std/msg"->msg("Issaren finds a scroll on one of the shelves and hands "+
    "it over to \bPRON.\n");
    write("+--------------------------------------------------------------+\n");
    write("| Orks                                                         |\n");
    write("|                                                              |\n");
    write("| Orks are a race of nomads. They are powerful and tough.      |\n");
    write("| However, most races consider them barbaric and dangerous.    |\n");
    write("| They stand 6 feet 3 inches on average and weigh 225          |\n");
    write("| pounds. They live to about 40 years but ages greater than    |\n");
    write("| 60 are not unknown. Their skins are normally olive green,    |\n");
    write("| pinkish-white, beige, tan or ebony. Their greatest           |\n");
    write("| loyalty lies with their tribe.                               |\n");
    write("|                                                              |\n");
    write("| Unique by the ork is that different things can often         |\n");
    write("| trigger intense heartburn, that they call gahad.             |\n");
    write("|                                                              |\n");        
    write("+--------------------------------------------------------------+\n");
    "/std/msg"->msg("After reading the scroll \bPRON hand\b$ it back to "+
    "Issaren.\n");
    return 1;
  } //Say ork
    if (sscanf(lower_case(word),"%*sgahad%*s") == 2) {
    HSAY("Let me see what I can find for you.");
    "/std/msg"->msg("Issaren finds a scroll on one of the shelves and hands "+
    "it over to \bPRON.\n");
    write("+--------------------------------------------------------------+\n");
    write("| Gahad                                                        |\n");
    write("|                                                              |\n");
    write("| Gahad is a sensation similar to intense heartburn            |\n");
    write("| triggerd in orks by certain circumstances or situations.     |\n");
    write("| Each ork character experiences gahad in response to unique   |\n");
    write("| circumstances or stimuli.                                    |\n");
    write("|                                                              |\n");
    write("| According to orks, if they try to resist their gahad it      |\n");
    write("| feels like their brain starts to boil. It is said about      |\n");
    write("| orks that suddenly drops dead at forty has swallowed         |\n");
    write("| their gahad one time to many.                                |\n");
    write("|                                                              |\n");
    write("+--------------------------------------------------------------+\n");
    this_player()->add_property("wilhelm_ork_gahad");
    "/std/msg"->msg("After reading the scroll \bPRON hand\b$ it back to "+
    "Issaren.\n");
    return 1;
  } //Say gahad
      if ((sscanf(lower_case(word),"%*self%*s") == 2) || 
	     (sscanf(lower_case(word),"%*selves%*s") == 2)){
    HSAY("Let me see what I can find for you.");
    "/std/msg"->msg("Issaren finds a scroll on one of the shelves and hands "+
    "it over to \bPRON.\n");
    write("+--------------------------------------------------------------+\n");
    write("| Elves                                                        |\n");
    write("|                                                              |\n");
    write("| Elves grow to an average height of 6 feet 3 inches,          |\n");
    write("| and weigh an average 150 pounds. Elven facial features       |\n");
    write("| appear completely symmetrical, often flawless, and           |\n");
    write("| many of the other races of Barsaive find elves attractive.   |\n");
    write("|                                                              |\n");
    write("| Elven skin color varies wildly by tribe and region, but the  |\n");
    write("| fmost common are pure white, pink, tan, brown, and           |\n");
    write("| midnight black. Elves with skin of a pale green or           |\n");
    write("| iridescent, pearly color called cetharel exist, but remain   |\n");
    write("| rare.                                                        |\n");
	write("|                                                              |\n");
	write("| A subrace of elves exist called bloodelves.                  |\n");
	write("|                                                              |\n");
    write("+--------------------------------------------------------------+\n");
   
    "/std/msg"->msg("After reading the scroll \bPRON hand\b$ it back to "+
    "Issaren.\n");
    return 1;
  } //Say elf
        if ((sscanf(lower_case(word),"%*sbloodelf%*s") == 2) || 
	   (sscanf(lower_case(word),"%*sbloodelves%*s") == 2)){
    HSAY("Let me see what I can find for you.");
    "/std/msg"->msg("Issaren finds a scroll on one of the shelves and hands "+
    "it over to \bPRON.\n");
    write("+--------------------------------------------------------------+\n");
    write("| Bloodelves                                                   |\n");
    write("|                                                              |\n");
    write("| They were once normal elves, living in the Wyrm Wood forest. |\n");
    write("| A large kaer made from True wood around the forest to        |\n");
    write("| protect them through the  Scourge. However, the defenses of  |\n");
    write("| the kaer failed.										      |\n");
    write("|                                                              |\n");
    write("| By desperate means, the elf used a ritual, which came to be  |\n");
    write("| known as the Ritual of Thorns, to protect themselves from    |\n");
    write("| the Horrors that roamed the land.                            |\n");
    write("|                                                              |\n");
    write("| The Ritual altered the true pattern of Wyrm Wood and its     |\n");
	write("| residents, and it is now known as Blood Wood.                |\n");
	write("|                                                              |\n");
	write("| Outside of the Wood, elves that have undertaken the ritual   |\n");
	write("| are considered corrupted by most of the populace and are     |\n");
	write("| referred to as Blood Elves.                                  |\n");
	write("|                                                              |\n");
    write("+--------------------------------------------------------------+\n");
    
    "/std/msg"->msg("After reading the scroll \bPRON hand\b$ it back to "+
    "Issaren.\n");
    return 1;
  } //Say bloodelf
  
          if ((sscanf(lower_case(word),"%*sbloodwood%*s") == 2) || 
	   (sscanf(lower_case(word),"%*sblood wood%*s") == 2)){
    HSAY("Thats the forest to the west of here. "+
	"Let me see what I can find.");
    "/std/msg"->msg("Issaren finds a scroll on one of the shelves and hands "+
    "it over to \bPRON.\n");
    write("+--------------------------------------------------------------+\n");
    write("| Bloodwood                                                    |\n");
    write("|                                                              |\n");
    write("| The Blood Wood was once known as the Wyrm Wood, before       |\n");
    write("| the desperate acts undertaken by Queen Alachia and the       |\n");
    write("| magicians of the wood. The Ritual of the Thorns transformed  |\n");
    write("| the wood and the Blood Elves living there, permanently       |\n");
    write("| embedding painful thorns into their flesh. The Wood itself   |\n");
    write("| was transformed into a different kind of creature, feeding   |\n");
    write("| off the constant dripping blood from the thorns of the elves.|\n");
    write("|                                                              |\n");
    write("| While the magic of this process repelled the Horrors and kep |\n");
    write("| the Wood safe during the Scourge, it also corrupted the      |\n");
	write("| Wood’s heart, creating a magical cancer that was slowly      |\n");
	write("| preading and eating the land itself alive.                   |\n");		
	write("|                                                              |\n");
    write("+--------------------------------------------------------------+\n");
    
    "/std/msg"->msg("After reading the scroll \bPRON hand\b$ it back to "+
    "Issaren.\n");
    return 1;
  } //Say bloodwood
  
  
    if (sscanf(lower_case(word),"%*sbarsaive%*s") == 2) {
    HSAY("Let me see what I can find for you.");
    "/std/msg"->msg("Issaren finds a scroll on one of the shelves and hands "+
    "it over to \bPRON.\n");
    write("+--------------------------------------------------------------+\n");
    write("| Barsaive                                                     |\n");
    write("|                                                              |\n");
    write("| The Therans named this province Barsaive six hundred years   |\n");
    write("| ago, before the Scourge began.								  |\n");
    write("|															  |\n");
    write("| It's a huge land with many interesting locations.            |\n");
    write("|                                                              |\n");
    write("+--------------------------------------------------------------+\n");
    "/std/msg"->msg("After reading the scroll \bPRON hand\b$ it back to "+
    "Issaren.\n");
    return 1;
  } //Say barsaive
    if (sscanf(lower_case(word),"%*swilhelm%*s") == 2) {
    HSAY("Don't mention that name!");
    "/std/msg"->msg("Issaren throws a pie in \bposs face.\n");
    return 1;
  } // Say wilhelm 
}
