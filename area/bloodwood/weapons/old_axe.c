// -- This line is 78 characters long ----------------------------------------
inherit "/std/simple_weapon";

reset(arg)
{
  ::reset(arg);
  if (arg) return;

  set_short("old lumber axe");
  set_long("This is an old rusty lumber axe. Not much use as a weapon, but "+
  "it might be able to chop something with it.");
  set_name("axe");
  set_type("chop");
  set_class(6);
  set_value(40);
  set_weight(2);
  add_property("wood");

} 

