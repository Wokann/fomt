#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_FollowupMaryDialogue_MaryIsNervousToShowHerNovelToItsFirstReader[] =
        "人に見せるの初めてだから\r\n"
        "キンチョウするな…{Press}";
};

void EventScript_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_FollowupMaryDialogue(void)
{
    SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_MARY);
    }
    TalkMessage(gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_FollowupMaryDialogue_MaryIsNervousToShowHerNovelToItsFirstReader);
    TalkClose();
    SetEntityFacing(ENTITY_MARY, FACING_LEFT);
    MarkNpcSpokenTo(CHARACTER_MARY);
}
