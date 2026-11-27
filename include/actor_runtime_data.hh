#ifndef ACTOR_RUNTIME_DATA_HH
#define ACTOR_RUNTIME_DATA_HH

#include "actor.hh"

struct Unk_Actor_0809BFE8 : Actor
{
    Unk_Actor_0809BFE8();

    u32 unk_08_0 : 7;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
};

// Payload passed to func_0809C0C8 by the wild dog's two reaction handlers.
// Only the bit layout is known from the handlers themselves: the low half is a
// randomised timer (240..359), bits 16..22 are a constant 0x3C (60), bit 23
// separates the tool-hit reaction from the dog-attack reaction, and the top
// byte is always zero.
union WildDogReactionPayload
{
    u32 raw;
    struct Bits
    {
        u32 timer : 16;
        u32 constant : 7;
        u32 kind : 1;
        u32 reserved : 8;
    } bits;
};

struct Unk_Actor_0809C0AC
{
    u32 unk_00;
    u32 unk_04;
};


extern "C" {
unsigned int func_0809C060(Unk_Actor_0809BFE8 const & self);
void func_0809C068(Unk_Actor_0809BFE8 & self, int amount);
void func_0809C098(Unk_Actor_0809BFE8 & self, u32 const & value);
void func_0809C0A0(Unk_Actor_0809BFE8 & self, u32 const & value);
void func_0809C0AC(Unk_Actor_0809BFE8 & self, Unk_Actor_0809C0AC const & value);
void func_0809C0BC(Unk_Actor_0809BFE8 & self, u32 const & value);
void func_0809C0C8(Unk_Actor_0809BFE8 & self, u32 const & value);

// Reset the location to MAP_NONE at (0, 0), select state 0, and restore the
// low seven-bit value to 100. Other payload words and high bits are retained.
void ResetActorRuntimeState(Unk_Actor_0809BFE8 & self);
}


#endif // ACTOR_RUNTIME_DATA_HH
