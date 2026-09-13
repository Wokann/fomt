#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_Anna_Followup_AnnaUnderstandsAjasDifficultAge[] =
        "Your daughter is at a \r\n"
        "difficult age too, right?{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_Anna_Followup_AnnaUnderstandsMannasLongingAsAMother[] =
        "With a daughter myself, \r\n"
        "I know how much you long\r\n"
        "for her to come back. {Press}";
};

void EventScript_NPCEvent_Manna_AjasDepartureAdviceFromFriends_FollowupAnnaDialogue(void)
{
    if (HasMetNpc(CHARACTER_ANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ANNA);
    }
    if (VarGet(VAR_MANNA_AJAS_DEPARTURE_ADVICE_FROM_FRIENDS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_ANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        if (WasNpcSpokenToJustNow(CHARACTER_ANNA) == FALSE)
        {
            SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_Anna_Followup_AnnaUnderstandsAjasDifficultAge);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_ANNA_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_Anna_Followup_AnnaUnderstandsMannasLongingAsAMother);
        }
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_ANNA);
        SetEntityFacing(ENTITY_ANNA, FACING_LEFT);
    }
}
