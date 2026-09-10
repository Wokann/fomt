#ifndef FIELD_PLOT_POSITION_RULES_HH
#define FIELD_PLOT_POSITION_RULES_HH

#include "field.hh"

struct FieldPlotPositionRule
{
    u32 match_value;
    i32 minimum_x;
    i32 minimum_y;
    i32 maximum_x;
    i32 maximum_y;
    u32 result;
};

extern FieldPlotPositionRule const gFieldPlotPositionRules[8];
extern char const gCppRuntimeBadAlloc_FieldPlotPositionRules[];

#endif // FIELD_PLOT_POSITION_RULES_HH
