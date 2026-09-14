#include "clinic_data.hh"

#include "item.hh"

ClinicCatalogEntry const gClinicCatalog[] = {
    { ITEM_FOOD_BODIGIZER, 500 },
    { ITEM_FOOD_BODIGIZER_XL, 1000 },
    { ITEM_FOOD_TURBOJOLT, 1000 },
    { ITEM_FOOD_TURBOJOLT_XL, 2000 },
};

#include FOMT_TEXT_INCLUDE(clinic_data_1.cc)
#include FOMT_TEXT_INCLUDE(clinic_data_2.cc)
