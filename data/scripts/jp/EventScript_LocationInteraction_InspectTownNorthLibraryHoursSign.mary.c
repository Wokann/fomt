#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectTownNorthLibraryHoursSign_InspectTownNorthLibraryHoursAfterMaryMarriage[] =
        "「マリーの図書館」\r\n"
        "開館　午前１０時\r\n"
        "閉館　午後４時　　木曜日休館{Press}";

    const char gText_LocationInteraction_InspectTownNorthLibraryHoursSign_InspectTownNorthLibraryHoursBeforeMaryMarriage[] =
        "「マリーの図書館」\r\n"
        "開館　午前１０時\r\n"
        "閉館　午後４時　　月曜日休館{Press}";
};

void EventScript_LocationInteraction_InspectTownNorthLibraryHoursSign(void)
{
    TalkOpen();
    if (VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
    {
        TalkAppendMessage(gText_LocationInteraction_InspectTownNorthLibraryHoursSign_InspectTownNorthLibraryHoursAfterMaryMarriage);
    }
    else
    {
        TalkAppendMessage(gText_LocationInteraction_InspectTownNorthLibraryHoursSign_InspectTownNorthLibraryHoursBeforeMaryMarriage);
    }
    TalkClose();
}
