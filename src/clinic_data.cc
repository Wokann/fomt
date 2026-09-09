#include "clinic_text.hh"

#include "item.hh"

ClinicCatalogEntry const gClinicCatalog[] = {
    { FOOD_BODIGIZER, 500 },
    { FOOD_BODIGIZER_XL, 1000 },
    { FOOD_TURBOJOLT, 1000 },
    { FOOD_TURBOJOLT_XL, 2000 },
};

#if defined(REGION_JP)
#include "data/text/jp/clinic.cc"
#else
#include "data/text/us/clinic.cc"
#endif
