inherit "/std/simple_weapon";

reset(arg)
{
  ::reset(arg);
  if (arg) return;

  set_short("A sword");
  set_long("This is a sharp sword that belonged to the t'skrang Patrochian. " +
		    "On the shaft there is carved a fish, showing that the sword " +
		    "belonged to the House of T'kambras.");
  set_name("sword");
  set_type("slash");
  set_class(10);
  set_value(99);
  set_weight(2);
  add_property("steel");

} 