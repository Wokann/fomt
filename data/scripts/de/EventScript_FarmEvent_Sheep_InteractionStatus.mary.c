#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Sheep_InteractionStatus_Sick[] =
        "Ah...{Var1}\r\n"
        "ist krank.{Press}";

    const char gText_FarmEvent_Sheep_InteractionStatus_PregnantBirthSoon[] =
        "{Var1} ist trächtig.\r\n"
        "Es ist bald soweit.{Press}";

    const char gText_FarmEvent_Sheep_InteractionStatus_PregnantBirthLater[] =
        "Das Baby kommt in\r\n"
        "ungefähr \r\n"
        "{Var2} Tagen.{Press}";

    const char gText_FarmEvent_Sheep_InteractionStatus_Unhappy[] =
        "Hmmm...{Var1}\r\n"
        "sieht nicht allzu froh aus.{Press}";

    const char gText_FarmEvent_Sheep_InteractionStatus_Happy[] =
        "Hi, {Var1}.\r\n"
        "Du siehst heute froh aus!{Press}";
};

void EventScript_FarmEvent_Sheep_InteractionStatus(void)
{
    int var_0, var_1, var_2, var_3, var_4;
    var_0 = GetInteractingAnimalIndex();
    var_1 = GetAnimalHealthyPregnancyDays(ANIMAL_KIND_SHEEP, var_0);
    var_2 = 21;
    var_3 = var_2 - var_1;
    var_4 = HasAnimalBeenTalkedTo(ANIMAL_KIND_SHEEP, var_0);
    GetAnimalName(TEXT_VARIABLE_1, ANIMAL_KIND_SHEEP, var_0);
    if (IsAnimalSick(ANIMAL_KIND_SHEEP, var_0))
    {
        TalkOpen();
        TalkMessage(gText_FarmEvent_Sheep_InteractionStatus_Sick);
        TalkClose();
        StartEntityEffect(ENTITY_BARN_ANIMAL_SLOT_1 + var_0, ENTITY_EMOTE_SKULL, FALSE);
    }
    else
    {
        if (IsAnimalPregnant(ANIMAL_KIND_SHEEP, var_0))
        {
            SetTextVariableNumber(TEXT_VARIABLE_2, var_3);
            TalkOpen();
            if (var_3 < 2)
            {
                TalkMessage(gText_FarmEvent_Sheep_InteractionStatus_PregnantBirthSoon);
                TalkClose();
            }
            else
            {
                TalkMessage(gText_FarmEvent_Sheep_InteractionStatus_PregnantBirthLater);
                TalkClose();
            }
            PlaySong(AUDIO_START, AUDIO_SFX_SHEEP_BLEAT);
            if (!var_4)
            {
                StartEntityEffect(ENTITY_BARN_ANIMAL_SLOT_1 + var_0, ENTITY_EMOTE_HEART, FALSE);
            }
        }
        else
        {
            if (IsAnimalUnhappy(ANIMAL_KIND_SHEEP, var_0))
            {
                TalkOpen();
                TalkMessage(gText_FarmEvent_Sheep_InteractionStatus_Unhappy);
                TalkClose();
                StartEntityEffect(ENTITY_BARN_ANIMAL_SLOT_1 + var_0, ENTITY_EMOTE_THINKING, FALSE);
            }
            else
            {
                TalkOpen();
                TalkMessage(gText_FarmEvent_Sheep_InteractionStatus_Happy);
                TalkClose();
                PlaySong(AUDIO_START, AUDIO_SFX_SHEEP_BLEAT);
                if (!var_4)
                {
                    StartEntityEffect(ENTITY_BARN_ANIMAL_SLOT_1 + var_0, ENTITY_EMOTE_HEART, FALSE);
                }
            }
        }
    }
    if (!var_4)
    {
        SetAnimalTalkedTo(ANIMAL_KIND_SHEEP, var_0);
        AddAnimalAffection(ANIMAL_KIND_SHEEP, var_0, 1);
    }
}
