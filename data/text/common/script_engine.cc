#include "script_engine.hh"

#if defined(FOMT_SCRIPT_ENGINE_TEXT_INVALID_STRING_ID)

// This is a directly addressed eight-byte error field in both ROMs.
char const gText_AScriptEngine_InvalidStringId[8]
    SECTION(".rodata.script_engine_string_error") ALIGN(1) =
    "Error";

#elif defined(FOMT_SCRIPT_ENGINE_TEXT_UI_ERROR)

// This distinct copy is physically separated by the localized data block.
char const gText_ScriptEngineUi_Error[]
    SECTION(".rodata.script_engine_ui_error") ALIGN(1) =
    "Error";

#else
#error "Include this file through src/script_engine.cc with a text partition."
#endif
