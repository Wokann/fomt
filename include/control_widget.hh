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
        u32 screen, u32 palette, u32 mode);
    virtual ~ControlWidget();
    virtual void Open();
    virtual void OpenImmediate();
    virtual void Close();
    virtual void CloseImmediate();
    virtual i32 GetX() const;
    virtual i32 GetY() const;
    virtual void SetPosition(u32 x, u32 y);
    virtual void OffsetPosition(u32 x, u32 y);
    u32 GetPhase() const;
    u32 Update(HardwareDisplayState * display, HardwareLinkedList * uploads,
        HardwareLinkedList * commands);
    UiTextWindow * state;
};

typedef char ControlWidgetSizeCheck[sizeof(ControlWidget) == 8 ? 1 : -1];
typedef char ControlWidgetStateCheck[offsetof(ControlWidget, state) == 0 ? 1 : -1];

#pragma implementation
#endif // CONTROL_WIDGET_HH
