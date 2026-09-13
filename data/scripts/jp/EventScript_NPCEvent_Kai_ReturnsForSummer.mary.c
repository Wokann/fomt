#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Kai_ReturnsForSummer_MayRecognizesKai[] =
        "カイお兄ちゃんだ！！{Press}";

    const char gText_NPCEvent_Kai_ReturnsForSummer_PopuriWelcomesKaiAndMarksStartOfSummer[] =
        "ひさしぶりね、カイ。\r\n"
        "カイが、この町に\r\n"
        "やって来ると、{Press}\p"
        "夏になったんだな、\r\n"
        "って思うわ。{Press}";

    const char gText_NPCEvent_Kai_ReturnsForSummer_KaiInvitesEveryoneToBeachHouseOpening[] =
        "ああ。海の家は、\r\n"
        "あさってからだからさ、\r\n"
        "よかったら来てよ。{Press}";

    const char gText_NPCEvent_Kai_ReturnsForSummer_MayCheersForBeachHouse[] =
        "うん！！{Press}";

    const char gText_NPCEvent_Kai_ReturnsForSummer_PopuriSaysGoodbye[] =
        "じゃあね。{Press}";

    const char gText_NPCEvent_Kai_ReturnsForSummer_KaiIntroducesHimselfAndBeachHouseToPlayer[] =
        "あれ、こんにちは…\r\n"
        "たしか、前の年は\r\n"
        "いなかったよね。{Press}\p"
        "オレ、カイ。よろしく。{Press}\p"
        "ほら、海岸にちっちゃい店\r\n"
        "あるでしょ？\r\n"
        "あれがオレの店。{Press}\p"
        "夏の間だけだけど、\r\n"
        "よかったら来てよ。\r\n"
        "金はとるけどさ。{Press}\p"
        "…おこんなよ、じゃあな。{Press}";
};

void EventScript_NPCEvent_Kai_ReturnsForSummer(void)
{
    ChangeMap(MAP_SOUTH_SIDE_TOWN, X(104), Y(194));
    SetEntityPosition(ENTITY_PLAYER, X(104), Y(316), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_KAI, X(104), Y(163), FACING_RIGHT);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    SetEntityPosition(ENTITY_POPURI, X(135), Y(171), FACING_LEFT);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityPosition(ENTITY_MAY, X(135), Y(145), FACING_LEFT);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MAY);
    TalkMessage(gText_NPCEvent_Kai_ReturnsForSummer_MayRecognizesKai);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Kai_ReturnsForSummer_PopuriWelcomesKaiAndMarksStartOfSummer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Kai_ReturnsForSummer_KaiInvitesEveryoneToBeachHouseOpening);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MAY);
    TalkMessage(gText_NPCEvent_Kai_ReturnsForSummer_MayCheersForBeachHouse);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    TalkMessage(gText_NPCEvent_Kai_ReturnsForSummer_PopuriSaysGoodbye);
    TalkClose();
    WaitFrames(30);
    SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
    SetEntityFacing(ENTITY_MAY, FACING_RIGHT);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WALK);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_WALK);
    MoveEntityXTo(ENTITY_POPURI, X(299), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    MoveEntityXTo(ENTITY_MAY, X(299), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_POPURI);
    WaitForEntityMovement(ENTITY_MAY);
    HideEntity(ENTITY_POPURI);
    HideEntity(ENTITY_MAY);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(194), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityFacing(ENTITY_KAI, FACING_DOWN);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_NPCEvent_Kai_ReturnsForSummer_KaiIntroducesHimselfAndBeachHouseToPlayer);
    TalkClose();
    SetEntityFacing(ENTITY_KAI, FACING_RIGHT);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_WALK);
    MoveEntityXTo(ENTITY_KAI, X(299), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_KAI);
    HideEntity(ENTITY_KAI);
    MarkNpcSpokenTo(CHARACTER_KAI);
    AddNpcFriendship(CHARACTER_KAI, 20);
    VarSet(VAR_KAI_RETURNS_FOR_SUMMER_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
}
