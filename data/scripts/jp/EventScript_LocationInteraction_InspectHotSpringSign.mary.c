#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectHotSpringSign[] =
        "温泉\r\n"
        "効能…体力、疲労回復\r\n"
        "{Press}";
};

void EventScript_LocationInteraction_InspectHotSpringSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHotSpringSign);
    TalkClose();
}
