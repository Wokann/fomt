#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0690_FestivalEvent_DayAnnouncement_SouthTownEntrance.mary.h"

void EventScript_0690_FestivalEvent_DayAnnouncement_SouthTownEntrance(void)
{
    int var_0, var_1, var_2;
    ChangeMap(MAP_ROSE_SQUARE, X(220), Y(432));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_MINERAL_TOWN);
    SetEntityPosition(ENTITY_PLAYER, X(220), Y(432), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_THOMAS, X(220), Y(408), FACING_DOWN);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    var_0 = VarGet(VAR_SEASON);
    var_1 = VarGet(VAR_DAY);
    var_2 = VarGet(VAR_HOUR);
    VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    if (VarGet(VAR_NEW_YEAR_RICE_CAKE_FESTIVAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_0 == SEASON_SPRING && var_1 == DAY_01)
    {
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        TalkMessage(gText_FestivalEvent_DayAnnouncement_SouthTownEntrance_NewYearsFestivalAnnouncement);
        TalkClose();
        VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_SOUTH_SIDE_TOWN, X(1272), Y(24));
        SetEntityPosition(ENTITY_PLAYER, X(1272), Y(24), FACING_DOWN);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        return;
    }
    else
    {
        if (VarGet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_SPRING && var_1 == DAY_18)
        {
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
            TalkMessage(gText_FestivalEvent_DayAnnouncement_SouthTownEntrance_SpringHorseRaceAnnouncement);
            TalkClose();
            VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_SOUTH_SIDE_TOWN, X(1272), Y(24));
            SetEntityPosition(ENTITY_PLAYER, X(1272), Y(24), FACING_DOWN);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            return;
        }
        else
        {
            if (VarGet(VAR_COOKING_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_SPRING && var_1 == DAY_22)
            {
                TalkOpen();
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                TalkMessage(gText_FestivalEvent_DayAnnouncement_SouthTownEntrance_CookingFestivalThemeAnnouncement);
                TalkClose();
                VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                ChangeMap(MAP_SOUTH_SIDE_TOWN, X(1272), Y(24));
                SetEntityPosition(ENTITY_PLAYER, X(1272), Y(24), FACING_DOWN);
                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                return;
            }
            else
            {
                if (VarGet(VAR_CHICKEN_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_SUMMER && var_1 == DAY_07)
                {
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_THOMAS);
                    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                    TalkMessage(gText_FestivalEvent_DayAnnouncement_SouthTownEntrance_ChickenFestivalAnnouncement);
                    TalkClose();
                    VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    ChangeMap(MAP_SOUTH_SIDE_TOWN, X(1272), Y(24));
                    SetEntityPosition(ENTITY_PLAYER, X(1272), Y(24), FACING_DOWN);
                    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    return;
                }
                else
                {
                    if (VarGet(VAR_COW_FESTIVAL_SESSION_STATE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_SUMMER && var_1 == DAY_20)
                    {
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                        TalkMessage(gText_FestivalEvent_DayAnnouncement_SouthTownEntrance_CowFestivalAnnouncement);
                        TalkClose();
                        VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        ChangeMap(MAP_SOUTH_SIDE_TOWN, X(1272), Y(24));
                        SetEntityPosition(ENTITY_PLAYER, X(1272), Y(24), FACING_DOWN);
                        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        return;
                    }
                    else
                    {
                        if (VarGet(VAR_HARVEST_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_FALL && var_1 == DAY_09)
                        {
                            TalkOpen();
                            SetTalkNameplateCharacter(CHARACTER_THOMAS);
                            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                            TalkMessage(gText_FestivalEvent_DayAnnouncement_SouthTownEntrance_HarvestFestivalAnnouncement);
                            TalkClose();
                            VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            ChangeMap(MAP_SOUTH_SIDE_TOWN, X(1272), Y(24));
                            SetEntityPosition(ENTITY_PLAYER, X(1272), Y(24), FACING_DOWN);
                            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            return;
                        }
                        else
                        {
                            if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_FALL && var_1 == DAY_18)
                            {
                                TalkOpen();
                                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                                SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                                TalkMessage(gText_FestivalEvent_DayAnnouncement_SouthTownEntrance_FallHorseRaceAnnouncement);
                                TalkClose();
                                VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ChangeMap(MAP_SOUTH_SIDE_TOWN, X(1272), Y(24));
                                SetEntityPosition(ENTITY_PLAYER, X(1272), Y(24), FACING_DOWN);
                                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                return;
                            }
                            else
                            {
                                if (VarGet(VAR_SHEEP_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_FALL && var_1 == DAY_21)
                                {
                                    TalkOpen();
                                    SetTalkNameplateCharacter(CHARACTER_THOMAS);
                                    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                                    TalkMessage(gText_FestivalEvent_DayAnnouncement_SouthTownEntrance_SheepFestivalAnnouncement);
                                    TalkClose();
                                    VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                    ChangeMap(MAP_SOUTH_SIDE_TOWN, X(1272), Y(24));
                                    SetEntityPosition(ENTITY_PLAYER, X(1272), Y(24), FACING_DOWN);
                                    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                    return;
                                }
                                else
                                {
                                    if (VarGet(VAR_NEW_YEARS_EVE_NOODLE_FESTIVAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_0 == SEASON_WINTER && var_1 == DAY_30)
                                    {
                                        TalkOpen();
                                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                                        TalkMessage(gText_FestivalEvent_DayAnnouncement_SouthTownEntrance_YearEndFestivalAnnouncement);
                                        TalkClose();
                                        VarSet(VAR_FESTIVAL_DAY_ANNOUNCEMENT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                        ChangeMap(MAP_SOUTH_SIDE_TOWN, X(1272), Y(24));
                                        SetEntityPosition(ENTITY_PLAYER, X(1272), Y(24), FACING_DOWN);
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
