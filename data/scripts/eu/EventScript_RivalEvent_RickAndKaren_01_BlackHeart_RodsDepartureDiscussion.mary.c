#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion_KarenAsksWhetherRickHeardFromRod[] =
        "Have you heard from\r\n"
        "your dad?{Press}";

    const char gText_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion_RickSaysHeHasNotHeardFromRod[] =
        "Not recently. {Press}";

    const char gText_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion_RickResentsRodLeavingLillia[] =
        "How could he leave my mom\r\n"
        "like that! {Press}";

    const char gText_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion_KarenExplainsRodLeftToFindCureForLillia[] =
        "You know the only reason \r\n"
        "he's away is to find a way \r\n"
        "to heal your mom! {Press}\p"
        "He's just trying to protect\r\n"
        "his family, you know. {Press}";

    const char gText_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion_RickAcceptsKarensPoint[] =
        "...I guess you're right. {Press}";

    const char gText_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion_KarenSaysTheyMustSupportLilliaAndPopuri[] =
        "We have to take care of  \r\n"
        "things until he comes \r\n"
        "back, right?! {Press}";

    const char gText_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion_RickAcknowledgesFamilyResponsibility[] =
        "Yeah, I know...{Press}";

    const char gText_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion_KarenEncouragesRickToStopBrooding[] =
        "Then stop getting\r\n"
        "so depressed! Let's head \r\n"
        "home. {Press}";

    const char gText_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion_RickAgreesToReturnHome[] =
        "OK...{Press}";
};

void EventScript_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion(void)
{
    ChangeMap(MAP_MOTHERS_HILL_MIDDLE, X(900), Y(350));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    VarSet(VAR_RICK_KAREN_RIVAL_EVENT_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityPosition(ENTITY_PLAYER, X(900), Y(350), FACING_DOWN);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_KAREN, X(1162), Y(480), FACING_LEFT);
    SetEntityPosition(ENTITY_RICK, X(1162), Y(480), FACING_LEFT);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(1020), Y(468), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
    MoveEntityXTo(ENTITY_KAREN, X(1020), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAREN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityFacing(ENTITY_KAREN, FACING_UP);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
    MoveEntityYTo(ENTITY_KAREN, Y(428), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAREN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WALK);
    MoveEntityXTo(ENTITY_RICK, X(1020), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_RICK);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    SetEntityFacing(ENTITY_RICK, FACING_UP);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WALK);
    MoveEntityYTo(ENTITY_RICK, Y(468), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_RICK);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion_KarenAsksWhetherRickHeardFromRod);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion_RickSaysHeHasNotHeardFromRod);
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion_RickResentsRodLeavingLillia);
    TalkClose();
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_KAREN, FACING_UP);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion_KarenExplainsRodLeftToFindCureForLillia);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion_RickAcceptsKarensPoint);
    TalkClose();
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion_KarenSaysTheyMustSupportLilliaAndPopuri);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion_RickAcknowledgesFamilyResponsibility);
    TalkClose();
    SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
    MoveEntityXTo(ENTITY_KAREN, X(1045), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAREN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
    MoveEntityYTo(ENTITY_KAREN, Y(468), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAREN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityFacing(ENTITY_KAREN, FACING_LEFT);
    SetEntityFacing(ENTITY_RICK, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion_KarenEncouragesRickToStopBrooding);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_01_BlackHeart_RodsDepartureDiscussion_RickAgreesToReturnHome);
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
    WaitForEntityMovement(ENTITY_RICK);
    WaitForEntityMovement(ENTITY_KAREN);
    HideEntity(ENTITY_RICK);
    HideEntity(ENTITY_KAREN);
    WaitFrames(60);
    PanCameraTo(X(900), Y(350), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    VarSet(VAR_RICK_KAREN_RIVAL_EVENT_1_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
