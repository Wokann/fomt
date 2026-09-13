#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue_LilliaReflectsOnPopuriBecomingABride[] =
        "ポプリが花よめさんだなんて…\r\n"
        "なんだか、へんな感じ～。{Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue_LilliaWishesRodWereHomeForWedding[] =
        "あーあ、\r\n"
        "パパはやく帰ってこないか\r\n"
        "なぁ。{Press}";
};

void EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue(void)
{
    if (HasMetNpc(CHARACTER_LILLIA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_LILLIA);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_LILLIA) == FALSE)
    {
        SetEntityFacing(ENTITY_LILLIA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_LILLIA);
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue_LilliaReflectsOnPopuriBecomingABride);
        TalkClose();
        SetEntityFacing(ENTITY_LILLIA, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_LILLIA);
    }
    else
    {
        SetEntityFacing(ENTITY_LILLIA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_LILLIA_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_LILLIA);
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue_LilliaWishesRodWereHomeForWedding);
        TalkClose();
        SetEntityFacing(ENTITY_LILLIA, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_LILLIA);
    }
}
