#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_Greeting[] =
        "Willkommen. {Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_AsksIfPlayerIsTourist[] =
        "Ich habe dich hier\r\n"
        "noch nie gesehen. Bist \r\n"
        "du ein Tourist?{Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_IntroducesHerself[] =
        "Du bist also der \r\n"
        "Neue auf der Farm? Ich\r\n"
        "habe von dir gehört. {Press}\p"
        "Mein Name ist Karen. \r\n"
        "Wie geht es dir. {Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_GreetsReturningPlayer[] =
        "Hi, {Player}. \r\n"
        "Willst du einkaufen?{Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_InvitesPlayerToShop[] =
        "Nimm dir Zeit. {Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_OffersHelp[] =
        "Wenn du gerade neu \r\n"
        "anfängst, musst du viele \r\n"
        "Dinge brauchen?{Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_ChoiceRequestHelp[] =
        "Ich könnte Hilfe brauchen.";

    const char gText_LoveEvent_Karen_01_BlackHeart_ChoiceDeclineHelp[] =
        "Kein Problem.";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_AsksPlayerToWait[] =
        "Warte eine Sekunde. {Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_AsksJeffForGrassSeeds[] =
        "Papa, können wir ihm ein\r\n"
        "Päckchen Samen geben?{Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Jeff_ObjectsToFreeSeeds[] =
        "Oh, komm schon!...{Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_AppealsForKindness[] =
        "Was ist mit der Freund- \r\n"
        "lichkeit gegenüber Fremden!{Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Sasha_EncouragesJeff[] =
        "Warum bist du nicht \r\n"
        "etwas netter... Bitte?{Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Jeff_Agrees[] =
        "...OK.{Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_ThanksJeff[] =
        "Danke, Papa. {Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Sasha_PraisesJeff[] =
        "Ich wusste schon, warum \r\n"
        "ich dich genommen habe!{Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_GivesGrassSeeds[] =
        "Bitte sehr. Das\r\n"
        "geht aufs Haus. \r\n"
        "Keine Ursache. {Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_EncouragesFarmWork[] =
        "Es bedeutet viel\r\n"
        "Arbeit, eine Farm zu führen.\r\n"
        "Ich drücke dir die Daumen. {Press}";

    const char gText_LoveEvent_Karen_01_BlackHeart_Karen_OffersFutureHelp[] =
        "Lass mich wissen, wenn \r\n"
        "du Hilfe brauchst. {Press}";
};

void EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift(void)
{
    int var_0;
    ChangeMap(MAP_SUPERMARKET, X(145), Y(275));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_LOVE_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(145), Y(274), FACING_UP);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_KAREN, X(145), Y(227), FACING_DOWN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(175), Y(115), FACING_DOWN);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_JEFF, X(226), Y(115), FACING_DOWN);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_Greeting);
    TalkClose();
    StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    if (HasMetNpc(CHARACTER_KAREN) == FALSE)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        ShowTalkHeartIndicator(CHARACTER_KAREN);
        TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_AsksIfPlayerIsTourist);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        ShowTalkHeartIndicator(CHARACTER_KAREN);
        TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_IntroducesHerself);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        ShowTalkHeartIndicator(CHARACTER_KAREN);
        TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_GreetsReturningPlayer);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        ShowTalkHeartIndicator(CHARACTER_KAREN);
        TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_InvitesPlayerToShop);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAREN);
    ShowTalkHeartIndicator(CHARACTER_KAREN);
    TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_OffersHelp);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_LoveEvent_Karen_01_BlackHeart_ChoiceRequestHelp, gText_LoveEvent_Karen_01_BlackHeart_ChoiceDeclineHelp);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddCharacterLove(CHARACTER_KAREN, 3000);
            AddNpcFriendship(CHARACTER_JEFF, 20);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_AsksPlayerToWait);
            TalkClose();
            SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
            MoveEntityXTo(ENTITY_KAREN, X(184), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            PanCameraTo(X(155), Y(136), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
            WaitForEntityMovement(ENTITY_KAREN);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            SetEntityFacing(ENTITY_KAREN, FACING_UP);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
            MoveEntityYTo(ENTITY_KAREN, Y(152), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_KAREN);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            WaitForCameraMovement();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_AsksJeffForGrassSeeds);
            TalkClose();
            StartEntityEffect(ENTITY_JEFF, ENTITY_EMOTE_EXCLAMATION, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_JEFF);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Jeff_ObjectsToFreeSeeds);
            TalkClose();
            StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_ANGRY, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_AppealsForKindness);
            TalkClose();
            SetEntityFacing(ENTITY_SASHA, FACING_RIGHT);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_SASHA);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Sasha_EncouragesJeff);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_JEFF);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Jeff_Agrees);
            TalkClose();
            StartEntityEffect(ENTITY_KAREN, ENTITY_EMOTE_HAPPY, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_ThanksJeff);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_SASHA);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Sasha_PraisesJeff);
            TalkClose();
            PanCameraTo(X(145), Y(274), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
            SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
            MoveEntityYTo(ENTITY_KAREN, Y(258), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_KAREN);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            SetEntityFacing(ENTITY_KAREN, FACING_LEFT);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WALK);
            MoveEntityXTo(ENTITY_KAREN, X(145), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_KAREN);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
            WaitForCameraMovement();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_GivesGrassSeeds);
            TalkClose();
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_GESTURE);
            WaitFrames(60);
            SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_RAISE_ARMS);
            ShowPlayerHoldingTool(ITEM_TOOL_SEEDS_GRASS);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            if (GetFirstFreeRucksackToolSlot() != mary_negated_int(RUCKSACK_SLOT_NOT_FOUND))
            {
                AddToolToRucksack(ITEM_TOOL_SEEDS_GRASS, 1);
            }
            else
            {
                SetPlayerHeldTool(ITEM_TOOL_SEEDS_GRASS, 1);
            }
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_EncouragesFarmWork);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            SetEntityFacing(ENTITY_SASHA, FACING_DOWN);
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_KAREN);
            MarkNpcSpokenTo(CHARACTER_JEFF);
            MarkNpcSpokenTo(CHARACTER_SASHA);
            SetEntityEventScript(ENTITY_KAREN, EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupKarenDialogue);
            SetEntityEventScript(ENTITY_SASHA, EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupSashaDialogue);
            SetEntityEventScript(ENTITY_JEFF, EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupJeffDialogue);
            VarSet(VAR_KAREN_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
        case CHOICE_OPTION_2:
            AddNpcFriendship(CHARACTER_JEFF, 20);
            AddNpcFriendship(CHARACTER_SASHA, 20);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            ShowTalkHeartIndicator(CHARACTER_KAREN);
            TalkMessage(gText_LoveEvent_Karen_01_BlackHeart_Karen_OffersFutureHelp);
            TalkClose();
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_LOWER_HEAD);
            WaitFrames(60);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            EnableScriptedNpcControl();
            MarkNpcSpokenTo(CHARACTER_KAREN);
            MarkNpcSpokenTo(CHARACTER_JEFF);
            MarkNpcSpokenTo(CHARACTER_SASHA);
            SetEntityEventScript(ENTITY_KAREN, EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupKarenDialogue);
            SetEntityEventScript(ENTITY_SASHA, EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupSashaDialogue);
            SetEntityEventScript(ENTITY_JEFF, EventScript_LoveEvent_Karen_01_BlackHeart_ReceiveWelcomeSeedGift_FollowupJeffDialogue);
            VarSet(VAR_KAREN_BLACK_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            break;
    }
}
