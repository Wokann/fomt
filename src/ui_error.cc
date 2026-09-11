#include "ui_error.hh"

#define FOMT_UI_ERROR_TEXT_FALLBACK_ERROR
#include "data/text/common/ui_error.cc"
#undef FOMT_UI_ERROR_TEXT_FALLBACK_ERROR

#if defined(REGION_JP)
#define FOMT_UI_ERROR_TEXT_FALLBACK_NONE
#include FOMT_TEXT_INCLUDE(ui_error.cc)
#undef FOMT_UI_ERROR_TEXT_FALLBACK_NONE
#else
#define FOMT_UI_ERROR_TEXT_FALLBACK_NONE
#include FOMT_TEXT_INCLUDE(ui_error.cc)
#undef FOMT_UI_ERROR_TEXT_FALLBACK_NONE
#endif

// This halfword table is selected by an unresolved native caller.
u16 const gUnk_080F19AE[] = {
    0x0427, 0x0423, 0x0000,
};

#define FOMT_UI_ERROR_TEXT_RUNTIME
#include "data/text/common/ui_error.cc"
#undef FOMT_UI_ERROR_TEXT_RUNTIME
