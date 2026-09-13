#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_Ceremony_WeddingAnnouncement[] =
        "Good morning. \r\n"
        "I've asked Elli to marry me.\r\n"
        "She said yes! {Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_Ceremony_WeddingInvitationAndCoupleDetails[] =
        "The wedding is later today. \r\n"
        "You're coming, aren't you? {Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_Ceremony_CarterConductsWeddingKiss[] =
        "You may now kiss the bride. {Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_Ceremony_CarterToastsElliAndDoctor[] =
        "A toast to the newlyweds! {Press}";
};

void EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_Ceremony(void)
{
    VarSet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    ChangeMap(MAP_FARM, X(228), Y(160));
    SetEntityPosition(ENTITY_PLAYER, X(228), Y(120), FACING_DOWN);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_DOCTOR, X(228), Y(160), FACING_UP);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_Ceremony_WeddingAnnouncement);
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_Ceremony_WeddingInvitationAndCoupleDetails);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StopBGM();
    ChangeMap(MAP_CHURCH, X(184), Y(160));
    SetEntityPosition(ENTITY_ELLI, X(200), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WEDDING_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(168), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_WEDDING_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(184), Y(120), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(104), Y(195), FACING_RIGHT);
    PreparePlayerForScriptedAnimation();
    SetEntityPosition(ENTITY_ELLEN, X(264), Y(120), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLEN, ANIMATION_ELLEN_IDLE);
    SetEntityPosition(ENTITY_STU, X(264), Y(195), FACING_LEFT);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityPosition(ENTITY_HARRIS, X(104), Y(155), FACING_RIGHT);
    SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_IDLE);
    if (GetEntityLocation(ENTITY_CLIFF) == MAP_CHURCH)
    {
        HideEntity(ENTITY_CLIFF);
    }
    if (GetEntityLocation(ENTITY_JEFF) == MAP_CHURCH)
    {
        HideEntity(ENTITY_JEFF);
    }
    if (GetEntityLocation(ENTITY_DUKE) == MAP_CHURCH)
    {
        HideEntity(ENTITY_DUKE);
    }
    if (GetEntityLocation(ENTITY_MANNA) == MAP_CHURCH)
    {
        HideEntity(ENTITY_MANNA);
    }
    if (GetEntityLocation(ENTITY_POPURI) == MAP_CHURCH)
    {
        HideEntity(ENTITY_POPURI);
    }
    StopAllSongs();
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PlaySong(AUDIO_START, AUDIO_SFX_CEREMONIAL_CHIME);
    WaitFrames(60 * 3);
    PlaySong(AUDIO_START, AUDIO_SFX_CEREMONIAL_CHIME);
    WaitFrames(60 * 3);
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_WEDDING);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_Ceremony_CarterConductsWeddingKiss);
    TalkClose();
    SetEntityFacing(ENTITY_DOCTOR, FACING_RIGHT);
    SetEntityFacing(ENTITY_ELLI, FACING_LEFT);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_WEDDING_WALK);
    MoveEntityXTo(ENTITY_DOCTOR, X(184), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_DOCTOR);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_WEDDING_IDLE);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_WEDDING_KISS);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WEDDING_KISS);
    WaitFrames(90);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_WEDDING_IDLE);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WEDDING_IDLE);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_WEDDING_WALK);
    MoveEntityXTo(ENTITY_DOCTOR, X(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_DOCTOR);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_WEDDING_IDLE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_DOCTOR, FACING_DOWN);
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
    WaitFrames(60);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_WEDDING_WALK);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WEDDING_WALK);
    MoveEntityYTo(ENTITY_DOCTOR, Y(179), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_ELLI, Y(179), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_DOCTOR);
    WaitForEntityMovement(ENTITY_ELLI);
    SetEntityFacing(ENTITY_HARRIS, FACING_DOWN);
    MoveEntityYTo(ENTITY_DOCTOR, Y(219), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_ELLI, Y(219), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_DOCTOR);
    WaitForEntityMovement(ENTITY_ELLI);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityFacing(ENTITY_STU, FACING_DOWN);
    MoveEntityYTo(ENTITY_DOCTOR, Y(272), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_ELLI, Y(272), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitFrames(60 * 3);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_Ceremony_CarterToastsElliAndDoctor);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
    VarSet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
