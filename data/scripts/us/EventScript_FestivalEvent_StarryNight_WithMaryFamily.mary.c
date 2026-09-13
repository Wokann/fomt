#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_StarryNight_WithMaryFamily_ThanksForComing[] =
        "Thanks for coming. {Press}";

    const char gText_FestivalEvent_StarryNight_WithMaryFamily_HelloComeOnIn[] =
        "Hello! \r\n"
        "Come on in! {Press}";

    const char gText_FestivalEvent_StarryNight_WithMaryFamily_MaryInvitedYouEhIHope[] =
        "Mary invited you, eh?\r\n"
        "I hope you enjoy yourself.{Press}\p"
        "Do you want to hear about\r\n"
        "the plants I'm researching?{Press}";

    const char gText_FestivalEvent_StarryNight_WithMaryFamily_MaryStopsBasilBoringPlayer[] =
        "Dad! Don't bore \r\n"
        "{Player}!{Press}";

    const char gText_FestivalEvent_StarryNight_WithMaryFamily_InThatCaseIWantTo[] =
        "In that case, I want to \r\n"
        "hear about the farm!{Press}";

    const char gText_FestivalEvent_StarryNight_WithMaryFamily_SpendingTheStarryNightFestivalWith[] =
        "Spending the Starry Night \r\n"
        "Festival with Mary's family\r\n"
        "sure was fun! {Press}";
};

void EventScript_FestivalEvent_StarryNight_WithMaryFamily(void)
{
    ChangeMap(MAP_BASIL_HOUSE_1F, X(120), Y(160));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
    CreateEventIcon(EVENT_ICON_SLOT_0, X(112), Y(112), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_CAKE));
    CreateEventIcon(EVENT_ICON_SLOT_1, X(128), Y(112), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_FRUIT_JUICE));
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
    SetEntityPosition(ENTITY_MARY, X(84), Y(128), FACING_RIGHT);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityPosition(ENTITY_ANNA, X(112), Y(96), FACING_DOWN);
    SetEntityAnim(ENTITY_ANNA, ANIMATION_ANNA_IDLE);
    SetEntityPosition(ENTITY_BASIL, X(128), Y(96), FACING_DOWN);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(160), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityFacing(ENTITY_MARY, FACING_DOWN);
    WaitFrames(10);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_FestivalEvent_StarryNight_WithMaryFamily_ThanksForComing);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
    TalkMessage(gText_FestivalEvent_StarryNight_WithMaryFamily_HelloComeOnIn);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
    TalkMessage(gText_FestivalEvent_StarryNight_WithMaryFamily_MaryInvitedYouEhIHope);
    TalkClose();
    SetEntityFacing(ENTITY_ANNA, FACING_RIGHT);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    SetTalkPortrait(TALK_PORTRAIT_ANNA_ANGRY);
    TalkMessage(gText_FestivalEvent_StarryNight_WithMaryFamily_MaryStopsBasilBoringPlayer);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
    TalkMessage(gText_FestivalEvent_StarryNight_WithMaryFamily_InThatCaseIWantTo);
    TalkClose();
    AddCharacterLove(CHARACTER_MARY, 2000);
    AddNpcFriendship(CHARACTER_MARY, 30);
    AddNpcFriendship(CHARACTER_BASIL, 30);
    AddNpcFriendship(CHARACTER_ANNA, 30);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_FestivalEvent_StarryNight_WithMaryFamily_SpendingTheStarryNightFestivalWith);
    TalkClose();
    RemoveEventIcon(EVENT_ICON_SLOT_0);
    RemoveEventIcon(EVENT_ICON_SLOT_1);
    VarSet(VAR_STARRY_NIGHT_MARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    VarSet(VAR_FESTIVAL_STARRY_NIGHT_HOST_INDEX, STARRY_NIGHT_HOST_NONE);
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
