#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Manna_FlattersJeff_JeffGreetsPlayerAtCounter[] =
        "いらっしゃい。\r\n"
        "{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaGreetsPlayer[] =
        "あら、\r\n"
        "{Player}さんじゃない。{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaExplainsShoppingAndDinnerErrand[] =
        "{Player}さんも、\r\n"
        "お買い物？\r\n"
        "わたし？\r\n"
        "わたしはサーシャとおしゃべり\r\n"
        "しにきたついでに\r\n"
        "お買い物しようと思ってね。\r\n"
        "{Player}さんは何を買いに\r\n"
        "きたの？\r\n"
        "そう、決めてないの。\r\n"
        "わたしは晩ご飯につかうものを\r\n"
        "買いにきたのよ。{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaOrdersRiceBallAndCurryPowder[] =
        "じゃあ、おにぎりとカレー粉\r\n"
        "もらおうかしら？{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_JeffAsksMannaToWaitForHerOrder[] =
        "おにぎりとカレー粉ね。\r\n"
        "{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaComplimentsJeffsAppearance[] =
        "あら、ジェフさん。\r\n"
        "このごろ、カッコよくなったん\r\n"
        "じゃないの？{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_JeffReactsInSurprise[] =
        "えっ？\r\n"
        "{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaInsistsJeffLooksFit[] =
        "そうよ、絶対そう！\r\n"
        "ちょっと見ない間に、りりしく\r\n"
        "なったっていうか…\r\n"
        "男らしくなったっていうか…{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_JeffAcceptsCompliment[] =
        "いやー、そうかなぁ…\r\n"
        "{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaFlirtsAndAsksPrice[] =
        "わたしもホレてしまいそうよ。\r\n"
        "それで、おいくらだった\r\n"
        "かしら？{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_JeffOffersHalfPrice[] =
        "え、えーと…\r\n"
        "マナさんだったら半額で\r\n"
        "いいよ。{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaThanksJeffAndComparesDuke[] =
        "ほんと？\r\n"
        "さすが、ジェフさん。太っ腹\r\n"
        "よねぇ。うちのダンナにも\r\n"
        "見習わせたいわ。{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_JeffIsFlatteredByMannasPraise[] =
        "いやー、テレちゃうな。\r\n"
        "\r\n"
        "{Press}";

    const char gText_NPCEvent_Manna_FlattersJeff_MannaRevealsFlatteryDiscountStrategy[] =
        "ここで買い物するときは、\r\n"
        "こうするのよ。\r\n"
        "ジェフさんはオダテに弱い\r\n"
        "から、安くで買えるのよ。{Press}";
};

void EventScript_NPCEvent_Manna_FlattersJeff(void)
{
    EnableScriptedNpcControl();
    ChangeMap(MAP_SUPERMARKET, X(228), Y(152));
    SetEntityPosition(ENTITY_PLAYER, X(228), Y(152), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_JEFF, X(228), Y(112), FACING_DOWN);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Manna_FlattersJeff_JeffGreetsPlayerAtCounter);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(30);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_MANNA, X(144), Y(288), FACING_UP);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_WALK);
    MoveEntityYTo(ENTITY_MANNA, Y(208), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MANNA);
    SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
    MoveEntityXTo(ENTITY_MANNA, X(208), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MANNA);
    SetEntityFacing(ENTITY_MANNA, FACING_UP);
    MoveEntityYTo(ENTITY_MANNA, Y(152), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MANNA);
    SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_FlattersJeff_MannaGreetsPlayer);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_FlattersJeff_MannaExplainsShoppingAndDinnerErrand);
    TalkClose();
    SetEntityFacing(ENTITY_MANNA, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_FlattersJeff_MannaOrdersRiceBallAndCurryPowder);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Manna_FlattersJeff_JeffAsksMannaToWaitForHerOrder);
    TalkClose();
    StartEntityEffect(ENTITY_MANNA, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_FlattersJeff_MannaComplimentsJeffsAppearance);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Manna_FlattersJeff_JeffReactsInSurprise);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_FlattersJeff_MannaInsistsJeffLooksFit);
    TalkClose();
    StartEntityEffect(ENTITY_JEFF, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Manna_FlattersJeff_JeffAcceptsCompliment);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_FlattersJeff_MannaFlirtsAndAsksPrice);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Manna_FlattersJeff_JeffOffersHalfPrice);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_FlattersJeff_MannaThanksJeffAndComparesDuke);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_NPCEvent_Manna_FlattersJeff_JeffIsFlatteredByMannasPraise);
    TalkClose();
    SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_FlattersJeff_MannaRevealsFlatteryDiscountStrategy);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    MarkNpcSpokenTo(CHARACTER_MANNA);
    EnableScriptedNpcControl();
    VarSet(VAR_MANNA_FLATTERS_JEFF_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_MANNA, EventScript_NPCEvent_Manna_FlattersJeff_FollowupMannaDialogue);
    SetEntityEventScript(ENTITY_JEFF, EventScript_NPCEvent_Manna_FlattersJeff_FollowupJeffDialogue);
    return;
}
