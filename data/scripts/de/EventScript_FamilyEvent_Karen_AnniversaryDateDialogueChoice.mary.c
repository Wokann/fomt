#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Karen_AnniversaryDateDialogueChoice_OpeningQuestion[] =
        "Guten Morgen, {NickName}.\r\n"
        "Gut geschlafen?\r\n"
        "Weißt du, was heute ist?{Press}";

    const char gText_FamilyEvent_Karen_AnniversaryDateDialogueChoice_PlayerBirthdayChoice[] =
        "Dein Geburtstag";

    const char gText_FamilyEvent_Karen_AnniversaryDateDialogueChoice_WeddingAnniversaryChoice[] =
        "Unser Hochzeitstag";

    const char gText_FamilyEvent_Karen_AnniversaryDateDialogueChoice_SpouseBirthdayChoice[] =
        "Mein Geburtstag";

    const char gText_FamilyEvent_Karen_AnniversaryDateDialogueChoice_IncorrectPlayerBirthdayResponse[] =
        "Mein Geburtstag? \r\n"
        "Nein, es ist unser\r\n"
        "Hochzeitstag, du Dummer! {Press}\r\n"
        "Ich kann nicht fassen, dass \r\n"
        "du das vergessen hast, ich\r\n"
        "habe sogar ein Geschenk!{Press}\p"
        "Aber jetzt kriegst du \r\n"
        "es nicht mehr!{Press}";

    const char gText_FamilyEvent_Karen_AnniversaryDateDialogueChoice_CorrectAnniversaryResponse[] =
        "Du hast Recht!\r\n"
        "Du bist so ein guter \r\n"
        "Ehemann! {Press}\p"
        "Ich wusste, du denkst daran!\r\n"
        "Hier ist ein Geschenk!{Press}";

    const char gText_FamilyEvent_Karen_AnniversaryDateDialogueChoice_ImmediateGiftDelivery[] =
        "Hier bitte, {NickName}.{Press}";

    const char gText_FamilyEvent_Karen_AnniversaryDateDialogueChoice_HandsOccupiedDeferredGiftPrompt[] =
        "Ich hatte so viel Spaß!\r\n"
        "Ich werde schlafen \r\n"
        "wie ein Stein...{Press}";

    const char gText_FamilyEvent_Karen_AnniversaryDateDialogueChoice_IncorrectSpouseBirthdayResponse[] =
        "Soll das ein Witz sein!?\r\n"
        "Ich kann nicht fassen, \r\n"
        "wie selbstsüchtig du bist!{Press}\p"
        "Ich wollte dir etwas \r\n"
        "schenken,\r\n"
        "aber jetzt nicht mehr!{Press}";
};

void EventScript_FamilyEvent_Karen_AnniversaryDateDialogueChoice(void)
{
    int var_0;
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
    SetEntityPosition(ENTITY_KAREN, X(265), Y(114), FACING_DOWN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    if (VarGet(VAR_KAREN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
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
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_FamilyEvent_Karen_AnniversaryDateDialogueChoice_OpeningQuestion);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice3(gText_FamilyEvent_Karen_AnniversaryDateDialogueChoice_PlayerBirthdayChoice, gText_FamilyEvent_Karen_AnniversaryDateDialogueChoice_WeddingAnniversaryChoice, gText_FamilyEvent_Karen_AnniversaryDateDialogueChoice_SpouseBirthdayChoice);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FamilyEvent_Karen_AnniversaryDateDialogueChoice_IncorrectPlayerBirthdayResponse);
            TalkClose();
            VarSet(VAR_KAREN_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
            SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_KAREN, 3000);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FamilyEvent_Karen_AnniversaryDateDialogueChoice_CorrectAnniversaryResponse);
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            if (IsPlayerHoldingNothing())
            {
                SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
                TalkMessage(gText_FamilyEvent_Karen_AnniversaryDateDialogueChoice_ImmediateGiftDelivery);
                TalkClose();
                SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_GESTURE);
                WaitFrames(60);
                SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
                PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
                SetPlayerHeldWrappedArticle(GetRandomSpouseGiftArticleId());
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
                VarSet(VAR_KAREN_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                WaitFrames(60);
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
                SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            }
            else
            {
                SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
                TalkMessage(gText_FamilyEvent_Karen_AnniversaryDateDialogueChoice_HandsOccupiedDeferredGiftPrompt);
                TalkClose();
                EnableScriptedNpcControl();
                SetEntityEventScript(ENTITY_KAREN, EventScript_FamilyEvent_Karen_AnniversaryDeferredGiftDelivery);
                if (VarGet(VAR_KAREN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
                {
                    SetEntityEventScript(ENTITY_CHILD, EventScript_FamilyEvent_Karen_AnniversaryChildReaction);
                }
                VarSet(VAR_KAREN_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            }
            break;
        case CHOICE_OPTION_3:
            AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            SetTalkPortrait(TALK_PORTRAIT_KAREN_ANGRY);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FamilyEvent_Karen_AnniversaryDateDialogueChoice_IncorrectSpouseBirthdayResponse);
            TalkClose();
            VarSet(VAR_KAREN_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_FARMHOUSE, X(327), Y(112));
            SetEntityPosition(ENTITY_PLAYER, X(327), Y(112), FACING_LEFT);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            break;
    }
    MarkNpcSpokenTo(CHARACTER_KAREN);
}
