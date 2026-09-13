#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Basil_GoodGirlILoveAnimalsEspecially[] =
        "Good girl...\r\n"
        "I love animals, especially \r\n"
        "gentle ones like Cows!{Press}";

    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Basil_IThinkYourCowHasA[] =
        "I think your Cow has a \r\n"
        "great face, {Player}. {Press}";
};

void EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_Basil(void)
{
    if (HasMetNpc(CHARACTER_BASIL) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_BASIL);
    }
    SetEntityFacing(ENTITY_BASIL, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_BASIL);
        TalkMessage(gText_FestivalEvent_CowFestival_PreJudgingDialogue_Basil_GoodGirlILoveAnimalsEspecially);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_BASIL);
        TalkMessage(gText_FestivalEvent_CowFestival_PreJudgingDialogue_Basil_IThinkYourCowHasA);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_BASIL) == FALSE)
    {
        AddNpcFriendship(CHARACTER_BASIL, 5);
    }
    MarkNpcSpokenTo(CHARACTER_BASIL);
    SetEntityFacing(ENTITY_BASIL, FACING_UP);
}
