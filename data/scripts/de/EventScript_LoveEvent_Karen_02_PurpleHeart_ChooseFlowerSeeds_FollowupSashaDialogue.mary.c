#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupSasha_FavorableChoice[] =
        "Hmm...\r\n"
        "Ich denke, meine Samen \r\n"
        "waren besser.{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupSasha_UnfavorableChoice[] =
        "Du hast dieselben \r\n"
        "Samen wie ich gewählt. Gut.{Press}";
};

void EventScript_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupSashaDialogue(void)
{
    if (VarGet(VAR_KAREN_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    if (VarGet(VAR_KAREN_PURPLE_HEART_EVENT_CHOICE) == KAREN_PURPLE_HEART_RESPONSE_MOONDROP_SEEDS)
    {
        SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SASHA_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_SASHA);
        TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupSasha_FavorableChoice);
        TalkClose();
        SetEntityFacing(ENTITY_SASHA, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    else
    {
        SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_SASHA);
        TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupSasha_UnfavorableChoice);
        TalkClose();
        SetEntityFacing(ENTITY_SASHA, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
}
