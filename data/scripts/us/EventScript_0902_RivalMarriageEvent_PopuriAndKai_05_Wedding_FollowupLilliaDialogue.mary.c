#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue_LilliaReflectsOnPopurisWedding[] =
// Lillia is reflecting on her daughter's wedding, not marrying Kai herself.
#ifdef BUGFIX
        "To think Popuri's a bride...\r\n"
        "Somehow, it feels strange.{Press}";
#else
        "Everybody I love is here to\r\n"
        "celebrate my marriage\r\n"
        "with Kai. {Press}";
#endif

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue_LilliaWishesRodWereHomeForWedding[] =
        "I just wish dad would \r\n"
        "come home for this...{Press}";
};

void EventScript_0902_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue(void)
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
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue_LilliaReflectsOnPopurisWedding);
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
