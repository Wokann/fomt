#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_DogFrisbeeTournament_PlayerVictory_WinnerAnnouncement[] =
        "Listen, everyone!\r\n"
        "This year's champion is\r\n"
        "{Dog}!!{Press}\r\n"
        "Good job!{Press}";
};

void EventScript_FestivalEvent_DogFrisbeeTournament_PlayerVictory(void)
{
    ChangeMap(MAP_MINERAL_BEACH, X(156), Y(154));
    StopBGM();
    SetEntityPosition(ENTITY_ZACK, X(156), Y(136), FACING_DOWN);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(156), Y(154), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(140), Y(154), FACING_UP);
    SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_SMALL_ANIMAL);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_FARM_DOG_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    StopBGM();
    PlaySong(AUDIO_START, AUDIO_SFX_SUCCESS);
    WaitFrames(60 * 4);
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_FestivalEvent_DogFrisbeeTournament_PlayerVictory_WinnerAnnouncement);
    TalkClose();
    if (IsPlayerHoldingNothing() == TRUE && VarGet(VAR_FRISBEE_TOURNAMENT_POWER_BERRY_OBTAINED) == FALSE)
    {
        ObtainPowerBerry();
        VarSet(VAR_FRISBEE_TOURNAMENT_POWER_BERRY_OBTAINED, TRUE);
    }
    PlaySong(AUDIO_START, AUDIO_SFX_VICTORY);
    WaitFrames(60 * 4);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    AddNpcFriendship(CHARACTER_THOMAS, 20);
    AddNpcFriendship(CHARACTER_JEFF, 20);
    AddNpcFriendship(CHARACTER_SASHA, 20);
    AddNpcFriendship(CHARACTER_KAI, 20);
    AddNpcFriendship(CHARACTER_POPURI, 20);
    AddNpcFriendship(CHARACTER_ZACK, 20);
    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
    CallScript(EventScript_FestivalEvent_BeachDay_Closing);
}
