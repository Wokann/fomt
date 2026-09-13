#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_FollowupGrayDialogue_GrayLooksForwardToReadingMarysNovel[] =
        "Marys Roman! Ich kann\r\n"
        "es kaum erwarten! {Press}";
};

void EventScript_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_FollowupGrayDialogue(void)
{
    SetEntityFacing(ENTITY_GRAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_FollowupGrayDialogue_GrayLooksForwardToReadingMarysNovel);
    TalkClose();
    SetEntityFacing(ENTITY_GRAY, FACING_RIGHT);
    MarkNpcSpokenTo(CHARACTER_GRAY);
}
