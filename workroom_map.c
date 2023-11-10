
inherit "/std/room";

reset(arg)
{
  ::reset(arg);
  if (!arg) 
    
// -- Properties ---------------------------------------------------------
    
  

// -- Description and settings -------------------------------------------


// -- Objects ------------------------------------------------------------

    add_item(({ "map" }), "A big map of the area. Try 'study map'");

// -- Commands ------------------------------------------------------------
 
	add_item_cmd("study", "map", "@study_map()");

}



study_map() {
  int i;
  int something;
  object *cellestoff;

  if (!(this_player() -> is_wizard())) {
    return "You aren't powerful enough to study the fog.\n";
  }

  write("When you study the map, you see:\n\n");
  write("------------------------------------------------------------------" +
        "------------\n");

  cellestoff = all_inventory(load_object("/players/wilhelm/area/siridfaath/rooms/area_entry"));
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
cellestoff = all_inventory(load_object("/players/wilhelm/area/siridfaath/rooms/siridfaath_circus"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- circus - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }
  //----------------------------- Bloodwood -----------------
cellestoff = all_inventory(load_object("/players/wilhelm/area/bloodwood/rooms/branch1"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- Bloodwood: branch - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }
cellestoff = all_inventory(load_object("/players/wilhelm/area/bloodwood/rooms/courtyard"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- Bloodwood: Courtyard - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }
cellestoff = all_inventory(load_object("/players/wilhelm/area/bloodwood/rooms/forest_p1"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- Bloodwood: Forest path1 - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }
cellestoff = all_inventory(load_object("/players/wilhelm/area/bloodwood/rooms/forest_p2"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- Bloodwood: Forest path2 - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }
cellestoff = all_inventory(load_object("/players/wilhelm/area/bloodwood/rooms/forest_p3"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- Bloodwood: Forest path3 - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }  
cellestoff = all_inventory(load_object("/players/wilhelm/area/bloodwood/rooms/forest_p4"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- Bloodwood: Forest path4 - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }   
cellestoff = all_inventory	

	((load_object("/players/wilhelm/area/bloodwood/rooms/forest1"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest2"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest3"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest4"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest5"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest6"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest7"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest8"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest9"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest10"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest11"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest12"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest13"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest14"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest15"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest16"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest17"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest18"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest19"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest20"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest21"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest22"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest23"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest24"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest25"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest26"))||
	 (load_object("/players/wilhelm/area/bloodwood/rooms/forest27")));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- Bloodwood: Forest - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }  
  
 
  
cellestoff = all_inventory(load_object("/players/wilhelm/area/bloodwood/rooms/forest22"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- Bloodwood: Forest22 - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  } 
cellestoff = all_inventory(load_object("/players/wilhelm/area/bloodwood/rooms/forest23"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- Bloodwood: Forest23 - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }   
  cellestoff = all_inventory(load_object("/players/wilhelm/area/bloodwood/rooms/forest24"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- Bloodwood: Forest24 - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  } 
cellestoff = all_inventory(load_object("/players/wilhelm/area/bloodwood/rooms/forest25"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- Bloodwood: Forest25 - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }   
cellestoff = all_inventory(load_object("/players/wilhelm/area/bloodwood/rooms/forest26"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- Bloodwood: Forest26 - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  } 
cellestoff = all_inventory(load_object("/players/wilhelm/area/bloodwood/rooms/forest27"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- Bloodwood: Forest27 - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  } 

cellestoff = all_inventory(load_object("/players/wilhelm/area/bloodwood/rooms/gardens1"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- Bloodwood: Gardens - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }
cellestoff = all_inventory(load_object("/players/wilhelm/area/bloodwood/rooms/gardens2"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- Bloodwood: Maze2 - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }
cellestoff = all_inventory(load_object("/players/wilhelm/area/bloodwood/rooms/gardens3"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- Bloodwood: Maze3 - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }
cellestoff = all_inventory(load_object("/players/wilhelm/area/bloodwood/rooms/gardens4"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- Bloodwood: Maze4 - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }  
cellestoff = all_inventory(load_object("/players/wilhelm/area/bloodwood/rooms/maze_tree"));
  if (sizeof(cellestoff)) {
    for (i=0; i < sizeof(cellestoff); i++) {
      if (interactive(cellestoff[i])) {
        something = 1;
        write("[- Bloodwood: Maze tree - ] " +
              colourize_string(capitalize(cellestoff[i] -> short()) + ".\n",
              this_player(), get_colour_kind(cellestoff[i])));
      }
    }
  }  
    
  // -----------------------------------------------------------
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




