#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearsEve_NoodleFestivalMeal_ThomasStartsMeal[] =
        "Alright, let's eat!{Press}";

    const char gText_FestivalEvent_NewYearsEve_NoodleFestivalMeal_ThomasOffersLeftoverBuckwheatFlour[] =
        "It looks like there's some \r\n"
        "extra Buckwheat Flour. {Press}\p"
        "Why don't you take some \r\n"
        "home, {Player}?\r\n"
        "We can't waste it!{Press}";

    const char gText_FestivalEvent_NewYearsEve_NoodleFestivalMeal_ThomasNotesNoInventorySpace[] =
        "Looks like your Rucksack\r\n"
        "is full, {Player}. \r\n"
        "Too bad...{Press}";

    const char gText_FestivalEvent_NewYearsEve_NoodleFestivalMeal_PlayerLeavesWithoutLeftoverBuckwheatFlour[] =
        "That was good!\r\n"
        "Too bad I couldn't take\r\n"
        "any home with me...{Press}";

    const char gText_FestivalEvent_NewYearsEve_NoodleFestivalMeal_PlayerReceivesLeftoverBuckwheatFlour[] =
        "That was good!\r\n"
        "I even got to take some\r\n"
        "home with me!{Press}";
};

void EventScript_FestivalEvent_NewYearsEve_NoodleFestivalMeal(void)
{
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
        SetPlayerHeldFood(ITEM_FOOD_BUCKWHEAT_NOODLES);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_NewYearsEve_NoodleFestivalMeal_ThomasStartsMeal);
        TalkClose();
        ClearPlayerHeldItem();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_EAT);
        WaitFrames(30);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        PlaySong(AUDIO_START, AUDIO_SFX_EAT);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_NewYearsEve_NoodleFestivalMeal_ThomasStartsMeal);
        TalkClose();
    }
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_FestivalEvent_NewYearsEve_NoodleFestivalMeal_ThomasOffersLeftoverBuckwheatFlour);
    TalkClose();
    if (IsPlayerHoldingNothing() == FALSE && GetFirstFreeRucksackItemSlot() == mary_negated_int(RUCKSACK_SLOT_NOT_FOUND))
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_NewYearsEve_NoodleFestivalMeal_ThomasNotesNoInventorySpace);
        TalkClose();
        WaitFrames(20);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        TalkOpen();
        TalkMessage(gText_FestivalEvent_NewYearsEve_NoodleFestivalMeal_PlayerLeavesWithoutLeftoverBuckwheatFlour);
        TalkClose();
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(20);
        PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
        SetPlayerHeldFood(ITEM_FOOD_BUCKWHEAT_FLOUR);
        AddFoodToRucksack(ITEM_FOOD_BUCKWHEAT_FLOUR, 8);
        WaitFrames(20);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        TalkOpen();
        TalkMessage(gText_FestivalEvent_NewYearsEve_NoodleFestivalMeal_PlayerReceivesLeftoverBuckwheatFlour);
        TalkClose();
    }
    ClearEntityEventScript(ENTITY_THOMAS);
    ClearEntityEventScript(ENTITY_GOTZ);
    ClearEntityEventScript(ENTITY_CARTER);
    ClearEntityEventScript(ENTITY_DUKE);
    ClearEntityEventScript(ENTITY_MANNA);
    ClearEntityEventScript(ENTITY_JEFF);
    ClearEntityEventScript(ENTITY_SASHA);
    ClearEntityEventScript(ENTITY_ANN);
    RemoveEventIcon(EVENT_ICON_SLOT_0);
    RemoveEventIcon(EVENT_ICON_SLOT_1);
    RemoveEventIcon(EVENT_ICON_SLOT_2);
    RemoveEventIcon(EVENT_ICON_SLOT_3);
    RemoveEventIcon(EVENT_ICON_SLOT_4);
    RemoveEventIcon(EVENT_ICON_SLOT_5);
    DisableScriptedNpcControl();
    VarSet(VAR_NEW_YEARS_EVE_NOODLE_FESTIVAL_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
