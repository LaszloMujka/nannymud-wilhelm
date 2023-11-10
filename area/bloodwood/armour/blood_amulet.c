/* Example of an armour with extra effects.
 *
 */
inherit "/std/simple_armour";


reset(arg) {
  ::reset(arg); // Needed to gte temp-properties etc. to work.
  if (!arg) {
    set_type("amulet");
    set_class(3);
    set_weight(1);
    set_value(350);
    set_name("amulet");
    set_short("A blood amulet");
    set_long("A powerful magical amulet imbued with blood magic. It feels icy cold in "+
	"your hands.");

    
    add_property("__remote", this_object());
  }
} // reset



// Limits on whom can use it.
remote_prevent_wear() {
  if (this_player()->query_int() < 12) {
    write("The power of the amulet is to strong for you to handle.\n");
    return 1;
  }
  return 0; 
} 
