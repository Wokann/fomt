#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MarySearchesForResearchGrass[] =
        "Ob dies das \r\n"
        "richtige Gras ist?...{Press}";

    const char gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryGreetsPlayer[] =
        "Oh! Hi, {Player}. {Press}";

    const char gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryAsksAboutPlayersMarriedLife[] =
        "Magst du das Eheleben?\r\n"
        "Man muss sich etwas\r\n"
        "anpassen, schätze ich!{Press}";

    const char gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryExplainsResearchGrassErrand[] =
        "Was habe ich getan?\r\n"
        "Ich suche ein Gras, dass\r\n"
        "mein Vater für seine {Press}\r\n"
        "Forschungen braucht. {Press}";

    const char gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_ChoicePraiseHerHelp[] =
        "Das ist nett von dir.";

    const char gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_ChoiceRespondNeutrally[] =
        "Ich verstehe.";

    const char gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryExplainsSheEnjoysHelpingBasil[] =
        "Ich versuche, meinem\r\n"
        "Vater auszuhelfen. \r\n"
        "Außerdem macht es{Press}\r\n"
        "mir Spaß!{Press}";

    const char gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryEndsConversationAndReturnsHome[] =
        "Entschuldige, wenn ich\r\n"
        "unterbreche. \r\n"
        "Ich muss zurück. {Press}\p"
        "Viel Glück auf der Farm!{Press}";

    const char gText_NPCEvent_Mary_GathersGrassForBasilsResearchChoice_MaryDefendsHelpingBasilsResearch[] =
        "Papas Forschung ist sehr\r\n"
        "wichtig, also helfe ich \r\n"
        "gerne, wo ich kann. {Press}";
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
