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
// follow member order; C++ sizeof/offsetof checks below verify the contract.
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
#include "hardware_music_player.hh"
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

typedef char IntroSceneStateHandleSizeCheck[sizeof(IntroSceneHardwareStateHandle) == INTRO_SCENE_HARDWARE_HANDLE_SIZE ? 1 : -1];
typedef char IntroSceneStateHandleOffsetCheck[offsetof(IntroSceneHardwareStateHandle, handle) == 4 ? 1 : -1];
typedef char IntroScenePoolHandleSizeCheck[sizeof(IntroSceneHardwarePoolHandle) == INTRO_SCENE_HARDWARE_HANDLE_SIZE ? 1 : -1];
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

// Member widths follow the constructor and the remaining assembly consumers.
// Unknown animation state and lifetime-owner bytes are not given meanings
// merely because their initialization or their physical extent is known.
struct IntroSceneCore
{
    HardwareCoreState * hardware_state;
    IntroSceneCoreVTable const * vtable;
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

typedef char IntroScenePointerSizeCheck[sizeof(void *) == 4 ? 1 : -1];
typedef char IntroSceneMusicPlayerSizeCheck[sizeof(HardwareMusicPlayerSlot) == 4 ? 1 : -1];
typedef char IntroSceneArchiveLayoutSizeCheck[sizeof(IndexedResourceArchive) == INTRO_SCENE_ARCHIVE_SIZE ? 1 : -1];
typedef char IntroSceneStateOwnerSizeCheck[sizeof(ObjTilePoolOwner) == INTRO_SCENE_OWNER_SIZE ? 1 : -1];
typedef char IntroScenePoolOwnerSizeCheck[sizeof(ObjPalettePoolOwner) == INTRO_SCENE_OWNER_SIZE ? 1 : -1];
typedef char IntroSceneUnpackedResourcesSizeCheck[sizeof(IntroSceneUnpackedResources) == INTRO_SCENE_RESOURCE_CAPACITY ? 1 : -1];
typedef char IntroSceneCoreMusicPlayersSizeCheck[sizeof(((IntroSceneCore *)0)->music_players) == 2 * 4 ? 1 : -1];
typedef char IntroSceneCoreResourcesSizeCheck[sizeof(((IntroSceneCore *)0)->resources) == 14 * INTRO_SCENE_RESOURCE_STATE_SIZE ? 1 : -1];
typedef char IntroSceneCoreSizeCheck[sizeof(IntroSceneCore) == INTRO_SCENE_CORE_SIZE ? 1 : -1];
typedef char IntroSceneResourceHandleSizeCheck[sizeof(IndexedResourceHandle) == INTRO_SCENE_RESOURCE_HANDLE_SIZE ? 1 : -1];
typedef char IntroSceneResourceHandleOffsetCheck[offsetof(IntroSceneResourceState, handle) == INTRO_SCENE_RESOURCE_HANDLE_OFFSET ? 1 : -1];
typedef char IntroSceneResourceResolvedOffsetCheck[offsetof(IntroSceneResourceState, handle) + offsetof(IndexedResourceHandle, resolved_resource) == INTRO_SCENE_RESOURCE_RESOLVED_OFFSET ? 1 : -1];
typedef char IntroSceneResourceStateSizeCheck[sizeof(IntroSceneResourceState) == INTRO_SCENE_RESOURCE_STATE_SIZE ? 1 : -1];
typedef char IntroSceneResourceFlagsOffsetCheck[offsetof(IntroSceneResourceState, flags) == INTRO_SCENE_RESOURCE_FLAGS_OFFSET ? 1 : -1];
typedef char IntroSceneResourceXOffsetCheck[offsetof(IntroSceneResourceState, x) == INTRO_SCENE_RESOURCE_X_OFFSET ? 1 : -1];
typedef char IntroSceneResourceYOffsetCheck[offsetof(IntroSceneResourceState, y) == INTRO_SCENE_RESOURCE_Y_OFFSET ? 1 : -1];
typedef char IntroSceneCoreResource9TileIndexWidthCheck[sizeof(((IntroSceneCore *)0)->resource9_tile_index) == 2 ? 1 : -1];
typedef char IntroSceneCoreSpriteMatrixSizeCheck[sizeof(((IntroSceneCore *)0)->sprite_matrix) == INTRO_SCENE_SPRITE_MATRIX_SIZE ? 1 : -1];
typedef char IntroSceneMatrixPbOffsetCheck[offsetof(IndexedResourceSpriteMatrix, pb) == 2 ? 1 : -1];
typedef char IntroSceneMatrixPcOffsetCheck[offsetof(IndexedResourceSpriteMatrix, pc) == 4 ? 1 : -1];
typedef char IntroSceneMatrixPdOffsetCheck[offsetof(IndexedResourceSpriteMatrix, pd) == INTRO_SCENE_MATRIX_PD_OFFSET ? 1 : -1];
typedef char IntroSceneCore_hardware_state_OffsetCheck[offsetof(IntroSceneCore, hardware_state) == INTRO_SCENE_CORE_HARDWARE_STATE_OFFSET ? 1 : -1];
typedef char IntroSceneCore_vtable_OffsetCheck[offsetof(IntroSceneCore, vtable) == INTRO_SCENE_CORE_VTABLE_OFFSET ? 1 : -1];
typedef char IntroSceneCore_music_players_OffsetCheck[offsetof(IntroSceneCore, music_players) == INTRO_SCENE_CORE_MUSIC_PLAYERS_OFFSET ? 1 : -1];
typedef char IntroSceneCore_unpacked_resources_OffsetCheck[offsetof(IntroSceneCore, unpacked_resources) == INTRO_SCENE_CORE_UNPACKED_RESOURCES_OFFSET ? 1 : -1];
typedef char IntroSceneCore_intro_archive_OffsetCheck[offsetof(IntroSceneCore, intro_archive) == INTRO_SCENE_CORE_INTRO_ARCHIVE_OFFSET ? 1 : -1];
typedef char IntroSceneCore_small_archive_OffsetCheck[offsetof(IntroSceneCore, small_archive) == INTRO_SCENE_CORE_SMALL_ARCHIVE_OFFSET ? 1 : -1];
typedef char IntroSceneCore_actor_archive_OffsetCheck[offsetof(IntroSceneCore, actor_archive) == INTRO_SCENE_CORE_ACTOR_ARCHIVE_OFFSET ? 1 : -1];
typedef char IntroSceneCore_resources_OffsetCheck[offsetof(IntroSceneCore, resources) == INTRO_SCENE_CORE_RESOURCES_OFFSET ? 1 : -1];
typedef char IntroSceneCore_resource9_tile_index_OffsetCheck[offsetof(IntroSceneCore, resource9_tile_index) == INTRO_SCENE_CORE_RESOURCE9_TILE_INDEX_OFFSET ? 1 : -1];
typedef char IntroSceneCore_unk_6C62_OffsetCheck[offsetof(IntroSceneCore, unk_6C62) == INTRO_SCENE_CORE_UNK_6C62_OFFSET ? 1 : -1];
typedef char IntroSceneCore_sprite_matrix_OffsetCheck[offsetof(IntroSceneCore, sprite_matrix) == INTRO_SCENE_CORE_SPRITE_MATRIX_OFFSET ? 1 : -1];
typedef char IntroSceneCore_unk_6C6C_OffsetCheck[offsetof(IntroSceneCore, unk_6C6C) == INTRO_SCENE_CORE_UNK_6C6C_OFFSET ? 1 : -1];
typedef char IntroSceneCore_unk_6C6D_OffsetCheck[offsetof(IntroSceneCore, unk_6C6D) == INTRO_SCENE_CORE_UNK_6C6D_OFFSET ? 1 : -1];
typedef char IntroSceneCore_continuation_OffsetCheck[offsetof(IntroSceneCore, continuation) == INTRO_SCENE_CORE_CONTINUATION_OFFSET ? 1 : -1];
typedef char IntroSceneCore_unk_6C6F_OffsetCheck[offsetof(IntroSceneCore, unk_6C6F) == INTRO_SCENE_CORE_UNK_6C6F_OFFSET ? 1 : -1];
typedef char IntroSceneCore_state_reservation_OffsetCheck[offsetof(IntroSceneCore, state_reservation) == INTRO_SCENE_CORE_STATE_RESERVATION_OFFSET ? 1 : -1];
typedef char IntroSceneCore_pool_reservation_OffsetCheck[offsetof(IntroSceneCore, pool_reservation) == INTRO_SCENE_CORE_POOL_RESERVATION_OFFSET ? 1 : -1];
typedef char IntroSceneCore_state_handle_6C78_OffsetCheck[offsetof(IntroSceneCore, state_handle_6C78) == INTRO_SCENE_CORE_STATE_HANDLE_6C78_OFFSET ? 1 : -1];
typedef char IntroSceneCore_pool_handle_6C80_OffsetCheck[offsetof(IntroSceneCore, pool_handle_6C80) == INTRO_SCENE_CORE_POOL_HANDLE_6C80_OFFSET ? 1 : -1];
typedef char IntroSceneCore_state_handle_6C88_OffsetCheck[offsetof(IntroSceneCore, state_handle_6C88) == INTRO_SCENE_CORE_STATE_HANDLE_6C88_OFFSET ? 1 : -1];
typedef char IntroSceneCore_pool_handle_6C90_OffsetCheck[offsetof(IntroSceneCore, pool_handle_6C90) == INTRO_SCENE_CORE_POOL_HANDLE_6C90_OFFSET ? 1 : -1];
typedef char IntroSceneCore_state_handle_6C98_OffsetCheck[offsetof(IntroSceneCore, state_handle_6C98) == INTRO_SCENE_CORE_STATE_HANDLE_6C98_OFFSET ? 1 : -1];
typedef char IntroSceneCore_pool_handle_6CA0_OffsetCheck[offsetof(IntroSceneCore, pool_handle_6CA0) == INTRO_SCENE_CORE_POOL_HANDLE_6CA0_OFFSET ? 1 : -1];
typedef char IntroSceneCore_state_handle_6CA8_OffsetCheck[offsetof(IntroSceneCore, state_handle_6CA8) == INTRO_SCENE_CORE_STATE_HANDLE_6CA8_OFFSET ? 1 : -1];
typedef char IntroSceneCore_state_handle_6CB0_OffsetCheck[offsetof(IntroSceneCore, state_handle_6CB0) == INTRO_SCENE_CORE_STATE_HANDLE_6CB0_OFFSET ? 1 : -1];
typedef char IntroSceneCore_pool_handle_6CB8_OffsetCheck[offsetof(IntroSceneCore, pool_handle_6CB8) == INTRO_SCENE_CORE_POOL_HANDLE_6CB8_OFFSET ? 1 : -1];
typedef char IntroSceneCore_state_handle_6CC0_OffsetCheck[offsetof(IntroSceneCore, state_handle_6CC0) == INTRO_SCENE_CORE_STATE_HANDLE_6CC0_OFFSET ? 1 : -1];
typedef char IntroSceneCore_pool_handle_6CC8_OffsetCheck[offsetof(IntroSceneCore, pool_handle_6CC8) == INTRO_SCENE_CORE_POOL_HANDLE_6CC8_OFFSET ? 1 : -1];
typedef char IntroSceneCore_state_handle_6CD0_OffsetCheck[offsetof(IntroSceneCore, state_handle_6CD0) == INTRO_SCENE_CORE_STATE_HANDLE_6CD0_OFFSET ? 1 : -1];
typedef char IntroSceneCore_state_handle_6CD8_OffsetCheck[offsetof(IntroSceneCore, state_handle_6CD8) == INTRO_SCENE_CORE_STATE_HANDLE_6CD8_OFFSET ? 1 : -1];
typedef char IntroSceneCore_state_handle_6CE0_OffsetCheck[offsetof(IntroSceneCore, state_handle_6CE0) == INTRO_SCENE_CORE_STATE_HANDLE_6CE0_OFFSET ? 1 : -1];
typedef char IntroSceneCore_pool_handle_6CE8_OffsetCheck[offsetof(IntroSceneCore, pool_handle_6CE8) == INTRO_SCENE_CORE_POOL_HANDLE_6CE8_OFFSET ? 1 : -1];
typedef char IntroSceneCore_state_handle_6CF0_OffsetCheck[offsetof(IntroSceneCore, state_handle_6CF0) == INTRO_SCENE_CORE_STATE_HANDLE_6CF0_OFFSET ? 1 : -1];
typedef char IntroSceneCore_state_handle_6CF8_OffsetCheck[offsetof(IntroSceneCore, state_handle_6CF8) == INTRO_SCENE_CORE_STATE_HANDLE_6CF8_OFFSET ? 1 : -1];
typedef char IntroSceneCore_pool_handle_6D00_OffsetCheck[offsetof(IntroSceneCore, pool_handle_6D00) == INTRO_SCENE_CORE_POOL_HANDLE_6D00_OFFSET ? 1 : -1];
typedef char IntroSceneCore_state_handle_6D08_OffsetCheck[offsetof(IntroSceneCore, state_handle_6D08) == INTRO_SCENE_CORE_STATE_HANDLE_6D08_OFFSET ? 1 : -1];
typedef char IntroSceneCore_pool_handle_6D10_OffsetCheck[offsetof(IntroSceneCore, pool_handle_6D10) == INTRO_SCENE_CORE_POOL_HANDLE_6D10_OFFSET ? 1 : -1];
typedef char IntroSceneCore_state_handle_6D18_OffsetCheck[offsetof(IntroSceneCore, state_handle_6D18) == INTRO_SCENE_CORE_STATE_HANDLE_6D18_OFFSET ? 1 : -1];
typedef char IntroSceneCore_pool_handle_6D20_OffsetCheck[offsetof(IntroSceneCore, pool_handle_6D20) == INTRO_SCENE_CORE_POOL_HANDLE_6D20_OFFSET ? 1 : -1];
typedef char IntroSceneCore_run_state_OffsetCheck[offsetof(IntroSceneCore, run_state) == INTRO_SCENE_CORE_RUN_STATE_OFFSET ? 1 : -1];
typedef char IntroSceneCore_startup_hold_frames_OffsetCheck[offsetof(IntroSceneCore, startup_hold_frames) == INTRO_SCENE_CORE_STARTUP_HOLD_FRAMES_OFFSET ? 1 : -1];
typedef char IntroSceneCore_unk_6D30_OffsetCheck[offsetof(IntroSceneCore, unk_6D30) == INTRO_SCENE_CORE_UNK_6D30_OFFSET ? 1 : -1];
typedef char IntroSceneCore_startup_phase_OffsetCheck[offsetof(IntroSceneCore, startup_phase) == INTRO_SCENE_CORE_STARTUP_PHASE_OFFSET ? 1 : -1];

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

extern IntroSceneCoreVTable const gIntroSceneCoreVTable;
extern u8 const gIntroSceneIndexedArchiveCompressed[];
extern u8 const gIntroSceneSmallIndexedArchive[];
extern u8 const gActorIndexedResourceArchive[];
IntroSceneCore * ConstructIntroSceneCore(void * core);
void DestroyIntroSceneCore(IntroSceneCore * core, int flags) SECTION(".text.intro_scene_core_cleanup");
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
