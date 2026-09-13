#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ChickenFestival_PlayerVictory_WinnerAnnouncement[] =
        "Congratulations on winning!\r\n"
        "I've never seen such a\r\n"
        "strong Chicken! {Press}\p"
        "Thanks again for a\r\n"
        "great set of bouts! {Press}";
};

void EventScript_FestivalEvent_ChickenFestival_PlayerVictory(void)
{
    ChangeMap(MAP_ROSE_SQUARE, X(220), Y(94));
    StopBGM();
    SetEntityPosition(ENTITY_RICK, X(220), Y(76), FACING_DOWN);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(220), Y(94), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(200), Y(98), FACING_UP);
    SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_SMALL_ANIMAL);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_CHICKEN_IDLE);
    if (GetEntityLocation(ENTITY_FARM_DOG) == MAP_ROSE_SQUARE)
    {
        SetEntityPosition(ENTITY_FARM_DOG, X(416), Y(133), FACING_DOWN);
    }
    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    PlaySong(AUDIO_START, AUDIO_SFX_SUCCESS);
    WaitFrames(60 * 4);
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_FestivalEvent_ChickenFestival_PlayerVictory_WinnerAnnouncement);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_VICTORY);
    WaitFrames(60 * 4);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    AddNpcFriendship(CHARACTER_RICK, 20);
    AddNpcFriendship(CHARACTER_BARLEY, 20);
    AddNpcFriendship(CHARACTER_SAIBARA, 20);
    AddNpcFriendship(CHARACTER_DUKE, 20);
    AddNpcFriendship(CHARACTER_THOMAS, 20);
    AddNpcFriendship(CHARACTER_POPURI, 20);
    AddNpcFriendship(CHARACTER_DOUG, 20);
    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
    CallScript(EventScript_FestivalEvent_ChickenFestival_Closing);
}
