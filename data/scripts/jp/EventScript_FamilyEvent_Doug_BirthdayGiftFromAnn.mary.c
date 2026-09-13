#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Doug_BirthdayGiftFromAnn_DougAsksPlayerToReturnLaterWhileBusy[] =
        "おう、{Player}！\r\n"
        "悪いけど、今は忙しいんだ。\r\n"
        "用だったら後にしてくれ。{Press}";

    const char gText_FamilyEvent_Doug_BirthdayGiftFromAnn_AnnCallsForDoug[] =
        "父さん。\r\n"
        "{Press}";

    const char gText_FamilyEvent_Doug_BirthdayGiftFromAnn_DougAsksWhyAnnLeftStore[] =
        "なんだ、ラン。\r\n"
        "店のほうはどうした？{Press}";

    const char gText_FamilyEvent_Doug_BirthdayGiftFromAnn_AnnSaysSheHasPresentForDoug[] =
        "うん、ちょっと父さんに\r\n"
        "わたしたいものがあって…{Press}";

    const char gText_FamilyEvent_Doug_BirthdayGiftFromAnn_DougAsksAboutPresent[] =
        "あん？　なんだ？\r\n"
        "{Press}";

    const char gText_FamilyEvent_Doug_BirthdayGiftFromAnn_AnnGivesPresent[] =
        "はい、これ。\r\n"
        "{Press}";

    const char gText_FamilyEvent_Doug_BirthdayGiftFromAnn_DougAsksReasonForPresent[] =
        "どうしたんだ？　これ。\r\n"
        "{Press}";

    const char gText_FamilyEvent_Doug_BirthdayGiftFromAnn_AnnRemindsDougOfHisBirthday[] =
        "やっぱり、父さん忘れてる！\r\n"
        "自分の誕生日でしょ？\r\n"
        "しっかりしてよ、もう。{Press}";

    const char gText_FamilyEvent_Doug_BirthdayGiftFromAnn_DougRemembersBirthdayAndThanksAnn[] =
        "ああ！\r\n"
        "そうか、オレの誕生日か。\r\n"
        "ラン、ありがとう。{Press}";

    const char gText_FamilyEvent_Doug_BirthdayGiftFromAnn_AnnReturnsToStore[] =
        "うん。じゃ…\r\n"
        "じゃあ、お店に戻るね。{Press}";

    const char gText_FamilyEvent_Doug_BirthdayGiftFromAnn_DougThanksAnn[] =
        "ああ。\r\n"
        "{Press}";
};

void EventScript_FamilyEvent_Doug_BirthdayGiftFromAnn(void)
{
    EnableScriptedNpcControl();
    ChangeMap(MAP_INN_BACK_ROOM, X(68), Y(80));
    SetEntityPosition(ENTITY_PLAYER, X(103), Y(224), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_DOUG, X(48), Y(80), FACING_UP);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(80), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    MoveEntityXTo(ENTITY_PLAYER, X(68), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityFacing(ENTITY_DOUG, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_FamilyEvent_Doug_BirthdayGiftFromAnn_DougAsksPlayerToReturnLaterWhileBusy);
    TalkClose();
    SetEntityPosition(ENTITY_ANN, X(36), Y(224), FACING_UP);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(100), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityFacing(ENTITY_ANN, FACING_RIGHT);
    MoveEntityXTo(ENTITY_ANN, X(48), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityFacing(ENTITY_ANN, FACING_UP);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityFacing(ENTITY_DOUG, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Doug_BirthdayGiftFromAnn_AnnCallsForDoug);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_FamilyEvent_Doug_BirthdayGiftFromAnn_DougAsksWhyAnnLeftStore);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Doug_BirthdayGiftFromAnn_AnnSaysSheHasPresentForDoug);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_FamilyEvent_Doug_BirthdayGiftFromAnn_DougAsksAboutPresent);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Doug_BirthdayGiftFromAnn_AnnGivesPresent);
    TalkClose();
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_GESTURE);
    WaitFrames(30);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    StartEntityEffect(ENTITY_DOUG, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_FamilyEvent_Doug_BirthdayGiftFromAnn_DougAsksReasonForPresent);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Doug_BirthdayGiftFromAnn_AnnRemindsDougOfHisBirthday);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_FamilyEvent_Doug_BirthdayGiftFromAnn_DougRemembersBirthdayAndThanksAnn);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Doug_BirthdayGiftFromAnn_AnnReturnsToStore);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_FamilyEvent_Doug_BirthdayGiftFromAnn_DougThanksAnn);
    TalkClose();
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    SetEntityFacing(ENTITY_ANN, FACING_LEFT);
    MoveEntityXTo(ENTITY_ANN, X(36), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
    MoveEntityYTo(ENTITY_ANN, Y(224), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    HideEntity(ENTITY_ANN);
    MarkNpcSpokenTo(CHARACTER_DOUG);
    EnableScriptedNpcControl();
    VarSet(VAR_ANN_GIVES_DOUG_BIRTHDAY_PRESENT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_DOUG, EventScript_FamilyEvent_Doug_BirthdayGiftFromAnn_FollowupDougDialogue);
    return;
}
