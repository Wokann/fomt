#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_FollowupLilliaDialogue_LilliaValuesHavingHusbandByHerSide[] =
        "ダンナさんが、\r\n"
        "いつもそばにいるって\r\n"
        "いいわねぇ～。{Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_FollowupLilliaDialogue_LilliaSaysSashaAndJeffMakeAGoodCouple[] =
        "サーシャとジェフって、\r\n"
        "本当にお似合いの夫婦だと\r\n"
        "思うわ～。{Press}";
};

void EventScript_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_FollowupLilliaDialogue(void)
{
    if (VarGet(VAR_LILLIA_AND_SASHA_REMINISCE_ABOUT_JEFFS_MARRIAGE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_LILLIA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        if (WasNpcSpokenToJustNow(CHARACTER_LILLIA) == FALSE)
        {
            SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_LILLIA);
            TalkMessage(gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_FollowupLilliaDialogue_LilliaValuesHavingHusbandByHerSide);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_LILLIA);
            TalkMessage(gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_FollowupLilliaDialogue_LilliaSaysSashaAndJeffMakeAGoodCouple);
        }
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_LILLIA);
        SetEntityFacing(ENTITY_LILLIA, FACING_LEFT);
    }
}
