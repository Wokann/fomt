#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Mary_02_PurpleHeart_MarySearchesForMissingBook[] =
        "Das ist es nicht...\r\n"
        "Das auch nicht...\r\n"
        "Wo ist es hingekommen?{Press}";

    const char gText_LoveEvent_Mary_02_PurpleHeart_MaryStartledByPlayer[] =
        "Oh, {Player}!\r\n"
        "Du hast mich erschreckt!{Press}";

    const char gText_LoveEvent_Mary_02_PurpleHeart_MaryWelcomesPlayer[] =
        "Willkommen. Bist du\r\n"
        "zum Lesen gekommen?{Press}\r\n"
        "Hmm?\r\n"
        "Wonach ich suche?{Press}";

    const char gText_LoveEvent_Mary_02_PurpleHeart_MaryExplainsBookIsMissing[] =
        "Hm, da ist ein Buch, das\r\n"
        "ich als Inspiration für \r\n"
        "meinen Roman nehme.{Press}\p"
        "Dachte, es ist im 1. Stock,\r\n"
        "aber ich finde es nicht!{Press}";

    const char gText_LoveEvent_Mary_02_PurpleHeart_MaryAsksPlayerToHelpSearch[] =
        "Tut mir Leid, dass ich dich \r\n"
        "frage, aber hilfst du mir, \r\n"
        "{Player}?{Press}";

    const char gText_LoveEvent_Mary_02_PurpleHeart_ChoiceHelpFindBook[] =
        "Gerne.";

    const char gText_LoveEvent_Mary_02_PurpleHeart_ChoiceRefuseToHelp[] =
        "Keine Lust.";

    const char gText_LoveEvent_Mary_02_PurpleHeart_MaryThanksPlayerForHelping[] =
        "Wirklich!?\r\n"
        "Supernett von dir! \r\n"
        "Es ist die Art Buch...{Press}";

    const char gText_LoveEvent_Mary_02_PurpleHeart_MaryAssignsSearchArea[] =
        "OK, {Player}, \r\n"
        "du guckst da hinten. {Press}";

    const char gText_LoveEvent_Mary_02_PurpleHeart_MaryReportsBookNotFound[] =
        "Hier ist es nicht...\r\n"
        "Hast du es gefunden,\r\n"
        "{Player}?{Press}";

    const char gText_LoveEvent_Mary_02_PurpleHeart_MaryAsksPlayerToKeepSearching[] =
        "Kannst du noch ein wenig\r\n"
        "weitersuchen? Danke!{Press}";

    const char gText_LoveEvent_Mary_02_PurpleHeart_MaryFindsMissingBook[] =
        "Das ist es! \r\n"
        "Jetzt weiß ich wieder, \r\n"
        "ich habe es dahin getan! {Press}";

    const char gText_LoveEvent_Mary_02_PurpleHeart_MaryCanResumeWriting[] =
        "Jetzt kann ich weiter- \r\n"
        "schreiben! Ich stehe\r\n"
        "in deiner Schuld, {Press}\r\n"
        "{Player}! {Press}";

    const char gText_LoveEvent_Mary_02_PurpleHeart_MaryApologizesForRequest[] =
        "Tut mir Leid, um so einen \r\n"
        "ungewöhnlichen \r\n"
        "Gefallen zu bitten. {Press}\r\n"
        "Vergiss es einfach. {Press}";
};

void EventScript_LoveEvent_Mary_02_PurpleHeart_FindMissingBook(void)
{
    int var_0;
    ChangeMap(MAP_LIBRARY_1F, X(120), Y(76));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(144), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_MARY, X(120), Y(68), FACING_UP);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(60);
    SetEntityFacing(ENTITY_MARY, FACING_RIGHT);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    MoveEntityXTo(ENTITY_MARY, X(152), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityFacing(ENTITY_MARY, FACING_UP);
    WaitFrames(60);
    SetEntityFacing(ENTITY_MARY, FACING_LEFT);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    MoveEntityXTo(ENTITY_MARY, X(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityFacing(ENTITY_MARY, FACING_UP);
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_02_PurpleHeart_MarySearchesForMissingBook);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_PLAYER, Y(88), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_MARY, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_02_PurpleHeart_MaryStartledByPlayer);
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_02_PurpleHeart_MaryWelcomesPlayer);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(60);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_02_PurpleHeart_MaryExplainsBookIsMissing);
    TalkClose();
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    ShowTalkHeartIndicator(CHARACTER_MARY);
    TalkMessage(gText_LoveEvent_Mary_02_PurpleHeart_MaryAsksPlayerToHelpSearch);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Mary_02_PurpleHeart_ChoiceHelpFindBook, gText_LoveEvent_Mary_02_PurpleHeart_ChoiceRefuseToHelp);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_MARY, 3000);
            TalkClose();
            StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_HAPPY, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_02_PurpleHeart_MaryThanksPlayerForHelping);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_02_PurpleHeart_MaryAssignsSearchArea);
            TalkClose();
            SetEntityFacing(ENTITY_MARY, FACING_RIGHT);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
            MoveEntityXTo(ENTITY_MARY, X(152), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_MARY);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
            SetEntityFacing(ENTITY_MARY, FACING_UP);
            SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
            MoveEntityXTo(ENTITY_PLAYER, X(24), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
            MoveEntityYTo(ENTITY_PLAYER, Y(68), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            WaitFrames(60 * 2);
            SetEntityFacing(ENTITY_MARY, FACING_LEFT);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_SURPRISED);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_02_PurpleHeart_MaryReportsBookNotFound);
            TalkClose();
            SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_02_PurpleHeart_MaryAsksPlayerToKeepSearching);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
            MoveEntityXTo(ENTITY_MARY, X(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            MoveEntityXTo(ENTITY_PLAYER, X(56), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_MARY);
            WaitForEntityMovement(ENTITY_PLAYER);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityFacing(ENTITY_MARY, FACING_UP);
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            WaitFrames(60 * 2);
            StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
            PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
            SetPlayerHeldArticle(ITEM_ARTICLE_PLANT_ENCYCLOPEDIA);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            SetEntityFacing(ENTITY_MARY, FACING_LEFT);
            WaitFrames(60);
            StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_EXCLAMATION, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_02_PurpleHeart_MaryFindsMissingBook);
            TalkClose();
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
            MoveEntityXTo(ENTITY_MARY, X(72), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
            WaitForEntityMovement(ENTITY_MARY);
            SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
            WaitFrames(30);
            UsePlayerHeldItem();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_02_PurpleHeart_MaryCanResumeWriting);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_MARY);
            SetEntityEventScript(ENTITY_MARY, EventScript_LoveEvent_Mary_02_PurpleHeart_FindMissingBook_FollowupMaryDialogue);
            VarSet(VAR_MARY_PURPLE_HEART_EVENT_CHOICE, MARY_PURPLE_HEART_RESPONSE_HELP_FIND_BOOK);
            VarSet(VAR_MARY_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_MARY, mary_negated_int(-2000));
            TalkClose();
            StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_THINKING, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            ShowTalkHeartIndicator(CHARACTER_MARY);
            TalkMessage(gText_LoveEvent_Mary_02_PurpleHeart_MaryApologizesForRequest);
            TalkClose();
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_MARY);
            SetEntityEventScript(ENTITY_MARY, EventScript_LoveEvent_Mary_02_PurpleHeart_FindMissingBook_FollowupMaryDialogue);
            VarSet(VAR_MARY_PURPLE_HEART_EVENT_CHOICE, MARY_PURPLE_HEART_RESPONSE_REFUSE_TO_HELP);
            VarSet(VAR_MARY_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
    }
}
