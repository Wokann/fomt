#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectClinicBusinessHoursSign[] =
        "「ミネラル医院」\r\n"
        "診察時間　午前９時～午後４時\r\n"
        "休診日　水曜日{Press}";
};

void EventScript_LocationInteraction_InspectClinicBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectClinicBusinessHoursSign);
    TalkClose();
}
