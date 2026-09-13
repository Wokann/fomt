#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaAsksAboutRecipeStep[] =
        "...and then what do you\r\n"
        "put in? {Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaExplainsRecipeStep[] =
        "You put in...\r\n"
        "...then you use the...{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaReactsToRecipeTip[] =
        "I never would have\r\n"
        "thought of that!...{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaWelcomesPlayer[] =
        "Hi, {Player}.\r\n"
        "Come on in. {Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaGreetsPlayer[] =
        "Hi there, {Player}. {Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaExplainsCookingLesson[] =
        "What were we doing? \r\n"
        "Anna was just teaching me\r\n"
        "how to make desserts. {Press}\p"
        "She's famous for her \r\n"
        "desserts, you know. {Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaRespondsToMannasPraise[] =
        "Oh, stop flattering me, \r\n"
        "Manna!...{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaInvitesPlayerToLearnCooking[] =
        "It's true! \r\n"
        "You cook too, don't you, \r\n"
        "{Player}?{Press}\p"
        "In that case, you should \r\n"
        "learn from Anna, too!{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_ChoiceAskAnnaForLessons[] =
        "Learn.";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_ChoiceDeclineBecauseBusy[] =
        "Sorry, I'm too busy.";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaAcceptsPlayerAsStudent[] =
        "Really? \r\n"
        "I'd be glad to teach you!{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaTeachesCakeRecipe[] =
        "In that case, both of you \r\n"
        "listen to this simple and \r\n"
        "easy Cake recipe. {Press}\p"
        "Ingredients are Eggs, Flour,\r\n"
        "and Butter. {Press}\p"
        "Seasoning is Sugar, of \r\n"
        "course. \r\n"
        "First, mix the Egg and {Press}\r\n"
        "Butter with a Whisk, then\r\n"
        "add Flour and put it all in\r\n"
        "the Oven. {Press}\p"
        "Not too hard, is it?\r\n"
        "You can also add all kinds\r\n"
        "of fruit to make it even {Press}\r\n"
        "better. Or, you can add \r\n"
        "Chocolate to make it a \r\n"
        "Chocolate Cake!{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaAsksForMoreLessons[] =
        "Can you teach me \r\n"
        "anything else?{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaProposesRecurringCookingLessons[] =
        "How about this...\r\n"
        "Come back again at this same\r\n"
        "time and I'll teach you a {Press}\r\n"
        "new dish. {Press}\p"
        "It'll be a miniature cooking\r\n"
        "school!{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaIsExcitedAboutTheLessons[] =
        "Really? That sounds great! {Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaAgreesToContinueLessons[] =
        "Sure! I'd love to!{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaConfirmsPlayerWillAttend[] =
        "You'll come too, won't \r\n"
        "you {Player}?{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaCriticizesPlayerForDeclining[] =
        "Aww...You're no fun!\r\n"
        "Don't you know that women \r\n"
        "love a man who knows{Press}\r\n"
        "how to cook?{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaDefendsPlayersBusySchedule[] =
        "I'm sure he's busy, Manna. \r\n"
        "It's tough running a farm \r\n"
        "all by yourself, after all! {Press}\p"
        "I'll teach you, instead. {Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaRequestsCakeRecipe[] =
        "How about a recipe for a\r\n"
        "Cake, then? Duke loves \r\n"
        "Cake...{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaBeginsCakeRecipeDiscussion[] =
        "OK. First you...{Press}";
};

void EventScript_NPCEvent_Anna_CookingLessonsInvitationChoice(void)
{
    int var_0;
    EnableScriptedNpcControl();
    ChangeMap(MAP_BASIL_HOUSE_1F, X(120), Y(208));
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ANNA, X(112), Y(96), FACING_DOWN);
    SetEntityAnim(ENTITY_ANNA, ANIMATION_ANNA_IDLE);
    SetEntityPosition(ENTITY_MANNA, X(88), Y(120), FACING_RIGHT);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PanCameraTo(X(120), Y(120), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaAsksAboutRecipeStep);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaExplainsRecipeStep);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaReactsToRecipeTip);
    TalkClose();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(152), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    StartEntityEffect(ENTITY_ANNA, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaWelcomesPlayer);
    TalkClose();
    SetEntityFacing(ENTITY_MANNA, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaGreetsPlayer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaExplainsCookingLesson);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaRespondsToMannasPraise);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaInvitesPlayerToLearnCooking);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_ChoiceAskAnnaForLessons, gText_NPCEvent_Anna_CookingLessonsInvitationChoice_ChoiceDeclineBecauseBusy);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaAcceptsPlayerAsStudent);
            SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
            SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
            TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaTeachesCakeRecipe);
            TalkClose();
            SetEntityFacing(ENTITY_MANNA, FACING_UP);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaAsksForMoreLessons);
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
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaProposesRecurringCookingLessons);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaIsExcitedAboutTheLessons);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaAgreesToContinueLessons);
            TalkClose();
            SetEntityFacing(ENTITY_MANNA, FACING_DOWN);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaConfirmsPlayerWillAttend);
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
            AddNpcFriendship(CHARACTER_ANNA, 20);
            AddNpcFriendship(CHARACTER_MANNA, 20);
            VarSet(VAR_ANNA_COOKING_LESSONS_ACCEPTED, TRUE);
            break;
        case CHOICE_OPTION_2:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaCriticizesPlayerForDeclining);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaDefendsPlayersBusySchedule);
            TalkClose();
            SetEntityFacing(ENTITY_MANNA, FACING_UP);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaRequestsCakeRecipe);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaBeginsCakeRecipeDiscussion);
            TalkClose();
            AddNpcFriendship(CHARACTER_ANNA, mary_negated_int(-10));
            AddNpcFriendship(CHARACTER_MANNA, mary_negated_int(-10));
            break;
    }
    MarkNpcSpokenTo(CHARACTER_ANNA);
    MarkNpcSpokenTo(CHARACTER_MANNA);
    DisableScriptedNpcControl();
    VarSet(VAR_ANNA_COOKING_LESSONS_INVITATION_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_NORTH_SIDE_TOWN, X(200), Y(168));
    SetEntityPosition(ENTITY_PLAYER, X(200), Y(168), FACING_DOWN);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    SetGameTime(13, 0);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    DisableScriptedNpcControl();
    return;
}
