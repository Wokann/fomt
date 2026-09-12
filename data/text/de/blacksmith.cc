#include "blacksmith_text.hh"

#if defined(FOMT_TEXT_BLACKSMITH_MENU)

char const gText_Blacksmith_ToolUpgradeMenuLabel[] =
    "            Upgrading ";

char const gText_Blacksmith_ToolUpgradeTitle[] =
    "Upgrading Tools";

char const gText_Blacksmith_Empty[] =
    "";

char const gText_Blacksmith_MakeMayonnaiseMaker[] =
    "Make Mayonnaise Maker";

char const gText_Blacksmith_CostAdamantite[] =
    "Cost to make this\r\n"
    "Gold   20,000G\r\n"
    "Ore     Adamantite";

char const gText_Blacksmith_MakeCheeseMaker[] =
    "Make Cheese Maker";

char const gText_Blacksmith_MakeYarnMaker[] =
    "Make Yarn Maker";

char const gText_Blacksmith_MakeNecklace[] =
    "Make Necklace";

char const gText_Blacksmith_CostOrichalc[] =
    "Cost to make this\r\n"
    "Gold   1,000G\r\n"
    "Ore     Orichalc";

char const gText_Blacksmith_MakeEarrings[] =
    "Make Earrings";

char const gText_Blacksmith_MakeBracelet[] =
    "Make Bracelet";

char const gText_Blacksmith_MakeBroach[] =
    "Make Broach";

#elif defined(FOMT_TEXT_BLACKSMITH_DIALOGUE)

char const gText_Blacksmith_InsufficientGoldAdamantite[] =
    "To make this, you need\r\n"
    "Adamantite Ore and 20,000\r\n"
    "gold pieces...{Press}\p"
    "So you don't have the \r\n"
    "money?...Too bad!{Press}";

char const gText_Blacksmith_InsufficientGoldOrichalc[] =
    "To make this, you need\r\n"
    "Orichalc Ore and 1,000\r\n"
    "gold pieces...{Press}\p"
    "So you don't have the \r\n"
    "money?...Too bad!{Press}";

char const gText_Blacksmith_MakerFiveDays[] =
    "It will take me five days\r\n"
    "to make. Are you sure?{Press}";

char const gText_Blacksmith_MakerOneDay[] =
    "It will take me one day\r\n"
    "to make. Are you sure?{Press}";

char const gText_Blacksmith_InsufficientOreAdamantite[] =
    "To make this, you need\r\n"
    "Adamantite Ore and 20,000\r\n"
    "gold pieces...{Press}\p"
    "So you don't have the \r\n"
    "Ore?...You can find it in \r\n"
    "the mine near the spring.{Press}";

char const gText_Blacksmith_InsufficientOreOrichalc[] =
    "To make this, you need\r\n"
    "Orichalc Ore and 1,000\r\n"
    "gold pieces...{Press}\p"
    "So you don't have the \r\n"
    "Ore?...You can find it in \r\n"
    "the mine near the spring.{Press}";

char const gText_Blacksmith_SelectToolAndOre[] =
    "Select a Tool to upgrade\r\n"
    "and an Ore to upgrade\r\n"
    "it with.{Press}";

char const gText_Blacksmith_InsufficientGold[] =
    "Sorry, but you don't have\r\n"
    "enough gold.{Press}";

char const gText_Blacksmith_EquipmentFull[] =
    "You can't hold anything \r\n"
    "else. {Press}";

char const gText_Blacksmith_NeedAnythingElse[] =
    "Do you need anything else?{Press}";

char const gText_Blacksmith_NothingElse[] =
    "You're sure you don't\r\n"
    "need anything?{Press}";

char const gText_Blacksmith_PurchaseComplete[] =
    "Thanks a lot!{Press}";

char const gText_Blacksmith_Delivery[] =
    "Thanks a lot. You can't\r\n"
    "anything else, though, so\r\n"
    "I'll have Gray deliver it.{Press}";

char const gText_Blacksmith_PurchaseMore[] =
    "Looking for something else\r\n"
    "as well?{Press}";

char const gText_Blacksmith_MakeIt[] =
    "Make it";

char const gText_Blacksmith_DontMakeIt[] =
    "Don't make it";

char const gText_Blacksmith_StartWork[] =
    "OK, I have to get to work!\r\n"
    "Quit bothering me!{Press}";

char const gText_Blacksmith_CannotChangeMind[] =
    "A man doesn't change\r\n"
    "his mind, you know.{Press}";

char const gText_Blacksmith_NoToolToUpgrade[] =
    "Why don't you come back\r\n"
    "when you have something\r\n"
    "for me to upgrade for you!{Press}";

char const gText_Blacksmith_NoOreToUpgrade[] =
    "You don't have any Ore for\r\n"
    "me to use! You can find \r\n"
    "some in the mine by the {Press}\r\n"
    "spring, you know.{Press}";

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
