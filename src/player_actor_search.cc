#include "prelude.h"
#include <iterator>

namespace std {
template <class Iterator, class Value>
Iterator find(Iterator, Iterator, Value const &, random_access_iterator_tag);

template <>
u8 * find<u8 *, u8>(u8 * begin, u8 * last, u8 const & value, random_access_iterator_tag)
{
    u8 * current = begin;
    ptrdiff_t groups = (last - current) >> 2;
    for (; groups > 0; --groups) {
        if (*current == value) return current;
        ++current;
        if (*current == value) return current;
        ++current;
        if (*current == value) return current;
        ++current;
        if (*current == value) return current;
        ++current;
    }
    switch (last - current) {
    case 3:
        if (*current == value) return current;
        ++current;
    case 2:
        if (*current == value) return current;
        ++current;
    case 1:
        if (*current == value) return current;
        ++current;
    case 0:
    default:
        return last;
    }
}
}
