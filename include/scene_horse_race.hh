#ifndef SCENE_HORSE_RACE_HH
#define SCENE_HORSE_RACE_HH

#include "scene.hh"
#include "hardware_context.hh"
#include "hardware_music_player.hh"
#include "resource_archive.hh"
#include "resource_handle.hh"

struct UiStateOwner;


struct GameStateSaveImage;
struct HorseRaceCore;

#pragma interface "scene_horse_race.hh"

// The wrapper constructor, destructor, and Run body remain native assembly.
struct HorseRaceScene : AScene {
    HorseRaceScene(SceneTransitionOwner next, GameStateSaveImage * image, bool compete);
    virtual ~HorseRaceScene();
    virtual SceneTransitionOwner Run();

    HorseRaceCore * core;
    SceneTransitionOwner continuation;
};

struct HorseRaceTransition : SceneTransition {
    HorseRaceTransition(SceneTransitionOwner next, GameStateSaveImage * image, bool compete)
        : continuation(next), save(image), player_competes(compete) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    bool player_competes;
};

typedef char HorseRaceSceneSizeCheck[sizeof(HorseRaceScene) == 12 ? 1 : -1];
typedef char HorseRaceSceneCoreCheck[offsetof(HorseRaceScene, core) == 4 ? 1 : -1];
typedef char HorseRaceSceneContinuationCheck[offsetof(HorseRaceScene, continuation) == 8 ? 1 : -1];
typedef char HorseRaceTransitionSizeCheck[sizeof(HorseRaceTransition) == 16 ? 1 : -1];
typedef char HorseRaceTransitionContinuationCheck[offsetof(HorseRaceTransition, continuation) == 4 ? 1 : -1];
typedef char HorseRaceTransitionSaveCheck[offsetof(HorseRaceTransition, save) == 8 ? 1 : -1];
typedef char HorseRaceTransitionModeCheck[offsetof(HorseRaceTransition, player_competes) == 12 ? 1 : -1];

// The allocation bound and initialized prefix agree in all four native ROMs.
// unk_... is unparsed runtime storage, not padding or recovered ROM data.
struct HorseRaceMedalExchangeCore : HardwareContext {
    HorseRaceMedalExchangeCore(GameStateSaveImage * image);
    virtual ~HorseRaceMedalExchangeCore();
    SceneTransitionOwner Run();
    GameStateSaveImage * save;
    u32 unk_00C;
    UiStateOwner * ui_state;
    HardwareMusicPlayerSlot music_players[3];
    IndexedResourceArchive unk_archive_020;
    IndexedResourceArchive cursor_archive;
    u8 unk_080[0xAF4 - 0x80];
};

typedef char HorseRaceMedalExchangeCoreSizeCheck[sizeof(HorseRaceMedalExchangeCore) == 0xAF4 ? 1 : -1];
typedef char HorseRaceMedalExchangeCoreSaveCheck[offsetof(HorseRaceMedalExchangeCore, save) == 8 ? 1 : -1];
typedef char HorseRaceMedalExchangeCoreOffset_unk_00C[offsetof(HorseRaceMedalExchangeCore, unk_00C) == 0xC ? 1 : -1];
typedef char HorseRaceMedalExchangeCoreOffset_ui_state[offsetof(HorseRaceMedalExchangeCore, ui_state) == 0x10 ? 1 : -1];
typedef char HorseRaceMedalExchangeCoreOffset_music_players[offsetof(HorseRaceMedalExchangeCore, music_players) == 0x14 ? 1 : -1];
typedef char HorseRaceMedalExchangeCoreOffset_unk_archive_020[offsetof(HorseRaceMedalExchangeCore, unk_archive_020) == 0x20 ? 1 : -1];
typedef char HorseRaceMedalExchangeCoreOffset_cursor_archive[offsetof(HorseRaceMedalExchangeCore, cursor_archive) == 0x50 ? 1 : -1];
typedef char HorseRaceMedalExchangeCoreOffset_unk_080[offsetof(HorseRaceMedalExchangeCore, unk_080) == 0x80 ? 1 : -1];

// The scene destroys its continuation first, then this owned core.
struct HorseRaceMedalExchangeCoreOwner {
    explicit HorseRaceMedalExchangeCoreOwner(HorseRaceMedalExchangeCore * core) : value(core) {}
    ~HorseRaceMedalExchangeCoreOwner() { delete value; }
    HorseRaceMedalExchangeCore * operator->() const { return value; }
    HorseRaceMedalExchangeCore * value;
private:
    HorseRaceMedalExchangeCoreOwner(HorseRaceMedalExchangeCoreOwner const &);
    HorseRaceMedalExchangeCoreOwner & operator=(HorseRaceMedalExchangeCoreOwner const &);
};
typedef char HorseRaceMedalExchangeCoreOwnerSizeCheck[sizeof(HorseRaceMedalExchangeCoreOwner) == 4 ? 1 : -1];


struct HorseRaceMedalExchangeScene : AScene {
    HorseRaceMedalExchangeScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~HorseRaceMedalExchangeScene();
    virtual SceneTransitionOwner Run();
    HorseRaceMedalExchangeCoreOwner core;
    SceneTransitionOwner continuation;
};

struct HorseRaceMedalExchangeTransition : SceneTransition {
    HorseRaceMedalExchangeTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char HorseRaceMedalExchangeSceneSizeCheck[sizeof(HorseRaceMedalExchangeScene) == 12 ? 1 : -1];
typedef char HorseRaceMedalExchangeSceneCoreCheck[offsetof(HorseRaceMedalExchangeScene, core) == 4 ? 1 : -1];
typedef char HorseRaceMedalExchangeSceneContinuationCheck[offsetof(HorseRaceMedalExchangeScene, continuation) == 8 ? 1 : -1];
typedef char HorseRaceMedalExchangeTransitionSizeCheck[sizeof(HorseRaceMedalExchangeTransition) == 12 ? 1 : -1];
typedef char HorseRaceMedalExchangeTransitionContinuationCheck[offsetof(HorseRaceMedalExchangeTransition, continuation) == 4 ? 1 : -1];
typedef char HorseRaceMedalExchangeTransitionSaveCheck[offsetof(HorseRaceMedalExchangeTransition, save) == 8 ? 1 : -1];

// Direct ABI declaration of this compiler constructor, not a wrapper.
// Retained until ordinary owner-return lowering matches the native factory.
// The second argument is the actual single-word continuation transfer slot.
extern "C" HorseRaceMedalExchangeScene * __27HorseRaceMedalExchangeSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * storage, SceneTransition ** next, GameStateSaveImage * image);

#endif
