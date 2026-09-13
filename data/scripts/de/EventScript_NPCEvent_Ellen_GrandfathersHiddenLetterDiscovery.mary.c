#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliGreetsPlayer[] =
        "Hi, <playname>!{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_StuGreetsPlayerEnthusiastically[] =
        "Jippie! Es ist {Player}!{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenInvitesPlayerToStay[] =
        "Danke fürs Kommen. Bleib\r\n"
        "doch ein bisschen. {Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliAsksAboutFarmWork[] =
        "Die Farm hält\r\n"
        "dich auf Trab?{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenAdmiresPlayerRunningFarmAlone[] =
        "Eine Farm zu führen \r\n"
        "ist nicht so einfach.\r\n"
        "Ich bewundere den, der{Press}\r\n"
        "das allein schafft!{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliSaysSheCanLearnFromPlayer[] =
        "Ich könnte etwas von\r\n"
        "dir lernen, wirklich.{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenPraisesElliStudyingMedicineOnDayOff[] =
        "Elli arbeitet auch hart. {Press}\p"
        "Es ist ihr freier Tag, aber\r\n"
        "sie studiert trotzdem \r\n"
        "ein Medizinbuch. {Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_StuPraisesHisSister[] =
        "Fleißiges Mädel. {Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliModestlyDismissesPraise[] =
        "Ist doch nichts, echt...{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliRemembersBookToReturnToDoctor[] =
        "Oh ja! Ich habe vergessen,\r\n"
        "dem Doktor das Buch \r\n"
        "zurückzugeben!{Press}\p"
        "Wo habe ich es nur...?{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliFindsLetterInsideMedicalBook[] =
        "Es war auf diesem Regal...\r\n"
        "Oh, hier ist es! Hm?{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenAsksWhatElliFound[] =
        "Was ist los?{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliExplainsLetterIsAddressedToEllen[] =
        "Als ich das Buch rausnahm,\r\n"
        "fiel dieser Brief heraus!{Press}\p"
        "Er ist an dich \r\n"
        "adressiert, Großmutter!{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenReactsInSurprise[] =
        "Was?{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliIdentifiesLetterFromGrandfather[] =
        "Er ist von deinem Großvater!{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_StuReactsToGrandfathersLetter[] =
        "Echt?!{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliAsksEllenToReadLetter[] =
        "Was steht drin?{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenBeginsReadingLetter[] =
        "Gucken wir mal...{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_GrandfathersHiddenLetterWrittenOnEllisBirthDay[] =
        "Liebe Ellen, \r\n"
        "ich schreibe dir an dem \r\n"
        "Tag, an dem deine Enkelin \r\n"
        "Elli geboren wurde. \r\n"
        "Ich bin wirklich froh \r\n"
        "und glücklich, dich zur\r\n"
        "Frau zu haben. VIELEN DANK!\r\n"
        "Wann wirst du diesen Brief \r\n"
        "lesen? Ich schäme mich zu\r\n"
        "sehr, um ihn dir direkt zu\r\n"
        "geben, ich lasse ihn hier.\r\n"
        "Bitte, selbst wenn du ihn \r\n"
        "findest, sag mir nichts\r\n"
        "davon.{Press}\p"
        "Es wäre mir unangenehm!{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_ElliLearnsLetterWasWrittenOnHerBirthDay[] =
        "Ich fasse nicht, dass er\r\n"
        "dies an meinem \r\n"
        "Geburtstag geschrieben hat!{Press}\p"
        "Warum hat er ihn dir\r\n"
        "nicht gegeben, Großmutter?{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_EllenTreasuresLateHusbandsWrittenFeelings[] =
        "Er war sehr schüchtern und\r\n"
        "schämte sich leicht. {Press}\p"
        "Ich kann nicht glauben, \r\n"
        "dass er seine Gefühle \r\n"
        "so aufgeschrieben hat!{Press}\r\n"
        "Er ist nun im Himmel, \r\n"
        "also hüte ich dies...{Press}";
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
