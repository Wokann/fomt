#include "script_engine.hh"

char const gText_AScriptEngine_InvalidStringId[] =
    "Error";

char const gCppRuntimeBadAlloc_ScriptEngineUiPrefix[] ALIGN(4) =
    "bad_alloc";

char const gText_ScriptEngineUi_Error[] ALIGN(4) =
    "Error";

char const gText_ScriptEngineUi_FallbackNone[] ALIGN(4) =
#if defined(REGION_JP)
    "なし";
#else
    "N/A ";
#endif
