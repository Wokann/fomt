#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MarySearchesForResearchGrass[] =
        "I wonder if this is \r\n"
        "the right grass?...{Press}";

    const char gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryGreetsPlayer[] =
        "Oh! Hi, {Player}. {Press}";

    const char gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryAsksAboutPlayersMarriedLife[] =
        "How do you like your\r\n"
        "married life? Takes some\r\n"
        "adjusting to, I bet!{Press}";

    const char gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryExplainsResearchGrassErrand[] =
        "What was I doing? \r\n"
        "I'm looking for a grass for\r\n"
        "my father that he needs {Press}\r\n"
        "for his research. {Press}";

    const char gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_ChoicePraiseHerHelp[] =
        "That's nice of you.";

    const char gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_ChoiceRespondNeutrally[] =
        "I see.";

    const char gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryExplainsSheEnjoysHelpingBasil[] =
        "I try to help out my dad. \r\n"
        "Besides, I actually enjoy\r\n"
        "it!{Press}";

    const char gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryEndsConversationAndReturnsHome[] =
        "Sorry for interrupting you. \r\n"
        "I have to get back now. {Press}\p"
        "Good luck on the farm!{Press}";

    const char gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryDefendsHelpingBasilsResearch[] =
        "Well, Dad's research really\r\n"
        "is important, so I like to \r\n"
        "help out any way I can. {Press}";
};

void EventScript_NPCEvent_Mary_GathersGrassForBasilsResearchChoice(void)
{
    int var_0;
    EnableScriptedNpcControl();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_MARY, X(648), Y(128), FACING_LEFT);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(668), Y(128), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MarySearchesForResearchGrass);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(128), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    MoveEntityXTo(ENTITY_PLAYER, X(668), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_EXCLAMATION, FALSE);
    SetEntityFacing(ENTITY_MARY, FACING_RIGHT);
    MoveEntityXTo(ENTITY_MARY, X(644), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryGreetsPlayer);
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    TalkMessage(gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryAsksAboutPlayersMarriedLife);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(30);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryExplainsResearchGrassErrand);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_ChoicePraiseHerHelp, gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_ChoiceRespondNeutrally);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            TalkMessage(gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryExplainsSheEnjoysHelpingBasil);
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            TalkMessage(gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryEndsConversationAndReturnsHome);
            TalkClose();
            AddNpcFriendship(CHARACTER_MARY, 20);
            break;
        case CHOICE_OPTION_2:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            TalkMessage(gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryDefendsHelpingBasilsResearch);
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            TalkMessage(gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryEndsConversationAndReturnsHome);
            TalkClose();
            AddNpcFriendship(CHARACTER_MARY, mary_negated_int(-10));
            break;
    }
    SetEntityFacing(ENTITY_MARY, FACING_LEFT);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    MoveEntityXTo(ENTITY_MARY, X(464), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    HideEntity(ENTITY_MARY);
    MarkNpcSpokenTo(CHARACTER_MARY);
    DisableScriptedNpcControl();
    VarSet(VAR_MARY_MARRIED_LIFE_AND_WRITING_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
