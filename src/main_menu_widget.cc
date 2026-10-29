#include "prelude.h"
#include "control_widget.hh"
#include "resource_handle.hh"
#include "hardware_resource.hh"
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
