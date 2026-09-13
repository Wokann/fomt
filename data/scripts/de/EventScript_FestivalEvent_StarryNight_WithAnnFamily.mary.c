#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_StarryNight_WithAnnFamily_ThanksForComingWeWereJust[] =
        "Danke fürs Kommen. \r\n"
        "Wir wollten gerade mit \r\n"
        "der Party beginnen. {Press}";

    const char gText_FestivalEvent_StarryNight_WithAnnFamily_YouCanComeOverAnyTime[] =
        "Du kannst jederzeit \r\n"
        "vorbeikommen. Du\r\n"
        "solltest sogar erwägen,{Press}\r\n"
        "Ann zu heiraten...{Press}";

    const char gText_FestivalEvent_StarryNight_WithAnnFamily_DadIfYouKeepTalkingLike[] =
        "Papa! Wenn du so\r\n"
        "redest, will er überhaupt\r\n"
        "nicht mehr kommen!{Press}";

    const char gText_FestivalEvent_StarryNight_WithAnnFamily_SpendingStarryNightFestivalWithAnns[] =
        "Das Sternennachtfestival\r\n"
        "mit Anns Familie zu ver-\r\n"
        "bringen, hat Spaß gemacht.{Press}";
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
