#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisAsksToTalkLateAtNight[] =
        "Sorry to bother you \r\n"
        "so late, but can I ask \r\n"
        "you something? {Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_ChoiceHearHarrisOut[] =
        "Sure.";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_ChoiceDeclineConversation[] =
        "Not now.";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisRevealsSecretCrushOnAja[] =
        "You see...I have a secret \r\n"
        "crush on Aja, Duke and \r\n"
        "Manna's daughter who's {Press}\r\n"
        "living in the city.{Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisExplainsDifficultyWritingLetter[] =
        "I want to write her a \r\n"
        "letter, but I'm kind of\r\n"
        "stuck...{Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisAsksWhatToWriteToAja[] =
        "I thought that you might\r\n"
        "be a good person to ask \r\n"
        "advice from. {Press}\p"
        "Do you have any idea \r\n"
        "what I should write to Aja?{Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_ChoiceAdviseHarrisToConfessFeelings[] =
        "Tell her how you feel.";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_ChoiceTellHarrisToDecideForHimself[] =
        "Think for yourself.";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisAgreesSimpleHonestyIsBest[] =
        "You're right! I'm \r\n"
        "thinking too much about it,\r\n"
        "I guess. Simple is best. {Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisThanksPlayerAndDecidesToConfess[] =
        "Thanks to your advice, \r\n"
        "I've decided to take a \r\n"
        "chance and just tell {Press}\r\n"
        "Aja how I feel. {Press}\p"
        "Thanks a lot!{Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisApologizesAndLeavesAfterAdviceRefusal[] =
        "OK...Sorry to\r\n"
        "bother you...{Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisApologizesAndRemindsPlayerToLockDoors[] =
        "OK...Sorry to bother you. {Press}\p"
        "Don't forget to lock you \r\n"
        "doors at night. {Press}";
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
