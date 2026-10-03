#ifndef INTRO_SCENE_HH
#define INTRO_SCENE_HH

#include "prelude.h"
#include "scene.hh"
#include "hardware_music_player.hh"
#include "hardware_refcount.hh"
#include "resource_handle.hh"

struct HardwareCoreState;

struct IntroSceneUnpackedResources
{
    u8 bytes[0x6A00];
    void Initialize(u8 const * source);
};

struct IntroSceneResourceState
{
    IndexedResourceHandle handle;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
};

struct IntroSceneHardwareStateHandle
{
    u32 unk_00;
    u32 handle;
};

struct IntroSceneHardwarePoolHandle
{
    u32 unk_00;
    u32 handle;
};

typedef void (*IntroSceneVTableFunction)(void);

struct IntroSceneCore;

typedef void (*IntroSceneCoreDestroyFunction)(IntroSceneCore *, int);

struct IntroSceneCoreVTable
{
    void * unk_00;
    void * unk_04;
    IntroSceneCoreDestroyFunction destroy;
};

// Member widths follow the constructor and the later assembly consumers.
// Unknown animation state and lifetime-owner bytes are not given meanings
// merely because their initialization or their physical extent is known.
struct IntroSceneCore
{
    HardwareCoreState * hardware_state;
    IntroSceneCoreVTable const * vtable;
    MusicPlayer * music_players[2];
    IntroSceneUnpackedResources unpacked_resources;
    IndexedResourceArchive intro_archive;
    IndexedResourceArchive small_archive;
    IndexedResourceArchive actor_archive;
    IntroSceneResourceState resources[14];
    u8 unk_6C60[0x0D];
    u8 unk_6C6D;
    i8 continuation;
    u8 unk_6C6F;
    HardwareSharedStateOwner state_reservation;
    u32 unk_6C74;
    IntroSceneHardwareStateHandle state_handle_6C78;
    IntroSceneHardwarePoolHandle pool_handle_6C80;
    IntroSceneHardwareStateHandle state_handle_6C88;
    IntroSceneHardwarePoolHandle pool_handle_6C90;
    IntroSceneHardwareStateHandle state_handle_6C98;
    IntroSceneHardwarePoolHandle pool_handle_6CA0;
    IntroSceneHardwareStateHandle state_handle_6CA8;
    IntroSceneHardwareStateHandle state_handle_6CB0;
    IntroSceneHardwarePoolHandle pool_handle_6CB8;
    IntroSceneHardwareStateHandle state_handle_6CC0;
    IntroSceneHardwarePoolHandle pool_handle_6CC8;
    IntroSceneHardwareStateHandle state_handle_6CD0;
    IntroSceneHardwareStateHandle state_handle_6CD8;
    IntroSceneHardwareStateHandle state_handle_6CE0;
    IntroSceneHardwarePoolHandle pool_handle_6CE8;
    IntroSceneHardwareStateHandle state_handle_6CF0;
    IntroSceneHardwareStateHandle state_handle_6CF8;
    IntroSceneHardwarePoolHandle pool_handle_6D00;
    IntroSceneHardwareStateHandle state_handle_6D08;
    IntroSceneHardwarePoolHandle pool_handle_6D10;
    IntroSceneHardwareStateHandle state_handle_6D18;
    IntroSceneHardwarePoolHandle pool_handle_6D20;
    u32 run_state;
    i32 startup_hold_frames;
    u16 unk_6D30;
    i16 startup_phase;
};

typedef char IntroSceneCoreSizeCheck[(sizeof(IntroSceneCore) == 0x6D34) ? 1 : -1];
typedef char IntroSceneCoreContinuationOffsetCheck[(offsetof(IntroSceneCore, continuation) == 0x6C6E) ? 1 : -1];
typedef char IntroSceneCoreRunStateOffsetCheck[(offsetof(IntroSceneCore, run_state) == 0x6D28) ? 1 : -1];
typedef char IntroSceneCoreStartupHoldOffsetCheck[(offsetof(IntroSceneCore, startup_hold_frames) == 0x6D2C) ? 1 : -1];
typedef char IntroSceneCoreStartupPhaseOffsetCheck[(offsetof(IntroSceneCore, startup_phase) == 0x6D32) ? 1 : -1];
typedef char IntroSceneResourceStateSizeCheck[(sizeof(IntroSceneResourceState) == 0x20) ? 1 : -1];
typedef char IntroSceneCoreArchiveOffsetCheck[(offsetof(IntroSceneCore, intro_archive) == 0x6A10) ? 1 : -1];
typedef char IntroSceneCoreResourcesOffsetCheck[(offsetof(IntroSceneCore, resources) == 0x6AA0) ? 1 : -1];
typedef char IntroSceneCoreHardwareHandlesOffsetCheck[(offsetof(IntroSceneCore, state_handle_6C78) == 0x6C78) ? 1 : -1];

struct GameIntroScene
{
    IntroSceneVTableFunction const * vtable;
    IntroSceneCore * core;
};

struct IntroNameEntryTransition : SceneTransition
{
    virtual SceneOwner CreateScene() SECTION(".text.intro_scene_transitions");
};

struct IntroMenuTransition : SceneTransition
{
    virtual SceneOwner CreateScene() SECTION(".text.intro_scene_transitions");
};

EXTERN_C

extern IntroSceneCoreVTable const vtable_unk_080E5A0C;
extern u8 const gIntroSceneIndexedArchiveCompressed[];
extern u8 const gIntroSceneSmallIndexedArchive[];
extern u8 const gActorIndexedResourceArchive[];
extern IntroSceneVTableFunction const vtable_unk_080E5A18[];
IntroSceneCore * ConstructIntroSceneCore(void * core) SECTION(".text.intro_scene_core_constructor");
void StartIntroSceneCore(IntroSceneCore * core) SECTION(".text.intro_scene_core_startup");
void func_08000F5C(IntroSceneCore * core);
int func_08000FF8(IntroSceneCore * core);
GameIntroScene * ConstructGameIntroScene(GameIntroScene * scene);
void DestroyGameIntroScene(GameIntroScene * scene, int flags);
SceneTransitionOwner RunGameIntroScene(GameIntroScene * scene);
SceneTransitionOwner RunIntroSceneCore(IntroSceneCore * core) SECTION(".text.intro_scene_core_run");

EXTERN_C_END

#endif // INTRO_SCENE_HH
