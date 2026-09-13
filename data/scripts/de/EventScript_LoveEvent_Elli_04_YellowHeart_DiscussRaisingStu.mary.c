#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Elli_04_YellowHeart_ElliGreetsPlayerAtBeach[] =
        "Hi, {Player}. {Press}";

    const char gText_LoveEvent_Elli_04_YellowHeart_ElliAsksIfVisitIsSurprising[] =
        "Bist du überrascht, mich \r\n"
        "am Strand zu sehen?{Press}\p"
        "Als meine Eltern noch \r\n"
        "lebten, waren wir oft hier.{Press}\p"
        "Ich habe viele \r\n"
        "Erinnerungen daran...{Press}";

    const char gText_LoveEvent_Elli_04_YellowHeart_ElliExplainsSheVisitsWhenWorried[] =
        "Ich komme, wenn mich\r\n"
        "etwas belastet. {Press}\p"
        "Ich spüre, dass mich meine \r\n"
        "Eltern hier hören können.{Press}";

    const char gText_LoveEvent_Elli_04_YellowHeart_ElliIntroducesConcernAboutStu[] =
        "Ich bin heute \r\n"
        "wegen Stu hier.{Press}";

    const char gText_LoveEvent_Elli_04_YellowHeart_ElliDescribesStusMisbehavior[] =
        "Stu macht immer Ärger, \r\n"
        "und hört nie auf mich!{Press}\p"
        "Ich habe versucht, wie \r\n"
        "eine Mutter zu ihm zu\r\n"
        "sein, aber ich bin schlecht.{Press}";

    const char gText_LoveEvent_Elli_04_YellowHeart_ChoiceSayElliSpoilsStu[] =
        "Du hast ihn verwöhnt.";

    const char gText_LoveEvent_Elli_04_YellowHeart_ChoicePraiseElliForRaisingStu[] =
        "Du machst das super!";

    const char gText_LoveEvent_Elli_04_YellowHeart_ElliAcceptsNeedForMoreDiscipline[] =
        "Ich weiß, ich hätte\r\n"
        "strenger sein sollen...{Press}\p"
        "Alle anderen in der Stadt \r\n"
        "denken das wohl auch...\r\n"
        "Ach... Ich gehe heim.{Press}";

    const char gText_LoveEvent_Elli_04_YellowHeart_ElliThanksPlayerForReassurance[] =
        "Danke, {Player}!\r\n"
        "Wenn du das sagst, \r\n"
        "bin ich mir sicher, dass{Press}\r\n"
        "ich es richtig mache. {Press}";
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
