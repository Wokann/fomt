#ifndef UI_VCOUNT_HH
#define UI_VCOUNT_HH

#include "hardware_interrupt_guard.hh"

#pragma interface "ui_vcount.hh"

struct UiSceneCore;

// The context points to a live pointer slot owned by a UI scene.
extern "C" UiSceneCore * const * gUiVCountContext;
extern "C" void UpdateUiVCount(UiSceneCore * core);
extern "C" void HandleUiVCountInterrupt();

// Restore the previous context before the outer IRQ guard is released.
struct UiVCountContextScope {
    static UiSceneCore * const * Exchange(UiSceneCore * const & value)
    {
        UiSceneCore * const * previous = gUiVCountContext;
        gUiVCountContext = &value;
        return previous;
    }
    explicit UiVCountContextScope(UiSceneCore * const & value)
        : previous(Exchange(value)) {}

    virtual ~UiVCountContextScope()
    {
        gUiVCountContext = previous;
    }

    UiSceneCore * const * previous;
};

// The native registration layer has its own virtual identity.
struct UiVCountContextRegistration : UiVCountContextScope {
    explicit UiVCountContextRegistration(UiSceneCore * const & value)
        : UiVCountContextScope(value) {}

    virtual ~UiVCountContextRegistration() {}
};

// Members deliberately follow the native lifetime and offset order.
struct UiVCountBinding {
    explicit UiVCountBinding(UiSceneCore * const & value);
    virtual ~UiVCountBinding();

    UiSceneCore * value;
    InterruptGuard guard;
    UiVCountContextRegistration context;
    InterruptHandler previous_handler;
};

typedef char UiVCountContextScopeSize[sizeof(UiVCountContextScope) == 8 ? 1 : -1];
typedef char UiVCountBindingSize[sizeof(UiVCountBinding) == 24 ? 1 : -1];
typedef char UiVCountBindingContextOffset[offsetof(UiVCountBinding, context) == 8 ? 1 : -1];
typedef char UiVCountBindingHandlerOffset[offsetof(UiVCountBinding, previous_handler) == 16 ? 1 : -1];

#endif // UI_VCOUNT_HH
