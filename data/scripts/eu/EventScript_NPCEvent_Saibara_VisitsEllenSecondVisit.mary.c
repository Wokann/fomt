#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_EllenThanksSaibaraForVisiting[] =
        "Thanks for coming, Sai. {Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_StuGreetsSaibara[] =
        "Hi there, Saibara.{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_SaibaraExplainsDroppingIn[] =
        "I was just passing by, so \r\n"
        "I thought I'd drop in. {Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_EllenInvitesSaibaraAnytime[] =
        "You're welcome any \r\n"
        "time, Sai! {Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_EllenRegretsUnableToVisitDueToLegs[] =
        "I wish I could come visit \r\n"
        "you, but with these legs...\r\n"
        "I can hardely walk!{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_SaibaraFallsSilent[] =
        "........{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_EllenLamentsUnableToGoOutside[] =
        "I can't even go outside\r\n"
        "with these legs!{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_EllenReminiscesAboutWalksTogether[] =
        "I remember when we used to \r\n"
        "take walks to the mountains,\r\n"
        "the beach, and lots of {Press}\r\n"
        "places together...!{Press}\p"
        "Too bad we can't now,\r\n"
        "all because of these \r\n"
        "darned legs of mine!{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_SaibaraPromisesTheyWillWalkAgain[] =
        "Don't say that!\r\n"
        "I'm sure your legs'll get \r\n"
        "better, and we can {Press}\r\n"
        "take our walks again! {Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_EllenThanksSaibaraForEncouragingHer[] =
        "Thanks, Sai...{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_SaibaraAwkwardlyPreparesToLeave[] =
        "It's nothing....\r\n"
        "Err...I guess I'll be \r\n"
        "going, now... {Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_SaibaraNoticesPlayer[] =
        "Oh, {Player}!\r\n"
        "I didn't see you there.\r\n"
        "What are you doing here?{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_StuRemindsSaibaraThisIsHisHome[] =
        "Umm...This is MY house,\r\n"
        "Saibara!{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_SaibaraRealizesMistakeAndLeaves[] =
        "Oh! You're right...\r\n"
        "Sorry...! Bye now...{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenSecondVisit_StuRemarksSaibaraActsStrangely[] =
        "Saibara can be so\r\n"
        "strange sometimes!{Press}";
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
