#ifndef MORE_ITEMS_HH
#define MORE_ITEMS_HH

#include "actor.hh"

struct MoreItems
{
    MoreItems();

    u32 GetSize() const;
    u8 * Begin();
    u8 * End();
    Location GetLocation() const;
    void PushBack(u32 value);
    void SetLocation(Location const & value);
    void Clear();

    // Only the first size slots have an active byte object. The constructor
    // leaves inactive slots and the save-image padding untouched.
    /* +00 */ u32 size;
    /* +04 */ u8 data[30];
    /* +24 */ Location location ALIGN(4);
};

typedef char MoreItems_data_offset_check[offsetof(MoreItems, data) == 4 ? 1 : -1];
typedef char MoreItems_location_offset_check[offsetof(MoreItems, location) == 0x24 ? 1 : -1];
typedef char MoreItems_size_check[sizeof(MoreItems) == 0x2C ? 1 : -1];

#endif // MORE_ITEMS_HH
