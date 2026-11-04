#include "prelude.h"
#include "control_widget.hh"
#include "resource_handle.hh"
#include "obj_palette_collection.hh"
#include "hardware_state_clear.hh"
#include "hardware_dma_link.hh"
#include "common_ui.hh"
#pragma implementation "main_menu_widget.hh"
#include "main_menu_widget.hh"

MainMenuWidget::MainMenuWidget(u32 background, u32 screen, u32 palette,
    u32 mode, u32 selection)
    : ControlWidget(0, 136, 240, 24, background, screen, palette, mode),
      data(new MainMenuData()), selection(selection), refresh_pending(0),
      blink_frame(1), input_enabled(1)
{
}

MainMenuWidget::~MainMenuWidget()
{
    delete data;
}

void MainMenuWidget::Open()
{
    ControlWidget::Open();
    refresh_pending = 1;
    input_enabled = 1;
}

void MainMenuWidget::OpenImmediate()
{
    ControlWidget::OpenImmediate();
    refresh_pending = 1;
    input_enabled = 1;
}

u32 MainMenuWidget::GetSelection() const
{
    return selection;
}

void MainMenuWidget::DisableInput()
{
    input_enabled = 0;
}

MainMenuData::~MainMenuData()
{
}

u32 MainMenuWidget::Update(HardwareCoreState * input,
    HardwareSpriteBufferState * sprites, HardwareDisplayState * display,
    HardwareLinkedList * uploads, HardwareLinkedList * commands)
{
    return UpdateImpl(input, sprites, display, uploads, commands, nullptr);
}

u32 MainMenuWidget::Update(HardwareCoreState * input,
    HardwareSpriteBufferState * sprites, HardwareDisplayState * display,
    HardwareLinkedList * uploads, HardwareLinkedList * commands,
    HardwareMusicPlayerSlot * music)
{
    return UpdateImpl(input, sprites, display, uploads, commands, music);
}

MainMenuData::MainMenuData()
    : archive(gMainMenuSpriteResourceArchive),
      cursor(new MainMenuSpriteResource(&archive, 7, 256))
{
    for (u32 i = 0; i < 7; ++i)
        icons[i] = new MainMenuSpriteResource(&archive, gMenuEntryIds[i], 256);
}
