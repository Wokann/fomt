#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HorseRace_EntryInvitation_NoHorse[] =
        "明日は広場で草競馬が\r\n"
        "あるんだが、\r\n"
        "知っているかね。{Press}\p"
        "キミの牧場にも馬がいれば\r\n"
        "エントリーして\r\n"
        "もらいたかったんだけど…{Press}";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_YoungHorse[] =
        "明日は広場で草競馬が\r\n"
        "あるんだが、\r\n"
        "知っているかね。{Press}\p"
        "キミの牧場にも大きな馬が\r\n"
        "いればエントリーして\r\n"
        "もらいたかったんだけど…{Press}";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ThomasAsksPlayerToEnterAdultHorse[] =
        "やあ、{Player}くん。\r\n"
        "明日は広場で、草競馬が\r\n"
        "行われるんだよ。{Press}\p"
        "キミも草競馬に\r\n"
        "エントリーするかい？{Press}";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ChoiceEnterHorse[] =
        "エントリーする";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ChoiceDeclineEntry[] =
        "エントリーしない";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ThomasAcceptsHorseRaceEntry[] =
        "じゃあ、{Horse}は\r\n"
        "連れていくよ。草競馬は\r\n"
        "朝の１０時からだからね。{Press}";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ThomasSuggestsSpectatingAndBettingAfterDecline[] =
        "そうか、でも、草競馬は\r\n"
        "チケットを買ったりする\r\n"
        "こともできるから、{Press}\r\n"
        "明日は、ぜひ遊びにおいで。{Press}";
};

void EventScript_FestivalEvent_HorseRace_EntryInvitation(void)
{
    int var_0;
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_THOMAS, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (VarGet(VAR_HAS_HORSE) == FALSE)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_HorseRace_EntryInvitation_NoHorse);
        TalkClose();
        PrepareHorseRaceEntries(FESTIVAL_HORSE_RACE_ENTRIES_NPC_ONLY);
    }
    else
    {
        if (VarGet(VAR_HORSE_GROWTH_STAGE) == ANIMAL_PET_GROWTH_STAGE_YOUNG)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_FestivalEvent_HorseRace_EntryInvitation_YoungHorse);
            TalkClose();
            PrepareHorseRaceEntries(FESTIVAL_HORSE_RACE_ENTRIES_NPC_ONLY);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_FestivalEvent_HorseRace_EntryInvitation_ThomasAsksPlayerToEnterAdultHorse);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice2(gText_FestivalEvent_HorseRace_EntryInvitation_ChoiceEnterHorse, gText_FestivalEvent_HorseRace_EntryInvitation_ChoiceDeclineEntry);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    TalkClose();
                    PrepareHorseRaceEntries(FESTIVAL_HORSE_RACE_ENTRIES_INCLUDE_PLAYER_HORSE);
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    SetEntityPosition(ENTITY_THOMAS, X(242), Y(145), FACING_UP);
                    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
                    SetEntityPosition(ENTITY_FARM_HORSE, X(212), Y(145), FACING_UP);
                    SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FARM_HORSE_IDLE);
                    StopEntityEffect(ENTITY_FARM_HORSE);
                    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_THOMAS);
                    TalkMessage(gText_FestivalEvent_HorseRace_EntryInvitation_ThomasAcceptsHorseRaceEntry);
                    TalkClose();
                    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_WALK);
                    SetEntityFacing(ENTITY_THOMAS, FACING_RIGHT);
                    MoveEntityXTo(ENTITY_THOMAS, X(330), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                    WaitForEntityMovement(ENTITY_THOMAS);
                    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
                    SetEntityFacing(ENTITY_THOMAS, FACING_LEFT);
                    SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FARM_HORSE_WALK);
                    SetEntityFacing(ENTITY_FARM_HORSE, FACING_RIGHT);
                    MoveEntityXTo(ENTITY_FARM_HORSE, X(305), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                    WaitForEntityMovement(ENTITY_FARM_HORSE);
                    SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FARM_HORSE_IDLE);
                    WaitFrames(30);
                    SetEntityFacing(ENTITY_FARM_HORSE, FACING_UP);
                    SetEntityFacing(ENTITY_THOMAS, FACING_UP);
                    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_WALK);
                    MoveEntityYTo(ENTITY_THOMAS, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                    SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FARM_HORSE_WALK);
                    MoveEntityYTo(ENTITY_FARM_HORSE, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                    WaitForEntityMovement(ENTITY_THOMAS);
                    WaitForEntityMovement(ENTITY_FARM_HORSE);
                    HideEntity(ENTITY_THOMAS);
                    HideEntity(ENTITY_FARM_HORSE);
                    VarSet(VAR_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_SELECTED);
                    SetContestAnimal(ANIMAL_KIND_HORSE, ANIMAL_SLOT_1);
                    VarSet(VAR_FESTIVAL_HORSE_RACE_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_COMPLETED);
                    return;
                case CHOICE_OPTION_2:
                    PrepareHorseRaceEntries(FESTIVAL_HORSE_RACE_ENTRIES_NPC_ONLY);
                    TalkClose();
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_THOMAS);
                    TalkMessage(gText_FestivalEvent_HorseRace_EntryInvitation_ThomasSuggestsSpectatingAndBettingAfterDecline);
                    TalkClose();
                    break;
            }
        }
    }
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_WALK);
    SetEntityFacing(ENTITY_THOMAS, FACING_RIGHT);
    MoveEntityXTo(ENTITY_THOMAS, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_THOMAS);
    SetEntityFacing(ENTITY_THOMAS, FACING_UP);
    MoveEntityYTo(ENTITY_THOMAS, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_THOMAS);
    HideEntity(ENTITY_THOMAS);
    VarSet(VAR_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_NOT_SELECTED);
    VarSet(VAR_FESTIVAL_HORSE_RACE_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_COMPLETED);
}
