#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_CarterWeddingCongratulations[] =
        "You are marrying the \r\n"
        "Harvest Goddess!!\r\n"
        "Congratulations!{Press}";

    const char gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_HarvestGoddessWeddingVow[] =
        "I love you, \r\n"
        "{Player}. {Press}";

    const char gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_HarvestSpriteWeddingBlessing[] =
        "I think you will be happy \r\n"
        "together always. {Press}";

    const char gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_HarvestGoddessRequestsNickname[] =
        "We're married now, so \r\n"
        "you should tell me what\r\n"
        "to call you. {Press}";

    const char gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_NicknameChoicePrompt[] =
        "Well, {Player}, how\r\n"
        "do you want to be called? {Press}";

    const char gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_ChoicePlayerName[] =
        "Just my name";

    const char gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_ChoiceHoney[] =
        "Honey";

    const char gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_ChoiceDarling[] =
        "Darling";

    const char gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_ChoiceCustomNickname[] =
        "Other";

    const char gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_RejectsPlainNameChoice[] =
        "{Player} is \r\n"
        "a cute name, come to \r\n"
        "think of it. {Press}";

    const char gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_ConfirmsDefaultNickname[] =
        "So, from now on I'll call\r\n"
        "you {Player}. {Press}";

    const char gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_RejectsHoneyChoice[] =
        "That's not very much fun!\r\n"
        "I think I'll call you \r\n"
        "{Player} instead. {Press}";

    const char gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_RejectsDarlingChoice[] =
        "That makes me kind of \r\n"
        "embarrassed to say! I think \r\n"
        "{Player} is better.{Press}";

    const char gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_RequestsCustomNickname[] =
        "Something else is better? \r\n"
        "Like what?{Press}";

    const char gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_RejectsCustomNickname[] =
        "Somehow I don't think that\r\n"
        "fits you. How about \r\n"
        "{Player} instead?{Press}";

    const char gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_ExplainsDivineDutiesAndAbsence[] =
        "I forgot to tell you, but\r\n"
        "I’m very busy with Harvest\r\n"
        "Goddess duties. {Press}\p"
        "I won't be able to come\r\n"
        "home much, so you'll have\r\n"
        "to do everything, OK? {Press}";

    const char gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_DepartsAfterWedding[] =
        "Bye, now!{Press}";

    const char gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_PlayerWondersWhenSheWillReturn[] =
        ".......\r\n"
        "I wonder when she'll come \r\n"
        "home...?{Press}";
};

void EventScript_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection(void)
{
    int var_0;
    VarSet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    ChangeMap(MAP_CHURCH, X(184), Y(160));
    SetEntityPosition(ENTITY_PLAYER, X(168), Y(152), FACING_DOWN);
    PreparePlayerForScriptedAnimation();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WEDDING_IDLE);
    SetEntityPosition(ENTITY_HARVEST_GODDESS, X(200), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_HARVEST_GODDESS, ANIMATION_HARVEST_GODDESS_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(184), Y(120), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_STAID, X(104), Y(155), FACING_RIGHT);
    SetEntityAnim(ENTITY_STAID, ANIMATION_STAID_IDLE);
    SetEntityPosition(ENTITY_NAPPY, X(72), Y(195), FACING_RIGHT);
    SetEntityAnim(ENTITY_NAPPY, ANIMATION_NAPPY_IDLE);
    SetEntityPosition(ENTITY_BOLD, X(104), Y(195), FACING_RIGHT);
    SetEntityAnim(ENTITY_BOLD, ANIMATION_BOLD_IDLE);
    SetEntityPosition(ENTITY_CHEF, X(72), Y(155), FACING_RIGHT);
    SetEntityAnim(ENTITY_CHEF, ANIMATION_CHEF_IDLE);
    SetEntityPosition(ENTITY_AQUA, X(264), Y(155), FACING_LEFT);
    SetEntityAnim(ENTITY_AQUA, ANIMATION_AQUA_IDLE);
    SetEntityPosition(ENTITY_HOGGY, X(296), Y(155), FACING_LEFT);
    SetEntityAnim(ENTITY_HOGGY, ANIMATION_HOGGY_IDLE);
    SetEntityPosition(ENTITY_TIMID, X(264), Y(195), FACING_LEFT);
    SetEntityAnim(ENTITY_TIMID, ANIMATION_TIMID_IDLE);
    if (GetEntityLocation(ENTITY_CLIFF) == MAP_CHURCH)
    {
        HideEntity(ENTITY_CLIFF);
    }
    if (GetEntityLocation(ENTITY_JEFF) == MAP_CHURCH)
    {
        HideEntity(ENTITY_JEFF);
    }
    if (GetEntityLocation(ENTITY_DOCTOR) == MAP_CHURCH)
    {
        HideEntity(ENTITY_DOCTOR);
    }
    if (GetEntityLocation(ENTITY_DUKE) == MAP_CHURCH)
    {
        HideEntity(ENTITY_DUKE);
    }
    if (GetEntityLocation(ENTITY_MANNA) == MAP_CHURCH)
    {
        HideEntity(ENTITY_MANNA);
    }
    if (GetEntityLocation(ENTITY_POPURI) == MAP_CHURCH)
    {
        HideEntity(ENTITY_POPURI);
    }
    StopAllSongs();
    FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    PlaySong(AUDIO_START, AUDIO_SFX_CEREMONIAL_CHIME);
    WaitFrames(60 * 3);
    PlaySong(AUDIO_START, AUDIO_SFX_CEREMONIAL_CHIME);
    WaitFrames(60 * 3);
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_WEDDING);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_CarterWeddingCongratulations);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    SetEntityFacing(ENTITY_HARVEST_GODDESS, FACING_LEFT);
    StartEntityEffect(ENTITY_HARVEST_GODDESS, ENTITY_EMOTE_HEART, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    TalkMessage(gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_HarvestGoddessWeddingVow);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityFacing(ENTITY_HARVEST_GODDESS, FACING_DOWN);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CHEF_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CHEF);
    TalkMessage(gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_HarvestSpriteWeddingBlessing);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WEDDING_WALK);
    SetEntityAnim(ENTITY_HARVEST_GODDESS, ANIMATION_HARVEST_GODDESS_WEDDING_WALK);
    MoveEntityYTo(ENTITY_PLAYER, Y(179), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_HARVEST_GODDESS, Y(179), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    WaitForEntityMovement(ENTITY_HARVEST_GODDESS);
    SetEntityFacing(ENTITY_STAID, FACING_DOWN);
    SetEntityAnim(ENTITY_STAID, ANIMATION_STAID_WEDDING_CEREMONY);
    OffsetEntityPosition(ENTITY_STAID, X(0), Y(16));
    SetEntityFacing(ENTITY_CHEF, FACING_DOWN);
    SetEntityAnim(ENTITY_CHEF, ANIMATION_CHEF_WEDDING_CEREMONY);
    OffsetEntityPosition(ENTITY_CHEF, X(0), Y(16));
    SetEntityFacing(ENTITY_AQUA, FACING_DOWN);
    SetEntityAnim(ENTITY_AQUA, ANIMATION_AQUA_WEDDING_CEREMONY);
    OffsetEntityPosition(ENTITY_AQUA, X(0), Y(16));
    SetEntityFacing(ENTITY_HOGGY, FACING_DOWN);
    SetEntityAnim(ENTITY_HOGGY, ANIMATION_HOGGY_WEDDING_CEREMONY);
    OffsetEntityPosition(ENTITY_HOGGY, X(0), Y(16));
    PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
    MoveEntityYTo(ENTITY_PLAYER, Y(219), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_HARVEST_GODDESS, Y(219), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    WaitForEntityMovement(ENTITY_HARVEST_GODDESS);
    SetEntityFacing(ENTITY_NAPPY, FACING_DOWN);
    SetEntityAnim(ENTITY_NAPPY, ANIMATION_NAPPY_WEDDING_CEREMONY);
    OffsetEntityPosition(ENTITY_NAPPY, X(0), Y(16));
    SetEntityFacing(ENTITY_BOLD, FACING_DOWN);
    SetEntityAnim(ENTITY_BOLD, ANIMATION_BOLD_WEDDING_CEREMONY);
    OffsetEntityPosition(ENTITY_BOLD, X(0), Y(16));
    SetEntityFacing(ENTITY_TIMID, FACING_DOWN);
    SetEntityAnim(ENTITY_TIMID, ANIMATION_TIMID_WEDDING_CEREMONY);
    OffsetEntityPosition(ENTITY_TIMID, X(0), Y(16));
    MoveEntityYTo(ENTITY_PLAYER, Y(300), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityYTo(ENTITY_HARVEST_GODDESS, Y(300), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
    WaitFrames(60);
    OffsetEntityPosition(ENTITY_STAID, X(0), Y(16));
    OffsetEntityPosition(ENTITY_CHEF, X(0), Y(16));
    OffsetEntityPosition(ENTITY_AQUA, X(0), Y(16));
    OffsetEntityPosition(ENTITY_HOGGY, X(0), Y(16));
    OffsetEntityPosition(ENTITY_NAPPY, X(0), Y(16));
    OffsetEntityPosition(ENTITY_BOLD, X(0), Y(16));
    OffsetEntityPosition(ENTITY_TIMID, X(0), Y(16));
    PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
    WaitFrames(60);
    OffsetEntityPosition(ENTITY_STAID, X(0), Y(16));
    OffsetEntityPosition(ENTITY_CHEF, X(0), Y(16));
    OffsetEntityPosition(ENTITY_AQUA, X(0), Y(16));
    OffsetEntityPosition(ENTITY_HOGGY, X(0), Y(16));
    OffsetEntityPosition(ENTITY_NAPPY, X(0), Y(16));
    OffsetEntityPosition(ENTITY_BOLD, X(0), Y(16));
    OffsetEntityPosition(ENTITY_TIMID, X(0), Y(16));
    PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
    WaitFrames(60);
    OffsetEntityPosition(ENTITY_STAID, X(0), Y(16));
    OffsetEntityPosition(ENTITY_CHEF, X(0), Y(16));
    OffsetEntityPosition(ENTITY_AQUA, X(0), Y(16));
    OffsetEntityPosition(ENTITY_HOGGY, X(0), Y(16));
    OffsetEntityPosition(ENTITY_NAPPY, X(0), Y(16));
    OffsetEntityPosition(ENTITY_BOLD, X(0), Y(16));
    OffsetEntityPosition(ENTITY_TIMID, X(0), Y(16));
    AddNpcFriendship(CHARACTER_CARTER, 20);
    AddNpcFriendship(CHARACTER_STAID, 20);
    AddNpcFriendship(CHARACTER_NAPPY, 20);
    AddNpcFriendship(CHARACTER_BOLD, 20);
    AddNpcFriendship(CHARACTER_CHEF, 20);
    AddNpcFriendship(CHARACTER_AQUA, 20);
    AddNpcFriendship(CHARACTER_HOGGY, 20);
    AddNpcFriendship(CHARACTER_TIMID, 20);
    MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
    MarkNpcSpokenTo(CHARACTER_CARTER);
    MarkNpcSpokenTo(CHARACTER_STAID);
    MarkNpcSpokenTo(CHARACTER_NAPPY);
    MarkNpcSpokenTo(CHARACTER_BOLD);
    MarkNpcSpokenTo(CHARACTER_CHEF);
    MarkNpcSpokenTo(CHARACTER_AQUA);
    MarkNpcSpokenTo(CHARACTER_HOGGY);
    MarkNpcSpokenTo(CHARACTER_TIMID);
    WaitFrames(60);
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    RunStaffCredits();
    ChangeMap(MAP_FARMHOUSE, X(303), Y(148));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(303), Y(148), FACING_RIGHT);
    PreparePlayerForScriptedAnimation();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_HARVEST_GODDESS, X(331), Y(148), FACING_LEFT);
    SetEntityAnim(ENTITY_HARVEST_GODDESS, ANIMATION_HARVEST_GODDESS_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    TalkMessage(gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_HarvestGoddessRequestsNickname);
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
    TalkMessage(gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_NicknameChoicePrompt);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice4(gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_ChoicePlayerName, gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_ChoiceHoney, gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_ChoiceDarling, gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_ChoiceCustomNickname);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            TalkMessage(gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_RejectsPlainNameChoice);
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            TalkMessage(gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_ConfirmsDefaultNickname);
            TalkClose();
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            TalkMessage(gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_RejectsHoneyChoice);
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            TalkMessage(gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_ConfirmsDefaultNickname);
            TalkClose();
            break;
        case CHOICE_OPTION_3:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            TalkMessage(gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_RejectsDarlingChoice);
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            TalkMessage(gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_ConfirmsDefaultNickname);
            TalkClose();
            break;
        case CHOICE_OPTION_4:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            TalkMessage(gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_RequestsCustomNickname);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            OpenNameEntry(NAME_ENTRY_SPOUSE_NICKNAME, NAME_ENTRY_SINGLETON_SLOT);
            PreparePlayerForScriptedAnimation();
            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            TalkMessage(gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_RejectsCustomNickname);
            SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
            TalkMessage(gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_ConfirmsDefaultNickname);
            TalkClose();
            break;
    }
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    TalkMessage(gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_ExplainsDivineDutiesAndAbsence);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    TalkMessage(gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_DepartsAfterWedding);
    TalkClose();
    WaitFrames(60);
    PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
    SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, X(GetEntityX(ENTITY_HARVEST_GODDESS)), Y(GetEntityY(ENTITY_HARVEST_GODDESS) + 2), FACING_DOWN);
    SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ENTITY_AUX_RENDER_DISABLED);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0, ANIMATION_HARVEST_GODDESS_APPEAR_DISAPPEAR_EFFECT);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_0);
    HideEntity(ENTITY_HARVEST_GODDESS);
    WaitFrames(30);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    WaitFrames(30);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    VarSet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_WeddingEvent_HarvestGoddess_CeremonyAndNicknameSelection_PlayerWondersWhenSheWillReturn);
    TalkClose();
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
