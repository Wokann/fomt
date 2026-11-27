#ifndef INTRO_SCENE_HH
#define INTRO_SCENE_HH

#include "intro_scene_resource_size.hh"

// The native object reserves at least 0x6A00 bytes, independently of the
// archive's decoded length. Larger archives grow this same inline storage.
// Four-byte rounding preserves the ordinary alignment of following members.
#if INTRO_SCENE_RESOURCE_BYTES > 0x6A00
#define INTRO_SCENE_RESOURCE_CAPACITY ((INTRO_SCENE_RESOURCE_BYTES + 3) & ~3)
#else
#define INTRO_SCENE_RESOURCE_CAPACITY 0x6A00
#endif

// ABI layout shared with the remaining assembly consumers. These offsets
// follow the declared member order.
#define INTRO_SCENE_RESOURCE_HANDLE_SIZE 0x14
#define INTRO_SCENE_RESOURCE_HANDLE_OFFSET 0
#define INTRO_SCENE_RESOURCE_RESOLVED_OFFSET (INTRO_SCENE_RESOURCE_HANDLE_OFFSET + 4)
#define INTRO_SCENE_RESOURCE_FLAGS_OFFSET (INTRO_SCENE_RESOURCE_HANDLE_OFFSET + INTRO_SCENE_RESOURCE_HANDLE_SIZE)
#define INTRO_SCENE_RESOURCE_X_OFFSET (INTRO_SCENE_RESOURCE_FLAGS_OFFSET + 4)
#define INTRO_SCENE_RESOURCE_Y_OFFSET (INTRO_SCENE_RESOURCE_X_OFFSET + 4)
#define INTRO_SCENE_RESOURCE_STATE_SIZE (INTRO_SCENE_RESOURCE_Y_OFFSET + 4)
#define INTRO_SCENE_ARCHIVE_SIZE 0x30
#define INTRO_SCENE_SPRITE_MATRIX_SIZE 8
#define INTRO_SCENE_MATRIX_PD_OFFSET 6
#define INTRO_SCENE_OWNER_SIZE 4
#define INTRO_SCENE_HARDWARE_HANDLE_SIZE (INTRO_SCENE_OWNER_SIZE + 4)
#define INTRO_SCENE_CORE_HARDWARE_STATE_OFFSET 0
#define INTRO_SCENE_CORE_VTABLE_OFFSET (INTRO_SCENE_CORE_HARDWARE_STATE_OFFSET + 4)
#define INTRO_SCENE_CORE_MUSIC_PLAYERS_OFFSET (INTRO_SCENE_CORE_VTABLE_OFFSET + 4)
#define INTRO_SCENE_CORE_UNPACKED_RESOURCES_OFFSET (INTRO_SCENE_CORE_MUSIC_PLAYERS_OFFSET + 2 * 4)
#define INTRO_SCENE_CORE_INTRO_ARCHIVE_OFFSET (INTRO_SCENE_CORE_UNPACKED_RESOURCES_OFFSET + INTRO_SCENE_RESOURCE_CAPACITY)
#define INTRO_SCENE_CORE_SMALL_ARCHIVE_OFFSET (INTRO_SCENE_CORE_INTRO_ARCHIVE_OFFSET + INTRO_SCENE_ARCHIVE_SIZE)
#define INTRO_SCENE_CORE_ACTOR_ARCHIVE_OFFSET (INTRO_SCENE_CORE_SMALL_ARCHIVE_OFFSET + INTRO_SCENE_ARCHIVE_SIZE)
#define INTRO_SCENE_CORE_RESOURCES_OFFSET (INTRO_SCENE_CORE_ACTOR_ARCHIVE_OFFSET + INTRO_SCENE_ARCHIVE_SIZE)
#define INTRO_SCENE_CORE_RESOURCE9_TILE_INDEX_OFFSET (INTRO_SCENE_CORE_RESOURCES_OFFSET + 14 * INTRO_SCENE_RESOURCE_STATE_SIZE)
#define INTRO_SCENE_CORE_UNK_6C62_OFFSET (INTRO_SCENE_CORE_RESOURCE9_TILE_INDEX_OFFSET + 2)
#define INTRO_SCENE_CORE_SPRITE_MATRIX_OFFSET (INTRO_SCENE_CORE_UNK_6C62_OFFSET + 2)
#define INTRO_SCENE_CORE_UNK_6C6C_OFFSET (INTRO_SCENE_CORE_SPRITE_MATRIX_OFFSET + INTRO_SCENE_SPRITE_MATRIX_SIZE)
#define INTRO_SCENE_CORE_UNK_6C6D_OFFSET (INTRO_SCENE_CORE_UNK_6C6C_OFFSET + 1)
#define INTRO_SCENE_CORE_CONTINUATION_OFFSET (INTRO_SCENE_CORE_UNK_6C6D_OFFSET + 1)
#define INTRO_SCENE_CORE_UNK_6C6F_OFFSET (INTRO_SCENE_CORE_CONTINUATION_OFFSET + 1)
#define INTRO_SCENE_CORE_STATE_RESERVATION_OFFSET (INTRO_SCENE_CORE_UNK_6C6F_OFFSET + 1)
#define INTRO_SCENE_CORE_POOL_RESERVATION_OFFSET (INTRO_SCENE_CORE_STATE_RESERVATION_OFFSET + INTRO_SCENE_OWNER_SIZE)
#define INTRO_SCENE_CORE_STATE_HANDLE_6C78_OFFSET (INTRO_SCENE_CORE_POOL_RESERVATION_OFFSET + INTRO_SCENE_OWNER_SIZE)
#define INTRO_SCENE_CORE_POOL_HANDLE_6C80_OFFSET (INTRO_SCENE_CORE_STATE_HANDLE_6C78_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_STATE_HANDLE_6C88_OFFSET (INTRO_SCENE_CORE_POOL_HANDLE_6C80_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_POOL_HANDLE_6C90_OFFSET (INTRO_SCENE_CORE_STATE_HANDLE_6C88_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_STATE_HANDLE_6C98_OFFSET (INTRO_SCENE_CORE_POOL_HANDLE_6C90_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_POOL_HANDLE_6CA0_OFFSET (INTRO_SCENE_CORE_STATE_HANDLE_6C98_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_STATE_HANDLE_6CA8_OFFSET (INTRO_SCENE_CORE_POOL_HANDLE_6CA0_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_STATE_HANDLE_6CB0_OFFSET (INTRO_SCENE_CORE_STATE_HANDLE_6CA8_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_POOL_HANDLE_6CB8_OFFSET (INTRO_SCENE_CORE_STATE_HANDLE_6CB0_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_STATE_HANDLE_6CC0_OFFSET (INTRO_SCENE_CORE_POOL_HANDLE_6CB8_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_POOL_HANDLE_6CC8_OFFSET (INTRO_SCENE_CORE_STATE_HANDLE_6CC0_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_STATE_HANDLE_6CD0_OFFSET (INTRO_SCENE_CORE_POOL_HANDLE_6CC8_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_STATE_HANDLE_6CD8_OFFSET (INTRO_SCENE_CORE_STATE_HANDLE_6CD0_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_STATE_HANDLE_6CE0_OFFSET (INTRO_SCENE_CORE_STATE_HANDLE_6CD8_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_POOL_HANDLE_6CE8_OFFSET (INTRO_SCENE_CORE_STATE_HANDLE_6CE0_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_STATE_HANDLE_6CF0_OFFSET (INTRO_SCENE_CORE_POOL_HANDLE_6CE8_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_STATE_HANDLE_6CF8_OFFSET (INTRO_SCENE_CORE_STATE_HANDLE_6CF0_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_POOL_HANDLE_6D00_OFFSET (INTRO_SCENE_CORE_STATE_HANDLE_6CF8_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_STATE_HANDLE_6D08_OFFSET (INTRO_SCENE_CORE_POOL_HANDLE_6D00_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_POOL_HANDLE_6D10_OFFSET (INTRO_SCENE_CORE_STATE_HANDLE_6D08_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_STATE_HANDLE_6D18_OFFSET (INTRO_SCENE_CORE_POOL_HANDLE_6D10_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_POOL_HANDLE_6D20_OFFSET (INTRO_SCENE_CORE_STATE_HANDLE_6D18_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_RUN_STATE_OFFSET (INTRO_SCENE_CORE_POOL_HANDLE_6D20_OFFSET + INTRO_SCENE_HARDWARE_HANDLE_SIZE)
#define INTRO_SCENE_CORE_STARTUP_HOLD_FRAMES_OFFSET (INTRO_SCENE_CORE_RUN_STATE_OFFSET + 4)
#define INTRO_SCENE_CORE_UNK_6D30_OFFSET (INTRO_SCENE_CORE_STARTUP_HOLD_FRAMES_OFFSET + 4)
#define INTRO_SCENE_CORE_STARTUP_PHASE_OFFSET (INTRO_SCENE_CORE_UNK_6D30_OFFSET + 2)
#define INTRO_SCENE_CORE_SIZE (INTRO_SCENE_CORE_STARTUP_PHASE_OFFSET + 2)
#define INTRO_SCENE_RESOURCE_OFFSET(index) (INTRO_SCENE_CORE_RESOURCES_OFFSET + (index) * INTRO_SCENE_RESOURCE_STATE_SIZE)

#ifndef __ASSEMBLER__

#include "prelude.h"
#include "scene.hh"
#include "hardware_sound.hh"
#include "hardware_context.hh"
#include "obj_tile_pool.hh"
#include "obj_palette_pool.hh"
#include "resource_handle.hh"

struct HardwareCoreState;

struct IntroSceneUnpackedResources
{
    u8 bytes[INTRO_SCENE_RESOURCE_CAPACITY];
    void Initialize(u8 const * source);
};

union IntroSceneResourceFlags
{
    // Native frame updates store the complete returned word. Consumers test
    // its low-byte fields; signed group/wrap flags read as zero or minus one.
    u32 raw;
    struct {
        u8 entry_advanced : 1;
        i8 group_changed : 1;
        i8 wrapped : 1;
        u8 unk_3 : 5;
    } bits;
};


struct IntroSceneResourceState
{
    IndexedResourceHandle handle;
    IntroSceneResourceFlags flags;
    // Signed 16.16 pixel coordinates; drawing reads the signed upper half.
    i32 x;
    i32 y;
};

struct IntroSceneHardwareStateHandle : ObjTilePoolOwner
{
    u32 handle;

    ~IntroSceneHardwareStateHandle()
    {
        ReleaseObjTileHandle(this, handle);
    }
};

struct IntroSceneHardwarePoolHandle : ObjPalettePoolOwner
{
    u32 handle;

    ~IntroSceneHardwarePoolHandle()
    {
        ReleaseObjPaletteHandle(this, handle);
    }
};


// The intro keeps its current group after the common 28-byte draw prefix.
// The sprite renderer only receives that prefix, not these group ranges.
struct IntroSceneSpriteParameters : IndexedResourceSpriteParameters
{
    IndexedResourceGroupResult group;

    IntroSceneSpriteParameters()
        : IndexedResourceSpriteParameters(),
          group(0, 0, 0, 0, 0, 0, 0, 0) {}
};


#pragma interface "intro_scene.hh"

struct IntroSceneCore;

struct GameIntroScene : AScene
{
    IntroSceneCore * core;
    GameIntroScene() asm("ConstructGameIntroScene");
    virtual ~GameIntroScene() asm("DestroyGameIntroScene");
    virtual SceneTransitionOwner Run() asm("RunGameIntroScene");
};

// Member widths follow the constructor and the remaining assembly consumers.
// Unknown animation state and lifetime-owner bytes are not given meanings
// merely because their initialization or their physical extent is known.
struct IntroSceneCore : HardwareContext
{
    // Destruction releases the owned members in reverse order, then the
    // hardware context. Resource handles borrow data.
    HardwareMusicPlayerSlot music_players[2];
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
    ObjTilePoolOwner state_reservation;
    ObjPalettePoolOwner pool_reservation;
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



struct IntroNameEntryTransition : SceneTransition
{
    virtual SceneOwner CreateScene();
};

struct IntroMenuTransition : SceneTransition
{
    virtual SceneOwner CreateScene();
};


EXTERN_C

extern u8 const gIntroSceneStartupBg0Tilemap[];
extern u8 const gIntroSceneStartupBg1Tilemap[];
extern u8 const gIntroSceneStartupBg2Tilemap[];
extern u8 const gIntroSceneStartupBg3Tilemap[];
extern u8 const gIntroSceneStartupTiles[];
extern u8 const gIntroSceneStartupPaletteBanks[];

extern u8 const * const gIntroSceneStartupBgTilemaps[4];
extern char const gCppRuntimeError_IntroSceneStartup[];

extern u8 const gIntroSceneIndexedArchiveCompressed[];
extern u8 const gIntroSceneSmallIndexedArchive[];
extern u8 const gActorIndexedResourceArchive[];
IntroSceneCore * ConstructIntroSceneCore(void * core);
void StartIntroSceneCore(IntroSceneCore * core);
void InitializeIntroSceneBackground(IntroSceneCore * core);
int RunIntroSceneSequence(IntroSceneCore * core);
// Native resource upload/setup; a full C++ replacement is not yet matched.
void InitializeIntroSceneSequenceResources(IntroSceneCore * core);
// Update resource playback, refresh changed OBJ data through the DMA queue,
// and submit the opening scene's sprites. JP also submits resource 9.
void RenderIntroSceneFrame(IntroSceneCore * core);
void SubmitIntroSceneSprite(IntroSceneCore * core, int x, int y, int type);
GameIntroScene * ConstructGameIntroScene(GameIntroScene * scene);
void DestroyGameIntroScene(GameIntroScene * scene, int flags);
SceneTransitionOwner RunGameIntroScene(GameIntroScene * scene);
SceneTransitionOwner RunIntroSceneCore(IntroSceneCore * core);

EXTERN_C_END

#endif // !__ASSEMBLER__

#endif // INTRO_SCENE_HH
