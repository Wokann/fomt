#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Cliff_CollapsesInSnow_CliffMurmursAboutDayHeLeftHometown[] =
        "Wenn es schneit, denke ich\r\n"
        "immer an den Tag, an dem ich\r\n"
        "mein Zuhause verlassen habe.{Press}\r\n"
        "Es hat auch damals \r\n"
        "geschneit.{Press}";

    const char gText_NPCEvent_Cliff_CollapsesInSnow_AnnGreetsPlayerOnSnowyDay[] =
        "Hallo. Verschneiter Tag,\r\n"
        "nicht wahr?{Press}";

    const char gText_NPCEvent_Cliff_CollapsesInSnow_AnnRecognizesCollapsedCliff[] =
        "Was? Cliff--?{Press}";

    const char gText_NPCEvent_Cliff_CollapsesInSnow_AnnCallsDougForHelp[] =
        "Papa! Komm schnell! \r\n"
        "Es ist Cliff!!{Press}";

    const char gText_NPCEvent_Cliff_CollapsesInSnow_DoctorThanksPlayerForFindingCliffBeforeTooLate[] =
        "Gott sei Dank\r\n"
        "bist du vorbeigekommen, \r\n"
        "{Player}. {Press}";

    const char gText_NPCEvent_Cliff_CollapsesInSnow_CarterRelievedCliffIsSafeAndAsksCause[] =
        "Gott sei Dank ist er ok!\r\n"
        "Was hat er da gemacht?{Press}";

    const char gText_NPCEvent_Cliff_CollapsesInSnow_AnnThanksPlayerForSavingCliff[] =
        "Ganz vielen Dank.{Press}";

    const char gText_NPCEvent_Cliff_CollapsesInSnow_DoctorSaysCliffNeedsRest[] =
        "Etwas Ruhe und er \r\n"
        "sollte ok sein. {Press}\r\n"
        "Alle sollten jetzt \r\n"
        "nach Hause gehen.{Press}";
};

void EventScript_NPCEvent_Cliff_CollapsesInSnow(void)
{
    ChangeMap(MAP_ROSE_SQUARE, X(220), Y(225));
    StopAllSongs();
    SetEntityPosition(ENTITY_CLIFF, X(220), Y(163), FACING_DOWN);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(220), Y(432), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60 * 2);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_WALK);
    MoveEntityYTo(ENTITY_CLIFF, Y(194), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_CLIFF);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
    WaitFrames(60 * 2);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_WALK);
    MoveEntityYTo(ENTITY_CLIFF, Y(223), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_CLIFF);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
    WaitFrames(60 * 2);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_COLLAPSE_FORWARD);
    WaitFrames(60);
    PanCameraTo(X(220), Y(284), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
    WaitForCameraMovement();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_PLAYER, Y(303), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_RUN_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_PLAYER, Y(256), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_COLLAPSED);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_NPCEvent_Cliff_CollapsesInSnow_CliffMurmursAboutDayHeLeftHometown);
    TalkClose();
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    SetPlayerHeldArticle(ITEM_ARTICLE_PHOTO);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_INN_1F, X(184), Y(274));
    SetEntityPosition(ENTITY_ANN, X(185), Y(257), FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(239), Y(225), FACING_RIGHT);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(143), Y(235), FACING_LEFT);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(185), Y(281), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_ANN);
    }
    TalkMessage(gText_NPCEvent_Cliff_CollapsesInSnow_AnnGreetsPlayerOnSnowyDay);
    SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
    TalkMessage(gText_NPCEvent_Cliff_CollapsesInSnow_AnnRecognizesCollapsedCliff);
    TalkClose();
    SetEntityFacing(ENTITY_ANN, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_NPCEvent_Cliff_CollapsesInSnow_AnnCallsDougForHelp);
    TalkClose();
    StartEntityEffect(ENTITY_DOUG, ENTITY_EMOTE_EXCLAMATION, FALSE);
    StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    SetEntityFacing(ENTITY_DOUG, FACING_DOWN);
    SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
    WaitFrames(60);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_MINERAL_CLINIC_1F, X(245), Y(124));
    SetEntityPosition(ENTITY_DOCTOR, X(244), Y(86), FACING_DOWN);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(216), Y(86), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(221), Y(127), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    SetEntityPosition(ENTITY_ANN, X(246), Y(127), FACING_UP);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(266), Y(127), FACING_UP);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_NPCEvent_Cliff_CollapsesInSnow_DoctorThanksPlayerForFindingCliffBeforeTooLate);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Cliff_CollapsesInSnow_CarterRelievedCliffIsSafeAndAsksCause);
    TalkClose();
    SetEntityFacing(ENTITY_ANN, FACING_LEFT);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_ANN);
    }
    TalkMessage(gText_NPCEvent_Cliff_CollapsesInSnow_AnnThanksPlayerForSavingCliff);
    TalkClose();
    WaitFrames(60 * 2);
    SetEntityFacing(ENTITY_ANN, FACING_UP);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_NPCEvent_Cliff_CollapsesInSnow_DoctorSaysCliffNeedsRest);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    AddNpcFriendship(CHARACTER_DOCTOR, 20);
    AddNpcFriendship(CHARACTER_DOUG, 20);
    AddNpcFriendship(CHARACTER_CARTER, 20);
    AddCharacterLove(CHARACTER_ANN, 3000);
    HideEntity(ENTITY_DOCTOR);
    HideEntity(ENTITY_DOUG);
    HideEntity(ENTITY_CARTER);
    HideEntity(ENTITY_ANN);
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
    MarkNpcSpokenTo(CHARACTER_DOUG);
    MarkNpcSpokenTo(CHARACTER_CARTER);
    MarkNpcSpokenTo(CHARACTER_ANN);
    ChangeMap(MAP_NORTH_SIDE_TOWN, X(856), Y(168));
    SetEntityPosition(ENTITY_PLAYER, X(856), Y(168), FACING_DOWN);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    VarSet(VAR_CLIFF_COLLAPSES_IN_SNOW_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    VarSet(VAR_CLIFF_COLLAPSE_FOLLOWUP_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetGameTime(16, 0);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
}
