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
// maximum selection, without replacing the other library headers.

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

template<class T>
inline T const & max_ref_inl(T const & a, T const & b)
{
    return a < b ? b : a;
}

#endif // CONTAINER_ALGORITHMS_HH
