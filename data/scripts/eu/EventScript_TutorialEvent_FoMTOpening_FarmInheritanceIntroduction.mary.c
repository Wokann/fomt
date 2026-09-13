#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_HeyTheOwnerOfThisFarm[] =
        "Hey! The owner of this farm\r\n"
        "died a while back.{Press}\p"
        "You can't just come \r\n"
        "waltzing in here!{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_WhatYouKnewHimAndYou[] =
        "What? You knew him?{Press}\p"
        "And you didn't know that\r\n"
        "he had died...?{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_HeDiedAboutOh6Months[] =
        "He died about...{Press}\p"
        "Oh, 6 months ago, I reckon.\r\n"
        "When I was cleaning out his\r\n"
        "place I found his will. {Press}\p"
        "In it, he said \"I'm leaving\r\n"
        "my farm to {Player}.\"{Press}\p"
        "So, until whoever that is \r\n"
        "shows up, I'm taking care\r\n"
        "of the farm. {Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_WhatYouSayYourePlayer[] =
        "What? You say \r\n"
        "you're {Player}? {Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_WillYouTellMeHowYou[] =
        "Will you tell me how you\r\n"
        "met the old man...?{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_YouWereWritingLettersToEach[] =
        "You were writing letters to \r\n"
        "each other, eh?{Press}\p"
        "And when he stopped writing\r\n"
        "back, you came to check on \r\n"
        "him, did you? {Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_SinceHeLeftYouTheFarm[] =
        "Since he left you the farm,\r\n"
        "it's yours if you want it. {Press}\p"
        "Well, what do you think? {Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_GreatFromHereOnOutThis[] =
        "Great! From here on out\r\n"
        "this place is yours!{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_ItWontBeEasyButIf[] =
        "It won't be easy, but if \r\n"
        "you try hard you can do a \r\n"
        "job to make him proud. {Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_TransitionToNextDay[] =
        "\r\n"
        "Then, the next day...{Press}";
};

void EventScript_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction(void)
{
    ChangeMap(MAP_FARM, X(330), Y(150));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_SPRING);
    SetEntityPosition(ENTITY_PLAYER, X(305), Y(171), FACING_LEFT);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_THOMAS, X(365), Y(20), FACING_DOWN);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(30);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, TRUE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_WALK);
    MoveEntityYTo(ENTITY_THOMAS, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_THOMAS);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    WaitFrames(60);
    StartEntityEffect(ENTITY_THOMAS, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_WALK);
    MoveEntityYTo(ENTITY_THOMAS, Y(171), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_THOMAS);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    SetEntityFacing(ENTITY_THOMAS, FACING_LEFT);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_WALK);
    MoveEntityXTo(ENTITY_THOMAS, X(330), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_THOMAS);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_HeyTheOwnerOfThisFarm);
    TalkClose();
    StopEntityEffect(ENTITY_PLAYER);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_WhatYouKnewHimAndYou);
    TalkClose();
    WaitFrames(30);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_HeDiedAboutOh6Months);
    TalkClose();
    WaitFrames(60);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_WhatYouSayYourePlayer);
    TalkClose();
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_WillYouTellMeHowYou);
    TalkClose();
    WaitFrames(30);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StopAllSongs();
    StartFarmInheritanceFlashback();
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    StartEntityEffect(ENTITY_THOMAS, ENTITY_EMOTE_THINKING, TRUE);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60 * 2);
    StopEntityEffect(ENTITY_THOMAS);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_YouWereWritingLettersToEach);
    TalkClose();
    WaitFrames(60);
    SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
    WaitFrames(60);
    StartEntityEffect(ENTITY_THOMAS, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(90);
    SetEntityFacing(ENTITY_THOMAS, FACING_LEFT);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_SinceHeLeftYouTheFarm);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(90);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_GreatFromHereOnOutThis);
    TalkClose();
    WaitFrames(30);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_ItWontBeEasyButIf);
    TalkClose();
    WaitFrames(30);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(30);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_RAISE_ARMS);
    WaitFrames(60);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_TransitionToNextDay);
    TalkClose();
    PlacePlayerAtFarmhouseBed();
    PreservePlayerLocationForNextDay();
    CallScript(EventScript_SystemEvent_AdvanceToNextDay);
}
