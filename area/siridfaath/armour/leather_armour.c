// -- Leather armour -----------------------------------------------

inherit "/std/simple_armour";

reset(arg)
{
  ::reset(arg);
  if (arg) return;

  // -- Descriptions -------------------------------------------------------

  set_short("leather armour");
  set_long("Armor made of several layers of normal leather.");

  // -- Settings -----------------------------------------------------------

  set_name("leather");
  add_alias("armour");
  add_alias("leather armour");
  set_type("armour");
  set_class(5);
  set_value(150);
  set_weight(3);

  // -- Properties ---------------------------------------------------------

  add_property("leather");
  add_property("colour", "brown");

  // -- Items --------------------------------------------------------------

}

