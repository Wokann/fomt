#include "blacksmith_text.hh"

#if defined(FOMT_TEXT_BLACKSMITH_MENU)

char const gText_Blacksmith_ToolUpgradeMenuLabel[] =
    "            Aufrüsten";

char const gText_Blacksmith_ToolUpgradeTitle[] =
    "Werkzeuge aufrüsten";

char const gText_Blacksmith_Empty[] =
    "";

char const gText_Blacksmith_MakeMayonnaiseMaker[] =
    "Mayonnaisemaschine machen";

char const gText_Blacksmith_CostAdamantite[] =
    "Preis für\r\n"
    "Gold   20.000G\r\n"
    "Erz     Adamantite";

char const gText_Blacksmith_MakeCheeseMaker[] =
    "Käsemaschine machen";

char const gText_Blacksmith_MakeYarnMaker[] =
    "Garnmaschine machen";

char const gText_Blacksmith_MakeNecklace[] =
    "Halskette machen";

char const gText_Blacksmith_CostOrichalc[] =
    "Preis für\r\n"
    "Gold   1.000G\r\n"
    "Erz     Orichalc";

char const gText_Blacksmith_MakeEarrings[] =
    "Ohrringe machen";

char const gText_Blacksmith_MakeBracelet[] =
    "Armband machen";

char const gText_Blacksmith_MakeBroach[] =
    "Brosche machen";

#elif defined(FOMT_TEXT_BLACKSMITH_DIALOGUE)

char const gText_Blacksmith_InsufficientGoldAdamantite[] =
    "Hierfür brauchst du\r\n"
    "Adamantiterz und  20.000\r\n"
    "Goldstücke...{Press}\p"
    "Du hast das Geld \r\n"
    "nicht?...Zu schade!{Press}";

char const gText_Blacksmith_InsufficientGoldOrichalc[] =
    "Hierfür brauchst du\r\n"
    "Orichalcerz und 1.000\r\n"
    "Goldstücke...{Press}\p"
    "Du hast das Geld also\r\n"
    "nicht?...Zu schade!{Press}";

char const gText_Blacksmith_MakerFiveDays[] =
    "Für die Herstellung\r\n"
    "brauche ich 5 Tage. \r\n"
    "Bist du sicher?{Press}";

char const gText_Blacksmith_MakerOneDay[] =
    "Ich brauche einen Tag\r\n"
    "für die Herstellung.\r\n"
    "Bist du sicher?{Press}";

char const gText_Blacksmith_InsufficientOreAdamantite[] =
    "Hierfür brauchst du\r\n"
    "Adamantiterz und  20.000\r\n"
    "Goldstücke...{Press}\p"
    "Du hast das Erz also \r\n"
    "nicht?...Du findest es in\r\n"
    "der Mine bei der Quelle.{Press}";

char const gText_Blacksmith_InsufficientOreOrichalc[] =
    "Hierfür brauchst du\r\n"
    "Orichalcerz und 1.000\r\n"
    "Goldstücke...{Press}\p"
    "Du hast das Erz also \r\n"
    "nicht?...Du findest es in\r\n"
    "der Mine bei der Quelle.{Press}";

char const gText_Blacksmith_SelectToolAndOre[] =
    "Wähle ein Werkzeug und\r\n"
    "das gewünschte Erz\r\n"
    "zum Aufrüsten.{Press}";

char const gText_Blacksmith_InsufficientGold[] =
    "Tut mir leid, aber du\r\n"
    "hast nicht genug Gold.{Press}";

char const gText_Blacksmith_EquipmentFull[] =
    "Du kannst nichts anderes \r\n"
    "mehr halten. {Press}";

char const gText_Blacksmith_NeedAnythingElse[] =
    "Brauchst du noch etwas?{Press}";

char const gText_Blacksmith_NothingElse[] =
    "Sicher, dass du nichts\r\n"
    "brauchst?{Press}";

char const gText_Blacksmith_PurchaseComplete[] =
    "Vielen Dank!{Press}";

char const gText_Blacksmith_Delivery[] =
    "Vielen Dank. Du kannst \r\n"
    "nichts mehr, also lasse ich\r\n"
    "es von Gray liefern.{Press}";

char const gText_Blacksmith_PurchaseMore[] =
    "Suchst du auch noch\r\n"
    "nach etwas anderem?{Press}";

char const gText_Blacksmith_MakeIt[] =
    "Herstellen";

char const gText_Blacksmith_DontMakeIt[] =
    "Nicht herstellen";

char const gText_Blacksmith_StartWork[] =
    "OK, ich muss arbeiten!\r\n"
    "Hör auf, mich zu stören!{Press}";

char const gText_Blacksmith_CannotChangeMind[] =
    "Ein Mann ändert seine\r\n"
    "Meinung nicht.{Press}";

char const gText_Blacksmith_NoToolToUpgrade[] =
    "Warum kommst du nicht\r\n"
    "wieder, wenn du etwas\r\n"
    "zum Aufrüsten hast!{Press}";

char const gText_Blacksmith_NoOreToUpgrade[] =
    "Du hast kein Erz, das ich\r\n"
    "gebrauchen kann! Du weißt,\r\n"
    "dass du in der Mine bei{Press}\r\n"
    "der Quelle welches findest.{Press}";

char const gCppRuntimeBadAlloc_BlacksmithDialogueTrailer[] =
    "bad_alloc";

#elif defined(FOMT_TEXT_BLACKSMITH_UPGRADE)

char const gText_BlacksmithUpgrade_EmptyDescription[] =
    "";

char const gText_BlacksmithUpgrade_Tools[] =
    "Werkzeug";

char const gText_BlacksmithUpgrade_Items[] =
    "Dinge ";

char const gText_BlacksmithUpgrade_SelectTool[] =
    "Wähle erst ein Werkzeug,\r\n"
    "das du aufrüsten willst.{Press}";

char const gText_BlacksmithUpgrade_CursedTool[] =
    "Das ist...v-verwünscht!\r\n"
    "Was denkst du dir dabei?!{Press}";

char const gText_BlacksmithUpgrade_SelectOre[] =
    "Als Nächstes wähle\r\n"
    "ein Erz, um damit dieses\r\n"
    "Werkzeug aufzurüsten.{Press}";

char const gText_BlacksmithUpgrade_CannotUpgradeTool[] =
    "Das kann nicht \r\n"
    "aufgerüstet werden.{Press}";

char const gText_BlacksmithUpgrade_InvalidUpgradeOre[] =
    "Das kannst du nicht\r\n"
    "zum Aufrüsten benutzen.\r\n"
    "Du brauchst stattdessen{Press}\p"
    "ein besseres Erz.{Press}";

char const gText_BlacksmithUpgrade_CannotChangeMind[] =
    "Ein richtiger Mann ändert\r\n"
    "seine Meinung nicht.{Press}";

char const gText_BlacksmithUpgrade_InsufficientExperience[] =
    "Du hast nicht genug\r\n"
    "Erfahrung, um dieses\r\n"
    "Werkzeug aufzurüsten.{Press}";

char const gText_BlacksmithUpgrade_AlreadyUpgradedWithOre[] =
    "Das Werkzeug wurde schon\r\n"
    "mit diesem Erz aufgerüstet.{Press}";

char const gText_BlacksmithUpgrade_DowngradeConfirmation[] =
    "Hmmpf! Was soll das denn\r\n"
    "werden, willst du deine\r\n"
    "Werkzeuge verschlechtern?!{Press}";

char const gText_BlacksmithUpgrade_WorkOrderPrefix[] =
    "Das Werkzeug ist ";

char const gText_BlacksmithUpgrade_WorkOrderGoldSuffix[] =
    "G, \r\n";

char const gText_BlacksmithUpgrade_WorkOrderDaysPrefix[] =
    "und es dauert ";

char const gText_BlacksmithUpgrade_WorkOrderDaysSuffix[] =
    " Tage.\r\n";

char const gText_BlacksmithUpgrade_WorkOrderQuestion[] =
    "Ist das OK?{Press}";

char const gText_BlacksmithUpgrade_InsufficientGoldPageBreak[] =
    "\p";

char const gText_BlacksmithUpgrade_InsufficientGold[] =
    "Hmm....Du hast nicht\r\n"
    "genug Geld!\r\n"
    "Dafür kann ich es nicht tun.{Press}";

char const gText_BlacksmithUpgrade_ResultYes[] =
    "Ja";

char const gText_BlacksmithUpgrade_ResultNo[] =
    "Nein";

#else
#error "Select one blacksmith text fragment before including this file."
#endif
