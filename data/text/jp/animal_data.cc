#include "animal_data.hh"

#if defined(FOMT_ANIMAL_DATA_TEXT_MAIN_REGION)

char const gText_AnimalDataFallbackNone[] =
    "なし";

#else
#error "Include this file through src/animal_data.cc with a text partition."
#endif
