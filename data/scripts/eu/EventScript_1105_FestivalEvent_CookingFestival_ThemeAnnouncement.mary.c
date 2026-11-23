#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1105_FestivalEvent_CookingFestival_ThemeAnnouncement.mary.h"

void EventScript_1105_FestivalEvent_CookingFestival_ThemeAnnouncement(void)
{
    if (HasMetNpc(CHARACTER_GOURMET) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_GOURMET);
    }
    SetEntityFacing(ENTITY_GOURMET, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GOURMET_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GOURMET);
    switch (VarGet(VAR_COOKING_FESTIVAL_DISH_CATEGORY))
    {
        case FESTIVAL_COOKING_DISH_CATEGORY_JUICE:
            TalkMessage(gText_FestivalEvent_CookingFestival_ThemeAnnouncement_JuiceTheme);
            break;
        case FESTIVAL_COOKING_DISH_CATEGORY_DESSERT:
            TalkMessage(gText_FestivalEvent_CookingFestival_ThemeAnnouncement_DessertTheme);
            break;
        case FESTIVAL_COOKING_DISH_CATEGORY_BREAD:
            TalkMessage(gText_FestivalEvent_CookingFestival_ThemeAnnouncement_BreadTheme);
            break;
        case FESTIVAL_COOKING_DISH_CATEGORY_NOODLES:
            TalkMessage(gText_FestivalEvent_CookingFestival_ThemeAnnouncement_NoodlesTheme);
            break;
        case FESTIVAL_COOKING_DISH_CATEGORY_RICE:
            TalkMessage(gText_FestivalEvent_CookingFestival_ThemeAnnouncement_RiceTheme);
            break;
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_GOURMET) == FALSE)
    {
        AddNpcFriendship(CHARACTER_GOURMET, 5);
    }
    MarkNpcSpokenTo(CHARACTER_GOURMET);
    SetEntityFacing(ENTITY_GOURMET, FACING_DOWN);
}
