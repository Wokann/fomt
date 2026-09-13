#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_Ceremony_WeddingAnnouncement[] =
        "Karen und ich  \r\n"
        "heiraten.{Press}\p"
        "Wir sind schon ewig\r\n"
        "zusammen, also ändert\r\n"
        "sich nicht so viel! {Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_Ceremony_WeddingInvitationAndCoupleDetails[] =
        "Unsere Hochzeit ist heute.\r\n"
        "Hoffe, ich sehe dich da.{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_Ceremony_CarterPronouncesCoupleMarried[] =
        "Du darfst die Braut küssen.{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_Ceremony_GuestsCongratulateNewlyweds[] =
        "Ein Toast auf die \r\n"
        "Frischvermählten! {Press}";
};

void EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_Ceremony(void)
{
    VarSet(VAR_RICK_KAREN_WEDDING_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
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
    SetEntityPosition(ENTITY_RICK, X(228), Y(160), FACING_UP);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_Ceremony_WeddingAnnouncement);
    SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_Ceremony_WeddingInvitationAndCoupleDetails);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StopBGM();
    ChangeMap(MAP_CHURCH, X(184), Y(160));
    SetEntityPosition(ENTITY_KAREN, X(200), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WEDDING_IDLE);
    SetEntityPosition(ENTITY_RICK, X(168), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WEDDING_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(184), Y(120), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(104), Y(195), FACING_RIGHT);
    PreparePlayerForScriptedAnimation();
    SetEntityPosition(ENTITY_LILLIA, X(104), Y(155), FACING_RIGHT);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
    SetEntityPosition(ENTITY_JEFF, X(296), Y(155), FACING_LEFT);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(264), Y(155), FACING_LEFT);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    if (GetEntityLocation(ENTITY_CLIFF) == MAP_CHURCH)
    {
        HideEntity(ENTITY_CLIFF);
    }
    if (GetEntityLocation(ENTITY_DOCTOR) == MAP_CHURCH)
    {
        HideEntity(ENTITY_DOCTOR);
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
    TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_Ceremony_CarterPronouncesCoupleMarried);
    TalkClose();
    SetEntityFacing(ENTITY_RICK, FACING_RIGHT);
    SetEntityFacing(ENTITY_KAREN, FACING_LEFT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WEDDING_WALK);
    MoveEntityXTo(ENTITY_RICK, X(184), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_RICK);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WEDDING_IDLE);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WEDDING_KISS);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WEDDING_KISS);
    WaitFrames(90);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WEDDING_IDLE);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WEDDING_IDLE);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WEDDING_WALK);
    MoveEntityXTo(ENTITY_RICK, X(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_RICK);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WEDDING_IDLE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_RICK, FACING_DOWN);
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
    WaitFrames(60);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WEDDING_WALK);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WEDDING_WALK);
    MoveEntityYTo(ENTITY_RICK, Y(179), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_KAREN, Y(179), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_RICK);
    WaitForEntityMovement(ENTITY_KAREN);
    SetEntityFacing(ENTITY_LILLIA, FACING_DOWN);
    SetEntityFacing(ENTITY_JEFF, FACING_DOWN);
    SetEntityFacing(ENTITY_SASHA, FACING_DOWN);
    MoveEntityYTo(ENTITY_RICK, Y(219), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_KAREN, Y(219), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_RICK);
    WaitForEntityMovement(ENTITY_KAREN);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    MoveEntityYTo(ENTITY_RICK, Y(272), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_KAREN, Y(272), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitFrames(60 * 3);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_Ceremony_GuestsCongratulateNewlyweds);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_RICK);
    VarSet(VAR_RICK_KAREN_WEDDING_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
