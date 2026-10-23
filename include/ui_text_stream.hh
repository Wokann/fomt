#ifndef UI_TEXT_STREAM_HH
#define UI_TEXT_STREAM_HH

#include "prelude.h"
#include "utility/fixed_str.hh"

struct UiTextInput;
struct UiTextOutput;
struct ScriptTextVariableStore;

// Native text reader: 0 is idle, 1 reads text and 2 waits for input.
// The parser temporarily switches from cursor to replacement_cursor while
// consuming a substituted value stored in the inline 32-byte buffer.
struct UiTextStream
{
    u32 phase;
    u16 speed;
    u16 progress;
    char const * cursor;
    ScriptTextVariableStore * variables;
    char const * replacement_cursor;
    FixedStr<31> replacement;

    UiTextStream();
};

typedef char UiTextStreamSizeCheck[sizeof(UiTextStream) == 0x34 ? 1 : -1];
typedef char UiTextStreamSpeedCheck[offsetof(UiTextStream, speed) == 4 ? 1 : -1];
typedef char UiTextStreamProgressCheck[offsetof(UiTextStream, progress) == 6 ? 1 : -1];
typedef char UiTextStreamCursorCheck[offsetof(UiTextStream, cursor) == 8 ? 1 : -1];
typedef char UiTextStreamVariablesCheck[offsetof(UiTextStream, variables) == 0x0C ? 1 : -1];
typedef char UiTextStreamReplacementCursorCheck[offsetof(UiTextStream, replacement_cursor) == 0x10 ? 1 : -1];
typedef char UiTextStreamReplacementCheck[offsetof(UiTextStream, replacement) == 0x14 ? 1 : -1];

EXTERN_C
void SetUiTextStreamText(UiTextStream *, char const *, ScriptTextVariableStore *);
void SetUiTextStreamSpeed(UiTextStream *, u16);
u32 UpdateUiTextStream(UiTextStream *, UiTextOutput *, UiTextInput *);
// This dependency keeps its original 44-byte assembly body.
int AdvanceUiTextStreamClock(UiTextStream *);
EXTERN_C_END

#endif // UI_TEXT_STREAM_HH
