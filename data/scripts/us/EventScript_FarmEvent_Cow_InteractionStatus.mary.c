#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Cow_InteractionStatus_Sick[] =
        "Ah...your{Var1}\r\n"
        "is sick.{Press}";

    const char gText_FarmEvent_Cow_InteractionStatus_PregnantBirthSoon[] =
        "{Var1} is pregnant.\r\n"
        "She'll give birth soon.{Press}";

    const char gText_FarmEvent_Cow_InteractionStatus_PregnantBirthLater[] =
        "{Var1} is pregnant.\r\n"
        "The baby is due in\r\n"
        "about {Var2} days.{Press}";

    const char gText_FarmEvent_Cow_InteractionStatus_Unhappy[] =
        "Hmmm...{Var1}\r\n"
        "doesn't seem too happy.{Press}";

    const char gText_FarmEvent_Cow_InteractionStatus_Happy[] =
        "Hi, {Var1}.\r\n"
        "You seem happy today!{Press}";
};

void EventScript_FarmEvent_Cow_InteractionStatus(void)
{
    int var_0, var_1, var_2;
    var_0 = GetInteractingAnimalIndex();
    var_1 = 21 - GetAnimalHealthyPregnancyDays(ANIMAL_KIND_COW, var_0);
    var_2 = HasAnimalBeenTalkedTo(ANIMAL_KIND_COW, var_0);
    GetAnimalName(TEXT_VARIABLE_1, ANIMAL_KIND_COW, var_0);
    if (IsAnimalSick(ANIMAL_KIND_COW, var_0))
    {
        TalkOpen();
        TalkMessage(gText_FarmEvent_Cow_InteractionStatus_Sick);
        TalkClose();
        StartEntityEffect(ENTITY_BARN_ANIMAL_SLOT_1 + var_0, ENTITY_EMOTE_SKULL, FALSE);
    }
    else
    {
        if (IsAnimalPregnant(ANIMAL_KIND_COW, var_0))
        {
            SetTextVariableNumber(TEXT_VARIABLE_2, var_1);
            TalkOpen();
            if (var_1 < 2)
            {
                TalkMessage(gText_FarmEvent_Cow_InteractionStatus_PregnantBirthSoon);
            }
            else
            {
                TalkMessage(gText_FarmEvent_Cow_InteractionStatus_PregnantBirthLater);
            }
            TalkClose();
            PlaySong(AUDIO_START, AUDIO_SFX_COW_MOO);
            if (!var_2)
            {
                StartEntityEffect(ENTITY_BARN_ANIMAL_SLOT_1 + var_0, ENTITY_EMOTE_HEART, FALSE);
            }
        }
        else
        {
            if (IsAnimalUnhappy(ANIMAL_KIND_COW, var_0))
            {
                TalkOpen();
                TalkMessage(gText_FarmEvent_Cow_InteractionStatus_Unhappy);
                TalkClose();
                StartEntityEffect(ENTITY_BARN_ANIMAL_SLOT_1 + var_0, ENTITY_EMOTE_THINKING, FALSE);
            }
            else
            {
                TalkOpen();
                TalkMessage(gText_FarmEvent_Cow_InteractionStatus_Happy);
                TalkClose();
                PlaySong(AUDIO_START, AUDIO_SFX_COW_MOO);
                if (!var_2)
                {
                    StartEntityEffect(ENTITY_BARN_ANIMAL_SLOT_1 + var_0, ENTITY_EMOTE_HEART, FALSE);
                }
            }
        }
    }
    if (!var_2)
    {
        SetAnimalTalkedTo(ANIMAL_KIND_COW, var_0);
        AddAnimalAffection(ANIMAL_KIND_COW, var_0, 1);
    }
}
