#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Saibara_VisitsEllenFirstVisit_SaibaraApologizesForRainyDayVisit[] =
        "Sorry, dass ich an einem \r\n"
        "Regentag komme.{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenFirstVisit_EllenWelcomesVisit[] =
        "Du störst doch nicht!{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenFirstVisit_EllenExpressesGladness[] =
        "Ich freue mich, dass\r\n"
        "du kommst, Saibara.{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenFirstVisit_SaibaraEmbarrassedlyExplainsVisit[] =
        "Oh, sag es nicht...\r\n"
        "Ich war nur...äh...\r\n"
        "du weißt schon...{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenFirstVisit_SaibaraNoticesPlayerListening[] =
        "{Player}!\r\n"
        "Wie lange stehst du {Press}\r\n"
        "hier schon!?{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenFirstVisit_StuRevealsPlayerWasPresent[] =
        "Er war die ganze \r\n"
        "Zeit da.{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenFirstVisit_SaibaraAwkwardlyLeaves[] =
        "Hust...Hust...\r\n"
        "Hmm, ich gehe jetzt\r\n"
        "nach Hause. Bis dann, Ellen.{Press}";

    const char gText_NPCEvent_Saibara_VisitsEllenFirstVisit_EllenNoticesSaibarasBlushing[] =
        "Was ist mit Sai los?\r\n"
        "Dein Gesicht ist \r\n"
        "auf einmal so rot!{Press}";
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
