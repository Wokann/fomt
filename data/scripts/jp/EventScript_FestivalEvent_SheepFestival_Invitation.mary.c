#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_Invitation_NoSheepAvailable[] =
        "明日広場で、羊祭りを\r\n"
        "するんじゃよ。もしよかったら\r\n"
        "見に来るとええ。{Press}\p"
        "羊祭りには、妊娠、病気を\r\n"
        "していなくて、毛を刈り取って\r\n"
        "いない、大人の羊なら{Press}\r\n"
        "参加できるんじゃ。{Press}\p"
        "来年は{Place1}牧場からも\r\n"
        "出てほしいもんじゃよ。\r\n"
        "それじゃあ{Player}さん。{Press}\r\n"
        "明日は待っとるからの。{Press}";

    const char gText_FestivalEvent_SheepFestival_Invitation_OnlyLambsAvailable[] =
        "明日広場で、羊祭りを\r\n"
        "するんじゃよ。もしよかったら\r\n"
        "見に来るとええ。{Press}\p"
        "羊祭りには、妊娠、病気を\r\n"
        "していなくて、毛を刈り取って\r\n"
        "いない、大人の羊なら{Press}\r\n"
        "参加できるんじゃ。{Press}\p"
        "{Player}さんとこの羊も\r\n"
        "来年なら出られるじゃろう。\r\n"
        "それじゃあ{Player}さん。{Press}\r\n"
        "明日は待っとるからの。{Press}";

    const char gText_FestivalEvent_SheepFestival_Invitation_EligibleSheepInvitation[] =
        "{Player}さん。\r\n"
        "明日は１０時から、広場で\r\n"
        "羊祭りをやるんじゃよ。{Press}\p"
        "{Place1}牧場の羊を\r\n"
        "出してみんかね？{Press}";

    const char gText_FestivalEvent_SheepFestival_Invitation_AcceptEntryChoice[] =
        "参加する";

    const char gText_FestivalEvent_SheepFestival_Invitation_DeclineEntryChoice[] =
        "参加しない";

    const char gText_FestivalEvent_SheepFestival_Invitation_PromptSelectEligibleSheep[] =
        "それじゃあ、どの羊にするか\r\n"
        "決めてくれんか？{Press}\p"
        "大人の羊なら何でも\r\n"
        "いいんじゃが、病気や妊娠中、\r\n"
        "毛を刈られた羊はダメじゃよ。{Press}";

    const char gText_FestivalEvent_SheepFestival_Invitation_ThomasRespondsToDeclinedEntry[] =
        "そうか、\r\n"
        "{Player}さんの羊なら\r\n"
        "いいと思ったんじゃがの。{Press}";

    const char gText_FestivalEvent_SheepFestival_Invitation_NoEligibleAdultSheep[] =
        "明日広場で、羊祭りを\r\n"
        "するんじゃよ。もしよかったら\r\n"
        "見に来るとええ。{Press}\p"
        "羊祭りには、妊娠、病気を\r\n"
        "していなくて、毛を刈り取って\r\n"
        "いない、大人の羊なら{Press}\r\n"
        "参加できるんじゃが、{Press}\p"
        "参加できる羊が\r\n"
        "おらんようじゃの。{Press}\p"
        "それじゃあ{Player}さん。\r\n"
        "明日は待っとるからの。{Press}";

    const char gText_FestivalEvent_SheepFestival_Invitation_ThomasTakesSelectedSheepForEntry[] =
        "それじゃあ、こいつは\r\n"
        "連れていくからの。\r\n"
        "明日は必ず来るようにな。{Press}";
};

void EventScript_FestivalEvent_SheepFestival_Invitation(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5;
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
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    var_1 = mary_negated_int(ANIMAL_SLOT_NOT_SELECTED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    if (CountAnimalsByLifeState(ANIMAL_KIND_SHEEP, LIVESTOCK_LIFE_STATE_ALIVE) == 0)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FestivalEvent_SheepFestival_Invitation_NoSheepAvailable);
        TalkClose();
    }
    else
    {
        var_2 = 0;
        var_3 = 0;
        var_4 = 0;
        for (var_5 = ANIMAL_SLOT_1; var_5 < 16; var_5++)
        {
            if (IsCowAtBarnSlot(var_5) == FALSE)
            {
                if (GetAnimalGrowthStage(ANIMAL_KIND_SHEEP, var_5) == ANIMAL_SHEEP_GROWTH_STAGE_ADULT)
                {
                    var_3++;
                    if (IsAnimalSick(ANIMAL_KIND_SHEEP, var_5) == FALSE && IsAnimalPregnant(ANIMAL_KIND_SHEEP, var_5) == FALSE && IsSheepSheared(var_5) == FALSE)
                    {
                        var_4++;
                    }
                }
                else
                {
                    var_2++;
                }
            }
        }
        if (var_2 > 0 && var_3 == 0)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BARLEY);
            TalkMessage(gText_FestivalEvent_SheepFestival_Invitation_OnlyLambsAvailable);
            TalkClose();
        }
        else
        {
            if (var_4 > 0)
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_BARLEY);
                TalkMessage(gText_FestivalEvent_SheepFestival_Invitation_EligibleSheepInvitation);
                TalkClose();
                TalkOpen();
                var_0 = TalkChoice2(gText_FestivalEvent_SheepFestival_Invitation_AcceptEntryChoice, gText_FestivalEvent_SheepFestival_Invitation_DeclineEntryChoice);
                TalkClose();
                if (var_0 == CHOICE_OPTION_1)
                {
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_BARLEY);
                    TalkMessage(gText_FestivalEvent_SheepFestival_Invitation_PromptSelectEligibleSheep);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    var_1 = SelectFestivalAnimal(FESTIVAL_ANIMAL_SHEEP);
                    if (var_1 != mary_negated_int(ANIMAL_SLOT_NOT_SELECTED))
                    {
                        GetAnimalName(TEXT_VARIABLE_1, ANIMAL_KIND_SHEEP, var_1);
                        SetEntityPosition(ENTITY_BARLEY, X(242), Y(145), FACING_UP);
                        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
                        SetEntityPosition(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, X(212), Y(145), FACING_UP);
                        SetEntityAnim(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, ANIMATION_SHEEP_IDLE);
                        StopEntityEffect(ENTITY_BARN_ANIMAL_SLOT_1 + var_1);
                    }
                    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                }
                else
                {
                    var_1 = mary_negated_int(ANIMAL_SLOT_NOT_SELECTED);
                }
                if (var_1 == mary_negated_int(ANIMAL_SLOT_NOT_SELECTED))
                {
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_BARLEY);
                    TalkMessage(gText_FestivalEvent_SheepFestival_Invitation_ThomasRespondsToDeclinedEntry);
                    TalkClose();
                }
            }
            else
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_BARLEY);
                TalkMessage(gText_FestivalEvent_SheepFestival_Invitation_NoEligibleAdultSheep);
                TalkClose();
            }
        }
    }
    if (var_1 == mary_negated_int(ANIMAL_SLOT_NOT_SELECTED))
    {
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        SetEntityFacing(ENTITY_BARLEY, FACING_RIGHT);
        MoveEntityXTo(ENTITY_BARLEY, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        SetEntityFacing(ENTITY_BARLEY, FACING_UP);
        MoveEntityYTo(ENTITY_BARLEY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        HideEntity(ENTITY_BARLEY);
        VarSet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_NOT_SELECTED);
        VarSet(VAR_SHEEP_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_COMPLETED);
        return;
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FestivalEvent_SheepFestival_Invitation_ThomasTakesSelectedSheepForEntry);
        TalkClose();
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        SetEntityFacing(ENTITY_BARLEY, FACING_RIGHT);
        MoveEntityXTo(ENTITY_BARLEY, X(330), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
        SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
        SetEntityAnim(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, ANIMATION_SHEEP_WALK);
        SetEntityFacing(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, FACING_RIGHT);
        MoveEntityXTo(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, X(305), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARN_ANIMAL_SLOT_1 + var_1);
        SetEntityAnim(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, ANIMATION_SHEEP_IDLE);
        WaitFrames(30);
        SetEntityFacing(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, FACING_UP);
        SetEntityFacing(ENTITY_BARLEY, FACING_UP);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        MoveEntityYTo(ENTITY_BARLEY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        SetEntityAnim(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, ANIMATION_SHEEP_WALK);
        MoveEntityYTo(ENTITY_BARN_ANIMAL_SLOT_1 + var_1, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        WaitForEntityMovement(ENTITY_BARN_ANIMAL_SLOT_1 + var_1);
        HideEntity(ENTITY_BARLEY);
        HideEntity(ENTITY_BARN_ANIMAL_SLOT_1 + var_1);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        VarSet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_SELECTED);
        SetContestAnimal(ANIMAL_KIND_SHEEP, var_1);
        VarSet(VAR_SHEEP_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_COMPLETED);
    }
}
