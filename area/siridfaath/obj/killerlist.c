// -- This line is 78 characters long ----------------------------------------
inherit "/std/stationary";

#define FD "/obj/daemon/fingerd"

mapping log_data;
mapping killernames;
int reset_count;

reset(arg)
{
  ::reset(arg);

  killernames = ([]);

  restore_object("/players/wilhelm/simple_logger");

  if (arg) return;
  set_name("plaque");
  add_alias("plaque");
  add_alias("list");

  set_short("a plaque");
  set_long("A plaque with a list of names on it.");

  add_command("read %s", "@read_plaque()");

} // reset

read_plaque(tmp, str) {
  mixed *killarray;
  string *namearray;
  int i;
  int j;
  int s;
  int spacecount;
  int arraycount;
  int doublecheck;
  int killarraycount;

  killernames = ([]);

  if (!str) {
    notify_fail("Read what?\n");
    return;
  }
  if (str != "plaque" && str != "list") {
    notify_fail("Read plaque, perhaps?");
    return;
  }

  namearray = ({});

  killarray = log_data["kills"];
  killarraycount = sizeof(killarray);

  for (i=0; i<killarraycount; i++) {
    if (killernames[killarray[i][2]]) {
      killernames[killarray[i][2]]++;
      doublecheck++;
    }
    else {
      killernames[killarray[i][2]] = 1;
      namearray = namearray + ({killarray[i][2]});
      arraycount++;
    }
  }

  namearray = sort_array(namearray, "sort_killer_array", this_object());

  if (!arraycount) {
    return "The list is empty.";
  }


  write("+-------------------------+\n");
  write("|  T O P   K I L L E R S  |\n");
  write("+-------------------------+\n");

j = 0;

  for (i = 0; i < arraycount; i++) {
    if (FD -> playerp(namearray[i]) && !(FD -> wizardp(namearray[i]))
        && !(FD -> get_player_stats(namearray[i])[21])) {
      write("| ");
      write(capitalize(namearray[i]));

      spacecount = 16 - strlen(namearray[i]);
      if (killernames[namearray[i]] > 9) spacecount--;
      if (killernames[namearray[i]] > 99) spacecount--;

      for (s = 0; s < spacecount; s++) {
        write(" ");
      }
      write(killernames[namearray[i]]);
      write(" kill");

      if (killernames[namearray[i]] > 1)
        write("s");
      else
        write(" ");

      write(" |\n");
      j++;
      if (j == 10) break;
    }
  }
  write("+-------------------------+\n");

  return 1;

} // read_plaque

sort_killer_array(a, b) {
  return killernames[a] < killernames[b];
} // sort_killer_array
