#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_Results_WeWillNowAnnounceTheWinner[] =
        "We will now announce the \r\n"
        "winner! Please come up\r\n"
        "close, now. {Press}\p"
        "The winner is......{Press}";

    const char gText_FestivalEvent_CookingFestival_Results_Player[] =
        "{Player}!{Press}";

    const char gText_FestivalEvent_CookingFestival_Results_Doug[] =
        "Doug!{Press}";

    const char gText_FestivalEvent_CookingFestival_Results_Ann[] =
        "Ann! {Press}";

    const char gText_FestivalEvent_CookingFestival_Results_Lillia[] =
        "Lillia!{Press}";

    const char gText_FestivalEvent_CookingFestival_Results_Manna[] =
        "Manna!{Press}";

    const char gText_FestivalEvent_CookingFestival_Results_YourCookingWasTrulyDeliciousLet[] =
        "Your cooking was truly \r\n"
        "delicious! Let me \r\n"
        "congratulate you myself!{Press}";

    const char gText_FestivalEvent_CookingFestival_Results_PlayerReturnsToWorkAfterFestival[] =
        "That was fun! \r\n"
        "Now, back to work...{Press}";
};

void EventScript_FestivalEvent_CookingFestival_Results(void)
{
    ChangeMap(MAP_ROSE_SQUARE, X(231), Y(142));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
    SetEntityPosition(ENTITY_THOMAS, X(180), Y(102), FACING_DOWN);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    SetEntityPosition(ENTITY_GOURMET, X(231), Y(130), FACING_DOWN);
    SetEntityAnim(ENTITY_GOURMET, ANIMATION_GOURMET_IDLE);
    SetEntityPosition(ENTITY_LILLIA, X(167), Y(198), FACING_UP);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(191), Y(198), FACING_UP);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    SetEntityPosition(ENTITY_ANN, X(215), Y(198), FACING_UP);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_KAREN, X(239), Y(198), FACING_UP);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_MANNA, X(263), Y(198), FACING_UP);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    if (VarGet(VAR_COOKING_FESTIVAL_PLAYER_ENTERED) == TRUE)
    {
        SetEntityPosition(ENTITY_PLAYER, X(287), Y(198), FACING_UP);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_FestivalEvent_CookingFestival_Results_WeWillNowAnnounceTheWinner);
    TalkClose();
    StopBGM();
    PlaySong(AUDIO_START, AUDIO_SFX_SUCCESS);
    WaitFrames(60 * 4);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    if (VarGet(VAR_COOKING_FESTIVAL_PLAYER_ENTERED) == TRUE && VarGet(VAR_COOKING_FESTIVAL_PLAYER_DISH_RATING) == FESTIVAL_COOKING_DISH_RATING_EXCELLENT)
    {
        TalkMessage(gText_FestivalEvent_CookingFestival_Results_Player);
        TalkClose();
        WaitFrames(30);
        PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
        AddNpcFriendship(CHARACTER_THOMAS, 20);
        AddNpcFriendship(CHARACTER_DOCTOR, 20);
        AddNpcFriendship(CHARACTER_CARTER, 20);
        AddNpcFriendship(CHARACTER_GOURMET, 20);
        AddNpcFriendship(CHARACTER_ZACK, 20);
        AddNpcFriendship(CHARACTER_ANN, 20);
        AddNpcFriendship(CHARACTER_GOTZ, 20);
        AddNpcFriendship(CHARACTER_KAREN, 20);
        AddNpcFriendship(CHARACTER_DOUG, 20);
        AddNpcFriendship(CHARACTER_SASHA, 20);
        AddNpcFriendship(CHARACTER_MANNA, 20);
        AddNpcFriendship(CHARACTER_RICK, 20);
        AddNpcFriendship(CHARACTER_LILLIA, 20);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
        MoveEntityYTo(ENTITY_PLAYER, Y(170), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_PLAYER);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
        MoveEntityXTo(ENTITY_PLAYER, X(231), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_PLAYER);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    }
    else
    {
        if (VarGet(VAR_COOKING_FESTIVAL_PLAYER_ENTERED) == TRUE && VarGet(VAR_COOKING_FESTIVAL_PLAYER_DISH_RATING) == FESTIVAL_COOKING_DISH_RATING_GREAT)
        {
            TalkMessage(gText_FestivalEvent_CookingFestival_Results_Player);
            TalkClose();
            WaitFrames(30);
            PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
            AddNpcFriendship(CHARACTER_THOMAS, 20);
            AddNpcFriendship(CHARACTER_DOCTOR, 20);
            AddNpcFriendship(CHARACTER_CARTER, 20);
            AddNpcFriendship(CHARACTER_GOURMET, 20);
            AddNpcFriendship(CHARACTER_ZACK, 20);
            AddNpcFriendship(CHARACTER_ANN, 20);
            AddNpcFriendship(CHARACTER_GOTZ, 20);
            AddNpcFriendship(CHARACTER_KAREN, 20);
            AddNpcFriendship(CHARACTER_DOUG, 20);
            AddNpcFriendship(CHARACTER_SASHA, 20);
            AddNpcFriendship(CHARACTER_MANNA, 20);
            AddNpcFriendship(CHARACTER_RICK, 20);
            AddNpcFriendship(CHARACTER_LILLIA, 20);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
            MoveEntityYTo(ENTITY_PLAYER, Y(170), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
            MoveEntityXTo(ENTITY_PLAYER, X(231), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
        }
        else
        {
            switch (RandomIntInclusive(0, 3))
            {
                case 0:
                    TalkMessage(gText_FestivalEvent_CookingFestival_Results_Doug);
                    TalkClose();
                    WaitFrames(30);
                    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
                    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_WALK);
                    MoveEntityYTo(ENTITY_DOUG, Y(170), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                    WaitForEntityMovement(ENTITY_DOUG);
                    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
                    SetEntityFacing(ENTITY_DOUG, FACING_RIGHT);
                    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_WALK);
                    MoveEntityXTo(ENTITY_DOUG, X(231), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                    WaitForEntityMovement(ENTITY_DOUG);
                    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
                    SetEntityFacing(ENTITY_DOUG, FACING_UP);
                    break;
                case 1:
                    TalkMessage(gText_FestivalEvent_CookingFestival_Results_Ann);
                    TalkClose();
                    WaitFrames(30);
                    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
                    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
                    MoveEntityYTo(ENTITY_ANN, Y(170), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                    WaitForEntityMovement(ENTITY_ANN);
                    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
                    SetEntityFacing(ENTITY_ANN, FACING_RIGHT);
                    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
                    MoveEntityXTo(ENTITY_ANN, X(231), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                    WaitForEntityMovement(ENTITY_ANN);
                    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
                    SetEntityFacing(ENTITY_ANN, FACING_UP);
                    break;
                case 2:
                    TalkMessage(gText_FestivalEvent_CookingFestival_Results_Lillia);
                    TalkClose();
                    WaitFrames(30);
                    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
                    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_WALK);
                    MoveEntityYTo(ENTITY_LILLIA, Y(170), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                    WaitForEntityMovement(ENTITY_LILLIA);
                    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
                    SetEntityFacing(ENTITY_LILLIA, FACING_RIGHT);
                    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_WALK);
                    MoveEntityXTo(ENTITY_LILLIA, X(231), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                    WaitForEntityMovement(ENTITY_LILLIA);
                    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
                    SetEntityFacing(ENTITY_LILLIA, FACING_UP);
                    break;
                case 3:
                    TalkMessage(gText_FestivalEvent_CookingFestival_Results_Manna);
                    TalkClose();
                    WaitFrames(30);
                    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
                    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_WALK);
                    MoveEntityYTo(ENTITY_MANNA, Y(170), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                    WaitForEntityMovement(ENTITY_MANNA);
                    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
                    SetEntityFacing(ENTITY_MANNA, FACING_LEFT);
                    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_WALK);
                    MoveEntityXTo(ENTITY_MANNA, X(231), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                    WaitForEntityMovement(ENTITY_MANNA);
                    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
                    SetEntityFacing(ENTITY_MANNA, FACING_UP);
                    break;
            }
        }
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_GOURMET);
    SetTalkPortrait(TALK_PORTRAIT_GOURMET_HAPPY);
    TalkMessage(gText_FestivalEvent_CookingFestival_Results_YourCookingWasTrulyDeliciousLet);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_VICTORY);
    WaitFrames(60 * 3);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_FestivalEvent_CookingFestival_Results_PlayerReturnsToWorkAfterFestival);
    TalkClose();
    DisableScriptedNpcControl();
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    MarkNpcSpokenTo(CHARACTER_GOURMET);
    ClearEntityEventScript(ENTITY_THOMAS);
    ClearEntityEventScript(ENTITY_DOCTOR);
    ClearEntityEventScript(ENTITY_CARTER);
    ClearEntityEventScript(ENTITY_GOURMET);
    ClearEntityEventScript(ENTITY_ZACK);
    ClearEntityEventScript(ENTITY_ANN);
    ClearEntityEventScript(ENTITY_GOTZ);
    ClearEntityEventScript(ENTITY_KAREN);
    ClearEntityEventScript(ENTITY_DOUG);
    ClearEntityEventScript(ENTITY_SASHA);
    ClearEntityEventScript(ENTITY_MANNA);
    ClearEntityEventScript(ENTITY_RICK);
    ClearEntityEventScript(ENTITY_LILLIA);
    VarSet(VAR_COOKING_FESTIVAL_COMPLETED, FESTIVAL_PHASE_ADVANCED);
    VarSet(VAR_COOKING_FESTIVAL_PLAYER_ENTERED, FALSE);
    PlacePlayerAtFarmhouseBed();
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    return;
}
