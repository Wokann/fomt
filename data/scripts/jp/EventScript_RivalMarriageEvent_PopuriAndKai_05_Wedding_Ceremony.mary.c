#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_Ceremony_WeddingAnnouncement[] =
        "よぉ、\r\n"
        "今から結婚式なんだよ。{Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_Ceremony_WeddingInvitationAndCoupleDetails[] =
        "だれのって、\r\n"
        "オレとポプリに決まってん\r\n"
        "じゃん。{Press}\p"
        "リックから聞いてない？\r\n"
        "今日、これから。\r\n"
        "ほら、早くいこーぜ。{Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_Ceremony_CarterInvitesWeddingKiss[] =
        "では、ちかいのキスを…{Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_Ceremony_GuestsToastNewlyweds[] =
        "わかい２人にカンパイ！！{Press}";
};

void EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_Ceremony(void)
{
    VarSet(VAR_POPURI_KAI_WEDDING_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
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
    SetEntityPosition(ENTITY_KAI, X(228), Y(160), FACING_UP);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_Ceremony_WeddingAnnouncement);
    SetTalkPortrait(TALK_PORTRAIT_KAI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_Ceremony_WeddingInvitationAndCoupleDetails);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StopBGM();
    ChangeMap(MAP_CHURCH, X(184), Y(160));
    SetEntityPosition(ENTITY_POPURI, X(200), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WEDDING_IDLE);
    SetEntityPosition(ENTITY_KAI, X(168), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WEDDING_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(184), Y(120), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(104), Y(195), FACING_RIGHT);
    PreparePlayerForScriptedAnimation();
    SetEntityPosition(ENTITY_LILLIA, X(264), Y(155), FACING_LEFT);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
    SetEntityPosition(ENTITY_KAREN, X(296), Y(195), FACING_LEFT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_RICK, X(264), Y(195), FACING_LEFT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    if (GetEntityLocation(ENTITY_CLIFF) == MAP_CHURCH)
    {
        HideEntity(ENTITY_CLIFF);
    }
    if (GetEntityLocation(ENTITY_JEFF) == MAP_CHURCH)
    {
        HideEntity(ENTITY_JEFF);
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
    TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_Ceremony_CarterInvitesWeddingKiss);
    TalkClose();
    SetEntityFacing(ENTITY_KAI, FACING_RIGHT);
    SetEntityFacing(ENTITY_POPURI, FACING_LEFT);
    WaitFrames(60);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WEDDING_WALK);
    MoveEntityXTo(ENTITY_KAI, X(184), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAI);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WEDDING_IDLE);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WEDDING_KISS);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WEDDING_KISS);
    WaitFrames(90);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WEDDING_IDLE);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WEDDING_IDLE);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WEDDING_WALK);
    MoveEntityXTo(ENTITY_KAI, X(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAI);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WEDDING_IDLE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_KAI, FACING_DOWN);
    SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
    WaitFrames(60);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WEDDING_WALK);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WEDDING_WALK);
    MoveEntityYTo(ENTITY_KAI, Y(179), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_POPURI, Y(179), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAI);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityFacing(ENTITY_LILLIA, FACING_DOWN);
    MoveEntityYTo(ENTITY_KAI, Y(219), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_POPURI, Y(219), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAI);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
    SetEntityFacing(ENTITY_RICK, FACING_DOWN);
    MoveEntityYTo(ENTITY_KAI, Y(272), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_POPURI, Y(272), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitFrames(60 * 3);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_Ceremony_GuestsToastNewlyweds);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_KAI);
    VarSet(VAR_POPURI_KAI_WEDDING_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
