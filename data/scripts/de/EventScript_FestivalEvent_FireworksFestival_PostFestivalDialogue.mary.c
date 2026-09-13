#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_IJustLoveFireworksTheyreSo[] =
        "Ich liebe Feuerwerke. \r\n"
        "Sie sind so schön, \r\n"
        "aber zu schnell vorbei. {Press}\p"
        "Die Farben sind auch \r\n"
        "so schön. Magisch. {Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_WasntTheFinaleGrandNobodyCould[] =
        "War das Finale nicht toll?\r\n"
        "Alle haben wie gebannt \r\n"
        "zugesehen. {Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ILoveWatchingFireworksFromMineral[] =
        "Ich liebe es, Feuerwerke\r\n"
        "vom Mineralstrand aus \r\n"
        "zu sehen. {Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_IWonderHowTheyMakeAll[] =
        "Wie sie wohl die ganzen\r\n"
        "Farben und Formen machen!{Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_RegretsFireworksEnded[] =
        "Schade, dass es \r\n"
        "vorbei ist!{Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_InTheTownIUsedTo[] =
        "In der Stadt, wo ich\r\n"
        "gewohnt habe, gab es \r\n"
        "ständig Feuerwerke. {Press}\p"
        "Irgendwie sind sie schö- \r\n"
        "ner, wenn man sie nur ein\r\n"
        "Mal im Jahr sieht. {Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ICantWaitUntilNextYear[] =
        "Ich freue mich schon \r\n"
        "auf nächstes Jahr! {Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_IUsedToBeAfraidOf[] =
        "Als Kind hatte ich \r\n"
        "Angst vor Feuerwerken.{Press}\p"
        "Jetzt finde ich sie gut,\r\n"
        "aber es sieht immer noch\r\n"
        "aus, als würde mir etwas {Press}\r\n"
        "auf den Kopf fallen!{Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ThatWasFunNowICan[] =
        "Das war ein Spaß! \r\n"
        "Nun kann ich morgen \r\n"
        "frisch an die Arbeit gehen!{Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_JustOnceAYearTheSky[] =
        "Nur einmal im Jahr \r\n"
        "wird der Himmel so\r\n"
        "bunt und laut...{Press}\p"
        "Ich frage mich immer, \r\n"
        "was die Fische denken!{Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_MyNeckHurtsFromLookingUp[] =
        "Mein Hals tut weh\r\n"
        "vom Hochsehen! \r\n"
        "Zeit zu gehen! {Press}";
};

void EventScript_FestivalEvent_FireworksFestival_PostFestivalDialogue(void)
{
    ChangeMap(MAP_MINERAL_BEACH, X(385), Y(124));
    PlayBGM(AUDIO_START_WEAK, AUDIO_AMBIENCE_BEACH);
    SetEntityPosition(ENTITY_PLAYER, X(385), Y(124), FACING_RIGHT);
    if (VarGet(VAR_FIREWORKS_FESTIVAL_PARTNER) == FESTIVAL_FIREWORKS_PARTNER_KAREN)
    {
        SetEntityPosition(ENTITY_KAREN, X(385), Y(142), FACING_RIGHT);
        SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    }
    else
    {
        if (VarGet(VAR_FIREWORKS_FESTIVAL_PARTNER) == FESTIVAL_FIREWORKS_PARTNER_POPURI)
        {
            SetEntityPosition(ENTITY_POPURI, X(385), Y(142), FACING_RIGHT);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
        }
        else
        {
            if (VarGet(VAR_FIREWORKS_FESTIVAL_PARTNER) == FESTIVAL_FIREWORKS_PARTNER_MARY)
            {
                SetEntityPosition(ENTITY_MARY, X(385), Y(142), FACING_RIGHT);
                SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
            }
            else
            {
                if (VarGet(VAR_FIREWORKS_FESTIVAL_PARTNER) == FESTIVAL_FIREWORKS_PARTNER_ELLI)
                {
                    SetEntityPosition(ENTITY_ELLI, X(385), Y(142), FACING_RIGHT);
                    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
                }
                else
                {
                    if (VarGet(VAR_FIREWORKS_FESTIVAL_PARTNER) == FESTIVAL_FIREWORKS_PARTNER_ANN)
                    {
                        SetEntityPosition(ENTITY_ANN, X(385), Y(142), FACING_RIGHT);
                        SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
                    }
                }
            }
        }
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
    WaitFrames(60 * 3);
    PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
    FlashScreenColor(31, 0, 0);
    PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
    WaitFrames(60 * 3);
    PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
    FlashScreenColor(0, 0, 31);
    PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
    WaitFrames(60 * 3);
    PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
    FlashScreenColor(0, 31, 0);
    if (VarGet(VAR_FIREWORKS_FESTIVAL_PARTNER) == FESTIVAL_FIREWORKS_PARTNER_KAREN)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        ShowTalkHeartIndicator(CHARACTER_KAREN);
        TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_IJustLoveFireworksTheyreSo);
        TalkClose();
        PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
        WaitFrames(60 * 3);
        PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
        FlashScreenColor(31, 0, 0);
        PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
        WaitFrames(60 * 3);
        PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
        FlashScreenColor(0, 0, 31);
        PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
        WaitFrames(60 * 3);
        PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
        FlashScreenColor(0, 31, 0);
        if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
        {
            SetEntityFacing(ENTITY_KAREN, FACING_UP);
            SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_WasntTheFinaleGrandNobodyCould);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ILoveWatchingFireworksFromMineral);
            TalkClose();
            DisableScriptedNpcControl();
            ClearEntityEventScript(ENTITY_ELLI);
            ClearEntityEventScript(ENTITY_DOCTOR);
            ClearEntityEventScript(ENTITY_GRAY);
            ClearEntityEventScript(ENTITY_ANN);
            ClearEntityEventScript(ENTITY_CLIFF);
            ClearEntityEventScript(ENTITY_KAREN);
            ClearEntityEventScript(ENTITY_KAI);
            ClearEntityEventScript(ENTITY_MARY);
            ClearEntityEventScript(ENTITY_RICK);
            ClearEntityEventScript(ENTITY_POPURI);
            VarSet(VAR_FIREWORKS_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
        }
        else
        {
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ILoveWatchingFireworksFromMineral);
            TalkClose();
            DisableScriptedNpcControl();
            DisableScriptedNpcControl();
            ClearEntityEventScript(ENTITY_ELLI);
            ClearEntityEventScript(ENTITY_DOCTOR);
            ClearEntityEventScript(ENTITY_GRAY);
            ClearEntityEventScript(ENTITY_ANN);
            ClearEntityEventScript(ENTITY_CLIFF);
            ClearEntityEventScript(ENTITY_KAREN);
            ClearEntityEventScript(ENTITY_KAI);
            ClearEntityEventScript(ENTITY_MARY);
            ClearEntityEventScript(ENTITY_RICK);
            ClearEntityEventScript(ENTITY_POPURI);
            VarSet(VAR_FIREWORKS_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
        }
    }
    else
    {
        if (VarGet(VAR_FIREWORKS_FESTIVAL_PARTNER) == FESTIVAL_FIREWORKS_PARTNER_POPURI)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_IWonderHowTheyMakeAll);
            TalkClose();
            PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
            WaitFrames(60 * 3);
            PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
            FlashScreenColor(31, 0, 0);
            PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
            WaitFrames(60 * 3);
            PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
            FlashScreenColor(0, 0, 31);
            PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
            WaitFrames(60 * 3);
            PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
            FlashScreenColor(0, 31, 0);
            if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                SetEntityFacing(ENTITY_POPURI, FACING_UP);
                SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                SetTalkNameplateCharacter(CHARACTER_POPURI);
                ShowTalkHeartIndicator(CHARACTER_POPURI);
                TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_RegretsFireworksEnded);
                TalkClose();
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                TalkOpen();
                TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ILoveWatchingFireworksFromMineral);
                TalkClose();
                DisableScriptedNpcControl();
                ClearEntityEventScript(ENTITY_ELLI);
                ClearEntityEventScript(ENTITY_DOCTOR);
                ClearEntityEventScript(ENTITY_GRAY);
                ClearEntityEventScript(ENTITY_ANN);
                ClearEntityEventScript(ENTITY_CLIFF);
                ClearEntityEventScript(ENTITY_KAREN);
                ClearEntityEventScript(ENTITY_KAI);
                ClearEntityEventScript(ENTITY_MARY);
                ClearEntityEventScript(ENTITY_RICK);
                ClearEntityEventScript(ENTITY_POPURI);
                VarSet(VAR_FIREWORKS_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
            }
            else
            {
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                TalkOpen();
                TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ILoveWatchingFireworksFromMineral);
                TalkClose();
                DisableScriptedNpcControl();
                ClearEntityEventScript(ENTITY_ELLI);
                ClearEntityEventScript(ENTITY_DOCTOR);
                ClearEntityEventScript(ENTITY_GRAY);
                ClearEntityEventScript(ENTITY_ANN);
                ClearEntityEventScript(ENTITY_CLIFF);
                ClearEntityEventScript(ENTITY_KAREN);
                ClearEntityEventScript(ENTITY_KAI);
                ClearEntityEventScript(ENTITY_MARY);
                ClearEntityEventScript(ENTITY_RICK);
                ClearEntityEventScript(ENTITY_POPURI);
                VarSet(VAR_FIREWORKS_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
            }
        }
        else
        {
            if (VarGet(VAR_FIREWORKS_FESTIVAL_PARTNER) == FESTIVAL_FIREWORKS_PARTNER_MARY)
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_MARY);
                ShowTalkHeartIndicator(CHARACTER_MARY);
                TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_InTheTownIUsedTo);
                TalkClose();
                PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
                WaitFrames(60 * 3);
                PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
                FlashScreenColor(31, 0, 0);
                PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
                WaitFrames(60 * 3);
                PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
                FlashScreenColor(0, 0, 31);
                PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
                WaitFrames(60 * 3);
                PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
                FlashScreenColor(0, 31, 0);
                if (VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    SetEntityFacing(ENTITY_MARY, FACING_UP);
                    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
                    SetTalkNameplateCharacter(CHARACTER_MARY);
                    ShowTalkHeartIndicator(CHARACTER_MARY);
                    TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ICantWaitUntilNextYear);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    TalkOpen();
                    TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ILoveWatchingFireworksFromMineral);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ELLI);
                    ClearEntityEventScript(ENTITY_DOCTOR);
                    ClearEntityEventScript(ENTITY_GRAY);
                    ClearEntityEventScript(ENTITY_ANN);
                    ClearEntityEventScript(ENTITY_CLIFF);
                    ClearEntityEventScript(ENTITY_KAREN);
                    ClearEntityEventScript(ENTITY_KAI);
                    ClearEntityEventScript(ENTITY_MARY);
                    ClearEntityEventScript(ENTITY_RICK);
                    ClearEntityEventScript(ENTITY_POPURI);
                    VarSet(VAR_FIREWORKS_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
                }
                else
                {
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    TalkOpen();
                    TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ILoveWatchingFireworksFromMineral);
                    TalkClose();
                    DisableScriptedNpcControl();
                    ClearEntityEventScript(ENTITY_ELLI);
                    ClearEntityEventScript(ENTITY_DOCTOR);
                    ClearEntityEventScript(ENTITY_GRAY);
                    ClearEntityEventScript(ENTITY_ANN);
                    ClearEntityEventScript(ENTITY_CLIFF);
                    ClearEntityEventScript(ENTITY_KAREN);
                    ClearEntityEventScript(ENTITY_KAI);
                    ClearEntityEventScript(ENTITY_MARY);
                    ClearEntityEventScript(ENTITY_RICK);
                    ClearEntityEventScript(ENTITY_POPURI);
                    VarSet(VAR_FIREWORKS_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
                }
            }
            else
            {
                if (VarGet(VAR_FIREWORKS_FESTIVAL_PARTNER) == FESTIVAL_FIREWORKS_PARTNER_ELLI)
                {
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
                    SetTalkNameplateCharacter(CHARACTER_ELLI);
                    ShowTalkHeartIndicator(CHARACTER_ELLI);
                    TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_IUsedToBeAfraidOf);
                    TalkClose();
                    PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
                    WaitFrames(60 * 3);
                    PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
                    FlashScreenColor(31, 0, 0);
                    PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
                    WaitFrames(60 * 3);
                    PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
                    FlashScreenColor(0, 0, 31);
                    PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
                    WaitFrames(60 * 3);
                    PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
                    FlashScreenColor(0, 31, 0);
                    if (VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                    {
                        SetEntityFacing(ENTITY_ELLI, FACING_UP);
                        SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        ShowTalkHeartIndicator(CHARACTER_ELLI);
                        TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ThatWasFunNowICan);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        TalkOpen();
                        TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ILoveWatchingFireworksFromMineral);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        ClearEntityEventScript(ENTITY_DOCTOR);
                        ClearEntityEventScript(ENTITY_GRAY);
                        ClearEntityEventScript(ENTITY_ANN);
                        ClearEntityEventScript(ENTITY_CLIFF);
                        ClearEntityEventScript(ENTITY_KAREN);
                        ClearEntityEventScript(ENTITY_KAI);
                        ClearEntityEventScript(ENTITY_MARY);
                        ClearEntityEventScript(ENTITY_RICK);
                        ClearEntityEventScript(ENTITY_POPURI);
                        VarSet(VAR_FIREWORKS_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
                    }
                    else
                    {
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        TalkOpen();
                        TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ILoveWatchingFireworksFromMineral);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        ClearEntityEventScript(ENTITY_DOCTOR);
                        ClearEntityEventScript(ENTITY_GRAY);
                        ClearEntityEventScript(ENTITY_ANN);
                        ClearEntityEventScript(ENTITY_CLIFF);
                        ClearEntityEventScript(ENTITY_KAREN);
                        ClearEntityEventScript(ENTITY_KAI);
                        ClearEntityEventScript(ENTITY_MARY);
                        ClearEntityEventScript(ENTITY_RICK);
                        ClearEntityEventScript(ENTITY_POPURI);
                        VarSet(VAR_FIREWORKS_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
                    }
                }
                else
                {
                    if (VarGet(VAR_FIREWORKS_FESTIVAL_PARTNER) == FESTIVAL_FIREWORKS_PARTNER_ANN)
                    {
                        TalkOpen();
                        VarSet(VAR_FIREWORKS_FESTIVAL_PARTNER, FESTIVAL_FIREWORKS_PARTNER_ANN);
                        SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
                        SetTalkNameplateCharacter(CHARACTER_ANN);
                        ShowTalkHeartIndicator(CHARACTER_ANN);
                        TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_JustOnceAYearTheSky);
                        TalkClose();
                        PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
                        WaitFrames(60 * 3);
                        PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
                        FlashScreenColor(31, 0, 0);
                        PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
                        WaitFrames(60 * 3);
                        PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
                        FlashScreenColor(0, 0, 31);
                        PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
                        WaitFrames(60 * 3);
                        PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
                        FlashScreenColor(0, 31, 0);
                        if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                        {
                            SetEntityFacing(ENTITY_ANN, FACING_UP);
                            SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
                            TalkOpen();
                            SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
                            SetTalkNameplateCharacter(CHARACTER_ANN);
                            ShowTalkHeartIndicator(CHARACTER_ANN);
                            TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_MyNeckHurtsFromLookingUp);
                            TalkClose();
                            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            TalkOpen();
                            TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ILoveWatchingFireworksFromMineral);
                            TalkClose();
                            DisableScriptedNpcControl();
                            ClearEntityEventScript(ENTITY_ELLI);
                            ClearEntityEventScript(ENTITY_DOCTOR);
                            ClearEntityEventScript(ENTITY_GRAY);
                            ClearEntityEventScript(ENTITY_ANN);
                            ClearEntityEventScript(ENTITY_CLIFF);
                            ClearEntityEventScript(ENTITY_KAREN);
                            ClearEntityEventScript(ENTITY_KAI);
                            ClearEntityEventScript(ENTITY_MARY);
                            ClearEntityEventScript(ENTITY_RICK);
                            ClearEntityEventScript(ENTITY_POPURI);
                            VarSet(VAR_FIREWORKS_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
                        }
                        else
                        {
                            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            TalkOpen();
                            TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ILoveWatchingFireworksFromMineral);
                            TalkClose();
                            DisableScriptedNpcControl();
                            ClearEntityEventScript(ENTITY_ELLI);
                            ClearEntityEventScript(ENTITY_DOCTOR);
                            ClearEntityEventScript(ENTITY_GRAY);
                            ClearEntityEventScript(ENTITY_ANN);
                            ClearEntityEventScript(ENTITY_CLIFF);
                            ClearEntityEventScript(ENTITY_KAREN);
                            ClearEntityEventScript(ENTITY_KAI);
                            ClearEntityEventScript(ENTITY_MARY);
                            ClearEntityEventScript(ENTITY_RICK);
                            ClearEntityEventScript(ENTITY_POPURI);
                            VarSet(VAR_FIREWORKS_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
                        }
                    }
                    else
                    {
                        PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
                        WaitFrames(60 * 3);
                        PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
                        FlashScreenColor(31, 0, 0);
                        PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
                        WaitFrames(60 * 3);
                        PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
                        FlashScreenColor(0, 0, 31);
                        PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_LAUNCH);
                        WaitFrames(60 * 3);
                        PlaySong(AUDIO_START, AUDIO_SFX_FIREWORK_EXPLOSION);
                        FlashScreenColor(0, 31, 0);
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        TalkOpen();
                        TalkMessage(gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ILoveWatchingFireworksFromMineral);
                        TalkClose();
                        DisableScriptedNpcControl();
                        ClearEntityEventScript(ENTITY_ELLI);
                        ClearEntityEventScript(ENTITY_DOCTOR);
                        ClearEntityEventScript(ENTITY_GRAY);
                        ClearEntityEventScript(ENTITY_ANN);
                        ClearEntityEventScript(ENTITY_CLIFF);
                        ClearEntityEventScript(ENTITY_KAREN);
                        ClearEntityEventScript(ENTITY_KAI);
                        ClearEntityEventScript(ENTITY_MARY);
                        ClearEntityEventScript(ENTITY_RICK);
                        ClearEntityEventScript(ENTITY_POPURI);
                        VarSet(VAR_FIREWORKS_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
                    }
                }
            }
        }
    }
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
