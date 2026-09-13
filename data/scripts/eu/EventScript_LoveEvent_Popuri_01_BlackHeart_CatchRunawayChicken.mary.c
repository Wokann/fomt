#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ChasesRunawayChicken[] =
        "Wait a second...!{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_CallsChickenBack[] =
        "Wait, come back!{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ScoldsChicken[] =
        "Bad chicken! \r\n"
        "Don't run away again!{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ThanksPlayerForCatch[] =
        "Thanks for helping me out. {Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_AsksIfPlayerIsNew[] =
        "I don't think I've seen you \r\n"
        "around before? {Press}\r\n"
        "My name is Popuri. \r\n"
        "How do you do.{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_RecognizesNewFarmer[] =
        "Ah, you're the new guy\r\n"
        "over at that farm, right?{Press}\p"
        "{Player} is your\r\n"
        "name? Nice to meet you! {Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ExplainsChickenEscaped[] =
        "Uh-oh. I let the \r\n"
        "Chicken get away again!{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ThanksPlayerAgain[] =
        "Thank you.\r\n"
        "Chickens are really hard\r\n"
        "to catch, you know. {Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_AsksIfPlayerLikesChickens[] =
        "Do you like Chickens, \r\n"
        "{Player}?{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_ChoiceLikesChickens[] =
        "Yes, I do.";

    const char gText_LoveEvent_Popuri_01_BlackHeart_ChoiceDislikesChickens[] =
        "No, I don't.";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_HappyPlayerLikesChickens[] =
        "I thought so! \r\n"
        "I love Chickens, too!{Press}\p"
        "I think people who like\r\n"
        "Chickens are just good\r\n"
        "people. Don't you agree?{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_PreparesToReturnChicken[] =
        "I've got to bring her back\r\n"
        "to the house now. {Press}\p"
        "If you ever need help with\r\n"
        "Chickens, just come to me!{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_InvitesRunawayChickenHome[] =
        "Let's go home now,\r\n"
        "baby!{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_QuestionsChickenDislike[] =
        "But why not?!\r\n"
        "They're so cute!{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_QuestionsFarmVisit[] =
        "Then what are you \r\n"
        "doing here?{Press}\p"
        "It's a Chicken farm, after \r\n"
        "all...Full of Chickens you \r\n"
        "hate, right?! {Press}\p"
        "Sorry to make you touch\r\n"
        "a Chicken!{Press}";

    const char gText_LoveEvent_Popuri_01_BlackHeart_Popuri_InvitesChickensHomeAfterDislikedChoice[] =
        "Let's go home now, \r\n"
        "Chickies! {Press}";
};

void EventScript_LoveEvent_Popuri_01_BlackHeart_CatchRunawayChicken(void)
{
    int var_0;
    ChangeMap(MAP_SOUTH_SIDE_TOWN, X(471), Y(171));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(320), Y(171), FACING_RIGHT);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_POPURI, X(471), Y(300), FACING_UP);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(471), Y(300), FACING_UP);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityXTo(ENTITY_PLAYER, X(471), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ChasesRunawayChicken);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
    MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(GetEntityY(ENTITY_PLAYER) + 8), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_CallsChickenBack);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
    BeginHoldingActorGraphic(ANIMATION_CHICKEN_HELD);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
    MoveEntityYTo(ENTITY_POPURI, Y(202), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
    MoveEntityYTo(ENTITY_POPURI, Y(GetEntityY(ENTITY_PLAYER) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    if (HasMetNpc(CHARACTER_POPURI) == FALSE)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ScoldsChicken);
        TalkClose();
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        ShowTalkHeartIndicator(CHARACTER_POPURI);
        TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ThanksPlayerForCatch);
        TalkClose();
        SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
        WaitFrames(60);
        UsePlayerHeldItem();
        SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_PLAYER) - 16), Y(GetEntityY(ENTITY_PLAYER)), FACING_DOWN);
        SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        WaitFrames(60);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        ShowTalkHeartIndicator(CHARACTER_POPURI);
        TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_AsksIfPlayerIsNew);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        ShowTalkHeartIndicator(CHARACTER_POPURI);
        TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_RecognizesNewFarmer);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        ShowTalkHeartIndicator(CHARACTER_POPURI);
        TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ExplainsChickenEscaped);
        TalkClose();
        SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
        WaitFrames(60);
        UsePlayerHeldItem();
        SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_PLAYER) - 16), Y(GetEntityY(ENTITY_PLAYER)), FACING_DOWN);
        SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        ShowTalkHeartIndicator(CHARACTER_POPURI);
        TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_ThanksPlayerAgain);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_AsksIfPlayerLikesChickens);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Popuri_01_BlackHeart_ChoiceLikesChickens, gText_LoveEvent_Popuri_01_BlackHeart_ChoiceDislikesChickens);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_POPURI, 3000);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_HappyPlayerLikesChickens);
            TalkClose();
            StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_HAPPY, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_PreparesToReturnChicken);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_InvitesRunawayChickenHome);
            TalkClose();
            SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityYTo(ENTITY_POPURI, Y(242), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            SetEntityFacing(ENTITY_POPURI, FACING_UP);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(GetEntityY(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_RIGHT);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityXTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_DOWN);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(226), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityXTo(ENTITY_POPURI, X(572), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            SetEntityFacing(ENTITY_POPURI, FACING_LEFT);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(242), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_RIGHT);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityXTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(556), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_POPURI, FACING_UP);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityYTo(ENTITY_POPURI, Y(228), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            HideEntity(ENTITY_POPURI);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityXTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(572), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_UP);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(228), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
            MarkNpcSpokenTo(CHARACTER_POPURI);
            VarSet(VAR_POPURI_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_POPURI, mary_negated_int(-2000));
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_QuestionsChickenDislike);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_QuestionsFarmVisit);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            TalkMessage(gText_LoveEvent_Popuri_01_BlackHeart_Popuri_InvitesChickensHomeAfterDislikedChoice);
            TalkClose();
            SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityYTo(ENTITY_POPURI, Y(242), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            SetEntityFacing(ENTITY_POPURI, FACING_UP);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(GetEntityY(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_RIGHT);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityXTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_DOWN);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(226), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityXTo(ENTITY_POPURI, X(572), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            SetEntityFacing(ENTITY_POPURI, FACING_LEFT);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(242), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_RIGHT);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityXTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(556), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_POPURI, FACING_UP);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
            MoveEntityYTo(ENTITY_POPURI, Y(228), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_POPURI);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            HideEntity(ENTITY_POPURI);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityXTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(572), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            SetEntityFacing(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, FACING_UP);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_WALK);
            MoveEntityYTo(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, Y(228), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
            HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
            PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
            MarkNpcSpokenTo(CHARACTER_POPURI);
            VarSet(VAR_POPURI_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            break;
    }
    RefreshAllNpcSchedules();
}
