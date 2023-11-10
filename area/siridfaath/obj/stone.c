inherit "/std/basic_thing";

void reset(int arg) {
  ::reset(arg);
  if (arg) {
    return;
  }
  set_name("stone");
  set_short("a stone");
  set_value(0);
  set_weight(1);
  add_alias(({"granite","granite stone"}));
  add_property("rock");
  add_property("colour", "white");
  set_long("A rounded granite stone, about half the size of your fist.");
}
