#ifndef UI_VCOUNT_HH
#define UI_VCOUNT_HH

#include "hardware_interrupt_guard.hh"


struct ShopScreenCore;

// The context points to a live pointer slot owned by a UI scene.
extern "C" ShopScreenCore * const * gUiVCountContext;
extern "C" void HandleUiVCountInterrupt();

#pragma interface "ui_vcount.hh"

// Restore the previous context before the outer IRQ guard is released.
struct UiVCountContextScope {
    static ShopScreenCore * const * Exchange(ShopScreenCore * const & value)
    {
        ShopScreenCore * const * previous = gUiVCountContext;
        gUiVCountContext = &value;
        return previous;
    }
    explicit UiVCountContextScope(ShopScreenCore * const & value)
        : previous(Exchange(value)) {}

#pragma interface "ui_vcount_lifetimes.hh"
    virtual ~UiVCountContextScope();
#pragma interface "ui_vcount.hh"

    ShopScreenCore * const * previous;
};

// The native registration layer has its own virtual identity.
struct UiVCountContextRegistration : UiVCountContextScope {
    explicit UiVCountContextRegistration(ShopScreenCore * const & value)
        : UiVCountContextScope(value) {}

#pragma interface "ui_vcount_lifetimes.hh"
    virtual ~UiVCountContextRegistration();
#pragma interface "ui_vcount.hh"
};

#pragma interface "ui_vcount.hh"

// Members deliberately follow the native lifetime and offset order.
struct UiVCountBinding {
    explicit UiVCountBinding(ShopScreenCore * const & value);
    virtual ~UiVCountBinding();

    ShopScreenCore * value;
    InterruptGuard guard;
    UiVCountContextRegistration context;
    InterruptHandler previous_handler;
};

typedef char UiVCountContextScopeSize[sizeof(UiVCountContextScope) == 8 ? 1 : -1];
typedef char UiVCountBindingSize[sizeof(UiVCountBinding) == 24 ? 1 : -1];
typedef char UiVCountBindingContextOffset[offsetof(UiVCountBinding, context) == 8 ? 1 : -1];
typedef char UiVCountBindingHandlerOffset[offsetof(UiVCountBinding, previous_handler) == 16 ? 1 : -1];

#include "ui_vcount_lifetimes.hh"


#endif // UI_VCOUNT_HH
