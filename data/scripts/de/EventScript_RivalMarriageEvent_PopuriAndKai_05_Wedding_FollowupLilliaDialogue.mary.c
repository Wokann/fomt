#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue_LilliaLocalizationErrorClaimsMarriageToKai[] =
// Lillia is reflecting on her daughter's wedding, not marrying Kai herself.
#ifdef BUGFIX
        "Popuri als Braut...\r\n"
        "Irgendwie seltsam.{Press}";
#else
        "Alle meine Freunde sind\r\n"
        "hier, um meine Hochzeit\r\n"
        "mit Kai zu feiern. {Press}";
#endif

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue_LilliaWishesRodWereHomeForWedding[] =
        "Ich wünschte, mein\r\n"
        "Vater wäre hier...{Press}";
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
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue_LilliaLocalizationErrorClaimsMarriageToKai);
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
