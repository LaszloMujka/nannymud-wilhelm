/*A circus outside Siridfaath*/
//Mortal players will not have access to this room.
// -- This line is 78 characters long ----------------------------------------

inherit "/std/room";


void reset(int arg)
{
  ::reset(arg);
  if (arg)
    return;
    
// -- Properties -------------------------------------------------------------

  add_light(1);
  add_property("no_tree");
  add_property("inside");
  add_exit("out", "siridfaath_road2");
  add_exit("start", "area_entry");
  add_exit("cave", "siridfaath_cave1");

// -- Description and settings -----------------------------------------------

  set_short("circus tent");
  set_long("A large circus tent. A big map is hangs on one of the walls.");

// -- Items ------------------------------------------------------------------

  add_item(({ "map" }), "A big map of the area. Try 'study map'");
  
  add_object("/players/wilhelm/killerlist");
  add_object("/players/wilhelm/puzzlelist");
  add_object(load_object("/players/wilhelm/simple_logger"));
  
  add_item_cmd("study", "map", "@study_map()");
}


study_map() {
  int i;
  int something;
  object *cellestoff;

  if (!(this_player() -> is_wizard())) {
    return "You aren't powerful enough to study the fog.\n";
  }

  write("When you look into the fog, you see:\n\n");
  write("------------------------------------------------------------------" +
        "------------\n");

  cellestoff = add_item(load_object("/players/wilhelm/area/siridfaath/rooms/area_entry"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- area start -] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }

 cellestoff = all_inventory(load_object("/players/wilhelm/area/siridfaath/rooms/area_road1"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- road 1 -] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }

 cellestoff = all_inventory(load_object("/players/wilhelm/area/siridfaath/rooms/siridfaath_road1"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- outside siridfaath -] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }

 cellestoff = all_inventory(load_object("/players/wilhelm/area/siridfaath/rooms/siridfaath_road2"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- outside circus -] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }

cellestoff = all_inventory(load_object("/players/wilhelm/area/siridfaath/rooms/siridfaath1"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[ siridfaath slums ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }

cellestoff = all_inventory(load_object("/players/wilhelm/area/siridfaath/rooms/siridfaath2"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- siridfaath well -] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }

  cellestoff = all_inventory(load_object("/players/wilhelm/area/siridfaath/rooms/siridfaath3"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- outside library -] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }

  cellestoff =
           all_inventory(load_object("/players/wilhelm/area/siridfaath/rooms/siridfaath4"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- outside tavern -] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }

cellestoff = all_inventory(load_object("/players/wilhelm/area/siridfaath/rooms/siridfaath_alley"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- garbage dump -] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }

cellestoff = all_inventory(load_object("/players/wilhelm/area/siridfaath/rooms/siridfaath_wagon"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- wagon - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }

cellestoff = all_inventory(load_object("/players/wilhelm/area/siridfaath/rooms/siridfaath_dock"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- docks - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }

cellestoff = all_inventory(load_object("/players/wilhelm/area/siridfaath/rooms/siridfaath_tavern"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- amberglass - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }
cellestoff = all_inventory(load_object("/players/wilhelm/area/siridfaath/rooms/siridfaath_library"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- library  - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }

  cellestoff = all_inventory(load_object("/players/wilhelm/area/siridfaath/rooms/siridfaath_well"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- inside well - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }
  
cellestoff = all_inventory(load_object("/players/wilhelm/area/siridfaath/rooms/siridfaath_cave1"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- cave1 - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }

cellestoff = all_inventory(load_object("/players/wilhelm/area/siridfaath/rooms/siridfaath_cave2"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- cave2 - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }
  
  if (!something) {
    write("Nothing.\n");
  }
  write("------------------------------------------------------------------" +
        "------------\n");
  write("\n");
  return 1;
} 

get_colour_kind(ob) {
  if (ob -> is_wizard()) {
    if (ob -> query_level() > 34) {
      return "whoadmin";
    }
    return "whowizard";
  }
  if (ob -> is_paragon()) {
    return "whoparagon";
  }
  return "whomortal";
}