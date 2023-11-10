inherit "/std/basic_thing";

void reset(int arg) {
  ::reset(arg);
  if (arg) {
    return;
  }
  set_name("doll");
  set_short("a doll");
  set_value(5);
  set_weight(1);
  add_alias(({"granite","granite stone"}));
  add_property("wool");
  add_property("colour", "brown");
  set_long("A small worn out, wool doll. Mostly used by children to play with.");

  add_item_cmd("play","doll","@play_doll()");
 
}


play_doll() {
   if (this_player()->query_level() > 9)  
      return line_break("You are to old to play with dolls.\n");      
	else 
	  "std/msg"->msg("\bPRON play\b$ with a small doll, how childish.\n");
	return 1;
}