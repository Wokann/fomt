#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Foal_Talk[] =
        "Here here...\r\n"
        "Get big and strong now.{Press}";
};

void EventScript_FarmEvent_Foal_Talk(void)
{
    int var_0;
    var_0 = HasAnimalBeenTalkedTo(ANIMAL_KIND_HORSE, ANIMAL_PET_INDEX_ARGUMENT_IGNORED_ZERO);
    TalkOpen();
    TalkMessage(gText_FarmEvent_Foal_Talk);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_FOAL_NEIGH);
    if (!var_0)
    {
        StartEntityEffect(ENTITY_FARM_HORSE, ENTITY_EMOTE_HEART, FALSE);
        SetAnimalTalkedTo(ANIMAL_KIND_HORSE, ANIMAL_PET_INDEX_ARGUMENT_IGNORED_ZERO);
        AddAnimalAffection(ANIMAL_KIND_HORSE, ANIMAL_PET_INDEX_ARGUMENT_IGNORED_ZERO, 1);
    }
}
