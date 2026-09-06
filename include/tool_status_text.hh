#ifndef TOOL_STATUS_TEXT_HH
#define TOOL_STATUS_TEXT_HH

#include "prelude.h"

#define TOOL_STATUS_TEXT SECTION(".rodata.tool_status")

extern char const gText_ToolStatus_GemOfTruth[];
extern char const gText_ToolStatus_EnergyLabel[];
extern char const gText_ToolStatus_ValueSeparator[];
extern char const gText_ToolStatus_EnergyFatigueLineBreak[];
extern char const gText_ToolStatus_FatigueLabel[];
extern char const gText_ToolStatus_FatigueMaximum[];
extern char const gText_ToolStatus_PedometerLabel[];
extern char const gText_ToolStatus_PedometerStepsSuffix[];

#if defined(REGION_JP)
extern char const gText_ToolStatus_DescriptionQuoteOpen[];
extern char const gText_ToolStatus_DescriptionQuoteClose[];
extern char const gText_ToolStatus_RemainingSquaresPrefix[];
extern char const gText_ToolStatus_RemainingSquaresSuffix[];
#else
extern char const gText_ToolStatus_DescriptionQuotePrefix[];
extern char const gText_ToolStatus_RemainingSquaresSuffix[];
#endif

#endif // TOOL_STATUS_TEXT_HH
