#include "field_plot_position_rules.hh"
#include "actor.hh"

extern "C" u32 GetFieldPlotPositionRuleResult(Location const & location)
{
    u32 result = 7;
    i32 x = location.x / 8;
    i32 y = location.y / 8;
    for (i32 index = 0; index < static_cast<i32>(ARRAY_COUNT(gFieldPlotPositionRules)); ++index) {
        if (location.map == gFieldPlotPositionRules[index].match_value
            && x >= gFieldPlotPositionRules[index].minimum_x
            && x <= gFieldPlotPositionRules[index].maximum_x
            && y >= gFieldPlotPositionRules[index].minimum_y
            && y <= gFieldPlotPositionRules[index].maximum_y) {
            result = gFieldPlotPositionRules[index].result;
            break;
        }
    }
    return result;
}

FieldPlotPositionRule const gFieldPlotPositionRules[8] = {
    { 0x00000000, 0x00000021, 0x0000002A, 0x00000048, 0x00000044, 0x00000000 },
    { 0x00000000, 0x00000035, 0x00000020, 0x0000007D, 0x00000029, 0x00000001 },
    { 0x00000000, 0x00000075, 0x0000002A, 0x00000095, 0x00000033, 0x00000002 },
    { 0x00000002, 0x00000000, 0x0000002F, 0x0000007F, 0x00000057, 0x00000003 },
    { 0x00000001, 0x00000019, 0x00000000, 0x0000003F, 0x00000049, 0x00000004 },
    { 0x0000002B, 0x00000001, 0x00000000, 0x0000001C, 0x0000000A, 0x00000005 },
    { 0x00000000, 0x0000006E, 0x00000038, 0x00000075, 0x0000003D, 0x00000006 },
    { 0x00000007, 0x00000020, 0x0000003A, 0x000000AC, 0x0000003F, 0x00000003 },
};

#include FOMT_TEXT_INCLUDE(field_plot_position_rules.cc)
