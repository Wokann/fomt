#ifndef SUPERMARKET_TEXT_HH
#define SUPERMARKET_TEXT_HH

#include "prelude.h"

// The two shop directories are contiguous pairs of a tool identifier and its
// price.  The final zero pair in the additional directory is an original
// sentinel and remains part of the table.
struct SupermarketCatalogEntry
{
    u32 tool_id;
    u32 price;
};

extern SupermarketCatalogEntry const gSupermarketCropSeedCatalog[];
extern SupermarketCatalogEntry const gSupermarketAdditionalSeedCatalog[];

extern char const gText_Supermarket_EquipmentCapacityFull[];
extern char const gText_Supermarket_BlankLinePair[];
extern char const gText_Supermarket_InsufficientGold[];
extern char const gText_Supermarket_ThankYou[];
extern char const gText_Supermarket_PurchaseConfirmation[];
extern char const gText_Supermarket_PurchaseMorePrompt[];
extern char const gText_Supermarket_EquipmentDelivery[];
extern char const gText_Supermarket_SeedDelivery[];
extern char const gText_Supermarket_SeedPurchaseConfirmation[];
extern char const gCppRuntimeBadAlloc_SupermarketTrailer[];

#if defined(REGION_JP)
extern char const gText_Supermarket_EquipmentDeliveryPartial[];
extern char const gText_Supermarket_SeedDeliveryPartial[];
#else
// The US ROM reuses this one object for both shop flows.
extern char const gText_Supermarket_DeliveryPartial[];
#endif

#endif // SUPERMARKET_TEXT_HH
