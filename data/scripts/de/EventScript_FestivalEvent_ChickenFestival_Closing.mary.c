#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ChickenFestival_Closing[] =
        "Das Hühnerfestival ist \r\n"
        "vorbei. Wir bringen\r\n"
        "eure Hühner zurück nach{Press}\r\n"
        "Hause, so dass ihr ohne \r\n"
        "sie gehen könnt. \r\n"
        "Das Hühnerfestival ist...{Press}";
};

void EventScript_FestivalEvent_ChickenFestival_Closing(void)
{
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
    SetGameTime(18, 1);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_RICK, X(170), Y(233), FACING_LEFT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    SetEntityPosition(ENTITY_BARLEY, X(140), Y(271), FACING_RIGHT);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    SetEntityPosition(ENTITY_SAIBARA, X(193), Y(155), FACING_DOWN);
    SetEntityAnim(ENTITY_SAIBARA, ANIMATION_SAIBARA_IDLE);
    SetEntityPosition(ENTITY_DUKE, X(289), Y(224), FACING_LEFT);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    SetEntityPosition(ENTITY_THOMAS, X(88), Y(86), FACING_DOWN);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    SetEntityPosition(ENTITY_POPURI, X(196), Y(296), FACING_UP);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(275), Y(162), FACING_LEFT);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_FestivalEvent_ChickenFestival_Closing);
    TalkClose();
    SetEntityEventScript(ENTITY_RICK, EventScript_FestivalEvent_ChickenFestival_PostTournamentDialogue_Rick);
    SetEntityEventScript(ENTITY_BARLEY, EventScript_FestivalEvent_ChickenFestival_PostTournamentDialogue_Barley);
    SetEntityEventScript(ENTITY_SAIBARA, EventScript_FestivalEvent_ChickenFestival_PostTournamentDialogue_Saibara);
    SetEntityEventScript(ENTITY_DUKE, EventScript_FestivalEvent_ChickenFestival_PostTournamentDialogue_Duke);
    SetEntityEventScript(ENTITY_THOMAS, EventScript_FestivalEvent_ChickenFestival_PostTournamentDialogue_Thomas);
    SetEntityEventScript(ENTITY_POPURI, EventScript_FestivalEvent_ChickenFestival_PostTournamentDialogue_Popuri);
    SetEntityEventScript(ENTITY_DOUG, EventScript_FestivalEvent_ChickenFestival_PostTournamentDialogue_Doug);
}
