#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_KarenScoldsInjuredRick[] =
        "You're such an idiot!...{Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_RickAsksKarenToStopCriticizing[] =
        "You don't have to rub it \r\n"
        "in, you know. {Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_KarenSaysRickWasBittenProtectingHer[] =
        "Getting hurt while\r\n"
        "protecting me from that \r\n"
        "wild dog...Idiotic!{Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_RickIsRelievedKarenWasNotBitten[] =
        "I'm just glad the wound\r\n"
        "isn't worse than it is!{Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_KarenInsistsRickTreatTheBite[] =
        "Idiot!\r\n"
        "A bite is a bite! {Press}\p"
        "You shouldn't let yourself\r\n"
        "get hurt for me, period!{Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_RickAddressesKaren[] =
        "Karen...{Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_KarenAddressesRick[] =
        "...Rick?{Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_RickReactsToKarensConcern[] =
        "...What?{Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_KarenThanksRick[] =
        "...Thanks.{Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_RickSuggestsReturningToTown[] =
        "...Don't mention it. \r\n"
        "Let's get back, shall we?{Press}\p"
        "And let's keep quiet about \r\n"
        "this. I don't want anyone\r\n"
        "to worry. {Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_KarenAgreesToReturnToTown[] =
        "OK. {Press}";
};

void EventScript_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue(void)
{
    ChangeMap(MAP_MOTHERS_HILL_MIDDLE, X(900), Y(350));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    VarSet(VAR_RICK_KAREN_RIVAL_EVENT_3_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityPosition(ENTITY_PLAYER, X(900), Y(350), FACING_DOWN);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_KAREN, X(1020), Y(448), FACING_RIGHT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_RICK, X(1044), Y(448), FACING_LEFT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(1020), Y(458), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_KarenScoldsInjuredRick);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_RickAsksKarenToStopCriticizing);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_KarenSaysRickWasBittenProtectingHer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_RickIsRelievedKarenWasNotBitten);
    TalkClose();
    StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_KarenInsistsRickTreatTheBite);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_RickAddressesKaren);
    TalkClose();
    StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_THINKING, FALSE);
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_KarenAddressesRick);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_RickReactsToKarensConcern);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_KarenThanksRick);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_RickSuggestsReturningToTown);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_KarenAgreesToReturnToTown);
    TalkClose();
    SetEntityFacing(ENTITY_RICK, FACING_DOWN);
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WALK);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
    MoveEntityYTo(ENTITY_RICK, Y(480), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_KAREN, Y(480), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_RICK);
    WaitForEntityMovement(ENTITY_KAREN);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityFacing(ENTITY_RICK, FACING_RIGHT);
    SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WALK);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
    MoveEntityXTo(ENTITY_RICK, X(1162), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityXTo(ENTITY_KAREN, X(1162), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAREN);
    WaitForEntityMovement(ENTITY_RICK);
    HideEntity(ENTITY_KAREN);
    HideEntity(ENTITY_RICK);
    PanCameraTo(X(900), Y(350), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    VarSet(VAR_RICK_KAREN_RIVAL_EVENT_3_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
