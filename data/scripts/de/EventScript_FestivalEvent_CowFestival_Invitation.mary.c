#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_Invitation_NoCows[] =
        "Das Kuhfestival ist\r\n"
        "morgen auf dem Rosenplatz. {Press}\p"
        "Wenn du eine ausgewachsene,\r\n"
        "nicht trächtige, gesunde\r\n"
        "Kuh hast, kannst du {Press}\r\n"
        "teilnehmen. {Press}\p"
        "Ich hoffe, nächstes Jahr\r\n"
        "eine Kuh von {Place1}\r\n"
        "zu sehen.{Press}\p"
        "Bis morgen! {Press}";

    const char gText_FestivalEvent_CowFestival_Invitation_OnlyCalves[] =
        "Das Kuhfestival ist\r\n"
        "morgen auf dem Rosenplatz. {Press}\p"
        "Wenn du eine ausgewachsene,\r\n"
        "nicht trächtige, gesunde\r\n"
        "Kuh hast, kannst du {Press}\r\n"
        "teilnehmen. {Press}\p"
        "Ich wette, du kannst \r\n"
        "nächstes Jahr teilnehmen.{Press}\r\n"
        "Bis morgen! {Press}";

    const char gText_FestivalEvent_CowFestival_Invitation_EligibleCowAvailable[] =
        "Das Kuhfestival ist\r\n"
        "morgen auf dem Rosenplatz.{Press}\p"
        "Lässt du eine Kuh von \r\n"
        "{Place1} teilnehmen?{Press}";

    const char gText_FestivalEvent_CowFestival_Invitation_IWill[] =
        "Werde ich.";

    const char gText_FestivalEvent_CowFestival_Invitation_IWont[] =
        "Werde ich nicht.";

    const char gText_FestivalEvent_CowFestival_Invitation_WillYouSelectACowThen[] =
        "Dann wähle eine Kuh.{Press}\p"
        "Es muss eine ausgewachs-\r\n"
        "ene Milchkuh sein. Sie\r\n"
        "darf nicht krank {Press}\r\n"
        "oder trächtig sein. {Press}";

    const char gText_FestivalEvent_CowFestival_Invitation_ThatsTooBadIThoughtYou[] =
        "Das ist zu schade... \r\n"
        "Ich dachte, du hättest\r\n"
        "eine gute Chance. {Press}";

    const char gText_FestivalEvent_CowFestival_Invitation_NoEligibleAdultCow[] =
        "Das Kuhfestival ist\r\n"
        "morgen auf dem Rosenplatz. {Press}\p"
        "Wenn du eine ausgewachsene,\r\n"
        "nicht trächtige, gesunde\r\n"
        "Kuh hast, kannst du {Press}\r\n"
        "teilnehmen. {Press}\p"
        "Ich sehe, dass du keine \r\n"
        "geeignete Kuh hast.{Press}\p"
        "Bis morgen! {Press}";

    const char gText_FestivalEvent_CowFestival_Invitation_IllBringThisCowWithMe[] =
        "Ich werde diese Kuh \r\n"
        "dann mitbringen. \r\n"
        "Bis morgen!{Press}";
};

void EventScript_FestivalEvent_CowFestival_Invitation(void)
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
    if (CountAnimalsByLifeState(ANIMAL_KIND_COW, LIVESTOCK_LIFE_STATE_ALIVE) == 0)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FestivalEvent_CowFestival_Invitation_NoCows);
        TalkClose();
    }
    else
    {
        var_2 = 0;
        var_3 = 0;
        var_4 = 0;
        for (var_5 = ANIMAL_SLOT_1; var_5 < 16; var_5++)
        {
            if (IsCowAtBarnSlot(var_5))
            {
                if (GetAnimalGrowthStage(ANIMAL_KIND_COW, var_5) == ANIMAL_COW_GROWTH_STAGE_ADULT)
                {
                    var_3++;
                    if (IsAnimalSick(ANIMAL_KIND_COW, var_5) == FALSE && IsAnimalPregnant(ANIMAL_KIND_COW, var_5) == FALSE)
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
            TalkMessage(gText_FestivalEvent_CowFestival_Invitation_OnlyCalves);
            TalkClose();
        }
        else
        {
            if (var_4 > 0)
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_BARLEY);
                TalkMessage(gText_FestivalEvent_CowFestival_Invitation_EligibleCowAvailable);
                TalkClose();
                TalkOpen();
                var_0 = TalkChoice2(gText_FestivalEvent_CowFestival_Invitation_IWill, gText_FestivalEvent_CowFestival_Invitation_IWont);
                TalkClose();
                if (var_0 == CHOICE_OPTION_1)
                {
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_BARLEY);
                    TalkMessage(gText_FestivalEvent_CowFestival_Invitation_WillYouSelectACowThen);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    var_1 = SelectFestivalAnimal(FESTIVAL_ANIMAL_COW);
                    if (var_1 != mary_negated_int(ANIMAL_SLOT_NOT_SELECTED))
                    {
                        GetAnimalName(TEXT_VARIABLE_1, ANIMAL_KIND_COW, var_1);
                        SetEntityPosition(ENTITY_BARLEY, X(242), Y(145), FACING_UP);
                        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
                        SetEntityPosition(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, X(212), Y(145), FACING_UP);
                        SetEntityAnim(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, ANIMATION_COW_IDLE);
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
                    TalkMessage(gText_FestivalEvent_CowFestival_Invitation_ThatsTooBadIThoughtYou);
                    TalkClose();
                }
            }
            else
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_BARLEY);
                TalkMessage(gText_FestivalEvent_CowFestival_Invitation_NoEligibleAdultCow);
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
        VarSet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_NOT_SELECTED);
        VarSet(VAR_COW_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_COMPLETED);
        return;
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FestivalEvent_CowFestival_Invitation_IllBringThisCowWithMe);
        TalkClose();
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        SetEntityFacing(ENTITY_BARLEY, FACING_RIGHT);
        MoveEntityXTo(ENTITY_BARLEY, X(330), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
        SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
        SetEntityAnim(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, ANIMATION_COW_WALK);
        SetEntityFacing(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, FACING_RIGHT);
        MoveEntityXTo(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, X(305), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARN_ANIMAL_SLOT_1 + var_1);
        SetEntityAnim(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, ANIMATION_COW_IDLE);
        WaitFrames(30);
        SetEntityFacing(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, FACING_UP);
        SetEntityFacing(ENTITY_BARLEY, FACING_UP);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        MoveEntityYTo(ENTITY_BARLEY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        SetEntityAnim(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, ANIMATION_COW_WALK);
        MoveEntityYTo(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        WaitForEntityMovement(ENTITY_BARN_ANIMAL_SLOT_1 + var_1);
        HideEntity(ENTITY_BARLEY);
        HideEntity(ENTITY_BARN_ANIMAL_SLOT_1 + var_1);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        VarSet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_SELECTED);
        SetContestAnimal(ANIMAL_KIND_COW, var_1);
        VarSet(VAR_COW_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_COMPLETED);
    }
}
