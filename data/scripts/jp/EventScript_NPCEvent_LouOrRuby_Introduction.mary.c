#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_LouOrRuby_Introduction_LouOrRubyIntroducesWeeklyFoodBuyingVisitAtInn[] =
        "おはようさん。{Press}\p"
        "今度、ミネラルタウンに毎週\r\n"
        "食材を買いに来る事になった\r\n"
        "ルウっていうねん。{Press}\p"
        "ここの町は食材がいいって評判\r\n"
        "でねぇ。{Press}\p"
        "わたしの宿屋もここの食材を\r\n"
        "使って料理を作ろうって事に\r\n"
        "なったんよ。{Press}\p"
        "毎週日曜日に宿屋におるから、\r\n"
        "なんかあったらきてや。{Press}\p"
        "ほな、さいなら。{Press}";
};

void EventScript_NPCEvent_LouOrRuby_Introduction(void)
{
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_LOU_OR_RUBY, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_LOU_OR_RUBY, ANIMATION_LOU_OR_RUBY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LOU_OR_RUBY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LOU_OR_RUBY);
    TalkMessage(gText_NPCEvent_LouOrRuby_Introduction_LouOrRubyIntroducesWeeklyFoodBuyingVisitAtInn);
    TalkClose();
    SetEntityFacing(ENTITY_LOU_OR_RUBY, FACING_RIGHT);
    SetEntityAnim(ENTITY_LOU_OR_RUBY, ANIMATION_LOU_OR_RUBY_WALK);
    MoveEntityXTo(ENTITY_LOU_OR_RUBY, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_LOU_OR_RUBY);
    SetEntityFacing(ENTITY_LOU_OR_RUBY, FACING_UP);
    MoveEntityYTo(ENTITY_LOU_OR_RUBY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_LOU_OR_RUBY);
    HideEntity(ENTITY_LOU_OR_RUBY);
    MarkNpcSpokenTo(CHARACTER_LOU_OR_RUBY);
    VarSet(VAR_LOU_OR_RUBY_INTRODUCTION_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
