#include "/players/wilhelm/area/macros.h"

inherit "std/state_monster";

reset(arg){
        ::reset(arg);
        if (arg)
                return;

        add_hook("die_hook", this_object());
}


void die_hook(mixed arr, object monster) {
        XP_LOGGER -> die_hook(arr, monster);
}