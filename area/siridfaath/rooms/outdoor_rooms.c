// -- This line is 78 characters long ----------------------------------------

inherit "/std/room";
#define TD "/obj/util/timed"

reset(arg)
{
  ::reset(arg);
  if (arg) return;
  add_light(1);
  add_property("outdoors");
  add_item("sky", "@make_sky()");
  add_item(({ "star", "stars" }), "@make_stars()");
  add_item(({ "cloud", "clouds" }),"@make_cloud()");
  add_item("sun", "@make_sun()");
  add_item("moon", "@make_moon()");
}

make_sky() {
  if (TD -> query_daytime()) {
  return line_break("The sky is blue and filled with large clouds. ");
  }
    
  return line_break("Stars light up the night sky. ");
}

make_stars() {
  if (TD -> query_daytime()) {
  return line_break("It’s the middle of the day, no stars can be seen.");
  }
  
  return line_break("The stars shine brightly in the night sky above you. ");
}

make_sun() {

  if (TD -> query_daytime()) {
  return line_break("High up in the sky between the clouds. ");
  }

  return line_break("It is late at night.");
}

make_cloud() {
  if (TD -> query_daytime()) {
  return line_break("Clouds of all shapes and sizes fill up the clear blue "+
  "sky above you.");
  }
  
  return line_break("The sky is filled with clouds that drift by in the night sky.");
}

make_moon() {
  if (TD -> query_daytime()) {
  return line_break("It's daytime. ");
  }
    
  return line_break("The moon helps light up the night sky. ");
}