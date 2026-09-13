#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_DontYouKnowHowToBehave[] =
        "Weißt du nicht, wie man \r\n"
        "sich benimmt, junger Mann?{Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_IfYourPurposeWasToInsult[] =
        "Falls du uns alle \r\n"
        "beleidigen wolltest - das\r\n"
        "hast du erreicht!{Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_DoYouKnowWhyImMad[] =
        "Weißt du, warum\r\n"
        "ich sauer bin?\r\n"
        "Das solltest du!{Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_IDontLikeYouAnyMore[] =
        "Ich mag dich nicht mehr!\r\n"
        "\r\n"
        "{Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_YoungPeopleTheseDaysAreJust[] =
        "Die jungen Leute heut- \r\n"
        "zutage, unmöglich! {Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_HowCanYouDoSomethingLike[] =
        "Wie kannst du so etwas\r\n"
        "mit allen machen!?{Press}\p"
        "Wie kannst du uns so \r\n"
        "beleidigen?!{Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_NowThisIsQuiteAMistake[] =
        "Jetzt machst du einen \r\n"
        "ziemlichen Fehler. \r\n"
        "Wir machen alle Fehler \r\n"
        "in unserer Jugend, aber\r\n"
        "das hier ist \r\n"
        "unentschuldbar!\r\n"
        "Wann wirst du erwachsen?{Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_YouHaveNoExcuseItsAn[] =
        "Du hast keine \r\n"
        "Entschuldigung! \r\n"
        "Eine Beleidigung der Natur!{Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_IDontEvenKnowWhatTo[] =
        "Ich weiß nicht einmal, was\r\n"
        "ich zu dir sagen soll...{Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_OfCourseEveryoneIsMadAt[] =
        "Natürlich sind alle \r\n"
        "sauer auf dich! {Press}\r\n"
        "Es ist wegen des \r\n"
        "Goldenen Nutzholzes! {Press}\p"
        "Wenn du uns respektierst,\r\n"
        "nimm es jetzt runter!!{Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_EveryoneInMineralTownIsMad[] =
        "Alle in Mineralstadt  \r\n"
        "sind böse auf dich!{Press}\p"
        "Wenn du keinen Frieden\r\n"
        "schaffst, muss ich dich \r\n"
        "festnehmen!{Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_ILikeToPlayJokesOn[] =
        "Ich spiele Leuten auch gerne\r\n"
        "einen Streich, aber das hier\r\n"
        "ist was anderes! {Press}\r\n"
        "Wie kannst du so fies sein!?{Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_ItTakesALotToMake[] =
        "Ich werde nicht schnell \r\n"
        "sauer, aber du hast es \r\n"
        "diesmal geschafft...!{Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_HowCanYouBeSoThoughtless[] =
        "Wie kannst du so\r\n"
        "gedankenlos sein! Und ich\r\n"
        "habe dich auch gemocht!{Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_TheGodsWillSurelyPunishYou[] =
        "Die Götter werden dich\r\n"
        "bestrafen, wenn du dich\r\n"
        "weiter so benimmst!{Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_AreYouTooDenseToFigure[] =
        "Bist du zu dumm, um zu \r\n"
        "verstehen, was die Leute\r\n"
        "so sauer macht!?...{Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_ArentYouEmbarrassedOfYourselfYou[] =
        "Schämst du dich \r\n"
        "nicht selber für dich?\r\n"
        "Das solltest du!{Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_IveEvenHeardAboutYouIn[] =
        "Sogar in meiner Stadt \r\n"
        "habe ich von dir gehört !{Press}\p"
        "Du solltest dich wirklich\r\n"
        "schämen!{Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_YouHaveManagedToArouseEven[] =
        "Du hast es geschafft, sogar\r\n"
        "mich wütend zu machen.\r\n"
        "Bessere dich schleunigst!{Press}";

    const char gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_AreYouStillUsingGoldenLumber[] =
        "Benutzt du noch immer\r\n"
        "Goldenes Holz?{Press}\p"
        "Schreckliche Person!\r\n"
        "Eine Beleidigung für\r\n"
        "alle. Entferne es sofort!{Press}";
};

void EventScript_NPCEvent_TownResidents_GoldenLumberAngerConfrontation(void)
{
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    PanCameraTo(X(282), Y(120), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    if (VarGet(VAR_GOLDEN_LUMBER_ANGER_DIALOGUE_VARIANT_STATE) != GOLDEN_LUMBER_ANGER_DIALOGUE_SECOND_SEQUENCE)
    {
        SetEntityPosition(ENTITY_LILLIA, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_WALK);
        StartEntityEffect(ENTITY_LILLIA, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_LILLIA, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_LILLIA);
        SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
        SetEntityFacing(ENTITY_LILLIA, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_LILLIA);
        SetTalkPortrait(TALK_PORTRAIT_LILLIA_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_DontYouKnowHowToBehave);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
        SetEntityFacing(ENTITY_LILLIA, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_WALK);
        MoveEntityYTo(ENTITY_LILLIA, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_LILLIA);
        HideEntity(ENTITY_LILLIA);
        SetEntityPosition(ENTITY_RICK, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WALK);
        StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_RICK, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_RICK);
        SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
        SetEntityFacing(ENTITY_RICK, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_RICK);
        SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_IfYourPurposeWasToInsult);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_AFRAID, FALSE);
        SetEntityFacing(ENTITY_RICK, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WALK);
        MoveEntityYTo(ENTITY_RICK, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_RICK);
        HideEntity(ENTITY_RICK);
        SetEntityPosition(ENTITY_BARLEY, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        StartEntityEffect(ENTITY_BARLEY, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_BARLEY, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
        SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_DoYouKnowWhyImMad);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
        SetEntityFacing(ENTITY_BARLEY, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
        MoveEntityYTo(ENTITY_BARLEY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BARLEY);
        HideEntity(ENTITY_BARLEY);
        SetEntityPosition(ENTITY_MAY, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_WALK);
        StartEntityEffect(ENTITY_MAY, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_MAY, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_MAY);
        SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
        SetEntityFacing(ENTITY_MAY, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_MAY);
        SetTalkPortrait(TALK_PORTRAIT_MAY_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_IDontLikeYouAnyMore);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
        SetEntityFacing(ENTITY_MAY, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_WALK);
        MoveEntityYTo(ENTITY_MAY, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_MAY);
        HideEntity(ENTITY_MAY);
        SetEntityPosition(ENTITY_SAIBARA, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_SAIBARA, ANIMATION_SAIBARA_WALK);
        StartEntityEffect(ENTITY_SAIBARA, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_SAIBARA, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_SAIBARA);
        SetEntityAnim(ENTITY_SAIBARA, ANIMATION_SAIBARA_IDLE);
        SetEntityFacing(ENTITY_SAIBARA, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_SAIBARA);
        SetTalkPortrait(TALK_PORTRAIT_SAIBARA_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_YoungPeopleTheseDaysAreJust);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
        SetEntityFacing(ENTITY_SAIBARA, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_SAIBARA, ANIMATION_SAIBARA_WALK);
        MoveEntityYTo(ENTITY_SAIBARA, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_SAIBARA);
        HideEntity(ENTITY_SAIBARA);
        SetEntityPosition(ENTITY_DUKE, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_WALK);
        StartEntityEffect(ENTITY_DUKE, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_DUKE, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_DUKE);
        SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
        SetEntityFacing(ENTITY_DUKE, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_DUKE);
        SetTalkPortrait(TALK_PORTRAIT_DUKE_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_HowCanYouDoSomethingLike);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
        SetEntityFacing(ENTITY_DUKE, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_WALK);
        MoveEntityYTo(ENTITY_DUKE, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_DUKE);
        HideEntity(ENTITY_DUKE);
        SetEntityPosition(ENTITY_MANNA, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_WALK);
        StartEntityEffect(ENTITY_MANNA, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_MANNA, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_MANNA);
        SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
        SetEntityFacing(ENTITY_MANNA, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_MANNA);
        SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
        TalkMessageSlow(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_NowThisIsQuiteAMistake);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
        SetEntityFacing(ENTITY_MANNA, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_WALK);
        MoveEntityYTo(ENTITY_MANNA, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_MANNA);
        HideEntity(ENTITY_MANNA);
        SetEntityPosition(ENTITY_BASIL, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_WALK);
        StartEntityEffect(ENTITY_BASIL, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_BASIL, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BASIL);
        SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_IDLE);
        SetEntityFacing(ENTITY_BASIL, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_BASIL);
        SetTalkPortrait(TALK_PORTRAIT_BASIL_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_YouHaveNoExcuseItsAn);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
        SetEntityFacing(ENTITY_BASIL, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_WALK);
        MoveEntityYTo(ENTITY_BASIL, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_BASIL);
        HideEntity(ENTITY_BASIL);
        SetEntityPosition(ENTITY_ANNA, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_ANNA, ANIMATION_ANNA_WALK);
        StartEntityEffect(ENTITY_ANNA, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_ANNA, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_ANNA);
        SetEntityAnim(ENTITY_ANNA, ANIMATION_ANNA_IDLE);
        SetEntityFacing(ENTITY_ANNA, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_ANNA);
        SetTalkPortrait(TALK_PORTRAIT_ANNA_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_IDontEvenKnowWhatTo);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
        SetEntityFacing(ENTITY_ANNA, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_ANNA, ANIMATION_ANNA_WALK);
        MoveEntityYTo(ENTITY_ANNA, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_ANNA);
        HideEntity(ENTITY_ANNA);
        SetEntityPosition(ENTITY_THOMAS, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_WALK);
        StartEntityEffect(ENTITY_THOMAS, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_THOMAS, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_THOMAS);
        SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
        SetEntityFacing(ENTITY_THOMAS, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_OfCourseEveryoneIsMadAt);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
        SetEntityFacing(ENTITY_THOMAS, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_WALK);
        MoveEntityYTo(ENTITY_THOMAS, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_THOMAS);
        HideEntity(ENTITY_THOMAS);
        VarSet(VAR_GOLDEN_LUMBER_ANGER_DIALOGUE_VARIANT_STATE, GOLDEN_LUMBER_ANGER_DIALOGUE_SECOND_SEQUENCE);
    }
    else
    {
        SetEntityPosition(ENTITY_HARRIS, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_WALK);
        StartEntityEffect(ENTITY_HARRIS, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_HARRIS, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_HARRIS);
        SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_IDLE);
        SetEntityFacing(ENTITY_HARRIS, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_HARRIS);
        SetTalkPortrait(TALK_PORTRAIT_HARRIS_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_EveryoneInMineralTownIsMad);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
        SetEntityFacing(ENTITY_HARRIS, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_WALK);
        MoveEntityYTo(ENTITY_HARRIS, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_HARRIS);
        HideEntity(ENTITY_HARRIS);
        SetEntityPosition(ENTITY_STU, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
        StartEntityEffect(ENTITY_STU, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_STU, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_STU);
        SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
        SetEntityFacing(ENTITY_STU, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_STU);
        SetTalkPortrait(TALK_PORTRAIT_STU_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_ILikeToPlayJokesOn);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_AFRAID, FALSE);
        SetEntityFacing(ENTITY_STU, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
        MoveEntityYTo(ENTITY_STU, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_STU);
        HideEntity(ENTITY_STU);
        SetEntityPosition(ENTITY_JEFF, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_WALK);
        StartEntityEffect(ENTITY_JEFF, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_JEFF, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_JEFF);
        SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
        SetEntityFacing(ENTITY_JEFF, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_JEFF);
        SetTalkPortrait(TALK_PORTRAIT_JEFF_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_ItTakesALotToMake);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
        SetEntityFacing(ENTITY_JEFF, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_WALK);
        MoveEntityYTo(ENTITY_JEFF, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_JEFF);
        HideEntity(ENTITY_JEFF);
        SetEntityPosition(ENTITY_SASHA, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_WALK);
        StartEntityEffect(ENTITY_SASHA, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_SASHA, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_SASHA);
        SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
        SetEntityFacing(ENTITY_SASHA, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_SASHA);
        SetTalkPortrait(TALK_PORTRAIT_SASHA_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_HowCanYouBeSoThoughtless);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
        SetEntityFacing(ENTITY_SASHA, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_WALK);
        MoveEntityYTo(ENTITY_SASHA, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_SASHA);
        HideEntity(ENTITY_SASHA);
        SetEntityPosition(ENTITY_CARTER, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_WALK);
        StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_CARTER, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_CARTER);
        SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
        SetEntityFacing(ENTITY_CARTER, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_CARTER);
        SetTalkPortrait(TALK_PORTRAIT_CARTER_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_TheGodsWillSurelyPunishYou);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
        SetEntityFacing(ENTITY_CARTER, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_WALK);
        MoveEntityYTo(ENTITY_CARTER, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_CARTER);
        HideEntity(ENTITY_CARTER);
        SetEntityPosition(ENTITY_DOUG, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_WALK);
        StartEntityEffect(ENTITY_DOUG, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_DOUG, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_DOUG);
        SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
        SetEntityFacing(ENTITY_DOUG, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_DOUG);
        SetTalkPortrait(TALK_PORTRAIT_DOUG_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_AreYouTooDenseToFigure);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
        SetEntityFacing(ENTITY_DOUG, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_WALK);
        MoveEntityYTo(ENTITY_DOUG, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_DOUG);
        HideEntity(ENTITY_DOUG);
        SetEntityPosition(ENTITY_ZACK, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_WALK);
        StartEntityEffect(ENTITY_ZACK, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_ZACK, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_ZACK);
        SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
        SetEntityFacing(ENTITY_ZACK, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_ZACK);
        SetTalkPortrait(TALK_PORTRAIT_ZACK_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_ArentYouEmbarrassedOfYourselfYou);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
        SetEntityFacing(ENTITY_ZACK, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_WALK);
        MoveEntityYTo(ENTITY_ZACK, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_ZACK);
        HideEntity(ENTITY_ZACK);
        SetEntityPosition(ENTITY_GOURMET, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_GOURMET, ANIMATION_GOURMET_WALK);
        StartEntityEffect(ENTITY_GOURMET, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_GOURMET, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_GOURMET);
        SetEntityAnim(ENTITY_GOURMET, ANIMATION_GOURMET_IDLE);
        SetEntityFacing(ENTITY_GOURMET, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_GOURMET);
        SetTalkPortrait(TALK_PORTRAIT_GOURMET_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_IveEvenHeardAboutYouIn);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
        SetEntityFacing(ENTITY_GOURMET, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_GOURMET, ANIMATION_GOURMET_WALK);
        MoveEntityYTo(ENTITY_GOURMET, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_GOURMET);
        HideEntity(ENTITY_GOURMET);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
        PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
        SetEntityPosition(ENTITY_HARVEST_GODDESS, X(336), Y(120), FACING_DOWN);
        SetEntityAnim(ENTITY_HARVEST_GODDESS, ANIMATION_HARVEST_GODDESS_LEVITATE);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
        StartEntityEffect(ENTITY_HARVEST_GODDESS, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_HARVEST_GODDESS, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_HARVEST_GODDESS);
        SetEntityAnim(ENTITY_HARVEST_GODDESS, ANIMATION_HARVEST_GODDESS_LEVITATE);
        SetEntityFacing(ENTITY_HARVEST_GODDESS, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_YouHaveManagedToArouseEven);
        TalkClose();
        SetEntityFacing(ENTITY_HARVEST_GODDESS, FACING_DOWN);
        SetEntityAnim(ENTITY_HARVEST_GODDESS, ANIMATION_HARVEST_GODDESS_LEVITATE);
        MoveEntityYTo(ENTITY_HARVEST_GODDESS, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitFrames(10);
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
        HideEntity(ENTITY_HARVEST_GODDESS);
        WaitFrames(30);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
        WaitFrames(60);
        SetEntityPosition(ENTITY_THOMAS, X(336), Y(0), FACING_DOWN);
        SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_WALK);
        StartEntityEffect(ENTITY_THOMAS, ENTITY_EMOTE_ANGRY, TRUE);
        MoveEntityYTo(ENTITY_THOMAS, Y(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_THOMAS);
        SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
        SetEntityFacing(ENTITY_THOMAS, FACING_LEFT);
        SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_ANGRY);
        TalkMessage(gText_NPCEvent_TownResidents_GoldenLumberAngerConfrontation_AreYouStillUsingGoldenLumber);
        TalkClose();
        StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
        SetEntityFacing(ENTITY_THOMAS, FACING_UP);
        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_WALK);
        MoveEntityYTo(ENTITY_THOMAS, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_THOMAS);
        HideEntity(ENTITY_THOMAS);
        VarSet(VAR_GOLDEN_LUMBER_ANGER_DIALOGUE_VARIANT_STATE, GOLDEN_LUMBER_ANGER_DIALOGUE_INACTIVE);
    }
    AddNpcFriendship(CHARACTER_LILLIA, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_RICK, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_POPURI, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_BARLEY, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_MAY, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_SAIBARA, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_GRAY, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_DUKE, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_MANNA, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_BASIL, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_ANNA, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_MARY, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_THOMAS, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_HARRIS, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_ELLEN, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_STU, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_JEFF, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_SASHA, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_KAREN, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_DOCTOR, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_ELLI, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_CARTER, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_CLIFF, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_DOUG, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_ANN, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_KAI, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_GOTZ, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_ZACK, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_WON, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_GOURMET, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_HARVEST_GODDESS, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_VAN, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_LOU_OR_RUBY, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_CHILD, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_STAID, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_NAPPY, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_BOLD, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_CHEF, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_AQUA, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_HOGGY, mary_negated_int(-10));
    AddNpcFriendship(CHARACTER_TIMID, mary_negated_int(-10));
    VarSet(VAR_GOLDEN_LUMBER_ANGER_EVENT_TODAY_STATE, EVENT_LIFECYCLE_COMPLETED);
    PanCameraTo(X(228), Y(120), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    return;
}
