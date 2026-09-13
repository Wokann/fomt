#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Elli_03_BlueHeart_RefusalResponse_FollowupElliImprovesCooking[] =
        "Ich muss besser kochen\r\n"
        "lernen, Stu zuliebe!{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_HelpResponse_FollowupElliRetriesDinner[] =
        "Ich versuche es  \r\n"
        "später noch einmal. {Press}";
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
