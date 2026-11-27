#ifndef FRISBEE_SCOREBOARD_HH
#define FRISBEE_SCOREBOARD_HH

#include "scene.hh"
#include "fomt_constants.hh"

#include "scene.hh"
#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "resource_archive.hh"
#include "resource_handle.hh"
#include "hardware_input.hh"
#include "obj_palette_pool.hh"
#include "obj_tile_collection.hh"

enum {
    FRISBEE_SCOREBOARD_CONTESTANT_COUNT = 30,
#if defined(REGION_JP)
    FRISBEE_SCOREBOARD_CONTESTANT_NAME_WIDTH = 13,
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    FRISBEE_SCOREBOARD_CONTESTANT_NAME_WIDTH = 14,
#endif
};
extern char const gText_FrisbeeScoreboard_ContestantNames[FRISBEE_SCOREBOARD_CONTESTANT_COUNT][FRISBEE_SCOREBOARD_CONTESTANT_NAME_WIDTH];
extern u16 const gFrisbeeScoreboardCharacterCodes[];

extern char const gText_Frisbee_TournamentScoreboard[];
extern u8 const gUnk_08527094[];
struct GameStateSaveImage;

// Each resource handle is followed by its native sprite parameters.
// The final word is not initialized by this constructor; its meaning is unknown.
struct FrisbeeScoreboardSpriteState {
    IndexedResourceHandle resource;
    IndexedResourceSpriteParameters parameters;
    u32 unk_30;
    FrisbeeScoreboardSpriteState(IndexedResourceProvider * archive, u32 index)
        : resource(archive, index, 256), parameters() {}
};


#pragma interface "frisbee_scoreboard.hh"
struct FrisbeeScoreboardCore;

// The scene destroys its continuation first, then this owned core.
struct FrisbeeScoreboardCoreOwner {
    explicit FrisbeeScoreboardCoreOwner(FrisbeeScoreboardCore * core);
    ~FrisbeeScoreboardCoreOwner();
    FrisbeeScoreboardCore * operator->() const;
    FrisbeeScoreboardCore * value;
private:
    FrisbeeScoreboardCoreOwner(FrisbeeScoreboardCoreOwner const &);
    FrisbeeScoreboardCoreOwner & operator=(FrisbeeScoreboardCoreOwner const &);
};

#pragma interface "frisbee_scoreboard.hh"
struct FrisbeeScoreboardScene : AScene {
    FrisbeeScoreboardScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~FrisbeeScoreboardScene();
    virtual SceneTransitionOwner Run();
    FrisbeeScoreboardCoreOwner core;
    SceneTransitionOwner continuation;
};

// Unknown bytes below are runtime RAM, not recovered ROM data or padding.
struct FrisbeeScoreboardCore : HardwareContext {
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

#pragma interface "frisbee_scoreboard.hh"

// Place one pre-rendered glyph in the core's 32-column tilemap. JP glyphs
// occupy two columns; western glyphs occupy one. Both use two tile rows.
extern "C" void WriteFrisbeeScoreboardGlyphTiles(FrisbeeScoreboardCore * core,
    unsigned x, unsigned y, unsigned glyph);




// Direct ABI declaration of this compiler constructor, not a wrapper.
// Retained until ordinary owner-return lowering matches the native factory.
// The second argument is the actual single-word continuation transfer slot.
extern "C" FrisbeeScoreboardScene * __22FrisbeeScoreboardSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * storage, SceneTransition ** next, GameStateSaveImage * image);

#endif // FRISBEE_SCOREBOARD_HH
