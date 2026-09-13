#include "intro_scene_data.hh"

// The physical order is the original childhood-visit sequence.  Its callers
// load these named strings directly from code literal pools.

char const gText_IntroScene_MotherName[] =
    "Mutter";

char const gText_IntroScene_MotherTravelGreeting[] ALIGN(4) =
    "\p"
    "Was ist damit, \xFF\x3F\r\n"
    "Freust du dich nicht, dass \r\n"
    "du mitgekommen bist?{Press}";

char const gText_IntroScene_FatherName[] ALIGN(4) =
    "Vater";

char const gText_IntroScene_FatherFishingInvitation[] ALIGN(4) =
    "\p"
    "Ich bin auch froh über\r\n"
    "den Urlaub. Willst du am\r\n"
    "Fluss angeln gehen?{Press}";

char const gText_IntroScene_MotherCannotFindPlayer[] ALIGN(4) =
    "\p"
    "\xFF\x3F{Press}\p"
    "Mensch! Ich kann \r\n"
    "\xFF\x20nicht finden!{Press}";

char const gText_IntroScene_PlayerResponseWhat[] ALIGN(4) =
    "\p"
    "Was...?{Press}";

char const gText_IntroScene_OldManName[] ALIGN(4) =
    "Alter Mann";

char const gText_IntroScene_OldManFindsPlayer[] ALIGN(4) =
    "\p"
    "Hey, kleiner Mann,\r\n"
    "warum weinst du?{Press}\p"
    "Hast du\r\n"
    "dich verlaufen?{Press}\r\n"
    "Was ist das? Eine Telefon- \r\n"
    "nummer auf deinem Rucksack?{Press}\r\n"
    "Lass uns anrufen.{Press}";

char const gText_IntroScene_MotherThanksOldMan[] ALIGN(4) =
    "\p"
    "Vielen Dank, dass du \r\n"
    "uns geholfen hast,\r\n"
    "unseren Sohn zu finden!{Press}";

char const gText_IntroScene_FatherExplainsVacation[] ALIGN(4) =
    "\p"
    "Wir wohnen in der Stadt, auf\r\n"
    "diesem Ausflug wollten wir\r\n"
    "unserem Sohn das{Press}\r\n"
    "Landleben zeigen.{Press}";

char const gText_IntroScene_OldManOffersStay[] ALIGN(4) =
    "\p"
    "Tatsächlich? {Press}\p"
    "Wenn das so ist, warum\r\n"
    "kommt ihr nicht mit und\r\n"
    "verbringt ein paar Tage{Press}\r\n"
    "auf meiner Farm?{Press}";

char const gText_IntroScene_FatherAsksAboutStay[] ALIGN(4) =
    "\p"
    "Im Ernst?{Press}";

char const gText_IntroScene_OldManWelcomesFamily[] ALIGN(4) =
    "\p"
    "Ja! Ich wohne allein, ihr \r\n"
    "stört niemanden.\r\n"
    "Ich würde mich über{Press}\r\n"
    "Gesellschaft freuen.{Press}";

char const gText_IntroScene_MotherTellsPlayerToPlay[] ALIGN(4) =
    "\p"
    "Ist das nicht toll, \r\n"
    "\xFF\x3F{Press}\r\n"
    "Dann hast du die ganze Farm\r\n"
    "zum Spielen!{Press}";

char const gText_IntroScene_UnknownName[] ALIGN(4) =
    "???";

char const gText_IntroScene_UnknownCallsPlayer[] ALIGN(4) =
    "\p"
    "y...{Press}\p"
    "ey...{Press}\p"
    "Hey.{Press}";

char const gText_IntroScene_UnknownFindsPlayer[] ALIGN(4) =
    "\p"
    "！{Press}";

char const gText_IntroScene_GirlName[] ALIGN(4) =
    "Mädchen";

char const gText_IntroScene_GirlThinksPlayerDead[] ALIGN(4) =
    "\p"
    "Du warst so still, \r\n"
    "ich dachte, du wärst tot!{Press}";

char const gText_IntroScene_GirlInvitesPlayerToPlay[] ALIGN(4) =
    "\p"
    "Das ist perfekt. \r\n"
    "Ich habe jemanden\r\n"
    "zum Spielen gesucht. {Press}\r\n"
    "Denke, du bist gut dafür. {Press}";

char const gText_IntroScene_GirlAsksPlayerStory[] ALIGN(4) =
    "\p"
    "Es macht keinen Spaß, wenn\r\n"
    "du nur stumm da sitzt!{Press}\p"
    "Warum erzählst du mir\r\n"
    "nichts über dich? \r\n"
    "Ich bin neugierig.{Press}";

char const gText_IntroScene_OldManFarewell[] ALIGN(4) =
    "\p"
    "Hattest du Spaß?{Press}\p"
    "Ich hatte auf jeden Fall\r\n"
    "Spaß mit dir.\r\n"
    "Ich selber habe keine{Press}\r\n"
    "Enkelkinder, weißt du...{Press}\p"
    "Na ja, du musst nun gehen.\r\n"
    "Mach es gut!...{Press}";

char const gText_IntroScene_OldManRequestsLetter[] ALIGN(4) =
    "\p"
    "Meinst du, dass du einem\r\n"
    "alten Mann mal einen Brief\r\n"
    "schrieben könntest...?{Press}";

char const gText_IntroScene_OldManGivesAddress[] ALIGN(4) =
    "\p"
    "Wirklich? \r\n"
    "Hier ist meine Adresse.{Press}";

char const gText_IntroScene_GirlSaysGoodbye[] ALIGN(4) =
    "\p"
    "Du gehst schon?{Press}";

char const gText_IntroScene_GirlAsksPlayerToReturn[] ALIGN(4) =
    "\p"
    "Wenn du gehst, ist mir\r\n"
    "langweilig und ich bin\r\n"
    "allein. Du MUSST{Press}\p"
    "zurückkommen, OK?{Press}";

char const gText_IntroScene_OldManNotesFriend[] ALIGN(4) =
    "\p"
    "Sieht aus, als hättest du \r\n"
    "einen Freund gefunden! \r\n"
    "Nur ein weiterer Grund, um{Press}\r\n"
    "zurückzukommen...{Press}";

char const gText_IntroScene_OldManWaitsForLetter[] ALIGN(4) =
    "\p"
    "Ich warte auf deinen \r\n"
    "Brief!...{Press}";

EXTERN_C

char const gCppRuntimeBadAlloc_IntroSceneTextTrailer[] ALIGN(4) =
    "bad_alloc";

EXTERN_C_END
