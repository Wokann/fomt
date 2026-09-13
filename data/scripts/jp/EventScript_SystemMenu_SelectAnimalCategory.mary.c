#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_SystemMenu_SelectAnimalCategory_Prompt[] =
        "説明を見たい動物を選んでね";

    const char gText_SystemMenu_SelectAnimalCategory_ChoiceChickens[] =
        "鶏";

    const char gText_SystemMenu_SelectAnimalCategory_ChoiceCows[] =
        "牛";

    const char gText_SystemMenu_SelectAnimalCategory_Sheep[] =
        "羊";

    const char gText_SystemMenu_SelectAnimalCategory_ChoiceCancel[] =
        "やめる";
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
