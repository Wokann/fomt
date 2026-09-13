#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Elli_03_BlueHeart_EllenThanksPlayerForVisiting[] =
        "{Player}, \r\n"
        "thanks for coming. {Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliWelcomesPlayerHome[] =
        "Welcome to our house...{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_EllenEncouragesElli[] =
        "Cheer up, Elli! {Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliAcceptsEllensEncouragement[] =
        "If you say so...{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_EllenExplainsStuRanAwayAfterDinner[] =
        "Elli made dinner for Stu, \r\n"
        "but he said he didn't want\r\n"
        "to eat it and ran out!{Press}.........{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliWorriesInSilence[] =
        "……………{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_EllenRegretsUnableToSearch[] =
        "If I could use my legs, I'd\r\n"
        "go drag him back here\r\n"
        "myself, but...{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_EllenAsksPlayerToFindStu[] =
        "I know! Will you go get him\r\n"
        "for us, {Player}? {Press}\p"
        "He's probably near the \r\n"
        "Church. Well?{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ChoiceRefuseToFindStu[] =
        "Sorry, no.";

    const char gText_LoveEvent_Elli_03_BlueHeart_ChoiceAgreeToFindStu[] =
        "Sure, I'll do it.";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliAcceptsPlayersRefusal[] =
        "That's OK. I know \r\n"
        "nothing I make is good, \r\n"
        "anyway...{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_EllenReassuresElliAboutStu[] =
        "That's not true!\r\n"
        "I'm sure Stu'll come back\r\n"
        "soon!{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliRemainsWorried[] =
        "…………{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_StuReturnsAndApologizesToElli[] =
        "Sniff...sniff....\r\n"
        "I'm sorry, Sis...{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliForgivesStu[] =
        "I forgive you, Stu. {Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_EllenTellsStuElliForgivesHim[] =
        "Elli says she forgives you,\r\n"
        "so you can stop crying now,\r\n"
        "Stu. {Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_StuAcceptsReconciliation[] =
        "...OK.{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_EllenThanksPlayerForKindness[] =
        "Thanks! \r\n"
        "You're so nice, \r\n"
        "{Player}!{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_StuGreetsPlayerWhenFound[] =
        "Hi there!{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_StuRegretsHurtingElli[] =
        "I made my sis that sad?\r\n"
        "I'd better go back, then.{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_StuApologizesAfterReturning[] =
        "I'm sorry, Sis. {Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliForgivesStuAfterSearch[] =
        "That's OK, Stu. {Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_EllenThanksPlayerAfterStusReturn[] =
        "Thanks again, \r\n"
        "{Player}. {Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliThanksPlayerAndIntroducesGift[] =
        "Thanks, {Player}!\r\n"
        "Oh yeah...{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliHandsDriedFlowersToPlayer[] =
        "Here it is!{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliExplainsDriedFlowerGift[] =
        "I made these dried flowers. \r\n"
        "Why don't you take them as\r\n"
        "my thanks for helping us {Press}\r\n"
        "out today?{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliRelievedPlayerLikesGift[] =
        "Thank goodness. {Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_ElliPlansAnotherDinnerForStu[] =
        "Now that you're back, \r\n"
        "Stu, I'll fix you another \r\n"
        "big meal!{Press}";

    const char gText_LoveEvent_Elli_03_BlueHeart_StuDreadsAnotherDinner[] =
        "Ugh! No more! You don’t\r\n"
        "have to, Sis...{Press}";
};

void EventScript_LoveEvent_Elli_03_BlueHeart_FindStuAndReceiveDriedFlowers(void)
{
    int var_0;
    ChangeMap(MAP_ELLEN_HOUSE, X(120), Y(104));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(104), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_ELLI, X(136), Y(80), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_STU, X(120), Y(208), FACING_UP);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityPosition(ENTITY_ELLEN, X(120), Y(80), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLEN, ANIMATION_ELLEN_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_ELLI_BLUE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_EllenThanksPlayerForVisiting);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliWelcomesPlayerHome);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_EllenEncouragesElli);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliAcceptsEllensEncouragement);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_EllenExplainsStuRanAwayAfterDinner);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliWorriesInSilence);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_EllenRegretsUnableToSearch);
    SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ELLEN);
    TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_EllenAsksPlayerToFindStu);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Elli_03_BlueHeart_ChoiceRefuseToFindStu, gText_LoveEvent_Elli_03_BlueHeart_ChoiceAgreeToFindStu);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_ELLI, mary_negated_int(-2000));
            AddNpcFriendship(CHARACTER_ELLEN, mary_negated_int(-10));
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliAcceptsPlayersRefusal);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ELLEN);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_EllenReassuresElliAboutStu);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliRemainsWorried);
            TalkClose();
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_WALK);
            MoveEntityYTo(ENTITY_STU, Y(136), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_STU);
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
            StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_EXCLAMATION, FALSE);
            StartEntityEffect(ENTITY_ELLEN, ENTITY_EMOTE_EXCLAMATION, FALSE);
            WaitFrames(60);
            SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_CRYING);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_StuReturnsAndApologizesToElli);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliForgivesStu);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ELLEN);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_EllenTellsStuElliForgivesHim);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_StuAcceptsReconciliation);
            TalkClose();
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_ELLI);
            MarkNpcSpokenTo(CHARACTER_STU);
            MarkNpcSpokenTo(CHARACTER_ELLEN);
            SetEntityEventScript(ENTITY_ELLI, EventScript_LoveEvent_Elli_03_BlueHeart_FindStuAndReceiveDriedFlowers_FollowupElliDialogue);
            SetEntityEventScript(ENTITY_ELLEN, EventScript_LoveEvent_Elli_03_BlueHeart_FindStuAndReceiveDriedFlowers_FollowupEllenDialogue);
            SetEntityEventScript(ENTITY_STU, EventScript_LoveEvent_Elli_03_BlueHeart_FindStuAndReceiveDriedFlowers_FollowupStuDialogue);
            VarSet(VAR_ELLI_BLUE_HEART_EVENT_CHOICE, ELLI_BLUE_HEART_RESPONSE_REFUSE_TO_SEARCH);
            VarSet(VAR_ELLI_BLUE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
        case CHOICE_OPTION_2:
            AddCharacterLove(CHARACTER_ELLI, 3000);
            AddNpcFriendship(CHARACTER_ELLEN, 20);
            AddNpcFriendship(CHARACTER_STU, 20);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLEN);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_EllenThanksPlayerForKindness);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_NORTH_SIDE_TOWN, X(1264), Y(216));
            PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
            SetEntityPosition(ENTITY_PLAYER, X(1128), Y(216), FACING_RIGHT);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityPosition(ENTITY_STU, X(1264), Y(216), FACING_UP);
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
            if (GetEntityLocation(ENTITY_CARTER) == MAP_NORTH_SIDE_TOWN)
            {
                HideEntity(ENTITY_CARTER);
            }
            if (GetEntityLocation(ENTITY_DOCTOR) == MAP_NORTH_SIDE_TOWN)
            {
                HideEntity(ENTITY_DOCTOR);
            }
            if (GetEntityLocation(ENTITY_CLIFF) == MAP_NORTH_SIDE_TOWN)
            {
                HideEntity(ENTITY_CLIFF);
            }
            if (GetEntityLocation(ENTITY_ZACK) == MAP_NORTH_SIDE_TOWN)
            {
                HideEntity(ENTITY_ZACK);
            }
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
            MoveEntityXTo(ENTITY_PLAYER, X(1184), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityFacing(ENTITY_STU, FACING_LEFT);
            StartEntityEffect(ENTITY_STU, ENTITY_EMOTE_EXCLAMATION, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_StuGreetsPlayerWhenFound);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
            MoveEntityXTo(ENTITY_PLAYER, X(1224), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_StuRegretsHurtingElli);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_ELLEN_HOUSE, X(120), Y(80));
            PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
            SetEntityPosition(ENTITY_PLAYER, X(120), Y(120), FACING_UP);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityPosition(ENTITY_ELLI, X(136), Y(80), FACING_DOWN);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityPosition(ENTITY_STU, X(136), Y(120), FACING_UP);
            SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
            SetEntityPosition(ENTITY_ELLEN, X(120), Y(80), FACING_DOWN);
            SetEntityAnim(ENTITY_ELLEN, ANIMATION_ELLEN_IDLE);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_StuApologizesAfterReturning);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliForgivesStuAfterSearch);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLEN);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_EllenThanksPlayerAfterStusReturn);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliThanksPlayerAndIntroducesGift);
            TalkClose();
            SetEntityFacing(ENTITY_ELLI, FACING_RIGHT);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            MoveEntityXTo(ENTITY_ELLI, X(160), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityFacing(ENTITY_ELLI, FACING_UP);
            StartEntityEffect(ENTITY_ELLI, ENTITY_EMOTE_THINKING, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliHandsDriedFlowersToPlayer);
            TalkClose();
            SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            MoveEntityYTo(ENTITY_ELLI, Y(88), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityFacing(ENTITY_ELLI, FACING_LEFT);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            MoveEntityXTo(ENTITY_ELLI, X(120), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliExplainsDriedFlowerGift);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            ShowTalkHeartIndicator(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliRelievedPlayerLikesGift);
            TalkClose();
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
            MoveEntityYTo(ENTITY_ELLI, Y(96), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_ELLI);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_GESTURE);
            WaitFrames(60);
            SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_PREPARE_TO_HOLD_ITEM);
            PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
            SetPlayerHeldArticle(ITEM_ARTICLE_ELLIS_PRESSED_FLOWER);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ELLI);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_ElliPlansAnotherDinnerForStu);
            TalkClose();
            StartEntityEffect(ENTITY_STU, ENTITY_EMOTE_EXCLAMATION, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_LoveEvent_Elli_03_BlueHeart_StuDreadsAnotherDinner);
            TalkClose();
            PanCameraTo(X(120), Y(120), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
            WaitForCameraMovement();
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_ELLI);
            MarkNpcSpokenTo(CHARACTER_STU);
            MarkNpcSpokenTo(CHARACTER_ELLEN);
            SetEntityEventScript(ENTITY_ELLI, EventScript_LoveEvent_Elli_03_BlueHeart_FindStuAndReceiveDriedFlowers_FollowupElliDialogue);
            SetEntityEventScript(ENTITY_ELLEN, EventScript_LoveEvent_Elli_03_BlueHeart_FindStuAndReceiveDriedFlowers_FollowupEllenDialogue);
            SetEntityEventScript(ENTITY_STU, EventScript_LoveEvent_Elli_03_BlueHeart_FindStuAndReceiveDriedFlowers_FollowupStuDialogue);
            VarSet(VAR_ELLI_BLUE_HEART_EVENT_CHOICE, ELLI_BLUE_HEART_RESPONSE_HELP_FIND_STU);
            VarSet(VAR_ELLI_BLUE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
    }
}
