#ifndef MAIN_MENU_WIDGET_HH
#define MAIN_MENU_WIDGET_HH

#include "ui_text_window.hh"
#include "resource_handle.hh"
#include "obj_palette_collection.hh"
#include "obj_tile_collection.hh"
#include "hardware_dma.hh"

struct HardwareCoreState;
struct HardwareSpriteBufferState;
struct HardwareMusicPlayerSlot;


#include "main_menu_data.hh"

#pragma interface "main_menu_widget.hh"
struct MainMenuWidget : ControlWidget {
    MainMenuWidget(u32 background, u32 screen, u32 palette, u32 mode, u32 selection);
    virtual ~MainMenuWidget();
    virtual void Open();
    virtual void OpenImmediate();
    u32 GetSelection() const;
    void DisableInput();

    // Return the window phase; a null music player suppresses menu SFX.
    u32 Update(HardwareCoreState * input, HardwareSpriteBufferState * sprites,
        HardwareDisplayState * display, HardwareLinkedList * uploads,
        HardwareLinkedList * commands);
    u32 Update(HardwareCoreState * input, HardwareSpriteBufferState * sprites,
        HardwareDisplayState * display, HardwareLinkedList * uploads,
        HardwareLinkedList * commands, HardwareMusicPlayerSlot * music);

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

typedef char MainMenuWidgetSizeCheck[sizeof(MainMenuWidget) == 16 ? 1 : -1];
typedef char MainMenuWidgetDataCheck[offsetof(MainMenuWidget, data) == 8 ? 1 : -1];
typedef char MainMenuWidgetSelectionCheck[offsetof(MainMenuWidget, selection) == 12 ? 1 : -1];

extern "C" {
}

#endif // MAIN_MENU_WIDGET_HH
