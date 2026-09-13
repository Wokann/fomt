#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayPraisesMarysNovel[] =
        "Mary, dein Roman \r\n"
        "war wirklich super! {Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryIsGladGrayEnjoyedNovel[] =
        "Meinst du?\r\n"
        "Dann bin ich froh, dass \r\n"
        "ich es geschrieben habe. {Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GraySaysMaryWillImproveWithPractice[] =
        "Wenn du etwas übst,\r\n"
        "wirst du noch besser! {Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayComparesHisLackOfProgress[] =
        "Ich kann nicht alles...{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryAsksWhatTroublesGray[] =
        "Was ist los, Gray?{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayDoubtsHisBlacksmithingTalent[] =
        "Ich werde einfach kein \r\n"
        "besserer Schmied! {Press}\p"
        "Ich habe kein Talent, \r\n"
        "anders als du...{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryRejectsGraysSelfDoubt[] =
        "Das stimmt nicht, Gray! {Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayAsksWhySheDisagrees[] =
        "Warum?{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryAsksWhetherGrayLovesBlacksmithing[] =
        "Hmm...\r\n"
        "Bist du gerne ein \r\n"
        "Schmied, Gray?{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayTentativelySaysYes[] =
        "......Ich denke ja.{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryPressesGrayForHonestAnswer[] =
        "Dir ist es ernst damit?{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryExplainsLovingCraftIsEssentialToMastery[] =
        "Wenn es darum geht, \r\n"
        "Schriftsteller oder\r\n"
        "Schmied zu sein... <wait >\p"
        "Wenn du deine Arbeit \r\n"
        "liebst, machst du sie gut.{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryAdmitsHerOwnNovelIsNotYetMasterful[] =
        "Noch kann ich keine \r\n"
        "richtigen Romane schreiben. {Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MarySaysSheWorksHardToBecomeARealNovelist[] =
        "Aber das möchte ich \r\n"
        "mehr als alles andere. \r\n"
        "Also arbeite ich daran.{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayBeginsToUnderstandMarysAdvice[] =
        "Mary...{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryEncouragesGrayToImproveThroughLoveOfBlacksmithing[] =
        "Also, wenn du wirklich\r\n"
        "gerne ein Schmied bist, \r\n"
        "wirst du besser werden.{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MarySuggestsReturningToTown[] =
        "Sollen wir zurück?{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayAgreesToReturn[] =
        "Sicher. {Press}";
};

void EventScript_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement(void)
{
    ChangeMap(MAP_MOTHERS_HILL_SUMMIT, X(237), Y(276));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    SetEntityPosition(ENTITY_MARY, X(224), Y(406), FACING_UP);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityPosition(ENTITY_GRAY, X(255), Y(406), FACING_UP);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_WALK);
    MoveEntityYTo(ENTITY_MARY, Y(284), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_GRAY, Y(284), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    WaitForEntityMovement(ENTITY_GRAY);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    WaitFrames(30);
    SetEntityFacing(ENTITY_MARY, FACING_RIGHT);
    SetEntityFacing(ENTITY_GRAY, FACING_LEFT);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayPraisesMarysNovel);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryIsGladGrayEnjoyedNovel);
    TalkClose();
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GraySaysMaryWillImproveWithPractice);
    SetTalkPortrait(TALK_PORTRAIT_GRAY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayComparesHisLackOfProgress);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryAsksWhatTroublesGray);
    TalkClose();
    StartEntityEffect(ENTITY_GRAY, ENTITY_EMOTE_THINKING, FALSE);
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayDoubtsHisBlacksmithingTalent);
    TalkClose();
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryRejectsGraysSelfDoubt);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayAsksWhySheDisagrees);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryAsksWhetherGrayLovesBlacksmithing);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayTentativelySaysYes);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryPressesGrayForHonestAnswer);
    TalkClose();
    StartEntityEffect(ENTITY_GRAY, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryExplainsLovingCraftIsEssentialToMastery);
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryAdmitsHerOwnNovelIsNotYetMasterful);
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MarySaysSheWorksHardToBecomeARealNovelist);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayBeginsToUnderstandMarysAdvice);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryEncouragesGrayToImproveThroughLoveOfBlacksmithing);
    TalkClose();
    StartEntityEffect(ENTITY_GRAY, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MarySuggestsReturningToTown);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayAgreesToReturn);
    TalkClose();
    SetEntityFacing(ENTITY_MARY, FACING_DOWN);
    SetEntityFacing(ENTITY_GRAY, FACING_DOWN);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_WALK);
    MoveEntityYTo(ENTITY_MARY, Y(406), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_GRAY, Y(406), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    WaitForEntityMovement(ENTITY_GRAY);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    HideEntity(ENTITY_MARY);
    HideEntity(ENTITY_GRAY);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_MARY_GRAY_RIVAL_EVENT_3_STATE, EVENT_LIFECYCLE_COMPLETED);
    ChangeMap(MAP_MOTHERS_HILL_SUMMIT, X(236), Y(411));
    SetEntityPosition(ENTITY_PLAYER, X(236), Y(500), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(464), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    return;
}
