inherit "/std/room";

reset(arg) {
	::reset(arg);
	if (arg) return

	add_property("no_teleport");
	add_property("indoors");
	add_light(1);
	add_exit("wr", "/players/wilhelm/workroom", 0, "check_wiz");
	set_short("XP logger control room");
	set_long("Log room for wilhelm's area");

	add_object("/players/wilhelm/area/xplogger/report.c");


}

check_wiz() {
 if (this_player()->query_level()<20) {
  return notify_fail("A strange force prevents you from going there.\n");
 }
 write("You use your wizard power and take a huge step through thin air.\n");
}
