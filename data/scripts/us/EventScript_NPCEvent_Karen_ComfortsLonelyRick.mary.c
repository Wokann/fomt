#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Karen_ComfortsLonelyRick_RickBroodsAboutFamily[] =
        "Hmmm.....{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_KarenAsksWhyRickIsDown[] =
        "What's wrong, Rick? \r\n"
        "You seem so down...{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_RickWondersWhenRodWillReturn[] =
        "I was just wondering when my\r\n"
        "father would come back...{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_KarenNotesRodsConstantTravel[] =
        "He travels all the time, \r\n"
        "doesn't he? I've only seen \r\n"
        "seen him a few times ever.{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_RickFeelsAloneAfterPopurisMarriage[] =
        "Popuri's married and doesn't\r\n"
        "live here any more...{Press}\p"
        "I'm worried about the store.{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_KarenPromisesToHelpAtStore[] =
        "Don't worry! You're \r\n"
        "forgetting about me!{Press}\p"
        "I'll work more than Popuri\r\n"
        "ever did!{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_RickThanksKarenForHerSupport[] =
        "Gee Karen...Thanks!{Press}";

    const char gText_NPCEvent_Karen_ComfortsLonelyRick_KarenSaysSpousesSupportEachOther[] =
        "You don't need to thank me!\r\n"
        "We're married, aren't we?\r\n"
        "That's what spouses do.{Press}";
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
