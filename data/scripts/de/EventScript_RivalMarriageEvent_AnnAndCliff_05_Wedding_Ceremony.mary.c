#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_Ceremony_WeddingAnnouncement[] =
        "Ich heirate Ann!\r\n"
        "Sie ist die Einzige, \r\n"
        "die mich glücklich macht.{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_Ceremony_WeddingInvitationAndCoupleDetails[] =
        "Kannst du heute zur \r\n"
        "Hochzeit kommen?{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_Ceremony_CarterInvitesWeddingKiss[] =
        "Du darfst die Braut küssen.{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_Ceremony_GuestsToastNewlyweds[] =
        "Ein Toast auf die \r\n"
        "Frischvermählten! {Press}";
};

void EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_Ceremony(void)
{
    VarSet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
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
    SetEntityPosition(ENTITY_CLIFF, X(228), Y(160), FACING_UP);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_Ceremony_WeddingAnnouncement);
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_Ceremony_WeddingInvitationAndCoupleDetails);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StopBGM();
    ChangeMap(MAP_CHURCH, X(184), Y(160));
    SetEntityPosition(ENTITY_ANN, X(200), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WEDDING_IDLE);
    SetEntityPosition(ENTITY_CLIFF, X(168), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_WEDDING_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(184), Y(120), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(104), Y(195), FACING_RIGHT);
    PreparePlayerForScriptedAnimation();
    SetEntityPosition(ENTITY_MANNA, X(104), Y(155), FACING_RIGHT);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    SetEntityPosition(ENTITY_DUKE, X(72), Y(195), FACING_RIGHT);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(264), Y(155), FACING_LEFT);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    if (GetEntityLocation(ENTITY_JEFF) == MAP_CHURCH)
    {
        HideEntity(ENTITY_JEFF);
    }
    if (GetEntityLocation(ENTITY_DOCTOR) == MAP_CHURCH)
    {
        HideEntity(ENTITY_DOCTOR);
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
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_Ceremony_CarterInvitesWeddingKiss);
    TalkClose();
    SetEntityFacing(ENTITY_CLIFF, FACING_RIGHT);
    SetEntityFacing(ENTITY_ANN, FACING_LEFT);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_WEDDING_WALK);
    MoveEntityXTo(ENTITY_CLIFF, X(184), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_CLIFF);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_WEDDING_IDLE);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_WEDDING_KISS);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WEDDING_KISS);
    WaitFrames(90);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_WEDDING_IDLE);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WEDDING_IDLE);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_WEDDING_WALK);
    MoveEntityXTo(ENTITY_CLIFF, X(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_CLIFF);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_WEDDING_IDLE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_CLIFF, FACING_DOWN);
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
    WaitFrames(60);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_WEDDING_WALK);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WEDDING_WALK);
    MoveEntityYTo(ENTITY_CLIFF, Y(179), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_ANN, Y(179), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_CLIFF);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityFacing(ENTITY_MANNA, FACING_DOWN);
    SetEntityFacing(ENTITY_DOUG, FACING_DOWN);
    MoveEntityYTo(ENTITY_CLIFF, Y(219), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_ANN, Y(219), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_CLIFF);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityFacing(ENTITY_DUKE, FACING_DOWN);
    MoveEntityYTo(ENTITY_CLIFF, Y(272), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_ANN, Y(272), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitFrames(60 * 3);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_Ceremony_GuestsToastNewlyweds);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_CLIFF);
    VarSet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
