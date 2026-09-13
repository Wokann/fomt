#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Elli_03_BlueHeart_RefusalResponse_FollowupElliImprovesCooking[] =
        "I have to get better at \r\n"
        "cooking for Stu's sake!{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_HelpResponse_FollowupElliRetriesDinner[] =
        "I'm going to try \r\n"
        "again tonight. {Press}";
};

void EventScript_LoveEvent_Elli_03_BlueHeart_FindStuAndReceiveDriedFlowers_FollowupElliDialogue(void)
{
    if (VarGet(VAR_ELLI_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    if (VarGet(VAR_ELLI_BLUE_HEART_EVENT_CHOICE) == ELLI_BLUE_HEART_RESPONSE_REFUSE_TO_SEARCH)
    {
        SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
        ShowTalkHeartIndicator(CHARACTER_ELLI);
        SetTalkNameplateCharacter(CHARACTER_ELLI);
        TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_RefusalResponse_FollowupElliImprovesCooking);
        TalkClose();
        SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_ELLI);
    }
    else
    {
        SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ELLI);
        ShowTalkHeartIndicator(CHARACTER_ELLI);
        TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_HelpResponse_FollowupElliRetriesDinner);
        TalkClose();
        SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_ELLI);
    }
}
