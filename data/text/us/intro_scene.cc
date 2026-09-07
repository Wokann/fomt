#include "intro_scene_text.hh"

// The physical order is the original childhood-visit sequence.  Its callers
// load these named strings directly from code literal pools.

char const gText_IntroScene_MotherName[] SECTION(".rodata.intro_scene_text") =
    "Mother";

char const gText_IntroScene_MotherTravelGreeting[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "What about it, \xFF?\r\n"
    "Aren't you glad you came \r\n"
    "on the trip?{Press}";

char const gText_IntroScene_FatherName[] SECTION(".rodata.intro_scene_text") =
    "Father";

char const gText_IntroScene_FatherFishingInvitation[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "I'm glad for the vacation,\r\n"
    "too.  Hey, want to go \r\n"
    "fishing in the river?{Press}";

char const gText_IntroScene_MotherCannotFindPlayer[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "\xFF?{Press}"
    "\p"
    "Oh, dear! I can't find \r\n"
    "{Player}{Press}";

char const gText_IntroScene_PlayerResponseWhat[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "What...?{Press}";

char const gText_IntroScene_OldManName[] SECTION(".rodata.intro_scene_text") =
    "Old Man";

char const gText_IntroScene_OldManFindsPlayer[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "Hey, young man. \r\n"
    "Why are you crying?\r\n"
    "Did you get lost?{Press}\r\n"
    "What's this? Is that your\r\n"
    "phone number on your bag?{Press}\r\n"
    "Let's call your parents.{Press}";

char const gText_IntroScene_MotherThanksOldMan[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "Thank you so much for \r\n"
    "helping us find our son!{Press}";

char const gText_IntroScene_FatherExplainsVacation[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "We live in the city, but we\r\n"
    "wanted to show our son the\r\n"
    "country on this trip.{Press}";

char const gText_IntroScene_OldManOffersStay[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "Is that so? {Press}"
    "\p"
    "In that case, why not come\r\n"
    "spend a few days \r\n"
    "on my farm?{Press}";

char const gText_IntroScene_FatherAsksAboutStay[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "You really mean it?{Press}";

char const gText_IntroScene_OldManWelcomesFamily[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "Sure! I live alone, so you\r\n"
    "wouldn't bother anybody.\r\n"
    "I'd love the company.{Press}";

char const gText_IntroScene_MotherTellsPlayerToPlay[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "Isn't this great, \r\n"
    "\xFF?{Press}\r\n"
    "Now you'll have a whole\r\n"
    "farm to play on!{Press}";

char const gText_IntroScene_UnknownName[] SECTION(".rodata.intro_scene_text") =
    "???";

char const gText_IntroScene_UnknownCallsPlayer[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "y...{Press}"
    "\p"
    "ey...{Press}"
    "\p"
    "Hey.{Press}";

char const gText_IntroScene_UnknownFindsPlayer[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "！{Press}";

char const gText_IntroScene_GirlName[] SECTION(".rodata.intro_scene_text") =
    "Girl";

char const gText_IntroScene_GirlThinksPlayerDead[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "You were so quiet that\r\n"
    "I thought you were dead!{Press}";

char const gText_IntroScene_GirlInvitesPlayerToPlay[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "This is perfect. I was \r\n"
    "looking for someone to\r\n"
    "play together. {Press}\r\n"
    "I guess you'll do. {Press}";

char const gText_IntroScene_GirlAsksPlayerStory[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "It's no fun if you just sit\r\n"
    "there and say nothing!{Press}"
    "\p"
    "Why don't you tell me about\r\n"
    "yourself?{Press}";

char const gText_IntroScene_OldManFarewell[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "Did you have fun?{Press}"
    "\p"
    "I sure had fun with you.\r\n"
    "I don't have any grandkids \r\n"
    "of my own, you know...{Press}"
    "\p"
    "Well, you have to go now.\r\n"
    "Farewell!...{Press}";

char const gText_IntroScene_OldManRequestsLetter[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "Is there any chance of you\r\n"
    "writing an old man a letter\r\n"
    "once in a while...?{Press}";

char const gText_IntroScene_OldManGivesAddress[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "Really? \r\n"
    "Here's my address, then.{Press}";

char const gText_IntroScene_GirlSaysGoodbye[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "You're leaving already?{Press}";

char const gText_IntroScene_GirlAsksPlayerToReturn[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "If you go, I'll be bored\r\n"
    "and lonely again...{Press}"
    "\p"
    "You HAVE to come back, OK?{Press}";

char const gText_IntroScene_OldManNotesFriend[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "Looks like you've made \r\n"
    "a friend! Just one more \r\n"
    "reason to return, I guess.{Press}";

char const gText_IntroScene_OldManWaitsForLetter[] SECTION(".rodata.intro_scene_text") =
    "\p"
    "I'll be waiting for \r\n"
    "your letter...{Press}";
