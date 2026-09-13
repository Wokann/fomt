#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearRiceCakeFestival_Meal_ThomasStartsMeal[] =
        "Let's eat! {Press}";

    const char gText_FestivalEvent_NewYearRiceCakeFestival_Meal_ThomasOffersLeftoverRiceCakes[] =
        "It looks like we made too \r\n"
        "much this year again! {Press}\p"
        "Let's each take some home. \r\n"
        "Help yourself, \r\n"
        "{Player}. {Press}";

    const char gText_FestivalEvent_NewYearRiceCakeFestival_Meal_ThomasNotesNoInventorySpace[] =
        "Looks like your Rucksack is\r\n"
        "full, {Player}. \r\n"
        "Too bad! {Press}";

    const char gText_FestivalEvent_NewYearRiceCakeFestival_Meal_PlayerLeavesWithoutLeftoverRiceCakes[] =
        "Now those were good! \r\n"
        "I just wish I could have\r\n"
        "taken some home!...{Press}";

    const char gText_FestivalEvent_NewYearRiceCakeFestival_Meal_PlayerReceivesLeftoverRiceCakes[] =
        "Now those were good! \r\n"
        "I can't wait to eat some\r\n"
        "more at home! {Press}";
};

void EventScript_FestivalEvent_NewYearRiceCakeFestival_Meal(void)
{
    CreateEventIcon(EVENT_ICON_SLOT_0, X(20 * 8 + 8), Y(18 * 8 + 8), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_RICE_CAKE));
    CreateEventIcon(EVENT_ICON_SLOT_1, X(23 * 8 + 8), Y(18 * 8 + 8), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_RICE_CAKE));
    CreateEventIcon(EVENT_ICON_SLOT_2, X(26 * 8 + 8), Y(18 * 8 + 8), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_RICE_CAKE));
    CreateEventIcon(EVENT_ICON_SLOT_3, X(29 * 8 + 8), Y(18 * 8 + 8), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_RICE_CAKE));
    CreateEventIcon(EVENT_ICON_SLOT_4, X(32 * 8 + 8), Y(18 * 8 + 8), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_RICE_CAKE));
    CreateEventIcon(EVENT_ICON_SLOT_5, X(35 * 8 + 8), Y(18 * 8 + 8), EVENT_ICON_LAYER_LOW_PRIORITY, GetFoodIconId(ITEM_FOOD_RICE_CAKE));
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
        SetPlayerHeldFood(ITEM_FOOD_RICE_CAKE);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_NewYearRiceCakeFestival_Meal_ThomasStartsMeal);
        TalkClose();
        ClearPlayerHeldItem();
        PlaySong(AUDIO_START, AUDIO_SFX_EAT);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_EAT);
        WaitFrames(30);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_NewYearRiceCakeFestival_Meal_ThomasStartsMeal);
        TalkClose();
    }
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_FestivalEvent_NewYearRiceCakeFestival_Meal_ThomasOffersLeftoverRiceCakes);
    TalkClose();
    if (IsPlayerHoldingNothing() == FALSE && GetFirstFreeRucksackItemSlot() == mary_negated_int(RUCKSACK_SLOT_NOT_FOUND))
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_NewYearRiceCakeFestival_Meal_ThomasNotesNoInventorySpace);
        TalkClose();
        WaitFrames(20);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        TalkOpen();
        TalkMessage(gText_FestivalEvent_NewYearRiceCakeFestival_Meal_PlayerLeavesWithoutLeftoverRiceCakes);
        TalkClose();
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(20);
        PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
        SetPlayerHeldFood(ITEM_FOOD_RICE_CAKE);
        AddFoodToRucksack(ITEM_FOOD_RICE_CAKE, 8);
        WaitFrames(20);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        TalkOpen();
        TalkMessage(gText_FestivalEvent_NewYearRiceCakeFestival_Meal_PlayerReceivesLeftoverRiceCakes);
        TalkClose();
    }
    ClearEntityEventScript(ENTITY_THOMAS);
    ClearEntityEventScript(ENTITY_ANN);
    ClearEntityEventScript(ENTITY_SAIBARA);
    ClearEntityEventScript(ENTITY_ELLI);
    ClearEntityEventScript(ENTITY_MAY);
    ClearEntityEventScript(ENTITY_STU);
    ClearEntityEventScript(ENTITY_DOUG);
    ClearEntityEventScript(ENTITY_DUKE);
    ClearEntityEventScript(ENTITY_MANNA);
    ClearEntityEventScript(ENTITY_GOTZ);
    ClearEntityEventScript(ENTITY_ZACK);
    ClearEntityEventScript(ENTITY_CARTER);
    RemoveEventIcon(EVENT_ICON_SLOT_0);
    RemoveEventIcon(EVENT_ICON_SLOT_1);
    RemoveEventIcon(EVENT_ICON_SLOT_2);
    RemoveEventIcon(EVENT_ICON_SLOT_3);
    RemoveEventIcon(EVENT_ICON_SLOT_4);
    RemoveEventIcon(EVENT_ICON_SLOT_5);
    DisableScriptedNpcControl();
    VarSet(VAR_NEW_YEAR_RICE_CAKE_FESTIVAL_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
