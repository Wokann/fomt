#include "control_widget.hh"

u32 UpdateControlWidget(ControlWidget * widget, HardwareDisplayState * display,
    HardwareLinkedList * uploads, HardwareLinkedList * commands)
{
    return func_0803BAAC(widget->state, display, uploads, commands);
}

void func_0803BEBC(ControlWidget * widget)
{
    func_0803BCF8(widget->state);
}

void func_0803BEC8(ControlWidget * widget)
{
    func_0803BD60(widget->state);
}

void func_0803BED4(ControlWidget * widget)
{
    func_0803BD88(widget->state);
}

void func_0803BEE0(ControlWidget * widget)
{
    func_0803BDB8(widget->state);
}

i32 GetControlWidgetX(ControlWidget const * widget)
{
    return reinterpret_cast<i16 const *>(widget->state)[0];
}

i32 GetControlWidgetY(ControlWidget const * widget)
{
    return reinterpret_cast<i16 const *>(widget->state)[1];
}

void SetControlWidgetPosition(ControlWidget * widget, u32 x, u32 y)
{
    func_0803BDE4(*static_cast<U16Pair *>(widget->state), x, y);
}

void OffsetControlWidgetPosition(ControlWidget * widget, u32 x, u32 y)
{
    func_0803BDEC(*static_cast<U16Pair *>(widget->state), x, y);
}
