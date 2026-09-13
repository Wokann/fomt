#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectYodelRanchBusinessHoursSign[] =
        "「ヨーデル牧場」\r\n"
        "ＡＭ１０時～ＰＭ３時、開いて\r\n"
        "ます。月曜日は出かけてます。{Press}";
};

void EventScript_LocationInteraction_InspectYodelRanchBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectYodelRanchBusinessHoursSign);
    TalkClose();
}
