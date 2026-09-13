#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_HeyTheOwnerOfThisFarm[] =
        "Hey! Der Besitzer dieser\r\n"
        "Farm ist vor einer Weile\r\n"
        "gestorben.{Press}\p"
        "Du kannst hier nicht \r\n"
        "einfach reinplatzen!{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_WhatYouKnewHimAndYou[] =
        "Was? Du kanntest ihn?{Press}\p"
        "Und du wusstest nicht,\r\n"
        "dass er gestorben ist...?{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_HeDiedAboutOh6Months[] =
        "Er ist vor ungefähr{Press}\p"
        "6 Monaten gestorben.\r\n"
        "Als ich hier aufräumte,\r\n"
        "habe ich sein Testament{Press}\r\n"
        "gefunden. {Press}\p"
        "Er sagte darin \"Ich \r\n"
        "überlasse {Player} \r\n"
        "meine Farm.\"{Press}\p"
        "Also passe ich so lange \r\n"
        "auf die Farm auf, \r\n"
        "bis er kommt. {Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_WhatYouSayYourePlayer[] =
        "Was? Du sagst, du\r\n"
        "bist {Player}?{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_WillYouTellMeHowYou[] =
        "Erzählst du mir, wie \r\n"
        "du den alten Mann \r\n"
        "kennengelernt hast?{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_YouWereWritingLettersToEach[] =
        "Ihr habt euch gegenseitig\r\n"
        "Briefe geschrieben?{Press}\p"
        "Und als er nicht mehr\r\n"
        "zurückgeschrieben hat,\r\n"
        "wolltest du nach ihm sehen?{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_SinceHeLeftYouTheFarm[] =
        "Er hat dir die Farm\r\n"
        "vermacht. Wenn du willst,\r\n"
        "gehört sie dir. {Press}\p"
        "Was meinst du?{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_GreatFromHereOnOutThis[] =
        "Toll! Ab jetzt gehört dir\r\n"
        "dieser Ort!{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_ItWontBeEasyButIf[] =
        "Es wird nicht leicht, aber \r\n"
        "wenn du dich anstrengst,\r\n"
        "kannst du ihn stolz machen.{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_TransitionToNextDay[] =
        "\r\n"
        "Dann, am nächsten Tag...{Press}";
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
