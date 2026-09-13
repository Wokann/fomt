#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_May_PhoneCallWithJoanna_BarleyIntroducesMayOnPhone[] =
        "Ich bin es. Wie geht es dir?\r\n"
        "May wollte mit dir reden,\r\n"
        "ich habe sie mitgebracht.{Press}";

    const char gText_NPCEvent_May_PhoneCallWithJoanna_BarleyHandsPhoneToMay[] =
        "Hier ist sie. {Press}";

    const char gText_NPCEvent_May_PhoneCallWithJoanna_MayGreetsHerMother[] =
        "Mami?\r\n"
        "Ich bin es, May. {Press}";

    const char gText_NPCEvent_May_PhoneCallWithJoanna_MayReassuresJoannaAboutBarley[] =
        "...Ja....Tja...\r\n"
        "Opa, Mama, macht \r\n"
        "euch keine Sorgen. {Press}";

    const char gText_NPCEvent_May_PhoneCallWithJoanna_MayDescribesPlayerAndInvitesJoannaHome[] =
        "Der neue Mann auf der\r\n"
        "Farm ist echt nett...\r\n"
        "und sieht gut aus!{Press}\p"
        "Du solltest selber \r\n"
        "kommen und sehen...{Press}";

    const char gText_NPCEvent_May_PhoneCallWithJoanna_MayLearnsJoannaWillNotReturnAndReturnsPhone[] =
        "...Du kommst jetzt\r\n"
        "nicht nach Hause?{Press}\p"
        "OK...ja...Ich weiß...\r\n"
        "Hier ist Opa...{Press}";

    const char gText_NPCEvent_May_PhoneCallWithJoanna_BarleyAcceptsAnswerAndPromisesWeeklyCall[] =
        "Verstehe...wenn du es sagst.\r\n"
        "...Wir passen auf.{Press}\p"
        "Ich rufe nächste\r\n"
        "Woche wieder an.{Press}";

    const char gText_NPCEvent_May_PhoneCallWithJoanna_DougAsksIfCallerWasJoanna[] =
        "Hast du mit \r\n"
        "Joanna gesprochen?{Press}";

    const char gText_NPCEvent_May_PhoneCallWithJoanna_MaySaysSheEnjoysTalkingToMother[] =
        "Ja, ich liebe es, mit\r\n"
        "meiner Mama zu sprechen!{Press}";

    const char gText_NPCEvent_May_PhoneCallWithJoanna_DougRespondsWithRelief[] =
        "Stimmt das?\r\n"
        "Das ist gut, denke ich. {Press}";

    const char gText_NPCEvent_May_PhoneCallWithJoanna_MayAffirmsHappiness[] =
        "Ist es!{Press}";

    const char gText_NPCEvent_May_PhoneCallWithJoanna_MayRevealsJoannaStillWillNotReturn[] =
        "Aber...sie sagt, sie\r\n"
        "komme immer noch \r\n"
        "nicht zurück...{Press}";

    const char gText_NPCEvent_May_PhoneCallWithJoanna_DougSympathizesWithMay[] =
        "Das ist zu schade.{Press}";

    const char gText_NPCEvent_May_PhoneCallWithJoanna_BarleyApologizesAndPreparesToLeave[] =
        "Sorry, dass ich störe.\r\n"
        "Wir gehen jetzt heim.{Press}";

    const char gText_NPCEvent_May_PhoneCallWithJoanna_MaySaysGoodbyeToDoug[] =
        "Tschüss, Doug.{Press}";

    const char gText_NPCEvent_May_PhoneCallWithJoanna_DougSaysGoodbyeToMay[] =
        "Tschüss, May. {Press}";
};

void EventScript_NPCEvent_May_PhoneCallWithJoanna(void)
{
    ChangeMap(MAP_INN_1F, X(293), Y(132));
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_DOUG, X(315), Y(81), FACING_DOWN);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    SetEntityPosition(ENTITY_BARLEY, X(336), Y(254), FACING_UP);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    SetEntityPosition(ENTITY_MAY, X(336), Y(276), FACING_UP);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_WALK);
    MoveEntityYTo(ENTITY_BARLEY, Y(119), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_MAY, Y(141), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BARLEY);
    WaitForEntityMovement(ENTITY_MAY);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_NPCEvent_May_PhoneCallWithJoanna_BarleyIntroducesMayOnPhone);
    TalkClose();
    StartEntityEffect(ENTITY_BARLEY, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_NPCEvent_May_PhoneCallWithJoanna_BarleyHandsPhoneToMay);
    TalkClose();
    SetEntityFacing(ENTITY_BARLEY, FACING_DOWN);
    WaitFrames(30);
    StartEntityEffect(ENTITY_MAY, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
    MoveEntityXTo(ENTITY_BARLEY, X(312), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BARLEY);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    SetEntityFacing(ENTITY_BARLEY, FACING_RIGHT);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_WALK);
    MoveEntityYTo(ENTITY_MAY, Y(116), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MAY);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MAY);
    TalkMessage(gText_NPCEvent_May_PhoneCallWithJoanna_MayGreetsHerMother);
    SetTalkPortrait(TALK_PORTRAIT_MAY_NORMAL);
    TalkMessage(gText_NPCEvent_May_PhoneCallWithJoanna_MayReassuresJoannaAboutBarley);
    SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
    TalkMessage(gText_NPCEvent_May_PhoneCallWithJoanna_MayDescribesPlayerAndInvitesJoannaHome);
    TalkClose();
    WaitFrames(30);
    StartEntityEffect(ENTITY_MAY, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MAY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MAY);
    TalkMessage(gText_NPCEvent_May_PhoneCallWithJoanna_MayLearnsJoannaWillNotReturnAndReturnsPhone);
    TalkClose();
    SetEntityFacing(ENTITY_MAY, FACING_DOWN);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_WALK);
    MoveEntityYTo(ENTITY_MAY, Y(141), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MAY);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
    SetEntityFacing(ENTITY_MAY, FACING_UP);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
    MoveEntityXTo(ENTITY_BARLEY, X(336), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BARLEY);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    SetEntityFacing(ENTITY_BARLEY, FACING_UP);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_NPCEvent_May_PhoneCallWithJoanna_BarleyAcceptsAnswerAndPromisesWeeklyCall);
    TalkClose();
    SetEntityFacing(ENTITY_BARLEY, FACING_LEFT);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
    MoveEntityXTo(ENTITY_BARLEY, X(312), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BARLEY);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    SetEntityFacing(ENTITY_BARLEY, FACING_UP);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_WALK);
    MoveEntityYTo(ENTITY_MAY, Y(116), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MAY);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_NPCEvent_May_PhoneCallWithJoanna_DougAsksIfCallerWasJoanna);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MAY);
    TalkMessage(gText_NPCEvent_May_PhoneCallWithJoanna_MaySaysSheEnjoysTalkingToMother);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_NPCEvent_May_PhoneCallWithJoanna_DougRespondsWithRelief);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MAY);
    TalkMessage(gText_NPCEvent_May_PhoneCallWithJoanna_MayAffirmsHappiness);
    TalkClose();
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MAY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MAY);
    TalkMessage(gText_NPCEvent_May_PhoneCallWithJoanna_MayRevealsJoannaStillWillNotReturn);
    TalkClose();
    WaitFrames(30);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_NPCEvent_May_PhoneCallWithJoanna_DougSympathizesWithMay);
    TalkClose();
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_NPCEvent_May_PhoneCallWithJoanna_BarleyApologizesAndPreparesToLeave);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MAY);
    TalkMessage(gText_NPCEvent_May_PhoneCallWithJoanna_MaySaysGoodbyeToDoug);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_NPCEvent_May_PhoneCallWithJoanna_DougSaysGoodbyeToMay);
    TalkClose();
    WaitFrames(30);
    SetEntityFacing(ENTITY_BARLEY, FACING_DOWN);
    SetEntityFacing(ENTITY_MAY, FACING_DOWN);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_WALK);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_WALK);
    MoveEntityYTo(ENTITY_BARLEY, Y(283), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_MAY, Y(283), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_BARLEY);
    WaitForEntityMovement(ENTITY_MAY);
    HideEntity(ENTITY_BARLEY);
    HideEntity(ENTITY_MAY);
    VarSet(VAR_MAY_PHONE_CALL_WITH_JOANNA_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    PanCameraTo(X(184), Y(320), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
}
