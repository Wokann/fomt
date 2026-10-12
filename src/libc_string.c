/*
 * Adapted from the newlib string routines distributed with agbcc.
 * The seven functions below retain their original ROM order.
 *
 * Copyright (c) 1994, 1997 Cygnus Solutions.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * at Cygnus Solutions. Cygnus Solutions may not be used to
 * endorse or promote products derived from this software without
 * specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#include <string.h>

#define UNALIGNED(X, Y) \
    (((long)(X) & (sizeof(long) - 1)) | ((long)(Y) & (sizeof(long) - 1)))
#define ALIGNED(X) (((long)(X) & (sizeof(long) - 1)) == 0)
#define LBLOCKSIZE sizeof(long)
#define BIGBLOCKSIZE (sizeof(long) << 2)
#define DETECTNULL(X) (((X) - 0x01010101) & ~(X) & 0x80808080)

int memcmp(void const * m1, void const * m2, size_t n)
{
    unsigned char * s1 = (unsigned char *)m1;
    unsigned char * s2 = (unsigned char *)m2;
    unsigned long * a1;
    unsigned long * a2;

    if (n >= LBLOCKSIZE && !UNALIGNED(s1, s2)) {
        a1 = (unsigned long *)s1;
        a2 = (unsigned long *)s2;
        while (n >= LBLOCKSIZE) {
            if (*a1 != *a2)
                break;
            a1++;
            a2++;
            n -= LBLOCKSIZE;
        }
        s1 = (char *)a1;
        s2 = (char *)a2;
    }

    while (n--) {
        if (*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
    }
    return 0;
}

void * memcpy(void * dst0, void const * src0, size_t len0)
{
    char * dst = dst0;
    char const * src = src0;
    long * aligned_dst;
    long const * aligned_src;
    int len = len0;

    if (len >= BIGBLOCKSIZE && !UNALIGNED(src, dst)) {
        aligned_dst = (long *)dst;
        aligned_src = (long *)src;
        while (len >= BIGBLOCKSIZE) {
            *aligned_dst++ = *aligned_src++;
            *aligned_dst++ = *aligned_src++;
            *aligned_dst++ = *aligned_src++;
            *aligned_dst++ = *aligned_src++;
            len -= BIGBLOCKSIZE;
        }
        while (len >= LBLOCKSIZE) {
            *aligned_dst++ = *aligned_src++;
            len -= LBLOCKSIZE;
        }
        dst = (char *)aligned_dst;
        src = (char *)aligned_src;
    }

    while (len--)
        *dst++ = *src++;
    return dst0;
}

void * memmove(void * dst_void, void const * src_void, size_t length)
{
    char * dst = dst_void;
    char const * src = src_void;
    long * aligned_dst;
    long const * aligned_src;
    int len = length;

    if (src < dst && dst < src + len) {
        src += len;
        dst += len;
        while (len--)
            *--dst = *--src;
    } else {
        if (len >= BIGBLOCKSIZE && !UNALIGNED(src, dst)) {
            aligned_dst = (long *)dst;
            aligned_src = (long *)src;
            while (len >= BIGBLOCKSIZE) {
                *aligned_dst++ = *aligned_src++;
                *aligned_dst++ = *aligned_src++;
                *aligned_dst++ = *aligned_src++;
                *aligned_dst++ = *aligned_src++;
                len -= BIGBLOCKSIZE;
            }
            while (len >= LBLOCKSIZE) {
                *aligned_dst++ = *aligned_src++;
                len -= LBLOCKSIZE;
            }
            dst = (char *)aligned_dst;
            src = (char *)aligned_src;
        }
        while (len--)
            *dst++ = *src++;
    }
    return dst_void;
}

void * memset(void * m, int c, size_t n)
{
    char * s = (char *)m;
    unsigned long buffer;
    unsigned long * aligned_addr;

    if (n >= LBLOCKSIZE && ALIGNED(m)) {
        aligned_addr = (unsigned long *)m;
        c &= 0xff;
        buffer = (c << 8) | c;
        buffer |= buffer << 16;

        while (n >= LBLOCKSIZE * 4) {
            *aligned_addr++ = buffer;
            *aligned_addr++ = buffer;
            *aligned_addr++ = buffer;
            *aligned_addr++ = buffer;
            n -= LBLOCKSIZE * 4;
        }
        while (n >= LBLOCKSIZE) {
            *aligned_addr++ = buffer;
            n -= LBLOCKSIZE;
        }
        s = (char *)aligned_addr;
    }

    while (n--)
        *s++ = (char)c;
    return m;
}

char * strcat(char * s1, char const * s2)
{
    char * s = s1;

    if (ALIGNED(s1)) {
        unsigned long * aligned_s1 = (unsigned long *)s1;
        while (!DETECTNULL(*aligned_s1))
            aligned_s1++;
        s1 = (char *)aligned_s1;
    }

    while (*s1)
        s1++;
    strcpy(s1, s2);
    return s;
}

char * strcpy(char * dst0, char const * src0)
{
    char * dst = dst0;
    char const * src = src0;
    long * aligned_dst;
    long const * aligned_src;

    if (!UNALIGNED(src, dst)) {
        aligned_dst = (long *)dst;
        aligned_src = (long *)src;
        while (!DETECTNULL(*aligned_src))
            *aligned_dst++ = *aligned_src++;
        dst = (char *)aligned_dst;
        src = (char *)aligned_src;
    }

    while ((*dst++ = *src++))
        ;
    return dst0;
}

size_t strlen(char const * str)
{
    char const * start = str;
    unsigned long * aligned_addr;

    if (ALIGNED(str)) {
        aligned_addr = (unsigned long *)str;
        while (!DETECTNULL(*aligned_addr))
            aligned_addr++;
        str = (char *)aligned_addr;
    }

    while (*str)
        str++;
    return str - start;
}
