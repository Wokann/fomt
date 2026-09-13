#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_StarryNight_WithElliFamily_HiThereGoodTimingWeWere[] =
        "Hi there. \r\n"
        "Good timing. We were \r\n"
        "just about to start. {Press}";

    const char gText_FestivalEvent_StarryNight_WithElliFamily_ImSoGladWeHaveCompany[] =
        "I'm so glad we have \r\n"
        "company! It's usually just\r\n"
        "the 3 of us...{Press}";

    const char gText_FestivalEvent_StarryNight_WithElliFamily_TheDoctorAlwaysEatsAtThe[] =
        "The Doctor always eats at \r\n"
        "the Church with Carter. {Press}\p"
        "Elli tried inviting him \r\n"
        "before!{Press}";

    const char gText_FestivalEvent_StarryNight_WithElliFamily_StuWillYouShutYourBig[] =
        "Stu, will you shut\r\n"
        "your big mouth!{Press}";

    const char gText_FestivalEvent_StarryNight_WithElliFamily_SpendingTheStarryNightFestivalWith[] =
        "Spending the Starry Night\r\n"
        "Festival with Elli's family\r\n"
        "sure was fun. {Press}";
};

void EventScript_FestivalEvent_StarryNight_WithElliFamily(void)
{
    ChangeMap(MAP_ELLEN_HOUSE, X(120), Y(160));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
    CreateEventIcon(EVENT_ICON_SLOT_0, X(64), Y(120), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_APPLE_PIE));
    CreateEventIcon(EVENT_ICON_SLOT_1, X(80), Y(120), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_MILK_L));
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
    SetEntityPosition(ENTITY_ELLI, X(104), Y(120), FACING_LEFT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_ELLEN, X(80), Y(100), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLEN, ANIMATION_ELLEN_IDLE);
    SetEntityPosition(ENTITY_STU, X(64), Y(100), FACING_DOWN);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
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
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
    WaitFrames(10);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FestivalEvent_StarryNight_WithElliFamily_HiThereGoodTimingWeWere);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    TalkMessage(gText_FestivalEvent_StarryNight_WithElliFamily_ImSoGladWeHaveCompany);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_STU);
    SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
    TalkMessage(gText_FestivalEvent_StarryNight_WithElliFamily_TheDoctorAlwaysEatsAtThe);
    TalkClose();
    SetEntityFacing(ENTITY_ELLI, FACING_LEFT);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FestivalEvent_StarryNight_WithElliFamily_StuWillYouShutYourBig);
    TalkClose();
    AddCharacterLove(CHARACTER_ELLI, 2000);
    AddNpcFriendship(CHARACTER_ELLI, 30);
    AddNpcFriendship(CHARACTER_STU, 30);
    AddNpcFriendship(CHARACTER_ELLEN, 30);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_FestivalEvent_StarryNight_WithElliFamily_SpendingTheStarryNightFestivalWith);
    TalkClose();
    RemoveEventIcon(EVENT_ICON_SLOT_0);
    RemoveEventIcon(EVENT_ICON_SLOT_1);
    VarSet(VAR_STARRY_NIGHT_ELLI_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    VarSet(VAR_FESTIVAL_STARRY_NIGHT_HOST_INDEX, STARRY_NIGHT_HOST_NONE);
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
