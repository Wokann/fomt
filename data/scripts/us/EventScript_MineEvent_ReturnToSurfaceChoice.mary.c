#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_MineEvent_ReturnToSurfaceChoice_ChoiceReturnToSurface[] =
        "Go back to the surface?";

    const char gText_MineEvent_ReturnToSurfaceChoice_Yes[] =
        "Yes";

    const char gText_MineEvent_ReturnToSurfaceChoice_No[] =
        "No";
};

void EventScript_MineEvent_ReturnToSurfaceChoice(void)
{
    int var_0;
    TalkOpen();
    var_0 = TalkPromptChoice2(gText_MineEvent_ReturnToSurfaceChoice_ChoiceReturnToSurface, gText_MineEvent_ReturnToSurfaceChoice_Yes, gText_MineEvent_ReturnToSurfaceChoice_No);
    TalkClose();
    switch (var_0)
    {
        case PROMPT_CHOICE_OPTION_1:
            CallScript(EventScript_LocationTransition_ReturnToMothersHillWithRivalEventDispatch);
            break;
        case PROMPT_CHOICE_OPTION_2:
            break;
    }
}
