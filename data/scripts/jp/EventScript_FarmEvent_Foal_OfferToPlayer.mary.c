#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Foal_OfferToPlayer_Barley_RequestIntroduction[] =
        "やあ、{Player}さん。\r\n"
        "お前さんを見こんで、\r\n"
        "頼みがあるんじゃが…{Press}";

    const char gText_FarmEvent_Foal_OfferToPlayer_Barley_ExplainsFoalNeedsHome[] =
        "ウチの牧場で生まれた\r\n"
        "この子馬が元気が無いんじゃ。{Press}\p"
        "こいつだけかまうわけにも\r\n"
        "いかないので、\r\n"
        "大きくなるまで、ここで{Press}\r\n"
        "育ててくれんかの？{Press}";

    const char gText_FarmEvent_Foal_OfferToPlayer_Barley_DeclineRetry[] =
        "そう言わずに、なんとか\r\n"
        "引き受けてくれんか？{Press}";

    const char gText_FarmEvent_Foal_OfferToPlayer_Barley_FinalConfirmation[] =
        "どうしてもだめかのぉ…{Press}";

    const char gText_FarmEvent_Foal_OfferToPlayer_ChoiceAccept[] =
        "引き受ける";

    const char gText_FarmEvent_Foal_OfferToPlayer_ChoiceDecline[] =
        "引き受けない";

    const char gText_FarmEvent_Foal_OfferToPlayer_Barley_DeclinedResponse[] =
        "そうか。\r\n"
        "そこまで言うのなら\r\n"
        "もう頼まん。{Press}\r\n"
        "わしゃ帰る。{Press}";

    const char gText_FarmEvent_Foal_OfferToPlayer_Barley_AcceptedThanks[] =
        "おお！そうか、\r\n"
        "引き受けてくれるか。{Press}\p"
        "ならば、こいつに\r\n"
        "名前をつけてやってくれ。{Press}";

    const char gText_FarmEvent_Foal_OfferToPlayer_Barley_HorseCareInstructions[] =
        "馬を育てるといっても\r\n"
        "そんなに神経質になることは\r\n"
        "ない。{Press}\p"
        "愛情をもって育ててくれれば\r\n"
        "それでいいんじゃ。{Press}\p"
        "そのためには毎日話しかけて\r\n"
        "やるのを忘れないようにな。{Press}\p"
        "ブラシをかけてやるのも\r\n"
        "効果的じゃの。{Press}";

    const char gText_FarmEvent_Foal_OfferToPlayer_Barley_MovesFoalToStable[] =
        "では、こいつは馬小屋に\r\n"
        "連れていっておくからの。{Press}";

    const char gText_FarmEvent_Foal_OfferToPlayer_Barley_PromisesToCheckOnFoal[] =
        "大きくなったら\r\n"
        "迎えに来るからの。{Press}\p"
        "それまでにしっかり\r\n"
        "育ててくれよ。\r\n"
        "たのんだぞ。{Press}";
};

void EventScript_FarmEvent_Foal_OfferToPlayer(void)
{
    int var_0, var_1, var_2;
    var_2 = 0;
    CreateFarmHorse(FALSE, ANIMAL_HORSE_AGE_STAGE_FOAL, MAP_FARM, X(207), Y(145));
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
    SetEntityPosition(ENTITY_FARM_HORSE, X(207), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FOAL_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_FarmEvent_Foal_OfferToPlayer_Barley_RequestIntroduction);
    TalkClose();
    SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
    WaitFrames(60);
    SetEntityFacing(ENTITY_BARLEY, FACING_UP);
    do
    {
        switch (var_2)
        {
            case 0:
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_BARLEY_AFRAID);
                SetTalkNameplateCharacter(CHARACTER_BARLEY);
                TalkMessage(gText_FarmEvent_Foal_OfferToPlayer_Barley_ExplainsFoalNeedsHome);
                TalkClose();
                break;
            case 1:
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_BARLEY_AFRAID);
                SetTalkNameplateCharacter(CHARACTER_BARLEY);
                TalkMessage(gText_FarmEvent_Foal_OfferToPlayer_Barley_DeclineRetry);
                TalkClose();
                break;
            case 2:
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_BARLEY_AFRAID);
                SetTalkNameplateCharacter(CHARACTER_BARLEY);
                TalkMessage(gText_FarmEvent_Foal_OfferToPlayer_Barley_FinalConfirmation);
                TalkClose();
                break;
        }
        TalkOpen();
        var_0 = TalkChoice2(gText_FarmEvent_Foal_OfferToPlayer_ChoiceAccept, gText_FarmEvent_Foal_OfferToPlayer_ChoiceDecline);
        TalkClose();
        switch (var_0)
        {
            case CHOICE_OPTION_1:
                var_1 = FALSE;
                break;
            case CHOICE_OPTION_2:
                var_1 = TRUE;
                ++var_2;
                break;
        }
    }
    while (var_1 != FALSE && var_2 < 3);
    if (var_1 != FALSE)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_ANGRY);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FarmEvent_Foal_OfferToPlayer_Barley_DeclinedResponse);
        TalkClose();
        AddNpcFriendship(CHARACTER_BARLEY, mary_negated_int(-10));
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        SetEntityFacing(ENTITY_BARLEY, FACING_RIGHT);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        MoveEntityXTo(ENTITY_BARLEY, X(337), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
        SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
        SetEntityFacing(ENTITY_FARM_HORSE, FACING_RIGHT);
        SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FOAL_WALK);
        MoveEntityXTo(ENTITY_FARM_HORSE, X(305), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_FARM_HORSE);
        SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FOAL_IDLE);
        WaitFrames(30);
        SetEntityFacing(ENTITY_FARM_HORSE, FACING_UP);
        SetEntityFacing(ENTITY_BARLEY, FACING_UP);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        MoveEntityYTo(ENTITY_BARLEY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FOAL_WALK);
        MoveEntityYTo(ENTITY_FARM_HORSE, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        WaitForEntityMovement(ENTITY_FARM_HORSE);
        HideEntity(ENTITY_BARLEY);
        HideEntity(ENTITY_FARM_HORSE);
        RemoveFarmHorse(FALSE, 0);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FarmEvent_Foal_OfferToPlayer_Barley_AcceptedThanks);
        TalkClose();
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        OpenNameEntry(NAME_ENTRY_HORSE, NAME_ENTRY_SINGLETON_SLOT);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FarmEvent_Foal_OfferToPlayer_Barley_HorseCareInstructions);
        TalkClose();
        SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
        WaitFrames(30);
        SetEntityFacing(ENTITY_BARLEY, FACING_UP);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FarmEvent_Foal_OfferToPlayer_Barley_MovesFoalToStable);
        TalkClose();
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        SetEntityFacing(ENTITY_BARLEY, FACING_RIGHT);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        SetEntityFacing(ENTITY_FARM_HORSE, FACING_RIGHT);
        SetEntityAnim(ENTITY_FARM_HORSE, ANIMATION_FOAL_WALK);
        MoveEntityXTo(ENTITY_BARLEY, X(500), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        MoveEntityXTo(ENTITY_FARM_HORSE, X(500), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        WaitForEntityMovement(ENTITY_FARM_HORSE);
        RelocateEntityToMap(ENTITY_FARM_HORSE, MAP_HORSE_STABLE, X(84), Y(124));
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
        SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        MoveEntityXTo(ENTITY_BARLEY, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FarmEvent_Foal_OfferToPlayer_Barley_PromisesToCheckOnFoal);
        TalkClose();
        SetEntityFacing(ENTITY_BARLEY, FACING_UP);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        MoveEntityYTo(ENTITY_BARLEY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
        HideEntity(ENTITY_BARLEY);
        AddNpcFriendship(CHARACTER_BARLEY, 10);
    }
    VarSet(VAR_BARLEY_FOAL_OFFER_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
}
