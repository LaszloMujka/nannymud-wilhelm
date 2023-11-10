// -- This line is 78 characters long ----------------------------------------
inherit "/std/basic_thing";

int water_in_bucket;
int bucket_raised = 1;

reset(arg)
{
  ::reset(arg);
  if (arg) return;
  set_name("bucket");
  add_alias("wooden bucket");
  set_short("A bucket");
  set_long("@bucket_long()");
  set_weight(1);
  set_value(1);
  add_alias("wilhelm_bucket");
  add_property("wooden");
  add_property("no_convert");
  add_property("colour", "brown");
  add_property("__remote", this_object());
  water_in_bucket = 3;  //reset to 0, testing
  
  add_item("water", "@make_water()");
  
  add_command("splash %s","@cmd_splash()");
  add_command(({ 
  "drink water", "drink bucket","drink from bucket","drink water from bucket"}),
  "@cmd_drink()");

  if(!environment()) 
    move_object(this_object(), "/players/wilhelm/area/siridfaath/rooms/siridfaath2");
} // reset

// -- Description -----------------------------------------------------------

bucket_long() {
  if (water_in_bucket == 0) {
    return line_break("It's a old wooden bucket, used to get water from the "+
           "well. It is empty.");
  }
  if (water_in_bucket == 1) {
    return line_break("It's a old wooden bucket, used to get water from the "+
           "well. It is a little water in the bottom.");
  }
  if (water_in_bucket == 2) {
    return line_break("It's a old wooden bucket, used to get water from the "+
           "well. It is half-full with water.");
  }
  if (water_in_bucket == 3) {
    return line_break("It's a old wooden bucket, used to get water from the "+
           "well. It is full of water.");
  }
} // Reset bucket description

// * check this out -ad;
make_water() {
  switch(water_in_bucket) {
    case 0 :
      return line_break("There isn't any water left in the bucket.");
    case 1 :
      return line_break("It is a little water left, in the bottom of the "+
        "bucket.");
    case 2 :
      return line_break("The bucket is half-full with cold water.");
    case 3 :
      return line_break("The bucket is full of cold water.");
  }
} // Reset water description

// * check this out -ad;
cmd_drink()
{
  if(!water_in_bucket)
    return line_break("The bucket is empty, you need to fill it up first.");
  else {
    "/std/msg"->msg("\bPRON drink\b$ some water from the bucket.\n");
    --water_in_bucket;
    return line_break("Mmm, cold and refreshing.");
  }
} // Reset drink command

cmd_splash(string a, mixed target) {
  if (environment(this_object())!=this_player())
    return;

  if(!target) {
    write("Who are you going to splash water on?\n");
  return 1;  }
 
  if(!water_in_bucket) {
    write("The bucket is empty, you need to fill it up.\n");
    return 1;  
  }
/* 
  if(water_in_bucket = 1) {
    write("You need more water in the bucket to do that.\n");
    return 1;  
  }
  
This makes the bucket bug for some reason.
*/ 
  if(target==this_player()->query_real_name()) {
    "/std/msg"->msg("\bPRON splash\b$$ \bobj with water from the bucket.\n");
    write("Brr, that was cold!\n");
    this_player()->set_wet(20);
    water_in_bucket = 0;
  return 1;  }

  target=present(target, environment(this_player()));
  if(target) {
    "std/msg"->msg("\bPRON splash\b$$ \b2PRON with water from the bucket!\n",
      0, target);
    target->set_wet(20);
    water_in_bucket = 0;
  return 1;  }
  else write("That person isn't here.\n");
  return 1;
} // Reset splash command

// * use remote_prevent_insert, read the man file
status prevent_insert() {
if (!query_property("__insertable")) {
write("The bucket is tied to the well.\n");
return 1;
  }
}

set_water(int i) { 
  water_in_bucket = i; 
}

query_raised() { return bucket_raised; }

int raise_bucket() {
  if (query_raised()) return 0;

  move_object(this_object(), "/players/wilhelm/area/siridfaath/rooms/siridfaath2");
  tell_room ("/players/wilhelm/area/siridfaath/rooms/siridfaath_well",
             "Someone raised the bucket from outside the well.\n");
  bucket_raised = 1;
  return 1;
}

int lower_bucket() {
  if (!query_raised()) return 0;

  move_object(this_object(), "players/wilhelm/area/siridfaath/rooms/siridfaath_well");
  tell_room ("/players/wilhelm/area/siridfaath/rooms/siridfaath_well",
             "A bucket lands beside you with a loud splash.\n");
  set_water(3); 
  bucket_raised = 0;
  return 1;
}

