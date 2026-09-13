#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_MusicFestival_Invitation_Carter_WereHavingTheMusicFestivalTomorrow[] =
        "明日の夜６時から音楽祭を\r\n"
        "教会でするんだけど、{Press}\p"
        "キミにも参加してほしいと\r\n"
        "思って来たんだ。どうかな？{Press}";

    const char gText_FestivalEvent_MusicFestival_Invitation_Carter_IdLoveTo[] =
        "音楽祭に参加する";

    const char gText_FestivalEvent_MusicFestival_Invitation_Carter_ChoiceDeclineBecauseBusy[] =
        "音楽祭に参加しない";

    const char gText_FestivalEvent_MusicFestival_Invitation_Carter_InThatCaseYouCanPlay[] =
        "そうか、じゃあキミには\r\n"
        "オカリナを吹いてもらおう\r\n"
        "かな。{Press}\p"
        "オカリナは明日わたすから。{Press}";

    const char gText_FestivalEvent_MusicFestival_Invitation_Carter_DontBeLateTomorrow[] =
        "それじゃあ、\r\n"
        "明日おくれないようにね。{Press}";

    const char gText_FestivalEvent_MusicFestival_Invitation_Carter_YoullBeAbleToHearKarens[] =
        "音楽祭では、カレンちゃんの\r\n"
        "きれいな歌声が聞けるんだ。{Press}\p"
        "時間があったら、\r\n"
        "教会においで。{Press}";
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
