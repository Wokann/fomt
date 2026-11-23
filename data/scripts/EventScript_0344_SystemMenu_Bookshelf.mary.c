#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0344_SystemMenu_Bookshelf.mary.h"

void EventScript_0344_SystemMenu_Bookshelf(void)
{
    int var_0;
    TalkOpen();
    var_0 = TalkChoice3(gText_SystemMenu_Bookshelf_MenuBooks, gText_SystemMenu_Bookshelf_MenuLetters, gText_SystemMenu_Bookshelf_Exit);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            OpenBookList();
            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            break;
        case CHOICE_OPTION_2:
            if (GetSavedLetterCount() == 0)
            {
                TalkAppendMessage(gText_SystemMenu_Bookshelf_NoLetterInside);
                TalkClose();
            }
            else
            {
                TalkClose();
                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                OpenLetterList();
                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            }
            break;
        case CHOICE_OPTION_3:
            TalkClose();
            break;
    }
}
