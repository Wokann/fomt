#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupMaryDialogue_MaryDescribesGrayAsBluntAndHonestUnlikeAnyoneSheKnew[] =
        "Ich habe noch nie \r\n"
        "jemanden wie Gray getroffen.\r\n"
        "Er ist so unverblümt {Press}\r\n"
        "und ehrlich, aber auf{Press}\r\n"
        "ein gute Art... {Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupMaryDialogue_MaryValuesGraysGentlenessAndWasHappyHeProposed[] =
        "Und er ist so sanft. {Press}\p"
        "Ich war so froh, als er um\r\n"
        "meine Hand gebeten hat! {Press}";
};

void EventScript_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupMaryDialogue(void)
{
    if (HasMetNpc(CHARACTER_MARY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MARY);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_MARY) == FALSE)
    {
        SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MARY_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_MARY);
        TalkMessage(gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupMaryDialogue_MaryDescribesGrayAsBluntAndHonestUnlikeAnyoneSheKnew);
        TalkClose();
        SetEntityFacing(ENTITY_MARY, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_MARY);
    }
    else
    {
        SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MARY_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_MARY);
        TalkMessage(gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupMaryDialogue_MaryValuesGraysGentlenessAndWasHappyHeProposed);
        TalkClose();
        SetEntityFacing(ENTITY_MARY, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_MARY);
    }
}
