#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriWondersWhyRickObjectsToHerSeeingKai[] =
        "お兄ちゃんって、ポプリとカイ\r\n"
        "が会ってると、どうしてあんな\r\n"
        "にウルサイのかなぁ？{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiThinksRickConsidersHimABadInfluence[] =
        "オレがポプリに悪いこと教える\r\n"
        "と思って、心配してんじゃない\r\n"
        "の？{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriRejectsRicksSuspicionOfKai[] =
        "カイがそんなこと言うわけない\r\n"
        "じゃない。{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiSaysRicksConcernShowsHerFamilyCares[] =
        "でも、家族にそれだけ大切に\r\n"
        "思われてるからいいじゃん。{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriConsidersKaisViewOfHerFamily[] =
        "…そうなのかな？{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriAsksAboutKaisFamily[] =
        "そういえば、カイの家族って何\r\n"
        "してるの？{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiSaysHeHasNotSeenHisParentsForYears[] =
        "家族？\r\n"
        "親がいるけど、何年も会って\r\n"
        "ないなぁ…{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriAsksWhyKaiLeftHisFamily[] =
        "どうして？{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiExplainsHisParentsRejectedHisWayOfLife[] =
        "ウチの親って勝手でさ。\r\n"
        "息子が自分の思う通りに動くと\r\n"
        "思ってんの。{Press}\p"
        "オレにも考えてることがあるの\r\n"
        "にさ…レールのしかれた人生な\r\n"
        "んて、まっぴらなんだよ。{Press}\p"
        "それに仕事におわれて、昔から\r\n"
        "オレとのコミュニケーションも\r\n"
        "ありゃしないし…{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiExplainsHeLeftHome[] =
        "で、たまらなくなって家を飛び\r\n"
        "出したってわけ。{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriReactsToKaiLeavingHome[] =
        "そうなんだ…{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiSaysLeavingLetHimTravelAndLiveFreely[] =
        "でも、家を出てよかったよ。{Press}\r\n"
        "色んな町にも行けるし、なんか\r\n"
        "こう、自分で生活してるんだっ\r\n"
        "ていうのも感じられてさ。{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriWishesSheCouldLiveFreely[] =
        "ポプリもそういう生活してみた\r\n"
        "いなぁ…{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiAsksWhetherPopuriIsSeriousAboutLeaving[] =
        "本気なの？{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriConfirmsSheWantsThatFreedom[] =
        "うん。{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_KaiRemindsPopuriOfLilliaAndRick[] =
        "ダメだって、ポプリにはおば\r\n"
        "さんやリックがいるじゃん？{Press}\p"
        "ウチの親ならいいけど、あんな\r\n"
        "いい家族を悲しませたら\r\n"
        "ダメだ。{Press}";

    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_PopuriFallsSilentAfterKaisFamilyReminder[] =
        "…{Press}";
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
