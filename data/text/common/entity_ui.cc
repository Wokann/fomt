#include "entity_ui.hh"

#if defined(FOMT_ENTITY_UI_TEXT_BEFORE_OFFSETS)

char const gCppRuntimeBadAlloc_EntityUiBeforeOffsets[] =
    "bad_alloc";
char const gCppRuntimeError_EntityUiBeforeOffsets[] =
    "Error";

#elif defined(FOMT_ENTITY_UI_TEXT_AFTER_OFFSETS)

char const gCppRuntimeBadAlloc_EntityUiAfterOffsets[] =
    "bad_alloc";
char const gCppRuntimeError_EntityUiAfterOffsets[] =
    "Error";

#elif defined(FOMT_ENTITY_UI_TEXT_FIRST)

char const gCppRuntimeBadAlloc_EntityUiFirst[] =
    "bad_alloc";
char const gCppRuntimeError_EntityUiFirst[] =
    "Error";

#elif defined(FOMT_ENTITY_UI_TEXT_SECOND)

char const gCppRuntimeBadAlloc_EntityUiSecond[] =
    "bad_alloc";
char const gCppRuntimeError_EntityUiSecond[] =
    "Error";

#elif defined(FOMT_ENTITY_UI_TEXT_THIRD)

char const gCppRuntimeBadAlloc_EntityUiThird[] =
    "bad_alloc";
char const gCppRuntimeError_EntityUiThird[] =
    "Error";

#elif defined(FOMT_ENTITY_UI_TEXT_FOURTH)

char const gCppRuntimeBadAlloc_EntityUiFourth[] =
    "bad_alloc";
char const gCppRuntimeError_EntityUiFourth[] =
    "Error";

#elif defined(FOMT_ENTITY_UI_TEXT_FIFTH)

char const gCppRuntimeBadAlloc_EntityUiFifth[] =
    "bad_alloc";

#elif defined(FOMT_ENTITY_UI_TEXT_SIXTH_TO_NINTH)

char const gCppRuntimeBadAlloc_EntityUiSixth[] =
    "bad_alloc";
char const gCppRuntimeBadAlloc_EntityUiSeventh[] =
    "bad_alloc";
char const gCppRuntimeBadAlloc_EntityUiEighth[] =
    "bad_alloc";
char const gCppRuntimeBadAlloc_EntityUiNinth[] =
    "bad_alloc";

#elif defined(FOMT_ENTITY_UI_TEXT_TENTH)

char const gCppRuntimeBadAlloc_EntityUiTenth[] =
    "bad_alloc";

#else
#error "Include this file through src/entity_ui.cc with a text partition."
#endif
