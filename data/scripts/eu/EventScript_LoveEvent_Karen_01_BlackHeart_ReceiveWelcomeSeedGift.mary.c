#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_Greeting[] =
        "Welcome. {Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_AsksIfPlayerIsTourist[] =
        "I've never seen you around\r\n"
        "here before. Are you \r\n"
        "a tourist? {Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_IntroducesHerself[] =
        "So you're the new guy at \r\n"
        "that farm? I heard about \r\n"
        "you. {Press}\p"
        "My name is Karen. \r\n"
        "How do you do. {Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_GreetsReturningPlayer[] =
        "Hi there, {Player}. \r\n"
        "Did you come to shop?{Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_InvitesPlayerToShop[] =
        "Take your time now. {Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_OffersHelp[] =
        "If you just started, then \r\n"
        "you must need lots of \r\n"
        "things, right? {Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_ChoiceRequestHelp[] =
        "I could use some help.";

    const char gText_LoveEvent_Karen_01_BlackHeart_ChoiceDeclineHelp[] =
        "No problem.";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_AsksPlayerToWait[] =
        "Just wait one second. {Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_AsksJeffForGrassSeeds[] =
        "Dad, can we give him one\r\n"
        "bag of Seeds? {Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Jeff_ObjectsToFreeSeeds[] =
        "Oh, come on!...{Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_AppealsForKindness[] =
        "Whatever happened to \r\n"
        "kindness to strangers!{Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Sasha_EncouragesJeff[] =
        "Why don't you show him \r\n"
        "some hospitality...Please?{Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Jeff_Agrees[] =
        "...OK.{Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_ThanksJeff[] =
        "Thanks, Dad. {Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Sasha_PraisesJeff[] =
        "See? There is a reason \r\n"
        "why you are my husband!{Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_GivesGrassSeeds[] =
        "Here you are. This is \r\n"
        "on the house. \r\n"
        "Don't mention it. {Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_EncouragesFarmWork[] =
        "It takes a lot of work to \r\n"
        "start up a farm. I'm \r\n"
        "rooting for you. {Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_OffersFutureHelp[] =
        "Just let me know if you \r\n"
        "need any help. {Press}";
};

void EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift(void)
{
    int var_0;
    ChangeMap(MAP_SUPERMARKET, X(145), Y(275));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(145), Y(274), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_KAREN, X(145), Y(227), FACING_DOWN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(175), Y(115), FACING_DOWN);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_JEFF, X(226), Y(115), FACING_DOWN);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_Greeting);
    TalkClose();
    StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    if (HasMetNpc(CHARACTER_KAREN) == FALSE)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        ShowTalkHeartIndicator(CHARACTER_KAREN);
        TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_AsksIfPlayerIsTourist);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        ShowTalkHeartIndicator(CHARACTER_KAREN);
        TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_IntroducesHerself);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        ShowTalkHeartIndicator(CHARACTER_KAREN);
        TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_GreetsReturningPlayer);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        ShowTalkHeartIndicator(CHARACTER_KAREN);
        TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_InvitesPlayerToShop);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_OffersHelp);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Karen_01_BlackHeart_ChoiceRequestHelp, gText_LoveEvent_Karen_01_BlackHeart_ChoiceDeclineHelp);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_KAREN, 3000);
            AddNpcFriendship(CHARACTER_JEFF, 20);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_AsksPlayerToWait);
            TalkClose();
            SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
            MoveEntityXTo(ENTITY_KAREN, X(184), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            PanCameraTo(X(155), Y(136), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
            WaitForEntityMovement(ENTITY_KAREN);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            SetEntityFacing(ENTITY_KAREN, FACING_UP);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
            MoveEntityYTo(ENTITY_KAREN, Y(152), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_KAREN);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            WaitForCameraMovement();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_AsksJeffForGrassSeeds);
            TalkClose();
            StartEntityEffect(ENTITY_JEFF, ENTITY_EMOTE_EXCLAMATION, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_JEFF);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Jeff_ObjectsToFreeSeeds);
            TalkClose();
            StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_ANGRY, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_AppealsForKindness);
            TalkClose();
            SetEntityFacing(ENTITY_SASHA, FACING_RIGHT);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_SASHA);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Sasha_EncouragesJeff);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_JEFF);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Jeff_Agrees);
            TalkClose();
            StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_HAPPY, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_ThanksJeff);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_SASHA);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Sasha_PraisesJeff);
            TalkClose();
            PanCameraTo(X(145), Y(274), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
            SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
            MoveEntityYTo(ENTITY_KAREN, Y(258), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_KAREN);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            SetEntityFacing(ENTITY_KAREN, FACING_LEFT);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
            MoveEntityXTo(ENTITY_KAREN, X(145), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_KAREN);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
            WaitForCameraMovement();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_GivesGrassSeeds);
            TalkClose();
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_GESTURE);
            WaitFrames(60);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_RAISE_ARMS);
            ShowPlayerHoldingTool(ITEM_TOOL_SEEDS_GRASS);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            if (GetFirstFreeRucksackToolSlot() != mary_negated_int(RUCKSACK_SLOT_NOT_FOUND))
            {
                AddToolToRucksack(ITEM_TOOL_SEEDS_GRASS, 1);
            }
            else
            {
                SetPlayerHeldTool(ITEM_TOOL_SEEDS_GRASS, 1);
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_EncouragesFarmWork);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityFacing(ENTITY_SASHA, FACING_DOWN);
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_KAREN);
            MarkNpcSpokenTo(CHARACTER_JEFF);
            MarkNpcSpokenTo(CHARACTER_SASHA);
            SetEntityEventScript(ENTITY_KAREN, EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupKarenDialogue);
            SetEntityEventScript(ENTITY_SASHA, EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupSashaDialogue);
            SetEntityEventScript(ENTITY_JEFF, EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupJeffDialogue);
            VarSet(VAR_KAREN_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
        case CHOICE_OPTION_2:
            AddNpcFriendship(CHARACTER_JEFF, 20);
            AddNpcFriendship(CHARACTER_SASHA, 20);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_OffersFutureHelp);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_KAREN);
            MarkNpcSpokenTo(CHARACTER_JEFF);
            MarkNpcSpokenTo(CHARACTER_SASHA);
            SetEntityEventScript(ENTITY_KAREN, EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupKarenDialogue);
            SetEntityEventScript(ENTITY_SASHA, EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupSashaDialogue);
            SetEntityEventScript(ENTITY_JEFF, EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupJeffDialogue);
            VarSet(VAR_KAREN_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
    }
}
