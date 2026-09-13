#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Popuri_AsksKaiForNecklace_PopuriGreetsKai[] =
        "Hi, Kai...{Press}";

    const char gText_NPCEvent_Popuri_AsksKaiForNecklace_KaiObjectsToCookingInterruption[] =
        "Was?\r\n"
        "Weißt du nicht, dass ich\r\n"
        "beim Kochen nicht{Press}\r\n"
        "gestört werden will?{Press}";

    const char gText_NPCEvent_Popuri_AsksKaiForNecklace_PopuriIntroducesRequest[] =
        "Sorry...Aber es gibt etwas,\r\n"
        "das ich möchte...{Press}";

    const char gText_NPCEvent_Popuri_AsksKaiForNecklace_KaiAsksWhatSheWants[] =
        "....Was ist es?{Press}";

    const char gText_NPCEvent_Popuri_AsksKaiForNecklace_PopuriRequestsNecklaceToLookMature[] =
        "Hmm... Bei Saibaira gibt\r\n"
        "es so eine schöne Kette,\r\n"
        "und ich denke, sie lässt{Press}\r\n"
        "mich sehr reif aussehen...{Press}\p"
        "Kaufst du sie mir...?{Press}";

    const char gText_NPCEvent_Popuri_AsksKaiForNecklace_KaiAsksPrice[] =
        "Wie teuer ist sie?{Press}";

    const char gText_NPCEvent_Popuri_AsksKaiForNecklace_PopuriStatesPrice[] =
        "Nur XXXX G!{Press}";

    const char gText_NPCEvent_Popuri_AsksKaiForNecklace_KaiReactsToHighPrice[] =
        "Das ist teuer?!{Press}";

    const char gText_NPCEvent_Popuri_AsksKaiForNecklace_PopuriAsksIfTooExpensive[] =
        "Ist das zu viel...?{Press}";

    const char gText_NPCEvent_Popuri_AsksKaiForNecklace_KaiRefusesExpensivePurchase[] =
        "Auf keinen Fall gebe ich\r\n"
        "das für eine Kette aus!{Press}";

    const char gText_NPCEvent_Popuri_AsksKaiForNecklace_PopuriProtests[] =
        "Aber...{Press}";

    const char gText_NPCEvent_Popuri_AsksKaiForNecklace_KaiFirmlyRefuses[] =
        "Ich sagte NEIN!!...{Press}";

    const char gText_NPCEvent_Popuri_AsksKaiForNecklace_PopuriCriesAndExplainsWantingToLookNiceForKai[] =
        "Ich wollte nur für dich \r\n"
        "besser aussehen!!{Press}\p"
        "Du musst nicht so gemein \r\n"
        "zu mir sein...{Press}\p"
        "Schief, schnief...{Press}";

    const char gText_NPCEvent_Popuri_AsksKaiForNecklace_KaiRelentsAndPromisesNecklace[] =
        "Oh, wein doch nicht!\r\n"
        "OK, ok, ich kaufe sie\r\n"
        "dir später. {Press}";

    const char gText_NPCEvent_Popuri_AsksKaiForNecklace_PopuriThanksKai[] =
        "Danke, Kai!{Press}";

    const char gText_NPCEvent_Popuri_AsksKaiForNecklace_PopuriLeavesForHome[] =
        "Ich gehe jetzt heim...{Press}";

    const char gText_NPCEvent_Popuri_AsksKaiForNecklace_KaiComplainsAboutWomen[] =
        "...Frauen! {Press}";
};

void EventScript_NPCEvent_Popuri_AsksKaiForNecklace(void)
{
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_KAI, X(32), Y(80), FACING_UP);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityPosition(ENTITY_POPURI, X(120), Y(224), FACING_UP);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
    MoveEntityYTo(ENTITY_POPURI, Y(136), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    MoveEntityXTo(ENTITY_PLAYER, X(112), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    WaitForEntityMovement(ENTITY_POPURI);
    PanCameraTo(X(44), Y(80), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    MoveEntityXTo(ENTITY_PLAYER, X(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
    MoveEntityXTo(ENTITY_POPURI, X(136), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityFacing(ENTITY_POPURI, FACING_UP);
    MoveEntityYTo(ENTITY_POPURI, Y(80), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityFacing(ENTITY_POPURI, FACING_LEFT);
    MoveEntityXTo(ENTITY_POPURI, X(56), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_AsksKaiForNecklace_PopuriGreetsKai);
    TalkClose();
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_KAI, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Popuri_AsksKaiForNecklace_KaiObjectsToCookingInterruption);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_AsksKaiForNecklace_PopuriIntroducesRequest);
    TalkClose();
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Popuri_AsksKaiForNecklace_KaiAsksWhatSheWants);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_AsksKaiForNecklace_PopuriRequestsNecklaceToLookMature);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Popuri_AsksKaiForNecklace_KaiAsksPrice);
    TalkClose();
    MoveEntityXTo(ENTITY_POPURI, X(48), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    SetEntityFacing(ENTITY_KAI, FACING_DOWN);
    WaitFrames(10);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_AsksKaiForNecklace_PopuriStatesPrice);
    TalkClose();
    MoveEntityXTo(ENTITY_POPURI, X(56), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    SetEntityFacing(ENTITY_KAI, FACING_RIGHT);
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Popuri_AsksKaiForNecklace_KaiReactsToHighPrice);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_AsksKaiForNecklace_PopuriAsksIfTooExpensive);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Popuri_AsksKaiForNecklace_KaiRefusesExpensivePurchase);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_AsksKaiForNecklace_PopuriProtests);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Popuri_AsksKaiForNecklace_KaiFirmlyRefuses);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_AsksKaiForNecklace_PopuriCriesAndExplainsWantingToLookNiceForKai);
    TalkClose();
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_AFRAID, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Popuri_AsksKaiForNecklace_KaiRelentsAndPromisesNecklace);
    TalkClose();
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_AsksKaiForNecklace_PopuriThanksKai);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    TalkMessage(gText_NPCEvent_Popuri_AsksKaiForNecklace_PopuriLeavesForHome);
    TalkClose();
    SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
    MoveEntityXTo(ENTITY_POPURI, X(144), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
    MoveEntityYTo(ENTITY_POPURI, Y(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityFacing(ENTITY_POPURI, FACING_LEFT);
    MoveEntityXTo(ENTITY_POPURI, X(128), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
    MoveEntityYTo(ENTITY_POPURI, Y(200), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    HideEntity(ENTITY_POPURI);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Popuri_AsksKaiForNecklace_KaiComplainsAboutWomen);
    TalkClose();
    SetEntityFacing(ENTITY_KAI, FACING_UP);
    PanCameraTo(X(120), Y(208), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    VarSet(VAR_POPURI_ASKS_KAI_FOR_NECKLACE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_KAI, EventScript_NPCEvent_Kai_ReflectsOnPopuri);
    return;
}
