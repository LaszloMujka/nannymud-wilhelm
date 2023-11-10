inherit "std/simple_drink";
// Used apple_cider.c and from examples

reset(arg)
{
  if(arg)  return;
  set_name("ale");
  add_alias("dwarf ale");
  add_alias("wilhelm_drink");
  set_short("a mug of dwarf ale");
  set_long("A mug of dwarf ale. It has a fruity smell.\n");;
   /* The drink message is passed to /std/msg.
   * Look at the doc for that one to see the details on how the
   * message is built.
   */
  set_drink_msg("\bPRON drink\b$ the dwarf ale in on big gulp.\n");
  set_strength(10);
  set_heal(10); /* Must not exceed the strength! */
} // reset

