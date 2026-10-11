#ifndef NEW_GAME_HH
#define NEW_GAME_HH

#include "prelude.h"
#include "hardware_bootstrap.hh"
#include "hardware_state_clear.hh"
#include "hardware_resource.hh"
#include "resource_handle.hh"
#include "scene.hh"

struct MusicPlayer;

// Runtime save-summary text, filled by func_08003788 and selected by the
// menu's second choice. These two 128-byte buffers are not ROM literals.
struct NewGameMenuSaveSlotStatus {
    char text[0x80];

    bool IsEmpty() const { return text[0] == '\0'; }
    char const * Data() const { return text; }
};

typedef char NewGameMenuSaveSlotStatusSizeCheck[sizeof(NewGameMenuSaveSlotStatus) == 0x80 ? 1 : -1];

// The menu constructor allocates 0x1A0 bytes. Only fields confirmed by its
// constructor, cleanup, and hardware/UI consumers are modeled here; the
// remaining payload is not yet a recovered high-level class.
struct NewGameMenuCore : HardwareBootstrap {
    void * unk_08;
    SceneTransitionOwner continuation;
    u8 * unk_10; // Owned 0x554-byte UI payload; its full layout is unresolved.
    MusicPlayer * music_players[2];
    IndexedResourceArchive resources;
    HardwareStateEntry state_entry;
    HardwareResourceEntry resource_entry;
    u32 unk_5C[2];
    u8 unk_64[0x1C];
    u32 active_row;
    u8 choices[6];
    u8 unk_8A[0x0E];
    NewGameMenuSaveSlotStatus save_slot_status[2];
    u8 unk_198[8];
};

typedef char NewGameMenuCoreSizeCheck[sizeof(NewGameMenuCore) == 0x1A0 ? 1 : -1];
typedef char NewGameMenuCoreUiCheck[offsetof(NewGameMenuCore, unk_10) == 0x10 ? 1 : -1];
typedef char NewGameMenuCoreMusicCheck[offsetof(NewGameMenuCore, music_players) == 0x14 ? 1 : -1];
typedef char NewGameMenuCoreResourcesCheck[offsetof(NewGameMenuCore, resources) == 0x1C ? 1 : -1];
typedef char NewGameMenuCoreStateEntryCheck[offsetof(NewGameMenuCore, state_entry) == 0x4C ? 1 : -1];
typedef char NewGameMenuCoreResourceEntryCheck[offsetof(NewGameMenuCore, resource_entry) == 0x54 ? 1 : -1];
typedef char NewGameMenuCoreActiveRowCheck[offsetof(NewGameMenuCore, active_row) == 0x80 ? 1 : -1];
typedef char NewGameMenuCoreChoicesCheck[offsetof(NewGameMenuCore, choices) == 0x84 ? 1 : -1];
typedef char NewGameMenuCoreSaveSlotStatusCheck[offsetof(NewGameMenuCore, save_slot_status) == 0x98 ? 1 : -1];

// Original ABI tables contain two metadata words before their callbacks.
typedef void (*NewGameSceneVTableFunction)(void);

struct NewGameMenuScene {
    NewGameSceneVTableFunction const * vtable;
    NewGameMenuCore * core;
};

struct NewGameNameEntryScene {
    NewGameSceneVTableFunction const * vtable;
};

typedef char NewGameMenuSceneSizeCheck[sizeof(NewGameMenuScene) == 8 ? 1 : -1];
typedef char NewGameNameEntrySceneSizeCheck[sizeof(NewGameNameEntryScene) == 4 ? 1 : -1];

EXTERN_C

// Both menu transitions wait until their stack-owned blend command leaves
// the hardware queue. The first decreases progress; the second increases it.
void func_08003B40(struct HardwareBootstrap * core);
void func_08003BB4(struct HardwareBootstrap * core);
void func_08003C28(struct NewGameMenuCore * core);

// The surrounding label graphics and OAM updates remain assembly.
void func_08003EEC(struct NewGameMenuCore * core)
    SECTION(".text.new_game_status_update");

// The core constructor consumes *continuation, clears that word, and stores
// the transition at core +0x0C. Its remaining body is still assembly.
NewGameMenuCore * func_080041DC(void * object, void * state,
    SceneTransition ** continuation);
SceneTransitionOwner func_08004570(struct NewGameMenuCore * core);
AScene * func_08004B58(void * object)
    SECTION(".text.new_game_scene_lifecycle");
AScene * func_08004B94(void * object, void * state, SceneTransitionOwner continuation)
    SECTION(".text.new_game_scene_lifecycle");

extern NewGameSceneVTableFunction const vtable_unk_080E5A3C[];
extern NewGameSceneVTableFunction const vtable_unk_080E5A68[];
extern NewGameSceneVTableFunction const vtable_unk_080E5A88[];

// One contiguous scene lifecycle interval, beginning with both constructors.
void func_08004BDC(struct NewGameMenuScene * scene, int flags)
    SECTION(".text.new_game_scene_lifecycle");
SceneTransitionOwner func_08004C0C(struct NewGameMenuScene * scene)
    SECTION(".text.new_game_scene_lifecycle");
AScene * func_08004C48(void * object)
    SECTION(".text.new_game_scene_lifecycle");
void func_08004C54(struct NewGameNameEntryScene * scene, int flags)
    SECTION(".text.new_game_scene_lifecycle");

EXTERN_C_END

#endif // NEW_GAME_HH
