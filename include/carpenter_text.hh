#ifndef CARPENTER_TEXT_HH
#define CARPENTER_TEXT_HH

#include "prelude.h"

// The original directory contains twenty fixed-width construction options.
// option_id values remain raw until the underlying construction enum is
// decompiled, while the pointer and cost fields reflect their ROM layout.
struct CarpenterCatalogEntry
{
    char const * menu_text;
    u32 gold_cost;
    u32 lumber_cost;
    u32 option_id;
    char const * detail_text;
};

extern char const gText_Carpenter_Lumber[];
extern char const gText_Carpenter_GoldenLumber[];
extern char const gText_Carpenter_HouseExtension[];
extern char const gText_Carpenter_HouseExtensionFirstCost[];
extern char const gText_Carpenter_HouseExtensionSecondCost[];
extern char const gText_Carpenter_AddBathtub[];
extern char const gText_Carpenter_BathtubCost[];
extern char const gText_Carpenter_ExpandChickenCoop[];
extern char const gText_Carpenter_ChickenCoopCost[];
extern char const gText_Carpenter_ExpandBarn[];
extern char const gText_Carpenter_BarnCost[];
extern char const gText_Carpenter_BuildVacationHouse[];
extern char const gText_Carpenter_VacationHouseCost[];
extern char const gText_Carpenter_RemodelWindow[];
extern char const gText_Carpenter_Rebuild[];
extern char const gText_Carpenter_RemodelDoghouse[];
extern char const gText_Carpenter_RemodelMailbox[];
extern char const gText_Carpenter_SquareWindowWithShutters[];
extern char const gText_Carpenter_WindowCost[];
extern char const gText_Carpenter_SquareWindowWithoutShutters[];
extern char const gText_Carpenter_RoundWindow[];
extern char const gText_Carpenter_RedDoghouse[];
extern char const gText_Carpenter_DoghouseCost[];
extern char const gText_Carpenter_BlueDoghouse[];
#if defined(REGION_DE)
extern char const gText_Carpenter_BlueDoghouseCost[];
#endif
extern char const gText_Carpenter_StrangeDoghouse[];
extern char const gText_Carpenter_RedMailbox[];
extern char const gText_Carpenter_MailboxCost[];
extern char const gText_Carpenter_BlueMailbox[];
extern char const gText_Carpenter_StrangeMailbox[];

extern char const gText_Carpenter_RebuildRequirements[];
extern char const gText_Carpenter_InsufficientGold[];
extern char const gText_Carpenter_LumberBinFull[];
extern char const gText_Carpenter_LumberHeader[];
extern char const gText_Carpenter_EquipmentFull[];
extern char const gText_Carpenter_GoldenLumberHeader[];
extern char const gText_Carpenter_CannotAcceptAnotherJob[];
extern char const gText_Carpenter_InsufficientLumber[];
extern char const gText_Carpenter_ThreeDayConfirmation[];
extern char const gText_Carpenter_NeedAnythingElse[];
extern char const gText_Carpenter_AreYouSureNow[];
extern char const gText_Carpenter_SameCurrentShape[];
extern char const gText_Carpenter_StoreLumber[];
extern char const gText_Carpenter_DeliveryAll[];
extern char const gText_Carpenter_DeliverySome[];
extern char const gText_Carpenter_PurchaseComplete[];
extern char const gText_Carpenter_Build[];
extern char const gText_Carpenter_DontBuild[];
extern char const gText_Carpenter_Upgrade[];
extern char const gText_Carpenter_DontUpgrade[];
extern char const gText_Carpenter_StartUpgradeTomorrow[];
#if defined(REGION_US) || defined(REGION_EU)
extern char const gText_Carpenter_ConfirmUpgrade[];
#endif
extern char const gText_Carpenter_NeedAnythingMore[];
extern char const gText_Carpenter_InitialPageBreak[];
extern char const gCppRuntimeBadAlloc_Carpenter[];

extern CarpenterCatalogEntry const gCarpenterCatalog[];

#endif // CARPENTER_TEXT_HH
