#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PlayerVictory_BarleyAnnouncesPlayersWinningSheep[] =
        "And the winning Sheep is...\r\n"
        "{Var1} from \r\n"
        "{Place1}!{Press}\p"
        "It had the best coat, and \r\n"
        "was also just the nicest!{Press}";
};

void EventScript_FestivalEvent_SheepFestival_PlayerVictory(void)
{
    int unused_0, var_1;
    var_1 = GetContestAnimalIndex(ANIMAL_KIND_SHEEP);
    GetAnimalName(TEXT_VARIABLE_1, ANIMAL_KIND_SHEEP, var_1);
    ChangeMap(MAP_ROSE_SQUARE, X(220), Y(94));
    StopBGM();
    SetEntityPosition(ENTITY_BARLEY, X(220), Y(76), FACING_DOWN);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(220), Y(94), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_1);
    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_2);
    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_3);
    SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(200), Y(98), FACING_UP);
    SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_LIVESTOCK);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_SHEEP_IDLE);
    if (GetEntityLocation(ENTITY_FARM_DOG) == MAP_ROSE_SQUARE)
    {
        SetEntityPosition(ENTITY_FARM_DOG, X(416), Y(133), FACING_DOWN);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    PlaySong(AUDIO_START, AUDIO_SFX_SUCCESS);
    WaitFrames(60 * 4);
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_ANIMAL_FESTIVAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_FestivalEvent_SheepFestival_PlayerVictory_BarleyAnnouncesPlayersWinningSheep);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_VICTORY);
    WaitFrames(60 * 4);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    AddNpcFriendship(CHARACTER_RICK, 20);
    AddNpcFriendship(CHARACTER_KAREN, 20);
    AddNpcFriendship(CHARACTER_BARLEY, 20);
    AddNpcFriendship(CHARACTER_MAY, 20);
    AddNpcFriendship(CHARACTER_GRAY, 20);
    AddNpcFriendship(CHARACTER_JEFF, 20);
    AddNpcFriendship(CHARACTER_THOMAS, 20);
    AddNpcFriendship(CHARACTER_ANNA, 20);
    AddNpcFriendship(CHARACTER_HARRIS, 20);
    AddNpcFriendship(CHARACTER_GOTZ, 20);
    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
    CallScript(EventScript_FestivalEvent_SheepFestival_ClosingAnnouncement);
}
