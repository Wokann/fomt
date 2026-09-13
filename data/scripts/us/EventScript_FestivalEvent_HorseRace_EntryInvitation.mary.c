#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HorseRace_EntryInvitation_SharedNoHorseOrYoungHorse[] =
        "The Horse Races are \r\n"
        "tomorrow at the Square, you\r\n"
        "know...{Press}\p"
        "If you've got a Horse, you\r\n"
        "should consider competing!{Press}";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ThomasAsksPlayerToEnterAdultHorse[] =
        "Hi there, {Player}. \r\n"
        "Are you going to compete\r\n"
        "in the Horse Races in the {Press}\r\n"
        "Square tomorrow?{Press}";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ChoiceEnterHorse[] =
        "I'll compete.";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ChoiceDeclineEntry[] =
        "I don't think so.";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ThomasAcceptsHorseRaceEntry[] =
        "In that case, bring\r\n"
        "{Horse} to \r\n"
        "the Square by 10AM. {Press}";

    const char gText_FestivalEvent_HorseRace_EntryInvitation_ThomasSuggestsSpectatingAndBettingAfterDecline[] =
        "Really?...\r\n"
        "Well, you can still \r\n"
        "place bets on the Race.{Press}\r\n"
        "It's fun - you should come!{Press}";
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
        TalkMessage(gText_FestivalEvent_HorseRace_EntryInvitation_SharedNoHorseOrYoungHorse);
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
            TalkMessage(gText_FestivalEvent_HorseRace_EntryInvitation_SharedNoHorseOrYoungHorse);
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
