#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FallHorseRace_PlayerVictory[] =
        "Ein tolles Rennen, \r\n"
        "{Player}. \r\n"
        "Herzlichen Glückwunsch!{Press}";
};

void EventScript_FestivalEvent_FallHorseRace_PlayerVictory(void)
{
    ChangeMap(MAP_ROSE_SQUARE, X(220), Y(94));
    StopBGM();
    SetEntityPosition(ENTITY_THOMAS, X(220), Y(76), FACING_DOWN);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
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
    SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_LIVESTOCK);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_FARM_HORSE_IDLE);
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
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_FestivalEvent_FallHorseRace_PlayerVictory);
    TalkClose();
    if (IsPlayerHoldingNothing() == TRUE && VarGet(VAR_FESTIVAL_HORSE_RACE_POWER_BERRY_OBTAINED) == FALSE)
    {
        ObtainPowerBerry();
        VarSet(VAR_FESTIVAL_HORSE_RACE_POWER_BERRY_OBTAINED, TRUE);
    }
    PlaySong(AUDIO_START, AUDIO_SFX_VICTORY);
    WaitFrames(60 * 4);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    AddNpcFriendship(CHARACTER_THOMAS, 20);
    AddNpcFriendship(CHARACTER_BARLEY, 20);
    AddNpcFriendship(CHARACTER_SAIBARA, 20);
    AddNpcFriendship(CHARACTER_ZACK, 20);
    AddNpcFriendship(CHARACTER_GOTZ, 20);
    AddNpcFriendship(CHARACTER_GRAY, 20);
    AddNpcFriendship(CHARACTER_MARY, 20);
    AddNpcFriendship(CHARACTER_DOUG, 20);
    AddNpcFriendship(CHARACTER_ELLI, 20);
    AddNpcFriendship(CHARACTER_DOCTOR, 20);
    AddNpcFriendship(CHARACTER_CARTER, 20);
    AddNpcFriendship(CHARACTER_LILLIA, 20);
    AddNpcFriendship(CHARACTER_RICK, 20);
    AddNpcFriendship(CHARACTER_HARRIS, 20);
    AddNpcFriendship(CHARACTER_DUKE, 20);
    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
    CallScript(EventScript_FestivalEvent_FallHorseRace_Competition);
}
