#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_IJustLoveFireworksTheyreSo[] =
        "やっぱりさぁ、花火って\r\n"
        "いっしゅんだからいいんだろう\r\n"
        "ね。{Press}\p"
        "ほら、上がっている間にもどん\r\n"
        "どん形が変わっていって、\r\n"
        "目がはなせないよね。{Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_WasntTheFinaleGrandNobodyCould[] =
        "さいご、すごかったと\r\n"
        "思わない？みんなも、\r\n"
        "おおーってなってたよ。{Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ILoveWatchingFireworksFromMineral[] =
        "ミネラルビーチから見る\r\n"
        "花火はさいこうだ…{Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_IWonderHowTheyMakeAll[] =
        "花火って、どうしてあんなに\r\n"
        "いろんな色があるんだろう。{Press}\p"
        "…どっから見ても同じ形なのか\r\n"
        "なぁ？{Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_RegretsFireworksEnded[] =
        "終わっちゃったね…\r\n"
        "帰ろうか。{Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_InTheTownIUsedTo[] =
        "街にいたときは、やたら花火が\r\n"
        "あったよ。{Press}\p"
        "パレードとか、お正月とか、\r\n"
        "お祭りがあるといつも花火が\r\n"
        "ドドン、ドドンって上がるの。{Press}\p"
        "でも、海岸から見る花火が\r\n"
        "１番好きだな。{Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ICantWaitUntilNextYear[] =
        "楽しかったね、\r\n"
        "また来年もいっしょに来よう。{Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_IUsedToBeAfraidOf[] =
        "きれいねぇ。…わたし、小さい\r\n"
        "ころは何だか花火がこわ\r\n"
        "かったの。{Press}\p"
        "ああやって上がった後、\r\n"
        "おちてくる感じがして…\r\n"
        "でも、そんな感じしない？{Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_ThatWasFunNowICan[] =
        "はぁ、楽しかった。\r\n"
        "また明日から、気分を入れかえ\r\n"
        "て、しっかりお仕事しましょ。{Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_JustOnceAYearTheSky[] =
        "くらい夜空が、１年に１度だけ\r\n"
        "大きい音を出して明るく\r\n"
        "なって…{Press}\p"
        "海に住む生き物たちは何だと\r\n"
        "思っているんだろうねぇ。{Press}";

    const char gText_FestivalEvent_FireworksFestival_PostFestivalDialogue_MyNeckHurtsFromLookingUp[] =
        "ずっと上を向いてたら、\r\n"
        "クビがいたくなっちゃったよ。\r\n"
        "う～、はやく帰って休もう。{Press}";
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
