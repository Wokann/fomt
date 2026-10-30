#ifndef SCENE_FRISBEE_HH
#define SCENE_FRISBEE_HH

#include "scene.hh"
#include "hardware_bootstrap.hh"
#include "hardware_music_player.hh"
#include "resource_archive.hh"

struct UiStateOwner;

struct GameStateSaveImage;
#pragma interface "scene_frisbee.hh"

// The allocation bound and initialized prefix agree in all four native ROMs.
// unk_... is unparsed runtime storage, not padding or recovered ROM data.
struct FrisbeeCore : HardwareBootstrap {
    FrisbeeCore(GameStateSaveImage * image, bool contest);
    virtual ~FrisbeeCore();
    SceneTransitionOwner Run();
    GameStateSaveImage * save;
    u32 unk_00C;
    UiStateOwner * ui_state;
    HardwareMusicPlayerSlot music_players[3];
    IndexedResourceArchive actor_archive;
    IndexedResourceArchive unk_archive_050;
    u8 unk_080[0x23A8 - 0x80];
};

typedef char FrisbeeCoreSizeCheck[sizeof(FrisbeeCore) == 0x23A8 ? 1 : -1];
typedef char FrisbeeCoreSaveCheck[offsetof(FrisbeeCore, save) == 8 ? 1 : -1];
typedef char FrisbeeCoreOffset_unk_00C[offsetof(FrisbeeCore, unk_00C) == 0xC ? 1 : -1];
typedef char FrisbeeCoreOffset_ui_state[offsetof(FrisbeeCore, ui_state) == 0x10 ? 1 : -1];
typedef char FrisbeeCoreOffset_music_players[offsetof(FrisbeeCore, music_players) == 0x14 ? 1 : -1];
typedef char FrisbeeCoreOffset_actor_archive[offsetof(FrisbeeCore, actor_archive) == 0x20 ? 1 : -1];
typedef char FrisbeeCoreOffset_unk_archive_050[offsetof(FrisbeeCore, unk_archive_050) == 0x50 ? 1 : -1];
typedef char FrisbeeCoreOffset_unk_080[offsetof(FrisbeeCore, unk_080) == 0x80 ? 1 : -1];

// The scene destroys its continuation first, then this owned core.
struct FrisbeeCoreOwner {
    explicit FrisbeeCoreOwner(FrisbeeCore * core) : value(core) {}
    ~FrisbeeCoreOwner() { delete value; }
    FrisbeeCore * operator->() const { return value; }
    FrisbeeCore * value;
private:
    FrisbeeCoreOwner(FrisbeeCoreOwner const &);
    FrisbeeCoreOwner & operator=(FrisbeeCoreOwner const &);
};
typedef char FrisbeeCoreOwnerSizeCheck[sizeof(FrisbeeCoreOwner) == 4 ? 1 : -1];

struct FrisbeeScene : AScene {
    FrisbeeScene(SceneTransitionOwner next, GameStateSaveImage * image, bool contest);
    virtual ~FrisbeeScene();
    virtual SceneTransitionOwner Run();
    FrisbeeCoreOwner core;
    SceneTransitionOwner continuation;
};

struct FrisbeeTransition : SceneTransition {
    FrisbeeTransition(SceneTransitionOwner next, GameStateSaveImage * image, bool contest)
        : continuation(next), save(image), contest_mode(contest) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    bool contest_mode;
};

typedef char FrisbeeSceneSizeCheck[sizeof(FrisbeeScene) == 12 ? 1 : -1];
typedef char FrisbeeSceneCoreCheck[offsetof(FrisbeeScene, core) == 4 ? 1 : -1];
typedef char FrisbeeSceneContinuationCheck[offsetof(FrisbeeScene, continuation) == 8 ? 1 : -1];
typedef char FrisbeeTransitionSizeCheck[sizeof(FrisbeeTransition) == 16 ? 1 : -1];
typedef char FrisbeeTransitionContinuationCheck[offsetof(FrisbeeTransition, continuation) == 4 ? 1 : -1];
typedef char FrisbeeTransitionSaveCheck[offsetof(FrisbeeTransition, save) == 8 ? 1 : -1];
typedef char FrisbeeTransitionModeCheck[offsetof(FrisbeeTransition, contest_mode) == 12 ? 1 : -1];

#endif // SCENE_FRISBEE_HH
