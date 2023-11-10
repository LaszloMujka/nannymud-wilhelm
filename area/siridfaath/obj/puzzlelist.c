// -- This line is 78 characters long ----------------------------------------
inherit "/std/stationary";

#define FD "/obj/daemon/fingerd"

mapping log_data;
mapping puzzlenames;
int reset_count;

reset(arg)
{
  ::reset(arg);

  puzzlenames = ([]);

  restore_object("/players/wilhelm/simple_logger");

  if (arg) return;
  set_name("gold plaque");
  add_alias("plaque");
  add_alias("shiny bronze plaque");
  add_alias("list");

  set_short("a gold plaque");
  set_long("This plaque lists all the most dangerous murderers on " +
           "Alliance Island at the moment. Due to worldwide Nanny policy, " +
           "killing the inhabitants of this island is not really illegal " +
           "according to the law, so the police force just use this " +
           "list of names for their own sake, to know who they should " +
           "stay away from if they want to survive their shift. You " +
           "could probably read it.");

  add_property("bronze");
  add_property("brazen");

  add_command("read %s", "@read_plaque()");

} // reset

read_plaque(tmp, str) {
  mixed *puzzlearray;
  string *namearray;
  int i;
  int j;
  int s;
  int spacecount;
  int arraycount;
  int doublecheck;
  int puzzlearraycount;

  puzzlenames = ([]);

  if (!str) {
    notify_fail("Read what?\n");
    return;
  }
  if (str != "plaque" && str != "gold plaque" && str != "list") {
    notify_fail("Read plaque, perhaps?");
    return;
  }

  namearray = ({});

  puzzlearray = log_data["puzzle"];
  puzzlearraycount = sizeof(puzzlearray);

  for (i=0; i<puzzlearraycount; i++) {
    if (puzzlenames[puzzlearray[i][2]]) {
      puzzlenames[puzzlearray[i][2]]++;
      doublecheck++;
    }
    else {
      puzzlenames[puzzlearray[i][2]] = 1;
      namearray = namearray + ({puzzlearray[i][2]});
      arraycount++;
    }
  }

  namearray = sort_array(namearray, "sort_puzzle_array", this_object());

  if (!arraycount) {
    return "The list is empty.";
  }


  write("+-------------------------+\n");
  write("|   T O P   P U Z Z L E   |\n");
  write("+-------------------------+\n");

j = 0;

  for (i = 0; i < arraycount; i++) {
    if (FD -> playerp(namearray[i]) && !(FD -> wizardp(namearray[i]))
        && !(FD -> get_player_stats(namearray[i])[21])) {
      write("| ");
      write(capitalize(namearray[i]));

      spacecount = 16 - strlen(namearray[i]);
      if (puzzlenames[namearray[i]] > 9) spacecount--;
      if (puzzlenames[namearray[i]] > 99) spacecount--;

      for (s = 0; s < spacecount; s++) {
        write(" ");
      }
      write(puzzlenames[namearray[i]]);
      write(" puzzle");

      if (puzzlenames[namearray[i]] > 1)
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

sort_puzzle_array(a, b) {
  return puzzlenames[a] < puzzlenames[b];
} // sort_puzzle_array
