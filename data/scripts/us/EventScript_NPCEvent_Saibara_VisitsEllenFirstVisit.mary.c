#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Saibara_VisitsEllenFirstVisit_SaibaraApologizesForRainyDayVisit[] =
        "Sorry to come on such a \r\n"
        "rainy day.{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenFirstVisit_EllenWelcomesVisit[] =
        "It's no bother at all!{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenFirstVisit_EllenExpressesGladness[] =
        "I'm just glad to have you\r\n"
        "come visit, Saibara.{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenFirstVisit_SaibaraEmbarrassedlyExplainsVisit[] =
        "Oh, don't mention it...\r\n"
        "I was just...err...\r\n"
        "you know...{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenFirstVisit_SaibaraNoticesPlayerListening[] =
        ".......\r\n"
        "{Player}!\r\n"
        "How long have you been {Press}\r\n"
        "standing there!?{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenFirstVisit_StuRevealsPlayerWasPresent[] =
        "He was here the\r\n"
        "whole time.{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenFirstVisit_SaibaraAwkwardlyLeaves[] =
        "Cough...cough...\r\n"
        "Well, I'll be getting home\r\n"
        "now. Good day, Ellen.{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenFirstVisit_EllenNoticesSaibarasBlushing[] =
        "What’s wrong with Sai?\r\n"
        "Your face got all red \r\n"
        "suddenly!{Press}";
};

void EventScript_NPCEvent_Saibara_VisitsEllenFirstVisit(void)
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
    SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SAIBARA);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenFirstVisit_SaibaraApologizesForRainyDayVisit);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenFirstVisit_EllenWelcomesVisit);
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenFirstVisit_EllenExpressesGladness);
    TalkClose();
    StartEntityEffect(ENTITY_SAIBARA, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SAIBARA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SAIBARA);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenFirstVisit_SaibaraEmbarrassedlyExplainsVisit);
    TalkClose();
    WaitFrames(60);
    SetEntityFacing(ENTITY_SAIBARA, FACING_LEFT);
    StartEntityEffect(ENTITY_SAIBARA, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SAIBARA);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenFirstVisit_SaibaraNoticesPlayerListening);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenFirstVisit_StuRevealsPlayerWasPresent);
    TalkClose();
    StartEntityEffect(ENTITY_SAIBARA, ENTITY_EMOTE_AFRAID, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_SAIBARA, FACING_UP);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SAIBARA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SAIBARA);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenFirstVisit_SaibaraAwkwardlyLeaves);
    TalkClose();
    SetEntityAnim(ENTITY_SAIBARA, ANIMATION_SAIBARA_WALK);
    SetEntityFacing(ENTITY_SAIBARA, FACING_DOWN);
    MoveEntityYTo(ENTITY_SAIBARA, Y(240), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_SAIBARA);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    HideEntity(ENTITY_SAIBARA);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Saibara_VisitsEllenFirstVisit_EllenNoticesSaibarasBlushing);
    TalkClose();
    WaitFrames(30);
    VarSet(VAR_SAIBARA_VISITS_ELLEN_EVENT_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    MarkNpcSpokenTo(CHARACTER_SAIBARA);
    AddNpcFriendship(CHARACTER_ELLEN, 20);
    AddNpcFriendship(CHARACTER_SAIBARA, 20);
    AddNpcFriendship(CHARACTER_STU, 20);
}
