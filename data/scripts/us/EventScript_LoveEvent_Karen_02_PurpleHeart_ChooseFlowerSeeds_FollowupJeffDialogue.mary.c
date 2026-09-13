#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupJeff_FavorableChoice[] =
        "Thank goodness our quarrel\r\n"
        "is finally over...{Press}\p"
        "Thank you, {Player}. {Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupJeff_UnfavorableChoice[] =
        "I'm glad our quarrel ended,\r\n"
        "but Karen can hold a grudge\r\n"
        "for a long time...{Press}";
};

void EventScript_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupJeffDialogue(void)
{
    if (VarGet(VAR_KAREN_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    if (VarGet(VAR_KAREN_PURPLE_HEART_EVENT_CHOICE) == KAREN_PURPLE_HEART_RESPONSE_MOONDROP_SEEDS)
    {
        SetEntityFacing(ENTITY_JEFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_JEFF);
        TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupJeff_FavorableChoice);
        TalkClose();
        SetEntityFacing(ENTITY_JEFF, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_JEFF);
    }
    else
    {
        SetEntityFacing(ENTITY_JEFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_JEFF);
        TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupJeff_UnfavorableChoice);
        TalkClose();
        SetEntityFacing(ENTITY_JEFF, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_JEFF);
    }
}
