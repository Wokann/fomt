#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffAsksWherePlayerFoundPhoto[] =
        "！　これ、\r\n"
        "どこで見つけたんだ？{Press}";

    const char gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffLearnsAnnAndDougSawPhoto[] =
        "ああ…そうか\r\n"
        "お前がランちゃんたちに\r\n"
        "知らせてくれたんだよな…{Press}\p"
        "この写真に写っているのは…{Press}\p"
        "オレの母親と妹なんだ…{Press}";

    const char gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffExplainsLeavingHometownAfterFamilySeparated[] =
        "オレ…{Press}\p"
        "自分の住んでいる町が嫌で、\r\n"
        "母さんと妹をほうって\r\n"
        "町を出たんだよ…{Press}\p"
        "しばらくして戻ってみたら、\r\n"
        "母さんは死んで、\r\n"
        "妹もどこへ行ったのか{Press}\r\n"
        "分からなくなっていた…{Press}\p"
        "この町は、そのこきょうに\r\n"
        "にているんだよなぁ…{Press}";

    const char gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffApologizesForPersonalStory[] =
        "ごめん！\r\n"
        "こんな話、聞きたくないよな。\r\n"
        "写真、サンキュ。{Press}";
};

void EventScript_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_FollowupCliffDialogue(void)
{
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_HOSPITAL_BED_REACT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_COLLAPSED);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffAsksWherePlayerFoundPhoto);
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    TalkMessage(gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffLearnsAnnAndDougSawPhoto);
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_AFRAID);
    TalkMessage(gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffExplainsLeavingHometownAfterFamilySeparated);
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    TalkMessage(gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffApologizesForPersonalStory);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
    WaitFrames(60);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_HOSPITAL_BED_IDLE);
    VarSet(VAR_CLIFF_COLLAPSE_FOLLOWUP_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    AddNpcFriendship(CHARACTER_CLIFF, 20);
    MarkNpcSpokenTo(CHARACTER_CLIFF);
}
