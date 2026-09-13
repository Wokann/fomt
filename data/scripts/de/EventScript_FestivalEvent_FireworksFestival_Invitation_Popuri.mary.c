#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FireworksFestival_Invitation_Popuri_HiPlayerICantWaitFor[] =
        "Hi, {Player}. \r\n"
        "Ich kann nicht erwarten, \r\n"
        "dass das Feuerwerk startet!{Press}";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Popuri_InviteToTheFireworks[] =
        "Zum Feuerwerk einladen?";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Popuri_Invite[] =
        "Einladen.";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Popuri_DontInvite[] =
        "Nicht einladen.";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Popuri_OKThanksForAskingLookTheyre[] =
        "Ok.\r\n"
        "Danke für die Einladung!\r\n"
        "Schau! Es beginnt!{Press}";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Popuri_HiPlayerTheFireworksAreStarting[] =
        "Hi, {Player}. \r\n"
        "Das Feuerwerk geht los!{Press}";
};

void EventScript_FestivalEvent_FireworksFestival_Invitation_Popuri(void)
{
    int var_0, var_1, var_2, var_3, var_4;
    if (HasMetNpc(CHARACTER_POPURI) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_POPURI);
    }
    SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
    {
        AddNpcFriendship(CHARACTER_POPURI, 5);
    }
    MarkNpcSpokenTo(CHARACTER_POPURI);
    TalkOpen();
    var_1 = VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE;
    var_2 = VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED;
    var_3 = VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE;
    var_4 = VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED;
    if (var_1 && var_3 && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_GREEN_MIN || var_4 || var_2)
    {
        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        if (var_1 && var_3)
        {
            ShowTalkHeartIndicator(CHARACTER_POPURI);
        }
        TalkMessage(gText_FestivalEvent_FireworksFestival_Invitation_Popuri_HiPlayerICantWaitFor);
        TalkClose();
    }
    else
    {
        if (var_1 && var_3 && GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_GREEN_MIN)
        {
            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FestivalEvent_FireworksFestival_Invitation_Popuri_HiPlayerICantWaitFor);
            TalkClose();
            TalkOpen();
            var_0 = TalkPromptChoice2(gText_FestivalEvent_FireworksFestival_Invitation_Popuri_InviteToTheFireworks, gText_FestivalEvent_FireworksFestival_Invitation_Popuri_Invite, gText_FestivalEvent_FireworksFestival_Invitation_Popuri_DontInvite);
            switch (var_0)
            {
                case PROMPT_CHOICE_OPTION_1:
                    VarSet(VAR_FIREWORKS_FESTIVAL_PARTNER, FESTIVAL_FIREWORKS_PARTNER_POPURI);
                    TalkClose();
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_POPURI);
                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                    TalkMessage(gText_FestivalEvent_FireworksFestival_Invitation_Popuri_OKThanksForAskingLookTheyre);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    CallScript(EventScript_FestivalEvent_FireworksFestival_PostFestivalDialogue);
                    break;
                case PROMPT_CHOICE_OPTION_2:
                    TalkClose();
                    break;
            }
        }
        else
        {
            if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                VarSet(VAR_FIREWORKS_FESTIVAL_PARTNER, FESTIVAL_FIREWORKS_PARTNER_POPURI);
                SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_POPURI);
                ShowTalkHeartIndicator(CHARACTER_POPURI);
                TalkMessage(gText_FestivalEvent_FireworksFestival_Invitation_Popuri_HiPlayerTheFireworksAreStarting);
                TalkClose();
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                CallScript(EventScript_FestivalEvent_FireworksFestival_PostFestivalDialogue);
            }
        }
    }
    if (WasNpcSpokenToJustNow(CHARACTER_RICK) && WasNpcSpokenToJustNow(CHARACTER_GRAY) && WasNpcSpokenToJustNow(CHARACTER_DOCTOR) && (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == FALSE || WasNpcSpokenToJustNow(CHARACTER_CLIFF)) && WasNpcSpokenToJustNow(CHARACTER_KAI) && WasNpcSpokenToJustNow(CHARACTER_KAREN) && WasNpcSpokenToJustNow(CHARACTER_ELLI) && WasNpcSpokenToJustNow(CHARACTER_ANN) && WasNpcSpokenToJustNow(CHARACTER_POPURI) && WasNpcSpokenToJustNow(CHARACTER_MARY))
    {
        VarSet(VAR_FIREWORKS_FESTIVAL_PARTNER, FESTIVAL_FIREWORKS_PARTNER_NONE);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        CallScript(EventScript_FestivalEvent_FireworksFestival_PostFestivalDialogue);
    }
    SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
}
