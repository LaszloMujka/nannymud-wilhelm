// A small note with informaation about my area

// -- This line is 78 characters long ----------------------------------------

inherit "std/basic_thing";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    
    set_name("paper");
    add_alias(({"note","small paper"}));
    set_weight(1);
    add_property("paper");
    add_property("fragile", "When the old paper lands, it crumbles to dust.");
    set_short("A small piece of paper");
    set_long("The old note seems to be ripped out of a book.");
  
    add_command("read %s", "@cmd_read()");
  }
} 





cmd_read(foo, str) {
  if (!id(str)) {
    notify_fail("Read what?\n");
    return 0;
  } 
 
  write("  +-------------------------------------------+  \n" +
        "  | Welcome to Wilhelm's realm!               |  \n" +
        "  |                                           |  \n" +
        "  |You deserve a free pie for finding this    |  \n" +
        "  |place. But hey your fat, so take this note |  \n" +
        "  |instead...                                 |  \n" +
		"  |                                           |  \n" +
        "  +-------^^^^^^-----^^^^^^--^^^^^^-----------+  \n");
  return 1;
}
