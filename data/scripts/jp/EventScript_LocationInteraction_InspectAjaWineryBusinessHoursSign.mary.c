#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectAjaWineryBusinessHoursSign[] =
        "「アージュワイナリー」\r\n"
        "土曜日以外の朝１０時～正午\r\n"
        "ワイン、ジュースを売ってます{Press}";
};

void EventScript_LocationInteraction_InspectAjaWineryBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectAjaWineryBusinessHoursSign);
    TalkClose();
}
