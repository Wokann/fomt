#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ChickenFestival_Opening_MayWeBeginTheChickenFestival[] =
        "May we begin the \r\n"
        "Chicken Festival now? {Press}";

    const char gText_FestivalEvent_ChickenFestival_Opening_ChoiceStartFestival[] =
        "Yes, let's start.";

    const char gText_FestivalEvent_ChickenFestival_Opening_NotYet[] =
        "Not yet.";

    const char gText_FestivalEvent_ChickenFestival_Opening_LetsStartThen[] =
        "Let's start then! {Press}";

    const char gText_FestivalEvent_ChickenFestival_Opening_LetMeKnowWhenYoureReady[] =
        "Let me know when you're \r\n"
        "ready. {Press}";
};

void EventScript_FestivalEvent_ChickenFestival_Opening(void)
{
    int unused_0, var_1;
    if (HasMetNpc(CHARACTER_RICK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_RICK);
    }
    SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_FestivalEvent_ChickenFestival_Opening_MayWeBeginTheChickenFestival);
    TalkClose();
    TalkOpen();
    var_1 = TalkChoice2(gText_FestivalEvent_ChickenFestival_Opening_ChoiceStartFestival, gText_FestivalEvent_ChickenFestival_Opening_NotYet);
    switch (var_1)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_RICK);
            TalkMessage(gText_FestivalEvent_ChickenFestival_Opening_LetsStartThen);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            if (WasNpcSpokenToToday(CHARACTER_POPURI) == FALSE)
            {
                AddNpcFriendship(CHARACTER_RICK, 5);
            }
            MarkNpcSpokenTo(CHARACTER_RICK);
            SetEntityFacing(ENTITY_RICK, FACING_LEFT);
            if (VarGet(VAR_CHICKEN_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
            {
                CallScript(EventScript_FestivalEvent_ChickenFestival_Closing);
            }
            else
            {
                VarSet(VAR_CHICKEN_FESTIVAL_RESULT, RunChickenFestivalContest());
                if (VarGet(VAR_CHICKEN_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
                {
                    CallScript(EventScript_FestivalEvent_ChickenFestival_PlayerVictory);
                }
                else
                {
                    CallScript(EventScript_FestivalEvent_ChickenFestival_Closing);
                }
            }
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_RICK);
            TalkMessage(gText_FestivalEvent_ChickenFestival_Opening_LetMeKnowWhenYoureReady);
            TalkClose();
            break;
    }
    if (WasNpcSpokenToToday(CHARACTER_POPURI) == FALSE)
    {
        AddNpcFriendship(CHARACTER_RICK, 5);
    }
    MarkNpcSpokenTo(CHARACTER_RICK);
    SetEntityFacing(ENTITY_RICK, FACING_LEFT);
}
