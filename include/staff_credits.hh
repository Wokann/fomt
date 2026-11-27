#ifndef STAFF_CREDITS_HH
#define STAFF_CREDITS_HH

#include "scene.hh"
#include "fomt_constants.hh"

#include "prelude.h"

// fomt-text derives each aligned storage field and shared pointer from the
// visible credit rows. No baseline ROM is needed during compilation.
template <unsigned int Size>
struct StaffCreditsTextStorage
{
    char bytes[Size];
};

// Native scrolling code walks this null-terminated row-pointer table.
extern char const * const gStaffCreditsLines[];

#include "hardware_context.hh"
#include "hardware_input.hh"
#include "hardware_sound.hh"
#include "font_draw.hh"
#include "smart_ptr.hh"
#pragma interface "staff_credits.hh"

struct StaffCreditsCore;

struct StaffCreditsScene : AScene {
    StaffCreditsScene(SceneTransitionOwner next);
    virtual ~StaffCreditsScene();
    virtual SceneTransitionOwner Run();
    SmartPtr<StaffCreditsCore> core;
    SceneTransitionOwner continuation;
};

struct StaffCreditsCore : HardwareContext {
    StaffCreditsCore();
    SceneTransitionOwner Run();
    HardwareMusicPlayerSlot music_player_0;
    HardwareMusicPlayerSlot music_player_1;
    u32 unk_10;
    // The renderer clears 28 x 2 4bpp tiles (eight words per tile).
    u32 text_tiles[28 * 2 * 8];
    i16 unk_714;
    u16 unk_716;
    u16 unk_718;
    u32 unk_71C;
    u32 unk_720;
    u32 unk_724;
    bool unk_728;
    u16 unk_72A;
    char const * const * lines;
};



#endif // STAFF_CREDITS_HH
