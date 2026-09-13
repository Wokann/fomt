#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Ann_01_BlackHeart_AnnWelcomesPlayer[] =
        "Willkommen. {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnAsksIfPlayerIsNew[] =
        "Ich denke nicht, dass ich\r\n"
        "dich schon mal gesehen habe.\r\n"
        "Du bist, {Player}?{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnRecognizesNewFarmer[] =
        "Ich wusste es! Der\r\n"
        "Bürgermeister hat \r\n"
        "von dir erzählt. Schön,{Press}\p"
        "dich kennen zu lernen.\r\n"
        "Ich heiße Ann und das\r\n"
        "ist mein Vater. {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougIntroducesHimself[] =
        "Hi. Ich bin Doug. {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnAsksWhyPlayerVisited[] =
        "Hey, {Player}!\r\n"
        "Willst du etwas essen?{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnAsksPlayerToWait[] =
        "Warte einen Moment. {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnOffersWelcomeMeal[] =
        "Weil du neu hier bist, \r\n"
        "denke ich, dass das hier \r\n"
        "aufs Haus geht! {Press}\p"
        "Was meinst du, Papa?{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougAgreesToCook[] =
        "Sicher. Komm \r\n"
        "einfach öfter zu uns!{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnInvitesPlayerToStayForMeal[] =
        "Siehst du? Warum\r\n"
        "bleibst du nicht und isst?{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_ChoiceAcceptMeal[] =
        "Hört sich gut an!";

    const char gText_LoveEvent_Ann_01_BlackHeart_ChoiceDeclineMeal[] =
        "Ich kann wirklich nicht.";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnCelebratesAcceptance[] =
        "Super! Mach dein\r\n"
        "Spezialgericht, Papa!{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougPromisesSpecialMeal[] =
        "Überlass das mir!\r\n"
        "Das wird das Beste, was\r\n"
        "du je gegessen hast!{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnPraisesDougsCooking[] =
        "Papa ist ein guter \r\n"
        "Koch.{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougServesMeal[] =
        "Bitte sehr.\r\n"
        "Iss, es wird kalt!{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnPassesMealToPlayer[] =
        "Bitte sehr, \r\n"
        "{Player}!{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougAsksHowMealTastes[] =
        "Wie schmeckt es dir?{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnAsksIfPlayerLikesMeal[] =
        "Magst du es, \r\n"
        "{Player}?{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougInvitesPlayerToReturn[] =
        "Nimm dir ruhig noch\r\n"
        "nach! {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnPraisesDoug[] =
        "Du bist der Beste, Papa!{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougConfidentInCooking[] =
        "Natürlich! Hast du\r\n"
        "daran gezweifelt?{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnEncouragesPlayerToEat[] =
        "Iss, so viel du willst. {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougSaysFarmWorkNeedsFood[] =
        "Wer arbeitet, muss  \r\n"
        "auch viel essen. {Press}\p"
        "Ich sehe gerne, wie du\r\n"
        "ordentlich zuschlägst! {Press}\p"
        "Ich habe entschieden,\r\n"
        "dass ich dich mag, \r\n"
        "{Player}!{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnWaivesPayment[] =
        "Du musst nicht bezahlen.\r\n"
        "Komm nur jederzeit wieder!{Press}\p"
        "Ich arbeite immer hier. {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougInvitesReturnVisit[] =
        "Ja, komm jederzeit \r\n"
        "und besuche Ann.\r\n"
        "Sie wird sich freuen. {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnEmbarrassedByDoug[] =
        "Papa! \r\n"
        "Hör auf damit...{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnDeniesEmbarrassment[] =
        "Was? Du muss nicht \r\n"
        "so schüchtern sein!{Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_DougTeasesAnn[] =
        "Genau! {Press}";

    const char gText_LoveEvent_Ann_01_BlackHeart_AnnSaysGoodbye[] =
        "Komm bald wieder!{Press}";
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
