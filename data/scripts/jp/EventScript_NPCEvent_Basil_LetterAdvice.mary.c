#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Basil_LetterAdvice_BasilPacesWhileWorried[] =
        "う～～～ん…\r\n"
        "{Press}";

    const char gText_NPCEvent_Basil_LetterAdvice_BasilGreetsPlayerAndIntroducesDilemma[] =
        "{Player}くんか…\r\n"
        "はぁ…{Press}";

    const char gText_NPCEvent_Basil_LetterAdvice_BasilExplainsPoisonMushroomMisreading[] =
        "どうしたかって？\r\n"
        "ああ、実はね…{Press}\p"
        "昨日のことなんだけど、\r\n"
        "わたしが出している本で{Press}\p"
        "きのこをあつかってる本が\r\n"
        "あるんだけど、{Press}\p"
        "わたしの本をまちがって解釈\r\n"
        "した人がいてね。{Press}\p"
        "毒きのこをあやまって食べて\r\n"
        "しまったらしいんだ。{Press}";

    const char gText_NPCEvent_Basil_LetterAdvice_BasilExplainsReadersComplaintLetter[] =
        "それで、その人から抗議の\r\n"
        "手紙が来てね…{Press}\p"
        "どう返事を書こうかと迷って\r\n"
        "いたんだよ…{Press}\p"
        "キミはどう思う？{Press}";

    const char gText_NPCEvent_Basil_LetterAdvice_ChoiceExplainTheWritersMistake[] =
        "間違いを教えてあげるべき";

    const char gText_NPCEvent_Basil_LetterAdvice_ChoiceRecommendApologizing[] =
        "あやまるべき";

    const char gText_NPCEvent_Basil_LetterAdvice_BasilAgreesToExplainReadersError[] =
        "そうだね。\r\n"
        "読者が間違っているので\r\n"
        "あれば、{Press}\p"
        "どう間違ったかを教えて\r\n"
        "あげるのもわたしの役目だね。{Press}";

    const char gText_NPCEvent_Basil_LetterAdvice_BasilThanksPlayerAndPreparesReply[] =
        "ありがとう。\r\n"
        "{Player}くんのおかげで\r\n"
        "吹っ切れたよ。{Press}\p"
        "さて、\r\n"
        "返事の手紙を書こうかな。{Press}";

    const char gText_NPCEvent_Basil_LetterAdvice_BasilLosesConfidenceAfterApologyAdvice[] =
        "そうか…\r\n"
        "わたしの書き方がいけなかった\r\n"
        "のかもしれないなぁ…{Press}\p"
        "自信がなくなってきたよ。{Press}\p"
        "ちょっと一人にしておいて\r\n"
        "くれるかな…{Press}";
};

void EventScript_NPCEvent_Basil_LetterAdvice(void)
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
    SetEntityPosition(ENTITY_BASIL, X(32), Y(80), FACING_DOWN);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(48), Y(80), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    StartEntityEffect(ENTITY_BASIL, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_BASIL, FACING_RIGHT);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_WALK);
    MoveEntityXTo(ENTITY_BASIL, X(56), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BASIL);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_IDLE);
    StartEntityEffect(ENTITY_BASIL, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(10);
    SetEntityFacing(ENTITY_BASIL, FACING_LEFT);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_WALK);
    MoveEntityXTo(ENTITY_BASIL, X(32), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BASIL);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_IDLE);
    StartEntityEffect(ENTITY_BASIL, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(10);
    SetEntityFacing(ENTITY_BASIL, FACING_RIGHT);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_WALK);
    MoveEntityXTo(ENTITY_BASIL, X(56), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BASIL);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_IDLE);
    StartEntityEffect(ENTITY_BASIL, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(10);
    SetEntityFacing(ENTITY_BASIL, FACING_LEFT);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_WALK);
    MoveEntityXTo(ENTITY_BASIL, X(32), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BASIL);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_IDLE);
    StartEntityEffect(ENTITY_BASIL, ENTITY_EMOTE_THINKING, TRUE);
    SetEntityFacing(ENTITY_BASIL, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BASIL_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_NPCEvent_Basil_LetterAdvice_BasilPacesWhileWorried);
    TalkClose();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(80), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    MoveEntityXTo(ENTITY_PLAYER, X(48), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityFacing(ENTITY_BASIL, FACING_LEFT);
    StartEntityEffect(ENTITY_BASIL, ENTITY_EMOTE_EXCLAMATION, FALSE);
    MoveEntityXTo(ENTITY_BASIL, X(24), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BASIL);
    SetEntityFacing(ENTITY_BASIL, FACING_RIGHT);
    WaitFrames(50);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BASIL_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_NPCEvent_Basil_LetterAdvice_BasilGreetsPlayerAndIntroducesDilemma);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BASIL_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_NPCEvent_Basil_LetterAdvice_BasilExplainsPoisonMushroomMisreading);
    SetTalkPortrait(TALK_PORTRAIT_BASIL_NORMAL);
    TalkMessage(gText_NPCEvent_Basil_LetterAdvice_BasilExplainsReadersComplaintLetter);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_NPCEvent_Basil_LetterAdvice_ChoiceExplainTheWritersMistake, gText_NPCEvent_Basil_LetterAdvice_ChoiceRecommendApologizing);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_BASIL);
            TalkMessage(gText_NPCEvent_Basil_LetterAdvice_BasilAgreesToExplainReadersError);
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
            TalkMessage(gText_NPCEvent_Basil_LetterAdvice_BasilThanksPlayerAndPreparesReply);
            TalkClose();
            AddNpcFriendship(CHARACTER_BASIL, 20);
            VarSet(VAR_BASIL_LETTER_ADVICE_CHOICE, BASIL_LETTER_ADVICE_EXPLAIN_ERROR);
            break;
        case CHOICE_OPTION_2:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BASIL_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_BASIL);
            TalkMessage(gText_NPCEvent_Basil_LetterAdvice_BasilLosesConfidenceAfterApologyAdvice);
            TalkClose();
            AddNpcFriendship(CHARACTER_BASIL, mary_negated_int(-10));
            VarSet(VAR_BASIL_LETTER_ADVICE_CHOICE, BASIL_LETTER_ADVICE_APOLOGIZE);
            break;
    }
    SetEntityFacing(ENTITY_BASIL, FACING_UP);
    MarkNpcSpokenTo(CHARACTER_BASIL);
    EnableScriptedNpcControl();
    VarSet(VAR_BASIL_LETTER_ADVICE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_BASIL, EventScript_NPCEvent_Basil_LetterAdvice_FollowupBasilDialogue);
    return;
}
