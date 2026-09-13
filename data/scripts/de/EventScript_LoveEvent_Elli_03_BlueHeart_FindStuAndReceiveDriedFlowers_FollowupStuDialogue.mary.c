#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Elli_03_BlueHeart_RefusalResponse_FollowupStuSilent[] =
        "........{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_HelpResponse_FollowupStuDreadsDinner[] =
        "Du musst nichts machen,\r\n"
        "wenn du nicht \r\n"
        "möchtest...{Press}";
};

void EventScript_LoveEvent_Elli_03_BlueHeart_FindStuAndReceiveDriedFlowers_FollowupStuDialogue(void)
{
    if (VarGet(VAR_ELLI_BLUE_HEART_EVENT_CHOICE) == ELLI_BLUE_HEART_RESPONSE_REFUSE_TO_SEARCH)
    {
        SetEntityFacing(ENTITY_STU, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_STU_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_STU);
        TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_RefusalResponse_FollowupStuSilent);
        TalkClose();
        SetEntityFacing(ENTITY_STU, FACING_UP);
        MarkNpcSpokenTo(CHARACTER_STU);
    }
    else
    {
        SetEntityFacing(ENTITY_STU, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_STU_ANGRY);
        SetTalkNameplateCharacter(CHARACTER_STU);
        TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_HelpResponse_FollowupStuDreadsDinner);
        TalkClose();
        SetEntityFacing(ENTITY_STU, FACING_UP);
        MarkNpcSpokenTo(CHARACTER_STU);
    }
}
