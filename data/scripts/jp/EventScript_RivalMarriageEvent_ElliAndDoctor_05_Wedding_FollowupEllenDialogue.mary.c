#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupEllenDialogue_EllenPraisesElliAndUrgesHerToPrioritizeHerNewFamily[] =
        "エリィ…本当にきれい…{Press}\r\n"
        "エリィは、今までわたしと\r\n"
        "ユウの事ばかり考えていた\r\n"
        "ようだけど…{Press}\p"
        "これからは、\r\n"
        "自分とドクターの事、\r\n"
        "大事にしてほしいわ。{Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupEllenDialogue_EllenWantsToLiveToSeeStuMarry[] =
        "エリィの結婚式を見ていたら\r\n"
        "よくが出てきて、{Press}\p"
        "ユウが結婚するまで\r\n"
        "生きていたくなったわ。{Press}";
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
