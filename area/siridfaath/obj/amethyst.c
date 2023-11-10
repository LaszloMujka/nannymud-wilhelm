inherit "/std/basic_thing";

void reset(int arg) {
  ::reset(arg);
  if (arg) {
    return;
  }
  set_name("amethyst");
  set_short("an amethyst");
  set_value(100);
  set_weight(1);
  add_alias(({"gem","jewel"}));
  add_property("amethyst");
  add_property("jewel");
  add_property("colour","purple");
  set_long("A purple colored amethyst.");
}
