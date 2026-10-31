#ifndef STAFF_CREDITS_HH
#define STAFF_CREDITS_HH

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
extern char const gCppRuntimeBadAlloc_StaffCredits[];


#include "game_scene.hh"
#include "hardware_bootstrap.hh"
#include "hardware_input.hh"
#include "hardware_music_player.hh"
#include "font_draw.hh"
#include "smart_ptr.hh"
#pragma interface "staff_credits.hh"

struct StaffCreditsCore : HardwareBootstrap {
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
typedef char StaffCreditsCoreSizeCheck[sizeof(StaffCreditsCore) == 0x730 ? 1 : -1];
typedef char StaffCreditsCoreMusic0Check[offsetof(StaffCreditsCore, music_player_0) == 8 ? 1 : -1];
typedef char StaffCreditsCoreMusic1Check[offsetof(StaffCreditsCore, music_player_1) == 12 ? 1 : -1];
typedef char StaffCreditsCoreTilesCheck[offsetof(StaffCreditsCore, text_tiles) == 0x14 ? 1 : -1];
typedef char StaffCreditsCore714Check[offsetof(StaffCreditsCore, unk_714) == 0x714 ? 1 : -1];
typedef char StaffCreditsCore71CCheck[offsetof(StaffCreditsCore, unk_71C) == 0x71C ? 1 : -1];
typedef char StaffCreditsCoreLinesCheck[offsetof(StaffCreditsCore, lines) == 0x72C ? 1 : -1];

struct StaffCreditsScene : AScene {
    StaffCreditsScene(SceneTransitionOwner next);
    virtual ~StaffCreditsScene();
    virtual SceneTransitionOwner Run();
    SmartPtr<StaffCreditsCore> core;
    SceneTransitionOwner continuation;
};
typedef char StaffCreditsSceneSizeCheck[sizeof(StaffCreditsScene) == 12 ? 1 : -1];
typedef char StaffCreditsSceneCoreCheck[offsetof(StaffCreditsScene, core) == 4 ? 1 : -1];
typedef char StaffCreditsSceneContinuationCheck[offsetof(StaffCreditsScene, continuation) == 8 ? 1 : -1];

struct StaffCreditsTransition : SceneTransition {
    StaffCreditsTransition(SceneTransitionOwner next) : continuation(next) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
};
typedef char StaffCreditsTransitionSizeCheck[sizeof(StaffCreditsTransition) == 8 ? 1 : -1];
#pragma implementation

#endif // STAFF_CREDITS_HH
