#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Anna_CookingClass_AnnaWelcomesStudents[] =
        "Hi, {Player}. \r\n"
        "Come on in. {Press}";

    const char gText_NPCEvent_Anna_CookingClass_MannaGreetsPlayer[] =
        "Hello, {Player}. {Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaOpensClass[] =
        "Are we ready to \r\n"
        "begin the class? {Press}";

    const char gText_NPCEvent_Anna_CookingClass_MannaAsksAnnaToBeginClass[] =
        "Yes, Teacher. \r\n"
        "Please begin!{Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaBeginsLesson[] =
        "Listen up, now...{Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaTeachesCookies[] =
        "Today's class will be on \r\n"
        "Cookies. All of you who \r\n"
        "like sweets will love this.{Press}\p"
        "The Ingredients are Egg, \r\n"
        "Flour, Butter, and Sugar.{Press}\p"
        "You also need a Rolling Pin\r\n"
        "and an Oven. {Press}\p"
        "It will also taste better \r\n"
        "if you add Honey. {Press}\p"
        "Also, if you add Chocolate,\r\n"
        "you can make Chocolate\r\n"
        "Cookies that are perfect{Press}\r\n"
        "for the Spring \r\n"
        "Thanksgiving Festival. {Press}";

    const char gText_NPCEvent_Anna_CookingClass_MannaThanksAnnaForLesson[] =
        "Thank you, Teacher!{Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaClosesLessonUntilNextTime[] =
        "Don't mention it. \r\n"
        "Until next time. {Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaTeachesPudding[] =
        "I think Pudding is a good \r\n"
        "subject for today's class. {Press}\p"
        "All you need is Egg, Milk, \r\n"
        "Sugar, and an Oven to \r\n"
        "cook it all in. {Press}\p"
        "They taste even better with\r\n"
        "Fruit or Corn Flakes. \r\n"
        "Try it out!{Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaTeachesCheesecake[] =
        "Today's lesson will be on \r\n"
        "Cheese Cake. \r\n"
        "Quite a sophisticated {Press}\r\n"
        "dessert, don't you think?{Press}\p"
        "It's made with Cheese, \r\n"
        "Eggs, and Milk, along with \r\n"
        "Sugar to sweeten it. {Press}\p"
        "You'll need a Pot, a Whisk,\r\n"
        "and an Oven. {Press}\p"
        "You can also add Honey \r\n"
        "on special occasions. {Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaTeachesApplePie[] =
        "Today's lesson will be on \r\n"
        "Apple Pie. {Press}\p"
        "I know that Ellen likes \r\n"
        "this recipe very well. {Press}\p"
        "She'll love it if you \r\n"
        "bring her some. {Press}\p"
        "Ingredients are Egg, Flour,\r\n"
        "and Butter. \r\n"
        "You'll need a Knife, a Pot,{Press}\r\n"
        "a Rolling Pin, and an Oven.{Press}\p"
        "It's not easy, but it's \r\n"
        "very delicious. {Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaAnnouncesFinalLessonNextTime[] =
        "I'm afraid next time will be\r\n"
        "our final lesson. {Press}";

    const char gText_NPCEvent_Anna_CookingClass_MannaAsksWhyClassWillEnd[] =
        "Really? Why?{Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaExplainsBasilsNewBook[] =
        "Yes, Basil is starting \r\n"
        "another book, so I don't\r\n"
        "want to disturb him.{Press}";

    const char gText_NPCEvent_Anna_CookingClass_MannaAcceptsClassEnding[] =
        "That's too bad...\r\n"
        "{Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaApologizesToPlayer[] =
        "Sorry, {Player}, \r\n"
        "but that's all I can teach\r\n"
        "you. {Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaTeachesIceCream[] =
        "Our final lesson will be on \r\n"
        "Ice Cream. \r\n"
        "Everybody loves Ice Cream. {Press}\p"
        "You'll need Milk, Egg, \r\n"
        "and of course Sugar. {Press}\p"
        "You'll also need a Pot \r\n"
        "and a Whisk. {Press}\p"
        "All children love this!{Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaConcludesDessertClass[] =
        "That's it for my Dessert \r\n"
        "Classroom. {Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaThanksStudentsAtFinalLesson[] =
        "Don't mention it. I'm \r\n"
        "glad to be able to share\r\n"
        "these recipes. {Press}";
};

void EventScript_NPCEvent_Anna_CookingClass(void)
{
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
    SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_NPCEvent_Anna_CookingClass_AnnaWelcomesStudents);
    TalkClose();
    SetEntityFacing(ENTITY_MANNA, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_Anna_CookingClass_MannaGreetsPlayer);
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
    TalkMessage(gText_NPCEvent_Anna_CookingClass_AnnaOpensClass);
    TalkClose();
    SetEntityFacing(ENTITY_MANNA, FACING_UP);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_NPCEvent_Anna_CookingClass_MannaAsksAnnaToBeginClass);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_NPCEvent_Anna_CookingClass_AnnaBeginsLesson);
    TalkClose();
    switch (VarGet(VAR_ANNA_COOKING_LESSONS_COMPLETED_COUNT))
    {
        case 0:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_AnnaTeachesCookies);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_MannaThanksAnnaForLesson);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_AnnaClosesLessonUntilNextTime);
            TalkClose();
            break;
        case 1:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_AnnaTeachesPudding);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_MannaThanksAnnaForLesson);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_AnnaClosesLessonUntilNextTime);
            TalkClose();
            break;
        case 2:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_AnnaTeachesCheesecake);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_MannaThanksAnnaForLesson);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_AnnaClosesLessonUntilNextTime);
            TalkClose();
            break;
        case 3:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_AnnaTeachesApplePie);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_MannaThanksAnnaForLesson);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_AnnaAnnouncesFinalLessonNextTime);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_MannaAsksWhyClassWillEnd);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_AnnaExplainsBasilsNewBook);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_MannaAcceptsClassEnding);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_AnnaApologizesToPlayer);
            TalkClose();
            break;
        case 4:
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_AnnaTeachesIceCream);
            SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_AnnaConcludesDessertClass);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_MannaThanksAnnaForLesson);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_NPCEvent_Anna_CookingClass_AnnaThanksStudentsAtFinalLesson);
            TalkClose();
            AddNpcFriendship(CHARACTER_ANNA, 20);
            AddNpcFriendship(CHARACTER_MANNA, 20);
            break;
    }
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
    MarkNpcSpokenTo(CHARACTER_ANNA);
    MarkNpcSpokenTo(CHARACTER_MANNA);
    DisableScriptedNpcControl();
    VarSet(VAR_ANNA_COOKING_LESSON_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    VarSet(VAR_ANNA_COOKING_LESSONS_COMPLETED_COUNT, VarGet(VAR_ANNA_COOKING_LESSONS_COMPLETED_COUNT) + 1);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_NORTH_SIDE_TOWN, X(200), Y(168));
    SetEntityPosition(ENTITY_PLAYER, X(200), Y(168), FACING_DOWN);
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    SetGameTime(13, 0);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    DisableScriptedNpcControl();
    return;
}
