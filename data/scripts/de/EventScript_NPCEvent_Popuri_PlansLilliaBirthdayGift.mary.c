#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackGreetsPlayer[] =
        "Hi, {Player}.{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackGreetsPopuri[] =
        "Hi, Popuri.{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriGreetsZack[] =
        "Hallo, Zack.\"{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriGreetsPlayer[] =
        "Hello, {Player}.{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriAsksAboutPackageArrival[] =
        "Sind die Pakete angekommen?{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackPresentsPackage[] =
        "Meinst du dies?{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriConfirmsPackage[] =
        "Ja, genau.{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackReassuresPackageWasRemembered[] =
        "Würde ich jemals dein \r\n"
        "Paket vergessen, Popuri?{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriThanksZackAndRequestsSecrecy[] =
        "Vielen Dank!\r\n"
        "Sag nur nichts zu Mutter.{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackAgreesToKeepBirthdayGiftSecret[] =
        "Natürlich nicht. \r\n"
        "Ich bin sicher, sie liebt\r\n"
        "die Überraschung.{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriAnticipatesSurprise[] =
        "Ich weiß. \r\n"
        "Ich kann es nicht erwarten!{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriExplainsMailOrderBirthdayGiftToPlayer[] =
        "Normalerweise bin ich\r\n"
        "nicht hier, aber ich wollte \r\n"
        "ein Geschenk für Mutter{Press}\r\n"
        "bestellen. Halte das geheim!{Press}\p"
        "Darum habe ich es Zack\r\n"
        "per Post bestellen lassen.{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriAsksPlayerToKeepSecret[] =
        "Was ist das?\r\n"
        "Kannst du ein Geheimnis\r\n"
        "bewahren?{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ChoicePromiseKeepSecret[] =
        "Natürlich!";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ChoiceRefuseSecret[] =
        "Ich denke nicht.";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriRequiresPromiseOfSecrecy[] =
        "OK. Schwöre, dass\r\n"
        "du es niemandem sagst! {Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriExplainsLilliasUpcomingBirthday[] =
        "Bald ist der Geburtstag\r\n"
        "meiner Mutter. {Press}\p"
        "Sie soll nicht wissen, das\r\n"
        "ich ihr etwas kaufe, also\r\n"
        "habe ich es eben bestellt.{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackRemindsPlayerNotToTellLillia[] =
        "Sag bloß Lillia nichts!{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriRefusesToExplainAfterPlayerDeclines[] =
        "Wenn das so ist,\r\n"
        "sage ich es dir nicht!{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackCriticizesPlayerForNotKeepingSecrets[] =
        "Ich sage es niemandem,\r\n"
        "der seinen Mund  \r\n"
        "nicht halten kann!{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriThanksZackAndLeaves[] =
        "Ich gehe jetzt nach Hause.\r\n"
        "Danke, Zack. {Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackInvitesPopuriBack[] =
        "Jederzeit, Popuri.{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriSaysGoodbye[] =
        "Tschüss!{Press}";
};

void EventScript_NPCEvent_Popuri_PlansLilliaBirthdayGift(void)
{
    int var_0;
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ZACK, X(176), Y(88), FACING_DOWN);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    SetEntityPosition(ENTITY_WON, X(192), Y(140), FACING_LEFT);
    SetEntityAnim(ENTITY_WON, ANIMATION_WON_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(176), Y(108), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(88), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    SetEntityFacing(ENTITY_ZACK, FACING_LEFT);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackGreetsPlayer);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(30);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_POPURI, X(120), Y(224), FACING_UP);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
    MoveEntityYTo(ENTITY_POPURI, Y(112), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
    MoveEntityXTo(ENTITY_POPURI, X(176), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityFacing(ENTITY_POPURI, FACING_UP);
    MoveEntityYTo(ENTITY_POPURI, Y(108), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityFacing(ENTITY_ZACK, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackGreetsPopuri);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriGreetsZack);
    SetEntityFacing(ENTITY_POPURI, FACING_LEFT);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_POPURI);
    }
    TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriGreetsPlayer);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
    WaitFrames(30);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityFacing(ENTITY_POPURI, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriAsksAboutPackageArrival);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackPresentsPackage);
    TalkClose();
    StartEntityEffect(ENTITY_POPURI, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriConfirmsPackage);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackReassuresPackageWasRemembered);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriThanksZackAndRequestsSecrecy);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackAgreesToKeepBirthdayGiftSecret);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriAnticipatesSurprise);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_POPURI, FACING_LEFT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_POPURI);
    }
    TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriExplainsMailOrderBirthdayGiftToPlayer);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_POPURI);
    }
    TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriAsksPlayerToKeepSecret);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ChoicePromiseKeepSecret, gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ChoiceRefuseSecret);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_POPURI);
            }
            TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriRequiresPromiseOfSecrecy);
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_POPURI);
            }
            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
            TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriExplainsLilliasUpcomingBirthday);
            TalkClose();
            SetEntityFacing(ENTITY_ZACK, FACING_LEFT);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ZACK_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_ZACK);
            TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackRemindsPlayerNotToTellLillia);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(30);
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            }
            AddNpcFriendship(CHARACTER_POPURI, 20);
            AddNpcFriendship(CHARACTER_ZACK, 20);
            break;
        case CHOICE_OPTION_2:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_POPURI);
            }
            TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriRefusesToExplainAfterPlayerDeclines);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ZACK_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_ZACK);
            TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackCriticizesPlayerForNotKeepingSecrets);
            TalkClose();
            AddNpcFriendship(CHARACTER_POPURI, mary_negated_int(-10));
            AddNpcFriendship(CHARACTER_ZACK, mary_negated_int(-10));
            break;
    }
    SetEntityFacing(ENTITY_POPURI, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriThanksZackAndLeaves);
    TalkClose();
    SetEntityFacing(ENTITY_ZACK, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackInvitesPopuriBack);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriSaysGoodbye);
    TalkClose();
    SetEntityFacing(ENTITY_POPURI, FACING_LEFT);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
    MoveEntityXTo(ENTITY_POPURI, X(148), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
    MoveEntityYTo(ENTITY_POPURI, Y(160), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityFacing(ENTITY_POPURI, FACING_LEFT);
    MoveEntityXTo(ENTITY_POPURI, X(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
    MoveEntityYTo(ENTITY_POPURI, Y(224), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    HideEntity(ENTITY_POPURI);
    MarkNpcSpokenTo(CHARACTER_POPURI);
    MarkNpcSpokenTo(CHARACTER_ZACK);
    VarSet(VAR_POPURI_PLANS_LILLIA_BIRTHDAY_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    PanCameraTo(X(120), Y(88), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    return;
}
