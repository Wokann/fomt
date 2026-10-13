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

struct IntroSceneResourceFlags
{
    // Returned by UpdateIndexedResourceHandle. The loop sign-tests bit 2:
    // a signed one-bit field is zero or -1 without changing the stored bit.
    u8 entry_advanced : 1;
    u8 group_changed : 1;
    i8 wrapped : 1;
    u8 unk_3 : 5;
};

struct IntroSceneResourceState
{
    IndexedResourceHandle handle;
    IntroSceneResourceFlags flags;
    i32 unk_18;
    i32 unk_1C;
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

// Parameters consumed by the sprite renderer at func_0805E99C. The two
// positions are signed halfwords; palette/tile offsets are added to each
// descriptor's OAM attributes. Object mode and mosaic are the actual OAM
// attr0 bits 10-11 and 12; mosaic is distinct from attr0's color-depth bit 13.
struct IntroSceneSpriteParameters
{
    i16 x;
    i16 y;
    u16 palette_offset;
    u16 tile_offset;
    u16 priority;
    u32 object_mode;
    u8 flips;
    u8 affine_index;
    u32 affine_mode;
    u8 mosaic;
    IndexedResourceGroupResult group;

    IntroSceneSpriteParameters()
        : x(0), y(0), palette_offset(0), tile_offset(0), priority(0),
          object_mode(0), flips(0), affine_index(0), affine_mode(0), mosaic(0),
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
    // Initialization stores a halfword; the next upload sign-extends it.
    // Preserve the following unknown bytes, rather than widening that store
    // or assuming the uninspected bytes are initialized alignment padding.
    i16 unk_6C60;
    u8 unk_6C62[2];
    i16 unk_6C64;
    i16 unk_6C66;
    i16 unk_6C68;
    i16 unk_6C6A;
    i8 unk_6C6C;
    i8 unk_6C6D;
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
typedef char IntroSceneResourceFlagsOffsetCheck[(offsetof(IntroSceneResourceState, flags) == 0x14) ? 1 : -1];
typedef char IntroSceneResourceXOffsetCheck[(offsetof(IntroSceneResourceState, unk_18) == 0x18) ? 1 : -1];
typedef char IntroSceneResourceYOffsetCheck[(offsetof(IntroSceneResourceState, unk_1C) == 0x1C) ? 1 : -1];
typedef char IntroSceneCoreField6C60OffsetCheck[(offsetof(IntroSceneCore, unk_6C60) == 0x6C60) ? 1 : -1];
typedef char IntroSceneCoreField6C60WidthCheck[(sizeof(((IntroSceneCore *)0)->unk_6C60) == 2) ? 1 : -1];
typedef char IntroSceneCoreUnknown6C62OffsetCheck[(offsetof(IntroSceneCore, unk_6C62) == 0x6C62) ? 1 : -1];
typedef char IntroSceneCoreField6C64OffsetCheck[(offsetof(IntroSceneCore, unk_6C64) == 0x6C64) ? 1 : -1];
typedef char IntroSceneCoreAnimationStateOffsetCheck[(offsetof(IntroSceneCore, unk_6C6C) == 0x6C6C) ? 1 : -1];
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
int RunIntroSceneSequence(IntroSceneCore * core) SECTION(".text.intro_scene_core_sequence");
void func_080019D8(IntroSceneCore * core);
void func_080024E0(IntroSceneCore * core);
void SubmitIntroSceneSprite(IntroSceneCore * core, int x, int y, int type)
    SECTION(".text.intro_scene_sprite_submission");
void func_0805E99C(HardwareSpriteBufferState * buffer, HardwareSpriteOamRecord const * descriptors,
    u32 count, IntroSceneSpriteParameters const * parameters);
GameIntroScene * ConstructGameIntroScene(GameIntroScene * scene);
void DestroyGameIntroScene(GameIntroScene * scene, int flags);
SceneTransitionOwner RunGameIntroScene(GameIntroScene * scene);
SceneTransitionOwner RunIntroSceneCore(IntroSceneCore * core) SECTION(".text.intro_scene_core_run");

EXTERN_C_END

#endif // INTRO_SCENE_HH
