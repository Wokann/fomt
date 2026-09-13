#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_MusicFestival_Invitation_Carter_WereHavingTheMusicFestivalTomorrow[] =
        "We're having the Music\r\n"
        "Festival tomorrow at 6PM\r\n"
        "at the Church. {Press}\p"
        "Do you want to come? {Press}";

    const char gText_FestivalEvent_MusicFestival_Invitation_Carter_IdLoveTo[] =
        "I'd love to.";

    const char gText_FestivalEvent_MusicFestival_Invitation_Carter_ChoiceDeclineBecauseBusy[] =
        "Sorry, I'm busy.";

    const char gText_FestivalEvent_MusicFestival_Invitation_Carter_InThatCaseYouCanPlay[] =
        "In that case, you can play\r\n"
        "the Ocarina. {Press}\p"
        "I'll give it to you \r\n"
        "tomorrow. {Press}";

    const char gText_FestivalEvent_MusicFestival_Invitation_Carter_DontBeLateTomorrow[] =
        "Don't be late tomorrow!{Press}";

    const char gText_FestivalEvent_MusicFestival_Invitation_Carter_YoullBeAbleToHearKarens[] =
        "You'll be able to hear\r\n"
        "Karen's beautiful voice if\r\n"
        "you do come. {Press}\p"
        "Come if you have time. {Press}";
};

void EventScript_FestivalEvent_MusicFestival_Invitation_Carter(void)
{
    int var_0;
    ChangeMap(MAP_FARM, X(228), Y(120));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_AUTUMN);
    SetEntityPosition(ENTITY_PLAYER, X(228), Y(120), FACING_DOWN);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_CARTER, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_FestivalEvent_MusicFestival_Invitation_Carter_WereHavingTheMusicFestivalTomorrow);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_FestivalEvent_MusicFestival_Invitation_Carter_IdLoveTo, gText_FestivalEvent_MusicFestival_Invitation_Carter_ChoiceDeclineBecauseBusy);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            TalkMessage(gText_FestivalEvent_MusicFestival_Invitation_Carter_InThatCaseYouCanPlay);
            SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            TalkMessage(gText_FestivalEvent_MusicFestival_Invitation_Carter_DontBeLateTomorrow);
            TalkClose();
            SetEntityFacing(ENTITY_CARTER, FACING_RIGHT);
            SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_WALK);
            MoveEntityXTo(ENTITY_CARTER, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_CARTER);
            SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
            SetEntityFacing(ENTITY_CARTER, FACING_UP);
            SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_WALK);
            SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
            MoveEntityYTo(ENTITY_CARTER, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_CARTER);
            SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
            HideEntity(ENTITY_CARTER);
            MarkNpcSpokenTo(CHARACTER_CARTER);
            VarSet(VAR_MUSIC_FESTIVAL_PLAYER_PERFORMANCE_ACCEPTED, TRUE);
            VarSet(VAR_MUSIC_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_COMPLETED);
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            TalkMessage(gText_FestivalEvent_MusicFestival_Invitation_Carter_YoullBeAbleToHearKarens);
            TalkClose();
            SetEntityFacing(ENTITY_CARTER, FACING_RIGHT);
            SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_WALK);
            MoveEntityXTo(ENTITY_CARTER, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_CARTER);
            SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
            SetEntityFacing(ENTITY_CARTER, FACING_UP);
            SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_WALK);
            SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
            MoveEntityYTo(ENTITY_CARTER, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_CARTER);
            SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
            HideEntity(ENTITY_CARTER);
            MarkNpcSpokenTo(CHARACTER_CARTER);
            VarSet(VAR_MUSIC_FESTIVAL_PLAYER_PERFORMANCE_ACCEPTED, FALSE);
            VarSet(VAR_MUSIC_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_COMPLETED);
            break;
    }
}
