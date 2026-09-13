#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FireworksFestival_Invitation_Karen_ILoveSummerTheFireworksThe[] =
        "Ich liebe den Sommer! \r\n"
        "Das Feuerwerk, das \r\n"
        "kalte Bier...{Press}\p"
        "Natürlich ist das Bier\r\n"
        "immer gut und kühl...{Press}";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Karen_AreYouLookingForSomeoneTo[] =
        "Suchst du jemanden,\r\n"
        "mit dem du das Feuerwerk\r\n"
        "ansehen kannst?{Press}";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Karen_InviteToTheFireworks[] =
        "Zum Feuerwerk einladen?";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Karen_Invite[] =
        "Einladen.";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Karen_DontInvite[] =
        "Nicht einladen.";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Karen_ThanksForAskingIdLoveTo[] =
        "Danke, für die Einladung!\r\n"
        "Ich schaue gern mit dir.{Press}";

    const char gText_FestivalEvent_FireworksFestival_Invitation_Karen_HiTherePlayerDoYouWant[] =
        "Hi, {Player}. \r\n"
        "Sollen wir zusammen \r\n"
        "gucken?{Press}\p"
        "Du bist allein, oder?{Press}";
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
