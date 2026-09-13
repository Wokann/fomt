#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_04_YellowHeart_TasteHomeCooking_FollowupKarenDialogue[] =
        "Es wird dir Leid tun, dass \r\n"
        "du sie nicht gegessen \r\n"
        "hast, {Player}!{Press}\p"
        "Sie sind sicher lecker!\r\n"
        "...denke ich...{Press}";
};

void EventScript_LoveEvent_Karen_04_YellowHeart_TasteHomeCooking_FollowupKarenDialogue(void)
{
    if (VarGet(VAR_KAREN_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_04_YellowHeart_TasteHomeCooking_FollowupKarenDialogue);
    TalkClose();
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_KAREN);
}
