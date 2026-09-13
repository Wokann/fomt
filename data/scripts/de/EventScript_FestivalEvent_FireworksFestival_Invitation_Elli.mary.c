#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FireworksFestival_Invitation_Elli_GoodEveningPlayerImGladI[] =
        "Guten Abend, \r\n"
        "{Player}. \r\n"
        "Gut, dass ich pünktlich bin!{Press}";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Elli_InviteToTheFireworks[] =
        "Zum Feuerwerk einladen?";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Elli_Invite[] =
        "Einladen.";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Elli_DontInvite[] =
        "Nicht einladen.";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Elli_IdLoveToThanksForAsking[] =
        "Liebend gerne!\r\n"
        "Danke für die Einladung!{Press}";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Elli_YouDidntTellMeYouWere[] =
        "Du hast mir nicht gesagt, \r\n"
        "dass du auch kommen \r\n"
        "würdest, {NickName}.{Press}";
};

void EventScript_FestivalEvent_FireworksFestival_Invitation_Elli(void)
{
    int var_0, var_1, var_2, var_3, var_4;
    if (HasMetNpc(CHARACTER_ELLI) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ELLI);
    }
    SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (WasNpcSpokenToJustNow(CHARACTER_ELLI) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ELLI, 5);
    }
    MarkNpcSpokenTo(CHARACTER_ELLI);
    TalkOpen();
    var_1 = VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED;
    var_2 = VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED;
    var_3 = VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE;
    var_4 = VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED;
    if (var_1 && var_3 && GetCharacterLove(CHARACTER_ELLI) < LOVE_HEART_GREEN_MIN || var_4 || var_2)
    {
        SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ELLI);
        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
        {
            ShowTalkHeartIndicator(CHARACTER_ELLI);
        }
        TalkMessage(gText_FestivalEvent_FireworksFestival_Invitation_Elli_GoodEveningPlayerImGladI);
        TalkClose();
    }
    else
    {
        if (var_1 && var_3 && GetCharacterLove(CHARACTER_ELLI) >= LOVE_HEART_GREEN_MIN)
        {
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_FestivalEvent_FireworksFestival_Invitation_Elli_GoodEveningPlayerImGladI);
            TalkClose();
            TalkOpen();
            var_0 = TalkPromptChoice2(gText_FestivalEvent_FireworksFestival_Invitation_Elli_InviteToTheFireworks, gText_FestivalEvent_FireworksFestival_Invitation_Elli_Invite, gText_FestivalEvent_FireworksFestival_Invitation_Elli_DontInvite);
            switch (var_0)
            {
                case PROMPT_CHOICE_OPTION_1:
                    VarSet(VAR_FIREWORKS_FESTIVAL_PARTNER, FESTIVAL_FIREWORKS_PARTNER_ELLI);
                    TalkClose();
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
                    SetTalkNameplateCharacter(CHARACTER_ELLI);
                    ShowTalkHeartIndicator(CHARACTER_ELLI);
                    TalkMessage(gText_FestivalEvent_FireworksFestival_Invitation_Elli_IdLoveToThanksForAsking);
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
            if (VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                VarSet(VAR_FIREWORKS_FESTIVAL_PARTNER, FESTIVAL_FIREWORKS_PARTNER_ELLI);
                SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_ELLI);
                ShowTalkHeartIndicator(CHARACTER_ELLI);
                TalkMessage(gText_FestivalEvent_FireworksFestival_Invitation_Elli_YouDidntTellMeYouWere);
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
    SetEntityFacing(ENTITY_ELLI, FACING_RIGHT);
}
