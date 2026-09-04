#ifndef GUARD_REGION_H
#define GUARD_REGION_H

#if defined(REGION_US) && defined(REGION_JP)
#error "REGION_US and REGION_JP are mutually exclusive"
#elif !defined(REGION_US) && !defined(REGION_JP)
#error "Build through Makefile with REGION=us or REGION=jp"
#endif

#ifdef REGION_US
#define REGION_IS_US 1
#define REGION_IS_JP 0
#include "layout/us/rom_layout.h"
#else
#define REGION_IS_US 0
#define REGION_IS_JP 1
#include "layout/jp/rom_layout.h"
#endif

#endif // GUARD_REGION_H
