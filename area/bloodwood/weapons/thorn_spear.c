// -- This line is 78 characters long ----------------------------------------
inherit "/std/simple_weapon";

reset(arg)
{
  ::reset(arg);
  if (arg) return;

  set_short("a thorn men spear");
  set_long("This is a spear wielded by the thorn men that guard the "+
  "Blood Wood. The spear sprout thorns up and down it length.");
  set_name("spear");
  set_type("pierce");
  set_class(10);
  set_value(200);
  set_weight(2);
  add_property("wood");

} 

