#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectClinicBusinessHoursSign[] =
        "Mineralklinik\r\n"
        "Öffnungszeiten: 9-16 Uhr\r\n"
        "mittwochs geschlossen{Press}";
};

void EventScript_LocationInteraction_InspectClinicBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectClinicBusinessHoursSign);
    TalkClose();
}
