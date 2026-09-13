#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Mary_03_BlueHeart_MaryMovedToTearsByNovel[] =
        "Sniff...Sniff...\r\n"
        "I wish I could write\r\n"
        "as well as this...!{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryGreetsPlayer[] =
        "Ah, hello, \r\n"
        "{Player}!{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryEmbarrassedPlayerSawHerCry[] =
        "I hope you didn't see me\r\n"
        "crying just now...{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryExplainsFindingNovel[] =
        "I just found this book when\r\n"
        "I was cleaning out the \r\n"
        "bookshelves. {Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryExplainsReadingOutdoors[] =
        "I wanted to read it in a \r\n"
        "place with a nice view. {Press}\r\n"
        "It turned out to be a\r\n"
        "wonderful story!{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryAsksIfPlayerEverCries[] =
        "Thanks for worrying about \r\n"
        "me. Do you ever cry like\r\n"
        "that when you read books? {Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_ChoiceSometimesCry[] =
        "Sometimes.";

    const char gText_LoveEvent_Mary_03_BlueHeart_ChoiceNeverCry[] =
        "Never.";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryAppreciatesEmotionalReaders[] =
        "I like people who read a \r\n"
        "lot, and respond to books.{Press}\p"
        "I think it means you're \r\n"
        "smart. \r\n"
        "Here, try reading this one.{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryFinishedReadingNovel[] =
        "That's OK...I've already \r\n"
        "finished it.\r\n"
        "I think you'll like this {Press}\r\n"
        "book...It made me cry!{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryOffersNovelToPlayer[] =
        "If you really like books\r\n"
        "so much, then I'm sure\r\n"
        "you'll like it, too!{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryHandsNovelToPlayer[] =
        "Here you are. {Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryReturnsToLibraryAfterGift[] =
        "I'm going back now.\r\n"
        "I hope you like the book.{Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryExplainsPlayersResponseToNovel[] =
        "...Really?\r\n"
        "That's probably because you\r\n"
        "haven't read the right\r\n"
        "books yet! {Press}\r\n"
        "I hope you do soon. {Press}";

    const char gText_LoveEvent_Mary_03_BlueHeart_MaryReturnsToLibraryWithoutGift[] =
        "I have to get back now...\r\n"
        "Bye, {Player}!{Press}";
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
