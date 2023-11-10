// -- Hardened Leather armour -----------------------------------------------

inherit "/std/simple_armour";

reset(arg)
{
  ::reset(arg);
  if (arg) return;

  // -- Descriptions -------------------------------------------------------

  set_short("hardened leather armour");
  set_long("This hardened leather armour has been boiled to be made harder "+
    "than normal leather.");

  // -- Settings -----------------------------------------------------------

  set_name("leather armour");
  add_alias("armour");
  set_type("armour");
  set_class(10);
  set_value(300);
  set_weight(5);

  // -- Properties ---------------------------------------------------------

  add_property("leather");
  add_property("colour", "brown");

  // -- Items --------------------------------------------------------------

}

