#include "ui_error_text.hh"

// ScriptEngineUi keeps this copy at its own historical ROM address.
char const gText_ScriptEngineUi_Error[] SECTION(".rodata.script_engine_ui_error") =
    "Error";

char const gText_Fallback_Error[] SECTION(".rodata.ui_error") =
    "Error";
