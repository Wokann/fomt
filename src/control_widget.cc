#include "control_widget.hh"
#include "ui_text_window.hh"

u32 GetControlWidgetPhase(ControlWidget const * widget)
{
    return widget->state->phase;
}

u32 UpdateControlWidget(ControlWidget * widget, HardwareDisplayState * display,
    HardwareLinkedList * uploads, HardwareLinkedList * commands)
{
    return widget->state->Update(display, uploads, commands);
}

void OpenControlWidget(ControlWidget * widget)
{
    widget->state->Open();
}

void OpenControlWidgetImmediate(ControlWidget * widget)
{
    widget->state->OpenImmediate();
}

void CloseControlWidget(ControlWidget * widget)
{
    widget->state->Close();
}

void CloseControlWidgetImmediate(ControlWidget * widget)
{
    widget->state->CloseImmediate();
}

i32 GetControlWidgetX(ControlWidget const * widget)
{
    return static_cast<i16>(widget->state->position.first);
}

i32 GetControlWidgetY(ControlWidget const * widget)
{
    return static_cast<i16>(widget->state->position.second);
}

void SetControlWidgetPosition(ControlWidget * widget, u32 x, u32 y)
{
    func_0803BDE4(widget->state->position, x, y);
}

void OffsetControlWidgetPosition(ControlWidget * widget, u32 x, u32 y)
{
    func_0803BDEC(widget->state->position, x, y);
}
