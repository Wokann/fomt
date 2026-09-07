#ifndef ACTOR_STATE_HH
#define ACTOR_STATE_HH

#include "prelude.h"

// Three parallel six-entry state arrays used by the actor-state helpers.
struct ActorStateSlots
{
    u8 unk_00[6];
    u8 unk_06[6];
    u8 unk_0C[6];
};

extern u8 const gActorStateMaxValues[];

// Known bit positions in an otherwise not-yet-modeled actor-state object.
struct ActorStateFlagBits
{
    u8 unk_000[0x624];
    bool flag_624_0 : 1;
    bool flag_624_1 : 1;
    bool flag_624_2 : 1;
    bool flag_624_3 : 1;
    bool flag_624_4 : 1;
    bool flag_624_5 : 1;
    bool flag_624_6 : 1;
    bool flag_624_7 : 1;
    bool flag_625_0 : 1;
    bool flag_625_1 : 1;
    bool flag_625_2 : 1;
    bool flag_625_3 : 1;
    bool flag_625_4 : 1;
    bool flag_625_5 : 1;
    bool flag_625_6 : 1;
    bool flag_625_7 : 1;
    bool flag_626_0 : 1;
    bool flag_626_1 : 1;
    bool flag_626_2 : 1;
    bool flag_626_3 : 1;
    bool flag_626_4 : 1;
    bool flag_626_5 : 1;
    bool unk_626_6 : 1;
    bool unk_626_7 : 1;
};

// A four-byte header followed by rows of 28 two-byte cells.  The meanings of
// the header and the second byte in each cell are not known yet.
struct ActorStateGrid
{
    u32 unk_00;
    u8 cells[1];
};

#endif // ACTOR_STATE_HH
