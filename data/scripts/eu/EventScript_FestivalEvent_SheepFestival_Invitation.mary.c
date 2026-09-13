#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_Invitation_NoSheepAvailable[] =
        "The Sheep Festival is \r\n"
        "tomorrow at Rose Square.{Press}\p"
        "Any adult Sheep that isn't \r\n"
        "pregnant, sick, or shorn \r\n"
        "can compete. {Press}\p"
        "I hope to see an entry from\r\n"
        "{Place1} next year. {Press}\r\n"
        "Hope to see you tomorrow!{Press}";

    const char gText_FestivalEvent_SheepFestival_Invitation_OnlyLambsAvailable[] =
        "The Sheep Festival is \r\n"
        "tomorrow at Rose Square.{Press}\p"
        "Any adult Sheep that isn't \r\n"
        "pregnant, sick, or shorn \r\n"
        "can compete. {Press}\p"
        "I hope to see a Sheep from\r\n"
        "{Place1} next year. {Press}\r\n"
        "It's fun; I hope you come!{Press}";

    const char gText_FestivalEvent_SheepFestival_Invitation_EligibleSheepInvitation[] =
        "The Sheep Festival is \r\n"
        "tomorrow at Rose Square.{Press}\p"
        "Do you want to enter a \r\n"
        "Sheep from {Place1}?{Press}";

    const char gText_FestivalEvent_SheepFestival_Invitation_AcceptEntryChoice[] =
        "Sure!";

    const char gText_FestivalEvent_SheepFestival_Invitation_DeclineEntryChoice[] =
        "Not this year.";

    const char gText_FestivalEvent_SheepFestival_Invitation_PromptSelectEligibleSheep[] =
        "Will you select which Sheep?\r\n"
        "Remember, it has to be \r\n"
        "adult, and can't be sick, {Press}\r\n"
        "pregnant, or shorn. {Press}";

    const char gText_FestivalEvent_SheepFestival_Invitation_ThomasRespondsToDeclinedEntry[] =
        "Really? And I thought \r\n"
        "your Sheep had a good \r\n"
        "chance, too...{Press}";

    const char gText_FestivalEvent_SheepFestival_Invitation_NoEligibleAdultSheep[] =
        "The Sheep Festival is \r\n"
        "tomorrow at Rose Square.{Press}\p"
        "Any adult Sheep that isn't \r\n"
        "pregnant, sick, or shorn \r\n"
        "can compete. {Press}\p"
        "You don't have any eligible\r\n"
        "Sheep, but I hope you can \r\n"
        "come watch anyway!{Press}";

    const char gText_FestivalEvent_SheepFestival_Invitation_ThomasTakesSelectedSheepForEntry[] =
        "I'll bring this one with \r\n"
        "me now, then. Don't forget \r\n"
        "to come tomorrow. {Press}";
};

void EventScript_FestivalEvent_SheepFestival_Invitation(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5;
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_BARLEY, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    var_1 = mary_negated_int(ANIMAL_SLOT_NOT_SELECTED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    if (CountAnimalsByLifeState(ANIMAL_KIND_SHEEP, LIVESTOCK_LIFE_STATE_ALIVE) == 0)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FestivalEvent_SheepFestival_Invitation_NoSheepAvailable);
        TalkClose();
    }
    else
    {
        var_2 = 0;
        var_3 = 0;
        var_4 = 0;
        for (var_5 = ANIMAL_SLOT_1; var_5 < 16; var_5++)
        {
            if (IsCowAtBarnSlot(var_5) == FALSE)
            {
                if (GetAnimalGrowthStage(ANIMAL_KIND_SHEEP, var_5) == ANIMAL_SHEEP_GROWTH_STAGE_ADULT)
                {
                    var_3++;
                    if (IsAnimalSick(ANIMAL_KIND_SHEEP, var_5) == FALSE && IsAnimalPregnant(ANIMAL_KIND_SHEEP, var_5) == FALSE && IsSheepSheared(var_5) == FALSE)
                    {
                        var_4++;
                    }
                }
                else
                {
                    var_2++;
                }
            }
        }
        if (var_2 > 0 && var_3 == 0)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BARLEY);
            TalkMessage(gText_FestivalEvent_SheepFestival_Invitation_OnlyLambsAvailable);
            TalkClose();
        }
        else
        {
            if (var_4 > 0)
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_BARLEY);
                TalkMessage(gText_FestivalEvent_SheepFestival_Invitation_EligibleSheepInvitation);
                TalkClose();
                TalkOpen();
                var_0 = TalkChoice2(gText_FestivalEvent_SheepFestival_Invitation_AcceptEntryChoice, gText_FestivalEvent_SheepFestival_Invitation_DeclineEntryChoice);
                TalkClose();
                if (var_0 == CHOICE_OPTION_1)
                {
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_BARLEY);
                    TalkMessage(gText_FestivalEvent_SheepFestival_Invitation_PromptSelectEligibleSheep);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    var_1 = SelectFestivalAnimal(FESTIVAL_ANIMAL_SHEEP);
                    if (var_1 != mary_negated_int(ANIMAL_SLOT_NOT_SELECTED))
                    {
                        GetAnimalName(TEXT_VARIABLE_1, ANIMAL_KIND_SHEEP, var_1);
                        SetEntityPosition(ENTITY_BARLEY, X(242), Y(145), FACING_UP);
                        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
                        SetEntityPosition(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, X(212), Y(145), FACING_UP);
                        SetEntityAnim(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, ANIMATION_SHEEP_IDLE);
                        StopEntityEffect(ENTITY_BARN_ANIMAL_SLOT_1 + var_1);
                    }
                    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                }
                else
                {
                    var_1 = mary_negated_int(ANIMAL_SLOT_NOT_SELECTED);
                }
                if (var_1 == mary_negated_int(ANIMAL_SLOT_NOT_SELECTED))
                {
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_BARLEY);
                    TalkMessage(gText_FestivalEvent_SheepFestival_Invitation_ThomasRespondsToDeclinedEntry);
                    TalkClose();
                }
            }
            else
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_BARLEY);
                TalkMessage(gText_FestivalEvent_SheepFestival_Invitation_NoEligibleAdultSheep);
                TalkClose();
            }
        }
    }
    if (var_1 == mary_negated_int(ANIMAL_SLOT_NOT_SELECTED))
    {
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        SetEntityFacing(ENTITY_BARLEY, FACING_RIGHT);
        MoveEntityXTo(ENTITY_BARLEY, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        SetEntityFacing(ENTITY_BARLEY, FACING_UP);
        MoveEntityYTo(ENTITY_BARLEY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        HideEntity(ENTITY_BARLEY);
        VarSet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_NOT_SELECTED);
        VarSet(VAR_SHEEP_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_COMPLETED);
        return;
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FestivalEvent_SheepFestival_Invitation_ThomasTakesSelectedSheepForEntry);
        TalkClose();
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        SetEntityFacing(ENTITY_BARLEY, FACING_RIGHT);
        MoveEntityXTo(ENTITY_BARLEY, X(330), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
        SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
        SetEntityAnim(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, ANIMATION_SHEEP_WALK);
        SetEntityFacing(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, FACING_RIGHT);
        MoveEntityXTo(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, X(305), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARN_ANIMAL_SLOT_1 + var_1);
        SetEntityAnim(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, ANIMATION_SHEEP_IDLE);
        WaitFrames(30);
        SetEntityFacing(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, FACING_UP);
        SetEntityFacing(ENTITY_BARLEY, FACING_UP);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        MoveEntityYTo(ENTITY_BARLEY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        SetEntityAnim(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, ANIMATION_SHEEP_WALK);
        MoveEntityYTo(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        WaitForEntityMovement(ENTITY_BARN_ANIMAL_SLOT_1 + var_1);
        HideEntity(ENTITY_BARLEY);
        HideEntity(ENTITY_BARN_ANIMAL_SLOT_1 + var_1);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        VarSet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_SELECTED);
        SetContestAnimal(ANIMAL_KIND_SHEEP, var_1);
        VarSet(VAR_SHEEP_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_COMPLETED);
    }
}
