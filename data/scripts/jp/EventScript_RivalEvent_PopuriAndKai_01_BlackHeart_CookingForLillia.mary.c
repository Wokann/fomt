#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_PopuriPraisesKaisCookingAndForeignFood[] =
        "はぁ～、おいしかった。{Press}\p"
        "カイの店にある食べものって、\r\n"
        "この町に無いものばっかりだよ\r\n"
        "ね。{Press}";

    const char gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_PopuriAsksHowKaiKnowsOtherTowns[] =
        "なんで、そんなに色んな町にく\r\n"
        "わしいの？{Press}";

    const char gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_KaiExplainsWinterTravelAndForeignCuisine[] =
        "オレ、寒いの苦手なんだよ。\r\n"
        "町が寒くなったら、暖かい季節\r\n"
        "になってる町に行くんだ。{Press}\p"
        "だから、色んな町に行ってるっ\r\n"
        "てわけ。{Press}\p"
        "まだまだ、他の町にはいろいろ\r\n"
        "な食べものがあるんだぜ。{Press}";

    const char gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_PopuriIsImpressedByKaisTravels[] =
        "へ～、そうなんだ…{Press}";

    const char gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_PopuriWondersWhetherKaisCookingCouldHelpLillia[] =
        "カイの料理、お母さんに食べさ\r\n"
        "せたら元気でるかなぁ？{Press}";

    const char gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_CookingForLillia[] =
        "今度、作りにいってやろうか？{Press}";

    const char gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_PopuriAsksIfKaiReallyWillCookForLillia[] =
        "本当？{Press}";

    const char gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_KaiPromisesToCookForLillia[] =
        "ああ、まかせとけって。{Press}";

    const char gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_PopuriThanksKai[] =
        "ありがとう、カイ！{Press}";
};

void EventScript_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia(void)
{
    ChangeMap(MAP_MINERAL_BEACH, X(160), Y(120));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(24), Y(280), FACING_RIGHT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_POPURI, X(152), Y(120), FACING_RIGHT);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityPosition(ENTITY_KAI, X(168), Y(120), FACING_LEFT);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_PopuriPraisesKaisCookingAndForeignFood);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_PopuriAsksHowKaiKnowsOtherTowns);
    TalkClose();
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_KaiExplainsWinterTravelAndForeignCuisine);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_PopuriIsImpressedByKaisTravels);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_PopuriWondersWhetherKaisCookingCouldHelpLillia);
    TalkClose();
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_CookingForLillia);
    TalkClose();
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_PopuriAsksIfKaiReallyWillCookForLillia);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_KaiPromisesToCookForLillia);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_PopuriThanksKai);
    TalkClose();
    PanCameraTo(X(24), Y(280), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_POPURI, EventScript_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_FollowupPopuriDialogue);
    SetEntityEventScript(ENTITY_KAI, EventScript_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_FollowupKaiDialogue);
    VarSet(VAR_POPURI_KAI_RIVAL_EVENT_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    return;
}
