#ifndef CONTAINER_ALGORITHMS_HH
#define CONTAINER_ALGORITHMS_HH

// Adapted from STLport 4.5.3: _algobase.h and _construct.h.
// Copyright (c) 1994 Hewlett-Packard Company
// Copyright (c) 1996,1997 Silicon Graphics Computer Systems, Inc.
// Copyright (c) 1997 Moscow Center for SPARC Technology
// Copyright (c) 1999 Boris Fomitchev
// This material is provided "as is", with absolutely no warranty expressed
// or implied. Any use is at your own risk.
// Permission to use or copy this software for any purpose is hereby granted
// without fee, provided the above notices are retained on all copies.
// Permission to modify the code and to distribute modified code is granted,
// provided the above notices are retained, and a notice that the code was
// modified is included with the above copyright notice.
// Modified: retain pointer-range copy/destruction and reference-based
// maximum selection, plus the three-argument pointer find from the bundled
// stl_algo.h, without replacing the other library headers.

#include "prelude.h"
#include <type_traits.h>
#include <string.h>

template<class Input, class Output>
inline Output copy_ptrs_inl(Input first, Input last, Output result,
    __false_type const &)
{
    for (ptrdiff_t count = last - first; count > 0; --count) {
        *result = *first;
        ++first;
        ++result;
    }
    return result;
}

template<class Input, class Output>
inline Output copy_ptrs_inl(Input first, Input last, Output result,
    __true_type const &)
{
    if (first != last)
        memmove(result, first, (last - first) * sizeof(*first));
    return result + (last - first);
}

template<class Iterator>
inline void destroy_object_inl(Iterator * object)
{
    object->~Iterator();
}

template<class Iterator>
inline void destroy_range_inl(Iterator first, Iterator last,
    __false_type const &)
{
    for (; first != last; ++first)
        destroy_object_inl(&*first);
}

template<class Iterator>
inline void destroy_range_inl(Iterator, Iterator, __true_type const &)
{
}

// SGI stl_construct.h passes the trait by value and projects the element
// type before dispatch. Keep this allocator-free pointer-range interface
// separate from the STLport const-reference overload above.
template<class Iterator>
inline void destroy_ptrs_aux(Iterator first, Iterator last, __false_type)
{
    for (; first != last; ++first)
        destroy_object_inl(&*first);
}

template<class Iterator>
inline void destroy_ptrs_aux(Iterator, Iterator, __true_type) {}

template<class Iterator, class Value>
inline void destroy_ptrs_typed(Iterator first, Iterator last, Value *)
{
    typedef typename __type_traits<Value>::has_trivial_destructor Trait;
    destroy_ptrs_aux(first, last, Trait());
}

template<class Value>
inline void destroy_ptrs(Value * first, Value * last)
{
    destroy_ptrs_typed(first, last, static_cast<Value *>(nullptr));
}

template<class T>
inline T const & max_ref_inl(T const & a, T const & b)
{
    return a < b ? b : a;
}

// The native pointer-range find entry has no iterator-category argument.
// Keep the four-element search and remainder order from the bundled STL.
template<class Iterator, class Value>
Iterator find_ptrs(Iterator begin, Iterator last, Value const & value)
{
    Iterator cursor = begin;
    ptrdiff_t groups = (last - cursor) >> 2;
    for (; groups > 0; --groups) {
        if (*cursor == value) return cursor;
        ++cursor;
        if (*cursor == value) return cursor;
        ++cursor;
        if (*cursor == value) return cursor;
        ++cursor;
        if (*cursor == value) return cursor;
        ++cursor;
    }
    switch (last - cursor) {
    case 3:
        if (*cursor == value) return cursor;
        ++cursor;
    case 2:
        if (*cursor == value) return cursor;
        ++cursor;
    case 1:
        if (*cursor == value) return cursor;
        ++cursor;
    case 0:
    default:
        return last;
    }
}

#endif // CONTAINER_ALGORITHMS_HH
