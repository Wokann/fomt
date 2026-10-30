#ifndef SCROLL_STATE_HH
#define SCROLL_STATE_HH

#include "prelude.h"
#include "hardware_linked_list.hh"
#include "utility/container_algorithms.hh"
#include <stdlib.h>

#pragma interface "scroll_state.hh"

struct HardwareDisplayState;

// One CPU-side tilemap row: 32 halfword entries, matching a BG screen block.
struct ScrollBufferRow {
    u16 tiles[32];
    u16 & operator[](u32 column) { return tiles[column]; }
};

struct ScrollBufferRows {
    ScrollBufferRow * first;
    ScrollBufferRow * last;
    // Native construction leaves this legacy container word untouched.
    u32 unk_08;
    ScrollBufferRow * capacity_end;

    ScrollBufferRow * Begin() { return first; }
    ScrollBufferRow & operator[](u32 index) { return *(Begin() + index); }
    ~ScrollBufferRows()
    {
        typedef __type_traits<ScrollBufferRow>::has_trivial_destructor Trait;
        destroy_range_inl(first, last, Trait());
        if (first != nullptr) free(first);
    }
private:
    ScrollBufferRows();
};

struct ScrollBufferUploadCommand : HardwareLinkBase {
    ScrollBufferUploadCommand() {}
    virtual ~ScrollBufferUploadCommand() {}
    virtual bool Run();

    bool IsQueued() const { return previous_slot != nullptr; }
    void SetTransfers(void const * first, void * target, u32 bytes,
        void const * second, void * other_target, u32 other_bytes)
    {
        first_source = first;
        first_destination = target;
        first_bytes = bytes;
        second_source = second;
        second_destination = other_target;
        second_bytes = other_bytes;
    }

    void const * first_source;
    void * first_destination;
    u32 first_bytes;
    void const * second_source;
    void * second_destination;
    u32 second_bytes;
};

// The constructor and position update retain their named native bodies.
struct ScrollState {
    ScrollState(u32 count, HardwareLinkedList * commands,
        HardwareDisplayState * display, u8 * destination);
    HardwareLinkedList * commands;
    i16 height;
    i16 last_rendered_position;
    i16 hardware_position;
    i16 scroll_offset;
    i16 position;
    i16 bottom_limit;
    u8 * destination;
    HardwareDisplayState * display;
    ScrollBufferRows rows;
    ScrollBufferUploadCommand upload;
};

typedef char ScrollBufferRowSize[sizeof(ScrollBufferRow) == 64 ? 1 : -1];
typedef char ScrollBufferRowsSize[sizeof(ScrollBufferRows) == 16 ? 1 : -1];
typedef char ScrollStateSize[sizeof(ScrollState) == 0x4C ? 1 : -1];
typedef char ScrollStatePosition[offsetof(ScrollState, position) == 0xC ? 1 : -1];
typedef char ScrollStateRows[offsetof(ScrollState, rows) == 0x18 ? 1 : -1];
typedef char ScrollStateUpload[offsetof(ScrollState, upload) == 0x28 ? 1 : -1];
typedef char ScrollCommandSize[sizeof(ScrollBufferUploadCommand) == 36 ? 1 : -1];

EXTERN_C

void UploadScrollBufferRows(ScrollState * state, i32 first, i32 last);
void SetScrollPosition(ScrollState * state, i16 position);
void ResetScrollPosition(ScrollState * state, u16 position);
void ClearScrollBuffer(ScrollState * state);
void SetScrollBottomLimit(ScrollState * state, i16 limit);

EXTERN_C_END

#endif // SCROLL_STATE_HH
