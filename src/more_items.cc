#include "more_items.hh"

#include <new>

u32 func_0800FFD0(MoreItems const * self)
{
    return self->size;
}

u8 * func_0800FFD4(MoreItems * self)
{
    return self->data;
}

u8 * func_0800FFD8(MoreItems * self)
{
    return self->data + self->size;
}

MoreItemsState func_0800FFE0(MoreItems const * self)
{
    return self->unk_24;
}

void func_0800FFF4(MoreItems * self, u32 value)
{
    if (self->size < ARRAY_COUNT(self->data))
    {
        u8 * destination = (u8 *)self + (offsetof(MoreItems, data) + self->size);
        new (destination) u8(value);
        self->size++;
    }
}

void func_08010014(MoreItems * self, MoreItemsState const & value)
{
    self->unk_24 = value;
}
