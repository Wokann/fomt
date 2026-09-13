#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Livestock_NewBirthAndNaming_BirthExpectedSoon[] =
        "It should be born soon...{Press}";

    const char gText_FarmEvent_Livestock_NewBirthAndNaming_PromptNameNewChick[] =
        "A Baby Chick has been born.\r\n"
        "Give it a name for this \r\n"
        "life.{Press}";

    const char gText_FarmEvent_Livestock_NewBirthAndNaming_PromptNameNewCalf[] =
        "A Calf has been born.\r\n"
        "Give it a name for this \r\n"
        "life.{Press}";

    const char gText_FarmEvent_Livestock_NewBirthAndNaming_PromptNameNewLamb[] =
        "A Lamb has been born.\r\n"
        "Give it a name for this \r\n"
        "life.{Press}";

    const char gText_FarmEvent_Livestock_NewBirthAndNaming_PlayerWelcomesNewAnimal[] =
        "A new member of my family.\r\n"
        "Gotta work harder.{Press}";
};

void EventScript_FarmEvent_Livestock_NewBirthAndNaming(void)
{
    int var_0, var_1, var_2, var_3, var_4;
    var_2 = FALSE;
    for (var_0 = 0; var_0 < GetIncubatorCapacity(); ++var_0)
    {
        if (IsEggReadyToHatch(var_0))
        {
            var_2 = TRUE;
        }
    }
    for (var_0 = 0; var_0 < GetPregnancyStallCapacity(); ++var_0)
    {
        if (IsBarnAnimalReadyToGiveBirth(var_0))
        {
            var_2 = TRUE;
        }
    }
    if (var_2 != FALSE)
    {
        TalkOpen();
        TalkMessage(gText_FarmEvent_Livestock_NewBirthAndNaming_BirthExpectedSoon);
        TalkClose();
        for (var_0 = 0; var_0 < GetIncubatorCapacity(); ++var_0)
        {
            if (IsEggReadyToHatch(var_0))
            {
                var_1 = AttemptEggHatch(var_0);
                ChangeMap(MAP_CHICKEN_COOP, X(59), Y(153));
                var_3 = GetEntityX(ENTITY_ANIMAL_CHICKEN_SLOT_1 + var_1);
                var_4 = GetEntityY(ENTITY_ANIMAL_CHICKEN_SLOT_1 + var_1);
                HideEntity(ENTITY_ANIMAL_CHICKEN_SLOT_1 + var_1);
                SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(var_3), Y(var_4), FACING_RIGHT);
                SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICK_IDLE);
                SetEntityPosition(ENTITY_PLAYER, X(var_3 + 17), Y(var_4), FACING_LEFT);
                if (IsPlayerHoldingNothing() == TRUE)
                {
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                }
                else
                {
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
                }
                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                TalkOpen();
                TalkMessage(gText_FarmEvent_Livestock_NewBirthAndNaming_PromptNameNewChick);
                TalkClose();
                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                OpenNameEntry(NAME_ENTRY_CHICKEN, var_1);
                HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
                SetEntityPosition(ENTITY_ANIMAL_CHICKEN_SLOT_1 + var_1, X(var_3), Y(var_4), FACING_RIGHT);
            }
        }
        for (var_0 = 0; var_0 < GetPregnancyStallCapacity(); ++var_0)
        {
            if (IsBarnAnimalReadyToGiveBirth(var_0))
            {
                var_1 = AttemptBarnAnimalBirth(var_0);
                var_3 = GetEntityX(ENTITY_BARN_ANIMAL_SLOT_1 + var_1);
                var_4 = GetEntityY(ENTITY_BARN_ANIMAL_SLOT_1 + var_1);
                ChangeMap(MAP_BARN, X(var_3 + 26), Y(var_4));
                SetEntityPosition(ENTITY_PLAYER, X(var_3 + 26), Y(var_4), FACING_LEFT);
                if (IsPlayerHoldingNothing() == TRUE)
                {
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                }
                else
                {
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
                }
                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                if (IsCowAtBarnSlot(var_1))
                {
                    TalkOpen();
                    TalkMessage(gText_FarmEvent_Livestock_NewBirthAndNaming_PromptNameNewCalf);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    OpenNameEntry(NAME_ENTRY_COW, var_1);
                }
                else
                {
                    TalkOpen();
                    TalkMessage(gText_FarmEvent_Livestock_NewBirthAndNaming_PromptNameNewLamb);
                    TalkClose();
                    OpenNameEntry(NAME_ENTRY_SHEEP, var_1);
                }
            }
        }
        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        TalkOpen();
        TalkMessage(gText_FarmEvent_Livestock_NewBirthAndNaming_PlayerWelcomesNewAnimal);
        TalkClose();
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
    CallScript(EventScript_FarmEvent_Livestock_DeathConsequences);
}
