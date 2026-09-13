#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_HeyTheOwnerOfThisFarm[] =
        "こらこら、\r\n"
        "ここは先日亡くなった、\r\n"
        "じいさんの土地なんだよ。{Press}\p"
        "勝手に入ってきちゃダメじゃ\r\n"
        "ないか！{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_WhatYouKnewHimAndYou[] =
        "えっ、　　　　　　　　　　　\r\n"
        "じいさんの知り合い？{Press}\p"
        "亡くなったことを\r\n"
        "知らなかったのかい？{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_HeDiedAboutOh6Months[] =
        "実は、半年前に亡くなってね。{Press}\p"
        "わたしがいろいろと整理をして\r\n"
        "いたんだけど、本棚からじい\r\n"
        "さんの遺書が見つかったんだ。{Press}\p"
        "遺書には、「{Player}に\r\n"
        "牧場を任せる」と書いて\r\n"
        "あったんだ。{Press}\p"
        "その人が現れるまで、\r\n"
        "この土地はわたしが管理する\r\n"
        "ことにしたんだよ。{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_WhatYouSayYourePlayer[] =
        "えっ、　　　　　　　　　　　\r\n"
        "キミが{Player}くんかい？{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_WillYouTellMeHowYou[] =
        "そうか…　　　　　　　　　　\r\n"
        "よかったら、知り合いになった\r\n"
        "キッカケを教えてくれるかい？{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_YouWereWritingLettersToEach[] =
        "じいさんと文通をしていた\r\n"
        "のか…　　　　　　　　　　　{Press}\p"
        "それで、文通の返事が返って\r\n"
        "来なくなったから様子を見に\r\n"
        "きたんだね…{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_SinceHeLeftYouTheFarm[] =
        "キミにだったら、　　　　　　\r\n"
        "この牧場をまかせても\r\n"
        "いいかもしれないな…{Press}\p"
        "キミは、　　　　　　　　　　\r\n"
        "牧場をやる気はあるのかい？{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_GreatFromHereOnOutThis[] =
        "わかった！\r\n"
        "キミに牧場をまかせることに\r\n"
        "しよう。{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_ItWontBeEasyButIf[] =
        "牧場の仕事は大変だが、{Press}\r\n"
        "しっかりがんばって、\r\n"
        "じいさんに負けないりっぱな\r\n"
        "牧場主になってくれ！{Press}";

    const char gText_TutorialEvent_FoMTOpening_FarmInheritanceIntroduction_TransitionToNextDay[] =
        "\r\n"
        "………そして次の日…\r\n"
        "{Press}";
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
