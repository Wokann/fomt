#include "animal_data.hh"

#if defined(FOMT_ANIMAL_DATA_TEXT_MAIN_COMMON)

char const gCppRuntimeBadAlloc_AnimalDataFirst[] =
    "bad_alloc";
char const gCppRuntimeBadAlloc_AnimalDataSecond[] =
    "bad_alloc";
char const gCppRuntimeError_AnimalData[] =
    "Error";

#elif defined(FOMT_ANIMAL_DATA_TEXT_TRAILER_COMMON)

char const gCppRuntimeBadAlloc_AnimalDataThird[] =
    "bad_alloc";
char const gCppRuntimeError_AnimalDataSecond[] =
    "Error";

#else
#error "Include this file through src/animal_data.cc with a text partition."
#endif
