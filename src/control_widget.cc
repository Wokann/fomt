#include "prelude.h"
#include "ui_text_window.hh"
#include "hardware_display_state.hh"
#pragma implementation "control_widget.hh"
#include "control_widget.hh"

ControlWidget::ControlWidget(i32 x, i32 y, u32 width, u32 height,
    u32 background, u32 screen, u32 palette, u32 mode)
    : state(new UiTextWindow(x, y, width, height, background, screen, palette, mode))
{
}

ControlWidget::~ControlWidget()
{
    delete state;
}

u32 ControlWidget::GetPhase() const
{
    return state->phase;
}

u32 ControlWidget::Update(HardwareDisplayState * display,
    HardwareLinkedList * uploads, HardwareLinkedList * commands)
{
    return state->Update(display, uploads, commands);
}

void ControlWidget::Open()
{
    state->Open();
}

void ControlWidget::OpenImmediate()
{
    state->OpenImmediate();
}

void ControlWidget::Close()
{
    state->Close();
}

void ControlWidget::CloseImmediate()
{
    state->CloseImmediate();
}

i32 ControlWidget::GetX() const
{
    return static_cast<i16>(state->position.first);
}

i32 ControlWidget::GetY() const
{
    return static_cast<i16>(state->position.second);
}

void ControlWidget::SetPosition(u32 x, u32 y)
{
    func_0803BDE4(state->position, x, y);
}

void ControlWidget::OffsetPosition(u32 x, u32 y)
{
    func_0803BDEC(state->position, x, y);
}
