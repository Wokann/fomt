#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0008_FarmEvent_Cow_InteractionStatus.mary.h"

void EventScript_0008_FarmEvent_Cow_InteractionStatus(void)
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
