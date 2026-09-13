#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FireworksFestival_Invitation_Karen_ILoveSummerTheFireworksThe[] =
        "I love Summer! \r\n"
        "The fireworks, the \r\n"
        "cold beer...{Press}\p"
        "Of course, the beer is nice\r\n"
        "and cold all year long...{Press}";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Karen_AreYouLookingForSomeoneTo[] =
        "Are you looking for someone\r\n"
        "to watch the fireworks \r\n"
        "with? {Press}";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Karen_InviteToTheFireworks[] =
        "Invite to the fireworks?";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Karen_Invite[] =
        "Invite.";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Karen_DontInvite[] =
        "Don't invite.";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Karen_ThanksForAskingIdLoveTo[] =
        "Thanks for asking!\r\n"
        "I'd love to watch with you.{Press}";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Karen_HiTherePlayerDoYouWant[] =
        "Hi there, {Player}. \r\n"
        "Do you want to watch \r\n"
        "together? {Press}\p"
        "You're alone, right? {Press}";
};

void EventScript_FestivalEvent_FireworksFestival_Invitation_Karen(void)
{
    int var_0, var_1, var_2, var_3, var_4;
    if (HasMetNpc(CHARACTER_KAREN) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_KAREN);
    }
    SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (WasNpcSpokenToJustNow(CHARACTER_KAREN) == FALSE)
    {
        AddNpcFriendship(CHARACTER_KAREN, 5);
    }
    MarkNpcSpokenTo(CHARACTER_KAREN);
    TalkOpen();
    var_1 = VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED;
    var_2 = VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED;
    var_3 = VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE;
    var_4 = VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED;
    if (var_1 && var_3 && GetCharacterLove(CHARACTER_KAREN) < LOVE_HEART_GREEN_MIN || var_4 || var_2)
    {
        SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        if (!(VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
        {
            ShowTalkHeartIndicator(CHARACTER_KAREN);
        }
        TalkMessage(gText_FestivalEvent_FireworksFestival_Invitation_Karen_ILoveSummerTheFireworksThe);
        TalkClose();
    }
    else
    {
        if (var_1 && var_3 && GetCharacterLove(CHARACTER_KAREN) >= LOVE_HEART_GREEN_MIN)
        {
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FestivalEvent_FireworksFestival_Invitation_Karen_AreYouLookingForSomeoneTo);
            TalkClose();
            TalkOpen();
            var_0 = TalkPromptChoice2(gText_FestivalEvent_FireworksFestival_Invitation_Karen_InviteToTheFireworks, gText_FestivalEvent_FireworksFestival_Invitation_Karen_Invite, gText_FestivalEvent_FireworksFestival_Invitation_Karen_DontInvite);
            switch (var_0)
            {
                case PROMPT_CHOICE_OPTION_1:
                    VarSet(VAR_FIREWORKS_FESTIVAL_PARTNER, FESTIVAL_FIREWORKS_PARTNER_KAREN);
                    TalkClose();
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_KAREN);
                    ShowTalkHeartIndicator(CHARACTER_KAREN);
                    TalkMessage(gText_FestivalEvent_FireworksFestival_Invitation_Karen_ThanksForAskingIdLoveTo);
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
            if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                VarSet(VAR_FIREWORKS_FESTIVAL_PARTNER, FESTIVAL_FIREWORKS_PARTNER_KAREN);
                SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_KAREN);
                ShowTalkHeartIndicator(CHARACTER_KAREN);
                TalkMessage(gText_FestivalEvent_FireworksFestival_Invitation_Karen_HiTherePlayerDoYouWant);
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
    SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
}
