// -- Hardened Leather armour -----------------------------------------------

inherit "/std/simple_armour";

reset(arg)
{
  ::reset(arg);
  if (arg) return;

  // -- Descriptions -------------------------------------------------------

  set_short("gardening gloves");
  set_long("This thin gloves will not give much protection in combat but "+
  "seems perfectly woven for protection against sharp thorns.");

  // -- Settings -----------------------------------------------------------

  set_name("pair of gloves");
  add_alias("gardening gloves");
  add_alias("gloves");
  add_alias("wilhelm_gardener_gloves");
  set_type("glove");
  set_class(1);
  set_value(50);
  set_weight(1);

  // -- Properties ---------------------------------------------------------

  add_property("leather");
  add_property("colour", "brown");
  add_property("special_item");

  // -- Items --------------------------------------------------------------

}

