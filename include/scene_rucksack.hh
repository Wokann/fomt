#ifndef SCENE_RUCKSACK_HH
#define SCENE_RUCKSACK_HH
#include "game_menu.hh"
#pragma interface "scene_rucksack.hh"

// This is the player's held tool, held item and rucksack menu. Its remaining
// menu/update logic is still native; no keyboard buffer belongs to this core.
struct RucksackMenuCore : GameSceneMenuSelectionCore {
    RucksackMenuCore(GameStateSaveImage * image);
    virtual ~RucksackMenuCore();
    void Run();

    u8 unk_98;
    u8 unk_99[0x63];
    ToolStack * held_tool;
    HeldItem * held_item;
    Rucksack * rucksack;
    u32 unk_108;
};
typedef char RucksackMenuCoreSizeCheck[sizeof(RucksackMenuCore) == 0x10C ? 1 : -1];
typedef char RucksackMenuCoreHeldToolCheck[offsetof(RucksackMenuCore, held_tool) == 0xFC ? 1 : -1];
typedef char RucksackMenuCoreHeldItemCheck[offsetof(RucksackMenuCore, held_item) == 0x100 ? 1 : -1];
typedef char RucksackMenuCoreRucksackCheck[offsetof(RucksackMenuCore, rucksack) == 0x104 ? 1 : -1];

struct RucksackMenuCoreOwner {
    RucksackMenuCore * value;
    explicit RucksackMenuCoreOwner(RucksackMenuCore * input) : value(input) {}
    ~RucksackMenuCoreOwner() { delete value; }
};

struct RucksackMenuScene : AScene {
    RucksackMenuScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~RucksackMenuScene();
    virtual SceneTransitionOwner Run();
    RucksackMenuCoreOwner core;
    SceneTransitionOwner continuation;
};
typedef char RucksackMenuSceneSizeCheck[sizeof(RucksackMenuScene) == 12 ? 1 : -1];
typedef char RucksackMenuSceneCoreCheck[offsetof(RucksackMenuScene, core) == 4 ? 1 : -1];
typedef char RucksackMenuSceneContinuationCheck[offsetof(RucksackMenuScene, continuation) == 8 ? 1 : -1];

struct RucksackMenuTransition : SceneTransition {
    RucksackMenuTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};
typedef char RucksackMenuTransitionSizeCheck[sizeof(RucksackMenuTransition) == 12 ? 1 : -1];
typedef char RucksackMenuTransitionContinuationCheck[offsetof(RucksackMenuTransition, continuation) == 4 ? 1 : -1];
typedef char RucksackMenuTransitionSaveCheck[offsetof(RucksackMenuTransition, save) == 8 ? 1 : -1];
#pragma implementation
#endif
