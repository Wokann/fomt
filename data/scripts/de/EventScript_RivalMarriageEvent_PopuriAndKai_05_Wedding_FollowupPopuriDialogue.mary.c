#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupPopuriDialogue_PopuriCallsWeddingHappiestDayOfHerLife[] =
        "Dies ist der schönste Tag \r\n"
        "meines Lebens! {Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupPopuriDialogue_PopuriCelebratesWithHerLovedOnes[] =
        "Alle meine Freunde sind\r\n"
        "hier, um meine Hochzeit\r\n"
        "mit Kai zu feiern. {Press}";
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
