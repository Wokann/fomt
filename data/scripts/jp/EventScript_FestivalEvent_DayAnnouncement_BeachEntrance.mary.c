#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_DayAnnouncement_BeachEntrance_NewYearsFestivalAnnouncement[] =
        "やぁ、今日はＰＭ６：００から\r\n"
        "ここでもちつき大会が行われる\r\n"
        "んだよ。{Press}\p"
        "今はそのじゅんびをして\r\n"
        "いるんだ。{Press}\p"
        "キミも時間があったら、また\r\n"
        "ＰＭ６：００に来るといい。{Press}";

    const char gText_FestivalEvent_DayAnnouncement_BeachEntrance_SpringHorseRaceAnnouncement[] =
        "やぁ、今日はＡＭ１０：００\r\n"
        "からここで春の草競馬が行われ\r\n"
        "るんだよ。{Press}\p"
        "今はそのじゅんびをして\r\n"
        "いるんだ。{Press}\p"
        "キミも時間があったら、また\r\n"
        "ＡＭ１０：００に来るといい。{Press}";

    const char gText_FestivalEvent_DayAnnouncement_BeachEntrance_CookingFestivalThemeAnnouncement[] =
        "やぁ、今日はＡＭ１０：００\r\n"
        "からここで料理祭のお題発表が\r\n"
        "行われるんだよ。{Press}\p"
        "今はそのじゅんびをして\r\n"
        "いるんだ。{Press}\p"
        "キミも時間があったら、また\r\n"
        "ＡＭ１０：００に来るといい。{Press}";

    const char gText_FestivalEvent_DayAnnouncement_BeachEntrance_ChickenFestivalAnnouncement[] =
        "やぁ、今日はＡＭ１０：００\r\n"
        "からここで鶏祭りが行われるん\r\n"
        "だよ。{Press}\p"
        "今はそのじゅんびをして\r\n"
        "いるんだ。{Press}\p"
        "キミも時間があったら、また\r\n"
        "ＡＭ１０：００に来るといい。{Press}";

    const char gText_FestivalEvent_DayAnnouncement_BeachEntrance_CowFestivalAnnouncement[] =
        "やぁ、今日はＡＭ１０：００\r\n"
        "からここで牛祭りが行われるん\r\n"
        "だよ。{Press}\p"
        "今はそのじゅんびをして\r\n"
        "いるんだ。{Press}\p"
        "キミも時間があったら、また\r\n"
        "ＡＭ１０：００に来るといい。{Press}";

    const char gText_FestivalEvent_DayAnnouncement_BeachEntrance_HarvestFestivalAnnouncement[] =
        "やぁ、今日はＡＭ１０：００\r\n"
        "からここで収穫祭が行われるん\r\n"
        "だよ。{Press}\p"
        "今はそのじゅんびをして\r\n"
        "いるんだ。{Press}\p"
        "キミも時間があったら、また\r\n"
        "ＡＭ１０：００に来るといい。{Press}";

    const char gText_FestivalEvent_DayAnnouncement_BeachEntrance_FallHorseRaceAnnouncement[] =
        "やぁ、今日はＡＭ１０：００\r\n"
        "からここで秋の草競馬が行われ\r\n"
        "るんだよ。{Press}\p"
        "今はそのじゅんびをして\r\n"
        "いるんだ。{Press}\p"
        "キミも時間があったら、また\r\n"
        "ＡＭ１０：００に来るといい。{Press}";

    const char gText_FestivalEvent_DayAnnouncement_BeachEntrance_SheepFestivalAnnouncement[] =
        "やぁ、今日はＡＭ１０：００\r\n"
        "からここで羊祭りが行われるん\r\n"
        "だよ。{Press}\p"
        "今はそのじゅんびをして\r\n"
        "いるんだ。{Press}\p"
        "キミも時間があったら、また\r\n"
        "ＡＭ１０：００に来るといい。{Press}";

    const char gText_FestivalEvent_DayAnnouncement_BeachEntrance_YearEndFestivalAnnouncement[] =
        "やぁ、今日はＰＭ６：００から\r\n"
        "ここで年越しそばが行われるん\r\n"
        "だよ。{Press}\p"
        "今はそのじゅんびをして\r\n"
        "いるんだ。{Press}\p"
        "キミも時間があったら、また\r\n"
        "ＰＭ６：００に来るといい。{Press}";
};

void EventScript_FestivalEvent_DayAnnouncement_BeachEntrance(void)
{
    int var_0, var_1, var_2;
    ChangeMap(MAP_ROSE_SQUARE, X(456), Y(128));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_MINERAL_TOWN);
    SetEntityPosition(ENTITY_PLAYER, X(456), Y(128), FACING_LEFT);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_THOMAS, X(432), Y(128), FACING_RIGHT);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    var_0 = VarGet(VAR_SEASON);
    var_1 = VarGet(VAR_DAY);
    var_2 = VarGet(VAR_HOUR);
    VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    if (VarGet(VAR_NEW_YEAR_RICE_CAKE_FESTIVAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_01)
    {
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        TalkMessage(gText_FestivalEvent_DayAnnouncement_BeachEntrance_NewYearsFestivalAnnouncement);
        TalkClose();
        VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_MINERAL_BEACH, X(24), Y(280));
        SetEntityPosition(ENTITY_PLAYER, X(24), Y(280), FACING_RIGHT);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        return;
    }
    else
    {
        if (VarGet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_18)
        {
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
            TalkMessage(gText_FestivalEvent_DayAnnouncement_BeachEntrance_SpringHorseRaceAnnouncement);
            TalkClose();
            VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_MINERAL_BEACH, X(24), Y(280));
            SetEntityPosition(ENTITY_PLAYER, X(24), Y(280), FACING_RIGHT);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            return;
        }
        else
        {
            if (VarGet(VAR_COOKING_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_22)
            {
                TalkOpen();
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                TalkMessage(gText_FestivalEvent_DayAnnouncement_BeachEntrance_CookingFestivalThemeAnnouncement);
                TalkClose();
                VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                ChangeMap(MAP_MINERAL_BEACH, X(24), Y(280));
                SetEntityPosition(ENTITY_PLAYER, X(24), Y(280), FACING_RIGHT);
                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                return;
            }
            else
            {
                if (VarGet(VAR_CHICKEN_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_07)
                {
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_THOMAS);
                    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                    TalkMessage(gText_FestivalEvent_DayAnnouncement_BeachEntrance_ChickenFestivalAnnouncement);
                    TalkClose();
                    VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    ChangeMap(MAP_MINERAL_BEACH, X(24), Y(280));
                    SetEntityPosition(ENTITY_PLAYER, X(24), Y(280), FACING_RIGHT);
                    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    return;
                }
                else
                {
                    if (VarGet(VAR_COW_FESTIVAL_SESSION_STATE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_20)
                    {
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                        TalkMessage(gText_FestivalEvent_DayAnnouncement_BeachEntrance_CowFestivalAnnouncement);
                        TalkClose();
                        VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        ChangeMap(MAP_MINERAL_BEACH, X(24), Y(280));
                        SetEntityPosition(ENTITY_PLAYER, X(24), Y(280), FACING_RIGHT);
                        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        return;
                    }
                    else
                    {
                        if (VarGet(VAR_HARVEST_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_09)
                        {
                            TalkOpen();
                            SetTalkNameplateCharacter(CHARACTER_THOMAS);
                            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                            TalkMessage(gText_FestivalEvent_DayAnnouncement_BeachEntrance_HarvestFestivalAnnouncement);
                            TalkClose();
                            VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            ChangeMap(MAP_MINERAL_BEACH, X(24), Y(280));
                            SetEntityPosition(ENTITY_PLAYER, X(24), Y(280), FACING_RIGHT);
                            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            return;
                        }
                        else
                        {
                            if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_18)
                            {
                                TalkOpen();
                                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                                SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                                TalkMessage(gText_FestivalEvent_DayAnnouncement_BeachEntrance_FallHorseRaceAnnouncement);
                                TalkClose();
                                VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ChangeMap(MAP_MINERAL_BEACH, X(24), Y(280));
                                SetEntityPosition(ENTITY_PLAYER, X(24), Y(280), FACING_RIGHT);
                                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                return;
                            }
                            else
                            {
                                if (VarGet(VAR_SHEEP_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_21)
                                {
                                    TalkOpen();
                                    SetTalkNameplateCharacter(CHARACTER_THOMAS);
                                    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                                    TalkMessage(gText_FestivalEvent_DayAnnouncement_BeachEntrance_SheepFestivalAnnouncement);
                                    TalkClose();
                                    VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                    ChangeMap(MAP_MINERAL_BEACH, X(24), Y(280));
                                    SetEntityPosition(ENTITY_PLAYER, X(24), Y(280), FACING_RIGHT);
                                    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                    return;
                                }
                                else
                                {
                                    if (VarGet(VAR_NEW_YEARS_EVE_NOODLE_FESTIVAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_30)
                                    {
                                        TalkOpen();
                                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                                        TalkMessage(gText_FestivalEvent_DayAnnouncement_BeachEntrance_YearEndFestivalAnnouncement);
                                        TalkClose();
                                        VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                        ChangeMap(MAP_MINERAL_BEACH, X(24), Y(280));
                                        SetEntityPosition(ENTITY_PLAYER, X(24), Y(280), FACING_RIGHT);
                                        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
