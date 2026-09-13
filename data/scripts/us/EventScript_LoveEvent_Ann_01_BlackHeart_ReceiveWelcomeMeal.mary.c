#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Ann_01_BlackHeart_AnnWelcomesPlayer[] =
        "Welcome. {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnAsksIfPlayerIsNew[] =
        "I don't think I've seen you\r\n"
        "before. You must be\r\n"
        "{Player}, right? {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnRecognizesNewFarmer[] =
        "I knew it! I heard about you\r\n"
        "from the Mayor. {Press}\p"
        "Nice to meet you. \r\n"
        "My name is Ann, and \r\n"
        "this is my father. {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougIntroducesHimself[] =
        "Hi. I'm Doug. {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnAsksWhyPlayerVisited[] =
        "Hey there, {Player}!\r\n"
        "Did you come to eat? {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnAsksPlayerToWait[] =
        "Just wait one moment. {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnOffersWelcomeMeal[] =
        "Since you're new here, \r\n"
        "I think this one should be\r\n"
        "our treat! {Press}\p"
        "What do you think, Dad?{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougAgreesToCook[] =
        "Sure. Just make sure \r\n"
        "to come back often!{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnInvitesPlayerToStayForMeal[] =
        "See? Why don't you\r\n"
        "stay and eat? {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_ChoiceAcceptMeal[] =
        "Sounds great!";

    const char gText_LoveEvent_Ann_01_BlackHeart_ChoiceDeclineMeal[] =
        "I really couldn't.";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnCelebratesAcceptance[] =
        "Great! Make him your\r\n"
        "special, Dad!{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougPromisesSpecialMeal[] =
        "Just leave it to me!\r\n"
        "This'll be the best thing\r\n"
        "you ever ate!{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnPraisesDougsCooking[] =
        "Dad's a great cook, \r\n"
        "you know.{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougServesMeal[] =
        "Here you are.\r\n"
        "Eat it while it's hot!{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnPassesMealToPlayer[] =
        "Here you are, \r\n"
        "{Player}!{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougAsksHowMealTastes[] =
        "How does it taste? {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnAsksIfPlayerLikesMeal[] =
        "Do you like it, \r\n"
        "{Player}?{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougInvitesPlayerToReturn[] =
        "In that case, feel \r\n"
        "free to have seconds! {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnPraisesDoug[] =
        "You're the best, Dad!{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougConfidentInCooking[] =
        "Of course! Did you \r\n"
        "doubt me for a second? {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnEncouragesPlayerToEat[] =
        "Eat all you want. {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougSaysFarmWorkNeedsFood[] =
        "A working man has to eat \r\n"
        "a lot. {Press}\p"
        "I like watching you shovel\r\n"
        "it in like that! {Press}\p"
        "I've decided I like you,\r\n"
        "{Player}!{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnWaivesPayment[] =
        "Don't worry about paying us.\r\n"
        "Just come back often!{Press}\p"
        "I'm always working here. {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougInvitesReturnVisit[] =
        "Yeah, come any time\r\n"
        "and visit Ann.\r\n"
        "I can tell she'd like it. {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnEmbarrassedByDoug[] =
        "Dad! Stop teasing me...{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnDeniesEmbarrassment[] =
        "What? You don’t have to\r\n"
        "be so modest, you know! {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougTeasesAnn[] =
        "Exactly! {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnSaysGoodbye[] =
        "Come back soon!{Press}";
};

void EventScript_LoveEvent_Ann_01_BlackHeart_ReceiveWelcomeMeal(void)
{
    int var_0;
    VarSet(VAR_ANN_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    ChangeMap(MAP_INN_1F, X(184), Y(256));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(184), Y(280), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_ANN, X(184), Y(224), FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(208), Y(224), FACING_DOWN);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_AnnWelcomesPlayer);
    TalkClose();
    StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    if (HasMetNpc(CHARACTER_ANN) == FALSE)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ANN);
        ShowTalkHeartIndicator(CHARACTER_ANN);
        TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_AnnAsksIfPlayerIsNew);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ANN);
        ShowTalkHeartIndicator(CHARACTER_ANN);
        TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_AnnRecognizesNewFarmer);
        TalkClose();
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_DOUG);
        TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_DougIntroducesHimself);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ANN);
        ShowTalkHeartIndicator(CHARACTER_ANN);
        TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_AnnAsksWhyPlayerVisited);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ANN);
        ShowTalkHeartIndicator(CHARACTER_ANN);
        TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_AnnAsksPlayerToWait);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_AnnOffersWelcomeMeal);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_DougAgreesToCook);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANN);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_AnnInvitesPlayerToStayForMeal);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Ann_01_BlackHeart_ChoiceAcceptMeal, gText_LoveEvent_Ann_01_BlackHeart_ChoiceDeclineMeal);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_ANN, 3000);
            AddNpcFriendship(CHARACTER_DOUG, 20);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_AnnCelebratesAcceptance);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_DougPromisesSpecialMeal);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_AnnPraisesDougsCooking);
            TalkClose();
            StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_HAPPY, FALSE);
            WaitFrames(60);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_INN_1F, X(184), Y(139));
            PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
            SetEntityPosition(ENTITY_PLAYER, X(184), Y(139), FACING_DOWN);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityPosition(ENTITY_ANN, X(152), Y(144), FACING_RIGHT);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
            SetEntityPosition(ENTITY_DOUG, X(216), Y(144), FACING_LEFT);
            SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
            CreateEventIcon(EVENT_ICON_SLOT_0, X(176), Y(152), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_APPLE_PIE));
            CreateEventIcon(EVENT_ICON_SLOT_1, X(192), Y(152), EVENT_ICON_LAYER_HIGH_PRIORITY, GetFoodIconId(ITEM_FOOD_GRAPE_JUICE));
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_DougServesMeal);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_AnnPassesMealToPlayer);
            TalkClose();
            WaitFrames(60);
            PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
            RemoveEventIcon(EVENT_ICON_SLOT_0);
            SetPlayerHeldFood(ITEM_FOOD_APPLE_PIE);
            WaitFrames(30);
            PlaySong(AUDIO_START, AUDIO_SFX_EAT);
            ClearPlayerHeldItem();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_EAT);
            WaitFrames(24);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            WaitFrames(30);
            PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
            RemoveEventIcon(EVENT_ICON_SLOT_1);
            SetPlayerHeldFood(ITEM_FOOD_GRAPE_JUICE);
            WaitFrames(30);
            PlaySong(AUDIO_START, AUDIO_SFX_DRINK);
            ClearPlayerHeldItem();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_DRINK);
            WaitFrames(72);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_GOOD, FALSE);
            WaitFrames(60 * 4);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_DougAsksHowMealTastes);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_AnnAsksIfPlayerLikesMeal);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_DougInvitesPlayerToReturn);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_AnnPraisesDoug);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_DougConfidentInCooking);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_INN_1F, X(184), Y(139));
            PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
            SetEntityPosition(ENTITY_PLAYER, X(184), Y(139), FACING_DOWN);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityPosition(ENTITY_ANN, X(152), Y(144), FACING_RIGHT);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
            SetEntityPosition(ENTITY_DOUG, X(216), Y(144), FACING_LEFT);
            SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_AnnEncouragesPlayerToEat);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_DougSaysFarmWorkNeedsFood);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_AnnWaivesPayment);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_DougInvitesReturnVisit);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_AnnEmbarrassedByDoug);
            TalkClose();
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_ANN);
            MarkNpcSpokenTo(CHARACTER_DOUG);
            SetEntityEventScript(ENTITY_ANN, EventScript_LoveEvent_Ann_01_BlackHeart_ReceiveWelcomeMeal_FollowupAnnDialogue);
            SetEntityEventScript(ENTITY_DOUG, EventScript_LoveEvent_Ann_01_BlackHeart_ReceiveWelcomeMeal_FollowupDougDialogue);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_ANN, mary_negated_int(-2000));
            AddNpcFriendship(CHARACTER_DOUG, mary_negated_int(-10));
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_AnnDeniesEmbarrassment);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_DougTeasesAnn);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_01_BlackHeart_AnnSaysGoodbye);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            VarSet(VAR_ANN_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            ChangeMap(MAP_NORTH_SIDE_TOWN, X(632), Y(496));
            SetEntityPosition(ENTITY_PLAYER, X(632), Y(496), FACING_DOWN);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            MarkNpcSpokenTo(CHARACTER_ANN);
            MarkNpcSpokenTo(CHARACTER_DOUG);
            PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            break;
    }
}
