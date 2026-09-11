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
    "Tools ";

char const gText_BlacksmithUpgrade_Items[] =
    "Items ";

char const gText_BlacksmithUpgrade_SelectTool[] =
    "First, select a Tool to be\r\n"
    "upgraded.{Press}";

char const gText_BlacksmithUpgrade_CursedTool[] =
    "This is...c-cursed!\r\n"
    "What are you thinking!!{Press}";

char const gText_BlacksmithUpgrade_SelectOre[] =
    "Next, select an Ore to\r\n"
    "upgrade that Tool with.{Press}";

char const gText_BlacksmithUpgrade_CannotUpgradeTool[] =
    "That can't be upgraded.{Press}";

char const gText_BlacksmithUpgrade_InvalidUpgradeOre[] =
    "You can't use that to\r\n"
    "upgrade Tools. You need\r\n"
    "a better Ore instead.{Press}";

char const gText_BlacksmithUpgrade_CannotChangeMind[] =
    "A real man doesn't change\r\n"
    "his mind, you know.{Press}";

char const gText_BlacksmithUpgrade_InsufficientExperience[] =
    "You don't have enough\r\n"
    "experience to upgrade\r\n"
    "that Tool.{Press}";

char const gText_BlacksmithUpgrade_AlreadyUpgradedWithOre[] =
    "That Tool has already been\r\n"
    "improved with the same Ore.{Press}";

char const gText_BlacksmithUpgrade_DowngradeConfirmation[] =
    "Hmmph! What are you\r\n"
    "trying to do, downgrade\r\n"
    "your Tools?!{Press}";

char const gText_BlacksmithUpgrade_WorkOrderPrefix[] =
    "That Tool is ";

char const gText_BlacksmithUpgrade_WorkOrderGoldSuffix[] =
    "G, \r\n";

char const gText_BlacksmithUpgrade_WorkOrderDaysPrefix[] =
    "and It will take ";

char const gText_BlacksmithUpgrade_WorkOrderDaysSuffix[] =
    " days.\r\n";

char const gText_BlacksmithUpgrade_WorkOrderQuestion[] =
    "Is that okay?{Press}";

char const gText_BlacksmithUpgrade_InsufficientGoldPageBreak[] =
    "\p";

char const gText_BlacksmithUpgrade_InsufficientGold[] =
    "Hmm....You don't have\r\n"
    "enough money!\r\n"
    "I can't do it for that.{Press}";

char const gText_BlacksmithUpgrade_ResultYes[] =
    "Yes";

char const gText_BlacksmithUpgrade_ResultNo[] =
    "No";

#else
#error "Select one blacksmith text fragment before including this file."
#endif
