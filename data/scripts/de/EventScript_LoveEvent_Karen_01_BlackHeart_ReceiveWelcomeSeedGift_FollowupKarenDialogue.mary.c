#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupKarenDialogue[] =
        "Frage nur meinen Vater, \r\n"
        "wenn du etwas über Samen\r\n"
        "oder Gegenstände {Press}\r\n"
        "wissen willst. {Press}";
};

void EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupKarenDialogue(void)
{
    if (VarGet(VAR_KAREN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupKarenDialogue);
    TalkClose();
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_KAREN);
}
