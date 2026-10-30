#ifndef SCENE_FRISBEE_HH
#define SCENE_FRISBEE_HH

#include "scene.hh"
#include "hardware_bootstrap.hh"
#include "hardware_music_player.hh"
#include "resource_archive.hh"
#include "resource_handle.hh"
#include "hardware_input.hh"
#include "hardware_resource.hh"
#include "hardware_state_clear.hh"

extern u8 const gUnk_08527094[];

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

// Each resource handle is followed by its native sprite parameters.
// The final word is not initialized by this constructor; its meaning is unknown.
struct FrisbeeTournamentSpriteState {
    IndexedResourceHandle resource;
    IndexedResourceSpriteParameters parameters;
    u32 unk_30;
    FrisbeeTournamentSpriteState(IndexedResourceProvider * archive, u32 index)
        : resource(archive, index, 256), parameters() {}
};

typedef char FrisbeeTournamentSpriteStateSizeCheck[sizeof(FrisbeeTournamentSpriteState) == 0x34 ? 1 : -1];
typedef char FrisbeeTournamentSpriteParametersCheck[offsetof(FrisbeeTournamentSpriteState, parameters) == 0x14 ? 1 : -1];
typedef char FrisbeeTournamentSpriteUnknownCheck[offsetof(FrisbeeTournamentSpriteState, unk_30) == 0x30 ? 1 : -1];

// Unknown bytes below are runtime RAM, not recovered ROM data or padding.
struct FrisbeeTournamentCore : HardwareBootstrap {
    FrisbeeTournamentCore(GameStateSaveImage * image);
    SceneTransitionOwner Run();
    GameStateSaveImage * save;
    HardwareMusicPlayerSlot music_player;
    IndexedResourceArchive unk_archive_010;
    FrisbeeTournamentSpriteState sprite_040;
    FrisbeeTournamentSpriteState sprite_074;
    HardwareStateEntry sprite_tiles;
    HardwareResourceEntry hardware_resource;
    u8 unk_0B8[0x800];
    u16 unk_8B8;
    u32 unk_8BC;
};

typedef char FrisbeeTournamentCoreSizeCheck[sizeof(FrisbeeTournamentCore) == 0x8C0 ? 1 : -1];
typedef char FrisbeeTournamentCoreOffset_save[offsetof(FrisbeeTournamentCore, save) == 0x8 ? 1 : -1];
typedef char FrisbeeTournamentCoreOffset_music_player[offsetof(FrisbeeTournamentCore, music_player) == 0xC ? 1 : -1];
typedef char FrisbeeTournamentCoreOffset_unk_archive_010[offsetof(FrisbeeTournamentCore, unk_archive_010) == 0x10 ? 1 : -1];
typedef char FrisbeeTournamentCoreOffset_sprite_040[offsetof(FrisbeeTournamentCore, sprite_040) == 0x40 ? 1 : -1];
typedef char FrisbeeTournamentCoreOffset_sprite_074[offsetof(FrisbeeTournamentCore, sprite_074) == 0x74 ? 1 : -1];
typedef char FrisbeeTournamentCoreOffset_sprite_tiles[offsetof(FrisbeeTournamentCore, sprite_tiles) == 0xA8 ? 1 : -1];
typedef char FrisbeeTournamentCoreOffset_hardware_resource[offsetof(FrisbeeTournamentCore, hardware_resource) == 0xB0 ? 1 : -1];
typedef char FrisbeeTournamentCoreOffset_unk_0B8[offsetof(FrisbeeTournamentCore, unk_0B8) == 0xB8 ? 1 : -1];
typedef char FrisbeeTournamentCoreOffset_unk_8B8[offsetof(FrisbeeTournamentCore, unk_8B8) == 0x8B8 ? 1 : -1];
typedef char FrisbeeTournamentCoreOffset_unk_8BC[offsetof(FrisbeeTournamentCore, unk_8BC) == 0x8BC ? 1 : -1];

// The scene destroys its continuation first, then this owned core.
struct FrisbeeTournamentCoreOwner {
    explicit FrisbeeTournamentCoreOwner(FrisbeeTournamentCore * core) : value(core) {}
    ~FrisbeeTournamentCoreOwner() { delete value; }
    FrisbeeTournamentCore * operator->() const { return value; }
    FrisbeeTournamentCore * value;
private:
    FrisbeeTournamentCoreOwner(FrisbeeTournamentCoreOwner const &);
    FrisbeeTournamentCoreOwner & operator=(FrisbeeTournamentCoreOwner const &);
};
typedef char FrisbeeTournamentCoreOwnerSizeCheck[sizeof(FrisbeeTournamentCoreOwner) == 4 ? 1 : -1];


struct FrisbeeTournamentScene : AScene {
    FrisbeeTournamentScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~FrisbeeTournamentScene();
    virtual SceneTransitionOwner Run();
    FrisbeeTournamentCoreOwner core;
    SceneTransitionOwner continuation;
};

struct FrisbeeTournamentTransition : SceneTransition {
    FrisbeeTournamentTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char FrisbeeTournamentSceneSizeCheck[sizeof(FrisbeeTournamentScene) == 12 ? 1 : -1];
typedef char FrisbeeTournamentSceneCoreCheck[offsetof(FrisbeeTournamentScene, core) == 4 ? 1 : -1];
typedef char FrisbeeTournamentSceneContinuationCheck[offsetof(FrisbeeTournamentScene, continuation) == 8 ? 1 : -1];
typedef char FrisbeeTournamentTransitionSizeCheck[sizeof(FrisbeeTournamentTransition) == 12 ? 1 : -1];
typedef char FrisbeeTournamentTransitionContinuationCheck[offsetof(FrisbeeTournamentTransition, continuation) == 4 ? 1 : -1];
typedef char FrisbeeTournamentTransitionSaveCheck[offsetof(FrisbeeTournamentTransition, save) == 8 ? 1 : -1];

// Direct ABI declaration of this compiler constructor, not a wrapper.
// Retained until ordinary owner-return lowering matches the native factory.
// The second argument is the actual single-word continuation transfer slot.
extern "C" FrisbeeTournamentScene * __22FrisbeeTournamentSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * storage, SceneTransition ** next, GameStateSaveImage * image);

#endif
