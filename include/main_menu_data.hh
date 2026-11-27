#ifndef MAIN_MENU_DATA_HH
#define MAIN_MENU_DATA_HH

#include "ui_text_window.hh"
#include "resource_handle.hh"
#include "obj_palette_collection.hh"
#include "obj_tile_collection.hh"
#include "hardware_dma.hh"

struct MainMenuSpriteResource {
    ObjTileCollectionEntry tiles;
    HardwareDmaCopyLink upload;
    IndexedResourceHandle handle;

    MainMenuSpriteResource(IndexedResourceProvider * provider, u32 index, i32 delta)
        : tiles(2), upload(), handle(provider, index, delta) {}
};

struct MainMenuSpriteOwner {
    MainMenuSpriteResource * value;
    MainMenuSpriteOwner() : value(0) {}
    explicit MainMenuSpriteOwner(MainMenuSpriteResource * resource) : value(resource) {}
    ~MainMenuSpriteOwner() { delete value; }
    void operator=(MainMenuSpriteResource * resource)
    {
        if (resource != value && value != 0)
            delete value;
        value = resource;
    }
};

// The menu draws a twelve-by-two-tile label after this untouched prefix.
struct MainMenuLabelTileBuffer {
    u32 unk_00;
    u32 tiles[12 * 2 * 8];
    MainMenuLabelTileBuffer() {}
};

struct MainMenuLabelRenderer {
    MainMenuLabelTileBuffer buffer;
    ObjTileCollectionEntry tiles[3];
    HardwareDmaCopyLink uploads[6];

    MainMenuLabelRenderer()
    {
        for (u32 i = 0; i < 3; ++i) {
            tiles[i].Reset(3);
        }
    }
};

struct MainMenuData {
    IndexedResourceArchive archive;
    ObjPaletteCollectionEntry palette;
    HardwareDmaCopyLink palette_upload;
    MainMenuSpriteOwner cursor;
    MainMenuSpriteOwner icons[7];
    MainMenuLabelRenderer label;

    MainMenuData();
    ~MainMenuData();
};



extern u32 const gMenuEntryIds[7];
extern char const gText_Menu_Diary[];
extern char const gText_Menu_Rucksack[];
extern char const gText_Menu_WorldMap[];
extern char const gText_Menu_FarmMap[];
extern char const gText_Menu_Earnings[];
extern char const gText_Menu_Memo[];
extern char const gText_Menu_Tutorial[];
extern char const * const gMenuEntryLabels[7];
extern u8 const gMainMenuSpriteResourceArchive[];

#endif // MAIN_MENU_DATA_HH
