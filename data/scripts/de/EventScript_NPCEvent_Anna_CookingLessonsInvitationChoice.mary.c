#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaAsksAboutRecipeStep[] =
        "...und was tust du\r\n"
        "dann hinein?{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaExplainsRecipeStep[] =
        "Du tust...hinein\r\n"
        "...dann nimmst du...{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaReactsToRecipeTip[] =
        "Daran hätte ich\r\n"
        "nie gedacht!...{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaWelcomesPlayer[] =
        "Hi, {Player}.\r\n"
        "Komm herein. {Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaGreetsPlayer[] =
        "Hi, {Player}. {Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaExplainsCookingLesson[] =
        "Was hast du gemacht?\r\n"
        "Anna hat mir gezeigt, \r\n"
        "wie man Nachtisch macht. {Press}\p"
        "Sie ist bekannt für \r\n"
        "ihren Nachtisch. {Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaRespondsToMannasPraise[] =
        "Hör auf, mir zu \r\n"
        "schmeicheln, Manna!...{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaInvitesPlayerToLearnCooking[] =
        "Das stimmt! \r\n"
        "Du kannst auch kochen oder,\r\n"
        "{Player}?{Press}\p"
        "Wenn das so ist, solltest \r\n"
        "du auch von Anna lernen!{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_ChoiceAskAnnaForLessons[] =
        "Lernen";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_ChoiceDeclineBecauseBusy[] =
        "Sorry, bin zu beschäftigt.";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaAcceptsPlayerAsStudent[] =
        "Echt?\r\n"
        "Ich zeige es euch gerne!{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaTeachesCakeRecipe[] =
        "Wenn das so ist, merkt \r\n"
        "euch dieses einfache \r\n"
        "Kuchenrezept. {Press}\p"
        "Die Zutaten sind: Mehl,\r\n"
        "Eier und Butter. {Press}\p"
        "Und Zucker natürlich. \r\n"
        "Zuerst mixe Eier und {Press}\r\n"
        "Butter mit dem Schneebesen,\r\n"
        "gib das Mehl hinzu und\r\n"
        "schiebe alles in den Ofen. {Press}\p"
        "Ganz leicht, oder?\r\n"
        "Du kannst auch alle\r\n"
        "möglichen Früchte dazugeben,{Press}\r\n"
        "das ist noch besser. Oder gib\r\n"
        "Schokolade dazu, dann wird \r\n"
        "es ein Schokoladenkuchen!{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaAsksForMoreLessons[] =
        "Kannst du mir noch \r\n"
        "etwas anderes zeigen?{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaProposesRecurringCookingLessons[] =
        "Wie wäre es hiermit...\r\n"
        "Komm einfach wieder zur\r\n"
        "selben Zeit, und ich zeige{Press}\r\n"
        "dir ein neues Gericht. {Press}\p"
        "Das wird wie eine \r\n"
        "Minikochschule!{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaIsExcitedAboutTheLessons[] =
        "Echt? Das hört sich toll an!{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaAgreesToContinueLessons[] =
        "Sicher! Liebend gerne!{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaConfirmsPlayerWillAttend[] =
        "Du kommst doch auch, \r\n"
        "{Player}, oder?{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaCriticizesPlayerForDeclining[] =
        "Ahhh... Spielverderber!\r\n"
        "Weißt du nicht, dass \r\n"
        "Frauen es lieben, wenn{Press}\r\n"
        "Männer kochen können?{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaDefendsPlayersBusySchedule[] =
        "Er hat sicher zu tun, Manna.\r\n"
        "Es ist nicht einfach, eine \r\n"
        "Farm alleine zu führen! Ich{Press}\p"
        "zeige es dir stattdessen.{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_MannaRequestsCakeRecipe[] =
        "Wie wäre es denn mit\r\n"
        "einem Kuchenrezept? Duke\r\n"
        "liebt Kuchen...{Press}";

    const char gText_NPCEvent_Anna_CookingLessonsInvitationChoice_AnnaBeginsCakeRecipeDiscussion[] =
        "OK. Zuerst du...{Press}";
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
