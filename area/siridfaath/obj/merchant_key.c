// -- This line is 78 characters long ----------------------------------------
inherit "/std/basic_thing";

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("golden key");
  add_alias("gold key");
  add_alias("key");
  set_short("a small, golden key");
  set_long("It's a small golden key, it probably belongs to the merchant.");
  set_weight(1);
  set_value(50);
  add_alias("wilhelm_mkey");
  add_property("code", "wilhelm_merchant");
  add_property("gold");
  add_property("colour", "golden");
  add_property("special_item");
} // reset

