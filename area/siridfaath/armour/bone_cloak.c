// -- This line is 78 characters long ----------------------------------------

inherit "/std/simple_armour";

reset(arg)
{
  ::reset(arg);
  if (arg) return;

  // -- Descriptions -------------------------------------------------------

  set_short("a dark green cloak");
  set_long("A thick dark green cloak. Maybe not much for armour, but good "+
  "for keeping you warm.");

  // -- Settings -----------------------------------------------------------

  set_name("green cloak");
  add_alias("cloak");
  set_type("cloak");
  set_class(2);
  set_value(200);
  set_weight(2);

  // -- Properties ---------------------------------------------------------

  add_property("wool");
  add_property("colour", "green");


} // reset

