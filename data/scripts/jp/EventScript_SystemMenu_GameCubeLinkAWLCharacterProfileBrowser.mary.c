#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_NoProfilesUnlocked[] =
        "まだここには本がない。\r\n"
        "{Press}";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_PreviousPage[] =
        "前のページ";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterTakakura[] =
        "タカクラ";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterRomana[] =
        "ロマナ";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_NextPage[] =
        "次のページ";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterLumina[] =
        "ルミナ";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterSebastian[] =
        "セバスチャン";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterWally[] =
        "スアリー";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterChris[] =
        "クリス";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterHugh[] =
        "ヒュー";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterGrant[] =
        "グラート";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterSamantha[] =
        "サン";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterKate[] =
        "ケイト";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterGalen[] =
        "ガリ";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterNina[] =
        "ニーナ";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterDaryl[] =
        "ダリル";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterGustafa[] =
        "グスタファ";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterCody[] =
        "ゴーディ";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterKassey[] =
        "ケサラン";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterPatrick[] =
        "パサラン";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterMurrey[] =
        "モイ";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterTim[] =
        "テイ";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterLouOrRuby[] =
        "ルウ";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterNami[] =
        "ナミ";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterRock[] =
        "ロック";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterGriffin[] =
        "ガーファン";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterMuffy[] =
        "ムームー";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterCarter[] =
        "カーター";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterFlora[] =
        "フローラ";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterVesta[] =
        "ベスタ";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterMarlin[] =
        "マッシュ";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterCelia[] =
        "セピリア";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterHardy[] =
        "バドッグ";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterVan[] =
        "バァン";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterMooky[] =
        "ムクムク";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterNak[] =
        "デビッド";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterNic[] =
        "エボニー";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterFlak[] =
        "フラット";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterPlayer[] =
        "主人公";

    const char gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_ProfileNotUnlocked[] =
        "見当たらない…\r\n"
        "{Press}";
};

void EventScript_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser(void)
{
    int var_0, var_1, var_2;
    var_1 = 0;
    TalkOpen();
    if (VarGet(VAR_GAMECUBE_LINK_AWL_TAKAKURA_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_ROMANA_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_LUMINA_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_SEBASTIAN_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_WALLY_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_CHRIS_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_HUGH_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_GRANT_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_SAMANTHA_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_KATE_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_GALEN_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_NINA_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_DARYL_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_GUSTAFA_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_CODY_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_KASSEY_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_PATRICK_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_MURREY_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_TIM_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_LOU_OR_RUBY_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_NAMI_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_ROCK_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_GRIFFIN_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_MUFFY_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_CARTER_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_FLORA_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_VESTA_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_MARLIN_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_CELIA_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_HARDY_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_VAN_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_MOOKY_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_NAK_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_NIC_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_FLAK_PROFILE_LEVEL) == AWL_PROFILE_LOCKED && VarGet(VAR_GAMECUBE_LINK_AWL_PLAYER_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
    {
        TalkMessage(gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_NoProfilesUnlocked);
    }
    else
    {
        do
        {
            switch (var_1)
            {
                case 0:
                    var_0 = TalkChoice6(gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_PreviousPage, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterTakakura, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterRomana, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_NextPage, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterLumina, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterSebastian);
                    switch (var_0)
                    {
                        case CHOICE_OPTION_1:
                            var_1 = 8;
                            var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
                            break;
                        case CHOICE_OPTION_2:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_TAKAKURA_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_TAKAKURA);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_3:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_ROMANA_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_ROMANA);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_4:
                            var_1 = 1;
                            var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
                            break;
                        case CHOICE_OPTION_5:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_LUMINA_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_LUMINA);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_6:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_SEBASTIAN_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_SEBASTIAN);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                    }
                    break;
                case 1:
                    var_0 = TalkChoice6(gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_PreviousPage, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterWally, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterChris, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_NextPage, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterHugh, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterGrant);
                    switch (var_0)
                    {
                        case CHOICE_OPTION_1:
                            var_1 = 0;
                            var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
                            break;
                        case CHOICE_OPTION_2:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_WALLY_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_WALLY);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_3:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_CHRIS_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_CHRIS);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_4:
                            var_1 = 2;
                            var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
                            break;
                        case CHOICE_OPTION_5:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_HUGH_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_HUGH);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_6:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_GRANT_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_GRANT);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                    }
                    break;
                case 2:
                    var_0 = TalkChoice6(gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_PreviousPage, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterSamantha, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterKate, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_NextPage, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterGalen, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterNina);
                    switch (var_0)
                    {
                        case CHOICE_OPTION_1:
                            var_1 = 1;
                            var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
                            break;
                        case CHOICE_OPTION_2:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_SAMANTHA_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_SAMANTHA);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_3:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_KATE_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_KATE);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_4:
                            var_1 = 3;
                            var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
                            break;
                        case CHOICE_OPTION_5:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_GALEN_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_GALEN);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_6:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_NINA_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_NINA);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                    }
                    break;
                case 3:
                    var_0 = TalkChoice6(gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_PreviousPage, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterDaryl, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterGustafa, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_NextPage, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterCody, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterKassey);
                    switch (var_0)
                    {
                        case CHOICE_OPTION_1:
                            var_1 = 2;
                            var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
                            break;
                        case CHOICE_OPTION_2:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_DARYL_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_DARYL);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_3:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_GUSTAFA_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_GUSTAFA);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_4:
                            var_1 = 4;
                            var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
                            break;
                        case CHOICE_OPTION_5:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_CODY_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_CODY);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_6:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_KASSEY_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_KASSEY);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                    }
                    break;
                case 4:
                    var_0 = TalkChoice6(gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_PreviousPage, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterPatrick, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterMurrey, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_NextPage, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterTim, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterLouOrRuby);
                    switch (var_0)
                    {
                        case CHOICE_OPTION_1:
                            var_1 = 3;
                            var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
                            break;
                        case CHOICE_OPTION_2:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_PATRICK_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_PATRICK);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_3:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_MURREY_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_MURREY);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_4:
                            var_1 = 5;
                            var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
                            break;
                        case CHOICE_OPTION_5:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_TIM_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_TIM);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_6:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_LOU_OR_RUBY_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_LOU_OR_RUBY);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                    }
                    break;
                case 5:
                    var_0 = TalkChoice6(gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_PreviousPage, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterNami, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterRock, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_NextPage, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterGriffin, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterMuffy);
                    switch (var_0)
                    {
                        case CHOICE_OPTION_1:
                            var_1 = 4;
                            var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
                            break;
                        case CHOICE_OPTION_2:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_NAMI_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_NAMI);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_3:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_ROCK_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_ROCK);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_4:
                            var_1 = 6;
                            var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
                            break;
                        case CHOICE_OPTION_5:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_GRIFFIN_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_GRIFFIN);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_6:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_MUFFY_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_MUFFY);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                    }
                    break;
                case 6:
                    var_0 = TalkChoice6(gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_PreviousPage, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterCarter, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterFlora, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_NextPage, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterVesta, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterMarlin);
                    switch (var_0)
                    {
                        case CHOICE_OPTION_1:
                            var_1 = 5;
                            var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
                            break;
                        case CHOICE_OPTION_2:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_CARTER_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_CARTER);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_3:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_FLORA_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_FLORA);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_4:
                            var_1 = 7;
                            var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
                            break;
                        case CHOICE_OPTION_5:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_VESTA_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_VESTA);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_6:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_MARLIN_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_MARLIN);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                    }
                    break;
                case 7:
                    var_0 = TalkChoice6(gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_PreviousPage, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterCelia, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterHardy, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_NextPage, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterVan, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterMooky);
                    switch (var_0)
                    {
                        case CHOICE_OPTION_1:
                            var_1 = 6;
                            var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
                            break;
                        case CHOICE_OPTION_2:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_CELIA_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_CELIA);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_3:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_HARDY_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_HARDY);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_4:
                            var_1 = 8;
                            var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
                            break;
                        case CHOICE_OPTION_5:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_VAN_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_VAN);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_6:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_MOOKY_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_MOOKY);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                    }
                    break;
                case 8:
                    var_0 = TalkChoice6(gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_PreviousPage, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterNak, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterNic, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_NextPage, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterFlak, gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_CharacterPlayer);
                    switch (var_0)
                    {
                        case CHOICE_OPTION_1:
                            var_1 = 7;
                            var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
                            break;
                        case CHOICE_OPTION_2:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_NAK_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_NAK);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_3:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_NIC_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_NIC);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_4:
                            var_1 = 0;
                            var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
                            break;
                        case CHOICE_OPTION_5:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_FLAK_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_FLAK);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                        case CHOICE_OPTION_6:
                            if (VarGet(VAR_GAMECUBE_LINK_AWL_PLAYER_PROFILE_LEVEL) == AWL_PROFILE_LOCKED)
                            {
                                var_2 = AWL_PROFILE_MENU_PROFILE_LOCKED;
                            }
                            else
                            {
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                ShowReferencePage(REFERENCE_PAGE_AWL_PLAYER);
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_2 = AWL_PROFILE_MENU_PROFILE_DISPLAYED;
                            }
                            break;
                    }
                    break;
            }
            if (var_2 == AWL_PROFILE_MENU_PROFILE_LOCKED)
            {
                TalkMessage(gText_SystemMenu_GameCubeLinkAWLCharacterProfileBrowser_ProfileNotUnlocked);
                var_2 = AWL_PROFILE_MENU_CONTINUE_BROWSING;
            }
        }
        while (var_2 == AWL_PROFILE_MENU_CONTINUE_BROWSING);
    }
    TalkClose();
}
