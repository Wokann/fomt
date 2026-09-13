#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_02_PurpleHeart_Jeff_TriesToStopArgument[] =
        "Nun nun... beruhigt\r\n"
        "euch mal.{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Sasha_SilencesJeff[] =
        "Sei du ruhig!{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_SilencesSasha[] =
        "Du auch!{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Jeff_ObjectsToHarshTone[] =
        "Du musst nicht \r\n"
        "so grob sein.{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Jeff_FeignsStomachPain[] =
        "Ohh... Mein Bauch beginnt\r\n"
        "zu schmerzen!...{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_GreetsPlayer[] =
        "Oh, hallo, \r\n"
        "{Player}. {Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_ExplainsSeedDispute[] =
        "Meine Kusine ist\r\n"
        "krank und{Press}\r\n"
        "liegt im Krankenhaus. {Press}\r\n"
        "Wir haben entschieden,\r\n"
        "ihr ein Geschenk zu\r\n"
        "kaufen.{Press}\p"
        "Ich wollte ihr Mondtropfen-\r\n"
        "samen kaufen, aber Sasha \r\n"
        "ist für Pinke Katzen-{Press}\r\n"
        "samen! {Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Jeff_EmbarrassedByArgument[] =
        "Ich kann nicht glauben, \r\n"
        "dass wir uns über so \r\n"
        "etwas streiten!{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_AsksPlayerToChooseSeeds[] =
        "Genau! Also lassen \r\n"
        "wir {Player} für \r\n"
        "uns entscheiden, ok?{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Sasha_AgreesToPlayerDecision[] =
        "OK. Wenn es das\r\n"
        "endlich beendet.{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_AgreesToPlayerDecision[] =
        "Ok, abgemacht!{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_PresentsSeedChoice[] =
        "Es hängt von dir ab, \r\n"
        "{Player}. \r\n"
        "Wofür stimmst du?{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_ChoiceMoonDropSeeds[] =
        "Mondtropfensamen";

    const char gText_LoveEvent_Karen_02_PurpleHeart_ChoicePinkCatSeeds[] =
        "Pinke Katzensamen";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_PraisesMoonDropChoice[] =
        "Ich wusste, du hast Ge-\r\n"
        "schmack, {Player}!{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Sasha_ConcedesPinkCatChoice[] =
        "Ok. Ich gebe auf. \r\n"
        "Schicken wir die\r\n"
        "Samen, die Karen wollte.{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_ThanksPlayer[] =
        "Ha! \r\n"
        "Danke, {Player}!{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_HesitatesOverChoice[] =
        "Hmm...{Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Sasha_InvokesPlayerOpinion[] =
        "{Player} findet \r\n"
        "das auch, also kannst \r\n"
        "du auch aufgeben! {Press}";

    const char gText_LoveEvent_Karen_02_PurpleHeart_Karen_Relents[] =
        "Gut!...{Press}";
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
