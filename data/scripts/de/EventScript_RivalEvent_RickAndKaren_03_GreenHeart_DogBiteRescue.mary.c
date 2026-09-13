#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_KarenScoldsInjuredRick[] =
        "Du bist so ein Idiot!...{Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_RickAsksKarenToStopCriticizing[] =
        "Du musst nicht auch \r\n"
        "noch darauf rumhacken. {Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_KarenSaysRickWasBittenProtectingHer[] =
        "Sich zu verletzen, weil\r\n"
        "du mich vor dem wilden \r\n"
        "Hund beschützt... Dämlich!{Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_RickIsRelievedKarenWasNotBitten[] =
        "Ich bin nur froh, dass die\r\n"
        "Wunde nicht schlimmer ist!{Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_KarenInsistsRickTreatTheBite[] =
        "Idiot!\r\n"
        "Ein Biss ist ein Biss! {Press}\p"
        "Du solltest dich nicht\r\n"
        "meinetwegen verletzen!{Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_RickAddressesKaren[] =
        "Karen...{Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_KarenAddressesRick[] =
        "...Rick?{Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_RickReactsToKarensConcern[] =
        "...Was?{Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_KarenThanksRick[] =
        "...Danke.{Press}";

    const char gText_RivalEvent_RickAndKaren_03_GreenHeart_DogBiteRescue_RickSuggestsReturningToTown[] =
        "...Keine Ursache. \r\n"
        "Gehen wir zurück, ja?{Press}\p"
        "Und lass uns nicht \r\n"
        "darüber sprechen. Ich\r\n"
        "will nicht, dass sich {Press}\r\n"
        "jemand Sorgen macht. {Press}";

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
