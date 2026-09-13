#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Popuri_FiftiethAnniversaryMountainCottageGift_Announcement[] =
        "Guten Morgen, {NickName}.\r\n"
        "Heute ist unser 50. \r\n"
        "Hochzeitstag!{Press}\p"
        "Ich habe ein \r\n"
        "Geschenk für dich.\r\n"
        "Es ist... Es ist eine {Press}\r\n"
        "Hütte in den Bergen!{Press}\p"
        "Wie ich das bezahlt habe?\r\n"
        "Das ist ein Geheimnis.{Press}";

    const char gText_FamilyEvent_Popuri_FiftiethAnniversaryMountainCottageGift_VisitSuggestion[] =
        "Schau sie dir später\r\n"
        "einmal an, OK?{Press}";
};

void EventScript_FamilyEvent_Popuri_FiftiethAnniversaryMountainCottageGift(void)
{
    ChangeMap(MAP_FARMHOUSE, X(265), Y(138));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(265), Y(138), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_POPURI, X(265), Y(114), FACING_DOWN);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    if (VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        if (VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START)
        {
            SetEntityPosition(ENTITY_CHILD, X(292), Y(84), FACING_DOWN);
            if (VarGet(VAR_CHILD_CAN_WALK) == CHILD_WALKING_CAN_WALK)
            {
                SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_WALKING_IDLE);
            }
            else
            {
                SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_PRE_WALKING_IDLE);
            }
        }
        else
        {
            SetEntityPosition(ENTITY_CHILD, X(416), Y(mary_negated_int(-48)), FACING_DOWN);
            SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_INFANT_SLEEPING);
        }
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_POPURI_ANNIVERSARY_MORNING_REMINDER_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_FiftiethAnniversaryMountainCottageGift_Announcement);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_FiftiethAnniversaryMountainCottageGift_VisitSuggestion);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_POPURI);
    VarSet(VAR_POPURI_ANNIVERSARY_MORNING_REMINDER_STATE, EVENT_LIFECYCLE_COMPLETED);
    BuildMountainCottage();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
    SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
}
