// -- This line is 78 characters long ----------------------------------------
inherit "/std/simple_weapon";

reset(arg)
{
  ::reset(arg);
  if (arg) return;

  set_short("a thorn sword");
  set_long("This sword is crafted from wood. It's incredibly light and "+
  "flexible. The hilt is woven of living thorn vines that flower with small "+
  "rose blossoms. ");
  set_name("sword");
  set_type("slash");
  set_class(14);
  set_value(600);
  set_weight(2);
  add_property("wood");

} 

