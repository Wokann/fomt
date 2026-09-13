#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Ann_Childbirth_DougAwaitsGrandchildBirth[] =
        "Ich kann nicht erwarten, \r\n"
        "dass das Baby kommt!{Press}";

    const char gText_FamilyEvent_Ann_Childbirth_AnnCallsForElliDuringLabor[] =
        "Elli...!\r\n"
        "Bitte hilf mir...{Press}";

    const char gText_FamilyEvent_Ann_Childbirth_ElliEncouragesAnnDuringLabor[] =
        "Du schaffst es!\r\n"
        "Nur noch ein bisschen!{Press}";

    const char gText_FamilyEvent_Ann_Childbirth_DougTellsAnnToStayCalm[] =
        "Beruhige dich!!\r\n"
        "Warum gehst du nicht etwas\r\n"
        "an die frische Luft?{Press}";

    const char gText_FamilyEvent_Ann_Childbirth_AnnFirstLaborCry[] =
        "Es tut so weh!!...{Press}";

    const char gText_FamilyEvent_Ann_Childbirth_AnnSecondLaborCry[] =
        "Aaaah!!{Press}";

    const char gText_FamilyEvent_Ann_Childbirth_DoctorRemarksOnWomensStrength[] =
        "Frauen sind wirklich\r\n"
        "stärker als Männer!...{Press}";

    const char gText_FamilyEvent_Ann_Childbirth_DougCelebratesGrandson[] =
        "Ein Junge! \r\n"
        "Ich freue mich so!{Press}";

    const char gText_FamilyEvent_Ann_Childbirth_ElliAnnouncesHealthyBabyBoy[] =
        "Ein gesunder Junge. \r\n"
        "Du solltest jetzt zu \r\n"
        "Ann gehen.{Press}";

    const char gText_FamilyEvent_Ann_Childbirth_AnnJokesBabyLooksLikeMonkey[] =
        "Er sieht aus wie ein\r\n"
        "Äffchen, aber er ist \r\n"
        "so niedlich!{Press}\p"
        "Wie soll er heißen?{Press}";

    const char gText_FamilyEvent_Ann_Childbirth_AnnApprovesBabyName[] =
        "{Baby}?\r\n"
        "Ich finde, das ist \r\n"
        "ein schöner Name!{Press}";

    const char gText_FamilyEvent_Ann_Childbirth_PlayerReflectsOnFatherhoodAndLoveForAnn[] =
        "Ich bin Vater! Ich\r\n"
        "liebe dich, {Baby}.{Press}";
};

void EventScript_FamilyEvent_Ann_Childbirth(void)
{
    ChangeMap(MAP_FARMHOUSE, X(117), Y(148));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(117), Y(148), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_DOUG, X(117), Y(124), FACING_DOWN);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_ANN_CHILDBIRTH_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(75), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(165), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(117), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    TalkMessage(gText_FamilyEvent_Ann_Childbirth_DougAwaitsGrandchildBirth);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_Childbirth_AnnCallsForElliDuringLabor);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Ann_Childbirth_ElliEncouragesAnnDuringLabor);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    TalkMessage(gText_FamilyEvent_Ann_Childbirth_DougTellsAnnToStayCalm);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(75), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_Childbirth_AnnFirstLaborCry);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(165), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_Childbirth_AnnSecondLaborCry);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(117), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    PlaySong(AUDIO_START, AUDIO_SFX_BABY_CRY);
    WaitFrames(60);
    PlaySong(AUDIO_START, AUDIO_SFX_BABY_CRY);
    WaitFrames(60);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60 * 2);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_FARMHOUSE, X(430), Y(124));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(430), Y(124), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ANN, X(440), Y(mary_negated_int(-48)), FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IN_BED);
    CreatePlayerChildEntity();
    SetEntityPosition(ENTITY_CHILD, X(416), Y(mary_negated_int(-48)), FACING_DOWN);
    SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_NEWBORN);
    SetEntityPosition(ENTITY_DOUG, X(408), Y(124), FACING_RIGHT);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(452), Y(124), FACING_LEFT);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    SetEntityPosition(ENTITY_ELLI, X(430), Y(148), FACING_UP);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_FamilyEvent_Ann_Childbirth_DoctorRemarksOnWomensStrength);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
    TalkMessage(gText_FamilyEvent_Ann_Childbirth_DougCelebratesGrandson);
    TalkClose();
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    TalkMessage(gText_FamilyEvent_Ann_Childbirth_ElliAnnouncesHealthyBabyBoy);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(100), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(60);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_Childbirth_AnnJokesBabyLooksLikeMonkey);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    OpenNameEntry(NAME_ENTRY_CHILD, NAME_ENTRY_SINGLETON_SLOT);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_Childbirth_AnnApprovesBabyName);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_ANN);
    MarkNpcSpokenTo(CHARACTER_DOUG);
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
    MarkNpcSpokenTo(CHARACTER_ELLI);
    AddCharacterLove(CHARACTER_ANN, 3000);
    AddNpcFriendship(CHARACTER_DOUG, 20);
    AddNpcFriendship(CHARACTER_DOCTOR, 20);
    AddNpcFriendship(CHARACTER_ELLI, 20);
    VarSet(VAR_ANN_CHILDBIRTH_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_FamilyEvent_Ann_Childbirth_PlayerReflectsOnFatherhoodAndLoveForAnn);
    TalkClose();
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
