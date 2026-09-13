#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Anna_CookingClass_AnnaWelcomesStudents[] =
        "Hi, {Player}. \r\n"
        "Komm herein. {Press}";

    const char gText_NPCEvent_Anna_CookingClass_MannaGreetsPlayer[] =
        "Hallo, {Player}.  {Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaOpensClass[] =
        "Können wir mir dem \r\n"
        "Unterricht beginnen?{Press}";

    const char gText_NPCEvent_Anna_CookingClass_MannaAsksAnnaToBeginClass[] =
        "Ja, Lehrer. \r\n"
        "Fang bitte an!{Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaBeginsLesson[] =
        "Hört jetzt zu...{Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaTeachesCookies[] =
        "Heute lernen wir, Kekse zu\r\n"
        "backen. Alle, die Süßes\r\n"
        "mögen, werden begeistert{Press}\p"
        "sein. Die Zutaten: Eier,\r\n"
        "Butter, Mehl und Zucker.{Press}\p"
        "Und du brauchst eine\r\n"
        "Nudelrolle und einen Ofen.{Press}\p"
        "Noch besser schmeckt es\r\n"
        "mit etwas Honig. Wenn du {Press}\p"
        "Schokolade dazugibst, kannst\r\n"
        "du perfekte Schokokekse für\r\n"
        "das Frühlings-Erntedankfest{Press}\p"
        "backen. {Press}";

    const char gText_NPCEvent_Anna_CookingClass_MannaThanksAnnaForLesson[] =
        "Danke, Lehrer!{Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaClosesLessonUntilNextTime[] =
        "Keine Ursache. \r\n"
        "Bis zum nächsten Mal.{Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaTeachesPudding[] =
        "Ich glaube, heute lernen\r\n"
        "wir, Pudding zu machen.{Press}\p"
        "Eier, Milch, Zucker und \r\n"
        "ein Ofen zum Kochen ist\r\n"
        "alles, was du brauchst. {Press}\p"
        "Noch besser schmeckt\r\n"
        "er mit Früchten \r\n"
        "oder Cornflakes. {Press}\r\n"
        "Probier es mal aus!{Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaClosesPuddingLessonUntilNextTime[] =
        "Keine Ursache. \r\n"
        "Bis zum nächsten Mal. {Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaTeachesCheesecake[] =
        "Heute geht es um \r\n"
        "Käsekuchen. \r\n"
        "Ein ziemlich vornehmes {Press}\r\n"
        "Dessert, meinst du nicht?{Press}\p"
        "Es wird aus Käse, Eiern\r\n"
        "und Milch gemacht und \r\n"
        "mit Zucker gesüßt. {Press}\p"
        "Du brauchst einen Topf, \r\n"
        "Schneebesen und Ofen. {Press}\p"
        "Bei speziellen Gelegenheiten\r\n"
        "gib noch Honig dazu. {Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaTeachesApplePie[] =
        "Heute geht es um \r\n"
        "Apfelkuchen. {Press}\p"
        "Ich weiß, dass Ellen dieses\r\n"
        "Rezept sehr gerne mag. {Press}\p"
        "Sie freut sich sehr, wenn \r\n"
        "du ihr welchen bringst. {Press}\p"
        "Die Zutaten sind: Eier,\r\n"
        "Mehl und Butter. \r\n"
        "Außerdem brauchst du{Press}\r\n"
        "ein Messer, ein Nudelholz, \r\n"
        "einen Topf und einen Ofen.{Press}\p"
        "Es ist nicht einfach, \r\n"
        "aber sehr lecker. {Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaAnnouncesFinalLessonNextTime[] =
        "Ich fürchte, nächstes Mal\r\n"
        "ist unsere letzte Stunde. {Press}";

    const char gText_NPCEvent_Anna_CookingClass_MannaAsksWhyClassWillEnd[] =
        "Echt? Warum?{Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaExplainsBasilsNewBook[] =
        "Basil fängt ein neues \r\n"
        "Buch an, also will ich\r\n"
        "ihn nicht stören.{Press}";

    const char gText_NPCEvent_Anna_CookingClass_MannaAcceptsClassEnding[] =
        "Zu schade...\r\n"
        "{Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaApologizesToPlayer[] =
        "Sorry, {Player}, \r\n"
        "aber mehr kann ich\r\n"
        "dir nicht beibringen. {Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaTeachesIceCream[] =
        "Unsere letzte Lektion  \r\n"
        "ist über Eiskrem. \r\n"
        "Jeder liebt Eiskrem. {Press}\p"
        "Du brauchst Milch, \r\n"
        "Eier und natürlich Zucker.{Press}\p"
        "Außerdem brauchst du \r\n"
        "Topf und Schneebesen. {Press}\p"
        "Alle Kinder lieben sie!{Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaConcludesDessertClass[] =
        "Das war es mit\r\n"
        "meinem Kochunterricht.{Press}";

    const char gText_NPCEvent_Anna_CookingClass_AnnaThanksStudentsAtFinalLesson[] =
        "Keine Ursache. Gut, dass \r\n"
        "ich diese Rezepte\r\n"
        "weitergeben kann. {Press}";
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
            TalkMessage(gText_NPCEvent_Anna_CookingClass_AnnaClosesPuddingLessonUntilNextTime);
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
            TalkMessage(gText_NPCEvent_Anna_CookingClass_AnnaClosesPuddingLessonUntilNextTime);
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
