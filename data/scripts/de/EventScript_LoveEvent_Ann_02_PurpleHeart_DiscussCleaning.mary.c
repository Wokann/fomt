#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Ann_02_PurpleHeart_AnnHummingWhileCleaning[] =
        "La la la....\r\n"
        "la la la...{Press}";

    const char gText_LoveEvent_Ann_02_PurpleHeart_AnnStartledByPlayer[] =
        "Oh, {Player}!\r\n"
        "Du hast mich erschreckt! \r\n"
        "Schleich dich nicht so an!{Press}";

    const char gText_LoveEvent_Ann_02_PurpleHeart_AnnReassuresPlayer[] =
        "Schon gut. \r\n"
        "Ich bin nicht sauer.{Press}";

    const char gText_LoveEvent_Ann_02_PurpleHeart_AnnAsksOpinionAboutCleaning[] =
        "Was ich gemacht habe?\r\n"
        "Saubergemacht, natürlich!{Press}\p"
        "Ich mache gerne sauber. \r\n"
        "Ich sehe gerne, wenn\r\n"
        "alles sauber ist. {Press}\p"
        "Machst du gerne sauber,\r\n"
        "{Player}?{Press}";

    const char gText_LoveEvent_Ann_02_PurpleHeart_ChoiceEnjoyCleaning[] =
        "Ja, gerne.";

    const char gText_LoveEvent_Ann_02_PurpleHeart_ChoiceDislikeCleaning[] =
        "Ich hasse es.";

    const char gText_LoveEvent_Ann_02_PurpleHeart_AnnApprovesSharedInterest[] =
        "Ich wusste es, du siehst\r\n"
        "schon so aus!\r\n"
        "Gut für dich. {Press}\p"
        "Mein Vater hasst Sauber- \r\n"
        "machen, also muss ich\r\n"
        "es erledigen. {Press}\p"
        "Gut, dass ich es so \r\n"
        "gerne mache! {Press}";

    const char gText_LoveEvent_Ann_02_PurpleHeart_AnnEncouragesCleaning[] =
        "Zu schade. \r\n"
        "Du solltest es versuchen. \r\n"
        "Vielleicht magst du es!{Press}\p"
        "Mein Vater hasst \r\n"
        "Saubermachen auch.\r\n"
        "Männer...{Press}";
};

void EventScript_LoveEvent_Ann_02_PurpleHeart_DiscussCleaning(void)
{
    int var_0;
    ChangeMap(MAP_INN_2F, X(276), Y(116));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(276), Y(248), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_ANN, X(255), Y(116), FACING_LEFT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    TalkMessage(gText_LoveEvent_Ann_02_PurpleHeart_AnnHummingWhileCleaning);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
    WaitFrames(60);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_PLAYER, Y(116), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_ANN, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_LoveEvent_Ann_02_PurpleHeart_AnnStartledByPlayer);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_LoveEvent_Ann_02_PurpleHeart_AnnReassuresPlayer);
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_LoveEvent_Ann_02_PurpleHeart_AnnAsksOpinionAboutCleaning);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Ann_02_PurpleHeart_ChoiceEnjoyCleaning, gText_LoveEvent_Ann_02_PurpleHeart_ChoiceDislikeCleaning);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_ANN, 3000);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_HAPPY, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_02_PurpleHeart_AnnApprovesSharedInterest);
            TalkClose();
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_ANN);
            SetEntityEventScript(ENTITY_ANN, EventScript_LoveEvent_Ann_02_PurpleHeart_DiscussCleaning_FollowupAnnDialogue);
            VarSet(VAR_ANN_PURPLE_HEART_EVENT_CHOICE, ANN_PURPLE_HEART_RESPONSE_LIKE_CLEANING);
            VarSet(VAR_ANN_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_02_PurpleHeart_AnnEncouragesCleaning);
            TalkClose();
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_ANN);
            SetEntityEventScript(ENTITY_ANN, EventScript_LoveEvent_Ann_02_PurpleHeart_DiscussCleaning_FollowupAnnDialogue);
            VarSet(VAR_ANN_PURPLE_HEART_EVENT_CHOICE, ANN_PURPLE_HEART_RESPONSE_HATE_CLEANING);
            VarSet(VAR_ANN_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
    }
}
