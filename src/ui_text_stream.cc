#include "ui_text_stream.hh"
#include "ui_state.hh"

#include <string.h>

UiTextStream::UiTextStream()
    : phase(0), speed(0x100), progress(0), cursor(nullptr),
      variables(nullptr), replacement_cursor(nullptr) {}

void SetUiTextStreamText(UiTextStream * stream, char const * text,
    ScriptTextVariableStore * variables)
{
    stream->cursor = text;
    stream->variables = variables;
    stream->replacement_cursor = nullptr;
    stream->replacement[0] = '\0';
    stream->phase = text != nullptr;
    stream->progress = 0;
}

void SetUiTextStreamSpeed(UiTextStream * stream, u16 speed)
{
    stream->speed = speed;
}

u32 UpdateUiTextStream(UiTextStream * stream, UiTextOutput * output, UiTextInput * input)
{
    bool fast = false;
    int remaining = AdvanceUiTextStreamClock(stream);
    if (stream->phase == 2) {
        if (!input->Resume())
            remaining = 0;
        else
            stream->phase = 1;
    } else {
        bool enabled = false;
        int requested = input->Fast();
        if (stream->speed == 0)
            requested |= 1;
        if (requested != 0)
            enabled = true;
        fast = enabled;
    }
    char const * cursor = stream->replacement_cursor;
    if (cursor == nullptr)
        cursor = stream->cursor;
    u32 code = 0;
    while (cursor != nullptr && (fast || remaining != 0) && !output->ShouldStop()) {
        u32 byte = static_cast<u8>(*cursor++);
        switch (byte) {
        default:
            if (byte <= 0x1F)
                continue;
            code |= byte;
            if (output->Emit(code))
                code = 0;
            else {
                if (stream->variables != nullptr && stream->replacement_cursor == nullptr) {
                    UiTextSubstitution result = stream->variables->Lookup(code);
                    if (result.found) {
                        code = 0;
                        char * buffer = &stream->replacement[0];
                        strcpy(buffer, result.text);
                        stream->cursor = cursor;
                        stream->replacement_cursor = buffer;
                        cursor = buffer;
                        continue;
                    }
                    code <<= 8;
                } else
                    code <<= 8;
                continue;
            }
            if (remaining != 0)
                --remaining;
            break;
        case '\0':
            if (stream->replacement_cursor != nullptr) {
                stream->replacement_cursor = nullptr;
                cursor = stream->cursor;
                continue;
            }
            cursor = nullptr;
            goto finished;
        case '\r':
            output->CarriageReturn();
            if (remaining != 0)
                --remaining;
            break;
        case '\n':
            output->LineFeed();
            if (remaining != 0)
                --remaining;
            break;
        case 0x0C: // \p: next page
            output->NextPage();
            if (remaining != 0)
                --remaining;
            break;
        case 0x05: // {Press}
            if (input->WaitForInput()) {
                stream->phase = 2;
                goto finished;
            }
            continue;
        }
    }
finished:
    if (stream->replacement_cursor != nullptr)
        stream->replacement_cursor = cursor;
    else {
        stream->cursor = cursor;
        if (cursor == nullptr)
            stream->phase = 0;
    }
    return stream->phase;
}

int AdvanceUiTextStreamClock(UiTextStream * stream)
{
    UiTextStreamClockValue previous(stream->progress);
    UiTextStreamClockValue next(previous.raw + stream->speed);
    int fraction = next.raw & 0xFF;
    int stored = 0;
    if (fraction != 0)
        stored = next.raw;
    stream->progress = stored;
    return next.Whole() - previous.Whole();
}
