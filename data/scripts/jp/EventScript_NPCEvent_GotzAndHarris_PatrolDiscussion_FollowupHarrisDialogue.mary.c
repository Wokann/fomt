#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupHarrisDialogue_HarrisExplainsGotzPatrolsAfterFamilyDeaths[] =
        "ゴッツさんは、\r\n"
        "山で奥さんと娘さんが\r\n"
        "亡くなられてね。{Press}\p"
        "それ以来、仕事の合間をぬって\r\n"
        "山のパトロールをしてくれて\r\n"
        "いるんだよ。{Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupHarrisDialogue_HarrisExpressesGratitudeToGotz[] =
        "ゴッツさんには、\r\n"
        "本当に感謝しているんだよ。{Press}";
};

void EventScript_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupHarrisDialogue(void)
{
    SetEntityFacing(ENTITY_HARRIS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_HARRIS);
    if (WasNpcSpokenToJustNow(CHARACTER_HARRIS) == FALSE)
    {
        SetTalkPortrait(TALK_PORTRAIT_HARRIS_AFRAID);
        TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupHarrisDialogue_HarrisExplainsGotzPatrolsAfterFamilyDeaths);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_HARRIS_NORMAL);
        TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupHarrisDialogue_HarrisExpressesGratitudeToGotz);
    }
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_HARRIS);
    SetEntityFacing(ENTITY_HARRIS, FACING_RIGHT);
    return;
}
