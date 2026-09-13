#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_StarryNight_WithKarenFamily_HiPlayer[] =
        "Hi, {Player}!{Press}";

    const char gText_FestivalEvent_StarryNight_WithKarenFamily_KarenWasAfraidYouWouldntCome[] =
        "Karen hatte Angst, du\r\n"
        "würdest nicht kommen, \r\n"
        "{Player}. {Press}";

    const char gText_FestivalEvent_StarryNight_WithKarenFamily_WhatDoYouMeanKarenWas[] =
        "Was meinst du mit Karen\r\n"
        "hatte Angst, {Player}\r\n"
        "würde nicht kommen?{Press}";

    const char gText_FestivalEvent_StarryNight_WithKarenFamily_Hesitates[] =
        "Ähm...{Press}";

    const char gText_FestivalEvent_StarryNight_WithKarenFamily_KarenDismissesHerEmbarrassment[] =
        "Vergiss es einfach!{Press}";

    const char gText_FestivalEvent_StarryNight_WithKarenFamily_AllISaidWasThatMaybe[] =
        "Ich habe nur gesagt,\r\n"
        "du hast es vielleicht \r\n"
        "vergessen!{Press}";

    const char gText_FestivalEvent_StarryNight_WithKarenFamily_SpendingTheStarryNightFestivalWith[] =
        "Es hat Spaß gemacht, das\r\n"
        "Sternennachtfestival mit \r\n"
        "Karens Familie zu feiern. {Press}";
};

void EventScript_FestivalEvent_StarryNight_WithKarenFamily(void)
{
    ChangeMap(MAP_SUPERMARKET_BACK_ROOM, X(92), Y(272));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
    CreateEventIcon(EVENT_ICON_SLOT_0, X(160), Y(192), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_CAKE));
    CreateEventIcon(EVENT_ICON_SLOT_1, X(176), Y(192), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_WINE));
    SetEntityPosition(ENTITY_PLAYER, X(92), Y(320), FACING_UP);
    SetEntityPosition(ENTITY_KAREN, X(112), Y(232), FACING_RIGHT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_JEFF, X(168), Y(224), FACING_UP);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(200), Y(192), FACING_LEFT);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
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
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
    SetEntityFacing(ENTITY_JEFF, FACING_DOWN);
    SetEntityFacing(ENTITY_SASHA, FACING_DOWN);
    WaitFrames(10);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FestivalEvent_StarryNight_WithKarenFamily_HiPlayer);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    TalkMessage(gText_FestivalEvent_StarryNight_WithKarenFamily_KarenWasAfraidYouWouldntCome);
    TalkClose();
    SetEntityFacing(ENTITY_JEFF, FACING_UP);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
    TalkMessage(gText_FestivalEvent_StarryNight_WithKarenFamily_WhatDoYouMeanKarenWas);
    SetEntityFacing(ENTITY_JEFF, FACING_LEFT);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
    TalkMessage(gText_FestivalEvent_StarryNight_WithKarenFamily_Hesitates);
    TalkClose();
    SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FestivalEvent_StarryNight_WithKarenFamily_KarenDismissesHerEmbarrassment);
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FestivalEvent_StarryNight_WithKarenFamily_AllISaidWasThatMaybe);
    TalkClose();
    AddCharacterLove(CHARACTER_KAREN, 2000);
    AddNpcFriendship(CHARACTER_KAREN, 30);
    AddNpcFriendship(CHARACTER_JEFF, 30);
    AddNpcFriendship(CHARACTER_SASHA, 30);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_FestivalEvent_StarryNight_WithKarenFamily_SpendingTheStarryNightFestivalWith);
    TalkClose();
    RemoveEventIcon(EVENT_ICON_SLOT_0);
    RemoveEventIcon(EVENT_ICON_SLOT_1);
    VarSet(VAR_STARRY_NIGHT_KAREN_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    VarSet(VAR_FESTIVAL_STARRY_NIGHT_HOST_INDEX, STARRY_NIGHT_HOST_NONE);
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
