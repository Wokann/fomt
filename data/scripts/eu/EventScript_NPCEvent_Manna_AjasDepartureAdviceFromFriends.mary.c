#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaRequestsAdviceAboutAja[] =
        "There's something I want\r\n"
        "your advice on...{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaAsksWhatTroublesManna[] =
        "What is it? {Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaNamesAjaAsConcern[] =
        "It's about Aja.{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaSaysSheHasNeverMetAja[] =
        "Your daughter? \r\n"
        "I've never seen her. {Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaExplainsAjaLeftAfterArgumentWithDuke[] =
        "She fought with Duke, \r\n"
        "then ran away from home. {Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaReactsToAjasDeparture[] =
        "Really...{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaAsksWhetherAjaKeepsInTouch[] =
        "Do you hear from her? {Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaWantsAjaToReturnAndReconcile[] =
        "We hear from her now and \r\n"
        "then. I wish she'd return \r\n"
        "home so we could all \r\n"
        "sit down and work it out. \r\n"
        "I can't bear to let it go \r\n"
        "on like this.{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaRespondsToMannasConcern[] =
        "It must be tough...{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaOffersToCallAja[] =
        "I have an idea. I'll try \r\n"
        "convincing Aja to come\r\n"
        "back home.{Press}\p"
        "Sometimes these things work\r\n"
        "better if it's not the \r\n"
        "parent doing the talking. {Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaSupportsSashasPlan[] =
        "That's a good idea. \r\n"
        "I think we'd just drive her\r\n"
        "further away if we tried to{Press}\r\n"
        "convince her ourselves. {Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaThanksFriendsForAdvice[] =
        "Thanks, Sasha and Anna. \r\n"
        "I'm glad I got this off my \r\n"
        "chest. {Press}\r\n"
        "Friends really are \r\n"
        "important, aren't they. {Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaSaysFriendsHelpEachOther[] =
        "Don't mention it!\r\n"
        "That's what we're here for!{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaReassuresManna[] =
        "Yeah. We love to help. {Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaThanksFriendsAgain[] =
        "Thanks again. {Press}";
};

void EventScript_NPCEvent_Manna_AjasDepartureAdviceFromFriends(void)
{
    ChangeMap(MAP_ROSE_SQUARE, X(341), Y(114));
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_SASHA, X(328), Y(81), FACING_DOWN);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_MANNA, X(328), Y(129), FACING_UP);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    SetEntityPosition(ENTITY_ANNA, X(359), Y(96), FACING_LEFT);
    SetEntityAnim(ENTITY_ANNA, ANIMATION_ANNA_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaRequestsAdviceAboutAja);
    TalkClose();
    StartEntityEffect(ENTITY_SASHA, ENTITY_EMOTE_QUESTION, FALSE);
    StartEntityEffect(ENTITY_ANNA, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaAsksWhatTroublesManna);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaNamesAjaAsConcern);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaSaysSheHasNeverMetAja);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaExplainsAjaLeftAfterArgumentWithDuke);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaReactsToAjasDeparture);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaAsksWhetherAjaKeepsInTouch);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaWantsAjaToReturnAndReconcile);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaRespondsToMannasConcern);
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaOffersToCallAja);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaSupportsSashasPlan);
    TalkClose();
    StartEntityEffect(ENTITY_MANNA, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaThanksFriendsForAdvice);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaSaysFriendsHelpEachOther);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaReassuresManna);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaThanksFriendsAgain);
    TalkClose();
    EnableScriptedNpcControl();
    PanCameraTo(X(220), Y(432), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    VarSet(VAR_MANNA_AJAS_DEPARTURE_ADVICE_FROM_FRIENDS_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_SASHA, EventScript_NPCEvent_Manna_AjasDepartureAdviceFromFriends_FollowupSashaDialogue);
    SetEntityEventScript(ENTITY_ANNA, EventScript_NPCEvent_Manna_AjasDepartureAdviceFromFriends_FollowupAnnaDialogue);
    SetEntityEventScript(ENTITY_MANNA, EventScript_NPCEvent_Manna_AjasDepartureAdviceFromFriends_FollowupMannaDialogue);
}
