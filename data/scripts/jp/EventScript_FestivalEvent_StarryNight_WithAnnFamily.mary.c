#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_StarryNight_WithAnnFamily_ThanksForComingWeWereJust[] =
        "やぁ、来たんだね。\r\n"
        "これからパーティをはじめよう\r\n"
        "としてたんだ。{Press}";

    const char gText_FestivalEvent_StarryNight_WithAnnFamily_YouCanComeOverAnyTime[] =
        "今日だけ何て言わず、\r\n"
        "いつでも遊びに来るといいぜ。\r\n"
        "なんなら、ランと結婚…{Press}";

    const char gText_FestivalEvent_StarryNight_WithAnnFamily_DadIfYouKeepTalkingLike[] =
        "また病気がはじまった。{Press}\p"
        "そんなこと言ったら、\r\n"
        "もう{Player}くんが\r\n"
        "来てくれなくなっちゃうよ！{Press}";

    const char gText_FestivalEvent_StarryNight_WithAnnFamily_SpendingStarryNightFestivalWithAnns[] =
        "ランの家族とすごした\r\n"
        "星夜祭…\r\n"
        "とても楽しかった。{Press}";
};

void EventScript_FestivalEvent_StarryNight_WithAnnFamily(void)
{
    ChangeMap(MAP_INN_1F, X(140), Y(272));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
    CreateEventIcon(EVENT_ICON_SLOT_0, X(104), Y(240), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_APPLE_PIE));
    CreateEventIcon(EVENT_ICON_SLOT_1, X(120), Y(240), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_GRAPE_JUICE));
    SetEntityPosition(ENTITY_PLAYER, X(184), Y(320), FACING_UP);
    SetEntityPosition(ENTITY_ANN, X(96), Y(272), FACING_UP);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(96), Y(224), FACING_DOWN);
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
    MoveEntityYTo(ENTITY_PLAYER, Y(272), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    SetEntityFacing(ENTITY_ANN, FACING_RIGHT);
    SetEntityFacing(ENTITY_DOUG, FACING_RIGHT);
    WaitFrames(10);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FestivalEvent_StarryNight_WithAnnFamily_ThanksForComingWeWereJust);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
    TalkMessage(gText_FestivalEvent_StarryNight_WithAnnFamily_YouCanComeOverAnyTime);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_BLUSHING);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FestivalEvent_StarryNight_WithAnnFamily_DadIfYouKeepTalkingLike);
    TalkClose();
    AddCharacterLove(CHARACTER_ANN, 2000);
    AddNpcFriendship(CHARACTER_ANN, 30);
    AddNpcFriendship(CHARACTER_DOUG, 30);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_FestivalEvent_StarryNight_WithAnnFamily_SpendingStarryNightFestivalWithAnns);
    TalkClose();
    RemoveEventIcon(EVENT_ICON_SLOT_0);
    RemoveEventIcon(EVENT_ICON_SLOT_1);
    VarSet(VAR_STARRY_NIGHT_ANN_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    VarSet(VAR_FESTIVAL_STARRY_NIGHT_HOST_INDEX, STARRY_NIGHT_HOST_NONE);
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
