#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Elli_04_YellowHeart_ElliGreetsPlayerAtBeach[] =
        "Hi there, {Player}. {Press}";

    const char gText_LoveEvent_Elli_04_YellowHeart_ElliAsksIfVisitIsSurprising[] =
        "Are you surprised to see me \r\n"
        "at the Beach? {Press}\p"
        "We used to come here often \r\n"
        "when my parents were alive. {Press}\p"
        "It has lots of memories\r\n"
        "for me...{Press}";

    const char gText_LoveEvent_Elli_04_YellowHeart_ElliExplainsSheVisitsWhenWorried[] =
        "I come when I have\r\n"
        "a lot on my mind. {Press}\p"
        "I feel like my parents can \r\n"
        "hear me here.{Press}";

    const char gText_LoveEvent_Elli_04_YellowHeart_ElliIntroducesConcernAboutStu[] =
        "Today I came about Stu...{Press}";

    const char gText_LoveEvent_Elli_04_YellowHeart_ElliDescribesStusMisbehavior[] =
        "Stu always makes trouble, \r\n"
        "and doesn't mind me at all!{Press}\p"
        "I've tried to be like a \r\n"
        "mother to him, but I don't\r\n"
        "think I've done a good job.{Press}";

    const char gText_LoveEvent_Elli_04_YellowHeart_ChoiceSayElliSpoilsStu[] =
        "You've spoiled him.";

    const char gText_LoveEvent_Elli_04_YellowHeart_ChoicePraiseElliForRaisingStu[] =
        "You're doing a great job!";

    const char gText_LoveEvent_Elli_04_YellowHeart_ElliAcceptsNeedForMoreDiscipline[] =
        "I knew I should have been\r\n"
        "stricter with him...{Press}\p"
        "Everyone else in town \r\n"
        "probably thinks so, too...\r\n"
        "Ahh...I'm going home now.{Press}";

    const char gText_LoveEvent_Elli_04_YellowHeart_ElliThanksPlayerForReassurance[] =
        "Thanks, {Player}!\r\n"
        "If you say so, then I can \r\n"
        "be confident I'm doing{Press}\r\n"
        "a good job. {Press}";
};

void EventScript_LoveEvent_Elli_04_YellowHeart_DiscussRaisingStu(void)
{
    int var_0;
    ChangeMap(MAP_MINERAL_BEACH, X(385), Y(144));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(231), Y(144), FACING_RIGHT);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_ELLI, X(221), Y(124), FACING_RIGHT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
    MoveEntityXTo(ENTITY_ELLI, X(385), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_ELLI);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    WaitFrames(60);
    StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(90);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityXTo(ENTITY_PLAYER, X(385), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    WaitFrames(60);
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_04_YellowHeart_ElliGreetsPlayerAtBeach);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_04_YellowHeart_ElliAsksIfVisitIsSurprising);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_04_YellowHeart_ElliExplainsSheVisitsWhenWorried);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_04_YellowHeart_ElliIntroducesConcernAboutStu);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_04_YellowHeart_ElliDescribesStusMisbehavior);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Elli_04_YellowHeart_ChoiceSayElliSpoilsStu, gText_LoveEvent_Elli_04_YellowHeart_ChoicePraiseElliForRaisingStu);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_04_YellowHeart_ElliAcceptsNeedForMoreDiscipline);
            TalkClose();
            SetEntityFacing(ENTITY_ELLI, FACING_LEFT);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
            MoveEntityXTo(ENTITY_ELLI, X(231), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            HideEntity(ENTITY_ELLI);
            MarkNpcSpokenTo(CHARACTER_ELLI);
            VarSet(VAR_ELLI_YELLOW_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_ELLI, 3000);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_04_YellowHeart_ElliThanksPlayerForReassurance);
            TalkClose();
            SetEntityFacing(ENTITY_ELLI, FACING_LEFT);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
            MoveEntityXTo(ENTITY_ELLI, X(231), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            HideEntity(ENTITY_ELLI);
            MarkNpcSpokenTo(CHARACTER_ELLI);
            VarSet(VAR_ELLI_YELLOW_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            break;
    }
}
