#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_HighFatigueRestAdvice[] =
        "なんだか顔色が凄く悪い…\r\n"
        "今日はもう仕事をしないで\r\n"
        "はやく寝た方がいいかも。{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_HighFatigueFoodRecoveryAdvice[] =
        "なんだか顔色が凄く悪い…\r\n"
        "何か疲労を回復させる物を\r\n"
        "食べた方がいいかも。{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_MidnightNoEventBedtimeAdvice[] =
        "今日はもう遅いから\r\n"
        "寝た方がいいかも。{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_PredawnSleepAdvice[] =
        "もう朝方だ…\r\n"
        "少しでも寝た方がいいかも。{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_NightTimeLabel[] =
        "夜。\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_MidnightTimeLabel[] =
        "深夜。\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_MorningMotivation[] =
        "今日も一日がんばろう。\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_MorningTimeLabel[] =
        "朝。\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_NoonWorkContinuationAdvice[] =
        "まだ昼間だからお仕事に\r\n"
        "戻った方がいいかも。{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_NoonTimeLabel[] =
        "昼。\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_EveningWorkContinuationAdvice[] =
        "まだ夕方だからお仕事に\r\n"
        "戻った方がいいかも。{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_EveningTimeLabel[] =
        "夕方。\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_DuskFinishWorkAdvice[] =
        "そろそろ暗くなってくるから\r\n"
        "お仕事終わった方がいいかも。{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_DuskTimeLabel[] =
        "そろそろ夜。\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_NightQuitWorkAdvice[] =
        "もう暗いから\r\n"
        "お仕事終わった方がいいかも。{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_LateBadWeatherFatigueWarning[] =
        "ただでさえ天気が悪くて疲労が\r\n"
        "たまりやすいのに、夜遅いから\r\n"
        "さらに疲労がたまりそう。{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_BadWeatherToolUseFatigueWarning[] =
        "天気が悪い時は道具を使ったら\r\n"
        "いつもより多めに疲労がたまり\r\n"
        "そうだから気をつけよう。{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_TyphoonStayIndoorsAdvice[] =
        "台風だから外に出られないし、\r\n"
        "おとなしく寝ておこう。\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_StormWindHouseConcern[] =
        "外はすごい風がふいている。\r\n"
        "この家は大丈夫かなぁ…\r\n"
        "{Press}";

    const char gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_SnowstormStayIndoorsAdvice[] =
        "大雪だから外に出られないし、\r\n"
        "おとなしく寝ておこう。\r\n"
        "{Press}";
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
                                    TalkMessage(gText_SystemEvent_PlayerConditionTimeAndWeatherMessages_MidnightNoEventBedtimeAdvice);
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
