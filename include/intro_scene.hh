#ifndef INTRO_SCENE_HH
#define INTRO_SCENE_HH

#include "prelude.h"
#include "scene.hh"
#include "hardware_music_player.hh"
#include "hardware_refcount.hh"
#include "hardware_allocator.hh"
#include "resource_handle.hh"

struct HardwareCoreState;

struct IntroSceneUnpackedResources
{
    u8 bytes[0x6A00];
    void Initialize(u8 const * source);
};

union IntroSceneResourceFlags
{
    // Native frame updates store the complete returned word. Consumers test
    // its low-byte fields; the signed wrap bit reads as zero or minus one.
    u32 raw;
    struct {
        u8 entry_advanced : 1;
        u8 group_changed : 1;
        i8 wrapped : 1;
        u8 unk_3 : 5;
    } bits;
};

typedef char IntroSceneResourceFlagsSizeCheck[sizeof(IntroSceneResourceFlags) == 4 ? 1 : -1];
typedef char IntroSceneResourceFlagBitsOffsetCheck[offsetof(IntroSceneResourceFlags, bits) == 0 ? 1 : -1];

struct IntroSceneResourceState
{
    IndexedResourceHandle handle;
    IntroSceneResourceFlags flags;
    // Signed 16.16 pixel coordinates; drawing reads the signed upper half.
    i32 x;
    i32 y;
};

struct IntroSceneHardwareStateHandle : HardwareSharedStateOwner
{
    u32 handle;

    ~IntroSceneHardwareStateHandle()
    {
        ReleaseHardwareSharedStateHandle(this, handle);
    }
};

struct IntroSceneHardwarePoolHandle : HardwarePoolOwner
{
    u32 handle;

    ~IntroSceneHardwarePoolHandle()
    {
        ReleaseHardwarePoolHandle(this, handle);
    }
};

typedef char IntroSceneStateHandleSizeCheck[sizeof(IntroSceneHardwareStateHandle) == 8 ? 1 : -1];
typedef char IntroSceneStateHandleOffsetCheck[offsetof(IntroSceneHardwareStateHandle, handle) == 4 ? 1 : -1];
typedef char IntroScenePoolHandleSizeCheck[sizeof(IntroSceneHardwarePoolHandle) == 8 ? 1 : -1];
typedef char IntroScenePoolHandleOffsetCheck[offsetof(IntroSceneHardwarePoolHandle, handle) == 4 ? 1 : -1];

// The intro keeps its current group after the common 28-byte draw prefix.
// The sprite renderer only receives that prefix, not these group ranges.
struct IntroSceneSpriteParameters : IndexedResourceSpriteParameters
{
    IndexedResourceGroupResult group;

    IntroSceneSpriteParameters()
        : IndexedResourceSpriteParameters(),
          group(0, 0, 0, 0, 0, 0, 0, 0) {}
};

typedef char IntroSceneSpriteParametersSizeCheck[sizeof(IntroSceneSpriteParameters) == 60 ? 1 : -1];
typedef char IntroSceneSpritePaletteOffsetCheck[offsetof(IntroSceneSpriteParameters, palette_offset) == 4 ? 1 : -1];
typedef char IntroSceneSpriteTileOffsetCheck[offsetof(IntroSceneSpriteParameters, tile_offset) == 6 ? 1 : -1];
typedef char IntroSceneSpriteAffineModeOffsetCheck[offsetof(IntroSceneSpriteParameters, affine_mode) == 20 ? 1 : -1];
typedef char IntroSceneSpriteObjectModeOffsetCheck[offsetof(IntroSceneSpriteParameters, object_mode) == 12 ? 1 : -1];
typedef char IntroSceneSpriteMosaicOffsetCheck[offsetof(IntroSceneSpriteParameters, mosaic) == 24 ? 1 : -1];
typedef char IntroSceneSpriteGroupOffsetCheck[offsetof(IntroSceneSpriteParameters, group) == 28 ? 1 : -1];

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
    // Resource 9 follows resource 8's OBJ tiles: initialization stores the
    // first upload's byte count / 32, and drawing uses it as the tile index.
    // Preserve the following untouched bytes; the native store is a halfword.
    i16 resource9_tile_index;
    u8 unk_6C62[2];
    // The frame renderer writes these four signed coefficients to OAM
    // matrix 0. The sequence changes its diagonal from 0x400 to 0x100.
    IndexedResourceSpriteMatrix sprite_matrix;
    i8 unk_6C6C;
    i8 unk_6C6D;
    i8 continuation;
    u8 unk_6C6F;
    HardwareSharedStateOwner state_reservation;
    HardwarePoolOwner pool_reservation;
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
typedef char IntroSceneResourceFlagsOffsetCheck[(offsetof(IntroSceneResourceState, flags) == 0x14) ? 1 : -1];
typedef char IntroSceneResourceXOffsetCheck[(offsetof(IntroSceneResourceState, x) == 0x18) ? 1 : -1];
typedef char IntroSceneResourceYOffsetCheck[(offsetof(IntroSceneResourceState, y) == 0x1C) ? 1 : -1];
typedef char IntroSceneCoreResource9TileIndexOffsetCheck[(offsetof(IntroSceneCore, resource9_tile_index) == 0x6C60) ? 1 : -1];
typedef char IntroSceneCoreResource9TileIndexWidthCheck[(sizeof(((IntroSceneCore *)0)->resource9_tile_index) == 2) ? 1 : -1];
typedef char IntroSceneCoreUnknown6C62OffsetCheck[(offsetof(IntroSceneCore, unk_6C62) == 0x6C62) ? 1 : -1];
typedef char IntroSceneCoreSpriteMatrixOffsetCheck[(offsetof(IntroSceneCore, sprite_matrix) == 0x6C64) ? 1 : -1];
typedef char IntroSceneCoreSpriteMatrixSizeCheck[(sizeof(((IntroSceneCore *)0)->sprite_matrix) == 8) ? 1 : -1];
typedef char IntroSceneMatrixPbOffsetCheck[(offsetof(IndexedResourceSpriteMatrix, pb) == 2) ? 1 : -1];
typedef char IntroSceneMatrixPcOffsetCheck[(offsetof(IndexedResourceSpriteMatrix, pc) == 4) ? 1 : -1];
typedef char IntroSceneMatrixPdOffsetCheck[(offsetof(IndexedResourceSpriteMatrix, pd) == 6) ? 1 : -1];
typedef char IntroSceneCoreAnimationStateOffsetCheck[(offsetof(IntroSceneCore, unk_6C6C) == 0x6C6C) ? 1 : -1];
typedef char IntroSceneCoreArchiveOffsetCheck[(offsetof(IntroSceneCore, intro_archive) == 0x6A10) ? 1 : -1];
typedef char IntroSceneCoreResourcesOffsetCheck[(offsetof(IntroSceneCore, resources) == 0x6AA0) ? 1 : -1];
typedef char IntroSceneCoreHardwareHandlesOffsetCheck[(offsetof(IntroSceneCore, state_handle_6C78) == 0x6C78) ? 1 : -1];
typedef char IntroSceneCorePoolReservationOffsetCheck[offsetof(IntroSceneCore, pool_reservation) == 0x6C74 ? 1 : -1];

struct GameIntroScene : AScene
{
    IntroSceneCore * core;
    GameIntroScene() asm("ConstructGameIntroScene");
    virtual ~GameIntroScene() asm("DestroyGameIntroScene");
    virtual SceneTransitionOwner Run() asm("RunGameIntroScene");
};

typedef char GameIntroSceneSizeCheck[sizeof(GameIntroScene) == 8 ? 1 : -1];
typedef char GameIntroSceneCoreOffsetCheck[offsetof(GameIntroScene, core) == 4 ? 1 : -1];

struct IntroNameEntryTransition : SceneTransition
{
    virtual SceneOwner CreateScene() SECTION(".text.intro_scene_transitions");
};

struct IntroMenuTransition : SceneTransition
{
    virtual SceneOwner CreateScene() SECTION(".text.intro_scene_transitions");
};

struct MenuIntroTransition : SceneTransition
{
    virtual SceneOwner CreateScene() asm("CreateIntroScene") SECTION(".text.intro_scene_factory");
};

typedef char MenuIntroTransitionSizeCheck[sizeof(MenuIntroTransition) == 4 ? 1 : -1];

EXTERN_C

extern IntroSceneCoreVTable const vtable_unk_080E5A0C;
extern u8 const gIntroSceneIndexedArchiveCompressed[];
extern u8 const gIntroSceneSmallIndexedArchive[];
extern u8 const gActorIndexedResourceArchive[];
IntroSceneCore * ConstructIntroSceneCore(void * core) SECTION(".text.intro_scene_core_constructor");
void DestroyIntroSceneCore(IntroSceneCore * core, int flags) SECTION(".text.intro_scene_core_cleanup");
void StartIntroSceneCore(IntroSceneCore * core) SECTION(".text.intro_scene_core_startup");
void InitializeIntroSceneBackground(IntroSceneCore * core);
int RunIntroSceneSequence(IntroSceneCore * core) SECTION(".text.intro_scene_core_sequence");
// Native resource upload/setup; a full C++ replacement is not yet matched.
void InitializeIntroSceneSequenceResources(IntroSceneCore * core);
// Update resource playback, refresh changed OBJ data through the DMA queue,
// and submit the opening scene's sprites. JP also submits resource 9.
void RenderIntroSceneFrame(IntroSceneCore * core);
void SubmitIntroSceneSprite(IntroSceneCore * core, int x, int y, int type)
    SECTION(".text.intro_scene_sprite_submission");
GameIntroScene * ConstructGameIntroScene(GameIntroScene * scene);
void DestroyGameIntroScene(GameIntroScene * scene, int flags);
SceneTransitionOwner RunGameIntroScene(GameIntroScene * scene);
SceneTransitionOwner RunIntroSceneCore(IntroSceneCore * core) SECTION(".text.intro_scene_core_run");

EXTERN_C_END

#endif // INTRO_SCENE_HH
