#ifndef MAIN_MENU_WIDGET_HH
#define MAIN_MENU_WIDGET_HH

#include "control_widget.hh"
#include "resource_handle.hh"
#include "hardware_resource.hh"
#include "hardware_state_clear.hh"
#include "hardware_dma_link.hh"
#include "common_ui.hh"

struct HardwareCoreState;
struct HardwareSpriteBufferState;
struct HardwareMusicPlayerSlot;

#pragma interface "main_menu_widget.hh"

struct MainMenuSpriteResource {
    HardwareStateEntry tiles;
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
    HardwareStateEntry tiles[3];
    HardwareDmaCopyLink uploads[6];

private:
    // Construction belongs to the still-native MainMenuData initializer.
    MainMenuLabelRenderer();
};

struct MainMenuData {
    IndexedResourceArchive archive;
    HardwareResourceEntry palette;
    HardwareDmaCopyLink palette_upload;
    MainMenuSpriteOwner cursor;
    MainMenuSpriteOwner icons[7];
    MainMenuLabelRenderer label;

    MainMenuData() SECTION(".text.main_menu_data_constructor");
    ~MainMenuData() SECTION(".text.main_menu_data_destructor");
};

struct MainMenuWidget : ControlWidget {
    MainMenuWidget(u32 background, u32 screen, u32 palette, u32 mode, u32 selection)
        SECTION(".text.main_menu_widget_lifetime");
    virtual ~MainMenuWidget() SECTION(".text.main_menu_widget_lifetime");
    virtual void Open() SECTION(".text.main_menu_widget_callbacks");
    virtual void OpenImmediate() SECTION(".text.main_menu_widget_callbacks");
    u32 GetSelection() const SECTION(".text.main_menu_widget_callbacks");
    void DisableInput() SECTION(".text.main_menu_widget_callbacks");

    // Return the window phase; a null music player suppresses menu SFX.
    u32 Update(HardwareCoreState * input, HardwareSpriteBufferState * sprites,
        HardwareDisplayState * display, HardwareLinkedList * uploads,
        HardwareLinkedList * commands) SECTION(".text.main_menu_widget_update");
    u32 Update(HardwareCoreState * input, HardwareSpriteBufferState * sprites,
        HardwareDisplayState * display, HardwareLinkedList * uploads,
        HardwareLinkedList * commands, HardwareMusicPlayerSlot * music)
        SECTION(".text.main_menu_widget_update");

    MainMenuData * data;
    u8 selection;
    u8 refresh_pending;
    u8 blink_frame;
    u8 input_enabled;

private:
    u32 UpdateImpl(HardwareCoreState * input, HardwareSpriteBufferState * sprites,
        HardwareDisplayState * display, HardwareLinkedList * uploads,
        HardwareLinkedList * commands, HardwareMusicPlayerSlot * music);
};

typedef char MainMenuSpriteSizeCheck[sizeof(MainMenuSpriteResource) == 0x34 ? 1 : -1];
typedef char MainMenuSpriteUploadCheck[offsetof(MainMenuSpriteResource, upload) == 8 ? 1 : -1];
typedef char MainMenuSpriteHandleCheck[offsetof(MainMenuSpriteResource, handle) == 0x20 ? 1 : -1];
typedef char MainMenuSpriteOwnerSizeCheck[sizeof(MainMenuSpriteOwner) == 4 ? 1 : -1];
typedef char MainMenuLabelSizeCheck[sizeof(MainMenuLabelTileBuffer) == 0x304 ? 1 : -1];
typedef char MainMenuDataSizeCheck[sizeof(MainMenuData) == 0x41C ? 1 : -1];
typedef char MainMenuPaletteCheck[offsetof(MainMenuData, palette) == 0x30 ? 1 : -1];
typedef char MainMenuCursorCheck[offsetof(MainMenuData, cursor) == 0x50 ? 1 : -1];
typedef char MainMenuIconsCheck[offsetof(MainMenuData, icons) == 0x54 ? 1 : -1];
typedef char MainMenuLabelCheck[offsetof(MainMenuData, label) == 0x70 ? 1 : -1];
typedef char MainMenuLabelTilesCheck[offsetof(MainMenuData, label) + offsetof(MainMenuLabelRenderer, tiles) == 0x374 ? 1 : -1];
typedef char MainMenuLabelUploadsCheck[offsetof(MainMenuData, label) + offsetof(MainMenuLabelRenderer, uploads) == 0x38C ? 1 : -1];
typedef char MainMenuWidgetSizeCheck[sizeof(MainMenuWidget) == 16 ? 1 : -1];
typedef char MainMenuWidgetDataCheck[offsetof(MainMenuWidget, data) == 8 ? 1 : -1];
typedef char MainMenuWidgetSelectionCheck[offsetof(MainMenuWidget, selection) == 12 ? 1 : -1];

extern "C" {
extern u8 const gMainMenuSpriteResourceArchive[];
}

#pragma implementation
#endif // MAIN_MENU_WIDGET_HH
