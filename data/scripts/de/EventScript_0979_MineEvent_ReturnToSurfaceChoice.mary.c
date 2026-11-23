#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0979_MineEvent_ReturnToSurfaceChoice.mary.h"

void EventScript_0979_MineEvent_ReturnToSurfaceChoice(void)
{
    int var_0;
    TalkOpen();
    var_0 = TalkPromptChoice2(gText_MineEvent_ReturnToSurfaceChoice_ChoiceReturnToSurface, gText_MineEvent_ReturnToSurfaceChoice_Yes, gText_MineEvent_ReturnToSurfaceChoice_No);
    TalkClose();
    switch (var_0)
    {
        case PROMPT_CHOICE_OPTION_1:
            CallScript(EventScript_0977_LocationTransition_ReturnToMothersHillWithRivalEventDispatch);
            break;
        case PROMPT_CHOICE_OPTION_2:
            break;
    }
}
