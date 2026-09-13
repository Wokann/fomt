#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Won_Introduction_WonGreetsPlayer[] =
        "おはようある。\r\n"
        "{Press}";

    const char gText_NPCEvent_Won_Introduction_WonIntroducesHimselfAsTravelingSalesman[] =
        "申しおくれたね。\r\n"
        "わたし、行商して歩いてる\r\n"
        "ホアンいうある。{Press}\p"
        "今日、この町についたね。\r\n"
        "よろしくあるよ。{Press}";

    const char gText_NPCEvent_Won_Introduction_WonAdvertisesRareSeedsAtZacksHouse[] =
        "みたとこ牧場やってるね？{Press}\p"
        "わたし、めずらし種とか、\r\n"
        "いっぱいいっぱい持ってるね。\r\n"
        "買いにくるよろし。{Press}\p"
        "わたし、ザクさんとこに泊めて\r\n"
        "もらってるある。\r\n"
        "いつでも来るよろし。{Press}\p"
        "歓迎するあるよ。{Press}";

    const char gText_NPCEvent_Won_Introduction_WonLeavesToContinueSalesRounds[] =
        "それじゃ、\r\n"
        "他にもアイサツまわりするから\r\n"
        "帰るね。{Press}";
};

void EventScript_NPCEvent_Won_Introduction(void)
{
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_WON, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_WON, ANIMATION_WON_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Won_Introduction_WonGreetsPlayer);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Won_Introduction_WonIntroducesHimselfAsTravelingSalesman);
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Won_Introduction_WonAdvertisesRareSeedsAtZacksHouse);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Won_Introduction_WonLeavesToContinueSalesRounds);
    TalkClose();
    SetEntityFacing(ENTITY_WON, FACING_RIGHT);
    SetEntityAnim(ENTITY_WON, ANIMATION_WON_WALK);
    MoveEntityXTo(ENTITY_WON, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_WON);
    SetEntityFacing(ENTITY_WON, FACING_UP);
    MoveEntityYTo(ENTITY_WON, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_WON);
    HideEntity(ENTITY_WON);
    MarkNpcSpokenTo(CHARACTER_WON);
    VarSet(VAR_WON_INTRODUCTION_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
