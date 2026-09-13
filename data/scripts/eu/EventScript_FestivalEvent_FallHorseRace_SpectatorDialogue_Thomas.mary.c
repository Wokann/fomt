#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Thomas_ThisIsWhereYouCanPlace[] =
        "This is where you can place \r\n"
        "your bets or exchange race\r\n"
        "medals for prizes.{Press}\p"
        "Also, come to me when \r\n"
        "you're ready to race. {Press}";

    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Thomas_YouCanBetEvenIfYou[] =
        "You can bet even if you\r\n"
        "race, you know. Most people\r\n"
        "bet on themselves. {Press}";
};

void EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Thomas(void)
{
    if (HasMetNpc(CHARACTER_THOMAS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_THOMAS);
    }
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Thomas_ThisIsWhereYouCanPlace);
        TalkClose();
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Thomas_YouCanBetEvenIfYou);
        TalkClose();
    }
    if (WasNpcSpokenToToday(CHARACTER_THOMAS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_THOMAS, 5);
    }
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
}
