#ifndef SCENE_REFERENCE_PAGE_HH
#define SCENE_REFERENCE_PAGE_HH

#include "scene.hh"
#include "fomt_constants.hh"

struct GameStateSaveImage;
struct HardwareKeySnapshot;
#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "resource_handle.hh"
#include "obj_tile_collection_storage.hh"
#include "obj_palette_pool.hh"
#include <stdlib.h>
#include "new_game_ui.hh"

// Native sprite state contains a resolved handle, OAM parameters, and flag.
struct ReferencePageTitleBuffer : NewGameTextTileBuffer<28> {
    enum { GlyphCount = TileCount / UiSpriteGlyphBuffer::TileCount };

    ReferencePageTitleBuffer() { Clear(); }
};

struct ReferencePageSprite {
    ReferencePageSprite(IndexedResourceProvider * provider, u32 index)
        : handle(provider, index, 256), parameters(), unk_30(0) {}

    IndexedResourceHandle handle;
    IndexedResourceSpriteParameters parameters;
    u8 unk_30;
};

// Rows beginning with the original star glyph are stored as 32-bit indices.
// The state-free allocator and its end pointer form the final subobject.
struct ReferencePageStarredLines {
    struct Allocator {
        Allocator() {}
        Allocator(Allocator const &) {}
        u32 * AllocateBytes(u32 bytes) const;
        void Deallocate(u32 * value, u32 count) const { free(value); }
    };

    struct Allocation : Allocator {
        Allocation(Allocator const & value) : Allocator(value), end(nullptr) {}
        u32 * end;
    };

    u32 * first;
    u32 * last;
    Allocation allocation;

    ReferencePageStarredLines(Allocator const & value = Allocator())
        : first(nullptr), last(nullptr), allocation(value) {}

    u32 const & Front() const { return *first; }
    bool Empty() const { return first == last; }
    u32 const * End() const { return last; }
    void Clear() { last = first; }

    ~ReferencePageStarredLines()
    {
        if (first != 0)
            allocation.Deallocate(first, allocation.end - first);
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
    inline void ScrollWithHeldKeys(HardwareKeySnapshot const & held);

    GameStateSaveImage * save;
    HardwareMusicPlayerSlot music;
    ReferencePageTitleBuffer title;
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


#pragma interface "scene_reference_page.hh"


EXTERN_C

extern u8 const gUnk_08527094[];

void LoadReferencePageGraphics(ReferencePageSceneCore *);
void InitializeReferenceBookList(ReferencePageSceneCore *);
void UpdateReferenceBookListRow(ReferencePageSceneCore *);
void InitializeReferenceArticle(ReferencePageSceneCore *);
i32 IsReferenceProfileBoundary(ReferencePageSceneCore *, u32 condition);
void UpdateReferenceArticleRow(ReferencePageSceneCore *);
void ExpandReferencePageText(ReferencePageSceneCore *, char const *, char *);
void InitializeReferencePageSprites(ReferencePageSceneCore *);
void RenderReferencePageSprites(ReferencePageSceneCore *);
void ScrollReferenceArticle(ReferencePageSceneCore *, i32 delta);

// Direct reference to the actual GCC 2.9 continuation-slot constructor ABI.
ReferencePageScene * __18ReferencePageSceneG20SceneTransitionOwnerP18GameStateSaveImagei(
    void * object, SceneTransition ** next, GameStateSaveImage * image, i32 page);

EXTERN_C_END

#pragma interface "scene_reference_page.hh"


// The list initializer reads 32-bit source slots before storing each low
// halfword in the active Library entry list.
extern u32 const gReferencePageInitialEntryIds[];

// The native selector uses two fixed fields: 9 encoded bytes in JP,
// 12 in the overseas versions, including the C string terminator.
#if defined(REGION_JP)
extern char const gText_ReferencePage_Menu[2][9];
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern char const gText_ReferencePage_Menu[2][12];
#endif

#endif // SCENE_REFERENCE_PAGE_HH
