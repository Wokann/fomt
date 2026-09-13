#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Thomas_ThatWasFunYouShouldHave[] =
        "That was fun! \r\n"
        "You should have joined in,\r\n"
        "{Player}. {Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Thomas_ThatWasAGreatMatchBring[] =
        "That was a great match!\r\n"
        "Bring {Var1} back \r\n"
        "next year! {Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Thomas_ThatWasAGreatBout[] =
        "That was a great bout!{Press}";
};

void EventScript_FestivalEvent_ChickenFestival_PostTournamentDialogue_Thomas(void)
{
    int var_0;
    var_0 = GetContestAnimalIndex(ANIMAL_KIND_CHICKEN);
    GetAnimalName(TEXT_VARIABLE_1, ANIMAL_KIND_CHICKEN, var_0);
    if (HasMetNpc(CHARACTER_THOMAS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_THOMAS);
    }
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_CHICKEN_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Thomas_ThatWasFunYouShouldHave);
    }
    else
    {
        if (VarGet(VAR_CHICKEN_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Thomas_ThatWasAGreatMatchBring);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Thomas_ThatWasAGreatBout);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_THOMAS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_THOMAS, 5);
    }
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
}
