#ifndef UI_QUANTITY_SELECTOR_HH
#define UI_QUANTITY_SELECTOR_HH

#include "prelude.h"

struct ShopScreenCore;

struct UiPurchaseQuantitySelector {
    // The native constructor is maintained alongside these methods in the cc.
    explicit UiPurchaseQuantitySelector(ShopScreenCore * owner);
    void Configure(u32 price, u32 available, u32 column);
    void Update();
    void Hide();

    u32 unit_price;
    u32 maximum;
    bool active;
    u32 row;
    u32 column;
    u32 quantity;
    ShopScreenCore * scene;
};

typedef char UiQuantitySize[sizeof(UiPurchaseQuantitySelector) == 28 ? 1 : -1];
typedef char UiQuantityOwner[offsetof(UiPurchaseQuantitySelector, scene) == 24 ? 1 : -1];

#endif // UI_QUANTITY_SELECTOR_HH
