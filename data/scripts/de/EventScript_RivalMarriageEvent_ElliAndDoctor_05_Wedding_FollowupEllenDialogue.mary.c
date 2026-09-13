#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupEllenDialogue_EllenPraisesElliAndUrgesHerToPrioritizeHerNewFamily[] =
        "Elli, du bist so eine\r\n"
        "hübsche Braut...!{Press}\p"
        "Du hast nur an mich \r\n"
        "und Stu gedacht, aber \r\n"
        "jetzt konzentriere dich{Press}\r\n"
        "auf deine neue Familie. {Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupEllenDialogue_EllenWantsToLiveToSeeStuMarry[] =
        "Ellis Hochzeit hat\r\n"
        "in mir den Wunsch zu\r\n"
        "leben geweckt, damit ich {Press}\r\n"
        "Stus Hochzeit sehen kann!{Press}";
};

void EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupEllenDialogue(void)
{
    if (HasMetNpc(CHARACTER_ELLEN) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ELLEN);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_ELLEN) == FALSE)
    {
        SetEntityFacing(ENTITY_ELLEN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ELLEN);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupEllenDialogue_EllenPraisesElliAndUrgesHerToPrioritizeHerNewFamily);
        TalkClose();
        SetEntityFacing(ENTITY_ELLEN, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_ELLEN);
    }
    else
    {
        SetEntityFacing(ENTITY_ELLEN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ELLEN);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupEllenDialogue_EllenWantsToLiveToSeeStuMarry);
        TalkClose();
        SetEntityFacing(ENTITY_ELLEN, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_ELLEN);
    }
}
