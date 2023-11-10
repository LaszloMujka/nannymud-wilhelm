// -- Padded Leather armour -----------------------------------------------

inherit "/std/simple_armour";

reset(arg)
{
  ::reset(arg);
  if (arg) return;

  // -- Descriptions -------------------------------------------------------

  set_short("padded leather armour");
  set_long("Leather armor with felt or padding sewn in between the layers.");

  // -- Settings -----------------------------------------------------------

  set_name("padded leather");
  add_alias("armour");
  add_alias("leather armour");
  set_type("armour");
  set_class(8);
  set_value(200);
  set_weight(3);

  // -- Properties ---------------------------------------------------------

  add_property("leather");
  add_property("colour", "brown");

  // -- Items --------------------------------------------------------------

}

