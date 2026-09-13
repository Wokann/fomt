#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Kappa_DailyOfferingAppearance_KappaSilentlyAcceptsOffering[] =
        "………　　　　　　　　　　　{Press}\p"
        "……　　　　　　　　　　　　{Press}\p"
        "…　　　　　　　　　　　　　{Press}";
};

void EventScript_NPCEvent_Kappa_DailyOfferingAppearance(void)
{
    int var_0;
    PlaySong(AUDIO_START, AUDIO_SFX_SHIPMENT_DEPOSIT);
    WaitFrames(10);
    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_FISHING_ROD_COLLECT_FISH);
    WaitFrames(20);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_FAST);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_FAST);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    switch (GetEntityFacing(ENTITY_PLAYER))
    {
        case FACING_UP:
            SetEntityPosition(ENTITY_KAPPA, X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) - 52), FACING_DOWN);
            break;
        case FACING_DOWN:
            SetEntityPosition(ENTITY_KAPPA, X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) + 52), FACING_UP);
            break;
        case FACING_LEFT:
            SetEntityPosition(ENTITY_KAPPA, X(GetEntityX(ENTITY_PLAYER) - 52), Y(GetEntityY(ENTITY_PLAYER)), FACING_RIGHT);
            break;
        case FACING_RIGHT:
            SetEntityPosition(ENTITY_KAPPA, X(GetEntityX(ENTITY_PLAYER) + 52), Y(GetEntityY(ENTITY_PLAYER)), FACING_LEFT);
            break;
    }
    SetEntityAnim(ENTITY_KAPPA, ANIMATION_KAPPA_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAPPA);
    SetTalkPortrait(TALK_PORTRAIT_KAPPA_NORMAL);
    TalkMessage(gText_NPCEvent_Kappa_DailyOfferingAppearance_KappaSilentlyAcceptsOffering);
    TalkClose();
    var_0 = 0;
    do
    {
        switch (GetEntityFacing(ENTITY_PLAYER))
        {
            case FACING_UP:
                MoveEntityYTo(ENTITY_KAPPA, Y(GetEntityY(ENTITY_KAPPA) - 1), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_KAPPA);
                HideEntity(ENTITY_KAPPA);
                SetEntityPosition(ENTITY_KAPPA, X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) - 52 - var_0), FACING_DOWN);
                SetEntityAnim(ENTITY_KAPPA, ANIMATION_KAPPA_HANDS_TOGETHER);
                switch (var_0 % 8)
                {
                    case 0:
                    case 1:
                        SetEntityFacing(ENTITY_KAPPA, FACING_DOWN);
                        break;
                    case 2:
                    case 3:
                        SetEntityFacing(ENTITY_KAPPA, FACING_LEFT);
                        break;
                    case 4:
                    case 5:
                        SetEntityFacing(ENTITY_KAPPA, FACING_UP);
                        break;
                    case 6:
                    case 7:
                        SetEntityFacing(ENTITY_KAPPA, FACING_RIGHT);
                        break;
                }
                break;
            case FACING_DOWN:
                MoveEntityYTo(ENTITY_KAPPA, Y(GetEntityY(ENTITY_KAPPA) + 1), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_KAPPA);
                HideEntity(ENTITY_KAPPA);
                SetEntityPosition(ENTITY_KAPPA, X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) + 52 + var_0), FACING_DOWN);
                SetEntityAnim(ENTITY_KAPPA, ANIMATION_KAPPA_HANDS_TOGETHER);
                switch (var_0 % 8)
                {
                    case 0:
                    case 1:
                        SetEntityFacing(ENTITY_KAPPA, FACING_DOWN);
                        break;
                    case 2:
                    case 3:
                        SetEntityFacing(ENTITY_KAPPA, FACING_LEFT);
                        break;
                    case 4:
                    case 5:
                        SetEntityFacing(ENTITY_KAPPA, FACING_UP);
                        break;
                    case 6:
                    case 7:
                        SetEntityFacing(ENTITY_KAPPA, FACING_RIGHT);
                        break;
                }
                break;
            case FACING_LEFT:
                MoveEntityXTo(ENTITY_KAPPA, X(GetEntityX(ENTITY_KAPPA) - 1), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_KAPPA);
                HideEntity(ENTITY_KAPPA);
                SetEntityPosition(ENTITY_KAPPA, X(GetEntityX(ENTITY_PLAYER) - 52 - var_0), Y(GetEntityY(ENTITY_PLAYER)), FACING_DOWN);
                SetEntityAnim(ENTITY_KAPPA, ANIMATION_KAPPA_HANDS_TOGETHER);
                switch (var_0 % 8)
                {
                    case 0:
                    case 1:
                        SetEntityFacing(ENTITY_KAPPA, FACING_DOWN);
                        break;
                    case 2:
                    case 3:
                        SetEntityFacing(ENTITY_KAPPA, FACING_LEFT);
                        break;
                    case 4:
                    case 5:
                        SetEntityFacing(ENTITY_KAPPA, FACING_UP);
                        break;
                    case 6:
                    case 7:
                        SetEntityFacing(ENTITY_KAPPA, FACING_RIGHT);
                        break;
                }
                break;
            case FACING_RIGHT:
                MoveEntityXTo(ENTITY_KAPPA, X(GetEntityX(ENTITY_KAPPA) + 1), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_KAPPA);
                HideEntity(ENTITY_KAPPA);
                SetEntityPosition(ENTITY_KAPPA, X(GetEntityX(ENTITY_PLAYER) + 52 + var_0), Y(GetEntityY(ENTITY_PLAYER)), FACING_DOWN);
                SetEntityAnim(ENTITY_KAPPA, ANIMATION_KAPPA_HANDS_TOGETHER);
                switch (var_0 % 8)
                {
                    case 0:
                    case 1:
                        SetEntityFacing(ENTITY_KAPPA, FACING_DOWN);
                        break;
                    case 2:
                    case 3:
                        SetEntityFacing(ENTITY_KAPPA, FACING_LEFT);
                        break;
                    case 4:
                    case 5:
                        SetEntityFacing(ENTITY_KAPPA, FACING_UP);
                        break;
                    case 6:
                    case 7:
                        SetEntityFacing(ENTITY_KAPPA, FACING_RIGHT);
                        break;
                }
                break;
        }
        WaitFrames(3);
        var_0 = var_0 + 1;
    }
    while (var_0 <= 50);
    WaitFrames(60);
    HideEntity(ENTITY_KAPPA);
    PlaySong(AUDIO_START, AUDIO_SFX_WATER_SPLASH);
    WaitFrames(60);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(100);
    VarSet(VAR_KAPPA_DAILY_APPEARANCE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
}
