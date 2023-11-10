inherit "/std/items/torch";

void reset(int arg) {
  ::reset(arg);
  if (arg) {
    return;
  }
  set_name("root");
  set_short("@switch_short()");
  set_long("@switch_long()");
  set_value(0);
  set_weight(1);
  add_property("wood");
  add_property("colour", "brown");
  
}

switch_long() {
  if (is_lit)
    return "The "+query_name()+" is lit.\n";
  if (query_wet())
    return "The "+query_name()+" is wet.\n";
  return "It's a long "+query_name()+". You could use it as a torch.\n";
}

switch_short() {
  if (is_lit)
    return "a lit "+query_name();
  if (query_wet())
    return "a wet "+query_name();
  return "a "+query_name();
}