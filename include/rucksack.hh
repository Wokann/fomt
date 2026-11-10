#ifndef RUCKSACK_HH
#define RUCKSACK_HH

#include "prelude.h"

#include "rucksack_item.hh"
#include <iterator>
#include <new>

#include "rucksack_types.hh"

template <typename T>
inline void Rucksack::Slots<T>::ConstructRange(T const * first, T const * last, T * destination)
{
    iterator current = destination;
    while (first != last) {
        new (current) T(*first);
        ++first;
        ++current;
    }
}

template <typename T>
inline Rucksack::Slots<T>::Slots(Slots const & other) : m_size(0)
{
    u32 active = other.m_size;
    const_iterator start = other.begin();
    // The slot arena uses word storage; derive the live extent from T.
    u32 end_address = active * sizeof(T);
    end_address += reinterpret_cast<u32>(start);
    const_iterator last = reinterpret_cast<const_iterator>(end_address);
    ConstructRange(other.begin(), last, begin());
    m_size = active;
}

#endif // RUCKSACK_HH
