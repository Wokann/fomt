#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_HighFatigueRestAdvice[] =
        "Ich sehe nicht gut aus...\r\n"
        "Ich sollte nicht arbeiten.\r\n"
        "Ruhe mich lieber aus.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_HighFatigueFoodRecoveryAdvice[] =
        "Ich sehe nicht gut aus...\r\n"
        "Ich esse besser etwas, um\r\n"
        "den Energieverlust auszu-{Press}\r\n"
        "gleichen.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_MidnightNoEventBedtimeAdvice[] =
        "Es ist schon spät.\r\n"
        "Ich sollte ins Bett gehen.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_PredawnSleepAdvice[] =
        "Es wird bald Morgen...\r\n"
        "Ich sollte wenigstens\r\n"
        "etwas schlafen.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_LateNightBedtimeAdvice[] =
        "Es wird spät.\r\n"
        "Warum gehst du \r\n"
        "nicht ins Bett?{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_NightTimeLabel[] =
        "Nacht\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_MidnightTimeLabel[] =
        "Mitternacht\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_MorningMotivation[] =
        "Ein weiterer schöner Tag!{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_MorningTimeLabel[] =
        "Morgen\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_NoonWorkContinuationAdvice[] =
        "Es ist noch Mittag. Ich\r\n"
        "sollte weiter arbeiten.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_NoonTimeLabel[] =
        "Mittag\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_EveningWorkContinuationAdvice[] =
        "Es ist noch Abend. Ich\r\n"
        "sollte weiter arbeiten.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_EveningTimeLabel[] =
        "Abend\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_DuskFinishWorkAdvice[] =
        "Es wird dunkel, ich\r\n"
        "sollte die Arbeit beenden.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_DuskTimeLabel[] =
        "Fast schon Nacht.\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_NightQuitWorkAdvice[] =
        "Es ist schon dunkel, ich\r\n"
        "sollte aufhören \r\n"
        "zu arbeiten.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_LateBadWeatherFatigueWarning[] =
        "Im schlechten Wetter ist\r\n"
        "der Energieverlust größer,\r\n"
        "aber spät arbeiten{Press}\r\n"
        "ist noch ungesünder!{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_BadWeatherToolUseFatigueWarning[] =
        "Wenn ich meine Werkzeuge\r\n"
        "in schlechtem Wetter be-\r\n"
        "nutze, ist der Energie- {Press}\r\n"
        "verlust höher - Vorsicht!{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_TyphoonStayIndoorsAdvice[] =
        "Ich kann bei einem\r\n"
        "Taifun nicht rausgehen.\r\n"
        "Schlafe ein wenig.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_StormWindHouseConcern[] =
        "Der Wind draußen wird\r\n"
        "schon zum Sturm. Hoffe,\r\n"
        "das Haus hält.{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_SnowstormStayIndoorsAdvice[] =
        "Bei so tiefem Schnee \r\n"
        "kann ich nicht raus. \r\n"
        "Schlafe ein wenig.{Press}";
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
