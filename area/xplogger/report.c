#include <fingerd.h>
#include "/players/wilhelm/area/macros.h"

inherit "/std/stationary";

static  mixed	pd		= 0;
static  int	timestamp	= 0;
//static	int	rating_point 	= 1000;

reset(arg)
{
  ::reset(arg);
  if (arg)
    return;

  set_name("xp log reporter");
  add_alias("reporter");
  set_short("xp log reporter");
  set_long("Use it with 'log nr_of_records' (default is 30)");

  add_command("log %s", "@general_report()");
}

static void refresh()
{
  if (!pointerp(pd) || !sizeof(pd) || XP_LOGGER -> get_timestamp() > timestamp)
    {
      timestamp = time();
      pd = XP_LOGGER -> get_parsed_data();
    }
}

string general_report(int foo, string arg)
{
  int i, j;
  int s1, s2, s3, nr;
  string res;


  if (!arg)
    nr = 30;
  else
    {
      sscanf(arg, "%d", nr);
      if (!nr)
	nr = 30;
    }

  refresh();

  if (!pointerp(pd) || !sizeof(pd))
    return "No data.\n";

  s1 = 0; s2 = 0; s3 = 0;


  res = sprintf(" %2|s | %12|s | %5|s | %10|s | %10|s | %17|s \n",
		"No", "Who", "Kills", "Points", "Worth", "Last kill");

  res += "----+--------------+-------+------------+------------+-------------------\n";

  for (j = 0, i = (sizeof(pd) - 1); j < nr && i >= 0; i--)
    if (pointerp(pd[i]) && sizeof(pd[i]) == 5 && stringp(pd[i][0]))
      if (FINGERD -> playerp(pd[i][0]) && intp(pd[i][1]))
	{
	  j++;
	  res += sprintf(" %2d | %12|s | %5d | %10d | %10d | %17|s \n",
			 j, capitalize(pd[i][0]), pd[i][2], pd[i][3], pd[i][4],
			 ctime(pd[i][1])[8..9] + " " + ctime(pd[i][1])[4..6] + " " + ctime(pd[i][1])[11..15] + " " + ctime(pd[i][1])[20..24]);
	  s1 += pd[i][2];
	  s2 += pd[i][3] / 1000;
	  s3 += pd[i][4] / 1000;
	}

  res += "----+--------------+-------+------------+------------+-------------------\n";
  res += sprintf(" %2|s | %12|s | %5d | %9dK | %9dK | %17|s \n",
		 "--", "T O T A L", s1, s2, s3, "--");

  return res;
}

string player_report()
{
  int i, j, k, rating_point;
  string res;

  rating_point = -1;

  refresh();

  if (!pointerp(pd) || !sizeof(pd))
    return "There is nothing on the list.\n";

   res = sprintf("|                             |\n");

  //res += sprintf("------+--------------+%40'-'s\n", " ");

  for (j = 0, i = (sizeof(pd) - 1); j < 10 && i >= 0; i--)
    if (pointerp(pd[i]) && sizeof(pd[i]) == 5 && stringp(pd[i][0]))
      if (FINGERD -> playerp(pd[i][0]) && pd[i][0] != "wilhelmjr" && pd[i][0] != "wilhelmii" && pd[i][0] != "wilhelm"  && intp(pd[i][1]))
	{
	  j++;
	  res += sprintf("|%-15s  %5d kills ",capitalize(pd[i][0]), pd[i][2]);

	  // if (rating_point == -1)
	  //   rating_point = pd[i][3] / 36;

	  // for (k = 0; k * rating_point < pd[i][3]; k++)
	  //   {
	  //     if (k && !(k%40))
		// res += "\n      |              | ";
	  //     res += "o";
	  //   }
	   res += "|\n";
	}

  //res += sprintf("------+--------------+%40'-'s\n", " ");

  return res;
}
