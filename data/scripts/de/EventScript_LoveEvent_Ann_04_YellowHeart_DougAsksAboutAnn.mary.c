#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Ann_04_YellowHeart_DougWelcomesPlayer[] =
        "Willkommen, {Player}.{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougIntroducesPrivateQuestion[] =
        "Schön, dass \r\n"
        "du gekommen bist. \r\n"
        "Da ist etwas, was ich {Press}\r\n"
        "dich fragen wollte. {Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougExplainsConcernForAnn[] =
        "Es geht um Ann. \r\n"
        "Siehst du... Ihre Mutter \r\n"
        "ist vor langer Zeit gestor-{Press}\r\n"
        "ben, ich habe sie \r\n"
        "allein aufgezogen.{Press}\p"
        "Es ist nur gut gegangen,\r\n"
        "weil sie so ein gutes \r\n"
        "Mädchen ist. {Press}\r\n"
        "Ich bin ihr dankbar.{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougWantsAnnToBeHappy[] =
        "Darum möchte ich, dass \r\n"
        "sie einen guten Mann findet.\r\n"
        "Ich will, dass sie {Press}\r\n"
        "glücklich ist. {Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougCreditsPlayerForAnnsChange[] =
        "Bevor sie dich getroffen \r\n"
        "hat, hat sie nie über \r\n"
        "Jungen gesprochen. {Press}\r\n"
        "Nun spricht sie die \r\n"
        "ganze Zeit von dir. {Press}\p"
        "Also... was denkst du \r\n"
        "über Ann?{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_ChoiceAdmitLikingAnn[] =
        "Ich mag sie.";

    const char gText_LoveEvent_Ann_04_YellowHeart_ChoiceSayAnnIsOnlyFriend[] =
        "Nur als Freund.";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougCelebratesPlayersFeelings[] =
        "Wirklich! Das ist super!!\r\n"
        "Ich hatte Angst...{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_AnnWelcomesPlayer[] =
        "Oh, {Player}. \r\n"
        "Willkommen. {Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougCallsAnnOver[] =
        "Ann, setz dich hier \r\n"
        "neben {Player}. {Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_AnnAsksWhatIsWrong[] =
        "Warum? Gibt es ein \r\n"
        "Problem?{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougInsistsAnnComeCloser[] =
        "Komm einfach her!...{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougAsksAnnsFeelingsForPlayer[] =
        "Hust...\r\n"
        "Ann...Was denkst du \r\n"
        "über {Player}?{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_AnnReactsInSurprise[] =
        "Was...?{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_AnnRefusesToAnswerDoug[] =
        "Das geht dich\r\n"
        "nichts an, Papa!{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougClaimsParentalInterest[] =
        "Und ob!\r\n"
        "Du bist meine Tochter!{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_AnnFallsSilentInEmbarrassment[] =
        ".......!{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougTeasesAnnAboutPlayer[] =
        "Ha ha ha...!\r\n"
        "Ann wird nicht oft\r\n"
        "verlegen!{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougNoticesPlayerBlushing[] =
        "Warum wirst du denn \r\n"
        "auch rot? Ihr beiden\r\n"
        "solltet euch unterhalten.{Press}";

    const char gText_LoveEvent_Ann_04_YellowHeart_DougDismissesUnfavorableAnswer[] =
        "Zu schade...\r\n"
        "Dann sei ihr ein \r\n"
        "guter Freund. {Press}";
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
