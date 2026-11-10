#ifndef SCENE_REFERENCE_PAGE_HH
#define SCENE_REFERENCE_PAGE_HH

#include "scene.hh"
#include "fomt_constants.hh"

struct GameStateSaveImage;
#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "resource_handle.hh"
#include "obj_tile_collection_storage.hh"
#include "obj_palette_pool.hh"
#include <stdlib.h>

// Native sprite state contains a resolved handle, OAM parameters, and flag.
struct ReferencePageSprite {
    IndexedResourceHandle handle;
    IndexedResourceSpriteParameters parameters;
    u8 unk_30;
};

// Rows beginning with the original star glyph are stored as 32-bit indices.
// The native grow operation owns this allocation; unk_08 is not initialized.
struct ReferencePageStarredLines {
    u32 * first;
    u32 * last;
    u32 unk_08;
    u32 * capacity_end;

    ~ReferencePageStarredLines()
    {
        if (first != 0)
            free(first);
    }
};

#pragma interface "scene_reference_page.hh"
struct ReferencePageSceneCore;

// The continuation member must be destroyed before the owned core.
struct ReferencePageSceneCoreOwner {
    explicit ReferencePageSceneCoreOwner(ReferencePageSceneCore * input);
    ~ReferencePageSceneCoreOwner();
    ReferencePageSceneCore * value;
};

#pragma interface "scene_reference_page.hh"
struct ReferencePageScene : AScene {
    enum SpecialPage {
        BOOK_LIST = 0x1000,
        LETTER_LIST = 0x1001,
    };

    ReferencePageScene(SceneTransitionOwner next, GameStateSaveImage * image, i32 page);
    virtual ~ReferencePageScene();
    virtual SceneTransitionOwner Run();

    ReferencePageSceneCoreOwner core;
    SceneTransitionOwner continuation;
};

struct ReferencePageSceneCore : HardwareContext {
    ReferencePageSceneCore(GameStateSaveImage * image, i32 page);
    SceneTransitionOwner Run();
    bool IsTopLineStarred() const;

    GameStateSaveImage * save;
    HardwareMusicPlayerSlot music;
    u32 unk_010;
    // The original renderer uses 28 columns x 2 rows of 4bpp tiles.
    u32 title_tiles[28 * 2 * 8];
    IndexedResourceArchive arrow_archive;
    IndexedResourceArchive cursor_archive;
    ReferencePageSprite up_arrow;
    ReferencePageSprite down_arrow;
    ReferencePageSprite cursor;
    ObjTileCollectionEntry arrow_tiles;
    ObjPaletteCollectionEntry arrow_palette;
    ObjTileCollectionEntry title_sprite_tiles;
    ObjPaletteCollectionEntry title_sprite_palette;
    ObjTileCollectionEntry cursor_tiles;
    ObjPaletteCollectionEntry cursor_palette;
    u16 scroll_y;
    u16 previous_row_y;
    i32 scroll_y_fixed;
    i32 maximum_scroll_fixed;
    i16 selected_entry;
    i16 first_visible_row;
    i16 entry_count;
    i16 cursor_x;
    i16 cursor_y;
    u16 saved_menu_scroll_y;
    // Fixed native menu capacity; this is not the ROM guide directory size.
    i16 entry_ids[255];
    bool direct_page;
    bool letter_list;
    i32 phase;
    char const * const * lines;
    ReferencePageStarredLines starred_lines;
    i16 page_id;
};

#pragma interface "scene_reference_page.hh"

typedef char ReferencePageSpriteSizeCheck[sizeof(ReferencePageSprite) == 0x34 ? 1 : -1];
typedef char ReferencePageStarredLinesSizeCheck[sizeof(ReferencePageStarredLines) == 0x10 ? 1 : -1];
typedef char ReferencePageSceneCoreTilesCheck[offsetof(ReferencePageSceneCore, title_tiles) == 0x14 ? 1 : -1];
typedef char ReferencePageSceneCoreArchiveCheck[offsetof(ReferencePageSceneCore, arrow_archive) == 0x714 ? 1 : -1];
typedef char ReferencePageSceneCoreSpritesCheck[offsetof(ReferencePageSceneCore, up_arrow) == 0x774 ? 1 : -1];
typedef char ReferencePageSceneCoreHandlesCheck[offsetof(ReferencePageSceneCore, arrow_tiles) == 0x810 ? 1 : -1];
typedef char ReferencePageSceneCoreScrollCheck[offsetof(ReferencePageSceneCore, scroll_y) == 0x840 ? 1 : -1];
typedef char ReferencePageSceneCoreEntriesCheck[offsetof(ReferencePageSceneCore, entry_ids) == 0x858 ? 1 : -1];
typedef char ReferencePageSceneCoreModeCheck[offsetof(ReferencePageSceneCore, direct_page) == 0xA56 ? 1 : -1];
typedef char ReferencePageSceneCoreLinesCheck[offsetof(ReferencePageSceneCore, lines) == 0xA5C ? 1 : -1];
typedef char ReferencePageSceneCoreStarredCheck[offsetof(ReferencePageSceneCore, starred_lines) == 0xA60 ? 1 : -1];
typedef char ReferencePageSceneCorePageCheck[offsetof(ReferencePageSceneCore, page_id) == 0xA70 ? 1 : -1];
typedef char ReferencePageSceneCoreSizeCheck[sizeof(ReferencePageSceneCore) == 0xA74 ? 1 : -1];

#pragma interface "scene_reference_page.hh"

typedef char ReferencePageSceneSizeCheck[sizeof(ReferencePageScene) == 12 ? 1 : -1];
typedef char ReferencePageSceneCoreCheck[offsetof(ReferencePageScene, core) == 4 ? 1 : -1];
typedef char ReferencePageSceneContinuationCheck[offsetof(ReferencePageScene, continuation) == 8 ? 1 : -1];

EXTERN_C

// Direct reference to the actual GCC 2.9 continuation-slot constructor ABI.
ReferencePageScene * __18ReferencePageSceneG20SceneTransitionOwnerP18GameStateSaveImagei(
    void * object, SceneTransition ** next, GameStateSaveImage * image, i32 page);

EXTERN_C_END

#pragma interface "scene_reference_page.hh"


// func_08079A64 reads this as 32-bit source slots before storing each low
// halfword in the active Library entry list.
extern u32 const gReferencePageInitialEntryIds[];

// The native selector uses two fixed fields: 9 encoded bytes in JP,
// 12 in the overseas versions, including the C string terminator.
#if defined(REGION_JP)
extern char const gText_ReferencePage_Menu[2][9];
#else
extern char const gText_ReferencePage_Menu[2][12];
#endif

#endif // SCENE_REFERENCE_PAGE_HH
