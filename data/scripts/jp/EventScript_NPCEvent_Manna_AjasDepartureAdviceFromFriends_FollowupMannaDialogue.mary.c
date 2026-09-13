#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_Manna_Followup_MannaAppreciatesHerFriends[] =
        "友達ってのは、\r\n"
        "ありがたいねぇ。{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_Manna_Followup_MannaHopesAjaReturnsHome[] =
        "これでアージュが\r\n"
        "帰って来てくれれば\r\n"
        "いいんだけど…{Press}";
};

void EventScript_NPCEvent_Manna_AjasDepartureAdviceFromFriends_FollowupMannaDialogue(void)
{
    if (HasMetNpc(CHARACTER_MANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    if (VarGet(VAR_MANNA_AJAS_DEPARTURE_ADVICE_FROM_FRIENDS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        if (WasNpcSpokenToJustNow(CHARACTER_MANNA) == FALSE)
        {
            SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessageSlow(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_Manna_Followup_MannaAppreciatesHerFriends);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessageSlow(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_Manna_Followup_MannaHopesAjaReturnsHome);
        }
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_MANNA);
        SetEntityFacing(ENTITY_MANNA, FACING_UP);
    }
}
