#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Elli_03_BlueHeart_RefusalResponse_FollowupEllenRelievedStuReturned[] =
        "I'm so glad Stu is back!{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_HelpResponse_FollowupEllenPraisesPlayer[] =
        "You are very kind, \r\n"
        "{Player}.{Press}";
};

void EventScript_LoveEvent_Elli_03_BlueHeart_FindStuAndReceiveDriedFlowers_FollowupEllenDialogue(void)
{
    if (VarGet(VAR_ELLI_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    if (VarGet(VAR_ELLI_BLUE_HEART_EVENT_CHOICE) == ELLI_BLUE_HEART_RESPONSE_REFUSE_TO_SEARCH)
    {
        SetEntityFacing(ENTITY_ELLEN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ELLEN);
        TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_RefusalResponse_FollowupEllenRelievedStuReturned);
        TalkClose();
        SetEntityFacing(ENTITY_ELLEN, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_ELLEN);
    }
    else
    {
        SetEntityFacing(ENTITY_ELLEN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ELLEN);
        TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_HelpResponse_FollowupEllenPraisesPlayer);
        TalkClose();
        SetEntityFacing(ENTITY_ELLEN, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_ELLEN);
    }
}
