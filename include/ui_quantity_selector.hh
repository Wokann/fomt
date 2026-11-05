#ifndef UI_QUANTITY_SELECTOR_HH
#define UI_QUANTITY_SELECTOR_HH

#include "prelude.h"
#include "hardware_music_player.hh"
#include "scroll_state.hh"

struct UiSceneCore;
struct GameStateSaveImage;
struct HardwareCoreState;

// Non-owning layout view of the first 0x20 bytes. Do not allocate it as a
// complete scene: the remaining common-core state is still native.
struct UiSceneCorePrefix {
    HardwareCoreState * hardware;
    void const * vtable;
    GameStateSaveImage * save;
    u16 unk_0C;
    u32 unk_10;
    i32 unk_14;
    HardwareMusicPlayerSlot music;
    ScrollState * scroll;
};

struct UiPurchaseQuantitySelector {
    // Construction still uses its named native body.
    explicit UiPurchaseQuantitySelector(UiSceneCore * owner);
    void Configure(u32 price, u32 available, u32 column);
    void Update();
    void Hide();

    u32 unit_price;
    u32 maximum;
    bool active;
    u32 row;
    u32 column;
    u32 quantity;
    UiSceneCorePrefix * scene;
};

typedef char UiQuantitySize[sizeof(UiPurchaseQuantitySelector) == 28 ? 1 : -1];
typedef char UiQuantityOwner[offsetof(UiPurchaseQuantitySelector, scene) == 24 ? 1 : -1];
typedef char UiScenePrefixSize[sizeof(UiSceneCorePrefix) == 32 ? 1 : -1];
typedef char UiScenePrefixSave[offsetof(UiSceneCorePrefix, save) == 8 ? 1 : -1];
typedef char UiScenePrefixMusic[offsetof(UiSceneCorePrefix, music) == 24 ? 1 : -1];
typedef char UiScenePrefixScroll[offsetof(UiSceneCorePrefix, scroll) == 28 ? 1 : -1];

#endif // UI_QUANTITY_SELECTOR_HH
