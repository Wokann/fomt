#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FallHorseRace_Invitation_NoHorseAvailable[] =
        "Tomorrow is the Fall \r\n"
        "Horse Racing in the Square.{Press}\p"
        "If you have a Horse that\r\n"
        "can enter, you should \r\n"
        "give it a try. {Press}";

    const char gText_FestivalEvent_FallHorseRace_Invitation_HorseTooYoung[] =
        "Tomorrow is the Fall \r\n"
        "Horse Racing in the Square.{Press}\p"
        "If you have a good Horse, \r\n"
        "you should try entering.{Press}";

    const char gText_FestivalEvent_FallHorseRace_Invitation_EligibleAdultHorseInvitation[] =
        "Hi, {Player}. \r\n"
        "Tomorrow is the Horse \r\n"
        "Races in the Square. {Press}\p"
        "You thinking of entering?{Press}";

    const char gText_FestivalEvent_FallHorseRace_Invitation_AcceptEntryChoice[] =
        "Yes.";

    const char gText_FestivalEvent_FallHorseRace_Invitation_DeclineEntryChoice[] =
        "No.";

    const char gText_FestivalEvent_FallHorseRace_Invitation_ThomasTakesHorseForEntry[] =
        "In that case, I'll take \r\n"
        "{Horse} with me now.\r\n"
        "Be there by 10AM tomorrow!{Press}";

    const char gText_FestivalEvent_FallHorseRace_Invitation_ThomasEncouragesAttendanceAfterDecline[] =
        "That's too bad. \r\n"
        "You should still come and \r\n"
        "bet on the races, though. \r\n"
        "It's fun!{Press}";
};

void EventScript_FestivalEvent_FallHorseRace_Invitation(void)
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
        TalkMessage(gText_FestivalEvent_FallHorseRace_Invitation_NoHorseAvailable);
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
            TalkMessage(gText_FestivalEvent_FallHorseRace_Invitation_HorseTooYoung);
            TalkClose();
            PrepareHorseRaceEntries(FESTIVAL_HORSE_RACE_ENTRIES_NPC_ONLY);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_FestivalEvent_FallHorseRace_Invitation_EligibleAdultHorseInvitation);
            TalkClose();
            TalkOpen();
            var_0 = TalkChoice2(gText_FestivalEvent_FallHorseRace_Invitation_AcceptEntryChoice, gText_FestivalEvent_FallHorseRace_Invitation_DeclineEntryChoice);
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
                    TalkMessage(gText_FestivalEvent_FallHorseRace_Invitation_ThomasTakesHorseForEntry);
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
                    VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_SELECTED);
                    SetContestAnimal(ANIMAL_KIND_HORSE, ANIMAL_SLOT_1);
                    VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_COMPLETED);
                    return;
                case CHOICE_OPTION_2:
                    PrepareHorseRaceEntries(FESTIVAL_HORSE_RACE_ENTRIES_NPC_ONLY);
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_THOMAS);
                    TalkMessage(gText_FestivalEvent_FallHorseRace_Invitation_ThomasEncouragesAttendanceAfterDecline);
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
    VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_NOT_SELECTED);
    VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_COMPLETED);
}
