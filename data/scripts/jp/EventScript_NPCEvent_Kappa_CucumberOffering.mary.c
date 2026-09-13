#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Kappa_CucumberOffering_SilentPause[] =
        "…………\r\n"
        "\r\n"
        "{Press}";

    const char gText_NPCEvent_Kappa_CucumberOffering_HereYouGoDontComeBack[] =
        "…これやる。もう来るな。\r\n"
        "\r\n"
        "{Press}";

    const char gText_NPCEvent_Kappa_CucumberOffering_YouSureAreStubborn[] =
        "お前、しつこい。もう来るな。\r\n"
        "\r\n"
        "{Press}";
};

void EventScript_NPCEvent_Kappa_CucumberOffering(void)
{
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_FAST);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_FAST);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    switch (GetEntityFacing(ENTITY_PLAYER))
    {
        case FACING_UP:
            SetEntityPosition(ENTITY_KAPPA, X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) - 24), FACING_DOWN);
            break;
        case FACING_DOWN:
            SetEntityPosition(ENTITY_KAPPA, X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) + 24), FACING_UP);
            break;
        case FACING_LEFT:
            SetEntityPosition(ENTITY_KAPPA, X(GetEntityX(ENTITY_PLAYER) - 24), Y(GetEntityY(ENTITY_PLAYER)), FACING_RIGHT);
            break;
        case FACING_RIGHT:
            SetEntityPosition(ENTITY_KAPPA, X(GetEntityX(ENTITY_PLAYER) + 24), Y(GetEntityY(ENTITY_PLAYER)), FACING_LEFT);
            break;
    }
    SetEntityAnim(ENTITY_KAPPA, ANIMATION_KAPPA_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_KAPPA);
    SetTalkPortrait(TALK_PORTRAIT_KAPPA_NORMAL);
    if (VarGet(VAR_KAPPA_FIRST_CUCUMBER_OFFERING_STATE) != EVENT_LIFECYCLE_COMPLETED)
    {
        TalkMessage(gText_NPCEvent_Kappa_CucumberOffering_SilentPause);
        TalkClose();
        VarSet(VAR_KAPPA_FIRST_CUCUMBER_OFFERING_STATE, EVENT_LIFECYCLE_COMPLETED);
    }
    else
    {
        if (VarGet(VAR_KAPPA_CUCUMBER_OFFERING_REWARD_CYCLE) == 10 && VarGet(VAR_KAPPA_MYSTIC_BERRY_REWARD_STATE) != EVENT_LIFECYCLE_COMPLETED)
        {
            TalkMessage(gText_NPCEvent_Kappa_CucumberOffering_HereYouGoDontComeBack);
            TalkClose();
            SetEntityAnim(ENTITY_KAPPA, ANIMATION_KAPPA_HANDS_TOGETHER);
            WaitFrames(30);
            SetEntityAnim(ENTITY_KAPPA, ANIMATION_KAPPA_IDLE);
            PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
            ObtainMysticBerry();
            VarSet(VAR_KAPPA_MYSTIC_BERRY_REWARD_STATE, EVENT_LIFECYCLE_COMPLETED);
            VarSet(VAR_HAS_MYSTIC_BERRY, TRUE);
        }
        else
        {
            TalkMessage(gText_NPCEvent_Kappa_CucumberOffering_YouSureAreStubborn);
            TalkClose();
        }
    }
    if (VarGet(VAR_KAPPA_CUCUMBER_OFFERING_MADE_TODAY) != TRUE)
    {
        if (VarGet(VAR_KAPPA_CUCUMBER_OFFERING_REWARD_CYCLE) == 10)
        {
            VarSet(VAR_KAPPA_CUCUMBER_OFFERING_REWARD_CYCLE, 0);
        }
        else
        {
            VarSet(VAR_KAPPA_CUCUMBER_OFFERING_REWARD_CYCLE, VarGet(VAR_KAPPA_CUCUMBER_OFFERING_REWARD_CYCLE) + 1);
        }
        VarSet(VAR_KAPPA_CUCUMBER_OFFERING_MADE_TODAY, TRUE);
    }
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_KAPPA);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK, SCREEN_FADE_SPEED_NORMAL);
}
