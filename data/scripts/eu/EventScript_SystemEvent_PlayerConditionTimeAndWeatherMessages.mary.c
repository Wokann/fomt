#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_HighFatigueRestAdvice[] =
        "I don't look so good...\r\n"
        "I shouldn't work today.\r\n"
        "Get some rest instead.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_HighFatigueFoodRecoveryAdvice[] =
        "I don't look so good...\r\n"
        "Better eat something to\r\n"
        "help me recuperate{Press}\r\n"
        "from Fatigue.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_MidnightNoEventBedtimeAdvice[] =
        "It's already late.\r\n"
        "I should get to bed.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_PredawnSleepAdvice[] =
        "It will be morning soon...\r\n"
        "I should get at least\r\n"
        "a little sleep.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_LateNightBedtimeAdvice[] =
        "It's getting late.\r\n"
        "I’d better go to bed.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_NightTimeLabel[] =
        "Night\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_MidnightTimeLabel[] =
        "Midnight\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_MorningMotivation[] =
        "Another day to enjoy!{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_MorningTimeLabel[] =
        "Morning\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_NoonWorkContinuationAdvice[] =
        "It's still noon. I should\r\n"
        "get back to work.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_NoonTimeLabel[] =
        "Noon\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_EveningWorkContinuationAdvice[] =
        "It's still evening. I\r\n"
        "should get back to work.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_EveningTimeLabel[] =
        "Evening\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_DuskFinishWorkAdvice[] =
        "It's getting dark, so I\r\n"
        "should finish up my work.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_DuskTimeLabel[] =
        "Almost nighttime.\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_NightQuitWorkAdvice[] =
        "It's dark already, so I\r\n"
        "should quit working.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_LateBadWeatherFatigueWarning[] =
        "My Fatigue builds up more\r\n"
        "easily in bad weather, but\r\n"
        "working this late will tire{Press}\r\n"
        "me out even faster!{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_BadWeatherToolUseFatigueWarning[] =
        "When I use your Tools\r\n"
        "in bad weather, I build up\r\n"
        "Fatigue faster, so {Press}\r\n"
        "be careful.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_TyphoonStayIndoorsAdvice[] =
        "I can't go outside in a\r\n"
        "Typhoon. Get some \r\n"
        "extra sleep.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_StormWindHouseConcern[] =
        "The winds outside are\r\n"
        "practically a gale. I hope\r\n"
        "the House can take this.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_SnowstormStayIndoorsAdvice[] =
        "I can't go outside in \r\n"
        "so much snow. Get some \r\n"
        "extra sleep.{Press}";
};

void EventScript_SystemEvent_PlayerConditionTimeAndWeatherMessages(void)
{
    if (!(VarGet(VAR_HOUR) == 0 && VarGet(VAR_MINUTE) == 0))
    {
        TalkOpen();
    }
    if (VarGet(VAR_PLAYER_FATIGUE) >= 80)
    {
        switch (RandomIntInclusive(0, 1))
        {
            case 0:
                TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_HighFatigueRestAdvice);
                break;
            case 1:
                TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_HighFatigueFoodRecoveryAdvice);
                break;
        }
    }
    else
    {
        switch (VarGet(VAR_WEATHER_TODAY))
        {
            case WEATHER_SUNNY:
                if (VarGet(VAR_HOUR) < 6 || VarGet(VAR_HOUR) >= 22)
                {
                    if (VarGet(VAR_HOUR) == 0 && VarGet(VAR_MINUTE) == 0)
                    {
                        switch (RandomIntInclusive(0, 7))
                        {
                            case 0:
                                SetEntityPosition(ENTITY_KAPPA, X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER) - 16), FACING_LEFT);
                                WaitFrames(1);
                                HideEntity(ENTITY_KAPPA);
                                PlaySong(AUDIO_START, AUDIO_SFX_KAPPA_SURPRISE);
                                WaitFrames(5);
                                StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
                                MoveEntityYTo(ENTITY_PLAYER, Y(GetEntityY(ENTITY_PLAYER) + 4), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                                WaitFrames(60);
                                break;
                            case 1:
                                PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
                                WaitFrames(5);
                                StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
                                MoveEntityYTo(ENTITY_PLAYER, Y(GetEntityY(ENTITY_PLAYER) + 4), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                                WaitFrames(20);
                                SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
                                WaitFrames(30);
                                SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
                                WaitFrames(30);
                                SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
                                WaitFrames(30);
                                SetEntityFacing(ENTITY_PLAYER, FACING_UP);
                                WaitFrames(10);
                                break;
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                            case 7:
                                TalkOpen();
                                TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_MidnightNoEventBedtimeAdvice);
                                break;
                        }
                    }
                    else
                    {
                        switch (RandomIntInclusive(0, 1))
                        {
                            case 0:
                                if (VarGet(VAR_HOUR) >= 4 && VarGet(VAR_HOUR) <= 6)
                                {
                                    TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_PredawnSleepAdvice);
                                }
                                else
                                {
                                    TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_LateNightBedtimeAdvice);
                                }
                                break;
                            case 1:
                                if (VarGet(VAR_HOUR) >= 22)
                                {
                                    TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_NightTimeLabel);
                                }
                                else
                                {
                                    if (VarGet(VAR_HOUR) <= 3)
                                    {
                                        TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_MidnightTimeLabel);
                                    }
                                    else
                                    {
                                        TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_PredawnSleepAdvice);
                                    }
                                }
                                break;
                        }
                    }
                }
                else
                {
                    if (VarGet(VAR_HOUR) <= 10)
                    {
                        switch (RandomIntInclusive(0, 1))
                        {
                            case 0:
                                TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_MorningMotivation);
                                break;
                            case 1:
                                TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_MorningTimeLabel);
                                break;
                        }
                    }
                    else
                    {
                        if (VarGet(VAR_HOUR) <= 15)
                        {
                            switch (RandomIntInclusive(0, 1))
                            {
                                case 0:
                                    TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_NoonWorkContinuationAdvice);
                                    break;
                                case 1:
                                    TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_NoonTimeLabel);
                                    break;
                            }
                        }
                        else
                        {
                            if (VarGet(VAR_HOUR) <= 17)
                            {
                                switch (RandomIntInclusive(0, 1))
                                {
                                    case 0:
                                        TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_EveningWorkContinuationAdvice);
                                        break;
                                    case 1:
                                        TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_EveningTimeLabel);
                                        break;
                                }
                            }
                            else
                            {
                                if (VarGet(VAR_HOUR) <= 19)
                                {
                                    switch (RandomIntInclusive(0, 1))
                                    {
                                        case 0:
                                            TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_DuskFinishWorkAdvice);
                                            break;
                                        case 1:
                                            TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_DuskTimeLabel);
                                            break;
                                    }
                                }
                                else
                                {
                                    switch (RandomIntInclusive(0, 1))
                                    {
                                        case 0:
                                            TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_NightQuitWorkAdvice);
                                            break;
                                        case 1:
                                            TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_NightTimeLabel);
                                            break;
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            case WEATHER_RAIN:
            case WEATHER_SNOW:
                if (VarGet(VAR_HOUR) < 6 || VarGet(VAR_HOUR) >= 22)
                {
                    TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_LateBadWeatherFatigueWarning);
                }
                else
                {
                    TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_BadWeatherToolUseFatigueWarning);
                }
                break;
            case WEATHER_TYPHOON:
                switch (RandomIntInclusive(0, 1))
                {
                    case 0:
                        TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_TyphoonStayIndoorsAdvice);
                        break;
                    case 1:
                        TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_StormWindHouseConcern);
                        break;
                }
                break;
            case WEATHER_SNOWSTORM:
                switch (RandomIntInclusive(0, 1))
                {
                    case 0:
                        TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_SnowstormStayIndoorsAdvice);
                        break;
                    case 1:
                        TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_StormWindHouseConcern);
                        break;
                }
                break;
        }
    }
    TalkClose();
}
