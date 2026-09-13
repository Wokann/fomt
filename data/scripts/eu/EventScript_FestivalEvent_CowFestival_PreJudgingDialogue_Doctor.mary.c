#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Doctor_YouShouldDrinkMilkEverydayYou[] =
        "You should drink Milk \r\n"
        "everyday, you know. {Press}";

    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Doctor_DoYouThinkYouHaveA[] =
        "Do you think you have a \r\n"
        "chance of winning? {Press}";
};

void EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_Doctor(void)
{
    if (HasMetNpc(CHARACTER_DOCTOR) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DOCTOR);
    }
    SetEntityFacing(ENTITY_DOCTOR, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_DOCTOR);
        TalkMessage(gText_FestivalEvent_CowFestival_PreJudgingDialogue_Doctor_YouShouldDrinkMilkEverydayYou);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_DOCTOR);
        TalkMessage(gText_FestivalEvent_CowFestival_PreJudgingDialogue_Doctor_DoYouThinkYouHaveA);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_DOCTOR) == FALSE)
    {
        AddNpcFriendship(CHARACTER_DOCTOR, 5);
    }
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
    SetEntityFacing(ENTITY_DOCTOR, FACING_DOWN);
}
