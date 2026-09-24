#ifndef GUARD_REGION_H
#define GUARD_REGION_H

#if (defined(REGION_US) + defined(REGION_JP) + defined(REGION_EU) + defined(REGION_DE)) != 1
#error "Define exactly one of REGION_US, REGION_JP, REGION_EU, or REGION_DE"
#endif

#if defined(REGION_US)
#define FOMT_TEXT_REGION_DIR us
#elif defined(REGION_JP)
#define FOMT_TEXT_REGION_DIR jp
#elif defined(REGION_EU)
#define FOMT_TEXT_REGION_DIR eu
#else
#define FOMT_TEXT_REGION_DIR de
#endif

// Macro-expanded header names select the maintained regional text source.
// This keeps EU and DE distinct from the US baseline while the owning C/C++
// module remains shared.
#define FOMT_TEXT_INCLUDE_PATH(region, file) <data/text/region/file>
#define FOMT_TEXT_INCLUDE_EXPAND(region, file) FOMT_TEXT_INCLUDE_PATH(region, file)
#define FOMT_TEXT_INCLUDE(file) FOMT_TEXT_INCLUDE_EXPAND(FOMT_TEXT_REGION_DIR, file)

#endif // GUARD_REGION_H
