#ifndef NEW_GAME_HH
#define NEW_GAME_HH

#include "prelude.h"
#include "game_state.hh"
#include "hardware_bootstrap.hh"
#include "hardware_state_clear.hh"
#include "hardware_resource.hh"
#include "resource_handle.hh"
#include "scene.hh"
#include "sram_proxy_2.hh"
#include "ui_state.hh"

struct MusicPlayer;

// Menu OAM coordinates use their wrapped hardware representation, not the
// signed offsets stored in sprite archives. Only the first six bytes are
// copied to OAM; the destination's affine coefficient is left untouched.
struct NewGameMenuSpriteAttributes {
    u32 y : 8;
    u32 affine_mode : 2;
    u32 object_mode : 2;
    u32 mosaic : 1;
    u32 color_mode : 1;
    u32 shape : 2;
    u32 x : 9;
    u32 affine_index_low : 3;
    u32 horizontal_flip : 1;
    u32 vertical_flip : 1;
    u32 size : 2;
    u16 tile_attributes;
    u16 affine_coefficient;
};

typedef char NewGameMenuSpriteAttributesSizeCheck[sizeof(NewGameMenuSpriteAttributes) == 8 ? 1 : -1];
typedef char NewGameMenuSpriteAttributesTileCheck[offsetof(NewGameMenuSpriteAttributes, tile_attributes) == 4 ? 1 : -1];
typedef char NewGameMenuSpriteAttributesCoefficientCheck[offsetof(NewGameMenuSpriteAttributes, affine_coefficient) == 6 ? 1 : -1];

// Runtime save-summary text, filled by func_08003788 and selected by the
// menu's second choice. These two 128-byte buffers are not ROM literals.
struct NewGameMenuSaveSlotStatus {
    char text[0x80];

    NewGameMenuSaveSlotStatus() { text[0] = '\0'; }
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
    UiStateOwner ui_state;
    MusicPlayer * music_players[2];
    IndexedResourceArchive resources;
    HardwareStateEntry state_entry;
    HardwareResourceEntry resource_entry;
    HardwareSpriteOamRecord option_attributes;
    IndexedResourceHandle selector_resource;
    HardwareSpriteOamRecord selector_attributes;
    u32 active_row;
    u8 choices[6];
    u8 unk_8A[2];
    u32 unk_8C;
    SramAccess sram;
    NewGameMenuSaveSlotStatus save_slot_status[2];
    GameDisplayOptions saved_display_options[2];
};

typedef char NewGameMenuCoreSizeCheck[sizeof(NewGameMenuCore) == 0x1A0 ? 1 : -1];
typedef char NewGameMenuCoreUiCheck[offsetof(NewGameMenuCore, ui_state) == 0x10 ? 1 : -1];
typedef char NewGameMenuCoreMusicCheck[offsetof(NewGameMenuCore, music_players) == 0x14 ? 1 : -1];
typedef char NewGameMenuCoreResourcesCheck[offsetof(NewGameMenuCore, resources) == 0x1C ? 1 : -1];
typedef char NewGameMenuCoreStateEntryCheck[offsetof(NewGameMenuCore, state_entry) == 0x4C ? 1 : -1];
typedef char NewGameMenuCoreResourceEntryCheck[offsetof(NewGameMenuCore, resource_entry) == 0x54 ? 1 : -1];
typedef char NewGameMenuCoreOptionAttributesCheck[offsetof(NewGameMenuCore, option_attributes) == 0x5C ? 1 : -1];
typedef char NewGameMenuCoreSelectorResourceCheck[offsetof(NewGameMenuCore, selector_resource) == 0x64 ? 1 : -1];
typedef char NewGameMenuCoreSelectorAttributesCheck[offsetof(NewGameMenuCore, selector_attributes) == 0x78 ? 1 : -1];
typedef char NewGameMenuCoreActiveRowCheck[offsetof(NewGameMenuCore, active_row) == 0x80 ? 1 : -1];
typedef char NewGameMenuCoreChoicesCheck[offsetof(NewGameMenuCore, choices) == 0x84 ? 1 : -1];
typedef char NewGameMenuCoreUnk8CCheck[offsetof(NewGameMenuCore, unk_8C) == 0x8C ? 1 : -1];
typedef char NewGameMenuCoreSramCheck[offsetof(NewGameMenuCore, sram) == 0x90 ? 1 : -1];
typedef char NewGameMenuCoreSaveSlotStatusCheck[offsetof(NewGameMenuCore, save_slot_status) == 0x98 ? 1 : -1];
typedef char NewGameMenuCoreSavedDisplayOptionsCheck[offsetof(NewGameMenuCore, saved_display_options) == 0x198 ? 1 : -1];

// Original ABI tables contain two metadata words before their callbacks.
typedef void (*NewGameSceneVTableFunction)(void);

// This one-word owner scopes the allocation returned by the save read. Its
// layout stays opaque; cleanup uses the existing image destructor. Failed
// reads release the allocation for the caller's original raw-delete path.
class NewGameLoadedSaveOwner {
public:
    explicit NewGameLoadedSaveOwner(void * state) : value(state) {}
    ~NewGameLoadedSaveOwner()
    {
        if (value != nullptr)
            func_080D4480(value, 3);
    }
    void * get() const { return value; }
    void * release()
    {
        void * state = value;
        value = nullptr;
        return state;
    }

private:
    void * value;
    NewGameLoadedSaveOwner(NewGameLoadedSaveOwner const &);
    NewGameLoadedSaveOwner & operator=(NewGameLoadedSaveOwner const &);
};

// The existing +0x0C virtual callback creates the next game scene; its
// destructor cleans up the save image stored immediately after the vtable.
struct NewGameLoadedSaveTransition {
    NewGameSceneVTableFunction const * vtable;
    void * state;
};

typedef char NewGameLoadedSaveOwnerSizeCheck[sizeof(NewGameLoadedSaveOwner) == 4 ? 1 : -1];
typedef char NewGameLoadedSaveTransitionSizeCheck[sizeof(NewGameLoadedSaveTransition) == 8 ? 1 : -1];
typedef char NewGameLoadedSaveTransitionStateCheck[offsetof(NewGameLoadedSaveTransition, state) == 4 ? 1 : -1];

struct NewGameMenuScene {
    NewGameSceneVTableFunction const * vtable;
    NewGameMenuCore * core;
};

struct NewGameNameEntryScene {
    NewGameSceneVTableFunction const * vtable;
};

// The identity-confirmation form owns a 0x1878-byte JP core or a 0x1A78-byte
// overseas core. Its full resource and text-buffer layout still remains
// assembly; only the directly verified owner/music pointers and control bytes are
// exposed here. The opaque tail names retain their US offsets.
struct NewGameIdentityCore : HardwareBootstrap {
#if defined(REGION_JP)
    u8 unk_08[0x1824];
#else
    u8 unk_08[0x1A24];
#endif
    UiStateOwner * ui_state;
    MusicPlayer * music;
    u8 unk_1A34[0x40];
    u8 unk_1A74;
    u8 unk_1A75;
    u8 unk_1A76;
    u8 unk_1A77;
};

struct NewGameIdentityScene {
    NewGameSceneVTableFunction const * vtable;
    NewGameIdentityCore * core;
};

typedef char NewGameMenuSceneSizeCheck[sizeof(NewGameMenuScene) == 8 ? 1 : -1];
typedef char NewGameNameEntrySceneSizeCheck[sizeof(NewGameNameEntryScene) == 4 ? 1 : -1];
#if defined(REGION_JP)
typedef char NewGameIdentityCoreSizeCheck[sizeof(NewGameIdentityCore) == 0x1878 ? 1 : -1];
typedef char NewGameIdentityCoreUiCheck[offsetof(NewGameIdentityCore, ui_state) == 0x182C ? 1 : -1];
typedef char NewGameIdentityCoreMusicCheck[offsetof(NewGameIdentityCore, music) == 0x1830 ? 1 : -1];
typedef char NewGameIdentityCoreControlCheck[offsetof(NewGameIdentityCore, unk_1A74) == 0x1874 ? 1 : -1];
typedef char NewGameIdentityCoreResultCheck[offsetof(NewGameIdentityCore, unk_1A76) == 0x1876 ? 1 : -1];
#else
typedef char NewGameIdentityCoreSizeCheck[sizeof(NewGameIdentityCore) == 0x1A78 ? 1 : -1];
typedef char NewGameIdentityCoreUiCheck[offsetof(NewGameIdentityCore, ui_state) == 0x1A2C ? 1 : -1];
typedef char NewGameIdentityCoreMusicCheck[offsetof(NewGameIdentityCore, music) == 0x1A30 ? 1 : -1];
typedef char NewGameIdentityCoreControlCheck[offsetof(NewGameIdentityCore, unk_1A74) == 0x1A74 ? 1 : -1];
typedef char NewGameIdentityCoreResultCheck[offsetof(NewGameIdentityCore, unk_1A76) == 0x1A76 ? 1 : -1];
#endif
typedef char NewGameIdentitySceneSizeCheck[sizeof(NewGameIdentityScene) == 8 ? 1 : -1];
typedef char NewGameIdentitySceneCoreCheck[offsetof(NewGameIdentityScene, core) == 4 ? 1 : -1];

EXTERN_C

// Both menu transitions wait until their stack-owned blend command leaves
// the hardware queue. The first decreases progress; the second increases it.
void func_08003B40(struct HardwareBootstrap * core);
void func_08003BB4(struct HardwareBootstrap * core);
void func_08003C28(struct NewGameMenuCore * core);

// One contiguous interval: option OAM, selector OAM, status, saving, loading,
// and core construction.
// The preceding label graphics renderer still remains assembly.
void func_08003DF0(struct NewGameMenuCore * core, u32 row,
    NewGameMenuSpriteAttributes attributes)
    SECTION(".text.new_game_menu_update");
void func_08003E88(struct NewGameMenuCore * core, u32 row,
    NewGameMenuSpriteAttributes const initial)
    SECTION(".text.new_game_menu_update");
void func_08003EEC(struct NewGameMenuCore * core)
    SECTION(".text.new_game_menu_update");
bool func_08003F9C(struct NewGameMenuCore * core)
    SECTION(".text.new_game_menu_update");
bool func_080040A0(struct NewGameMenuCore * core)
    SECTION(".text.new_game_menu_update");

// Formats one runtime save-summary buffer; the source image's full layout
// and the formatter body still remain unresolved assembly.
void func_08003788(struct NewGameMenuCore * core,
    NewGameMenuSaveSlotStatus & output, void const * snapshot);

// Initialize the supplied storage and consume the transition pointer word.
// This explicit pointer-reference view preserves the native ownership ABI;
// cleanup of the consumed input also belongs to the callee.
NewGameMenuCore * func_080041DC(NewGameMenuCore * core, void * state,
    SceneTransition *& continuation)
    SECTION(".text.new_game_menu_update");
SceneTransitionOwner func_08004570(struct NewGameMenuCore * core);
AScene * func_08004B58(void * object)
    SECTION(".text.new_game_scene_lifecycle");
AScene * func_08004B94(void * object, void * state, SceneTransitionOwner continuation)
    SECTION(".text.new_game_scene_lifecycle");

extern NewGameSceneVTableFunction const vtable_unk_080E5A3C[];
extern NewGameSceneVTableFunction const vtable_unk_080E5A4C[];
extern NewGameSceneVTableFunction const vtable_unk_080E5A5C[];
extern NewGameSceneVTableFunction const vtable_unk_080E5A68[];
extern NewGameSceneVTableFunction const vtable_unk_080E5A88[];
extern u8 const gUiHandCursorArchive[];

// One contiguous scene lifecycle interval, beginning with both constructors.
void func_08004BDC(struct NewGameMenuScene * scene, int flags)
    SECTION(".text.new_game_scene_lifecycle");
SceneTransitionOwner func_08004C0C(struct NewGameMenuScene * scene)
    SECTION(".text.new_game_scene_lifecycle");
AScene * func_08004C48(void * object)
    SECTION(".text.new_game_scene_lifecycle");
void func_08004C54(struct NewGameNameEntryScene * scene, int flags)
    SECTION(".text.new_game_scene_lifecycle");

// Native form construction and UI setup still remain assembly. The
// running core and scene below share their real allocation and return-owner ABI.
NewGameIdentityCore * func_08004EFC(NewGameIdentityCore * core,
    char const * player_name, u32 birthday, char const * farm_name, char const * dog_name);
void func_080050C8(NewGameIdentityCore * core, int flags)
    SECTION(".text.new_game_identity_core_cleanup");
SceneTransitionOwner func_080050F8(NewGameIdentityCore * core)
    SECTION(".text.new_game_identity_core_run");
void func_08005254(NewGameIdentityCore * core)
    SECTION(".text.new_game_identity_core_initialization");
void func_08005260(NewGameIdentityCore * core)
    SECTION(".text.new_game_identity_core_initialization");
void func_08005278(NewGameIdentityCore * core);
void func_08005800(NewGameIdentityCore * core)
    SECTION(".text.new_game_identity_core_update");
extern NewGameSceneVTableFunction const vtable_unk_080E5A98[];
extern NewGameSceneVTableFunction const vtable_unk_080E5AA4[];

// One consecutive scene interval: construction, cleanup, running and the
// two native byte-result accessors. Its core remains an incomplete field view.
NewGameIdentityScene * func_0800598C(NewGameIdentityScene * scene,
    char const * player_name, u32 birthday, char const * farm_name, char const * dog_name)
    SECTION(".text.new_game_identity_scene");
void func_080059D0(NewGameIdentityScene * scene, int flags)
    SECTION(".text.new_game_identity_scene");
SceneTransitionOwner func_08005A00(NewGameIdentityScene * scene)
    SECTION(".text.new_game_identity_scene");
u8 func_08005A3C(NewGameIdentityScene const * scene)
    SECTION(".text.new_game_identity_scene");
u8 func_08005A4C(NewGameIdentityCore const * core)
    SECTION(".text.new_game_identity_scene");

EXTERN_C_END

#endif // NEW_GAME_HH
