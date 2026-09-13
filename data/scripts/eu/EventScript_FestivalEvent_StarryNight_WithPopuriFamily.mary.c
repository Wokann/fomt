#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_StarryNight_WithPopuriFamily_ThanksForComing[] =
        "Thanks for coming. {Press}";

    const char gText_FestivalEvent_StarryNight_WithPopuriFamily_FamilyWelcomesPlayer[] =
        "Good evening. \r\n"
        "Please come in.{Press}";

    const char gText_FestivalEvent_StarryNight_WithPopuriFamily_SoPopuriInvitedYouYouLive[] =
        "So Popuri invited you?\r\n"
        "You live alone, right?{Press}\p"
        "It's always good to be with\r\n"
        "friends for the Starry \r\n"
        "Night Festival, you know!{Press}";

    const char gText_FestivalEvent_StarryNight_WithPopuriFamily_WellThenLetsStartTheParty[] =
        "Well then, let's start\r\n"
        "the party...!{Press}";

    const char gText_FestivalEvent_StarryNight_WithPopuriFamily_SpendingTheStarryNightFestivalWith[] =
        "Spending the Starry Night \r\n"
        "Festival with Popuri's \r\n"
        "family was lots of fun!{Press}";
};

void EventScript_FestivalEvent_StarryNight_WithPopuriFamily(void)
{
    ChangeMap(MAP_POULTRY_FARM_HOUSE_1F, X(120), Y(168));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
    CreateEventIcon(EVENT_ICON_SLOT_0, X(120), Y(104), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_CAKE));
    CreateEventIcon(EVENT_ICON_SLOT_1, X(136), Y(104), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_FRUIT_JUICE));
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(210), FACING_UP);
    SetEntityPosition(ENTITY_POPURI, X(168), Y(142), FACING_LEFT);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityPosition(ENTITY_RICK, X(128), Y(88), FACING_DOWN);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    SetEntityPosition(ENTITY_LILLIA, X(96), Y(120), FACING_RIGHT);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
    SetEntityFacing(ENTITY_LILLIA, FACING_DOWN);
    WaitFrames(10);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FestivalEvent_StarryNight_WithPopuriFamily_ThanksForComing);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    TalkMessage(gText_FestivalEvent_StarryNight_WithPopuriFamily_FamilyWelcomesPlayer);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_RICK);
    SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
    TalkMessage(gText_FestivalEvent_StarryNight_WithPopuriFamily_SoPopuriInvitedYouYouLive);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    TalkMessage(gText_FestivalEvent_StarryNight_WithPopuriFamily_WellThenLetsStartTheParty);
    TalkClose();
    AddCharacterLove(CHARACTER_POPURI, 2000);
    AddNpcFriendship(CHARACTER_POPURI, 30);
    AddNpcFriendship(CHARACTER_RICK, 30);
    AddNpcFriendship(CHARACTER_LILLIA, 30);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_FestivalEvent_StarryNight_WithPopuriFamily_SpendingTheStarryNightFestivalWith);
    TalkClose();
    RemoveEventIcon(EVENT_ICON_SLOT_0);
    RemoveEventIcon(EVENT_ICON_SLOT_1);
    VarSet(VAR_STARRY_NIGHT_POPURI_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    VarSet(VAR_FESTIVAL_STARRY_NIGHT_HOST_INDEX, STARRY_NIGHT_HOST_NONE);
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
