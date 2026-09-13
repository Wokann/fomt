#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectKaiRestaurantCookingUtensils[] =
        "調理道具{Press}";
};

void EventScript_LocationInteraction_InspectKaiRestaurantCookingUtensils(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectKaiRestaurantCookingUtensils);
    TalkClose();
}
