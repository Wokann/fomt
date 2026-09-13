#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_KarenAsksAboutLilliasHealth[] =
        "Deine Mutter scheint \r\n"
        "sich besser zu fühlen.{Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_RickSaysLilliasHealthHasImproved[] =
        "Ja, in letzter Zeit schon...{Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_KarenIsGladLilliaFeelsBetter[] =
        "Schön zu hören!{Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_LilliaGreetsKaren[] =
        "Hi, Karen. \r\n"
        "Wie geht es dir. {Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_KarenSaysRickSharedTheGoodNews[] =
        "Hi. Rick sagte gerade,\r\n"
        "dass sich deine Gesundheit\r\n"
        "verbessert hat. {Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_LilliaConfirmsHerImprovement[] =
        "Das stimmt. {Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_KarenHopesLilliaStaysWell[] =
        "Das freut mich. Ich hoffe,\r\n"
        "du bleibst immer gesund!{Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_LilliaSaysAnotherMatterConcernsHer[] =
        "Es ist nicht meine \r\n"
        "Gesundheit, aber ich \r\n"
        "mache mir Sorgen...{Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_KarenAsksWhetherConcernIsRod[] =
        "Deinen Mann meinst du?{Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_LilliaRevealsConcernIsRickAndKaren[] =
        "Ja, das auch...\r\n"
        "Aber eigentlich um \r\n"
        "dich und Karen. {Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_RickReactsToLilliasMatchmaking[] =
        "Mich und Karen!?!{Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_LilliaAsksWhenRickAndKarenWillMarry[] =
        "Ich habe mich gefragt, \r\n"
        "wann ihr heiratet...{Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_RickIsEmbarrassedByLilliasMatchmaking[] =
        "Mama...!!{Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_LilliaSaysRickAndKarenHaveAlwaysBeenClose[] =
        "Ich wusste immer, dass \r\n"
        "ihr beiden euch gerne \r\n"
        "mögt. Keinen Zweck,{Press}\r\n"
        "es zu verbergen!{Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_KarenIsSilentlyEmbarrassed[] =
        ".......{Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_RickProtestsLilliasTeasing[] =
        "Mama!{Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_LilliaStopsTeasingRickAndKaren[] =
        "OK, OK...Ich will \r\n"
        "mich nicht einmischen...\r\n"
        "Ich gehe nach Hause.{Press}\p"
        "Nimm dir Zeit, Karen.{Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_RickApologizesForLilliasTeasing[] =
        "Ha ha ha...\r\n"
        "Tut mir Leid...Keine Ahnung,\r\n"
        "wovon Mama gesprochen hat.{Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_KarenLeavesInEmbarrassment[] =
        "...Ha ha...\r\n"
        "Hmm,ich muss weg...{Press}";

    const char gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_RickFollowsKarenHome[] =
        "Ich gehe auch. {Press}";
};

void EventScript_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion(void)
{
    ChangeMap(MAP_SOUTH_SIDE_TOWN, X(572), Y(232));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    VarSet(VAR_RICK_KAREN_RIVAL_EVENT_4_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityPosition(ENTITY_PLAYER, X(572), Y(232), FACING_DOWN);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_KAREN, X(464), Y(424), FACING_RIGHT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_RICK, X(495), Y(424), FACING_LEFT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(480), Y(424), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    SetEntityPosition(ENTITY_LILLIA, X(480), Y(328), FACING_DOWN);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_KarenAsksAboutLilliasHealth);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_RickSaysLilliasHealthHasImproved);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_KarenIsGladLilliaFeelsBetter);
    TalkClose();
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_WALK);
    MoveEntityYTo(ENTITY_LILLIA, Y(384), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_LILLIA);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_LilliaGreetsKaren);
    TalkClose();
    SetEntityFacing(ENTITY_KAREN, FACING_UP);
    SetEntityFacing(ENTITY_RICK, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_KarenSaysRickSharedTheGoodNews);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_LilliaConfirmsHerImprovement);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_KarenHopesLilliaStaysWell);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_LilliaSaysAnotherMatterConcernsHer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_KarenAsksWhetherConcernIsRod);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_LilliaRevealsConcernIsRickAndKaren);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_RickReactsToLilliasMatchmaking);
    TalkClose();
    SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
    SetEntityFacing(ENTITY_RICK, FACING_LEFT);
    StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_QUESTION, FALSE);
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_LilliaAsksWhenRickAndKarenWillMarry);
    TalkClose();
    StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_EXCLAMATION, FALSE);
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_KAREN, FACING_UP);
    SetEntityFacing(ENTITY_RICK, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_RickIsEmbarrassedByLilliasMatchmaking);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_LilliaSaysRickAndKarenHaveAlwaysBeenClose);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_KarenIsSilentlyEmbarrassed);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_RickProtestsLilliasTeasing);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_LilliaStopsTeasingRickAndKaren);
    TalkClose();
    SetEntityFacing(ENTITY_LILLIA, FACING_UP);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_WALK);
    MoveEntityYTo(ENTITY_LILLIA, Y(328), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_LILLIA);
    StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_THINKING, FALSE);
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_RICK, FACING_LEFT);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_RickApologizesForLilliasTeasing);
    TalkClose();
    SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_KarenLeavesInEmbarrassment);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion_RickFollowsKarenHome);
    TalkClose();
    SetEntityFacing(ENTITY_KAREN, FACING_UP);
    SetEntityFacing(ENTITY_RICK, FACING_UP);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WALK);
    MoveEntityYTo(ENTITY_KAREN, Y(328), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_RICK, Y(328), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAREN);
    WaitForEntityMovement(ENTITY_RICK);
    HideEntity(ENTITY_KAREN);
    HideEntity(ENTITY_RICK);
    HideEntity(ENTITY_LILLIA);
    PanCameraTo(X(572), Y(232), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    VarSet(VAR_RICK_KAREN_RIVAL_EVENT_4_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
