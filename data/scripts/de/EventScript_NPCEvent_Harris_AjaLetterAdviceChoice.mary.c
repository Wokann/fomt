#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisAsksToTalkLateAtNight[] =
        "Tut mir leid, dich so spät\r\n"
        "zu stören, aber kann \r\n"
        "ich dich etwas fragen?{Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_ChoiceHearHarrisOut[] =
        "Sicher.";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_ChoiceDeclineConversation[] =
        "Nicht jetzt.";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisRevealsSecretCrushOnAja[] =
        "Also... ich schwärme\r\n"
        "heimlich für Aja, Dukes\r\n"
        "und Mannas Tochter, {Press}\r\n"
        "die in der Stadt lebt. {Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisExplainsDifficultyWritingLetter[] =
        "Ich möchte ihr einen \r\n"
        "Brief schreiben, aber ich\r\n"
        "weiß nicht weiter...{Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisAsksWhatToWriteToAja[] =
        "Ich dachte, ich könnte\r\n"
        "dich vielleicht um \r\n"
        "Rat fragen. {Press}\p"
        "Hast du irgendeine Idee, \r\n"
        "was ich schreiben könnte?{Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_ChoiceAdviseHarrisToConfessFeelings[] =
        "Sag ihr, was du fühlst";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_ChoiceTellHarrisToDecideForHimself[] =
        "Musst du selber wissen.";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisAgreesSimpleHonestyIsBest[] =
        "Du hast Recht! Ich mache mir\r\n"
        "zu viele Gedanken darüber.\r\n"
        "Einfach ist am besten.{Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisThanksPlayerAndDecidesToConfess[] =
        "Dank deines Rates habe \r\n"
        "ich mich dazu entschlossen,\r\n"
        "Aja zu schreiben, was {Press}\r\n"
        "ich für sie fühle. {Press}\p"
        "Vielen Dank. {Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisApologizesAndLeavesAfterAdviceRefusal[] =
        "OK... Tut mir leid,\r\n"
        "wenn ich störe...{Press}";

    const char gText_NPCEvent_Harris_AjaLetterAdviceChoice_HarrisApologizesAndRemindsPlayerToLockDoors[] =
        "OK... Entschuldigung,\r\n"
        "wenn ich dich störe. {Press}\p"
        "Vergiss nicht, deine Türen\r\n"
        "nachts zu schließen. {Press}";
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
