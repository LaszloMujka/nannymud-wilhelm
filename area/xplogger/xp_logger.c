/*****************************************************************
 *
 * logger: Experience logger.
 *
 * Please note any changes to this file in the table below, to
 * preserve consistency.
 *
 * Date       Who             What
 * ---------------------------------------------------------------
 * 01-03-2000 Spiral          First version, bugfixing, etc.
 * 10-07-2000 Sync            Some more bugfixing and fiddling here
 *                            and there.
 *
 *****************************************************************/
#include <level.h>
#include <tune.h>
#include <fingerd.h>

#include "/players/wilhelm/area/macros.h"

inherit "/std/basic_monster";

#pragma strict_types
#pragma save_types

/* Location of files. */
#define AREAD      "obj/daemon/area_d"

/* Tune defines. */
#define CHUNK       500
#define TIMEOUT     60*60*24*365*100

/* Variables that will not be saved. */
static private int      setup_done          = 0;
static private int      prevent_logging     = 0;
static private int      data_indices_size   = 0;
static private int      count_entries       = 0;
static private int      timestamp           = 0;

static private string   log_file_name       = AREA + "xplogger/xp_log";
static private string   *data_indices       = ({});

/* Variables that will be saved. */
int                     log_start_time      = 0;
mapping                 parsed_data         = ([]);

string *pi = ({ "wilhelm" });

/* Function prototypes. */
void reset(int arg);
void garbage_collect();
static void setup_logger();


static void setup_logger() {
    string mname;
    mixed tmpm;

    if (setup_done) return;
    mname = creator(this_object());
    if (!stringp(mname)) return;

    if (!restore_object(log_file_name)) {
        parsed_data = ([]);
        log_start_time = time();
    }
    setup_done = 1;
    timestamp = time();
} /* setup_logger */


void reset(int arg) {
    if (!arg) {
        if (_isclone())
            call_out("destruct_logger", 0);
        else
            setup_logger();
    }
    if (arg) {
        if (mappingp(parsed_data) && m_sizeof(parsed_data)) {
            if (random(200)) {
                if (!prevent_logging)
                    save_object(log_file_name);
            } else {
                call_out("garbage_collect", 2);
            }
        }
    }

	set_name("xp logger");
	add_alias("logger");
	set_short("xp logger");
	set_long("an xp logger");
	move_object(this_object(), "/players/wilhelm/area/xplogger/xplogger_control_room");
} /* reset */


void destruct_logger() {
    while (remove_call_out("destruct_logger") != -1);
    destruct(this_object());
} /* destruct_logger */


int clean_up(int ref_count) {
    if (ref_count > 1)
        return 1;
    destruct(this_object());
    return 0;
} /* clean_up */


void garbage_collect() {
    if (!setup_done) setup_logger();

    if (!mappingp(parsed_data)) parsed_data = ([]);
    data_indices = m_indices(parsed_data) - ({ 0 });

    if (!sizeof(data_indices)) return;
    data_indices_size = sizeof(data_indices);
    count_entries = 0;

    if (environment())
        tell_room(environment(),
                  "xp_logger: Garbage collect started:\n");

    call_out("garbage_collect_low", 2, 0);
} /* garbage_collect */


void garbage_collect_low(int current) {
    int i, count;

    while (remove_call_out("garbage_collect_low") != -1);
    if ((current + CHUNK) < data_indices_size)
        call_out("garbage_collect_low", 2, current + CHUNK);
    else
        call_out("garbage_collect_finished", 2);

    if (!mappingp(parsed_data))
        parsed_data = ([]);

    count = 0;
    for (i = current; i < (current + CHUNK) && i < data_indices_size; i++)
        if (!stringp(data_indices[i]) ||                        // sanity
            !strlen(data_indices[i]) ||                         // sanity
            !FINGERD->playerp(data_indices[i]) ||               // wiped player
            FINGERD->query_banished(data_indices[i]) ||         // banned player
            member_array(data_indices[i], pi) != -1 ||          // ignored player
            sizeof(parsed_data[data_indices[i]]) != 4 )
        {
          _m_delete(parsed_data, data_indices[i]);
          count++;
        }

    if (environment())
        tell_room(environment(),
                  "xp_logger: Just collected " + count + " garbage data.\n");
} /* garbage_collect_low */


void garbage_collect_finished() {
    while (remove_call_out("garbage_collect_finished") != -1);

    if (environment())
        tell_room(environment(),
                  "xp_logger: Garbage collecting done.\n");

    save_object(log_file_name);
} /* garbage_collect_finished */


void __exit() {
    if (!prevent_logging)
        save_object(log_file_name);
} /* __exit */


void _exit() {
    catch(__exit());
} /* _exit */

void save_me() {
    save_object(log_file_name);
}


void die_hook(mixed arr, object monster) {
    string pname;
    int i, worth;
    object *o_tmp;
    mixed *data;

    if (!setup_done) setup_logger();

    if (prevent_logging) return;

    if (!pointerp(arr) || (sizeof(arr) != 3) ||
        !objectp(monster) || !objectp(arr[0]))
        return;

    if (!arr[0]->is_player() || !monster->query_npc()) return;

    pname = arr[0]->query_real_name();

    if (!stringp(pname) || !stringp(pname)
            || !FINGERD->playerp(pname)) return;

    if (!mappingp(parsed_data))                      /* Extra security. */
        parsed_data = ([]);

    if (pointerp(parsed_data[pname]))
        data = parsed_data[pname];
    else
        data = ({ 0, 0, 0, 0 });

    data[0] = time();
    data[1]++;
    data[2] += monster->query_level();

    worth = 0;
    if (objectp(arr[2])) {                          /* The corpse. */
        o_tmp = deep_inventory(arr[2]) - ({ 0 });
        for (i = 0; i < sizeof(o_tmp); i++)
            if(objectp(o_tmp[i]) && (o_tmp[i]->query_value() > 0))
                worth += o_tmp[i]->query_value();
    }
    data[3] += worth;

    parsed_data[pname] = data;
    timestamp = time();
} /* die_hook */


/******************************************
 Interface functions.
 ******************************************/
mapping get_raw_data() {
    if (!setup_done) setup_logger();
    if (!mappingp(parsed_data)) parsed_data = ([]);

    return parsed_data;
} /* get_raw_data */



mixed *get_parsed_data() {
    mapping dt;
    string *ind;
    int i;

    if (!setup_done) setup_logger();
    if (!mappingp(parsed_data)) parsed_data = ([]);
    ind = m_indices(parsed_data) - ({ 0 });
    dt = ([]);
    for (i = 0; i < sizeof(ind); i++)
        if (pointerp(parsed_data[ind[i]])
                && sizeof(parsed_data[ind[i]]) == 4)
            dt[parsed_data[ind[i]][2]] = ({  /* mapping-sorting by xp */
                    ind[i],
                    parsed_data[ind[i]][0],
                    parsed_data[ind[i]][1],
                    parsed_data[ind[i]][2],
                    parsed_data[ind[i]][3] });
    return m_values(dt) + ({});             /* copy the mapping for security */
} /* get_parsed_data */

int clear_all_data() {

    parsed_data = ([]);
    log_start_time = 0;

    if (!setup_done) setup_logger();

    parsed_data = ([]);
    log_start_time = 0;

    timestamp = time();

    if (!prevent_logging)
        save_object(log_file_name);
} /* clean_all_data */

int get_timestamp() { return timestamp; }
