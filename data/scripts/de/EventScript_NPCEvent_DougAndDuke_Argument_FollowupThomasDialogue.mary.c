#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_StoppedFight_FirstTalk_ThomasRelievedMealCanResume[] =
        "Ich bin nur froh, dass \r\n"
        "sie nicht mehr streiten. \r\n"
        "Jetzt kann ich mein{Press}\r\n"
        "Essen genießen!{Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_StoppedFight_RepeatTalk_ThomasThanksPlayer[] =
        "Danke, dass du die Dinge \r\n"
        "geregelt hast, {Player}.{Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_NotIntervened_FirstTalk_ThomasWondersWhatCausedFight[] =
        "Warum sie wohl \r\n"
        "überhaupt gestritten \r\n"
        "haben...?{Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_NotIntervened_RepeatTalk_ThomasSaysFightRuinedMeal[] =
        "Jetzt schmeckt mein Essen\r\n"
        "nicht mehr...\r\n"
        "Welche Verschwendung!{Press}";
};

void EventScript_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue(void)
{
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    if (VarGet(VAR_DOUG_AND_DUKE_ARGUMENT_CHOICE) == DOUG_DUKE_ARGUMENT_STOP_FIGHT)
    {
        if (WasNpcSpokenToJustNow(CHARACTER_THOMAS) == FALSE)
        {
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
            TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_StoppedFight_FirstTalk_ThomasRelievedMealCanResume);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
            TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_StoppedFight_RepeatTalk_ThomasThanksPlayer);
        }
    }
    else
    {
        if (WasNpcSpokenToJustNow(CHARACTER_THOMAS) == FALSE)
        {
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
            TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_NotIntervened_FirstTalk_ThomasWondersWhatCausedFight);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
            TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_NotIntervened_RepeatTalk_ThomasSaysFightRuinedMeal);
        }
    }
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    SetEntityFacing(ENTITY_THOMAS, FACING_RIGHT);
    return;
}
