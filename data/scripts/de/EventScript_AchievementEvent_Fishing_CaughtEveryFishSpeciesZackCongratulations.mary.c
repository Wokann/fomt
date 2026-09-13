#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_AchievementEvent_Fishing_CaughtEveryFishSpeciesZackCongratulations_ZackPraisesPlayerForCatchingEveryFishSpecies[] =
        "Hi, {Player}!\r\n"
        "Ich habe gehört, du hast\r\n"
        "alle Fische gefangen!{Press}\p"
        "Super! Ich wusste, dass es\r\n"
        "richtig war, die Angelrute\r\n"
        "dir zu geben!{Press}\p"
        "Mach weiter so!\r\n"
        "Mein Freund wird so \r\n"
        "eifersüchtig sein.{Press}";
};

void EventScript_AchievementEvent_Fishing_CaughtEveryFishSpeciesZackCongratulations(void)
{
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
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_AchievementEvent_Fishing_CaughtEveryFishSpeciesZackCongratulations_ZackPraisesPlayerForCatchingEveryFishSpecies);
    TalkClose();
    SetEntityFacing(ENTITY_ZACK, FACING_RIGHT);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_WALK);
    MoveEntityXTo(ENTITY_ZACK, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    SetEntityFacing(ENTITY_ZACK, FACING_UP);
    MoveEntityYTo(ENTITY_ZACK, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ZACK);
    HideEntity(ENTITY_ZACK);
    AddNpcFriendship(CHARACTER_ZACK, 10);
    VarSet(VAR_ZACK_CONGRATULATES_CATCHING_EVERY_FISH_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    MarkNpcSpokenTo(CHARACTER_ZACK);
}
