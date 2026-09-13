#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_RickAndKaren_02_BlueHeart_ChildhoodMemories_RickReminiscesAboutChildhoodGames[] =
        "Wir haben hier \r\n"
        "immer gespielt. {Press}";

    const char gText_RivalEvent_RickAndKaren_02_BlueHeart_ChildhoodMemories_KarenRecallsTagKickballAndHideAndSeek[] =
        "Wir haben immer \r\n"
        "Dosenschießen und \r\n"
        "Verstecken und so gespielt.{Press}";

    const char gText_RivalEvent_RickAndKaren_02_BlueHeart_ChildhoodMemories_RickTeasesKarenAboutLosingWrestlingMatches[] =
        "Oder auch Ringen...\r\n"
        "Obwohl... ich dich nie \r\n"
        "schlagen konnte.{Press}";

    const char gText_RivalEvent_RickAndKaren_02_BlueHeart_ChildhoodMemories_KarenDeniesBeingWeak[] =
        "Oder auch Ringen...\r\n"
        "Obwohl...ich dich nie \r\n"
        "schlagen konnte.{Press}";

    const char gText_RivalEvent_RickAndKaren_02_BlueHeart_ChildhoodMemories_RickRecallsKarenCryingAfterLosing[] =
        "Was meinst du denn!? \r\n"
        "Ich erinnere mich\r\n"
        "an nichts dergleichen!?{Press}";

    const char gText_RivalEvent_RickAndKaren_02_BlueHeart_ChildhoodMemories_KarenRefusesToRemember[] =
        "Ich sagte doch, ich weiß\r\n"
        "es nicht mehr!\r\n"
        "Ich gehe nach Hause!{Press}";

    const char gText_RivalEvent_RickAndKaren_02_BlueHeart_ChildhoodMemories_RickCallsAfterAngryKaren[] =
        "Warum bist du sauer?\r\n"
        "Warte mal!{Press}";
};

void EventScript_RivalEvent_RickAndKaren_02_BlueHeart_ChildhoodMemories(void)
{
    ChangeMap(MAP_FOREST, X(412), Y(156));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    VarSet(VAR_RICK_KAREN_RIVAL_EVENT_2_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityPosition(ENTITY_PLAYER, X(612), Y(248), FACING_DOWN);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_KAREN, X(400), Y(156), FACING_RIGHT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_RICK, X(424), Y(156), FACING_LEFT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StartEntityEffect(ENTITY_RICK, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_02_BlueHeart_ChildhoodMemories_RickReminiscesAboutChildhoodGames);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_02_BlueHeart_ChildhoodMemories_KarenRecallsTagKickballAndHideAndSeek);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_02_BlueHeart_ChildhoodMemories_RickTeasesKarenAboutLosingWrestlingMatches);
    TalkClose();
    StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_ANGRY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_02_BlueHeart_ChildhoodMemories_KarenDeniesBeingWeak);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_02_BlueHeart_ChildhoodMemories_RickRecallsKarenCryingAfterLosing);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    TalkMessage(gText_RivalEvent_RickAndKaren_02_BlueHeart_ChildhoodMemories_KarenRefusesToRemember);
    TalkClose();
    StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_ANGRY, TRUE);
    SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
    SetEntityFacing(ENTITY_RICK, FACING_DOWN);
    MoveEntityYTo(ENTITY_KAREN, Y(290), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAREN);
    StopEntityEffect(ENTITY_KAREN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_RickAndKaren_02_BlueHeart_ChildhoodMemories_RickCallsAfterAngryKaren);
    TalkClose();
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WALK);
    MoveEntityYTo(ENTITY_RICK, Y(268), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_RICK);
    HideEntity(ENTITY_KAREN);
    HideEntity(ENTITY_RICK);
    PanCameraTo(X(612), Y(248), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    VarSet(VAR_RICK_KAREN_RIVAL_EVENT_2_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
