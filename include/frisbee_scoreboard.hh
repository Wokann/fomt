#ifndef FRISBEE_SCOREBOARD_HH
#define FRISBEE_SCOREBOARD_HH

#include "scene.hh"
#include "hardware_bootstrap.hh"
#include "hardware_music_player.hh"
#include "resource_archive.hh"
#include "resource_handle.hh"
#include "hardware_input.hh"
#include "obj_palette_collection.hh"
#include "obj_tile_collection.hh"

extern char const gText_Frisbee_TournamentScoreboard[];
extern u8 const gUnk_08527094[];
struct GameStateSaveImage;
#pragma interface "frisbee_scoreboard.hh"

// Each resource handle is followed by its native sprite parameters.
// The final word is not initialized by this constructor; its meaning is unknown.
struct FrisbeeScoreboardSpriteState {
    IndexedResourceHandle resource;
    IndexedResourceSpriteParameters parameters;
    u32 unk_30;
    FrisbeeScoreboardSpriteState(IndexedResourceProvider * archive, u32 index)
        : resource(archive, index, 256), parameters() {}
};

typedef char FrisbeeScoreboardSpriteStateSizeCheck[sizeof(FrisbeeScoreboardSpriteState) == 0x34 ? 1 : -1];
typedef char FrisbeeScoreboardSpriteParametersCheck[offsetof(FrisbeeScoreboardSpriteState, parameters) == 0x14 ? 1 : -1];
typedef char FrisbeeScoreboardSpriteUnknownCheck[offsetof(FrisbeeScoreboardSpriteState, unk_30) == 0x30 ? 1 : -1];

// Unknown bytes below are runtime RAM, not recovered ROM data or padding.
struct FrisbeeScoreboardCore : HardwareBootstrap {
    FrisbeeScoreboardCore(GameStateSaveImage * image);
    SceneTransitionOwner Run();
    void InitializeDisplay();
    void UpdateArrows();
    GameStateSaveImage * save;
    HardwareMusicPlayerSlot music_player;
    IndexedResourceArchive unk_archive_010;
    FrisbeeScoreboardSpriteState sprite_040;
    FrisbeeScoreboardSpriteState sprite_074;
    ObjTileCollectionEntry sprite_tiles;
    ObjPaletteCollectionEntry obj_palette_collection;
    u8 unk_0B8[0x800];
    i16 scroll_y;
    i32 phase;
};

// Place one pre-rendered glyph in the core's 32-column tilemap. JP glyphs
// occupy two columns; western glyphs occupy one. Both use two tile rows.
extern "C" void WriteFrisbeeScoreboardGlyphTiles(FrisbeeScoreboardCore * core,
    unsigned x, unsigned y, unsigned glyph);

typedef char FrisbeeScoreboardCoreSizeCheck[sizeof(FrisbeeScoreboardCore) == 0x8C0 ? 1 : -1];
typedef char FrisbeeScoreboardCoreOffset_save[offsetof(FrisbeeScoreboardCore, save) == 0x8 ? 1 : -1];
typedef char FrisbeeScoreboardCoreOffset_music_player[offsetof(FrisbeeScoreboardCore, music_player) == 0xC ? 1 : -1];
typedef char FrisbeeScoreboardCoreOffset_unk_archive_010[offsetof(FrisbeeScoreboardCore, unk_archive_010) == 0x10 ? 1 : -1];
typedef char FrisbeeScoreboardCoreOffset_sprite_040[offsetof(FrisbeeScoreboardCore, sprite_040) == 0x40 ? 1 : -1];
typedef char FrisbeeScoreboardCoreOffset_sprite_074[offsetof(FrisbeeScoreboardCore, sprite_074) == 0x74 ? 1 : -1];
typedef char FrisbeeScoreboardCoreOffset_sprite_tiles[offsetof(FrisbeeScoreboardCore, sprite_tiles) == 0xA8 ? 1 : -1];
typedef char FrisbeeScoreboardCoreOffset_obj_palette_collection[offsetof(FrisbeeScoreboardCore, obj_palette_collection) == 0xB0 ? 1 : -1];
typedef char FrisbeeScoreboardCoreOffset_unk_0B8[offsetof(FrisbeeScoreboardCore, unk_0B8) == 0xB8 ? 1 : -1];
typedef char FrisbeeScoreboardCoreOffset_scroll_y[offsetof(FrisbeeScoreboardCore, scroll_y) == 0x8B8 ? 1 : -1];
typedef char FrisbeeScoreboardCoreOffset_phase[offsetof(FrisbeeScoreboardCore, phase) == 0x8BC ? 1 : -1];

// The scene destroys its continuation first, then this owned core.
struct FrisbeeScoreboardCoreOwner {
    explicit FrisbeeScoreboardCoreOwner(FrisbeeScoreboardCore * core) : value(core) {}
    ~FrisbeeScoreboardCoreOwner() { delete value; }
    FrisbeeScoreboardCore * operator->() const { return value; }
    FrisbeeScoreboardCore * value;
private:
    FrisbeeScoreboardCoreOwner(FrisbeeScoreboardCoreOwner const &);
    FrisbeeScoreboardCoreOwner & operator=(FrisbeeScoreboardCoreOwner const &);
};
typedef char FrisbeeScoreboardCoreOwnerSizeCheck[sizeof(FrisbeeScoreboardCoreOwner) == 4 ? 1 : -1];


struct FrisbeeScoreboardScene : AScene {
    FrisbeeScoreboardScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~FrisbeeScoreboardScene();
    virtual SceneTransitionOwner Run();
    FrisbeeScoreboardCoreOwner core;
    SceneTransitionOwner continuation;
};

struct FrisbeeScoreboardTransition : SceneTransition {
    FrisbeeScoreboardTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char FrisbeeScoreboardSceneSizeCheck[sizeof(FrisbeeScoreboardScene) == 12 ? 1 : -1];
typedef char FrisbeeScoreboardSceneCoreCheck[offsetof(FrisbeeScoreboardScene, core) == 4 ? 1 : -1];
typedef char FrisbeeScoreboardSceneContinuationCheck[offsetof(FrisbeeScoreboardScene, continuation) == 8 ? 1 : -1];
typedef char FrisbeeScoreboardTransitionSizeCheck[sizeof(FrisbeeScoreboardTransition) == 12 ? 1 : -1];
typedef char FrisbeeScoreboardTransitionContinuationCheck[offsetof(FrisbeeScoreboardTransition, continuation) == 4 ? 1 : -1];
typedef char FrisbeeScoreboardTransitionSaveCheck[offsetof(FrisbeeScoreboardTransition, save) == 8 ? 1 : -1];

// Direct ABI declaration of this compiler constructor, not a wrapper.
// Retained until ordinary owner-return lowering matches the native factory.
// The second argument is the actual single-word continuation transfer slot.
extern "C" FrisbeeScoreboardScene * __22FrisbeeScoreboardSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * storage, SceneTransition ** next, GameStateSaveImage * image);

#endif // FRISBEE_SCOREBOARD_HH
