#ifndef INTRO_STORY_SCENE_HH
#define INTRO_STORY_SCENE_HH

#include "hardware_bootstrap.hh"
#include "hardware_music_player.hh"
#include "ui_state.hh"

struct GameStateSaveImage;

// Variable context embedded in the childhood story. Its local selector is
// 0xFF; do not confuse this with a complete encoded control sequence.
struct IntroStoryTextVariables : ScriptTextVariableStore
{
    char const * player_name;
    IntroStoryTextVariables() : player_name(nullptr) {}
    virtual ~IntroStoryTextVariables() {}
    virtual UiTextSubstitution Lookup(u32 code);
};

typedef char IntroStoryTextVariablesSizeCheck[sizeof(IntroStoryTextVariables) == 8 ? 1 : -1];
typedef char IntroStoryPlayerNameOffsetCheck[offsetof(IntroStoryTextVariables, player_name) == 4 ? 1 : -1];

// Verified native layout, not yet a complete C++ polymorphic scene class.
struct IntroStorySceneCore : HardwareBootstrap
{
    GameStateSaveImage * saved;
    u32 unk_0C;
    UiStateOwner * ui_state;
    HardwareMusicPlayerSlot music_players[3];
    // Initialization leaves this not-yet-decoded storage untouched.
    u8 unk_20[0x6400];
    u16 unk_6420;
    u16 unk_6422;
    u16 unk_6424;
    u16 unk_6426;
    IntroStoryTextVariables variables;
private:
    IntroStorySceneCore();
};

struct IntroStorySceneCoreVTable
{
    void const * metadata[2];
    void (*destroy)(IntroStorySceneCore *, u32);
};
extern IntroStorySceneCoreVTable const gIntroStorySceneCoreVTable;

typedef char IntroStoryCoreSizeCheck[sizeof(IntroStorySceneCore) == 0x6430 ? 1 : -1];
typedef char IntroStoryUiOffsetCheck[offsetof(IntroStorySceneCore, ui_state) == 0x10 ? 1 : -1];
typedef char IntroStoryVariablesOffsetCheck[offsetof(IntroStorySceneCore, variables) == 0x6428 ? 1 : -1];
typedef char IntroStorySavedOffsetCheck[offsetof(IntroStorySceneCore, saved) == 8 ? 1 : -1];
typedef char IntroStoryMusicOffsetCheck[offsetof(IntroStorySceneCore, music_players) == 0x14 ? 1 : -1];
typedef char IntroStoryUnknown20OffsetCheck[offsetof(IntroStorySceneCore, unk_20) == 0x20 ? 1 : -1];
typedef char IntroStoryControlOffsetCheck[offsetof(IntroStorySceneCore, unk_6420) == 0x6420 ? 1 : -1];
typedef char IntroStoryVTableSizeCheck[sizeof(IntroStorySceneCoreVTable) == 12 ? 1 : -1];
typedef char IntroStoryDestroySlotCheck[offsetof(IntroStorySceneCoreVTable, destroy) == 8 ? 1 : -1];

EXTERN_C
IntroStorySceneCore * InitializeIntroStorySceneCore(IntroStorySceneCore *, GameStateSaveImage *);
void DestroyIntroStorySceneCore(IntroStorySceneCore *, u32 flags);
EXTERN_C_END

#endif // INTRO_STORY_SCENE_HH
