#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayPraisesMarysNovel[] =
        "マリー、\r\n"
        "その小説おもしろかったよ。{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryIsGladGrayEnjoyedNovel[] =
        "本当？\r\n"
        "よかった。\r\n"
        "書いたかいがあったわ。{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GraySaysMaryWillImproveWithPractice[] =
        "マリーは書く度に\r\n"
        "うまくなっていくなぁ…{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayComparesHisLackOfProgress[] =
        "それにくらべて、オレは…{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryAsksWhatTroublesGray[] =
        "どうしたの、グレイ？{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayDoubtsHisBlacksmithingTalent[] =
        "鍛冶屋の仕事、\r\n"
        "いつまでたっても\r\n"
        "うまくならないんだ…{Press}\p"
        "マリーとちがって\r\n"
        "才能ないのかな？{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryRejectsGraysSelfDoubt[] =
        "それはちがうわよ、グレイ。{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayAsksWhySheDisagrees[] =
        "ちがう？{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryAsksWhetherGrayLovesBlacksmithing[] =
        "ええ、そうよ。\r\n"
        "グレイ、鍛冶屋の仕事って\r\n"
        "好き？{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayTentativelySaysYes[] =
        "……ああ。{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryPressesGrayForHonestAnswer[] =
        "本当に？{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryExplainsLovingCraftIsEssentialToMastery[] =
        "わたしは、こう思うのよ。\r\n"
        "小説も鍛冶屋の仕事で作り出す\r\n"
        "ものも、{Press}\r\n"
        "本当に心から好きにならなきゃ\r\n"
        "本物は作れないって…{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryAdmitsHerOwnNovelIsNotYetMasterful[] =
        "だからといって、今のわたしが\r\n"
        "本物を書けるかって言えば、\r\n"
        "まだムリかもしれないけどね。{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MarySaysSheWorksHardToBecomeARealNovelist[] =
        "でも、本物を書けるように\r\n"
        "なりたいって思って、\r\n"
        "努力してるつもりよ。{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayBeginsToUnderstandMarysAdvice[] =
        "マリー…{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MaryEncouragesGrayToImproveThroughLoveOfBlacksmithing[] =
        "鍛冶屋の仕事を心から好きに\r\n"
        "ならないと、いつまでたっても\r\n"
        "うまくならないと思うよ。{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_MarySuggestsReturningToTown[] =
        "うん。じゃ、帰ろうか？{Press}";

    const char gText_RivalEvent_MaryAndGray_03_GreenHeart_SummitEncouragement_GrayAgreesToReturn[] =
        "ああ。{Press}";
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
