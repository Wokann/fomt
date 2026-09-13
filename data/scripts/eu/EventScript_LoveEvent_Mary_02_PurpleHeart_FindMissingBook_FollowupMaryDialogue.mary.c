#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Mary_02_PurpleHeart_HelpResponse_FollowupMaryContinuesWriting[] =
        "Now I can get some more \r\n"
        "written on my novel. {Press}";

    const char gText_LoveEvent_Mary_02_PurpleHeart_RefusalResponse_FollowupMaryStillSearching[] =
        "I wonder where I put \r\n"
        "that...I can't write \r\n"
        "without it...{Press}";
};

void EventScript_LoveEvent_Mary_02_PurpleHeart_FindMissingBook_FollowupMaryDialogue(void)
{
    if (VarGet(VAR_MARY_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    if (VarGet(VAR_MARY_PURPLE_HEART_EVENT_CHOICE) == MARY_PURPLE_HEART_RESPONSE_HELP_FIND_BOOK)
    {
        SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_MARY);
        ShowTalkHeartIndicator(CHARACTER_MARY);
        TalkMessage(gText_LoveEvent_Mary_02_PurpleHeart_HelpResponse_FollowupMaryContinuesWriting);
        TalkClose();
        SetEntityFacing(ENTITY_MARY, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_MARY);
    }
    else
    {
        SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MARY_ANGRY);
        SetTalkNameplateCharacter(CHARACTER_MARY);
        ShowTalkHeartIndicator(CHARACTER_MARY);
        TalkMessage(gText_LoveEvent_Mary_02_PurpleHeart_RefusalResponse_FollowupMaryStillSearching);
        TalkClose();
        SetEntityFacing(ENTITY_MARY, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_MARY);
    }
}
