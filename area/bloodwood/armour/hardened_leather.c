// -- Hardened Leather armour -----------------------------------------------

inherit "/std/simple_armour";

reset(arg)
{
  ::reset(arg);
  if (arg) return;

  // -- Descriptions -------------------------------------------------------

  set_short("hardened leather armour");
  set_long("This hardened leather armour has been boiled to be made harder "+
    "than normal leather.Infused with some kind of magic to keep it from "+
	"pulling at the thorns on blood elves.");

  // -- Settings -----------------------------------------------------------

  set_name("hardened Leather");
  add_alias("armour");
  add_alias("leather armour");
  set_type("armour");
  set_class(9);
  set_value(500);
  set_weight(4);

  // -- Properties ---------------------------------------------------------

  add_property("leather");
  add_property("colour", "brown");

  // -- Items --------------------------------------------------------------

}

