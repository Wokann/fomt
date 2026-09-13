#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Karen_ComfortsLonelyRick_RickBroodsAboutFamily[] =
        "Hmmm.....{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_KarenAsksWhyRickIsDown[] =
        "Was ist los, Rick?\r\n"
        "Du siehst geknickt aus...{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_RickWondersWhenRodWillReturn[] =
        "Ich frage mich nur, wann\r\n"
        "mein Vater zurückkommt...{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_KarenNotesRodsConstantTravel[] =
        "Er reist die ganze Zeit,\r\n"
        "oder? Ich habe ihn überhaupt\r\n"
        "nur ein paar Mal gesehen.{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_RickFeelsAloneAfterPopurisMarriage[] =
        "Popuri ist verheiratet und\r\n"
        "lebt nicht mehr hier...{Press}\p"
        "Ich sorge mich um den Laden.{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_KarenPromisesToHelpAtStore[] =
        "Keine Sorge! Du vergisst\r\n"
        "mich!{Press}\p"
        "Ich werde mehr arbeiten, als\r\n"
        "es Popuri je getan hat!{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_RickThanksKarenForHerSupport[] =
        "Oh, Karen... Danke!{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_KarenSaysSpousesSupportEachOther[] =
        "Nichts zu danken!\r\n"
        "Wir sind verheiratet, oder?\r\n"
        "Dafür bin ich da.{Press}";
};

void EventScript_NPCEvent_Karen_ComfortsLonelyRick(void)
{
    EnableScriptedNpcControl();
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_KAREN, X(120), Y(80), FACING_RIGHT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_RICK, X(144), Y(80), FACING_LEFT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(120), Y(112), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    MoveEntityYTo(ENTITY_PLAYER, Y(144), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitForCameraMovement();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_NPCEvent_Karen_ComfortsLonelyRick_RickBroodsAboutFamily);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_NPCEvent_Karen_ComfortsLonelyRick_KarenAsksWhyRickIsDown);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_NPCEvent_Karen_ComfortsLonelyRick_RickWondersWhenRodWillReturn);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_NPCEvent_Karen_ComfortsLonelyRick_KarenNotesRodsConstantTravel);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_NPCEvent_Karen_ComfortsLonelyRick_RickFeelsAloneAfterPopurisMarriage);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_NPCEvent_Karen_ComfortsLonelyRick_KarenPromisesToHelpAtStore);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_NPCEvent_Karen_ComfortsLonelyRick_RickThanksKarenForHerSupport);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_NPCEvent_Karen_ComfortsLonelyRick_KarenSaysSpousesSupportEachOther);
    TalkClose();
    PanCameraTo(X(120), Y(144), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    VarSet(VAR_KAREN_COMFORTS_LONELY_RICK_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_RICK, EventScript_NPCEvent_RickAndKaren_MarriedDialogueInteractWithRick);
    SetEntityEventScript(ENTITY_KAREN, EventScript_NPCEvent_RickAndKaren_MarriedDialogueInteractWithKaren);
    return;
}
