#ifndef UI_PORTRAIT_HH
#define UI_PORTRAIT_HH

#include "resource_handle.hh"

// Own the current portrait archive group, including sprite and tile/palette
// ranges. The pointed-to 32-byte result borrows its actual archive payload.
struct UiPortraitGroupOwner
{
    IndexedResourceGroupResult * value;
    UiPortraitGroupOwner();
    UiPortraitGroupOwner(u32 index);
    ~UiPortraitGroupOwner();
    void Set(u32 index);
    IndexedResourceGroupResult Get() const;
};


EXTERN_C
u32 GetUiPortraitCount();
extern u8 const gPortraitIndexedResourceArchive[];
EXTERN_C_END

#endif // UI_PORTRAIT_HH
