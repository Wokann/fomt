#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Foal_OfferToPlayer_Barley_RequestIntroduction[] =
        "Hallo,{Player}.\r\n"
        "Ich würde dich gerne\r\n"
        "um einen Gefallen bitten.{Press}";

    const char gText_FarmEvent_Foal_OfferToPlayer_Barley_ExplainsFoalNeedsHome[] =
        "Dieses Fohlen ist auf unse-\r\n"
        "rer Farm geboren, aber aus\r\n"
        "irgendwelchen Gründen{Press}\r\n"
        "geht es ihm schlecht.{Press}\r\n"
        "Wir können nicht immer\r\n"
        "nach ihm sehen, meinst\r\n"
        "du, du kannst es{Press}\r\n"
        "für uns großziehen?{Press}";

    const char gText_FarmEvent_Foal_OfferToPlayer_Barley_DeclineRetry[] =
        "Sicher nicht?\r\n"
        "Wir haben echt{Press}";

    const char gText_FarmEvent_Foal_OfferToPlayer_Barley_FinalConfirmation[] =
        "Bist du sicher?{Press}";

    const char gText_FarmEvent_Foal_OfferToPlayer_ChoiceAccept[] =
        "Annehmen";

    const char gText_FarmEvent_Foal_OfferToPlayer_ChoiceDecline[] =
        "Nicht annehmen";

    const char gText_FarmEvent_Foal_OfferToPlayer_Barley_DeclinedResponse[] =
        "Hm, es war wohl \r\n"
        "falsch, sich auf dich zu\r\n"
        "verlassen!{Press}\r\n"
        "Tschüss dann.{Press}";

    const char gText_FarmEvent_Foal_OfferToPlayer_Barley_AcceptedThanks[] =
        "Das ist toll!\r\n"
        "Vielen Dank!{Press}\p"
        "In diesem Fall darfst \r\n"
        "du es benennen!{Press}";

    const char gText_FarmEvent_Foal_OfferToPlayer_Barley_HorseCareInstructions[] =
        "Du musst dir keine\r\n"
        "allzu großen Umstände\r\n"
        "machen.{Press}\p"
        "Pass auf es auf und gib\r\n"
        "ihm, was es braucht.{Press}\p"
        "Vergiss nicht, mit ihm\r\n"
        "zu sprechen - jeden\r\n"
        "Tag.{Press}\p"
        "Regelmäßig bürsten ist\r\n"
        "auch wichtig.{Press}";

    const char gText_FarmEvent_Foal_OfferToPlayer_Barley_MovesFoalToStable[] =
        "Ich bringe es für \r\n"
        "dich in den Stall.{Press}";

    const char gText_FarmEvent_Foal_OfferToPlayer_Barley_PromisesToCheckOnFoal[] =
        "Ich komme wieder, wenn\r\n"
        "es größer ist.{Press}\p"
        "Bis dahin pass gut\r\n"
        "auf das Fohlen auf.{Press}";
};

void EventScript_FarmEvent_Foal_OfferToPlayer(void)
{
    int var_0, var_1, var_2;
    var_2 = 0;
    CreateFarmHorse(FALSE, ANIMAL_HORSE_AGE_STAGE_FOAL, MAP_FARM, X(207), Y(145));
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
    SetEntityPosition(ENTITY_FARM_HORSE, X(207), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FOAL_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_FarmEvent_Foal_OfferToPlayer_Barley_RequestIntroduction);
    TalkClose();
    SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
    WaitFrames(60);
    SetEntityFacing(ENTITY_BARLEY, FACING_UP);
    do
    {
        switch (var_2)
        {
            case 0:
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_BARLEY_AFRAID);
                SetTalkNameplateCharacter(CHARACTER_BARLEY);
                TalkMessage(gText_FarmEvent_Foal_OfferToPlayer_Barley_ExplainsFoalNeedsHome);
                TalkClose();
                break;
            case 1:
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_BARLEY_AFRAID);
                SetTalkNameplateCharacter(CHARACTER_BARLEY);
                TalkMessage(gText_FarmEvent_Foal_OfferToPlayer_Barley_DeclineRetry);
                TalkClose();
                break;
            case 2:
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_BARLEY_AFRAID);
                SetTalkNameplateCharacter(CHARACTER_BARLEY);
                TalkMessage(gText_FarmEvent_Foal_OfferToPlayer_Barley_FinalConfirmation);
                TalkClose();
                break;
        }
        TalkOpen();
        var_0 = TalkChoice2(gText_FarmEvent_Foal_OfferToPlayer_ChoiceAccept, gText_FarmEvent_Foal_OfferToPlayer_ChoiceDecline);
        TalkClose();
        switch (var_0)
        {
            case CHOICE_OPTION_1:
                var_1 = FALSE;
                break;
            case CHOICE_OPTION_2:
                var_1 = TRUE;
                ++var_2;
                break;
        }
    }
    while (var_1 != FALSE && var_2 < 3);
    if (var_1 != FALSE)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_ANGRY);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FarmEvent_Foal_OfferToPlayer_Barley_DeclinedResponse);
        TalkClose();
        AddNpcFriendship(CHARACTER_BARLEY, mary_negated_int(-10));
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        SetEntityFacing(ENTITY_BARLEY, FACING_RIGHT);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        MoveEntityXTo(ENTITY_BARLEY, X(337), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
        SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
        SetEntityFacing(ENTITY_FARM_HORSE, FACING_RIGHT);
        SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FOAL_WALK);
        MoveEntityXTo(ENTITY_FARM_HORSE, X(305), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_FARM_HORSE);
        SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FOAL_IDLE);
        WaitFrames(30);
        SetEntityFacing(ENTITY_FARM_HORSE, FACING_UP);
        SetEntityFacing(ENTITY_BARLEY, FACING_UP);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        MoveEntityYTo(ENTITY_BARLEY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FOAL_WALK);
        MoveEntityYTo(ENTITY_FARM_HORSE, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        WaitForEntityMovement(ENTITY_FARM_HORSE);
        HideEntity(ENTITY_BARLEY);
        HideEntity(ENTITY_FARM_HORSE);
        RemoveFarmHorse(FALSE, 0);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FarmEvent_Foal_OfferToPlayer_Barley_AcceptedThanks);
        TalkClose();
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        OpenNameEntry(NAME_ENTRY_HORSE, NAME_ENTRY_SINGLETON_SLOT);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FarmEvent_Foal_OfferToPlayer_Barley_HorseCareInstructions);
        TalkClose();
        SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
        WaitFrames(30);
        SetEntityFacing(ENTITY_BARLEY, FACING_UP);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FarmEvent_Foal_OfferToPlayer_Barley_MovesFoalToStable);
        TalkClose();
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        SetEntityFacing(ENTITY_BARLEY, FACING_RIGHT);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        SetEntityFacing(ENTITY_FARM_HORSE, FACING_RIGHT);
        SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FOAL_WALK);
        MoveEntityXTo(ENTITY_BARLEY, X(500), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        MoveEntityXTo(ENTITY_FARM_HORSE, X(500), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        WaitForEntityMovement(ENTITY_FARM_HORSE);
        RelocateEntityToMap(ENTITY_FARM_HORSE, MAP_HORSE_STABLE, X(84), Y(124));
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
        SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        MoveEntityXTo(ENTITY_BARLEY, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FarmEvent_Foal_OfferToPlayer_Barley_PromisesToCheckOnFoal);
        TalkClose();
        SetEntityFacing(ENTITY_BARLEY, FACING_UP);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        MoveEntityYTo(ENTITY_BARLEY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
        HideEntity(ENTITY_BARLEY);
        AddNpcFriendship(CHARACTER_BARLEY, 10);
    }
    VarSet(VAR_BARLEY_FOAL_OFFER_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
}
