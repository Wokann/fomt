#ifndef FIELD_PLOT_POSITION_RULES_HH
#define FIELD_PLOT_POSITION_RULES_HH

#include "prelude.h"

struct FieldPlotPositionRule
{
    u32 match_value;
    i32 minimum_x;
    i32 minimum_y;
    i32 maximum_x;
    i32 maximum_y;
    u32 result;
};

struct Location;

// Native classifier returns the matching rule result, or 7 if none matches.
EXTERN_C
u32 func_080A45A8(Location const & location);
EXTERN_C_END

extern FieldPlotPositionRule const gFieldPlotPositionRules[8];
extern char const gCppRuntimeBadAlloc_FieldPlotPositionRules[];

#endif // FIELD_PLOT_POSITION_RULES_HH
