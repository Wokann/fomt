#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FireworksFestival_Invitation_Ann_ILoveFireworksMoreThanAnything[] =
        "I love fireworks \r\n"
        "more than anything!{Press}";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Ann_InviteToTheFireworks[] =
        "Invite to the fireworks?";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Ann_Invite[] =
        "Invite.";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Ann_DontInvite[] =
        "Don't invite.";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Ann_OfCourseSitDownTheyreAbout[] =
        "Of course! \r\n"
        "Sit down, they're about \r\n"
        "to start!{Press}";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Ann_OhHiPlayerWeMightAs[] =
        "Oh, hi {Player}!\r\n"
        "We might as well watch the \r\n"
        "fireworks together!{Press}";
};

void EventScript_FestivalEvent_FireworksFestival_Invitation_Ann(void)
{
    int var_0, var_1, var_2, var_3, var_4;
    if (HasMetNpc(CHARACTER_ANN) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ANN);
    }
    SetEntityFacing(ENTITY_ANN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (WasNpcSpokenToJustNow(CHARACTER_ANN) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ANN, 5);
    }
    MarkNpcSpokenTo(CHARACTER_ANN);
    TalkOpen();
    var_1 = VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED;
    var_2 = VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED;
    var_3 = VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE;
    var_4 = VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED;
    if (var_1 && var_3 && GetCharacterLove(CHARACTER_ANN) < LOVE_HEART_GREEN_MIN || var_4 || var_2)
    {
        SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ANN);
        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
        {
            ShowTalkHeartIndicator(CHARACTER_ANN);
        }
        TalkMessage(gText_FestivalEvent_FireworksFestival_Invitation_Ann_ILoveFireworksMoreThanAnything);
        TalkClose();
    }
    else
    {
        if (var_1 && var_3 && GetCharacterLove(CHARACTER_ANN) >= LOVE_HEART_GREEN_MIN)
        {
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_FestivalEvent_FireworksFestival_Invitation_Ann_ILoveFireworksMoreThanAnything);
            TalkClose();
            TalkOpen();
            var_0 = TalkPromptChoice2(gText_FestivalEvent_FireworksFestival_Invitation_Ann_InviteToTheFireworks, gText_FestivalEvent_FireworksFestival_Invitation_Ann_Invite, gText_FestivalEvent_FireworksFestival_Invitation_Ann_DontInvite);
            switch (var_0)
            {
                case PROMPT_CHOICE_OPTION_1:
                    VarSet(VAR_FIREWORKS_FESTIVAL_PARTNER, FESTIVAL_FIREWORKS_PARTNER_ANN);
                    TalkClose();
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
                    SetTalkNameplateCharacter(CHARACTER_ANN);
                    ShowTalkHeartIndicator(CHARACTER_ANN);
                    TalkMessage(gText_FestivalEvent_FireworksFestival_Invitation_Ann_OfCourseSitDownTheyreAbout);
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
            if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                VarSet(VAR_FIREWORKS_FESTIVAL_PARTNER, FESTIVAL_FIREWORKS_PARTNER_ANN);
                SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_ANN);
                ShowTalkHeartIndicator(CHARACTER_ANN);
                TalkMessage(gText_FestivalEvent_FireworksFestival_Invitation_Ann_OhHiPlayerWeMightAs);
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
    SetEntityFacing(ENTITY_ANN, FACING_RIGHT);
}
