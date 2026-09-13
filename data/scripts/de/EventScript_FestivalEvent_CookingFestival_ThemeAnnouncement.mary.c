#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_ThemeAnnouncement_JuiceTheme[] =
        "Das Thema dieses \r\n"
        "Jahres ist Saft! Ich\r\n"
        "bin gespannt auf die {Press}\r\n"
        "Kreationen! {Press}";

    const char gText_FestivalEvent_CookingFestival_ThemeAnnouncement_DessertTheme[] =
        "Das Thema dieses  \r\n"
        "Jahres ist Dessert! \r\n"
        "Macht etwas {Press}\r\n"
        "Unwiderstehliches! {Press}";

    const char gText_FestivalEvent_CookingFestival_ThemeAnnouncement_BreadTheme[] =
        "Das Thema dieses \r\n"
        "Jahres ist Brot!  Macht \r\n"
        "gutes, frisches Brot! {Press}";

    const char gText_FestivalEvent_CookingFestival_ThemeAnnouncement_NoodlesTheme[] =
        "Das Thema dieses \r\n"
        "Jahres sind Nudeln! \r\n"
        "Ich warte auf {Press}\r\n"
        "unwiderstehliche Nudeln!{Press}";

    const char gText_FestivalEvent_CookingFestival_ThemeAnnouncement_RiceTheme[] =
        "Das Thema dieses \r\n"
        "ist Reis. Serviert uns\r\n"
        "kreative Reisgerichte! {Press}";
};

void EventScript_FestivalEvent_CookingFestival_ThemeAnnouncement(void)
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
