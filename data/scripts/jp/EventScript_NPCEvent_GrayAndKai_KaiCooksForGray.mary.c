#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_GraySaysHeIsHungry[] =
        "じゃ、さっそく\r\n"
        "食わせてくれよ。{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiOffersDishForTasting[] =
        "これとこれを\r\n"
        "食べてみてくれる？{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayPraisesDish[] =
        "結構うまいな。{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiAsksForConfirmation[] =
        "だろ？{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiWelcomesPlayer[] =
        "おっ、{Player}じゃん。\r\n"
        "いらっしゃい。{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayGreetsPlayer[] =
        "よう。{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayExplainsKaiInvitedHim[] =
        "オレがカイの店にいるのが\r\n"
        "めずらしいって？{Press}\p"
        "カイに、一度食べにきてくれ\r\n"
        "って言われたんだよ。{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiValuesGraysCityFoodExperience[] =
        "そうそう、街の味を知ってて\r\n"
        "仲がいいのって\r\n"
        "グレイぐらいだからな。{Press}\p"
        "色々、味見してもらったって\r\n"
        "わけだよ。{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayPraisesKaisCookingSkill[] =
        "カイのやつ、\r\n"
        "店を出すだけあって\r\n"
        "中々うまいんだよ。{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiGainsConfidenceFromGraysPraise[] =
        "サンキュー。\r\n"
        "そう言ってもらうと\r\n"
        "作ったかいがあったぜ。{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayReturnsToForgeWork[] =
        "じいさんもうるさいし、\r\n"
        "そろそろ仕事にもどるよ。{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiThanksGrayForVisiting[] =
        "ああ、いそがしいとこ\r\n"
        "悪かったな。{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_GraySaysGoodbyeToKai[] =
        "じゃあな。{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_GraySaysGoodbyeToPlayer[] =
        "{Player}もまたな。{Press}";

    const char gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiPraisesGrayToPlayer[] =
        "グレイはいいやつだよ。\r\n"
        "なんか気があっちゃってさ。{Press}";
};

void EventScript_NPCEvent_GrayAndKai_KaiCooksForGray(void)
{
    ChangeMap(MAP_KAI_RESTAURANT, X(120), Y(124));
    SetEntityPosition(ENTITY_KAI, X(110), Y(91), FACING_DOWN);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    SetEntityPosition(ENTITY_GRAY, X(122), Y(240), FACING_UP);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(250), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_WALK);
    MoveEntityYTo(ENTITY_GRAY, Y(161), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GRAY);
    SetEntityFacing(ENTITY_GRAY, FACING_RIGHT);
    MoveEntityXTo(ENTITY_GRAY, X(140), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GRAY);
    SetEntityFacing(ENTITY_GRAY, FACING_UP);
    MoveEntityYTo(ENTITY_GRAY, Y(91), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GRAY);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    SetEntityFacing(ENTITY_GRAY, FACING_LEFT);
    SetEntityFacing(ENTITY_KAI, FACING_RIGHT);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_GraySaysHeIsHungry);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiOffersDishForTasting);
    TalkClose();
    WaitFrames(60);
    StartEntityEffect(ENTITY_GRAY, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayPraisesDish);
    TalkClose();
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiAsksForConfirmation);
    TalkClose();
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(124), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    SetEntityFacing(ENTITY_KAI, FACING_DOWN);
    SetEntityFacing(ENTITY_GRAY, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiWelcomesPlayer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayGreetsPlayer);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayExplainsKaiInvitedHim);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiValuesGraysCityFoodExperience);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayPraisesKaisCookingSkill);
    TalkClose();
    SetEntityFacing(ENTITY_KAI, FACING_RIGHT);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiGainsConfidenceFromGraysPraise);
    TalkClose();
    SetEntityFacing(ENTITY_GRAY, FACING_LEFT);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_GrayReturnsToForgeWork);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiThanksGrayForVisiting);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_GraySaysGoodbyeToKai);
    TalkClose();
    SetEntityFacing(ENTITY_GRAY, FACING_DOWN);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_GraySaysGoodbyeToPlayer);
    TalkClose();
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_WALK);
    SetEntityFacing(ENTITY_GRAY, FACING_RIGHT);
    MoveEntityXTo(ENTITY_GRAY, X(142), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GRAY);
    SetEntityFacing(ENTITY_KAI, FACING_DOWN);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityFacing(ENTITY_GRAY, FACING_DOWN);
    MoveEntityYTo(ENTITY_GRAY, Y(156), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GRAY);
    SetEntityFacing(ENTITY_GRAY, FACING_LEFT);
    MoveEntityXTo(ENTITY_GRAY, X(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GRAY);
    SetEntityFacing(ENTITY_GRAY, FACING_DOWN);
    MoveEntityYTo(ENTITY_GRAY, Y(230), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_GRAY);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    HideEntity(ENTITY_GRAY);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_GrayAndKai_KaiCooksForGray_KaiPraisesGrayToPlayer);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_KAI);
    MarkNpcSpokenTo(CHARACTER_GRAY);
    EnableScriptedNpcControl();
    VarSet(VAR_GRAY_AND_KAI_FRIENDSHIP_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_KAI, EventScript_NPCEvent_GrayAndKai_KaiCooksForGray_FollowupKaiDialogue);
}
