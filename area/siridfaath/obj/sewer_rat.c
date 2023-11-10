// -- This line is 78 characters long ----------------------------------------
inherit "/std/basic_thing";

reset(arg)
{
  ::reset(arg);
  if (arg) return;
  set_name("dead rat");
  set_short("A dead stinking rat");
  set_long("The remains of a huge rat. It's decayed and have an awful smell. "+
  "Why would you bring this with you?.");
  set_weight(1);
  set_value(0);
  add_alias("rat");
  add_alias("wilhelm_rat");
  add_property("colour", "grey");
  add_property("special_item");
  add_property("__extra_look", "@smelly_rat()");
  add_property("fragile", "You drop the rat corpse./n"+
  "A cat jumps in from nowhere and snatches the foul rat remains.");
  
} // reset

smelly_rat()
{
  object env;

  env = environment(this_object());
  if (!env || !env -> query_living()) return 0;

  return (env -> query_pronoun() +
          "is carrying a dead rat. What an awful smell!"); 
} //smelly rat
