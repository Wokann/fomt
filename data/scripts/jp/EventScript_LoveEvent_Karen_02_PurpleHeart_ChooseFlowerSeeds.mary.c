#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_02_PurpleHeart_Jeff_TriesToStopArgument[] =
        "まぁまぁ、\r\n"
        "二人とも落ち着いて…{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Sasha_SilencesJeff[] =
        "あなたはだまってなさいよ…{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_SilencesSasha[] =
        "父さんはだまってて！{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Jeff_ObjectsToHarshTone[] =
        "そんな風に言わなくても\r\n"
        "いいじゃないか…{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Jeff_FeignsStomachPain[] =
        "イタタタタ…\r\n"
        "胃が痛くなってきたよ…{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_GreetsPlayer[] =
        "あっ、{Player}くん。{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_ExplainsSeedDispute[] =
        "ちょっと聞いてよ。\r\n"
        "わたしのしんせきの子供が\r\n"
        "入院したから、{Press}\r\n"
        "元気になるようにって\r\n"
        "花の種をおくろうってことに\r\n"
        "なったのよ。{Press}\p"
        "そこまではよかったんだけど、\r\n"
        "わたしはムーンドロップ草の\r\n"
        "種が一番いいって言ってるのに{Press}\r\n"
        "母さんがピンクキャット草の\r\n"
        "方がいいっていうのよ。{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Jeff_EmbarrassedByArgument[] =
        "だからって、\r\n"
        "ケンカしてどうするんだよ…\r\n"
        "どっちでもいいじゃないか…{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_AsksPlayerToChooseSeeds[] =
        "そうだ！どっちがいいか\r\n"
        "{Player}くんに聞いて\r\n"
        "みて、どっちかにしようよ。{Press}\p"
        "母さんもそれでいいよね？{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Sasha_AgreesToPlayerDecision[] =
        "ああ、いいよ。\r\n"
        "それでうらみっこなしって\r\n"
        "ことにしようじゃない。{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_AgreesToPlayerDecision[] =
        "じゃ、それで決まり！{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_PresentsSeedChoice[] =
        "じゃあ、{Player}くん。\r\n"
        "そういうことなんで、\r\n"
        "どっちの種がいいと思う？{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_ChoiceMoonDropSeeds[] =
        "ムーンドロップ草の種";

    const char gText_LoveEvent_Karen_02_PurpleHeart_ChoicePinkCatSeeds[] =
        "ピンクキャット草の種";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_PraisesMoonDropChoice[] =
        "あっ、やっぱり！\r\n"
        "{Player}くんも\r\n"
        "そう思うよねぇ？{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Sasha_ConcedesPinkCatChoice[] =
        "わかったよ。\r\n"
        "じゃあ、カレンが選んだ種を\r\n"
        "送ろっか。{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_ThanksPlayer[] =
        "やったー！\r\n"
        "ありがとう。{Player}\r\n"
        "くん！！{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_HesitatesOverChoice[] =
        "え～～～、{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Sasha_InvokesPlayerOpinion[] =
        "{Player}くんも、\r\n"
        "こう言ってるんだし、\r\n"
        "あきらめな。{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_Relents[] =
        "わかったわよ…{Press}";
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
