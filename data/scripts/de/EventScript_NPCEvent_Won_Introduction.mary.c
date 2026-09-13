#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Won_Introduction_WonGreetsPlayer[] =
        "Guten Tag!{Press}";

    const char gText_NPCEvent_Won_Introduction_WonIntroducesHimselfAsTravelingSalesman[] =
        "Mein Name ist Won, \r\n"
        "ich bin ein reisender\r\n"
        "Händler aus Fernost.{Press}\p"
        "Wie geht es dir? {Press}";

    const char gText_NPCEvent_Won_Introduction_WonAdvertisesRareSeedsAtZacksHouse[] =
        "Ich führe viele \r\n"
        "seltene Samen! Du wirst\r\n"
        "zufrieden sein, wenn du{Press}\r\n"
        "sie kaufst. Ich wohne bei{Press}\p"
        "Zack. Komm jederzeit vorbei\r\n"
        "und schau dich um!{Press}";

    const char gText_NPCEvent_Won_Introduction_WonLeavesToContinueSalesRounds[] =
        "Ich muss gehen und \r\n"
        "meine Runden machen.\r\n"
        "Ich erwarte dich. {Press}";
};

void EventScript_NPCEvent_Won_Introduction(void)
{
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_WON, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_WON, ANIMATION_WON_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Won_Introduction_WonGreetsPlayer);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Won_Introduction_WonIntroducesHimselfAsTravelingSalesman);
    SetTalkPortrait(TALK_PORTRAIT_WON_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Won_Introduction_WonAdvertisesRareSeedsAtZacksHouse);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_WON);
    TalkMessage(gText_NPCEvent_Won_Introduction_WonLeavesToContinueSalesRounds);
    TalkClose();
    SetEntityFacing(ENTITY_WON, FACING_RIGHT);
    SetEntityAnim(ENTITY_WON, ANIMATION_WON_WALK);
    MoveEntityXTo(ENTITY_WON, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_WON);
    SetEntityFacing(ENTITY_WON, FACING_UP);
    MoveEntityYTo(ENTITY_WON, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_WON);
    HideEntity(ENTITY_WON);
    MarkNpcSpokenTo(CHARACTER_WON);
    VarSet(VAR_WON_INTRODUCTION_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    return;
}
