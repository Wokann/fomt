#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Duke_GrapeHarvestInvitation_DukeInvitesPlayerToGrapeHarvest[] =
        "おはよう、{Player}。\r\n"
        "明日、うちの果樹園で\r\n"
        "ワインにするぶどうを{Press}\r\n"
        "収穫するんだが、\r\n"
        "手伝ってくれねぇか？{Press}";

    const char gText_NPCEvent_Duke_GrapeHarvestInvitation_ChoiceAcceptHelp[] =
        "手伝う";

    const char gText_NPCEvent_Duke_GrapeHarvestInvitation_ChoiceDeclineHelp[] =
        "いそがしいからダメ";

    const char gText_NPCEvent_Duke_GrapeHarvestInvitation_DukeSchedulesTenAmPaidWork[] =
        "ありがとうよ。\r\n"
        "じゃあ明日１０時くらいに\r\n"
        "家に来てくれよ。{Press}\p"
        "もちろんバイト代は\r\n"
        "出すからよ。{Press}";

    const char gText_NPCEvent_Duke_GrapeHarvestInvitation_DukeAsksPlayerToInviteAnotherWorker[] =
        "そうだ。\r\n"
        "他にもだれか手伝ってくれる\r\n"
        "ヤツがいたら、{Press}\r\n"
        "さそっておいてくれよ。{Press}";

    const char gText_NPCEvent_Duke_GrapeHarvestInvitation_DukeAcceptsDeclineAndStillRequestsRecruitment[] =
        "そうか、お前も自分の仕事が\r\n"
        "あるからな。{Press}\p"
        "じゃ、他のやつに声を\r\n"
        "かけておいてくれよ。おまえも\r\n"
        "気が向いたら来てくれよ。{Press}";
};

void EventScript_NPCEvent_Duke_GrapeHarvestInvitation(void)
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
    SetEntityPosition(ENTITY_DUKE, X(228), Y(145), FACING_UP);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_NPCEvent_Duke_GrapeHarvestInvitation_DukeInvitesPlayerToGrapeHarvest);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_NPCEvent_Duke_GrapeHarvestInvitation_ChoiceAcceptHelp, gText_NPCEvent_Duke_GrapeHarvestInvitation_ChoiceDeclineHelp);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessage(gText_NPCEvent_Duke_GrapeHarvestInvitation_DukeSchedulesTenAmPaidWork);
            TalkClose();
            SetEntityFacing(ENTITY_DUKE, FACING_RIGHT);
            SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_WALK);
            MoveEntityXTo(ENTITY_DUKE, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_DUKE);
            SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
            WaitFrames(30);
            SetEntityFacing(ENTITY_DUKE, FACING_LEFT);
            SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessage(gText_NPCEvent_Duke_GrapeHarvestInvitation_DukeAsksPlayerToInviteAnotherWorker);
            TalkClose();
            SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_WALK);
            SetEntityFacing(ENTITY_DUKE, FACING_UP);
            MoveEntityYTo(ENTITY_DUKE, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_DUKE);
            HideEntity(ENTITY_DUKE);
            AddNpcFriendship(CHARACTER_DUKE, 20);
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DUKE);
            TalkMessage(gText_NPCEvent_Duke_GrapeHarvestInvitation_DukeAcceptsDeclineAndStillRequestsRecruitment);
            TalkClose();
            SetEntityFacing(ENTITY_DUKE, FACING_RIGHT);
            SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_WALK);
            MoveEntityXTo(ENTITY_DUKE, X(319), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_DUKE);
            SetEntityFacing(ENTITY_DUKE, FACING_UP);
            MoveEntityYTo(ENTITY_DUKE, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_DUKE);
            HideEntity(ENTITY_DUKE);
            AddNpcFriendship(CHARACTER_DUKE, mary_negated_int(-10));
            break;
    }
    VarSet(VAR_DUKE_GRAPE_HARVEST_INVITATION_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    MarkNpcSpokenTo(CHARACTER_DUKE);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
}
