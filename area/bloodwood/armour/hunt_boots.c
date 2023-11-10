// -- Hardened Leather armour -----------------------------------------------

inherit "/std/simple_armour";

reset(arg)
{
  ::reset(arg);
  if (arg) return;

  // -- Descriptions -------------------------------------------------------

  set_short("huntsman's boots");
  set_long("Leather boots are designed for the huntsman who spends "+
  "extended periods of time in the forest. Produced to repel water and "+
  "keep the wearer's feet dry.");

  // -- Settings -----------------------------------------------------------

  set_name("Huntsman's Boots");
  add_alias("boots");
  add_alias("leather boots");
  set_type("boot");
  set_class(3);
  set_value(200);
  set_weight(3);

  // -- Properties ---------------------------------------------------------

  add_property("leather");
  add_property("colour", "brown");

  // -- Items --------------------------------------------------------------

}

