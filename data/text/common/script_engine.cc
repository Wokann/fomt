#include "script_engine.hh"

#ifndef FOMT_SCRIPT_ENGINE_TEXT_ATTRIBUTE
#define FOMT_SCRIPT_ENGINE_TEXT_ATTRIBUTE
#define FOMT_SCRIPT_ENGINE_TEXT_ATTRIBUTE_LOCAL
#endif

char const gText_AScriptEngine_InvalidStringId[] FOMT_SCRIPT_ENGINE_TEXT_ATTRIBUTE =
    "Error";

char const gCppRuntimeBadAlloc_ScriptEngineUiPrefix[] ALIGN(4) FOMT_SCRIPT_ENGINE_TEXT_ATTRIBUTE =
    "bad_alloc";

char const gText_ScriptEngineUi_Error[] ALIGN(4) FOMT_SCRIPT_ENGINE_TEXT_ATTRIBUTE =
    "Error";

char const gText_ScriptEngineUi_FallbackNone[] ALIGN(4) FOMT_SCRIPT_ENGINE_TEXT_ATTRIBUTE =
#if defined(REGION_JP)
    "なし";
#else
    "N/A ";
#endif

#ifdef FOMT_SCRIPT_ENGINE_TEXT_ATTRIBUTE_LOCAL
#undef FOMT_SCRIPT_ENGINE_TEXT_ATTRIBUTE_LOCAL
#undef FOMT_SCRIPT_ENGINE_TEXT_ATTRIBUTE
#endif
