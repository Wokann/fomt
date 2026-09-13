#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonWelcomesPlayer[] =
        "Welcome. {Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_ZackThanksPlayerForVisiting[] =
        "Thank you for your coming. {Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonAdvertisesHighQualityWares[] =
        "I only carry highest quality\r\n"
        "Items. Take your time. {Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_KarenGreetsZack[] =
        "Hi!{Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_ZackRemarksKarenRarelyVisits[] =
        "Hello, Karen. \r\n"
        "Don't see you around\r\n"
        "here very much. {Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_KarenExplainsSheCameFromBeachToSeeShop[] =
        "I was at the beach anyway,\r\n"
        "and wanted to check out\r\n"
        "your new shop. {Press}\p"
        "I'd heard rumors about it. {Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonAdmiresKarensBeauty[] =
        "What a beauty...!!{Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_KarenAsksWonsIdentity[] =
        "Who is this? {Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_ZackHesitatesWhileIntroducingWon[] =
        "Umm...This is...{Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonIntroducesHimselfAsTravelingSalesman[] =
        "My name is Won,\r\n"
        "a travelling salesman.{Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_KarenIntroducesHerself[] =
        "Oh, I've heard about you!\r\n"
        "My name's Karen.{Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonComplimentsKarensName[] =
        "Karen...That's a very \r\n"
        "beautiful name!{Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_KarenAsksToSeeWares[] =
        "Thanks! {Press}\p"
        "Why don't you show\r\n"
        "me what you have!{Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonInvitesKarenToBrowse[] =
        "Good idea!{Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonOrdersPlayerOutOfWay[] =
        "{Player}!\r\n"
        "Get out of my way!{Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonCallsPlayerAnObstructionToBusiness[] =
        "You are an \r\n"
        "obstruction to business!{Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_KarenPraisesInterestingWares[] =
        "You have many \r\n"
        "interesting things!{Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonOffersKarenOneFreeItemDuringGoldenServiceTime[] =
        "You have good taste!\r\n"
        "Right now is golden \r\n"
        "service time,{Press}\r\n"
        "so you can take home \r\n"
        "any one thing for free.{Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_KarenAcceptsFreeItem[] =
        "Really?! Gee, thanks!\r\n"
        "I'll take this.{Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonInvitesKarenToReturn[] =
        "Just come back, OK?{Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_KarenPromisesToReturnAndLeaves[] =
        "I will! Bye now. {Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_ZackConsidersWhatToTakeDuringGoldenServiceTime[] =
        "Golden service time, eh? \r\n"
        "What should I take...?{Press}";

    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonEndsGoldenServiceTimeAndDemandsPayment[] =
        "Golden service time is over!\r\n"
        "You want something, you \r\n"
        "must pay!{Press}";
};

void EventScript_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse(void)
{
    ChangeMap(MAP_ZACK_HOUSE, X(120), Y(141));
    SetEntityPosition(ENTITY_ZACK, X(130), Y(116), FACING_DOWN);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    SetEntityPosition(ENTITY_WON, X(191), Y(141), FACING_LEFT);
    SetEntityAnim(ENTITY_WON, ANIMATION_WON_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(193), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(141), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonWelcomesPlayer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_ZackThanksPlayerForVisiting);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonAdvertisesHighQualityWares);
    TalkClose();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    MoveEntityXTo(ENTITY_PLAYER, X(153), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_KarenGreetsZack);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityPosition(ENTITY_KAREN, X(120), Y(240), FACING_UP);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
    MoveEntityYTo(ENTITY_KAREN, Y(141), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAREN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_ZackRemarksKarenRarelyVisits);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_KarenExplainsSheCameFromBeachToSeeShop);
    TalkClose();
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonAdmiresKarensBeauty);
    TalkClose();
    SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
    StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_KarenAsksWonsIdentity);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_ZackHesitatesWhileIntroducingWon);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonIntroducesHimselfAsTravelingSalesman);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_KarenIntroducesHerself);
    TalkClose();
    StartEntityEffect(ENTITY_WON, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonComplimentsKarensName);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_KarenAsksToSeeWares);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonInvitesKarenToBrowse);
    SetTalkPortrait(TALK_PORTRAIT_WON_ANGRY);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonOrdersPlayerOutOfWay);
    TalkClose();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    MoveEntityYTo(ENTITY_PLAYER, Y(116), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonCallsPlayerAnObstructionToBusiness);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
    SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
    MoveEntityXTo(ENTITY_KAREN, X(153), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAREN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_KarenPraisesInterestingWares);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonOffersKarenOneFreeItemDuringGoldenServiceTime);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_KarenAcceptsFreeItem);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonInvitesKarenToReturn);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_KarenPromisesToReturnAndLeaves);
    TalkClose();
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
    SetEntityFacing(ENTITY_KAREN, FACING_LEFT);
    MoveEntityXTo(ENTITY_KAREN, X(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAREN);
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
    MoveEntityYTo(ENTITY_KAREN, Y(240), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAREN);
    HideEntity(ENTITY_KAREN);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_ZackConsidersWhatToTakeDuringGoldenServiceTime);
    TalkClose();
    WaitFrames(30);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_WonEndsGoldenServiceTimeAndDemandsPayment);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
    StartEntityEffect(ENTITY_ZACK, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    PanCameraTo(X(153), Y(116), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
    WaitForCameraMovement();
    MarkNpcSpokenTo(CHARACTER_WON);
    MarkNpcSpokenTo(CHARACTER_ZACK);
    MarkNpcSpokenTo(CHARACTER_KAREN);
    EnableScriptedNpcControl();
    VarSet(VAR_WON_AND_KAREN_FIRST_MEETING_AT_ZACKS_HOUSE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_WON, EventScript_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_FollowupWonDialogue);
    SetEntityEventScript(ENTITY_ZACK, EventScript_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_FollowupZackDialogue);
}
