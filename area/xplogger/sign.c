#include "/players/wilhelm/area/macros.h"

inherit "/std/stationary";

reset(arg){
	::reset(arg);
	if (arg)
		return;

	if (_isclone(this_object()))
		destruct(this_object());

	set_name("plaque");
	set_short("bronze plaque");
	set_long("@my_long()");
	add_property("non-gettable");
}

my_long(){
  return "\n"+
  	"+-----------------------------+\n"+
  	"|    T O P   K I L L E R S    |\n"+
  	"+-----------------------------+\n"+
	("/players/wilhelm/area/xplogger/report.c" -> player_report())+	
	"+-----------------------------+\n";

}
