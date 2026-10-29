#ifndef CONTROL_WIDGET_HH
#define CONTROL_WIDGET_HH

#include "prelude.h"
#include "ui_position.hh"
#include "hardware_display_state.hh"

struct UiTextWindow;
struct HardwareLinkedList;

#pragma interface "control_widget.hh"

struct ControlWidget {
    ControlWidget(i32 x, i32 y, u32 width, u32 height, u32 background,
        u32 screen, u32 palette, u32 mode) SECTION(".text.control_widget_constructor");
    virtual ~ControlWidget() SECTION(".text.control_widget_destructor");
    virtual void Open() SECTION(".text.control_widget_callbacks");
    virtual void OpenImmediate() SECTION(".text.control_widget_callbacks");
    virtual void Close() SECTION(".text.control_widget_callbacks");
    virtual void CloseImmediate() SECTION(".text.control_widget_callbacks");
    virtual i32 GetX() const SECTION(".text.control_widget_callbacks");
    virtual i32 GetY() const SECTION(".text.control_widget_callbacks");
    virtual void SetPosition(u32 x, u32 y) SECTION(".text.control_widget_callbacks");
    virtual void OffsetPosition(u32 x, u32 y) SECTION(".text.control_widget_callbacks");
    u32 GetPhase() const SECTION(".text.control_widget_phase");
    u32 Update(HardwareDisplayState * display, HardwareLinkedList * uploads,
        HardwareLinkedList * commands) SECTION(".text.control_widget_callbacks");
    UiTextWindow * state;
};

typedef char ControlWidgetSizeCheck[sizeof(ControlWidget) == 8 ? 1 : -1];
typedef char ControlWidgetStateCheck[offsetof(ControlWidget, state) == 0 ? 1 : -1];

#pragma implementation
#endif // CONTROL_WIDGET_HH
