#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliGreetsPlayer[] =
        "Hi, <playname>!{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_StuGreetsPlayerEnthusiastically[] =
        "Yay!! It's {Player}!{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenInvitesPlayerToStay[] =
        "Thanks for coming. Stick\r\n"
        "around for a while. {Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliAsksAboutFarmWork[] =
        "Is the farm keeping\r\n"
        "you busy?{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenAdmiresPlayerRunningFarmAlone[] =
        "It's not easy running a \r\n"
        "farm. I admire someone \r\n"
        "who can do it alone!{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliSaysSheCanLearnFromPlayer[] =
        "I could take a lesson\r\n"
        "from you, yes I could.{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenPraisesElliStudyingMedicineOnDayOff[] =
        "Elli's working hard, too. {Press}\p"
        "It's her day off, but she's\r\n"
        "studying a medical textbook\r\n"
        "even so. {Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_StuPraisesHisSister[] =
        "Quite a sister, she is. {Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliModestlyDismissesPraise[] =
        "It's nothing, really...{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliRemembersBookToReturnToDoctor[] =
        "Oh yeah! I forgot to return\r\n"
        "that book to the Doctor!{Press}\p"
        "Where did I put it...?{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliFindsLetterInsideMedicalBook[] =
        "It was on this shelf...\r\n"
        "Oh, here it is! Hmm?{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenAsksWhatElliFound[] =
        "What's wrong?{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliExplainsLetterIsAddressedToEllen[] =
        "When I took the book out,\r\n"
        "a letter came out with it!{Press}\p"
        "It's addressed to you, \r\n"
        "Grandma!{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenReactsInSurprise[] =
        "What?{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliIdentifiesLetterFromGrandfather[] =
        "It's from your Grandpa!{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_StuReactsToGrandfathersLetter[] =
        "Really?!{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliAsksEllenToReadLetter[] =
        "What's it say? {Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenBeginsReadingLetter[] =
        "Let's see...{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_GrandfathersHiddenLetterWrittenOnEllisBirthDay[] =
        "Dear Ellen,\r\n"
        "I am writing this on the \r\n"
        "day our granddaughter Elli\r\n"
        "is born. \r\n"
        "I am truly happy, and \r\n"
        "blessed to have you as \r\n"
        "my wife. Thank you. \r\n"
        "When will you read this\r\n"
        "letter? I'm too embarrassed\r\n"
        "to give it to you directly,\r\n"
        "so I'll just hide it here.\r\n"
        "Please, even if you do \r\n"
        "come across this, don't\r\n"
        "tell me you found it.\r\n"
        "It'll be too embarrassing!{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliLearnsLetterWasWrittenOnHerBirthDay[] =
        "I can't believe he wrote\r\n"
        "this the day I was born!...{Press}\p"
        "Why didn't he give this\r\n"
        "to you then, Grandma?{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenTreasuresLateHusbandsWrittenFeelings[] =
        "He was very shy and \r\n"
        "easily embarrassed. {Press}\p"
        "I can't believe he even \r\n"
        "wrote out his feelings \r\n"
        "like he did!{Press}\r\n"
        "He's in heaven now, so \r\n"
        "I'll treasure this...{Press}";
};

void EventScript_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery(void)
{
    ChangeMap(MAP_ELLEN_HOUSE, X(129), Y(120));
    SetEntityPosition(ENTITY_ELLEN, X(128), Y(96), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLEN, ANIMATION_ELLEN_IDLE);
    SetEntityPosition(ENTITY_ELLI, X(150), Y(96), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_STU, X(185), Y(103), FACING_LEFT);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(129), Y(120), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_ELLI);
    }
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliGreetsPlayer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_StuGreetsPlayerEnthusiastically);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenInvitesPlayerToStay);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_ELLI);
    }
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliAsksAboutFarmWork);
    TalkClose();
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
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenAdmiresPlayerRunningFarmAlone);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliSaysSheCanLearnFromPlayer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenPraisesElliStudyingMedicineOnDayOff);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_StuPraisesHisSister);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliModestlyDismissesPraise);
    TalkClose();
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliRemembersBookToReturnToDoctor);
    TalkClose();
    SetEntityFacing(ENTITY_ELLI, FACING_UP);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
    MoveEntityYTo(ENTITY_ELLI, Y(68), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ELLI);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliFindsLetterInsideMedicalBook);
    TalkClose();
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenAsksWhatElliFound);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliExplainsLetterIsAddressedToEllen);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenReactsInSurprise);
    TalkClose();
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
    MoveEntityYTo(ENTITY_ELLI, Y(96), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ELLI);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityFacing(ENTITY_ELLI, FACING_LEFT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_GESTURE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliIdentifiesLetterFromGrandfather);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_StuReactsToGrandfathersLetter);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliAsksEllenToReadLetter);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenBeginsReadingLetter);
    TalkClose();
    TalkOpen();
    TalkMessageSlow(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_GrandfathersHiddenLetterWrittenOnEllisBirthDay);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliLearnsLetterWasWrittenOnHerBirthDay);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenTreasuresLateHusbandsWrittenFeelings);
    TalkClose();
    AddNpcFriendship(CHARACTER_STU, 20);
    AddNpcFriendship(CHARACTER_ELLI, 20);
    AddNpcFriendship(CHARACTER_ELLEN, 20);
    MarkNpcSpokenTo(CHARACTER_STU);
    MarkNpcSpokenTo(CHARACTER_ELLI);
    MarkNpcSpokenTo(CHARACTER_ELLEN);
    EnableScriptedNpcControl();
    VarSet(VAR_ELLEN_GRANDFATHERS_HIDDEN_LETTER_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_ELLEN, EventScript_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_FollowupEllenDialogue);
    SetEntityEventScript(ENTITY_ELLI, EventScript_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_FollowupElliDialogue);
    SetEntityEventScript(ENTITY_STU, EventScript_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_FollowupStuDialogue);
}
