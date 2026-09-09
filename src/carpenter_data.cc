#include "carpenter_text.hh"

#if defined(REGION_JP)
#include "data/text/jp/carpenter_menu.cc"
#else
#include "data/text/us/carpenter_menu.cc"
#endif

CarpenterCatalogEntry const gCarpenterCatalog[] = {
    { gText_Carpenter_Lumber, 50, 0, 0, nullptr },
    { gText_Carpenter_GoldenLumber, 100000, 0, 0, nullptr },
    { gText_Carpenter_HouseExtension, 3000, 200, 1, gText_Carpenter_HouseExtensionFirstCost },
    { gText_Carpenter_HouseExtension, 10000, 700, 1, gText_Carpenter_HouseExtensionSecondCost },
    { gText_Carpenter_AddBathtub, 30000, 580, 1, gText_Carpenter_BathtubCost },
    { gText_Carpenter_ExpandChickenCoop, 5000, 420, 2, gText_Carpenter_ChickenCoopCost },
    { gText_Carpenter_ExpandBarn, 6800, 500, 3, gText_Carpenter_BarnCost },
    { gText_Carpenter_BuildVacationHouse, 100000000, 999, 4, gText_Carpenter_VacationHouseCost },
    { gText_Carpenter_RemodelWindow, 0, 0, 0, gText_Carpenter_Rebuild },
    { gText_Carpenter_RemodelDoghouse, 0, 0, 0, gText_Carpenter_Rebuild },
    { gText_Carpenter_RemodelMailbox, 0, 0, 0, gText_Carpenter_Rebuild },
    { gText_Carpenter_SquareWindowWithShutters, 25000, 300, 5, gText_Carpenter_WindowCost },
    { gText_Carpenter_SquareWindowWithoutShutters, 25000, 300, 6, gText_Carpenter_WindowCost },
    { gText_Carpenter_RoundWindow, 25000, 300, 7, gText_Carpenter_WindowCost },
    { gText_Carpenter_RedDoghouse, 20000, 500, 11, gText_Carpenter_DoghouseCost },
    { gText_Carpenter_BlueDoghouse, 20000, 500, 12, gText_Carpenter_DoghouseCost },
    { gText_Carpenter_StrangeDoghouse, 20000, 500, 13, gText_Carpenter_DoghouseCost },
    { gText_Carpenter_RedMailbox, 10000, 200, 8, gText_Carpenter_MailboxCost },
    { gText_Carpenter_BlueMailbox, 10000, 200, 9, gText_Carpenter_MailboxCost },
    { gText_Carpenter_StrangeMailbox, 10000, 200, 10, gText_Carpenter_MailboxCost },
};

#include "data/text/common/carpenter.cc"

#if defined(REGION_JP)
#include "data/text/jp/carpenter_dialogue.cc"
#else
#include "data/text/us/carpenter_dialogue.cc"
#endif

char const gCppRuntimeBadAlloc_Carpenter[] ALIGN(4) =
    "bad_alloc";
