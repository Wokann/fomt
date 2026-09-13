#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Basil_PublishingAward_AnnaCongratulatesBasil[] =
        "Congratulations!{Press}";

    const char gText_NPCEvent_Basil_PublishingAward_MaryCongratulatesBasil[] =
        "Congratulations, Dad!{Press}";

    const char gText_NPCEvent_Basil_PublishingAward_GrayCongratulatesBasil[] =
        "That's really great...{Press}";

    const char gText_NPCEvent_Basil_PublishingAward_BasilThanksFamilyAndFriends[] =
        "Ha ha ha...Thank you, \r\n"
        "everyone. {Press}";

    const char gText_NPCEvent_Basil_PublishingAward_BasilWelcomesPlayer[] =
        "Hi there, {Player}.\r\n"
        "Come on in. {Press}";

    const char gText_NPCEvent_Basil_PublishingAward_MaryAnnouncesBasilsBookAward[] =
        "Listen to this, \r\n"
        "{Player}.\r\n"
        "One of my dad's books won{Press}\r\n"
        "a huge award!{Press}";

    const char gText_NPCEvent_Basil_PublishingAward_BasilDownplaysAward[] =
        "Well, it's not all that \r\n"
        "prestigious...{Press}";

    const char gText_NPCEvent_Basil_PublishingAward_GrayAffirmsAwardImportance[] =
        "That's not true. \r\n"
        "It's a big deal. We're \r\n"
        "all very proud. {Press}";

    const char gText_NPCEvent_Basil_PublishingAward_MaryAffirmsFamilyPride[] =
        "Exactly! We're all \r\n"
        "proud of you, Dad.{Press}";

    const char gText_NPCEvent_Basil_PublishingAward_BasilAcceptsPraise[] =
        "Thank you for saying so. {Press}";

    const char gText_NPCEvent_Basil_PublishingAward_AnnaRenewsLoveForBasil[] =
        "I'm ready to fall in love\r\n"
        "with you all over again, \r\n"
        "dear!{Press}";

    const char gText_NPCEvent_Basil_PublishingAward_BasilReactsEmbarrassed[] =
        "Now I'm getting all\r\n"
        "embarrassed...!{Press}";
};

void EventScript_NPCEvent_Basil_PublishingAward(void)
{
    EnableScriptedNpcControl();
    ChangeMap(MAP_BASIL_HOUSE_1F, X(68), Y(80));
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(152), FACING_LEFT);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_BASIL, X(48), Y(80), FACING_DOWN);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_IDLE);
    SetEntityPosition(ENTITY_ANNA, X(28), Y(100), FACING_UP);
    SetEntityAnim(ENTITY_ANNA, ANIMATION_ANNA_IDLE);
    SetEntityPosition(ENTITY_MARY, X(48), Y(100), FACING_UP);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityPosition(ENTITY_GRAY, X(68), Y(100), FACING_UP);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_NPCEvent_Basil_PublishingAward_AnnaCongratulatesBasil);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_NPCEvent_Basil_PublishingAward_MaryCongratulatesBasil);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_NPCEvent_Basil_PublishingAward_GrayCongratulatesBasil);
    TalkClose();
    StartEntityEffect(ENTITY_BASIL, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_NPCEvent_Basil_PublishingAward_BasilThanksFamilyAndFriends);
    TalkClose();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(88), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    MoveEntityYTo(ENTITY_PLAYER, Y(80), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    MoveEntityXTo(ENTITY_PLAYER, X(68), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
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
    SetTalkPortrait(TALK_PORTRAIT_BASIL_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_NPCEvent_Basil_PublishingAward_BasilWelcomesPlayer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_NPCEvent_Basil_PublishingAward_MaryAnnouncesBasilsBookAward);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_NPCEvent_Basil_PublishingAward_BasilDownplaysAward);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_NPCEvent_Basil_PublishingAward_GrayAffirmsAwardImportance);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_NPCEvent_Basil_PublishingAward_MaryAffirmsFamilyPride);
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
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_NPCEvent_Basil_PublishingAward_BasilAcceptsPraise);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_NPCEvent_Basil_PublishingAward_AnnaRenewsLoveForBasil);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_NPCEvent_Basil_PublishingAward_BasilReactsEmbarrassed);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_BASIL);
    MarkNpcSpokenTo(CHARACTER_MARY);
    EnableScriptedNpcControl();
    VarSet(VAR_BASIL_PUBLISHING_AWARD_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_BASIL, EventScript_NPCEvent_Basil_PublishingAward_FollowupBasilDialogue);
    SetEntityEventScript(ENTITY_ANNA, EventScript_NPCEvent_Basil_PublishingAward_FollowupAnnaDialogue);
    SetEntityEventScript(ENTITY_MARY, EventScript_NPCEvent_Basil_PublishingAward_FollowupMaryDialogue);
    SetEntityEventScript(ENTITY_GRAY, EventScript_NPCEvent_Basil_PublishingAward_FollowupGrayDialogue);
    return;
}
