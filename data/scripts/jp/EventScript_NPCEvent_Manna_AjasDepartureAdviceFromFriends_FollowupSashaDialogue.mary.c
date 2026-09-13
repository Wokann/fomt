#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_Sasha_Followup_AjaLeftAfterArgumentWithDuke[] =
        "アージュはデュークともめて、\r\n"
        "家を飛び出したんだよ。{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_Sasha_Followup_SashaPlansToCallAja[] =
        "さて、アージュに電話でも\r\n"
        "しておこうか。{Press}";
};

void EventScript_NPCEvent_Manna_AjasDepartureAdviceFromFriends_FollowupSashaDialogue(void)
{
    if (HasMetNpc(CHARACTER_SASHA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    if (VarGet(VAR_MANNA_AJAS_DEPARTURE_ADVICE_FROM_FRIENDS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        if (WasNpcSpokenToJustNow(CHARACTER_SASHA) == FALSE)
        {
            SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_SASHA);
            TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_Sasha_Followup_AjaLeftAfterArgumentWithDuke);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_SASHA);
            TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_Sasha_Followup_SashaPlansToCallAja);
        }
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_SASHA);
        SetEntityFacing(ENTITY_SASHA, FACING_DOWN);
    }
}
