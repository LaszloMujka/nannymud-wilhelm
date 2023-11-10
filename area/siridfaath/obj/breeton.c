// -- This line is 78 characters long ----------------------------------------
inherit "/std/stationary";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("ship");
  add_alias("breeton");
  add_alias("wilhelm_ship");
  set_short("A trading ship");
  set_long("@get_long()");  
  add_property("wooden");
  add_property("colour", "brown");
 
  
  add_item( ({ "sail","sails" }), 
    "The ship has two huge sails.");
  add_item( ({ "breeton","letters","letter","sign" }), 
    "The letters Breeton is decorated on the back of the ship.");
 
  add_item_cmd("read","sign","@cmd_sign()");
  add_item(({ "vine","vines" }), 
	"@exa_vine()");
		
} // reset


get_long() {

  
  if (this_player()-> query_puzzle("wilhelm_bloodwood_quest")) {
  return line_break("It's a large trading ship, a large sign on the back is "+
  "decorated with the words BREETON.");
  }
  return line_break("It's a large trading ship, a large sign on the back is "+
  "decorated with the words BREETON. Large thorny vines stretch up from the "+
  "river coiling around the ship.");
}

exa_vine() {
  if (this_player()-> query_puzzle("wilhelm_bloodwood_quest")) {
  return line_break("You can still see the scratch marks on the ship, but the vines "+
  "are gone.");
  }
  return line_break("Large thick vines with sharp thorns are coiled around "+
  "the ship");
}

cmd_sign() {
    write("+------------------------------------------------------------+\n");
    write("| _____   _____   ______  ______  _______   _____    _     _ |\n");
    write("|(_____) (_____) (______)(______)(__ _ __) (_____)  (_)   (_)|\n");
    write("|(_)__(_)(_)__(_)(_)__   (_)__      (_)   (_)   (_) (__)_ (_)|\n");
    write("|(_____) (_____) (____)  (____)     (_)   (_)   (_) (_)(_)(_)|\n");
    write("|(_)__(_)( ) ( ) (_)____ (_)____    (_)   (_)___(_) (_)  (__)|\n");
    write("|(_____) (_)  (_)(______)(______)   (_)    (_____)  (_)   (_)|\n");
    write("|                                                            |\n");
    write("+------------------------------------------------------------+\n");
  return 1;
}	

