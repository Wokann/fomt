#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Karen_ComfortsLonelyRick_RickBroodsAboutFamily[] =
        "はぁ…\r\n"
        "{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_KarenAsksWhyRickIsDown[] =
        "リック、どうしたの？\r\n"
        "ため息なんかついちゃって。{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_RickWondersWhenRodWillReturn[] =
        "うん…\r\n"
        "父さんがいつ\r\n"
        "帰ってくるかなぁって。{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_KarenNotesRodsConstantTravel[] =
        "おじさん？{Press}\p"
        "そうよね、昔からおじさんは\r\n"
        "旅ばかり出てたよね。{Press}\p"
        "わたしも何回かしか見たこと\r\n"
        "ないわ。{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_RickFeelsAloneAfterPopurisMarriage[] =
        "ポプリもお嫁に\r\n"
        "いっちゃったし…\r\n"
        "店の将来が心配だよ…{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_KarenPromisesToHelpAtStore[] =
        "大丈夫！{Press}\p"
        "リック、わたしを忘れてない？\r\n"
        "お母さんやポプリちゃんの分ま\r\n"
        "でわたしが働いてあげるわよ！{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_RickThanksKarenForHerSupport[] =
        "カレン…\r\n"
        "ありがとう。{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_KarenSaysSpousesSupportEachOther[] =
        "やめてよ。お礼なんて…\r\n"
        "夫婦なんだから当たり前\r\n"
        "じゃない。{Press}";
};

void EventScript_NPCEvent_Karen_ComfortsLonelyRick(void)
{
    EnableScriptedNpcControl();
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_KAREN, X(120), Y(80), FACING_RIGHT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_RICK, X(144), Y(80), FACING_LEFT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(120), Y(112), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    MoveEntityYTo(ENTITY_PLAYER, Y(144), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitForCameraMovement();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_NPCEvent_Karen_ComfortsLonelyRick_RickBroodsAboutFamily);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_NPCEvent_Karen_ComfortsLonelyRick_KarenAsksWhyRickIsDown);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_NPCEvent_Karen_ComfortsLonelyRick_RickWondersWhenRodWillReturn);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_NPCEvent_Karen_ComfortsLonelyRick_KarenNotesRodsConstantTravel);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_NPCEvent_Karen_ComfortsLonelyRick_RickFeelsAloneAfterPopurisMarriage);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_NPCEvent_Karen_ComfortsLonelyRick_KarenPromisesToHelpAtStore);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_NPCEvent_Karen_ComfortsLonelyRick_RickThanksKarenForHerSupport);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_NPCEvent_Karen_ComfortsLonelyRick_KarenSaysSpousesSupportEachOther);
    TalkClose();
    PanCameraTo(X(120), Y(144), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    VarSet(VAR_KAREN_COMFORTS_LONELY_RICK_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_RICK, EventScript_NPCEvent_RickAndKaren_MarriedDialogueInteractWithRick);
    SetEntityEventScript(ENTITY_KAREN, EventScript_NPCEvent_RickAndKaren_MarriedDialogueInteractWithKaren);
    return;
}
