#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaRequestsAdviceAboutAja[] =
        "実は相談があるんだけど…{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaAsksWhatTroublesManna[] =
        "なんだい？{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaNamesAjaAsConcern[] =
        "アージュのことなんだよ…{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaSaysSheHasNeverMetAja[] =
        "ああ、マナの娘さん？\r\n"
        "わたしは見た事がないけど。{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaExplainsAjaLeftAfterArgumentWithDuke[] =
        "デュークとケンカになって\r\n"
        "家を飛び出したんだよ。{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaReactsToAjasDeparture[] =
        "そう…{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaAsksWhetherAjaKeepsInTouch[] =
        "アージュから連絡は\r\n"
        "あるのかい？{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaWantsAjaToReturnAndReconcile[] =
        "連絡はあるんだけどね。\r\n"
        "わたしとしては、\r\n"
        "一度帰ってきてゆっくり\r\n"
        "話し合って、\r\n"
        "あの子の考えを\r\n"
        "知りたいんだよ。\r\n"
        "今のままじゃいけないと\r\n"
        "思うし…{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaRespondsToMannasConcern[] =
        "そうだねぇ…{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaOffersToCallAja[] =
        "わかった、わたしがそれとなく\r\n"
        "アージュに言ってみるよ。{Press}\p"
        "こういうことは親が言うより、\r\n"
        "他人が言った方が\r\n"
        "素直に聞くもんさ。{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaSupportsSashasPlan[] =
        "そうよね。親がガミガミ\r\n"
        "言っても子供は逆にガンコに\r\n"
        "なるからねぇ。{Press}\p"
        "それがいいかもしれないわね。{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaThanksFriendsForAdvice[] =
        "ありがとう、\r\n"
        "サーシャ、アンナ。\r\n"
        "相談してよかったわ。\r\n"
        "胸につかえてたモヤモヤが\r\n"
        "晴れたよ。\r\n"
        "やっぱり、持つべきものは\r\n"
        "友達よね。{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaSaysFriendsHelpEachOther[] =
        "なに言ってるんだい。\r\n"
        "困ったときは、\r\n"
        "おたがいさまだよ。{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaReassuresManna[] =
        "そうよ。\r\n"
        "そんなに気にしないで。{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaThanksFriendsAgain[] =
        "ありがとう。{Press}";
};

void EventScript_NPCEvent_Manna_AjasDepartureAdviceFromFriends(void)
{
    ChangeMap(MAP_ROSE_SQUARE, X(341), Y(114));
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_SASHA, X(328), Y(81), FACING_DOWN);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_MANNA, X(328), Y(129), FACING_UP);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    SetEntityPosition(ENTITY_ANNA, X(359), Y(96), FACING_LEFT);
    SetEntityAnim(ENTITY_ANNA, ANIMATION_ANNA_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaRequestsAdviceAboutAja);
    TalkClose();
    StartEntityEffect(ENTITY_SASHA, ENTITY_EMOTE_QUESTION, FALSE);
    StartEntityEffect(ENTITY_ANNA, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaAsksWhatTroublesManna);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaNamesAjaAsConcern);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaSaysSheHasNeverMetAja);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaExplainsAjaLeftAfterArgumentWithDuke);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaReactsToAjasDeparture);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaAsksWhetherAjaKeepsInTouch);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaWantsAjaToReturnAndReconcile);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaRespondsToMannasConcern);
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaOffersToCallAja);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaSupportsSashasPlan);
    TalkClose();
    StartEntityEffect(ENTITY_MANNA, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaThanksFriendsForAdvice);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaSaysFriendsHelpEachOther);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaReassuresManna);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaThanksFriendsAgain);
    TalkClose();
    EnableScriptedNpcControl();
    PanCameraTo(X(220), Y(432), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    VarSet(VAR_MANNA_AJAS_DEPARTURE_ADVICE_FROM_FRIENDS_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    SetEntityEventScript(ENTITY_SASHA, EventScript_NPCEvent_Manna_AjasDepartureAdviceFromFriends_FollowupSashaDialogue);
    SetEntityEventScript(ENTITY_ANNA, EventScript_NPCEvent_Manna_AjasDepartureAdviceFromFriends_FollowupAnnaDialogue);
    SetEntityEventScript(ENTITY_MANNA, EventScript_NPCEvent_Manna_AjasDepartureAdviceFromFriends_FollowupMannaDialogue);
}
