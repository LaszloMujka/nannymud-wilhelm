#define NAME "wilhelm"
#define AREA "players/wilhelm/area/bloodwood/rooms"
#define HOME "players/wilhelm/area/"
#define DIVIDER sprintf("%75'=='s","") + "\n"
inherit "/std/room";

void reset(int arg) 
{
  ::reset(arg);
  
  object o;
  o = load_object("/players/wilhelm/area/xplogger/sign.c");
  if (!environment(o))
    move_object(o, this_object());
  
    if (arg) 
    return;
    
// -- Properties ---------------------------------------------------------
    
  add_light(1);
  add_exit("west", "/players/wilhelm/area/siridfaath/rooms/siridfaath_circus");
  add_exit("examples", "/examples/room/room1", 0, "@block_mortal()");
  add_exit("test", "/players/wilhelm/tests/start", 0, "@block_mortal()");
  add_exit("xpl", "/players/wilhelm/area/xplogger/xplogger_control_room", 0, "@block_mortal()");
  
  add_property("no_teleport");
  add_property("indoors");
  

// -- Description and settings -------------------------------------------

    set_short(capitalize(NAME) + "'s workroom");
    set_long("You are standing inside " + capitalize(NAME) + "'s workroom. " +
	     "It appears to be an abandoned circus tent. A map hangs on wall. ");

	add_item(({ "map" }), "A big map of the area. Try 'study map'");
	//add_item("plaque", "Read plaque ?");
	
// -- Objects ------------------------------------------------------------

    //add_object(load_object("/players/wilhelm/simple_logger"));
	//add_object("killerlist");
	//add_object("/players/wilhelm/area/siridfaath/obj/puzzlelist");
// -- Commands ------------------------------------------------------------
 
 	add_item_cmd("study", "map", "@inarea()");
    
}

block_mortal()
{
  if (this_player() -> is_mortal())
    return "A strange force prevents you from going there.";
} // check_wiz


inarea() 
{
   object *arr, player;
   string guild;
   
   arr = filter_array(users(), "local_only", this_object(), HOME + "%*s");
   /*
   if (!sizeof(arr)) 
      {
      write("The area is empty at the moment.\n");
      return 1;
   }
   */
   //else 
      {
      write("The following people are in the area:\n");
      write(DIVIDER);
      write(sprintf("  %-18s%-37s%-10s","Name","Location","Guild")+
         "\n");
      write(DIVIDER);
      
      foreach (player, arr) 
      {
         guild = player->getenv("GUILD");
         if (!guild) {
            guild = "None";
            }
         if (player->query_level() > 19) {
            guild = "Wizard";
            }
         guild = capitalize(guild);
         write(sprintf("  %-18s%-37s%-10s",
               capitalize(player->query_real_name()),
               replace(file_name(environment(player)),HOME,"~/"),
               guild)+"\n");
      }
   }
   
   write("\n");
   return 1;
}

int local_only(mixed player, string match) 
{
   if (!objectp(player)) return 0;
   
   if (sscanf(file_name(environment(player)),match))
      return 1;
}

