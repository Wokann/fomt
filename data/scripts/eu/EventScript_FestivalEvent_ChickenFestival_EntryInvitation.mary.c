#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ChickenFestival_EntryInvitation_NoChickensAvailable[] =
        "The Chicken Festival is \r\n"
        "tomorrow in Rose Square.{Press}\p"
        "We'll see who is the \r\n"
        "strongest Chicken of all!{Press}\p"
        "I was going to invite you, \r\n"
        "but it seems you don't have\r\n"
        "an eligible Chicken. {Press}";

    const char gText_FestivalEvent_ChickenFestival_EntryInvitation_OnlyBabyChicksAvailable[] =
        "The Chicken Festival is \r\n"
        "tomorrow in Rose Square.{Press}\p"
        "We'll see who is the \r\n"
        "strongest Chicken of all!{Press}\p"
        "Baby Chicks can't compete,\r\n"
        "though. It's too dangerous.{Press}";

    const char gText_FestivalEvent_ChickenFestival_EntryInvitation_HealthyAdultChickenAvailableEntryPrompt[] =
        "The Chicken Festival is \r\n"
        "tomorrow in Rose Square.{Press}\p"
        "We'll see who is the \r\n"
        "strongest Chicken of all!{Press}\p"
        "Do you want to enter? {Press}";

    const char gText_FestivalEvent_ChickenFestival_EntryInvitation_ChoiceEnterChicken[] =
        "Yes, I do.";

    const char gText_FestivalEvent_ChickenFestival_EntryInvitation_ChoiceDeclineEntry[] =
        "No, I don't.";

    const char gText_FestivalEvent_ChickenFestival_EntryInvitation_WillYouSelectWhichChickenYou[] =
        "Will you select which \r\n"
        "Chicken you want to compete?{Press}";

    const char gText_FestivalEvent_ChickenFestival_EntryInvitation_AdultChickensExistButNoneAreHealthy[] =
        "The Chicken Festival is \r\n"
        "tomorrow in Rose Square.{Press}\p"
        "We'll see who is the \r\n"
        "strongest Chicken of all!{Press}\p"
        "I was going to invite you, \r\n"
        "but it looks like none of \r\n"
        "your Chickens is eligible. {Press}";

    const char gText_FestivalEvent_ChickenFestival_EntryInvitation_ItsFunToRootForOther[] =
        "It's fun to root for other \r\n"
        "Chickens, though, so you \r\n"
        "should come down, anyway! {Press}";

    const char gText_FestivalEvent_ChickenFestival_EntryInvitation_RickConfirmsSelectedChickenAndStartTime[] =
        "In that case, I'll bring \r\n"
        "{Var1} along now.\r\n"
        "It starts at 10AM. {Press}";
};

void EventScript_FestivalEvent_ChickenFestival_EntryInvitation(void)
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
    SetEntityPosition(ENTITY_RICK, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    var_1 = mary_negated_int(-1);
    var_0 = 2;
    var_5 = 0;
    var_2 = 0;
    var_3 = 0;
    for (var_4 = ANIMAL_CHICKEN_SLOT_1; var_4 < 8; var_4++)
    {
        if (DoesAnimalExist(ANIMAL_KIND_CHICKEN, var_4))
        {
            var_5++;
            if (GetAnimalGrowthStage(ANIMAL_KIND_CHICKEN, var_4) == ANIMAL_CHICKEN_GROWTH_STAGE_ADULT)
            {
                if (IsAnimalSick(ANIMAL_KIND_CHICKEN, var_4) == FALSE)
                {
                    var_3++;
                }
            }
            else
            {
                var_2++;
            }
        }
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    if (var_5 == 0)
    {
        TalkMessage(gText_FestivalEvent_ChickenFestival_EntryInvitation_NoChickensAvailable);
    }
    else
    {
        if (var_2 >= var_5)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_RICK);
            TalkMessage(gText_FestivalEvent_ChickenFestival_EntryInvitation_OnlyBabyChicksAvailable);
        }
        else
        {
            if (var_3 > 0)
            {
                TalkMessage(gText_FestivalEvent_ChickenFestival_EntryInvitation_HealthyAdultChickenAvailableEntryPrompt);
                TalkClose();
                TalkOpen();
                var_0 = TalkChoice2(gText_FestivalEvent_ChickenFestival_EntryInvitation_ChoiceEnterChicken, gText_FestivalEvent_ChickenFestival_EntryInvitation_ChoiceDeclineEntry);
                TalkClose();
                if (var_0 == CHOICE_OPTION_1)
                {
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_RICK);
                    TalkMessage(gText_FestivalEvent_ChickenFestival_EntryInvitation_WillYouSelectWhichChickenYou);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    var_1 = SelectFestivalAnimal(FESTIVAL_ANIMAL_CHICKEN);
                    SetEntityPosition(ENTITY_RICK, X(228), Y(145), FACING_UP);
                    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
                    if (IsPlayerHoldingNothing() == TRUE)
                    {
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                    }
                    else
                    {
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
                    }
                    if (var_1 != mary_negated_int(ANIMAL_CHICKEN_SLOT_NONE))
                    {
                        GetAnimalName(TEXT_VARIABLE_1, ANIMAL_KIND_CHICKEN, var_1);
                        if (!IsPlayerHoldingNothing() && GetPlayerHeldItemKind() == HELD_ITEM_KIND_CHICKEN && GetPlayerHeldChickenId() == var_1)
                        {
                            UsePlayerHeldItem();
                        }
                        HideEntity(ENTITY_ANIMAL_CHICKEN_SLOT_1 + var_1);
                        VarSet(VAR_CHICKEN_FESTIVAL_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_SELECTED);
                        SetContestAnimal(ANIMAL_KIND_CHICKEN, var_1);
                        SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(212), Y(145), FACING_UP);
                        SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_SMALL_ANIMAL);
                        SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
                        StopEntityEffect(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
                    }
                    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                }
                if (var_1 == mary_negated_int(ANIMAL_CHICKEN_SLOT_NONE))
                {
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_RICK);
                }
            }
            else
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_RICK);
                TalkMessage(gText_FestivalEvent_ChickenFestival_EntryInvitation_AdultChickensExistButNoneAreHealthy);
            }
        }
    }
    if (var_1 == mary_negated_int(ANIMAL_CHICKEN_SLOT_NONE))
    {
        TalkMessage(gText_FestivalEvent_ChickenFestival_EntryInvitation_ItsFunToRootForOther);
        TalkClose();
        SetEntityFacing(ENTITY_RICK, FACING_RIGHT);
        SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WALK);
        MoveEntityXTo(ENTITY_RICK, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_RICK);
        SetEntityFacing(ENTITY_RICK, FACING_UP);
        MoveEntityYTo(ENTITY_RICK, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_RICK);
        HideEntity(ENTITY_RICK);
        VarSet(VAR_CHICKEN_FESTIVAL_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_NOT_SELECTED);
        VarSet(VAR_CHICKEN_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_COMPLETED);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_FestivalEvent_ChickenFestival_EntryInvitation_RickConfirmsSelectedChickenAndStartTime);
        TalkClose();
        SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WALK);
        SetEntityFacing(ENTITY_RICK, FACING_RIGHT);
        MoveEntityXTo(ENTITY_RICK, X(325), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_RICK);
        SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
        SetEntityFacing(ENTITY_RICK, FACING_LEFT);
        SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
        SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_RIGHT);
        MoveEntityXTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(305), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
        SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
        WaitFrames(30);
        SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_UP);
        SetEntityFacing(ENTITY_RICK, FACING_UP);
        SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WALK);
        MoveEntityYTo(ENTITY_RICK, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
        MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_RICK);
        WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
        HideEntity(ENTITY_RICK);
        HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        VarSet(VAR_CHICKEN_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_COMPLETED);
    }
}
