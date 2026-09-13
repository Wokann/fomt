#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriWondersWhyRickObjectsToHerSeeingKai[] =
        "Ich frage mich, was mein\r\n"
        "Bruder dagegen hat,  \r\n"
        "wenn ich dich sehe?{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiThinksRickConsidersHimABadInfluence[] =
        "Er denkt vielleicht, ich \r\n"
        "habe einen schlechten \r\n"
        "Einfluss auf dich.{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriRejectsRicksSuspicionOfKai[] =
        "Das ist dämlich! Wieso \r\n"
        "sollte er das denken...?{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiSaysRicksConcernShowsHerFamilyCares[] =
        "Deine Familie versucht\r\n"
        "nur, dich zu \r\n"
        "beschützen. {Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriConsidersKaisViewOfHerFamily[] =
        "Hmm...{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriAsksAboutKaisFamily[] =
        "Was macht deine \r\n"
        "Familie, Kai?{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiSaysHeHasNotSeenHisParentsForYears[] =
        "Ich habe meine Eltern \r\n"
        "ewig nicht gesehen...{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriAsksWhyKaiLeftHisFamily[] =
        "Warum?{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiExplainsHisParentsRejectedHisWayOfLife[] =
        "Meine Eltern verstehen\r\n"
        "mich nicht. Sie mögen\r\n"
        "nicht, dass ich nicht so {Press}\r\n"
        "leben will wie sie. {Press}\p"
        "Ich hasse es, immer  \r\n"
        "diese Regeln zu befolgen! \r\n"
        "So bin ich nicht! {Press}\p"
        "Außerdem... sie arbeiten\r\n"
        "immer... Sie haben \r\n"
        "sowieso nie Zeit. {Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiExplainsHeLeftHome[] =
        "Ich habe es nicht mehr\r\n"
        "ausgehalten und ging eben.{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriReactsToKaiLeavingHome[] =
        "Wirklich...?{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiSaysLeavingLetHimTravelAndLiveFreely[] =
        "Und das ist gut so. {Press}\p"
        "Ich habe so viele Städte\r\n"
        "gesehen und lebe auf\r\n"
        "meine Art. {Press}\r\n"
        "Es macht mir Spaß. {Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriWishesSheCouldLiveFreely[] =
        "Ich wünschte, ich \r\n"
        "könnte so frei sein...{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiAsksWhetherPopuriIsSeriousAboutLeaving[] =
        "Meinst du das ernst?{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriConfirmsSheWantsThatFreedom[] =
        "...Ja. {Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiRemindsPopuriOfLilliaAndRick[] =
        "Ich denke nicht. Was\r\n"
        "ist mit deiner \r\n"
        "Mutter und Rick?{Press}\p"
        "Sie sind zu nett, um sie\r\n"
        "zu verlassen...{Press}";

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
