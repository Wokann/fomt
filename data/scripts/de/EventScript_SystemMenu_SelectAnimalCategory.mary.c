#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_SystemMenu_SelectAnimalCategory_Prompt[] =
        "Welches Tier?";

    const char gText_SystemMenu_SelectAnimalCategory_ChoiceChickens[] =
        "Hühner";

    const char gText_SystemMenu_SelectAnimalCategory_ChoiceCows[] =
        "Kühe";

    const char gText_SystemMenu_SelectAnimalCategory_Sheep[] =
        "Schafe";

    const char gText_SystemMenu_SelectAnimalCategory_ChoiceCancel[] =
        "Abbruch";
};

void EventScript_SystemMenu_SelectAnimalCategory(void)
{
    int var_0;
    TalkOpen();
    var_0 = TalkPromptChoice4(gText_SystemMenu_SelectAnimalCategory_Prompt, gText_SystemMenu_SelectAnimalCategory_ChoiceChickens, gText_SystemMenu_SelectAnimalCategory_ChoiceCows, gText_SystemMenu_SelectAnimalCategory_Sheep, gText_SystemMenu_SelectAnimalCategory_ChoiceCancel);
    TalkClose();
    switch (var_0)
    {
        case PROMPT_CHOICE_OPTION_1:
            CallScript(EventScript_TutorialEvent_ChickenCareInstructions);
            break;
        case PROMPT_CHOICE_OPTION_2:
            CallScript(EventScript_TutorialEvent_CowCareInstructions);
            break;
        case PROMPT_CHOICE_OPTION_3:
            CallScript(EventScript_TutorialEvent_SheepCareInstructions);
            break;
    }
    return;
}
