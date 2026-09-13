#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_DogEntryInvitation_Zack_Shared_FestivalAnnouncementAndAdultDogInvitation[] =
        "Morgen ist Strand- \r\n"
        "tag. {Press}\p"
        "Ich wollte dich und deinen\r\n"
        "Hund einladen. {Press}\p";

    const char gText_FestivalEvent_FrisbeeTournament_DogEntryInvitation_Zack_PuppyIneligibleExplanation[] =
        "Oh, dein Hund ist \r\n"
        "noch klein?{Press}\p"
        "Tut mir Leid, dann kann \r\n"
        "er nicht mitmachen. {Press}\p"
        "Komm trotzdem morgen\r\n"
        "um 10 Uhr an den Strand, \r\n"
        "wenn du Zeit hast. Tschüss.{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_DogEntryInvitation_Zack_ChoiceEnterDog[] =
        "Mitmachen.";

    const char gText_FestivalEvent_FrisbeeTournament_DogEntryInvitation_Zack_DontCompete[] =
        "Nicht mitmachen.";

    const char gText_FestivalEvent_FrisbeeTournament_DogEntryInvitation_Zack_InThatCaseIllTakeHim[] =
        "Wenn das so ist, nehme\r\n"
        "ich ihn jetzt mit. {Press}";

    const char gText_FestivalEvent_FrisbeeTournament_DogEntryInvitation_Zack_IfYouHaveTheTimeCome[] =
        "Komm trotzdem morgen\r\n"
        "um 10 Uhr an den Strand, \r\n"
        "du kannst zugucken. {Press}\r\n"
        "Tschüss dann.{Press}";
};

void EventScript_FestivalEvent_FrisbeeTournament_DogEntryInvitation_Zack(void)
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
    SetEntityPosition(ENTITY_ZACK, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (VarGet(VAR_DOG_GROWTH_STAGE) == ANIMAL_PET_GROWTH_STAGE_YOUNG)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ZACK);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_DogEntryInvitation_Zack_Shared_FestivalAnnouncementAndAdultDogInvitation);
        SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_DogEntryInvitation_Zack_PuppyIneligibleExplanation);
        TalkClose();
        SetEntityFacing(ENTITY_ZACK, FACING_RIGHT);
        SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_WALK);
        MoveEntityXTo(ENTITY_ZACK, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_ZACK);
        SetEntityFacing(ENTITY_ZACK, FACING_UP);
        MoveEntityYTo(ENTITY_ZACK, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_ZACK);
        HideEntity(ENTITY_ZACK);
        VarSet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED, FALSE);
        VarSet(VAR_FRISBEE_TOURNAMENT_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_COMPLETED);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ZACK);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_DogEntryInvitation_Zack_Shared_FestivalAnnouncementAndAdultDogInvitation);
        TalkClose();
        TalkOpen();
        var_0 = TalkChoice2(gText_FestivalEvent_FrisbeeTournament_DogEntryInvitation_Zack_ChoiceEnterDog, gText_FestivalEvent_FrisbeeTournament_DogEntryInvitation_Zack_DontCompete);
        switch (var_0)
        {
            case CHOICE_OPTION_1:
                TalkClose();
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                if (IsPlayerHoldingNothing() == TRUE)
                {
                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                }
                else
                {
                    if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_DOG)
                    {
                        UsePlayerHeldItem();
                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                    }
                }
                HideEntity(ENTITY_FARM_DOG);
                VarSet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED, TRUE);
                SetContestAnimal(ANIMAL_KIND_DOG, ANIMAL_SLOT_1);
                SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(212), Y(145), FACING_UP);
                SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_SMALL_ANIMAL);
                SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_FARM_DOG_IDLE);
                StopEntityEffect(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
                SetTalkNameplateCharacter(CHARACTER_ZACK);
                TalkMessage(gText_FestivalEvent_FrisbeeTournament_DogEntryInvitation_Zack_InThatCaseIllTakeHim);
                TalkClose();
                SetEntityFacing(ENTITY_ZACK, FACING_RIGHT);
                SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_WALK);
                MoveEntityXTo(ENTITY_ZACK, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_ZACK);
                SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
                SetEntityFacing(ENTITY_ZACK, FACING_LEFT);
                SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_RIGHT);
                SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_FARM_DOG_WALK);
                MoveEntityXTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(305), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
                SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_FARM_DOG_IDLE);
                WaitFrames(30);
                SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_UP);
                SetEntityFacing(ENTITY_ZACK, FACING_UP);
                SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_WALK);
                MoveEntityYTo(ENTITY_ZACK, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_FARM_DOG_WALK);
                MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_ZACK);
                WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
                SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
                SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_FARM_DOG_IDLE);
                SetEntityFacing(ENTITY_ZACK, FACING_DOWN);
                SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_UP);
                HideEntity(ENTITY_ZACK);
                HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
                VarSet(VAR_FRISBEE_TOURNAMENT_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_COMPLETED);
                break;
            case CHOICE_OPTION_2:
                SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_ZACK);
                TalkMessage(gText_FestivalEvent_FrisbeeTournament_DogEntryInvitation_Zack_IfYouHaveTheTimeCome);
                TalkClose();
                SetEntityFacing(ENTITY_ZACK, FACING_RIGHT);
                SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_WALK);
                MoveEntityXTo(ENTITY_ZACK, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_ZACK);
                SetEntityFacing(ENTITY_ZACK, FACING_UP);
                MoveEntityYTo(ENTITY_ZACK, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_ZACK);
                HideEntity(ENTITY_ZACK);
                VarSet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED, FALSE);
                VarSet(VAR_FRISBEE_TOURNAMENT_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_COMPLETED);
                break;
        }
    }
}
