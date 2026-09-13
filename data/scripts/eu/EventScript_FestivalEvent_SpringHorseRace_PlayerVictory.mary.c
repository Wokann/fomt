#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SpringHorseRace_PlayerVictory[] =
        "That was a great race, \r\n"
        "{Player}!\r\n"
        "Congratulations!{Press}";
};

void EventScript_FestivalEvent_SpringHorseRace_PlayerVictory(void)
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
    TalkMessage(gText_FestivalEvent_SpringHorseRace_PlayerVictory);
    TalkClose();
    if (IsPlayerHoldingNothing() == TRUE && VarGet(VAR_FESTIVAL_HORSE_RACE_POWER_BERRY_OBTAINED) == FALSE)
    {
        ObtainPowerBerry();
        VarSet(VAR_FESTIVAL_HORSE_RACE_POWER_BERRY_OBTAINED, TRUE);
    }
    PlaySong(AUDIO_START, AUDIO_SFX_VICTORY);
    WaitFrames(60 * 4);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    AddNpcFriendship(CHARACTER_RICK, 20);
    AddNpcFriendship(CHARACTER_POPURI, 20);
    AddNpcFriendship(CHARACTER_BARLEY, 20);
    AddNpcFriendship(CHARACTER_MAY, 20);
    AddNpcFriendship(CHARACTER_SAIBARA, 20);
    AddNpcFriendship(CHARACTER_DUKE, 20);
    AddNpcFriendship(CHARACTER_MANNA, 20);
    AddNpcFriendship(CHARACTER_THOMAS, 20);
    AddNpcFriendship(CHARACTER_HARRIS, 20);
    AddNpcFriendship(CHARACTER_JEFF, 20);
    AddNpcFriendship(CHARACTER_SASHA, 20);
    AddNpcFriendship(CHARACTER_KAREN, 20);
    AddNpcFriendship(CHARACTER_DOUG, 20);
    AddNpcFriendship(CHARACTER_ANN, 20);
    AddNpcFriendship(CHARACTER_ZACK, 20);
    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
    CallScript(EventScript_FestivalEvent_SpringHorseRace_Competition);
}
