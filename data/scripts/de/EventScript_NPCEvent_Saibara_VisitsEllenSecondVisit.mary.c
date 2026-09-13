#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_EllenThanksSaibaraForVisiting[] =
        "Danke für den Besuch, Sai.{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_StuGreetsSaibara[] =
        "Hi, Saibara.{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_SaibaraExplainsDroppingIn[] =
        "Ich kam gerade vorbei und  \r\n"
        "dachte, ich schau mal rein. {Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_EllenInvitesSaibaraAnytime[] =
        "Du bist jederzeit \r\n"
        "willkommen, Sai! {Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_EllenRegretsUnableToVisitDueToLegs[] =
        "Ich wünschte, ich könnte\r\n"
        "dich besuchen, aber mit\r\n"
        "diesen Beinen...{Press}\r\n"
        "ich kann kaum laufen!{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_SaibaraFallsSilent[] =
        "........{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_EllenLamentsUnableToGoOutside[] =
        "Ich kann nicht einmal\r\n"
        "nach draußen gehen!{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_EllenReminiscesAboutWalksTogether[] =
        "Ich weiß noch, wie wir in\r\n"
        "den Bergen gelaufen sind\r\n"
        "und am Strand und an {Press}\r\n"
        "vielen anderen Orten...!{Press}\p"
        "Zu schade, dass das\r\n"
        "wegen dieser dummen \r\n"
        "Beine vorbei ist!{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_SaibaraPromisesTheyWillWalkAgain[] =
        "Sag das nicht!\r\n"
        "Ich bin sicher, deine \r\n"
        "Beine werden wieder {Press}\r\n"
        "besser und wir \r\n"
        "laufen wieder zusammen! {Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_EllenThanksSaibaraForEncouragingHer[] =
        "Danke, Sai...{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_SaibaraAwkwardlyPreparesToLeave[] =
        "Es ist nichts....\r\n"
        "Ähm...Ich denke, ich gehe\r\n"
        "jetzt mal... {Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_SaibaraNoticesPlayer[] =
        "Oh, {Player}!\r\n"
        "Ich habe dich nicht gesehen.\r\n"
        "Was möchtest du?{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_StuRemindsSaibaraThisIsHisHome[] =
        "Hmm...Das ist MEIN\r\n"
        "Haus, Saibara!{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_SaibaraRealizesMistakeAndLeaves[] =
        "Oh! Du hast Recht...\r\n"
        "Sorry...! Tschüss...{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_StuRemarksSaibaraActsStrangely[] =
        "Saibara kann manchmal\r\n"
        "so komisch sein!{Press}";
};

void EventScript_NPCEvent_Saibara_VisitsEllenSecondVisit(void)
{
    ChangeMap(MAP_ELLEN_HOUSE, X(84), Y(156));
    SetEntityPosition(ENTITY_ELLEN, X(128), Y(96), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLEN, ANIMATION_ELLEN_IDLE);
    SetEntityPosition(ENTITY_SAIBARA, X(128), Y(240), FACING_UP);
    SetEntityAnim(ENTITY_SAIBARA, ANIMATION_SAIBARA_IDLE);
    SetEntityPosition(ENTITY_STU, X(176), Y(118), FACING_LEFT);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(84), Y(156), FACING_RIGHT);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
    SetEntityAnim(ENTITY_SAIBARA, ANIMATION_SAIBARA_WALK);
    MoveEntityYTo(ENTITY_SAIBARA, Y(118), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_SAIBARA);
    SetEntityAnim(ENTITY_SAIBARA, ANIMATION_SAIBARA_IDLE);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenSecondVisit_EllenThanksSaibaraForVisiting);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenSecondVisit_StuGreetsSaibara);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SAIBARA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SAIBARA);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenSecondVisit_SaibaraExplainsDroppingIn);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenSecondVisit_EllenInvitesSaibaraAnytime);
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_AFRAID);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenSecondVisit_EllenRegretsUnableToVisitDueToLegs);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SAIBARA);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenSecondVisit_SaibaraFallsSilent);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenSecondVisit_EllenLamentsUnableToGoOutside);
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenSecondVisit_EllenReminiscesAboutWalksTogether);
    TalkClose();
    StartEntityEffect(ENTITY_SAIBARA, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SAIBARA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SAIBARA);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenSecondVisit_SaibaraPromisesTheyWillWalkAgain);
    TalkClose();
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenSecondVisit_EllenThanksSaibaraForEncouragingHer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SAIBARA);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenSecondVisit_SaibaraAwkwardlyPreparesToLeave);
    TalkClose();
    SetEntityFacing(ENTITY_SAIBARA, FACING_LEFT);
    StartEntityEffect(ENTITY_SAIBARA, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SAIBARA);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenSecondVisit_SaibaraNoticesPlayer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenSecondVisit_StuRemindsSaibaraThisIsHisHome);
    TalkClose();
    StartEntityEffect(ENTITY_SAIBARA, ENTITY_EMOTE_AFRAID, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SAIBARA);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenSecondVisit_SaibaraRealizesMistakeAndLeaves);
    TalkClose();
    SetEntityAnim(ENTITY_SAIBARA, ANIMATION_SAIBARA_WALK);
    SetEntityFacing(ENTITY_SAIBARA, FACING_DOWN);
    MoveEntityYTo(ENTITY_SAIBARA, Y(240), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_SAIBARA);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    HideEntity(ENTITY_SAIBARA);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenSecondVisit_StuRemarksSaibaraActsStrangely);
    TalkClose();
    WaitFrames(30);
    VarSet(VAR_SAIBARA_VISITS_ELLEN_EVENT_2_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    MarkNpcSpokenTo(CHARACTER_SAIBARA);
    AddNpcFriendship(CHARACTER_ELLEN, 20);
    AddNpcFriendship(CHARACTER_SAIBARA, 20);
    AddNpcFriendship(CHARACTER_STU, 20);
}
