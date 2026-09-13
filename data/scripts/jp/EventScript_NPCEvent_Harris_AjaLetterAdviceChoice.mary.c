#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisAsksToTalkLateAtNight[] =
        "すいません、\r\n"
        "こんなおそくに…\r\n"
        "ちょっといいですか？{Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_ChoiceHearHarrisOut[] =
        "どうぞ";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_ChoiceDeclineConversation[] =
        "いそがしい";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisRevealsSecretCrushOnAja[] =
        "実はボク、\r\n"
        "果樹園のむすめさんで{Press}\p"
        "街に行ってしまった\r\n"
        "アージュさんの事が\r\n"
        "好きなんです。{Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisExplainsDifficultyWritingLetter[] =
        "手紙を書きたいんですが、\r\n"
        "何もないのに出しづらくって…{Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisAsksWhatToWriteToAja[] =
        "そこで、{Player}さんは\r\n"
        "恋愛結婚と聞いたもので…{Press}\p"
        "恋愛経験が豊富な、\r\n"
        "{Player}さんに\r\n"
        "相談しようと考えて{Press}\r\n"
        "来たんです。{Press}\p"
        "何かアドバイスを\r\n"
        "もらえませんか？{Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_ChoiceAdviseHarrisToConfessFeelings[] =
        "気持ちをぶつけるべき";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_ChoiceTellHarrisToDecideForHimself[] =
        "自分で考えるべき";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisAgreesSimpleHonestyIsBest[] =
        "なるほど、そうですよね。\r\n"
        "ウジウジ考えていても仕方が\r\n"
        "ないですもんね。{Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisThanksPlayerAndDecidesToConfess[] =
        "{Player}さんのおかげで\r\n"
        "ふっきれました。\r\n"
        "正直にボクの思いのすべてを{Press}\r\n"
        "書いてみます。{Press}\p"
        "{Player}さん、\r\n"
        "ありがとうございました。{Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisApologizesAndLeavesAfterAdviceRefusal[] =
        "………そうですか…\r\n"
        "すいません、\r\n"
        "おいそがしいところ…{Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisApologizesAndRemindsPlayerToLockDoors[] =
        "ああ、そうですか…\r\n"
        "すいません、\r\n"
        "おいそがしいところ。{Press}\p"
        "では、とじまりに気をつけて…{Press}";
};

void EventScript_NPCEvent_Harris_AjaLetterAdviceChoice(void)
{
    int var_0;
    SetEntityPosition(ENTITY_HARRIS, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_IDLE);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARRIS_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_HARRIS);
    TalkMessage(gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisAsksToTalkLateAtNight);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_NPCEvent_Harris_AjaLetterAdviceChoice_ChoiceHearHarrisOut, gText_NPCEvent_Harris_AjaLetterAdviceChoice_ChoiceDeclineConversation);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_HARRIS_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_HARRIS);
            TalkMessage(gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisRevealsSecretCrushOnAja);
            TalkClose();
            StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_HARRIS_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_HARRIS);
            TalkMessage(gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisExplainsDifficultyWritingLetter);
            SetTalkPortrait(TALK_PORTRAIT_HARRIS_NORMAL);
            TalkMessage(gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisAsksWhatToWriteToAja);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice2(gText_NPCEvent_Harris_AjaLetterAdviceChoice_ChoiceAdviseHarrisToConfessFeelings, gText_NPCEvent_Harris_AjaLetterAdviceChoice_ChoiceTellHarrisToDecideForHimself);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    VarSet(VAR_HARRIS_AJA_LETTER_ADVICE_CHOICE, HARRIS_AJA_LETTER_ADVICE_TELL_HER_FEELINGS);
                    AddNpcFriendship(CHARACTER_HARRIS, 20);
                    TalkClose();
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_HARRIS_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_HARRIS);
                    TalkMessage(gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisAgreesSimpleHonestyIsBest);
                    SetTalkPortrait(TALK_PORTRAIT_HARRIS_HAPPY);
                    TalkMessage(gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisThanksPlayerAndDecidesToConfess);
                    TalkClose();
                    break;
                case CHOICE_OPTION_2:
                    AddNpcFriendship(CHARACTER_HARRIS, mary_negated_int(-20));
                    VarSet(VAR_HARRIS_AJA_LETTER_ADVICE_CHOICE, HARRIS_AJA_LETTER_ADVICE_THINK_FOR_YOURSELF);
                    TalkClose();
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_HARRIS_AFRAID);
                    SetTalkNameplateCharacter(CHARACTER_HARRIS);
                    TalkMessage(gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisApologizesAndLeavesAfterAdviceRefusal);
                    TalkClose();
                    break;
            }
            break;
        case CHOICE_OPTION_2:
            VarSet(VAR_HARRIS_AJA_LETTER_ADVICE_CHOICE, HARRIS_AJA_LETTER_ADVICE_THINK_FOR_YOURSELF);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_HARRIS_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_HARRIS);
            TalkMessage(gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisApologizesAndRemindsPlayerToLockDoors);
            TalkClose();
            break;
    }
    SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_WALK);
    SetEntityFacing(ENTITY_HARRIS, FACING_RIGHT);
    MoveEntityXTo(ENTITY_HARRIS, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_HARRIS);
    SetEntityFacing(ENTITY_HARRIS, FACING_UP);
    MoveEntityYTo(ENTITY_HARRIS, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_HARRIS);
    HideEntity(ENTITY_HARRIS);
    VarSet(VAR_HARRIS_AJA_LETTER_ADVICE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    MarkNpcSpokenTo(CHARACTER_HARRIS);
}
