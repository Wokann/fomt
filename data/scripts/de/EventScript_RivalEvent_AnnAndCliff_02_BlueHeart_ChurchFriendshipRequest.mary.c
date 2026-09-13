#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterUrgesCliffToOpenUpToTownspeople[] =
        "Cliff, warum sprichst \r\n"
        "du nicht mehr mit den\r\n"
        "Leuten in der Stadt? Sie {Press}\r\n"
        "sind alle sehr nett. {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffSaysNewPeopleAreHardToTalkTo[] =
        "Ich weiß nicht warum, aber\r\n"
        "es ist schwer, mit neuen \r\n"
        "Leuten zu reden.{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterNotesCliffTalksComfortablyWithHim[] =
        "Aber mit mir zu reden, \r\n"
        "macht dir nichts!{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffSaysCarterIsEasyToTalkTo[] =
        "Mit dir zu reden ist \r\n"
        "irgendwie leicht. Du\r\n"
        "bist anders. {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterReflectsOnCliffCallingHimDifferent[] =
        "Anders...?{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnGreetsCarterAndCliff[] =
        "Hallo, Carter! \r\n"
        "Oh, Hi, Cliff! {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterGreetsAnn[] =
        "Hi, Ann. {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffGreetsAnnShyly[] =
        "...Hallo.{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterAsksWhyAnnCameToChurch[] =
        "Ungewöhnlich, dass du\r\n"
        "in die Kirche kommst, Ann.\r\n"
        "Ist irgendetwas?{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnDeliversCartersLunch[] =
        "Hast du Essen bestellt?\r\n"
        "Ich bringe es. {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterApologizesForForgettingLunch[] =
        "Habe ich total vergessen! \r\n"
        "Tut mir Leid. {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnHandsLunchToCarter[] =
        "Bitte sehr. {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnAsksWhyCliffIsAtChurch[] =
        "Was machst du hier, \r\n"
        "Cliff. {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffAvoidsExplainingWhyHeIsAtChurch[] =
        "Öh... nichts Besonderes...{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterReactsToCliffsEvasion[] =
        "Hmm...{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterAsksAnnForAFavor[] =
        "Ann... Ich würde dich \r\n"
        "gern etwas fragen. {Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnAsksWhatFavorCarterNeeds[] =
        "Ja?{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterExplainsCliffHasDifficultyMakingFriends[] =
        "Es geht um Cliff. {Press}\p"
        "Er ist sehr schüchtern,\r\n"
        "er findet schwer Freunde.{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffProtestsCartersExplanation[] =
        "Hey...! Warte mal...{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterAsksAnnToHelpCliffMeetTownspeople[] =
        "Also, hilfst du ihm, neue \r\n"
        "Freunde in der Stadt \r\n"
        "zu finden?{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnAgreesToHelpCliffMakeFriends[] =
        "Kein Problem! \r\n"
        "Das wird mir \r\n"
        "Spaß machen!{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnReturnsToWorkAndSaysGoodbye[] =
        "Ich muss zurück, \r\n"
        "aber bis später. {Press}\p"
        "Tschüss, Carter. \r\n"
        "Tschüss, Cliff.{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterSaysGoodbyeToAnn[] =
        "Tschüss!{Press}";

    const char gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffAwkwardlySaysGoodbyeToAnn[] =
        "...Bis bald...{Press}";
};

void EventScript_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest(void)
{
    ChangeMap(MAP_CHURCH, X(184), Y(136));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(184), Y(320), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ANN, X(172), Y(248), FACING_UP);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_CLIFF, X(196), Y(120), FACING_LEFT);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(172), Y(120), FACING_RIGHT);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
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
    if (GetEntityLocation(ENTITY_POPURI) == MAP_CHURCH)
    {
        HideEntity(ENTITY_POPURI);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterUrgesCliffToOpenUpToTownspeople);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffSaysNewPeopleAreHardToTalkTo);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterNotesCliffTalksComfortablyWithHim);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffSaysCarterIsEasyToTalkTo);
    TalkClose();
    StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterReflectsOnCliffCallingHimDifferent);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
    WaitFrames(60);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(152), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnGreetsCarterAndCliff);
    TalkClose();
    SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
    SetEntityFacing(ENTITY_CLIFF, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterGreetsAnn);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffGreetsAnnShyly);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterAsksWhyAnnCameToChurch);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnDeliversCartersLunch);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterApologizesForForgettingLunch);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnHandsLunchToCarter);
    TalkClose();
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(136), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_GESTURE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(152), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnAsksWhyCliffIsAtChurch);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffAvoidsExplainingWhyHeIsAtChurch);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterReactsToCliffsEvasion);
    TalkClose();
    StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterAsksAnnForAFavor);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnAsksWhatFavorCarterNeeds);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterExplainsCliffHasDifficultyMakingFriends);
    TalkClose();
    StartEntityEffect(ENTITY_CLIFF, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_CLIFF, FACING_LEFT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffProtestsCartersExplanation);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterAsksAnnToHelpCliffMeetTownspeople);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnAgreesToHelpCliffMakeFriends);
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_AnnReturnsToWorkAndSaysGoodbye);
    TalkClose();
    SetEntityFacing(ENTITY_CLIFF, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CarterSaysGoodbyeToAnn);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_CliffAwkwardlySaysGoodbyeToAnn);
    TalkClose();
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
    MoveEntityYTo(ENTITY_ANN, Y(248), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ANN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    HideEntity(ENTITY_ANN);
    WaitFrames(80);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    PanCameraTo(X(184), Y(320), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_CLIFF, EventScript_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_FollowupCliffDialogue);
    SetEntityEventScript(ENTITY_CARTER, EventScript_RivalEvent_AnnAndCliff_02_BlueHeart_ChurchFriendshipRequest_FollowupCarterDialogue);
    VarSet(VAR_ANN_CLIFF_RIVAL_EVENT_2_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    return;
}
