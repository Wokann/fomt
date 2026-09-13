#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Doctor[] =
        "I came because I heard \r\n"
        "Lillia was going to compete.{Press}\p"
        "I should be near her in \r\n"
        "case she gets sick. {Press}";
};

void EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Doctor(void)
{
    if (HasMetNpc(CHARACTER_DOCTOR) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DOCTOR);
    }
    SetEntityFacing(ENTITY_DOCTOR, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Doctor);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_DOCTOR) == FALSE)
    {
        AddNpcFriendship(CHARACTER_DOCTOR, 5);
    }
    SetEntityFacing(ENTITY_DOCTOR, FACING_UP);
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
}
