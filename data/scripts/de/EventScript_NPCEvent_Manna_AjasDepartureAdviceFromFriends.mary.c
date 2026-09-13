#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaRequestsAdviceAboutAja[] =
        "Ich brauche deinen Rat\r\n"
        "für eine gewisse Sache...{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaAsksWhatTroublesManna[] =
        "Worum geht's?{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaNamesAjaAsConcern[] =
        "Es geht um Aja.{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaSaysSheHasNeverMetAja[] =
        "Deine Tochter?\r\n"
        "Ich habe sie nie gesehen.{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaExplainsAjaLeftAfterArgumentWithDuke[] =
        "Sie hat sich mit Duke\r\n"
        "gestritten und ist dann \r\n"
        "von zu Hause weggerannt.{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaReactsToAjasDeparture[] =
        "Wirklich...{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaAsksWhetherAjaKeepsInTouch[] =
        "Hörst du von ihr ?{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaWantsAjaToReturnAndReconcile[] =
        "Ab und zu hören \r\n"
        "wir von ihr. Ich wünschte,\r\n"
        "sie käme heim,\r\n"
        "sodass wir uns hinsetzen\r\n"
        "und alles klären können.\r\n"
        "So kann es nicht\r\n"
        "weitergehen.{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaRespondsToMannasConcern[] =
        "Es muss hart sein...{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaOffersToCallAja[] =
        "Ich habe eine Idee. \r\n"
        "Ich versuche, Aja zu \r\n"
        "überreden, nach Hause{Press}\r\n"
        "zu kommen.{Press}\p"
        "Manchmal funktionieren diese\r\n"
        "Dinge besser, wenn die\r\n"
        "Eltern sich raushalten. {Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaSupportsSashasPlan[] =
        "Das ist eine gute Idee. \r\n"
        "Wir würden sie wohl selber\r\n"
        "nur verjagen.{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaThanksFriendsForAdvice[] =
        "Danke, Sasha und Anna. \r\n"
        "Ich bin froh, dass ich das \r\n"
        "von meiner Seele habe.\r\n"
        "Freunde sind wirklich \r\n"
        "wichtig, nicht wahr? {Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_SashaSaysFriendsHelpEachOther[] =
        "Keine Ursache!\r\n"
        "Daf rüsind wir da!{Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaReassuresManna[] =
        "Ja. Wir helfen gerne. {Press}";

    const char gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaThanksFriendsAgain[] =
        "Danke noch mal. {Press}";
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
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaNamesAjaAsConcern);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_AnnaSaysSheHasNeverMetAja);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_Manna_AjasDepartureAdviceFromFriends_MannaExplainsAjaLeftAfterArgumentWithDuke);
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
