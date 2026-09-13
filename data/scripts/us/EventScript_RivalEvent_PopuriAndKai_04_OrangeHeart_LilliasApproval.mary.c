#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_KaiSaysPopuriWantsToMoveToAnotherTownWithHim[] =
        "Popuri and I are thinking of\r\n"
        "moving to another town...{Press}";

    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_RickAsksWhetherPopuriReallyPlansToLeave[] =
        "Is this true?!\r\n"
        "Popuri!{Press}";

    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_PopuriConfirmsShePlansToLeave[] =
        "...It is.{Press}";

    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_LilliaWondersWhatToDoAboutPopurisPlan[] =
        "Really...?\r\n"
        "What'll I do...{Press}";

    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_KaiSaysHeTriedToConvincePopuriToStay[] =
        "I tried to convince her to \r\n"
        "stay.{Press}";

    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_RickAccusesKaiOfEncouragingPopuriToLeave[] =
        "Liar! I bet you are the\r\n"
        "one who’s trying to\r\n"
        "take her!{Press}";

    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_PopuriSaysLeavingWasHerOwnIdea[] =
        "It's not Kai's fault.\r\n"
        "It really was my idea. {Press}";

    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_RickRefusesToLetPopuriLeave[] =
        "I won't allow it!{Press}";

    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_PopuriInsistsSheWillLeaveDespiteRicksObjection[] =
        "We're going no matter what!{Press}";

    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_LilliaAllowsPopuriToLeave[] =
        "It's OK. I don't mind. {Press}";

    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_RickChallengesLilliasDecision[] =
        "...M-mom! \r\n"
        "What are you saying?{Press}";

    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_PopuriCelebratesLilliasPermission[] =
        "Really! \r\n"
        "Fantastic!{Press}";

    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_LilliaExplainsSheWillNotStopTheirDecision[] =
        "If that's what they really \r\n"
        "want to do, then I don't\r\n"
        "want to stop them. {Press}";

    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_LilliaRequiresKaiToMakePopuriHappy[] =
        "I have a condition, though.\r\n"
        "Kai, you must make Popuri\r\n"
        "happy forever!{Press}";

    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_PopuriOrRickReactsToLilliasMarriageCondition[] =
        "Mom!...{Press}";

    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_KaiIsSurprisedByLilliasMarriageCondition[] =
        "Wha... What is this\r\n"
        "all of a sudden?{Press}";

    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_LilliaTellsKaiToConsiderHerCondition[] =
        "You don't have to answer \r\n"
        "now. Just think about it.{Press}";

    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_KaiLeavesToConsiderLilliasCondition[] =
        ".....I'll go home\r\n"
        "and think about it.{Press}";
};

void EventScript_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval(void)
{
    ChangeMap(MAP_POULTRY_FARM_HOUSE_1F, X(120), Y(95));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_POPURI, X(200), Y(128), FACING_UP);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityPosition(ENTITY_KAI, X(176), Y(128), FACING_UP);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    SetEntityPosition(ENTITY_RICK, X(200), Y(96), FACING_DOWN);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    SetEntityPosition(ENTITY_LILLIA, X(176), Y(96), FACING_DOWN);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
    if (GetEntityLocation(ENTITY_SASHA) == MAP_POULTRY_FARM_HOUSE_1F)
    {
        SetEntityPosition(ENTITY_SASHA, X(64), Y(84), FACING_UP);
        SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_KaiSaysPopuriWantsToMoveToAnotherTownWithHim);
    TalkClose();
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_EXCLAMATION, FALSE);
    StartEntityEffect(ENTITY_LILLIA, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_RickAsksWhetherPopuriReallyPlansToLeave);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_PopuriConfirmsShePlansToLeave);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_LilliaWondersWhatToDoAboutPopurisPlan);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_KaiSaysHeTriedToConvincePopuriToStay);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_RickAccusesKaiOfEncouragingPopuriToLeave);
    TalkClose();
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_PopuriSaysLeavingWasHerOwnIdea);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_RickRefusesToLetPopuriLeave);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_PopuriInsistsSheWillLeaveDespiteRicksObjection);
    TalkClose();
    StartEntityEffect(ENTITY_LILLIA, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_LilliaAllowsPopuriToLeave);
    TalkClose();
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_EXCLAMATION, FALSE);
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_RICK, FACING_LEFT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_RickChallengesLilliasDecision);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_PopuriCelebratesLilliasPermission);
    TalkClose();
    SetEntityFacing(ENTITY_LILLIA, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_LilliaExplainsSheWillNotStopTheirDecision);
    TalkClose();
    SetEntityFacing(ENTITY_LILLIA, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_LilliaRequiresKaiToMakePopuriHappy);
    TalkClose();
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_AFRAID, FALSE);
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_HEART, FALSE);
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_PopuriOrRickReactsToLilliasMarriageCondition);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_KaiIsSurprisedByLilliasMarriageCondition);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_PopuriOrRickReactsToLilliasMarriageCondition);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_LilliaTellsKaiToConsiderHerCondition);
    TalkClose();
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_KaiLeavesToConsiderLilliasCondition);
    TalkClose();
    SetEntityFacing(ENTITY_KAI, FACING_DOWN);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WALK);
    MoveEntityYTo(ENTITY_KAI, Y(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAI);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    SetEntityFacing(ENTITY_KAI, FACING_LEFT);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WALK);
    MoveEntityXTo(ENTITY_KAI, X(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAI);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    SetEntityFacing(ENTITY_KAI, FACING_DOWN);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WALK);
    MoveEntityYTo(ENTITY_KAI, Y(224), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAI);
    HideEntity(ENTITY_KAI);
    PanCameraTo(X(120), Y(208), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_RICK, EventScript_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_FollowupRickDialogue);
    SetEntityEventScript(ENTITY_POPURI, EventScript_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_FollowupPopuriDialogue);
    SetEntityEventScript(ENTITY_LILLIA, EventScript_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_FollowupLilliaDialogue);
    VarSet(VAR_POPURI_KAI_RIVAL_EVENT_4_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    return;
}
