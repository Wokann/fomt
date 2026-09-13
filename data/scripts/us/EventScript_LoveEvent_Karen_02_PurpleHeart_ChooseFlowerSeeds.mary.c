#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_02_PurpleHeart_Jeff_TriesToStopArgument[] =
        "Now now...Both of you\r\n"
        "calm down.{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Sasha_SilencesJeff[] =
        "You be quiet!{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_SilencesSasha[] =
        "You shut up too!{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Jeff_ObjectsToHarshTone[] =
        "You don't have to be \r\n"
        "so rude.{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Jeff_FeignsStomachPain[] =
        "Ohh...My stomach is\r\n"
        "starting to hurt...!{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_GreetsPlayer[] =
        "Oh, hello, \r\n"
        "{Player}. {Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_ExplainsSeedDispute[] =
        "Just listen to this.\r\n"
        "My cousin is sick and\r\n"
        "staying in the Hospital.{Press}\r\n"
        "We decided to send her some\r\n"
        "Seeds as a get-well\r\n"
        "present. {Press}\p"
        "I wanted to send her Moon\r\n"
        "Drop Seeds, but Mom\r\n"
        "wants to send her{Press}\r\n"
        "Pink Cat Seeds! {Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Jeff_EmbarrassedByArgument[] =
        "I can't believe we're \r\n"
        "fighting about something \r\n"
        "like this!{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_AsksPlayerToChooseSeeds[] =
        "Right! So, let's ask \r\n"
        "{Player} to \r\n"
        "decide for us, OK?{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Sasha_AgreesToPlayerDecision[] =
        "OK. If that will settle\r\n"
        "it once and for all.{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_AgreesToPlayerDecision[] =
        "Alright, it's a deal!{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_PresentsSeedChoice[] =
        "It's all up to you, \r\n"
        "{Player}. \r\n"
        "Which do you vote for?{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_ChoiceMoonDropSeeds[] =
        "Moon Drop Seeds";

    const char gText_LoveEvent_Karen_02_PurpleHeart_ChoicePinkCatSeeds[] =
        "Pink Cat Seeds";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_PraisesMoonDropChoice[] =
        "I knew you had a good\r\n"
        "taste, {Player}!{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Sasha_ConcedesPinkCatChoice[] =
        "Alright. I give up. \r\n"
        "Let's send the Seeds\r\n"
        "Karen wanted to. {Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_ThanksPlayer[] =
        "Ha! \r\n"
        "Thanks, {Player}!{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_HesitatesOverChoice[] =
        "Hmm...{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Sasha_InvokesPlayerOpinion[] =
        "{Player} thinks \r\n"
        "so too, so you might as \r\n"
        "well give up! {Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_Relents[] =
        "Fine!...{Press}";
};

void EventScript_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds(void)
{
    int var_0;
    ChangeMap(MAP_SUPERMARKET, X(184), Y(111));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(184), Y(258), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_KAREN, X(167), Y(111), FACING_LEFT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(136), Y(111), FACING_RIGHT);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_JEFF, X(151), Y(95), FACING_DOWN);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_Jeff_TriesToStopArgument);
    TalkClose();
    SetEntityFacing(ENTITY_SASHA, FACING_UP);
    SetEntityFacing(ENTITY_KAREN, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_Sasha_SilencesJeff);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_Karen_SilencesSasha);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_Jeff_ObjectsToHarshTone);
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HURT);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_Jeff_FeignsStomachPain);
    TalkClose();
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
    WaitFrames(30);
    StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_Karen_GreetsPlayer);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_PLAYER, Y(111), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_Karen_ExplainsSeedDispute);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_Jeff_EmbarrassedByArgument);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_Karen_AsksPlayerToChooseSeeds);
    TalkClose();
    SetEntityFacing(ENTITY_KAREN, FACING_LEFT);
    WaitFrames(60);
    SetEntityFacing(ENTITY_SASHA, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_Sasha_AgreesToPlayerDecision);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_Karen_AgreesToPlayerDecision);
    TalkClose();
    SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_Karen_PresentsSeedChoice);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Karen_02_PurpleHeart_ChoiceMoonDropSeeds, gText_LoveEvent_Karen_02_PurpleHeart_ChoicePinkCatSeeds);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_KAREN, 3000);
            AddNpcFriendship(CHARACTER_SASHA, mary_negated_int(-10));
            AddNpcFriendship(CHARACTER_JEFF, 20);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_Karen_PraisesMoonDropChoice);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_SASHA);
            TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_Sasha_ConcedesPinkCatChoice);
            TalkClose();
            StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_HAPPY, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_Karen_ThanksPlayer);
            TalkClose();
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_KAREN);
            MarkNpcSpokenTo(CHARACTER_JEFF);
            MarkNpcSpokenTo(CHARACTER_SASHA);
            SetEntityEventScript(ENTITY_KAREN, EventScript_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupKarenDialogue);
            SetEntityEventScript(ENTITY_SASHA, EventScript_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupSashaDialogue);
            SetEntityEventScript(ENTITY_JEFF, EventScript_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupJeffDialogue);
            VarSet(VAR_KAREN_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            VarSet(VAR_KAREN_PURPLE_HEART_EVENT_CHOICE, KAREN_PURPLE_HEART_RESPONSE_MOONDROP_SEEDS);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_KAREN, mary_negated_int(-2000));
            AddNpcFriendship(CHARACTER_SASHA, 20);
            AddNpcFriendship(CHARACTER_JEFF, 20);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_Karen_HesitatesOverChoice);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_SASHA);
            TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_Sasha_InvokesPlayerOpinion);
            TalkClose();
            StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_THINKING, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_02_PurpleHeart_Karen_Relents);
            TalkClose();
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_KAREN);
            MarkNpcSpokenTo(CHARACTER_JEFF);
            MarkNpcSpokenTo(CHARACTER_SASHA);
            SetEntityEventScript(ENTITY_KAREN, EventScript_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupKarenDialogue);
            SetEntityEventScript(ENTITY_SASHA, EventScript_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupSashaDialogue);
            SetEntityEventScript(ENTITY_JEFF, EventScript_LoveEvent_Karen_02_PurpleHeart_ChooseFlowerSeeds_FollowupJeffDialogue);
            VarSet(VAR_KAREN_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            VarSet(VAR_KAREN_PURPLE_HEART_EVENT_CHOICE, KAREN_PURPLE_HEART_RESPONSE_PINK_CAT_SEEDS);
            break;
    }
}
