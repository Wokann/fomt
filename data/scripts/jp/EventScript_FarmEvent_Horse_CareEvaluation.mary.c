#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Horse_CareEvaluation_Barley_ArrivesToInspectHorse[] =
        "やあ、{Player}さん。\r\n"
        "{Var1}の様子を\r\n"
        "見に来たぞ。{Press}\r\n"
        "そろそろ大きくなった\r\n"
        "じゃろう。{Press}";

    const char gText_FarmEvent_Horse_CareEvaluation_Barley_Hesitates[] =
        "ふむ、ふむ…{Press}";

    const char gText_FarmEvent_Horse_CareEvaluation_Barley_PraisesHorseCare[] =
        "あれから１年間、愛情を持って\r\n"
        "しっかり育てたようじゃな。\r\n"
        "合格じゃ。{Press}";

    const char gText_FarmEvent_Horse_CareEvaluation_Barley_AwardsHorseOwnership[] =
        "しっかり育ててくれたお礼に\r\n"
        "{Var1}をここの馬に\r\n"
        "してやってもかまわんよ。{Press}\p"
        "{Player}さんにずいぶん\r\n"
        "なついているようじゃからの。{Press}\p"
        "これからも{Var1}\r\n"
        "のことを頼むぞ。{Press}";

    const char gText_FarmEvent_Horse_CareEvaluation_Barley_ReclaimsNeglectedHorse[] =
        "残念じゃが、\r\n"
        "{Player}さん。{Press}\p"
        "この１年、馬に対する愛情が\r\n"
        "足りなかったようじゃの。\r\n"
        "失格じゃ。{Press}";

    const char gText_FarmEvent_Horse_CareEvaluation_Barley_TakesHorseHome[] =
        "{Var1}は、\r\n"
        "連れてかえるからの。{Press}";
};

void EventScript_FarmEvent_Horse_CareEvaluation(void)
{
    int var_0;
    SetEntityPosition(ENTITY_PLAYER, X(228), Y(120), FACING_DOWN);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_BARLEY, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    SetEntityPosition(ENTITY_FARM_HORSE, X(0), Y(0), FACING_UP);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    GetAnimalName(TEXT_VARIABLE_1, ANIMAL_KIND_HORSE, ANIMAL_PET_INDEX_ARGUMENT_IGNORED_ZERO);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_FarmEvent_Horse_CareEvaluation_Barley_ArrivesToInspectHorse);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_HORSE_STABLE, X(68), Y(124));
    SetEntityPosition(ENTITY_PLAYER, X(68), Y(124), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_BARLEY, X(90), Y(124), FACING_UP);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    SetEntityPosition(ENTITY_FARM_HORSE, X(83), Y(76), FACING_DOWN);
    SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FARM_HORSE_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    var_0 = VarGet(VAR_HORSE_AFFECTION);
    if (var_0 >= 100)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FarmEvent_Horse_CareEvaluation_Barley_Hesitates);
        ClearTalkPortrait();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_HAPPY);
        TalkMessage(gText_FarmEvent_Horse_CareEvaluation_Barley_PraisesHorseCare);
        TalkClose();
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_FARM, X(316), Y(116));
        SetEntityPosition(ENTITY_PLAYER, X(316), Y(116), FACING_RIGHT);
        if (IsPlayerHoldingNothing() == TRUE)
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        }
        else
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
        }
        SetEntityPosition(ENTITY_BARLEY, X(342), Y(116), FACING_LEFT);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FarmEvent_Horse_CareEvaluation_Barley_AwardsHorseOwnership);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        if (IsPlayerHoldingNothing() == TRUE)
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        }
        else
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
        }
        SetEntityFacing(ENTITY_BARLEY, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_UP);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        MoveEntityYTo(ENTITY_BARLEY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        HideEntity(ENTITY_BARLEY);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        AddNpcFriendship(CHARACTER_BARLEY, 10);
        VarSet(VAR_BARLEY_HORSE_YEAR_EVALUATION_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FarmEvent_Horse_CareEvaluation_Barley_Hesitates);
        ClearTalkPortrait();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_ANGRY);
        TalkMessage(gText_FarmEvent_Horse_CareEvaluation_Barley_ReclaimsNeglectedHorse);
        TalkClose();
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_FARM, X(316), Y(116));
        SetEntityPosition(ENTITY_PLAYER, X(316), Y(116), FACING_RIGHT);
        if (IsPlayerHoldingNothing() == TRUE)
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        }
        else
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
        }
        SetEntityPosition(ENTITY_BARLEY, X(342), Y(116), FACING_LEFT);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
        SetEntityPosition(ENTITY_FARM_HORSE, X(366), Y(116), FACING_LEFT);
        SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FARM_HORSE_IDLE);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_ANGRY);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FarmEvent_Horse_CareEvaluation_Barley_TakesHorseHome);
        TalkClose();
        SetEntityFacing(ENTITY_BARLEY, FACING_UP);
        SetEntityFacing(ENTITY_FARM_HORSE, FACING_UP);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FARM_HORSE_WALK);
        MoveEntityYTo(ENTITY_BARLEY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        MoveEntityYTo(ENTITY_FARM_HORSE, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        WaitForEntityMovement(ENTITY_FARM_HORSE);
        HideEntity(ENTITY_BARLEY);
        HideEntity(ENTITY_FARM_HORSE);
        AddNpcFriendship(CHARACTER_BARLEY, mary_negated_int(-10));
        RemoveFarmHorse(FALSE, 0);
        VarSet(VAR_BARLEY_HORSE_YEAR_EVALUATION_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    }
}
