#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaAccusesDukeOfDrinkingWineryStock[] =
        "あんた！\r\n"
        "また、わたしにかくれて\r\n"
        "飲んでたねぇ！{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeDeniesDrinkingStock[] =
        "飲んでねぇよ。\r\n"
        "{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaRevealsBottlesUnderBed[] =
        "ウソ言うんじゃないよ！{Press}\p"
        "じゃあ、ベッドの下にあった\r\n"
        "ワインはなんなのさ？\r\n"
        "うちのワインじゃないわよね？{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeHesitatesWhenConfronted[] =
        "うっ…\r\n"
        "{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeClaimsHeWasResearchingQuality[] =
        "ほ…　他の町で作ったワインを\r\n"
        "研究しようと思っておいて\r\n"
        "おいたんだよ。{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaChallengesResearchExcuse[] =
        "へぇ～～～、{Press}\p"
        "研究用ねぇ…{Press}\p"
        "わたしが寝るたびに減ってたん\r\n"
        "だけど？{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeDefendsModerateDrinkingAndResentsMonitoring[] =
        "……あ～！\r\n"
        "いちいち細かいんだよ！{Press}\p"
        "ちょっとぐらい飲んだって\r\n"
        "いいじゃねぇか！{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaRecallsPromiseAndAjasDeparture[] =
        "あんたねぇ！{Press}\p"
        "自分で飲まないって\r\n"
        "言い出したんだろ？\r\n"
        "ちょっとは守ったらどうだい！{Press}\p"
        "あんた、タダでさえワイン\r\n"
        "飲んだら止まらなくて\r\n"
        "タチが悪いんだから！{Press}\p"
        "アージュも嫌がってたろ？{Press}\p"
        "アージュが帰ってきても、\r\n"
        "あんたがこの調子だったら\r\n"
        "また、あの子出て行くよ？{Press}\p"
        "クリフにしたってそうだよ。{Press}\p"
        "あんたのせいであんないい子が\r\n"
        "いなくなったら、\r\n"
        "わたしは許さないからね。{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeFallsSilent[] =
        "…………\r\n"
        "{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaExplainsConcernAndRequestsModeration[] =
        "わたしはね、何も飲むなとは\r\n"
        "言ってないんだよ。{Press}\p"
        "いきなり飲むなって言っても、\r\n"
        "あんたはムリだろうしね。{Press}\p"
        "でも、少しずつ減らしていって\r\n"
        "くれないかい？{Press}\p"
        "わたしは、あんたの体も心配\r\n"
        "なんだよ…{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeAgreesToCutBack[] =
        "…わかった。\r\n"
        "{Press}";

    const char gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaForgivesDuke[] =
        "うん、だったら今回はかんべん\r\n"
        "してあげるわ。{Press}";
};

void EventScript_NPCEvent_DukeAndManna_MissingJuiceArgument(void)
{
    EnableScriptedNpcControl();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_MANNA, X(88), Y(80), FACING_RIGHT);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    SetEntityPosition(ENTITY_DUKE, X(108), Y(80), FACING_LEFT);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(120), Y(80), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    StartEntityEffect(ENTITY_MANNA, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaAccusesDukeOfDrinkingWineryStock);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeDeniesDrinkingStock);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaRevealsBottlesUnderBed);
    TalkClose();
    StartEntityEffect(ENTITY_DUKE, ENTITY_EMOTE_AFRAID, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeHesitatesWhenConfronted);
    SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeClaimsHeWasResearchingQuality);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaChallengesResearchExcuse);
    TalkClose();
    StartEntityEffect(ENTITY_DUKE, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeDefendsModerateDrinkingAndResentsMonitoring);
    TalkClose();
    StartEntityEffect(ENTITY_MANNA, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaRecallsPromiseAndAjasDeparture);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeFallsSilent);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaExplainsConcernAndRequestsModeration);
    TalkClose();
    StartEntityEffect(ENTITY_DUKE, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_DukeAgreesToCutBack);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_DukeAndManna_MissingJuiceArgument_MannaForgivesDuke);
    TalkClose();
    PanCameraTo(X(120), Y(208), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    EnableScriptedNpcControl();
    VarSet(VAR_DUKE_AND_MANNA_MISSING_JUICE_ARGUMENT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_MANNA, EventScript_NPCEvent_DukeAndManna_MissingJuiceArgument_FollowupMannaDialogue);
    SetEntityEventScript(ENTITY_DUKE, EventScript_NPCEvent_DukeAndManna_MissingJuiceArgument_FollowupDukeDialogue);
    return;
}
