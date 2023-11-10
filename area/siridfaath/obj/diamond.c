inherit "/std/basic_thing";

void reset(int arg) {
  ::reset(arg);
  if (arg) {
    return;
  }
  set_name("diamond");
  set_short("a diamond");
  set_value(400);
  set_weight(1);
  add_alias(({"gem","jewel"}));
  add_property("jewel");
  add_property("diamond");
  add_property("colour","clear");
  set_long("A crystal clear sparkling diamond.");
}
