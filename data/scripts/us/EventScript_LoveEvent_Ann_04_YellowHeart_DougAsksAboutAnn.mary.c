#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Ann_04_YellowHeart_DougWelcomesPlayer[] =
        "Welcome, {Player}. {Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougIntroducesPrivateQuestion[] =
        "I'm glad you came. \r\n"
        "I have something I wanted \r\n"
        "to ask you. {Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougExplainsConcernForAnn[] =
        "It's about Ann. \r\n"
        "You see...Her mom died \r\n"
        "a long time ago, and I've{Press}\r\n"
        "had to raise her by myself.{Press}\p"
        "It's only worked out so\r\n"
        "well because she's such a \r\n"
        "great girl. {Press}\r\n"
        "I'm really grateful to her.{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougWantsAnnToBeHappy[] =
        "That is why I want her \r\n"
        "to find a good husband.\r\n"
        "I want her to be happy. {Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougCreditsPlayerForAnnsChange[] =
        "Until she met you, \r\n"
        "she never talked about \r\n"
        "boys at all. {Press}\r\n"
        "Now she talks about you\r\n"
        "all the time, though. {Press}\p"
        "So..what do you think \r\n"
        "about Ann? {Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_ChoiceAdmitLikingAnn[] =
        "I like her.";

    const char gText_LoveEvent_Ann_04_YellowHeart_ChoiceSayAnnIsOnlyFriend[] =
        "Only as a friend.";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougCelebratesPlayersFeelings[] =
        "Really! That's great!!\r\n"
        "I was so nervous...{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_AnnWelcomesPlayer[] =
        "Oh, {Player}. \r\n"
        "Welcome. {Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougCallsAnnOver[] =
        "Ann, come over here next to\r\n"
        "{Player}. {Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_AnnAsksWhatIsWrong[] =
        "Why? Is something the \r\n"
        "matter?{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougInsistsAnnComeCloser[] =
        "Just get over here!...{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougAsksAnnsFeelingsForPlayer[] =
        "Cough...\r\n"
        "Ann...What do you think \r\n"
        "of {Player}?{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_AnnReactsInSurprise[] =
        "What...?{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_AnnRefusesToAnswerDoug[] =
        "That's none of \r\n"
        "your business, Dad!{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougClaimsParentalInterest[] =
        "Of course it's my business!\r\n"
        "You're my daughter!{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_AnnFallsSilentInEmbarrassment[] =
        ".......!{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougTeasesAnnAboutPlayer[] =
        "Ha ha ha...!\r\n"
        "It's not often Ann gets\r\n"
        "embarrassed!{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougNoticesPlayerBlushing[] =
        "Why are you getting red, \r\n"
        "too? Well, you two should\r\n"
        "talk about this. {Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougDismissesUnfavorableAnswer[] =
        "That's too bad...\r\n"
        "Be a good friend to her, \r\n"
        "then. {Press}";
};

void EventScript_LoveEvent_Ann_04_YellowHeart_DougAsksAboutAnn(void)
{
    int var_0;
    ChangeMap(MAP_INN_1F, X(248), Y(116));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(315), Y(248), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_ANN, X(112), Y(116), FACING_RIGHT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(315), Y(80), FACING_DOWN);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StartEntityEffect(ENTITY_DOUG, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougWelcomesPlayer);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_PLAYER, Y(116), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougIntroducesPrivateQuestion);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougExplainsConcernForAnn);
    SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougWantsAnnToBeHappy);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougCreditsPlayerForAnnsChange);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Ann_04_YellowHeart_ChoiceAdmitLikingAnn, gText_LoveEvent_Ann_04_YellowHeart_ChoiceSayAnnIsOnlyFriend);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_ANN, 3000);
            AddNpcFriendship(CHARACTER_DOUG, 20);
            TalkClose();
            StartEntityEffect(ENTITY_DOUG, ENTITY_EMOTE_HAPPY, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougCelebratesPlayersFeelings);
            TalkClose();
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
            MoveEntityXTo(ENTITY_ANN, X(232), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ANN);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            ShowTalkHeartIndicator(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_AnnWelcomesPlayer);
            TalkClose();
            SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
            WaitFrames(30);
            SetEntityFacing(ENTITY_DOUG, FACING_LEFT);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougCallsAnnOver);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_AnnAsksWhatIsWrong);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougInsistsAnnComeCloser);
            TalkClose();
            StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_QUESTION, FALSE);
            WaitFrames(60);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
            MoveEntityXTo(ENTITY_ANN, X(300), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ANN);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
            SetEntityFacing(ENTITY_DOUG, FACING_DOWN);
            WaitFrames(30);
            SetEntityFacing(ENTITY_ANN, FACING_UP);
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougAsksAnnsFeelingsForPlayer);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_AnnReactsInSurprise);
            SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_AnnRefusesToAnswerDoug);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougClaimsParentalInterest);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANN_BLUSHING);
            SetTalkNameplateCharacter(CHARACTER_ANN);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_AnnFallsSilentInEmbarrassment);
            TalkClose();
            StartEntityEffect(ENTITY_ANN, ENTITY_EMOTE_ANGRY, FALSE);
            WaitFrames(60);
            SetEntityFacing(ENTITY_ANN, FACING_LEFT);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WALK);
            MoveEntityXTo(ENTITY_ANN, X(112), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
            SetEntityFacing(ENTITY_DOUG, FACING_LEFT);
            SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
            WaitForEntityMovement(ENTITY_ANN);
            SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
            HideEntity(ENTITY_ANN);
            WaitFrames(60);
            SetEntityFacing(ENTITY_DOUG, FACING_DOWN);
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougTeasesAnnAboutPlayer);
            SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougNoticesPlayerBlushing);
            TalkClose();
            StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
            WaitFrames(60);
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_ANN);
            MarkNpcSpokenTo(CHARACTER_DOUG);
            SetEntityEventScript(ENTITY_DOUG, EventScript_LoveEvent_Ann_04_YellowHeart_DougAsksAboutAnn_FollowupDougDialogue);
            VarSet(VAR_ANN_YELLOW_HEART_EVENT_CHOICE, ANN_YELLOW_HEART_RESPONSE_LIKE_ANN);
            VarSet(VAR_ANN_YELLOW_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
        case CHOICE_OPTION_2:
            AddNpcFriendship(CHARACTER_DOUG, mary_negated_int(-10));
            HideEntity(ENTITY_ANN);
            TalkClose();
            StartEntityEffect(ENTITY_DOUG, ENTITY_EMOTE_THINKING, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOUG);
            TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_DougDismissesUnfavorableAnswer);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_DOUG);
            SetEntityEventScript(ENTITY_DOUG, EventScript_LoveEvent_Ann_04_YellowHeart_DougAsksAboutAnn_FollowupDougDialogue);
            VarSet(VAR_ANN_YELLOW_HEART_EVENT_CHOICE, ANN_YELLOW_HEART_RESPONSE_ONLY_FRIENDS);
            VarSet(VAR_ANN_YELLOW_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
    }
}
