#define DEBUG(x) if(find_player("wilhelm")) tell_object(find_player("wilhelm"), sprintf("%O\n", x));
#define TO this_object()
#define TP this_player()
#define MSG(x) "/std/msg"->msg(x)
