#ifndef CLINIC_TEXT_HH
#define CLINIC_TEXT_HH

#include "prelude.h"

struct ClinicCatalogEntry
{
    u32 food_id;
    u32 price;
};

#define CLINIC_CATALOG SECTION(".rodata.clinic_catalog")
#define CLINIC_TEXT SECTION(".rodata.clinic_text")

extern ClinicCatalogEntry const gClinicCatalog[];

extern char const gText_Clinic_InventoryFull[];
extern char const gText_Clinic_BlankLinePair[];
extern char const gText_Clinic_InsufficientGold[];
extern char const gText_Clinic_NoAdditionalPurchase[];
extern char const gText_Clinic_NoPurchaseRestAdvice[];
extern char const gText_Clinic_PurchaseMorePrompt[];
extern char const gText_Clinic_Delivery[];
extern char const gText_Clinic_DeliveryPartial[];
extern char const gText_Clinic_PurchaseComplete[];

#endif // CLINIC_TEXT_HH
