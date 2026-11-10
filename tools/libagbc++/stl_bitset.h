/*
 * Copyright (c) 1998
 * Silicon Graphics Computer Systems, Inc.
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation. Silicon Graphics makes no
 * representations about the suitability of this software for any
 * purpose. It is provided "as is" without express or implied warranty.
 */

#ifndef __SGI_STL_INTERNAL_BITSET_H
#define __SGI_STL_INTERNAL_BITSET_H

// Numeric bitset interface adapted from GCC 2.95.3's SGI implementation.
// This declaration header can describe stored values without importing
// algorithm implementations. Include <bitset> when constructing or using
// them. String, stream, and exception interfaces are not provided here.
// As with SGI STL configured without exceptions, callers must supply a
// bit index below size(). The word type must be unsigned integral.
#include <stl_config.h>
#include <stddef.h>
#include <limits.h>

#define __BITS_PER_WORDT(__wt) (CHAR_BIT * sizeof(__wt))
#define __BITSET_WORDS(__n,__wt) \
  ((__n) < 1 ? 1 : ((__n) + __BITS_PER_WORDT(__wt) - 1) / __BITS_PER_WORDT(__wt))

__STL_BEGIN_NAMESPACE

template<size_t _Nw, class _WordT>
struct _Base_bitset {
  _WordT _M_w[_Nw];
  inline _Base_bitset();
  inline _Base_bitset(unsigned long __val);
  static inline size_t _S_whichword(size_t __pos);
  static inline size_t _S_whichbit(size_t __pos);
  static inline _WordT _S_maskbit(size_t __pos);
  inline _WordT& _M_getword(size_t __pos);
  inline const _WordT& _M_getword(size_t __pos) const;
  inline void _M_do_reset();
};

template<class _WordT>
struct _Base_bitset<1, _WordT> {
  _WordT _M_w;
  inline _Base_bitset();
  inline _Base_bitset(unsigned long __val);
  static inline size_t _S_whichbit(size_t __pos);
  static inline _WordT _S_maskbit(size_t __pos);
  inline _WordT& _M_getword(size_t);
  inline const _WordT& _M_getword(size_t) const;
  inline void _M_do_reset();
};

template<size_t _Nb, class _WordT = unsigned long>
class bitset : private _Base_bitset<__BITSET_WORDS(_Nb,_WordT), _WordT> {
public:
  inline bitset();
  inline bitset(unsigned long __val);
  inline bitset& _Unchecked_set(size_t __pos);
  inline bitset& _Unchecked_reset(size_t __pos);
  inline bool _Unchecked_test(size_t __pos) const;
  inline bitset& set(size_t __pos);
  inline bitset& reset(size_t __pos);
  inline bitset& reset();
  inline bool test(size_t __pos) const;
  inline size_t size() const;
};

__STL_END_NAMESPACE
#endif
