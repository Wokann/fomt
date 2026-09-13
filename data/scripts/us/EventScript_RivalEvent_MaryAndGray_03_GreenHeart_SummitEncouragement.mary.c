#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayPraisesMarysNovel[] =
        "Mary, your novel was \r\n"
        "really great! {Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryIsGladGrayEnjoyedNovel[] =
        "You mean it?\r\n"
        "That makes me glad I \r\n"
        "wrote it. {Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GraySaysMaryWillImproveWithPractice[] =
        "I think you'll get even \r\n"
        "better with practice! {Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayComparesHisLackOfProgress[] =
        "And I can't do anything...{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryAsksWhatTroublesGray[] =
        "What's wrong, Gray? {Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayDoubtsHisBlacksmithingTalent[] =
        "I just don't get any better \r\n"
        "at being a blacksmith! {Press}\p"
        "I don't have any talent, \r\n"
        "unlike you...{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryRejectsGraysSelfDoubt[] =
        "That's wrong, Gray! {Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayAsksWhySheDisagrees[] =
        "Why? {Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryAsksWhetherGrayLovesBlacksmithing[] =
        "Hmm...\r\n"
        "Do you like being a \r\n"
        "blacksmith, Gray?{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayTentativelySaysYes[] =
        "......I guess so.{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryPressesGrayForHonestAnswer[] =
        "Do you like it or not?{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryExplainsLovingCraftIsEssentialToMastery[] =
        "I think whatever you are\r\n"
        "trying to do...\r\n"
        "A blacksmith or an author.{Press}\p"
        "If you really love what you\r\n"
        "do, you'll be good at it.{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryAdmitsHerOwnNovelIsNotYetMasterful[] =
        "Of course, I can't write \r\n"
        "real novels, yet. {Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MarySaysSheWorksHardToBecomeARealNovelist[] =
        "But I want to, more than \r\n"
        "anything. So I work hard \r\n"
        "at it. {Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayBeginsToUnderstandMarysAdvice[] =
        "Mary...{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryEncouragesGrayToImproveThroughLoveOfBlacksmithing[] =
        "So, if you really love being\r\n"
        "a blacksmith, then \r\n"
        "eventually you'll improve.{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MarySuggestsReturningToTown[] =
        "Shall we get back now?{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayAgreesToReturn[] =
        "Sure. {Press}";
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
