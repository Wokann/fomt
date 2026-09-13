#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupPopuriDialogue_PopuriCallsWeddingHappiestDayOfHerLife[] =
        "This is the happiest \r\n"
        "day of my life! {Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupPopuriDialogue_PopuriCelebratesWithHerLovedOnes[] =
        "Everybody I love is here to\r\n"
        "celebrate my marriage\r\n"
        "with Kai. {Press}";
};

void EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupPopuriDialogue(void)
{
    if (HasMetNpc(CHARACTER_POPURI) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_POPURI);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
    {
        SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupPopuriDialogue_PopuriCallsWeddingHappiestDayOfHerLife);
        TalkClose();
        SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_POPURI);
    }
    else
    {
        SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupPopuriDialogue_PopuriCelebratesWithHerLovedOnes);
        TalkClose();
        SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_POPURI);
    }
}
