#define DEBUG(x) if(find_player("wilhelm")) tell_object(find_player("wilhelm"), sprintf("%O\n", x));
#define TO this_object()
#define TP this_player()
#define MSG(x) "/std/msg"->msg(x)
#define AREA "/players/wilhelm/area/"
#define XP_LOGGER	AREA + "xplogger/xp_logger"
#define MONSTER AREA + "siridfaath/monsters/basic_monster.c"
