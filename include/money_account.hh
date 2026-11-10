#ifndef MONEY_ACCOUNT_HH
#define MONEY_ACCOUNT_HH

#include "prelude.h"
#include <algorithm>
#include <memory>

#include "money_account_types.hh"

template <unsigned Capacity>
inline void MoneyAccountHistory<Capacity>::Erase(MoneyAccountRecord * first, MoneyAccountRecord * last)
{
    MoneyAccountRecord * new_end = std::copy(last, End(), first);
    MoneyAccountRecord * old_end = End();
    for (MoneyAccountRecord * record = new_end; record != old_end; ++record)
        record->~MoneyAccountRecord();
    count -= last - first;
}

template <unsigned Capacity>
inline void MoneyAccountHistory<Capacity>::Assign(u32 size, MoneyAccountRecord const & value)
{
    if (size > Size()) {
        std::fill(Begin(), End(), value);
        std::uninitialized_fill_n(End(), size - Size(), value);
        count = size;
    } else {
        MoneyAccountRecord * last = Begin();
        for (u32 remaining = size; remaining != 0; --remaining, ++last)
            *last = value;
        Erase(last, End());
    }
}

#endif // MONEY_ACCOUNT_HH
