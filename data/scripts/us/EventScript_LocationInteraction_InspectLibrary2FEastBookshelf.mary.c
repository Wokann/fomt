#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectLibrary2FEastBookshelf[] =
        "Bookshelf\r\n"
        "{Press}";
};

void EventScript_LocationInteraction_InspectLibrary2FEastBookshelf(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ShowReferencePage(REFERENCE_PAGE_STAMINA_AND_FATIGUE);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
    else
    {
        TalkOpen();
        TalkMessage(gText_LocationInteraction_InspectLibrary2FEastBookshelf);
        TalkClose();
    }
}
