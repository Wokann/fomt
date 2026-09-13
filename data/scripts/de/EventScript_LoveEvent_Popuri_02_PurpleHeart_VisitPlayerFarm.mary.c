#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Popuri_02_PurpleHeart_Popuri_AsksForFarmTour[] =
        "Guten Morgen, \r\n"
        "{Player}.{Press}\p"
        "Heute wollte ich mir \r\n"
        "deine Farm ansehen. Zeigst\r\n"
        "du mir alles?{Press}";

    const char gText_LoveEvent_Popuri_02_PurpleHeart_ChoiceTooBusy[] =
        "Ich bin zu beschäftigt!";

    const char gText_LoveEvent_Popuri_02_PurpleHeart_ChoiceGiveFarmTour[] =
        "Sicher.";

    const char gText_LoveEvent_Popuri_02_PurpleHeart_Popuri_HurtByRefusal[] =
        "Ich habe gedacht, du \r\n"
        "wärst netter!{Press}\p"
        "Ich gehe nach Hause!{Press}";

    const char gText_LoveEvent_Popuri_02_PurpleHeart_Popuri_ThanksForAcceptance[] =
        "Wirklich? Ooh, danke!{Press}";

    const char gText_LoveEvent_Popuri_02_PurpleHeart_Popuri_VisitsLivestockArea[] =
        "Hier hältst du also \r\n"
        "deine Schafe und Kühe?{Press}";

    const char gText_LoveEvent_Popuri_02_PurpleHeart_Popuri_AdmiresChicken[] =
        "Was für ein schöner \r\n"
        "Hühnerstall!{Press}\p"
        "Wenn du etwas über\r\n"
        "Hühner wissen willst, \r\n"
        "frag meine Mutter!{Press}";

    const char gText_LoveEvent_Popuri_02_PurpleHeart_Popuri_ThanksForFarmTour[] =
        "Danke, dass du mich \r\n"
        "herumgeführt hat. \r\n"
        "Hat Spaß gemacht. {Press}\r\n"
        "Tschüss dann!{Press}";
};

void EventScript_LoveEvent_Popuri_02_PurpleHeart_VisitPlayerFarm(void)
{
    int var_0;
    ChangeMap(MAP_FARM, X(228), Y(160));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(228), Y(120), FACING_DOWN);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_POPURI, X(228), Y(160), FACING_UP);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_POPURI_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_LoveEvent_Popuri_02_PurpleHeart_Popuri_AsksForFarmTour);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Popuri_02_PurpleHeart_ChoiceTooBusy, gText_LoveEvent_Popuri_02_PurpleHeart_ChoiceGiveFarmTour);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_02_PurpleHeart_Popuri_HurtByRefusal);
            TalkClose();
            SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityXTo(ENTITY_POPURI, X(320), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            SetEntityFacing(ENTITY_POPURI, FACING_UP);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityYTo(ENTITY_POPURI, Y(0), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            HideEntity(ENTITY_POPURI);
            PanCameraTo(X(228), Y(120), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
            WaitForCameraMovement();
            MarkNpcSpokenTo(CHARACTER_POPURI);
            VarSet(VAR_POPURI_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_POPURI, 3000);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_HAPPY, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_02_PurpleHeart_Popuri_ThanksForAcceptance);
            TalkClose();
            WaitFrames(60);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_FARM, X(490), Y(140));
            PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
            SetEntityPosition(ENTITY_PLAYER, X(490), Y(140), FACING_UP);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityPosition(ENTITY_POPURI, X(522), Y(140), FACING_UP);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            WaitFrames(60);
            SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
            SetEntityFacing(ENTITY_POPURI, FACING_LEFT);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_02_PurpleHeart_Popuri_VisitsLivestockArea);
            TalkClose();
            WaitFrames(60);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_FARM, X(130), Y(540));
            PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
            SetEntityPosition(ENTITY_PLAYER, X(130), Y(540), FACING_UP);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityPosition(ENTITY_POPURI, X(162), Y(540), FACING_UP);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            WaitFrames(60);
            SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
            SetEntityFacing(ENTITY_POPURI, FACING_LEFT);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_02_PurpleHeart_Popuri_AdmiresChicken);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            WaitFrames(60);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            SetGameTime(13, 0);
            ChangeMap(MAP_FARM, X(228), Y(90));
            PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
            SetEntityPosition(ENTITY_PLAYER, X(220), Y(220), FACING_UP);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityPosition(ENTITY_POPURI, X(244), Y(220), FACING_UP);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityYTo(ENTITY_PLAYER, Y(130), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            MoveEntityYTo(ENTITY_POPURI, Y(130), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            WaitFrames(60);
            SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
            SetEntityFacing(ENTITY_POPURI, FACING_LEFT);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_02_PurpleHeart_Popuri_ThanksForFarmTour);
            TalkClose();
            SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityXTo(ENTITY_POPURI, X(320), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            SetEntityFacing(ENTITY_POPURI, FACING_UP);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityYTo(ENTITY_POPURI, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            HideEntity(ENTITY_POPURI);
            PanCameraTo(X(220), Y(130), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
            WaitForCameraMovement();
            MarkNpcSpokenTo(CHARACTER_POPURI);
            VarSet(VAR_POPURI_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            break;
    }
}
