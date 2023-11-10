/* Example of an armour with extra effects.
 *
 */
inherit "/std/simple_armour";


reset(arg) {
  ::reset(arg); // Needed to gte temp-properties etc. to work.
  if (!arg) {
    set_type("ring");
    set_class(3);
    set_weight(1);
    set_value(250);
    set_name("ring");
    set_short("A ring of thorns");
    set_long("It is a small elegant ring made out of small twisted together twigs, "+
	"with sharp thorns. It seems to pulsate with pure light, brightening up the room.");

	add_light(1);
    add_property("wood");
    add_property("__remote", this_object());
  }
} // reset


remote_do_wear() {
  this_player()->add_hp(-2);	
  write("The sharp thorns on the ring dig into your finger as you put it on.\n");
} // remote_do_wear


// Limits on whom can use it.
remote_prevent_wear() {
  if (this_player()->query_int() < 10) {
    write("The power of the ring is to strong for you to handle.\n");
    return 1;
  }
  return 0; // The same as not returning anything.
} // remote_prevent_wear
