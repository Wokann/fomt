#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Livestock_PregnancyNotice[] =
        "{Var1}is \r\n"
        "prengant!{Press}";
};

void EventScript_FarmEvent_Livestock_PregnancyNotice(void)
{
    int var_0, var_1;
    var_0 = GetInteractingAnimalIndex();
    var_1 = 54 + var_0;
    if (IsCowAtBarnSlot(var_0))
    {
        GetAnimalName(TEXT_VARIABLE_1, ANIMAL_KIND_COW, var_0);
    }
    else
    {
        GetAnimalName(TEXT_VARIABLE_1, ANIMAL_KIND_SHEEP, var_0);
    }
    TalkOpen();
    TalkMessage(gText_FarmEvent_Livestock_PregnancyNotice);
    TalkClose();
    StartEntityEffect(var_1, ENTITY_EMOTE_HEART, FALSE);
}
