#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_ThemeAnnouncement_JuiceTheme[] =
        "今回のお題はジュースです。\r\n"
        "おいしいジュースを期待して\r\n"
        "いますよ。{Press}";

    const char gText_FestivalEvent_CookingFestival_ThemeAnnouncement_DessertTheme[] =
        "今回のお題はお菓子です。\r\n"
        "子供が思わず飛びつきそうな\r\n"
        "お菓子が食べたいですね。{Press}";

    const char gText_FestivalEvent_CookingFestival_ThemeAnnouncement_BreadTheme[] =
        "今回のお題はパンです。\r\n"
        "ホッペが落ちそうなパンを\r\n"
        "焼いてもらいたいものです。{Press}";

    const char gText_FestivalEvent_CookingFestival_ThemeAnnouncement_NoodlesTheme[] =
        "今回のお題はうどんです。{Press}\r\n"
        "コシがつよくて、ノドごしの\r\n"
        "いいうどんが食べてみたい\r\n"
        "ですね。{Press}";

    const char gText_FestivalEvent_CookingFestival_ThemeAnnouncement_RiceTheme[] =
        "今回のお題はごはんです。\r\n"
        "ごはんを使った色々な料理を\r\n"
        "期待しています。{Press}";
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
