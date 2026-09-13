#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectHotSpringEggSign[] =
        "Wenn du von hier ein Ei\r\n"
        "hineinwirfst, kannst du\r\n"
        "ein Thermalei machen!{Press}";
};

void EventScript_LocationInteraction_InspectHotSpringEggSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHotSpringEggSign);
    TalkClose();
}
