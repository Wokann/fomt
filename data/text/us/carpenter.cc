#include "carpenter_text.hh"

#if defined(FOMT_TEXT_CARPENTER_MENU)

char const gText_Carpenter_Lumber[] =
    "Lumber";

char const gText_Carpenter_GoldenLumber[] =
    "Golden Lumber";

char const gText_Carpenter_HouseExtension[] =
    "House Extension";

char const gText_Carpenter_HouseExtensionFirstCost[] =
    "Cost of upgrading your House\r\n"
    "Gold      3,000G\r\n"
    "Lumber    200 pieces";

char const gText_Carpenter_HouseExtensionSecondCost[] =
    "Cost of upgrading your House\r\n"
    "Gold    10,000G\r\n"
    "Lumber  700 pieces";

char const gText_Carpenter_AddBathtub[] =
    "Add a Bathtub";

char const gText_Carpenter_BathtubCost[] =
    "Cost of upgrading your Bath\r\n"
    "Gold    30,000G\r\n"
    "Lumber  580 pieces";

char const gText_Carpenter_ExpandChickenCoop[] =
    "Chicken Coop";

char const gText_Carpenter_ChickenCoopCost[] =
    "Cost of upgrading your \r\n"
    "Chicken Coop{Press}\p"
    "Gold    5,000G\r\n"
    "Lumber  420 pieces";

char const gText_Carpenter_ExpandBarn[] =
    "Remodel Barn";

char const gText_Carpenter_BarnCost[] =
    "Cost of upgrading your Barn\r\n"
    "Gold    6,800G\r\n"
    "Lumber  500 pieces";

char const gText_Carpenter_BuildVacationHouse[] =
    "Vacation House";

char const gText_Carpenter_VacationHouseCost[] =
    "Cost of building a Cottage\r\n"
    "Gold    100,000,000G\r\n"
    "Lumber  999 pieces";

char const gText_Carpenter_RemodelWindow[] =
    "Remodel Window";

char const gText_Carpenter_Rebuild[] =
    "Rebuild.";

char const gText_Carpenter_RemodelDoghouse[] =
    "Remodel Doghouse";

char const gText_Carpenter_RemodelMailbox[] =
    "New Mailbox";

char const gText_Carpenter_SquareWindowWithShutters[] =
    "Sq. Window w/ Scr";

char const gText_Carpenter_WindowCost[] =
    "Gold    25,000G\r\n"
    "Lumber  300 pieces";

char const gText_Carpenter_SquareWindowWithoutShutters[] =
    "Sq. Window w/o Scr";

char const gText_Carpenter_RoundWindow[] =
    "Round Window";

char const gText_Carpenter_RedDoghouse[] =
    "Red Doghouse";

char const gText_Carpenter_DoghouseCost[] =
    "Gold    20,000G\r\n"
    "Lumber  500 pieces";

char const gText_Carpenter_BlueDoghouse[] =
    "Blue Doghouse";

char const gText_Carpenter_StrangeDoghouse[] =
    "Strange Doghouse";

char const gText_Carpenter_RedMailbox[] =
    "Red Mailbox";

char const gText_Carpenter_MailboxCost[] =
    "Gold    10,000G\r\n"
    "Lumber  200 pieces";

char const gText_Carpenter_BlueMailbox[] =
    "Blue Mailbox";

char const gText_Carpenter_StrangeMailbox[] =
    "Strange Mailbox";

#elif defined(FOMT_TEXT_CARPENTER_DIALOGUE)

char const gText_Carpenter_RebuildRequirements[] ALIGN(4) =
    "What you need to rebuild:\r\n";

char const gText_Carpenter_InsufficientGold[] =
    "You don't have enough gold.{Press}";

char const gText_Carpenter_LumberBinFull[] =
    "Your Woodbin is \r\n"
    "already full, you know.{Press}";

char const gText_Carpenter_LumberHeader[] =
    "Lumber\r\n"
    "\r\n";

char const gText_Carpenter_EquipmentFull[] =
    "You can't hold anything\r\n"
    "more, you know.{Press}";

char const gText_Carpenter_GoldenLumberHeader[] =
    "Golden Lumber\r\n"
    "\r\n";

char const gText_Carpenter_CannotAcceptAnotherJob[] =
    "I won't take on another job\r\n"
    "until I finish the first \r\n"
    "one. That's how I work.{Press}";

char const gText_Carpenter_InsufficientLumber[] =
    "You don't have enough \r\n"
    "Lumber.{Press}";

char const gText_Carpenter_ThreeDayConfirmation[] =
    "It'll take 3 days to\r\n"
    "complete. Are you sure?{Press}";

char const gText_Carpenter_NeedAnythingElse[] =
    "Don't you need\r\n"
    "anything else?{Press}";

char const gText_Carpenter_AreYouSureNow[] =
    "Are you sure now?{Press}";

char const gText_Carpenter_SameCurrentShape[] =
    "You sure you don't want\r\n"
    "to change it?{Press}";

char const gText_Carpenter_StoreLumber[] =
    "I'll put the Lumber in the \r\n"
    "Wood bin, then!{Press}";

char const gText_Carpenter_DeliveryAll[] =
    "Thanks. You can't hold\r\n"
    "anything else, so I'll\r\n"
    "deliver it to your home.{Press}";

char const gText_Carpenter_DeliverySome[] =
    "Thanks. You can't hold\r\n"
    "some of these, so I'll\r\n"
    "deliver them to your home.{Press}";

char const gText_Carpenter_PurchaseComplete[] =
    "Much obliged!{Press}";

char const gText_Carpenter_Build[] =
    "Build";

char const gText_Carpenter_DontBuild[] =
    "Don't build";

char const gText_Carpenter_Upgrade[] =
    "Upgrade";

char const gText_Carpenter_DontUpgrade[] =
    "Don't upgrade";

char const gText_Carpenter_StartUpgradeTomorrow[] =
    "Alright, I'll start the \r\n"
    "upgrade tomorrow, then.{Press}";

char const gText_Carpenter_ConfirmUpgrade[] =
    "Are you sure?{Press}";

char const gText_Carpenter_NeedAnythingMore[] =
    "Need anything more?{Press}";

#else
#error "Select one carpenter text fragment before including this file."
#endif
