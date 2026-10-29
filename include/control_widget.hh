#ifndef CONTROL_WIDGET_HH
#define CONTROL_WIDGET_HH

#include "prelude.h"
#include "u16_pair.hh"
#include "hardware_display_state.hh"

struct ControlWidget;
struct UiTextWindow;
struct HardwareLinkedList;

// Native ABI view; the owning virtual hierarchy is still being recovered.
struct ControlWidgetVTable {
    void * unk_00;
    void * unk_04;
    void (*destroy)(ControlWidget *, u32 flags);
    void (*open)(ControlWidget *);
    void (*open_immediate)(ControlWidget *);
    void (*close)(ControlWidget *);
    void (*close_immediate)(ControlWidget *);
    i32 (*get_x)(ControlWidget const *);
    i32 (*get_y)(ControlWidget const *);
    void (*set_position)(ControlWidget *, u32, u32);
    void (*offset_position)(ControlWidget *, u32, u32);
};

struct ControlWidget {
    UiTextWindow * state;
    ControlWidgetVTable const * vtable;
};

typedef char ControlWidgetSizeCheck[sizeof(ControlWidget) == 8 ? 1 : -1];
typedef char ControlWidgetVTableSizeCheck[sizeof(ControlWidgetVTable) == 44 ? 1 : -1];
typedef char ControlWidgetVTableXCheck[offsetof(ControlWidgetVTable, get_x) == 0x1C ? 1 : -1];
typedef char ControlWidgetVTableYCheck[offsetof(ControlWidgetVTable, get_y) == 0x20 ? 1 : -1];

EXTERN_C

u32 GetControlWidgetPhase(ControlWidget const * widget) SECTION(".text.control_widget_phase");

// Preserve all three forwarded arguments: the native owned-state update
// really consumes r1/r2/r3, even though the former one-argument view did not
// describe them. It updates the display shadow, splices pending uploads,
// and queues/removes its window command through the separate command list.
u32 UpdateControlWidget(ControlWidget * widget, HardwareDisplayState * display,
    HardwareLinkedList * uploads, HardwareLinkedList * commands);
void OpenControlWidget(ControlWidget * widget);
void OpenControlWidgetImmediate(ControlWidget * widget);
void CloseControlWidget(ControlWidget * widget);
void CloseControlWidgetImmediate(ControlWidget * widget);
i32 GetControlWidgetX(ControlWidget const * widget);
i32 GetControlWidgetY(ControlWidget const * widget);
void SetControlWidgetPosition(ControlWidget * widget, u32 x, u32 y);
void OffsetControlWidgetPosition(ControlWidget * widget, u32 x, u32 y);

// Shared halfword-pair operations at the start of the owned window.
void func_0803BDE4(U16Pair & value, u32 first, u32 second);
void func_0803BDEC(U16Pair & value, u32 first, u32 second);

EXTERN_C_END

#endif // CONTROL_WIDGET_HH
