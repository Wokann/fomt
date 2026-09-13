#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_DayAnnouncement_NorthTownEntrance_NewYearsFestivalAnnouncement[] =
        "Hier ist heute ab 18 Uhr\r\n"
        "das Neujahrsfestival. {Press}\p"
        "Ich mache mich gerade\r\n"
        "dafür fertig.{Press}\p"
        "Du solltest auch kommen. {Press}";

    const char gText_FestivalEvent_DayAnnouncement_NorthTownEntrance_SpringHorseRaceAnnouncement[] =
        "Hier sind heute ab 10 Uhr\r\n"
        "die Frühlings-Pferderennen.{Press}\p"
        "Ich mache mich gerade\r\n"
        "dafür fertig.{Press}\p"
        "Du solltest auch kommen. {Press}";

    const char gText_FestivalEvent_DayAnnouncement_NorthTownEntrance_CookingFestivalThemeAnnouncement[] =
        "Hier ist heute um 10 Uhr \r\n"
        "die Bekanntgabe des Themas \r\n"
        "des Kochwettbewerbs. {Press}\p"
        "Ich mache mich gerade\r\n"
        "dafür fertig.{Press}\p"
        "Du solltest auch kommen. {Press}";

    const char gText_FestivalEvent_DayAnnouncement_NorthTownEntrance_ChickenFestivalAnnouncement[] =
        "Heute ist hier das\r\n"
        "Hühnerfestival ab 10 Uhr.{Press}\p"
        "Ich mache mich gerade\r\n"
        "dafür fertig.{Press}\p"
        "Du solltest auch kommen. {Press}";

    const char gText_FestivalEvent_DayAnnouncement_NorthTownEntrance_CowFestivalAnnouncement[] =
        "Das Kuhfestival findet\r\n"
        "hier heute ab 10 Uhr statt. {Press}\p"
        "Ich mache mich gerade\r\n"
        "dafür fertig.{Press}\p"
        "Du solltest auch kommen. {Press}";

    const char gText_FestivalEvent_DayAnnouncement_NorthTownEntrance_HarvestFestivalAnnouncement[] =
        "Das Erntefestival findet \r\n"
        "hier heute ab 10 Uhr statt. {Press}\p"
        "Ich mache mich gerade\r\n"
        "dafür fertig.{Press}\p"
        "Du solltest auch kommen. {Press}";

    const char gText_FestivalEvent_DayAnnouncement_NorthTownEntrance_FallHorseRaceAnnouncement[] =
        "Ab 10 Uhr finden hier heute\r\n"
        "die Herbst-Pferderennen statt. {Press}\p"
        "Ich mache mich gerade\r\n"
        "dafür fertig.{Press}\p"
        "Du solltest auch kommen. {Press}";

    const char gText_FestivalEvent_DayAnnouncement_NorthTownEntrance_SheepFestivalAnnouncement[] =
        "Das Schaffestival findet\r\n"
        "hier heute ab 10 Uhr statt. {Press}\p"
        "Ich mache mich gerade\r\n"
        "dafür fertig.{Press}\p"
        "Du solltest auch kommen. {Press}";

    const char gText_FestivalEvent_DayAnnouncement_NorthTownEntrance_YearEndFestivalAnnouncement[] =
        "Das Jahresendfestival \r\n"
        "findet hier heute \r\n"
        "ab 18 Uhr statt.  {Press}\p"
        "Ich mache mich gerade\r\n"
        "dafür fertig.{Press}\p"
        "Du solltest auch kommen. {Press}";
};

void EventScript_FestivalEvent_DayAnnouncement_NorthTownEntrance(void)
{
    int var_0, var_1, var_2;
    ChangeMap(MAP_ROSE_SQUARE, X(220), Y(24));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_MINERAL_TOWN);
    SetEntityPosition(ENTITY_PLAYER, X(220), Y(24), FACING_DOWN);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_THOMAS, X(220), Y(48), FACING_UP);
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
        TalkMessage(gText_FestivalEvent_DayAnnouncement_NorthTownEntrance_NewYearsFestivalAnnouncement);
        TalkClose();
        VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_NORTH_SIDE_TOWN, X(1260), Y(688));
        SetEntityPosition(ENTITY_PLAYER, X(1260), Y(688), FACING_UP);
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
            TalkMessage(gText_FestivalEvent_DayAnnouncement_NorthTownEntrance_SpringHorseRaceAnnouncement);
            TalkClose();
            VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_NORTH_SIDE_TOWN, X(1260), Y(688));
            SetEntityPosition(ENTITY_PLAYER, X(1260), Y(688), FACING_UP);
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
                TalkMessage(gText_FestivalEvent_DayAnnouncement_NorthTownEntrance_CookingFestivalThemeAnnouncement);
                TalkClose();
                VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                ChangeMap(MAP_NORTH_SIDE_TOWN, X(1260), Y(688));
                SetEntityPosition(ENTITY_PLAYER, X(1260), Y(688), FACING_UP);
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
                    TalkMessage(gText_FestivalEvent_DayAnnouncement_NorthTownEntrance_ChickenFestivalAnnouncement);
                    TalkClose();
                    VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    ChangeMap(MAP_NORTH_SIDE_TOWN, X(1260), Y(688));
                    SetEntityPosition(ENTITY_PLAYER, X(1260), Y(688), FACING_UP);
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
                        TalkMessage(gText_FestivalEvent_DayAnnouncement_NorthTownEntrance_CowFestivalAnnouncement);
                        TalkClose();
                        VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        ChangeMap(MAP_NORTH_SIDE_TOWN, X(1260), Y(688));
                        SetEntityPosition(ENTITY_PLAYER, X(1260), Y(688), FACING_UP);
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
                            TalkMessage(gText_FestivalEvent_DayAnnouncement_NorthTownEntrance_HarvestFestivalAnnouncement);
                            TalkClose();
                            VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            ChangeMap(MAP_NORTH_SIDE_TOWN, X(1260), Y(688));
                            SetEntityPosition(ENTITY_PLAYER, X(1260), Y(688), FACING_UP);
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
                                TalkMessage(gText_FestivalEvent_DayAnnouncement_NorthTownEntrance_FallHorseRaceAnnouncement);
                                TalkClose();
                                VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ChangeMap(MAP_NORTH_SIDE_TOWN, X(1260), Y(688));
                                SetEntityPosition(ENTITY_PLAYER, X(1260), Y(688), FACING_UP);
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
                                    TalkMessage(gText_FestivalEvent_DayAnnouncement_NorthTownEntrance_SheepFestivalAnnouncement);
                                    TalkClose();
                                    VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                    ChangeMap(MAP_NORTH_SIDE_TOWN, X(1260), Y(688));
                                    SetEntityPosition(ENTITY_PLAYER, X(1260), Y(688), FACING_UP);
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
                                        TalkMessage(gText_FestivalEvent_DayAnnouncement_NorthTownEntrance_YearEndFestivalAnnouncement);
                                        TalkClose();
                                        VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                        ChangeMap(MAP_NORTH_SIDE_TOWN, X(1260), Y(688));
                                        SetEntityPosition(ENTITY_PLAYER, X(1260), Y(688), FACING_UP);
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
