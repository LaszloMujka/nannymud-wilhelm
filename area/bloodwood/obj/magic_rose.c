inherit "/std/basic_thing";

void reset(int arg) {
  ::reset(arg);
  if (arg) {
    return;
  }
  set_name("rose");
  set_short("a rose");
  set_value(0);
  //set_weight(0);
  add_property("flower");
  add_property("colour", "red");
  add_property("quest_item");
  add_alias("wilhelm_bloodwood_rose");
  add_property("fragile", "When the rose lands on the ground, it crumbles into dust.");
  set_long("An elegant spiky rose. It feels like it's pulsating with magic.");
}
