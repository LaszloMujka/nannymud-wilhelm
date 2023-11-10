// -- This line is 78 characters long ----------------------------------------

inherit "/std/simple_weapon";

reset(arg)
{
  ::reset(arg);
  if (arg) return;

  // -- Descriptions -------------------------------------------------------

  set_short("A troll sword");
  set_long("Created specifically for trolls, the troll sword has a blade almost "+
    "four feet long and is balanced for one-handed use by those with "+ 
    "exptional strength. ");

  // -- Settings -----------------------------------------------------------

  set_name("troll sword");
  add_alias("sword");
  set_type("slash");
  set_class(13);
  set_value(325);
  set_weight(2);

  // -- Properties ---------------------------------------------------------

  add_property("steel");
  add_property("colour", "grey");

  // -- Items --------------------------------------------------------------

}

