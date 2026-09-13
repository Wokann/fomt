#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_PlayerNoticesCarterMissing[] =
        "カーターさんがいない。\r\n"
        "どこにいったんだろう？{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_PlayerFindsChurchBackDoorOpen[] =
        "トビラが開いている…\r\n"
        "入ってみよう。{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterEnjoysAutumnMushroomGathering[] =
        "やはり、秋は最高ですね。\r\n"
        "お金のない、わたしでも\r\n"
        "ゼイタクが出来ますからね…{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterWorriesOthersWillDiscoverArea[] =
        "このことは、子供たちにも\r\n"
        "言えませんよ。\r\n"
        "ふっふっふっふっふっ…{Press}\r\n"
        "さあ、いただきますか。{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAsksWhyPlayerFollowed[] =
        "{Player}さん、\r\n"
        "どうしてここに？{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_PlayerSaysDoorWasOpen[] =
        "トビラが開いていた？\r\n"
        "わたしとしたことが\r\n"
        "ウッカリしていました…{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterExplainsGatheringMushrooms[] =
        "えっ、\r\n"
        "何をしていたかですって？{Press}\p"
        "そ…そうじですよ。\r\n"
        "そ…そう、ただのそうじです。{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAsksPlayerNotToJudge[] =
        "そんな目で\r\n"
        "見ないでくださいよ…{Press}\p"
        "わかりました。\r\n"
        "正直に言いますよ。{Press}\p"
        "実は、きのこを採りに\r\n"
        "来ていたのです。{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterExplainsBackAreaIsGoodForMushrooms[] =
        "昔から、ここにはきのこが\r\n"
        "生えましてね。{Press}\p"
        "秋になると\r\n"
        "食べられるのですよ。{Press}\p"
        "お金のない、わたしは、\r\n"
        "この季節が楽しみでしてね。{Press}\r\n"
        "唯一、ゼイタクが\r\n"
        "出来るのです。{Press}\p"
        "誰にも楽しみを\r\n"
        "とられたくないので、\r\n"
        "秘密にしていたのです。{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAsksPlayerToKeepMushroomSpotSecret[] =
        "{Player}さん、{Press}\p"
        "お願いですから\r\n"
        "秘密にしておいて\r\n"
        "もらえませんか？{Press}\p";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_ChoiceKeepSecret[] =
        "はい";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_ChoiceRefuseSecret[] =
        "いいえ";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterThanksPlayerForKeepingSecret[] =
        "ありがとうございます。\r\n"
        "お礼といってはなんですが、\r\n"
        "これから裏口のカギを{Press}\r\n"
        "この時間開けておきます。{Press}\p"
        "自由に出入りしても\r\n"
        "いいですよ。{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_SharedChoiceOutcomeCarterReturnsToMushrooms[] =
        "では、わたしはこれで…{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_SharedChoiceOutcomeBackDoorReminder[] =
        "カギは空けておきますから。{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAcceptsPlayersRefusalToKeepSecret[] =
        "やはり、そうですか…\r\n"
        "かくしごとはいけないこと\r\n"
        "ですからね。{Press}\p"
        "わかりました。\r\n"
        "これから裏口のカギを\r\n"
        "この時間開けておきます。{Press}\p"
        "自由に出入りしても\r\n"
        "いいですよ。{Press}";
};

void EventScript_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice(void)
{
    int var_0;
    ChangeMap(MAP_CHURCH, X(236), Y(95));
    SetEntityPosition(ENTITY_PLAYER, X(185), Y(212), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    if (GetEntityLocation(ENTITY_CARTER) == MAP_CHURCH)
    {
        HideEntity(ENTITY_CARTER);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(100), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    WaitFrames(30);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    WaitFrames(10);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    WaitFrames(30);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    WaitFrames(30);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_PlayerNoticesCarterMissing);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(309), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    WaitFrames(30);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(60), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_PlayerFindsChurchBackDoorOpen);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_BEHIND_CHURCH, X(140), Y(115));
    SetEntityPosition(ENTITY_PLAYER, X(140), Y(267), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_CARTER, X(140), Y(76), FACING_UP);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterEnjoysAutumnMushroomGathering);
    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterWorriesOthersWillDiscoverArea);
    TalkClose();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(135), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAsksWhyPlayerFollowed);
    SetTalkPortrait(TALK_PORTRAIT_CARTER_AFRAID);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_PlayerSaysDoorWasOpen);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterExplainsGatheringMushrooms);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAsksPlayerNotToJudge);
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterExplainsBackAreaIsGoodForMushrooms);
    SetTalkPortrait(TALK_PORTRAIT_CARTER_AFRAID);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAsksPlayerToKeepMushroomSpotSecret);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_ChoiceKeepSecret, gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_ChoiceRefuseSecret);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_HAPPY, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterThanksPlayerForKeepingSecret);
            SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
            TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_SharedChoiceOutcomeCarterReturnsToMushrooms);
            SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
            TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_SharedChoiceOutcomeBackDoorReminder);
            TalkClose();
            AddNpcFriendship(CHARACTER_CARTER, 20);
            SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_WALK);
            SetEntityFacing(ENTITY_CARTER, FACING_LEFT);
            MoveEntityXTo(ENTITY_CARTER, X(103), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_CARTER);
            SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
            MoveEntityYTo(ENTITY_CARTER, Y(253), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_CARTER);
            HideEntity(ENTITY_CARTER);
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_AFRAID, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_CARTER_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAcceptsPlayersRefusalToKeepSecret);
            SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
            TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_SharedChoiceOutcomeCarterReturnsToMushrooms);
            SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
            TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_SharedChoiceOutcomeBackDoorReminder);
            TalkClose();
            AddNpcFriendship(CHARACTER_CARTER, mary_negated_int(-10));
            SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_WALK);
            SetEntityFacing(ENTITY_CARTER, FACING_LEFT);
            MoveEntityXTo(ENTITY_CARTER, X(103), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_CARTER);
            SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
            MoveEntityYTo(ENTITY_CARTER, Y(253), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_CARTER);
            HideEntity(ENTITY_CARTER);
            break;
    }
    PanCameraTo(X(140), Y(135), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    MarkNpcSpokenTo(CHARACTER_CARTER);
    VarSet(VAR_CARTER_CHURCH_BACK_DOOR_MUSHROOM_SECRET_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
}
