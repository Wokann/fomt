#include "clinic_text.hh"

#include "item.hh"

ClinicCatalogEntry const gClinicCatalog[] = {
    { ITEM_FOOD_BODIGIZER, 500 },
    { ITEM_FOOD_BODIGIZER_XL, 1000 },
    { ITEM_FOOD_TURBOJOLT, 1000 },
    { ITEM_FOOD_TURBOJOLT_XL, 2000 },
};

#if defined(REGION_JP)
#include FOMT_TEXT_INCLUDE(clinic.cc)
#else
#include FOMT_TEXT_INCLUDE(clinic.cc)
#endif
