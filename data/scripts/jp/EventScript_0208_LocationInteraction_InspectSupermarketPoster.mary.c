#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectSupermarketPoster[] =
        "ポスター{Press}";
};

void EventScript_0208_LocationInteraction_InspectSupermarketPoster(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectSupermarketPoster);
    TalkClose();
}
