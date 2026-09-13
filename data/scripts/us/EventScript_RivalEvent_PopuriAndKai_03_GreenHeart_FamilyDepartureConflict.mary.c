#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriWondersWhyRickObjectsToHerSeeingKai[] =
        "I wonder why my brother\r\n"
        "hates it when I see you \r\n"
        "so much? {Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiThinksRickConsidersHimABadInfluence[] =
        "He probably thinks I'm a \r\n"
        "bad influence.{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriRejectsRicksSuspicionOfKai[] =
        "That's so silly! Why would \r\n"
        "he think that...?{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiSaysRicksConcernShowsHerFamilyCares[] =
        "That just means your family\r\n"
        "tries to protect you, \r\n"
        "that's all. {Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriConsidersKaisViewOfHerFamily[] =
        "Hmm...{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriAsksAboutKaisFamily[] =
        "What does your family do, \r\n"
        "Kai?{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiSaysHeHasNotSeenHisParentsForYears[] =
        "Well, I haven't seen \r\n"
        "my parents for years...{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriAsksWhyKaiLeftHisFamily[] =
        "Why?{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiExplainsHisParentsRejectedHisWayOfLife[] =
        "My parents don't understand\r\n"
        "me at all. They don't like\r\n"
        "me not wanting to {Press}\r\n"
        "live like they do. {Press}\p"
        "I hate following all those \r\n"
        "rules all the time! That's \r\n"
        "just not me! {Press}\p"
        "Besides...they work all the\r\n"
        "time... They have no\r\n"
        "time for me anyways. {Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiExplainsHeLeftHome[] =
        "So, I couldn't stand it any\r\n"
        "more and left home.{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriReactsToKaiLeavingHome[] =
        "Really...?{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiSaysLeavingLetHimTravelAndLiveFreely[] =
        "I'm glad I did, though. {Press}\p"
        "I've gotten to see all\r\n"
        "kinds of towns, and live my\r\n"
        "own way. I enjoy myself. {Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriWishesSheCouldLiveFreely[] =
        "I wish I could be so free...{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiAsksWhetherPopuriIsSeriousAboutLeaving[] =
        "Are you serious?{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriConfirmsSheWantsThatFreedom[] =
        "...Yes. {Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiRemindsPopuriOfLilliaAndRick[] =
        "your mom and Rick?{Press}\p"
        "They are too nice to leave,\r\n"
        "I think...{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriFallsSilentAfterKaisFamilyReminder[] =
        "...{Press}";
};

void EventScript_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict(void)
{
    ChangeMap(MAP_MINERAL_BEACH, X(385), Y(124));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(24), Y(280), FACING_RIGHT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_POPURI, X(385), Y(124), FACING_RIGHT);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityPosition(ENTITY_KAI, X(385), Y(144), FACING_RIGHT);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriWondersWhyRickObjectsToHerSeeingKai);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiThinksRickConsidersHimABadInfluence);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriRejectsRicksSuspicionOfKai);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiSaysRicksConcernShowsHerFamilyCares);
    TalkClose();
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriConsidersKaisViewOfHerFamily);
    TalkClose();
    SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriAsksAboutKaisFamily);
    TalkClose();
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_KAI, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiSaysHeHasNotSeenHisParentsForYears);
    TalkClose();
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriAsksWhyKaiLeftHisFamily);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiExplainsHisParentsRejectedHisWayOfLife);
    SetTalkPortrait(TALK_PORTRAIT_KAI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiExplainsHeLeftHome);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriReactsToKaiLeavingHome);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiSaysLeavingLetHimTravelAndLiveFreely);
    TalkClose();
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriWishesSheCouldLiveFreely);
    TalkClose();
    StartEntityEffect(ENTITY_KAI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiAsksWhetherPopuriIsSeriousAboutLeaving);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriConfirmsSheWantsThatFreedom);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiRemindsPopuriOfLilliaAndRick);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriFallsSilentAfterKaisFamilyReminder);
    TalkClose();
    PanCameraTo(X(24), Y(280), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_POPURI, EventScript_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_FollowupPopuriDialogue);
    SetEntityEventScript(ENTITY_KAI, EventScript_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_FollowupKaiDialogue);
    VarSet(VAR_POPURI_KAI_RIVAL_EVENT_3_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    return;
}
