#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Mary_01_BlackHeart_MaryWorriesAboutHerWriting[] =
        "Was ich damit wohl \r\n"
        "anfangen soll? Nein...Hmm.{Press}";

    const char gText_LoveEvent_Mary_01_BlackHeart_MaryApologizesForCollision[] =
        "Oh! \r\n"
        "Tut mir Leid, ich habe\r\n"
        "dich wirklich nicht gesehen.{Press}";

    const char gText_LoveEvent_Mary_01_BlackHeart_MaryAsksIfPlayerIsNew[] =
        "Ich habe dich noch nie \r\n"
        "gesehen... Bist du ein \r\n"
        "Tourist oder so?{Press}";

    const char gText_LoveEvent_Mary_01_BlackHeart_MaryRecognizesNewFarmer[] =
        "Oh, du bist der Neue\r\n"
        "auf der Farm...!{Press}\r\n"
        "Du bist, {Player}?\r\n"
        "Ich bin Mary. Schön,\r\n"
        "dich kennen zu lernen.{Press}";

    const char gText_LoveEvent_Mary_01_BlackHeart_MaryWelcomesPlayerToLibrary[] =
        "Hi, {Player}. \r\n"
        "Willkommen in \r\n"
        "der Bibliothek.{Press}";

    const char gText_LoveEvent_Mary_01_BlackHeart_MaryAppreciatesLibraryVisitor[] =
        "Es kommen nicht viele in\r\n"
        "die Bibliothek, schön, dass\r\n"
        "du gekommen bist!{Press}";

    const char gText_LoveEvent_Mary_01_BlackHeart_MaryApologizesAgain[] =
        "Tut mir Leid wegen eben...\r\n"
        "Wenn ich über etwas \r\n"
        "nachdenke, merke ich nichts.{Press}";

    const char gText_LoveEvent_Mary_01_BlackHeart_ChoiceOfferToHelpMary[] =
        "Kann ich dir helfen?";

    const char gText_LoveEvent_Mary_01_BlackHeart_ChoiceTellMaryToBeCareful[] =
        "Sei vorsichtig.";

    const char gText_LoveEvent_Mary_01_BlackHeart_MaryExplainsSheIsWritingNovel[] =
        "Ich schreibe einen \r\n"
        "Roman. Ich hatte nur so\r\n"
        "etwas wie eine Schreib-{Press}\r\n"
        "blockade - sonst nichts.{Press}";

    const char gText_LoveEvent_Mary_01_BlackHeart_MaryAcceptsPlayersHelp[] =
        "Lass mich wissen, wenn \r\n"
        "du etwas lesen willst.{Press}\p"
        "Ich wette, ich habe viele\r\n"
        "Bücher, die du magst!{Press}";

    const char gText_LoveEvent_Mary_01_BlackHeart_MaryAcceptsCautiousAdvice[] =
        "Ab jetzt versuche ich\r\n"
        "vorsichtiger zu sein. {Press}";
};

void EventScript_LoveEvent_Mary_01_BlackHeart_LibraryIntroduction(void)
{
    int var_0;
    ChangeMap(MAP_LIBRARY_1F, X(120), Y(144));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_MARY, X(216), Y(168), FACING_LEFT);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_PLAYER, Y(168), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryWorriesAboutHerWriting);
    TalkClose();
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    MoveEntityXTo(ENTITY_MARY, X(136), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryApologizesForCollision);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    if (HasMetNpc(CHARACTER_MARY) == FALSE)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_MARY);
        ShowTalkHeartIndicator(CHARACTER_MARY);
        TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryAsksIfPlayerIsNew);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_MARY);
        ShowTalkHeartIndicator(CHARACTER_MARY);
        TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryRecognizesNewFarmer);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_MARY);
        ShowTalkHeartIndicator(CHARACTER_MARY);
        TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryWelcomesPlayerToLibrary);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_MARY);
        ShowTalkHeartIndicator(CHARACTER_MARY);
        TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryAppreciatesLibraryVisitor);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryApologizesAgain);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Mary_01_BlackHeart_ChoiceOfferToHelpMary, gText_LoveEvent_Mary_01_BlackHeart_ChoiceTellMaryToBeCareful);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_MARY, 3000);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryExplainsSheIsWritingNovel);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryAcceptsPlayersHelp);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            MarkNpcSpokenTo(CHARACTER_MARY);
            SetEntityEventScript(ENTITY_MARY, EventScript_LoveEvent_Mary_01_BlackHeart_LibraryIntroduction_FollowupMaryDialogue);
            VarSet(VAR_MARY_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_01_BlackHeart_MaryAcceptsCautiousAdvice);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            MarkNpcSpokenTo(CHARACTER_MARY);
            SetEntityEventScript(ENTITY_MARY, EventScript_LoveEvent_Mary_01_BlackHeart_LibraryIntroduction_FollowupMaryDialogue);
            VarSet(VAR_MARY_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
    }
    EnableScriptedNpcControl();
}
