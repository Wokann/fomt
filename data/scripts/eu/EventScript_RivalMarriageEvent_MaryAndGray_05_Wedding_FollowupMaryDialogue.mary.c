#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupMaryDialogue_MaryDescribesGrayAsBluntAndHonestUnlikeAnyoneSheKnew[] =
        "I'd never met anybody like \r\n"
        "Gray before. He's so blunt \r\n"
        "and honest, but in a good{Press}\r\n"
        "way... {Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupMaryDialogue_MaryValuesGraysGentlenessAndWasHappyHeProposed[] =
        "Inside he's so gentle, \r\n"
        "though. {Press}\p"
        "I was so glad when he \r\n"
        "proposed to me! {Press}";
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
