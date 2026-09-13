#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue_MannaSaysCliffSettlingDownMeansHeCannotMarryAja[] =
        "クリフ、ずっとこの町に\r\n"
        "いる事になったのよ。\r\n"
        "うちのむすめとの結婚は、\r\n"
        "あきらめなきゃいけなく\r\n"
        "なったけど。{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue_MannaRegardsCliffAndAnnAsHerChildren[] =
        "そんな事しなくたって、\r\n"
        "クリフはうちの子どもよね。\r\n"
        "だから、ランちゃんも\r\n"
        "わたしの子どもなのよ。{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue_MannaStillHopesAjaReturnsHome[] =
        "でも、やっぱりアージュにも、\r\n"
        "はやくこの町に帰ってきて\r\n"
        "もらいたいわ。\r\n"
        "すぐにあきて帰ってくると\r\n"
        "思っていたのに…{Press}";
};

void EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue(void)
{
    if (HasMetNpc(CHARACTER_MANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_MANNA) == FALSE)
    {
        SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_MANNA);
        TalkMessageSlow(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue_MannaSaysCliffSettlingDownMeansHeCannotMarryAja);
        SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_MANNA);
        TalkMessageSlow(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue_MannaRegardsCliffAndAnnAsHerChildren);
        TalkClose();
        SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    else
    {
        SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_MANNA);
        TalkMessageSlow(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue_MannaStillHopesAjaReturnsHome);
        TalkClose();
        SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
}
