// -- This line is 78 characters long ----------------------------------------
inherit "/std/box";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("small chest");
  add_alias("chest");
  add_alias("wooden chest");
  add_alias("wilhelm_merchant_chest");
  set_short("a wooden chest");
  set_long("It's a small wooden chest, bolted to the wagon floor. ");
  set_weight(50);
  add_property("non-gettable", "It's bolted to the wagon.\n");
  add_property("wooden");
  add_property("colour", "brown");
  set_lock("wilhelm_merchant", "small, golden");
  
  add_object("/players/wilhelm/area/siridfaath/obj/diamond");
  add_object("/players/wilhelm/area/siridfaath/obj/amethyst");
  
} // reset
