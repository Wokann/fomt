#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupMaryDialogue_MaryDescribesGrayAsBluntAndHonestUnlikeAnyoneSheKnew[] =
        "グレイって始めて見る\r\n"
        "タイプだったわ。{Press}\p"
        "パパともぜんぜんちがうし、\r\n"
        "自分の思ったことはすぐに\r\n"
        "口に出すし。{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupMaryDialogue_MaryValuesGraysGentlenessAndWasHappyHeProposed[] =
        "とっても人間らしい人だと\r\n"
        "思ってたの。{Press}\p"
        "プロポーズしてもらえて\r\n"
        "うれしかった。{Press}";
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
