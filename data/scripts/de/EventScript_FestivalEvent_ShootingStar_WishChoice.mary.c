#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ShootingStar_WishChoice_PlayerMakesWishUponShootingStars[] =
        "Wow, Sternschnuppen!\r\n"
        "Ich wünsche mir...{Press}";

    const char gText_FestivalEvent_ShootingStar_WishChoice_WishForHealthyAnimals[] =
        "Gesunde Tiere.";

    const char gText_FestivalEvent_ShootingStar_WishChoice_WishForFriendshipWithTownspeople[] =
        "Freunde.";

    const char gText_FestivalEvent_ShootingStar_WishChoice_WishForProfitableShipping[] =
        "Gute Versandpreise.";

    const char gText_FestivalEvent_ShootingStar_WishChoice_PlayerHopesWishComesTrue[] =
        "Ich hoffe, mein Wunsch\r\n"
        "geht in Erfüllung...{Press}";
};

void EventScript_FestivalEvent_ShootingStar_WishChoice(void)
{
    int var_0, unused_1, var_2;
    VarSet(VAR_SHOOTING_STAR_WISH_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    PanCameraTo(X(236), Y(140), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
    MoveEntityYTo(ENTITY_PLAYER, Y(248), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
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
    PlaySong(AUDIO_START, AUDIO_SFX_STAR_SPARKLE);
    PlayStarSparkleEffect();
    TalkOpen();
    TalkMessage(gText_FestivalEvent_ShootingStar_WishChoice_PlayerMakesWishUponShootingStars);
    var_0 = TalkChoice3(gText_FestivalEvent_ShootingStar_WishChoice_WishForHealthyAnimals, gText_FestivalEvent_ShootingStar_WishChoice_WishForFriendshipWithTownspeople, gText_FestivalEvent_ShootingStar_WishChoice_WishForProfitableShipping);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            CureAllSickLivestock();
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            AddNpcFriendship(CHARACTER_LILLIA, 10);
            AddNpcFriendship(CHARACTER_RICK, 10);
            AddNpcFriendship(CHARACTER_POPURI, 10);
            AddNpcFriendship(CHARACTER_BARLEY, 10);
            AddNpcFriendship(CHARACTER_MAY, 10);
            AddNpcFriendship(CHARACTER_SAIBARA, 10);
            AddNpcFriendship(CHARACTER_GRAY, 10);
            AddNpcFriendship(CHARACTER_DUKE, 10);
            AddNpcFriendship(CHARACTER_MANNA, 10);
            AddNpcFriendship(CHARACTER_BASIL, 10);
            AddNpcFriendship(CHARACTER_ANNA, 10);
            AddNpcFriendship(CHARACTER_MARY, 10);
            AddNpcFriendship(CHARACTER_THOMAS, 10);
            AddNpcFriendship(CHARACTER_HARRIS, 10);
            AddNpcFriendship(CHARACTER_ELLEN, 10);
            AddNpcFriendship(CHARACTER_STU, 10);
            AddNpcFriendship(CHARACTER_JEFF, 10);
            AddNpcFriendship(CHARACTER_SASHA, 10);
            AddNpcFriendship(CHARACTER_KAREN, 10);
            AddNpcFriendship(CHARACTER_DOCTOR, 10);
            AddNpcFriendship(CHARACTER_ELLI, 10);
            AddNpcFriendship(CHARACTER_CARTER, 10);
            AddNpcFriendship(CHARACTER_CLIFF, 10);
            AddNpcFriendship(CHARACTER_DOUG, 10);
            AddNpcFriendship(CHARACTER_ANN, 10);
            AddNpcFriendship(CHARACTER_KAI, 10);
            AddNpcFriendship(CHARACTER_GOTZ, 10);
            AddNpcFriendship(CHARACTER_ZACK, 10);
            AddNpcFriendship(CHARACTER_WON, 10);
            AddNpcFriendship(CHARACTER_GOURMET, 10);
            AddNpcFriendship(CHARACTER_HARVEST_GODDESS, 10);
            AddNpcFriendship(CHARACTER_VAN, 10);
            AddNpcFriendship(CHARACTER_LOU_OR_RUBY, 10);
            AddNpcFriendship(CHARACTER_CHILD, 10);
            AddNpcFriendship(CHARACTER_STAID, 10);
            AddNpcFriendship(CHARACTER_NAPPY, 10);
            AddNpcFriendship(CHARACTER_BOLD, 10);
            AddNpcFriendship(CHARACTER_CHEF, 10);
            AddNpcFriendship(CHARACTER_AQUA, 10);
            AddNpcFriendship(CHARACTER_HOGGY, 10);
            AddNpcFriendship(CHARACTER_TIMID, 10);
            break;
        case CHOICE_OPTION_3:
            EnableShootingStarShippingBonus();
            break;
    }
    TalkClose();
    var_2 = RandomIntInclusive(1, 4);
    do
    {
        PlayStarSparkleEffect();
        PlaySong(AUDIO_START, AUDIO_SFX_STAR_SPARKLE);
        WaitFrames(3);
        var_2 = var_2 - 1;
    }
    while (var_2 >= 0);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_FestivalEvent_ShootingStar_WishChoice_PlayerHopesWishComesTrue);
    TalkClose();
    VarSet(VAR_SHOOTING_STAR_WISH_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
