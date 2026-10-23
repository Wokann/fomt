#ifndef CONTROL_WIDGET_HH
#define CONTROL_WIDGET_HH

#include "prelude.h"
#include "u16_pair.hh"
#include "hardware_display_output.hh"

struct ControlWidget;
struct HardwareLinkedList;

// Native ABI view of the eleven-slot base table. The remaining callbacks
// keep erased signatures until their complete arguments are established.
struct ControlWidgetVTable {
    void * unk_00;
    void * unk_04;
    void (*unk_08[5])();
    i32 (*get_x)(ControlWidget const *);
    i32 (*get_y)(ControlWidget const *);
    void (*unk_24[2])();
};

// The owned control state is larger than its leading coordinate pair and
// is still native. This raw view does not claim a recovered C++ hierarchy.
struct ControlWidget {
    void * state;
    ControlWidgetVTable const * vtable;
};

typedef char ControlWidgetSizeCheck[sizeof(ControlWidget) == 8 ? 1 : -1];
typedef char ControlWidgetVTableSizeCheck[sizeof(ControlWidgetVTable) == 44 ? 1 : -1];
typedef char ControlWidgetVTableXCheck[offsetof(ControlWidgetVTable, get_x) == 0x1C ? 1 : -1];
typedef char ControlWidgetVTableYCheck[offsetof(ControlWidgetVTable, get_y) == 0x20 ? 1 : -1];

EXTERN_C

// Preserve all three forwarded arguments: the native owned-state update
// really consumes r1/r2/r3, even though the former one-argument view did not
// describe them. It updates the display shadow, splices pending uploads,
// and queues/removes its window command through the separate command list.
u32 UpdateControlWidget(ControlWidget * widget, HardwareDisplayState * display,
    HardwareLinkedList * uploads, HardwareLinkedList * commands);
void func_0803BEBC(ControlWidget * widget);
void func_0803BEC8(ControlWidget * widget);
void func_0803BED4(ControlWidget * widget);
void func_0803BEE0(ControlWidget * widget);
i32 GetControlWidgetX(ControlWidget const * widget);
i32 GetControlWidgetY(ControlWidget const * widget);
void SetControlWidgetPosition(ControlWidget * widget, u32 x, u32 y);
void OffsetControlWidgetPosition(ControlWidget * widget, u32 x, u32 y);

// Retained native owned-state services and shared halfword-pair operations.
u32 func_0803BAAC(void * state, HardwareDisplayState * display,
    HardwareLinkedList * uploads, HardwareLinkedList * commands);
void func_0803BCF8(void * state);
void func_0803BD60(void * state);
void func_0803BD88(void * state);
void func_0803BDB8(void * state);
void func_0803BDE4(U16Pair & value, u32 first, u32 second);
void func_0803BDEC(U16Pair & value, u32 first, u32 second);

EXTERN_C_END

#endif // CONTROL_WIDGET_HH
