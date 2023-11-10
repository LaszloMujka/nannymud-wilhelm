// -- This line is 78 characters long ---------------------------------------

inherit "/std/simple_weapon";

reset(arg)
{
  ::reset(arg);
  if (arg) return;

  // -- Descriptions --------------------------------------------------------
  
  set_short("A crystal sword");
  set_long(" At a first glance this weapon looks like fragile glass, but a "+
  "further inspections shows how the blade ins made from crystal and bits of "+
  "elemental earth. The weapon glimmers as you swing it in the air. In the "+
  "right hands this is surely a deadly weapon..");
  
  // -- Settings ------------------------------------------------------------
  
  set_name("crystal sword");
  set_type("slash");
  set_class(17);
  add_alias("sword");
  set_value(850);
  set_weight(2);
  add_property("crystal");

} //reset

