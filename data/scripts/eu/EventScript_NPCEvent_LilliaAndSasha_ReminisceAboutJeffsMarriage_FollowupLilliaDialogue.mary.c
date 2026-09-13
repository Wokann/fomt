#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_FollowupLilliaDialogue_LilliaValuesHavingHusbandByHerSide[] =
        "It's nice to have your\r\n"
        "husband by your side all \r\n"
        "the time, isn't it? {Press}";

    const char gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_FollowupLilliaDialogue_LilliaSaysSashaAndJeffMakeAGoodCouple[] =
        "You two really do make\r\n"
        "a cute couple. {Press}";
};

void EventScript_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_FollowupLilliaDialogue(void)
{
    if (VarGet(VAR_LILLIA_AND_SASHA_REMINISCE_ABOUT_JEFFS_MARRIAGE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_LILLIA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        if (WasNpcSpokenToJustNow(CHARACTER_LILLIA) == FALSE)
        {
            SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_LILLIA);
            TalkMessage(gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_FollowupLilliaDialogue_LilliaValuesHavingHusbandByHerSide);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_LILLIA);
            TalkMessage(gText_NPCEvent_LilliaAndSasha_ReminisceAboutJeffsMarriage_FollowupLilliaDialogue_LilliaSaysSashaAndJeffMakeAGoodCouple);
        }
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_LILLIA);
        SetEntityFacing(ENTITY_LILLIA, FACING_LEFT);
    }
}
