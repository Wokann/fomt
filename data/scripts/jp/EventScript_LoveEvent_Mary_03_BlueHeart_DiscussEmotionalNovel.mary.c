#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Mary_03_BlueHeart_MaryMovedToTearsByNovel[] =
        "はぁ…グスッ…\r\n"
        "いい話だわ…グスッ…{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryGreetsPlayer[] =
        "ああ…グスッ…\r\n"
        "{Player}くん。{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryEmbarrassedPlayerSawHerCry[] =
        "誰に泣かされたかって？{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryExplainsFindingNovel[] =
        "ちがうのよ。\r\n"
        "図書館を整理してたら、\r\n"
        "奥から一冊の本が出てきてね。{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryExplainsReadingOutdoors[] =
        "どうせだったら景色がいい\r\n"
        "ところで読もうと思って、\r\n"
        "ここで読んでみたら、{Press}\r\n"
        "それは感動する本だったの…{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryAsksIfPlayerEverCries[] =
        "心配してくれてありがとう。\r\n"
        "{Player}くんも本を読んで\r\n"
        "感動して泣いたことってある？{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_ChoiceSometimesCry[] =
        "感動して泣いたことがある";

    const char gText_LoveEvent_Mary_03_BlueHeart_ChoiceNeverCry[] =
        "感動して泣いたことがない";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryAppreciatesEmotionalReaders[] =
        "それだけ本にのめりこむことが\r\n"
        "出来るって、\r\n"
        "すばらしいことだわ。{Press}\p"
        "あ、そうだ。\r\n"
        "{Player}くんに、\r\n"
        "この本あげる。{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryFinishedReadingNovel[] =
        "いいのよ。わたし、\r\n"
        "読み終わっちゃったし…\r\n"
        "それに、少しでもこの感動を{Press}\r\n"
        "{Player}くんに\r\n"
        "感じてもらいたいの。{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryOffersNovelToPlayer[] =
        "本を読んで感動出来る\r\n"
        "{Player}くんになら\r\n"
        "あげてもいいと思ったの。{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryHandsNovelToPlayer[] =
        "よかった。\r\n"
        "じゃ、受け取って。{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryReturnsToLibraryAfterGift[] =
        "じゃ、わたしは帰るね。\r\n"
        "その本、大切にしてね。{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryExplainsPlayersResponseToNovel[] =
        "…そう。\r\n"
        "{Player}くんは、\r\n"
        "まだ心から感動出来る本に{Press}\r\n"
        "めぐりあったことがないのね。\r\n"
        "いつか、そういう本に\r\n"
        "めぐりあうといいわね。{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryReturnsToLibraryWithoutGift[] =
        "じゃ、わたし帰らないと…\r\n"
        "{Player}くん、\r\n"
        "またね。{Press}";
};

void EventScript_LoveEvent_Mary_03_BlueHeart_DiscussEmotionalNovel(void)
{
    int var_0;
    ChangeMap(MAP_MOTHERS_HILL_SUMMIT, X(152), Y(380));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(236), Y(487), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_MARY, X(236), Y(487), FACING_UP);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    MoveEntityYTo(ENTITY_MARY, Y(380), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityFacing(ENTITY_MARY, FACING_LEFT);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    MoveEntityXTo(ENTITY_MARY, X(136), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    WaitFrames(60);
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(90);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_03_BlueHeart_MaryMovedToTearsByNovel);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_PLAYER, Y(380), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    WaitFrames(30);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityXTo(ENTITY_PLAYER, X(152), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(60);
    SetEntityFacing(ENTITY_MARY, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_03_BlueHeart_MaryGreetsPlayer);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_03_BlueHeart_MaryEmbarrassedPlayerSawHerCry);
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_03_BlueHeart_MaryExplainsFindingNovel);
    SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_03_BlueHeart_MaryExplainsReadingOutdoors);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_03_BlueHeart_MaryAsksIfPlayerEverCries);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Mary_03_BlueHeart_ChoiceSometimesCry, gText_LoveEvent_Mary_03_BlueHeart_ChoiceNeverCry);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_MARY, 3000);
            TalkClose();
            StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_HAPPY, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_03_BlueHeart_MaryAppreciatesEmotionalReaders);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_03_BlueHeart_MaryFinishedReadingNovel);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_03_BlueHeart_MaryOffersNovelToPlayer);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_03_BlueHeart_MaryHandsNovelToPlayer);
            TalkClose();
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_GESTURE);
            WaitFrames(60);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
            PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
            SetPlayerHeldArticle(ITEM_ARTICLE_MARYS_GREAT_BOOK);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_03_BlueHeart_MaryReturnsToLibraryAfterGift);
            TalkClose();
            SetEntityFacing(ENTITY_MARY, FACING_DOWN);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
            MoveEntityYTo(ENTITY_MARY, Y(435), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_MARY);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
            SetEntityFacing(ENTITY_MARY, FACING_RIGHT);
            SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
            MoveEntityXTo(ENTITY_MARY, X(236), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_MARY);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
            SetEntityFacing(ENTITY_MARY, FACING_DOWN);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
            MoveEntityYTo(ENTITY_MARY, Y(479), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_MARY);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
            HideEntity(ENTITY_MARY);
            MarkNpcSpokenTo(CHARACTER_MARY);
            VarSet(VAR_MARY_BLUE_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_03_BlueHeart_MaryExplainsPlayersResponseToNovel);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_03_BlueHeart_MaryReturnsToLibraryWithoutGift);
            TalkClose();
            SetEntityFacing(ENTITY_MARY, FACING_DOWN);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
            MoveEntityYTo(ENTITY_MARY, Y(435), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_MARY);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
            SetEntityFacing(ENTITY_MARY, FACING_RIGHT);
            SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
            MoveEntityXTo(ENTITY_MARY, X(236), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_MARY);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
            SetEntityFacing(ENTITY_MARY, FACING_DOWN);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
            MoveEntityYTo(ENTITY_MARY, Y(479), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_MARY);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
            HideEntity(ENTITY_MARY);
            MarkNpcSpokenTo(CHARACTER_MARY);
            VarSet(VAR_MARY_BLUE_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            break;
    }
}
