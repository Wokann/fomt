#ifndef UI_TEXT_STREAM_HH
#define UI_TEXT_STREAM_HH

#include "prelude.h"
#include "utility/fixed_str.hh"

struct UiTextInput;
struct UiTextOutput;
struct ScriptTextVariableStore;

// A calculation value is wider than the stored Q8 clock: count a carry
// before narrowing the saved progress back to sixteen bits.
struct UiTextStreamClockValue
{
    int raw;
    explicit UiTextStreamClockValue(int input) : raw(input) {}
    int Whole() const { return raw / 0x100; }
};

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


EXTERN_C
void SetUiTextStreamText(UiTextStream *, char const *, ScriptTextVariableStore *);
void SetUiTextStreamSpeed(UiTextStream *, u16);
u32 UpdateUiTextStream(UiTextStream *, UiTextOutput *, UiTextInput *);
// Advance Q8 progress and return the number of whole character ticks crossed.
int AdvanceUiTextStreamClock(UiTextStream *);
EXTERN_C_END

#endif // UI_TEXT_STREAM_HH
