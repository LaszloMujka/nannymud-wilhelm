/* Scintillant a huge spider */

#include "../../macros.h"
inherit MONSTER;

//#define LOGGER load_object("/players/wilhelm/simple_logger")

void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;

  set_short("a big spider");
  set_long("This huge spider is about six feet in length, the big legs "+
    "looks like sharp weapons, and his body is crystal clear so you can "+
    "clearly see what it had for dinner.");

  set_name("spider");
  add_alias("spider");
  set_race("spider");
  set_gender(0);
  set_level(12);
  set_al(-50);
  set_aggressive(10);


  
  add_attack("The spider's sharp crystal legs burrow into your body!\n", 10, 0, 1);
  
  add_item( ({ "body" }), 
  "The spider seems to be made of sharp crystal that lights up the dark "+
  "cave. You can see his intestines under the sharp glass.");

  add_object("@make_crystal()");
  
	}

  make_crystal() {
  object crystal;
  crystal = clone_object("std/basic_thing");
  crystal -> set_name("Large crystal");
  crystal -> add_alias("crystal");
  crystal -> set_weight(8);
  crystal -> set_value(300);
  crystal -> set_short("A large crystal");
  crystal -> set_long("A large crystal from the body of a spider.");
  return crystal;
  }
  
