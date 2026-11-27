#ifndef MORE_ITEMS_HH
#define MORE_ITEMS_HH

#include "actor.hh"

struct MoreItems
{
    MoreItems();
    ~MoreItems()
    {
        u8 * last = data + size;
        u8 * first = data;
        while (first != last) {
            first->~u8();
            ++first;
        }
    }

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


#endif // MORE_ITEMS_HH
