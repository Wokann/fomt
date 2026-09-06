#include "script_engine_text.hh"

// This fixed field includes the original two trailing padding bytes.
char const gText_AScriptEngine_InvalidStringId[8] SECTION(".rodata.script_engine_string_error") ALIGN(1) =
    "Error";
