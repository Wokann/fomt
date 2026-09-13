#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_03_BlueHeart_Duke_ExplainsFamilyWineReady[] =
        "...So, we thought it\r\n"
        "was a good idea.{Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Karen_ExpressesSurprise[] =
        "Really? {Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Karen_CelebratesWineReady[] =
        "That's great!! {Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Karen_ThanksParents[] =
        "Mom..Dad...Thanks!{Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Sasha_ReflectsOnPassingYears[] =
        "The years have passed \r\n"
        "just like that...{Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Jeff_HappyForKaren[] =
        "I'm just glad you're so \r\n"
        "happy about it, Karen. {Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Karen_GreetsPlayer[] =
        "Oh, hey, {Player}.{Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Karen_ExplainsRetrievalRequest[] =
        "Listen to this! My dad \r\n"
        "asked Doug to make some \r\n"
        "Wine for me when I was{Press}\r\n"
        "born! Isn't that great?!{Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Duke_PraisesJeffIdea[] =
        "Jeff does have good ideas\r\n"
        "doesn't he?{Press}\p"
        "It's just about mature by \r\n"
        "now, so we dropped by to \r\n"
        "tell you about it. {Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Jeff_AsksPlayerToAccompanyKaren[] =
        "{Player}, \r\n"
        "why don't you go with Karen\r\n"
        "to pick it up? {Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_ChoiceAccompanyKaren[] =
        "I'd be glad to.";

    const char gText_LoveEvent_Karen_03_BlueHeart_ChoiceDeclineTrip[] =
        "Sorry, I'm busy.";

    const char gText_LoveEvent_Karen_03_BlueHeart_Duke_ThanksPlayer[] =
        "We're much obliged!{Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Karen_DepartsForWinery[] =
        "Let's go, then.{Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Duke_PresentsFamilyWine[] =
        "Here it is. {Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Karen_ThanksDukeForWine[] =
        "Thanks, Uncle Duke!\r\n"
        "Look, it even says \"Karen\"\r\n"
        "on the label! I can't wait{Press}\r\n"
        "to drink it!{Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Duke_MarksKarensComingOfAge[] =
        "Now that you're a woman, \r\n"
        "it was yours!{Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Karen_PreparesToReturnHome[] =
        "Let's go home now.{Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Duke_AsksAboutRemainingWine[] =
        "Wait a second...\r\n"
        "What about the wine?{Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Karen_SaysTheyWillTakeWineHome[] =
        "We're going to bring\r\n"
        "it home now...{Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Duke_ClarifiesEntireCollection[] =
        "It's not just that \r\n"
        "one bottle, you know!{Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Karen_AsksIfAllBottles[] =
        "Well, will you bring it \r\n"
        "all here for me?{Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Duke_RejectsTakingAllWine[] =
        "Hah! You must be joking.{Press}\p"
        "Jeff was so happy when you\r\n"
        "were born that he asked me \r\n"
        "to make 3 whole cases!{Press}\p"
        "It's down below, but I'm\r\n"
        "not going to get it myself!{Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Karen_ComplainsAboutFathersRequest[] =
        "I can't believe Dad \r\n"
        "made so much!!\r\n"
        "Will you help me carry{Press}\r\n"
        "it all? {Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Karen_ReturnsExhaustedAndThanksPlayer[] =
        "Uggh...I'm so tired...!!\r\n"
        "Thanks a load for helping.{Press}\p"
        "I'm grateful to Dad for\r\n"
        "the thought, {Press}\r\n"
        "but he really didn't need\r\n"
        "to make so much! {Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Karen_HappyParentsReconciled[] =
        "It does make me glad \r\n"
        "to have such a kind father.{Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Karen_AsksPlayerToWait[] =
        "Oh, yeah. \r\n"
        "Wait here one second. {Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Karen_GivesReward[] =
        "This is a thank-you\r\n"
        "for helping me out today.{Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Karen_ThanksPlayerSincerely[] =
        "Thanks a lot.\r\n"
        "I mean it. {Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Jeff_RespondsToDecline[] =
        "Well, that's too bad.{Press}\r\n"
        "We'll have to go pick it up\r\n"
        "later ourselves, Karen. {Press}";

    const char gText_LoveEvent_Karen_03_BlueHeart_Karen_AcknowledgesDecline[] =
        "OK...{Press}";
};

void EventScript_LoveEvent_Karen_03_BlueHeart_RetrieveFamilyWine(void)
{
    int var_0;
    ChangeMap(MAP_SUPERMARKET, X(144), Y(255));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(144), Y(279), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_KAREN, X(144), Y(240), FACING_RIGHT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(111), Y(255), FACING_RIGHT);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_JEFF, X(111), Y(220), FACING_RIGHT);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    SetEntityPosition(ENTITY_DUKE, X(184), Y(240), FACING_LEFT);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_KAREN_BLUE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Duke_ExplainsFamilyWineReady);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Karen_ExpressesSurprise);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Karen_CelebratesWineReady);
    TalkClose();
    StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_KAREN, FACING_LEFT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Karen_ThanksParents);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Sasha_ReflectsOnPassingYears);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Jeff_HappyForKaren);
    TalkClose();
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Karen_GreetsPlayer);
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Karen_ExplainsRetrievalRequest);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Duke_PraisesJeffIdea);
    TalkClose();
    StartEntityEffect(ENTITY_JEFF, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_JEFF, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Jeff_AsksPlayerToAccompanyKaren);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Karen_03_BlueHeart_ChoiceAccompanyKaren, gText_LoveEvent_Karen_03_BlueHeart_ChoiceDeclineTrip);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_KAREN, 3000);
            AddNpcFriendship(CHARACTER_SASHA, 20);
            AddNpcFriendship(CHARACTER_JEFF, 20);
            AddNpcFriendship(CHARACTER_DUKE, 20);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Duke_ThanksPlayer);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Karen_DepartsForWinery);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_AJA_WINERY_STORAGE_1F, X(136), Y(164));
            PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
            SetEntityPosition(ENTITY_PLAYER, X(103), Y(167), FACING_UP);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityPosition(ENTITY_KAREN, X(120), Y(167), FACING_UP);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            SetEntityPosition(ENTITY_DUKE, X(120), Y(95), FACING_UP);
            SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            SetEntityFacing(ENTITY_DUKE, FACING_RIGHT);
            SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_WALK);
            MoveEntityXTo(ENTITY_DUKE, X(151), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_DUKE);
            SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
            SetEntityFacing(ENTITY_DUKE, FACING_DOWN);
            SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_WALK);
            MoveEntityYTo(ENTITY_DUKE, Y(143), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_DUKE);
            SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
            SetEntityFacing(ENTITY_DUKE, FACING_LEFT);
            SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_WALK);
            MoveEntityXTo(ENTITY_DUKE, X(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_DUKE);
            SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
            SetEntityFacing(ENTITY_DUKE, FACING_DOWN);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Duke_PresentsFamilyWine);
            TalkClose();
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_GESTURE);
            WaitFrames(60);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_HAPPY, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Karen_ThanksDukeForWine);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Duke_MarksKarensComingOfAge);
            TalkClose();
            SetEntityFacing(ENTITY_KAREN, FACING_LEFT);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Karen_PreparesToReturnHome);
            TalkClose();
            SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            StartEntityEffect(ENTITY_DUKE, ENTITY_EMOTE_EXCLAMATION, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Duke_AsksAboutRemainingWine);
            TalkClose();
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            SetEntityFacing(ENTITY_KAREN, FACING_UP);
            StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_QUESTION, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Karen_SaysTheyWillTakeWineHome);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Duke_ClarifiesEntireCollection);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Karen_AsksIfAllBottles);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Duke_RejectsTakingAllWine);
            TalkClose();
            StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_THINKING, FALSE);
            StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
            WaitFrames(60);
            SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
            SetEntityFacing(ENTITY_KAREN, FACING_LEFT);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Karen_ComplainsAboutFathersRequest);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_SUPERMARKET_BACK_ROOM, X(198), Y(252));
            PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
            SetEntityPosition(ENTITY_PLAYER, X(160), Y(240), FACING_RIGHT);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityPosition(ENTITY_KAREN, X(184), Y(240), FACING_LEFT);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_AFRAID, FALSE);
            StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_AFRAID, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Karen_ReturnsExhaustedAndThanksPlayer);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Karen_HappyParentsReconciled);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_EXCLAMATION, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Karen_AsksPlayerToWait);
            TalkClose();
            SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
            MoveEntityXTo(ENTITY_KAREN, X(200), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_KAREN);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            SetEntityFacing(ENTITY_KAREN, FACING_UP);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
            MoveEntityYTo(ENTITY_KAREN, Y(160), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_KAREN);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            WaitFrames(60);
            StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
            WaitFrames(60);
            SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
            MoveEntityYTo(ENTITY_KAREN, Y(240), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_KAREN);
            SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            SetEntityFacing(ENTITY_KAREN, FACING_LEFT);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
            MoveEntityXTo(ENTITY_KAREN, X(184), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_KAREN);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Karen_GivesReward);
            TalkClose();
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_GESTURE);
            WaitFrames(60);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
            PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
            SetPlayerHeldArticle(ITEM_ARTICLE_KARENS_WINE);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Karen_ThanksPlayerSincerely);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_KAREN);
            MarkNpcSpokenTo(CHARACTER_JEFF);
            MarkNpcSpokenTo(CHARACTER_SASHA);
            MarkNpcSpokenTo(CHARACTER_DUKE);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            VarSet(VAR_KAREN_BLUE_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            ChangeMap(MAP_NORTH_SIDE_TOWN, X(688), Y(168));
            SetEntityPosition(ENTITY_PLAYER, X(688), Y(168), FACING_DOWN);
            PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
            AddNpcFriendship(CHARACTER_SASHA, mary_negated_int(-10));
            AddNpcFriendship(CHARACTER_JEFF, mary_negated_int(-10));
            AddNpcFriendship(CHARACTER_DUKE, mary_negated_int(-10));
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_JEFF);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Jeff_RespondsToDecline);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_03_BlueHeart_Karen_AcknowledgesDecline);
            TalkClose();
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_KAREN);
            MarkNpcSpokenTo(CHARACTER_JEFF);
            MarkNpcSpokenTo(CHARACTER_SASHA);
            MarkNpcSpokenTo(CHARACTER_DUKE);
            SetEntityEventScript(ENTITY_KAREN, EventScript_LoveEvent_Karen_03_BlueHeart_RetrieveFamilyWine_FollowupKarenDialogue);
            SetEntityEventScript(ENTITY_SASHA, EventScript_LoveEvent_Karen_03_BlueHeart_RetrieveFamilyWine_FollowupSashaDialogue);
            SetEntityEventScript(ENTITY_JEFF, EventScript_LoveEvent_Karen_03_BlueHeart_RetrieveFamilyWine_FollowupJeffDialogue);
            SetEntityEventScript(ENTITY_DUKE, EventScript_LoveEvent_Karen_03_BlueHeart_RetrieveFamilyWine_FollowupDukeDialogue);
            VarSet(VAR_KAREN_BLUE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
    }
}
