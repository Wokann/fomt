#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackGreetsPlayer[] =
        "よお、{Player}。\r\n"
        "{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackGreetsPopuri[] =
        "おっ、ポプリちゃん。\r\n"
        "{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriGreetsZack[] =
        "こんにちは。\r\n"
        "{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriGreetsPlayer[] =
        "{Player}さんも\r\n"
        "来てたんだ。{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriAsksAboutPackageArrival[] =
        "ザクさん、荷物来てる？\r\n"
        "{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackPresentsPackage[] =
        "おう、これだろ？\r\n"
        "{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriConfirmsPackage[] =
        "あ、これこれ。\r\n"
        "{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackReassuresPackageWasRemembered[] =
        "苦労したんだぜ。\r\n"
        "{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriThanksZackAndRequestsSecrecy[] =
        "ザクさん、ありがとう。\r\n"
        "お母さんには黙っていてね。{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackAgreesToKeepBirthdayGiftSecret[] =
        "わかってるって、\r\n"
        "リリアさんの喜ぶ顔が\r\n"
        "目に浮かぶなぁ。{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriAnticipatesSurprise[] =
        "うん、それが楽しみなんだ。\r\n"
        "{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriExplainsMailOrderBirthdayGiftToPlayer[] =
        "ここにいるのがめずらしい\r\n"
        "って？{Press}\p"
        "家に持ってこられたくないもの\r\n"
        "だったから、{Press}\p"
        "ザクさんに頼んでた通信販売の\r\n"
        "品を取りに来たの。{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriAsksPlayerToKeepSecret[] =
        "えっ、何を買ったかって？\r\n"
        "うーん…　{Player}さん、\r\n"
        "誰にも言わない？{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ChoicePromiseKeepSecret[] =
        "はい";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ChoiceRefuseSecret[] =
        "いいえ";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriRequiresPromiseOfSecrecy[] =
        "そう？\r\n"
        "絶対に言っちゃダメよ？\r\n"
        "じゃあ、教えてあげる。{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriExplainsLilliasUpcomingBirthday[] =
        "あと少しで、お母さんの誕生日\r\n"
        "なんだ。{Press}\p"
        "それでね、\r\n"
        "この町でプレゼントを買ったら\r\n"
        "バレちゃうじゃない？{Press}\p"
        "で、通信販売でプレゼントを\r\n"
        "買うことにしたのよ。{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackRemindsPlayerNotToTellLillia[] =
        "絶対リリアさんには秘密だぜ！\r\n"
        "{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriRefusesToExplainAfterPlayerDeclines[] =
        "じゃあ、ダメ！\r\n"
        "{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackCriticizesPlayerForNotKeepingSecrets[] =
        "そうだな。そんな口の軽いやつ\r\n"
        "には教えられねぇな。{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriThanksZackAndLeaves[] =
        "じゃあ、帰るね。\r\n"
        "ザクさん、ありがとうね。{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_ZackInvitesPopuriBack[] =
        "おう、しっかりやれよ。\r\n"
        "{Press}";

    const char gText_NPCEvent_Popuri_PlansLilliaBirthdayGift_PopuriSaysGoodbye[] =
        "うん！\r\n"
        "{Press}";
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
