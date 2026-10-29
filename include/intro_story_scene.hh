#ifndef INTRO_STORY_SCENE_HH
#define INTRO_STORY_SCENE_HH

#include "hardware_bootstrap.hh"
#include "hardware_music_player.hh"
#include "ui_state.hh"
#include "scene.hh"

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
    virtual ~IntroStorySceneCore() asm("DestroyIntroStorySceneCore");
    GameStateSaveImage * saved;
    u32 unk_0C;
    UiStateOwner * ui_state;
    HardwareMusicPlayerSlot music_players[3];
    // Twenty 32-column, 20-row BG maps. Consecutive pairs upload to BG3/BG2.
    // Initialization leaves their storage untouched until the maps are unpacked.
    u16 background_tilemaps[20][20][32];
    i16 scene_step;
    i16 transition_phase;
    // Animation and dialogue share the story index. The dialogue coordinator
    // keeps its original numeric states until the complete animation loop is recovered.
    i16 story_step;
    i16 dialogue_state;
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
typedef char IntroStoryTilemapsOffsetCheck[offsetof(IntroStorySceneCore, background_tilemaps) == 0x20 ? 1 : -1];
typedef char IntroStorySceneStepOffsetCheck[offsetof(IntroStorySceneCore, scene_step) == 0x6420 ? 1 : -1];
typedef char IntroStoryTransitionPhaseOffsetCheck[offsetof(IntroStorySceneCore, transition_phase) == 0x6422 ? 1 : -1];
typedef char IntroStoryTilemapSizeCheck[sizeof(((IntroStorySceneCore *)0)->background_tilemaps[0]) == 0x500 ? 1 : -1];
typedef char IntroStoryStepOffsetCheck[offsetof(IntroStorySceneCore, story_step) == 0x6424 ? 1 : -1];
typedef char IntroStoryDialogueStateOffsetCheck[offsetof(IntroStorySceneCore, dialogue_state) == 0x6426 ? 1 : -1];
typedef char IntroStoryMusicSlotsSizeCheck[sizeof(((IntroStorySceneCore *)0)->music_players) == 3 * sizeof(MusicPlayer *) ? 1 : -1];
typedef char IntroStoryVTableSizeCheck[sizeof(IntroStorySceneCoreVTable) == 12 ? 1 : -1];
typedef char IntroStoryDestroySlotCheck[offsetof(IntroStorySceneCoreVTable, destroy) == 8 ? 1 : -1];

EXTERN_C
IntroStorySceneCore * InitializeIntroStorySceneCore(IntroStorySceneCore *, GameStateSaveImage *);
void DestroyIntroStorySceneCore(IntroStorySceneCore *, u32 flags);
SceneTransitionOwner RunIntroStorySceneCore(IntroStorySceneCore *);
void UpdateIntroStoryUi(IntroStorySceneCore *);
void InitializeIntroStoryGraphics(IntroStorySceneCore *);
EXTERN_C_END

// Own the native core through its verified +4 callback table. The complete
// C++ hierarchy of that core is still being recovered.
struct IntroStoryCoreOwner
{
    IntroStorySceneCore * value;
    explicit IntroStoryCoreOwner(GameStateSaveImage * saved);
    ~IntroStoryCoreOwner();
private:
    IntroStoryCoreOwner(IntroStoryCoreOwner const &);
    IntroStoryCoreOwner & operator=(IntroStoryCoreOwner const &);
};

struct IntroStoryScene : AScene
{
    IntroStoryCoreOwner core;
    SceneTransitionOwner continuation;

    IntroStoryScene(SceneTransition *& next, GameStateSaveImage * saved);
    virtual ~IntroStoryScene();
    virtual SceneTransitionOwner Run();
};

typedef char IntroStoryCoreOwnerSizeCheck[sizeof(IntroStoryCoreOwner) == 4 ? 1 : -1];
typedef char IntroStorySceneSizeCheck[sizeof(IntroStoryScene) == 12 ? 1 : -1];
typedef char IntroStorySceneCoreOffsetCheck[offsetof(IntroStoryScene, core) == 4 ? 1 : -1];
typedef char IntroStoryContinuationOffsetCheck[offsetof(IntroStoryScene, continuation) == 8 ? 1 : -1];


// Native transition layout. Its shared callback-table run is not yet a
// complete recovered C++ class hierarchy; do not construct this ABI view.
struct IntroStoryTransition : SceneTransition
{
    SceneTransitionOwner continuation;
    GameStateSaveImage * saved;
private:
    IntroStoryTransition();
};
typedef char IntroStoryTransitionSizeCheck[sizeof(IntroStoryTransition) == 12 ? 1 : -1];
typedef char IntroStoryTransitionContinuationOffsetCheck[offsetof(IntroStoryTransition,continuation) == 4 ? 1 : -1];
typedef char IntroStoryTransitionSavedOffsetCheck[offsetof(IntroStoryTransition,saved) == 8 ? 1 : -1];

struct IntroStoryTransitionVTable
{
    void const * metadata[2];
    void (*destroy)(IntroStoryTransition *, int flags);
    SceneOwner (*create_scene)(IntroStoryTransition *);
};
typedef char IntroStoryTransitionVTableSizeCheck[sizeof(IntroStoryTransitionVTable) == 16 ? 1 : -1];
typedef char IntroStoryTransitionDestroySlotCheck[offsetof(IntroStoryTransitionVTable,destroy) == 8 ? 1 : -1];
typedef char IntroStoryTransitionCreateSlotCheck[offsetof(IntroStoryTransitionVTable,create_scene) == 12 ? 1 : -1];

EXTERN_C
SceneOwner CreateIntroStoryScene(IntroStoryTransition * transition);
void DestroyIntroStoryTransition(IntroStoryTransition * transition, int flags);
extern IntroStoryTransitionVTable const gIntroStoryTransitionVTable;
EXTERN_C_END

#endif // INTRO_STORY_SCENE_HH
