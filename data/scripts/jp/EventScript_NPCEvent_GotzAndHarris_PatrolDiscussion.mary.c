#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzAsksAboutHarrisPatrol[] =
        "パトロール、ごくろうさん。\r\n"
        "{Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisReportsTownIsSafe[] =
        "ありがとうございます。\r\n"
        "この町は今日も平和ですよ。{Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzReportsMountainIsSafe[] =
        "それはよかったぜ。\r\n"
        "山の方も異常なかったぜ。{Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisThanksGotzForPatrollingMountain[] =
        "いつも、すいません。本来なら\r\n"
        "山の方もボクがパトロールする\r\n"
        "べきなんですが、{Press}\p"
        "ゴッツさんにやってもらって…{Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzExplainsHeKnowsMountainAndVolunteered[] =
        "いいって、気にするな。\r\n"
        "山は、おまえよりオレが\r\n"
        "くわしいからな。{Press}\p"
        "それに、これはオレが\r\n"
        "言い出したことなんだからな。{Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisMentionsDeathOfGotzWifeAndDaughter[] =
        "……………{Press}\p"
        "奥さんと娘さんが山で\r\n"
        "亡くなって、\r\n"
        "ずいぶん経ちましたね。{Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzExplainsPatrolHonorsHisFamily[] =
        "ああ。{Press}\p"
        "あいつらも、２度と自分たちの\r\n"
        "ような人を出したくないだろう\r\n"
        "しな。{Press}\p"
        "あいつらもオレが\r\n"
        "山のパトロールをすることに\r\n"
        "賛成してくれると思うんだよ。{Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisAgreesTheyCanRestPeacefully[] =
        "そうですね。\r\n"
        "ボクもそう思います。{Press}";
};

void EventScript_NPCEvent_GotzAndHarris_PatrolDiscussion(void)
{
    EnableScriptedNpcControl();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_GOTZ, X(120), Y(80), FACING_LEFT);
    SetEntityAnim(ENTITY_GOTZ, ANIMATION_GOTZ_IDLE);
    SetEntityPosition(ENTITY_HARRIS, X(100), Y(80), FACING_RIGHT);
    SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(120), Y(100), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(100), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GOTZ_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GOTZ);
    TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzAsksAboutHarrisPatrol);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARRIS_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_HARRIS);
    TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisReportsTownIsSafe);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GOTZ_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GOTZ);
    TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzReportsMountainIsSafe);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARRIS_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_HARRIS);
    TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisThanksGotzForPatrollingMountain);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GOTZ_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GOTZ);
    TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzExplainsHeKnowsMountainAndVolunteered);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARRIS_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_HARRIS);
    TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisMentionsDeathOfGotzWifeAndDaughter);
    TalkClose();
    StartEntityEffect(ENTITY_GOTZ, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GOTZ_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GOTZ);
    TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_GotzExplainsPatrolHonorsHisFamily);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARRIS_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_HARRIS);
    TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_HarrisAgreesTheyCanRestPeacefully);
    TalkClose();
    EnableScriptedNpcControl();
    VarSet(VAR_GOTZ_AND_HARRIS_PATROL_DISCUSSION_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_GOTZ, EventScript_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupGotzDialogue);
    SetEntityEventScript(ENTITY_HARRIS, EventScript_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupHarrisDialogue);
    return;
}
