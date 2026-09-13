#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_PlayerNoticesCarterMissing[] =
        "Carter ist nicht hier. \r\n"
        "Wo er wohl ist...?{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_PlayerFindsChurchBackDoorOpen[] =
        "ich kann auch reingehen...{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterEnjoysAutumnMushroomGathering[] =
        "Ich liebe den Herbst, \r\n"
        "dann kann sogar ich \r\n"
        "etwas Vergnügen haben...{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterWorriesOthersWillDiscoverArea[] =
        "Ich kann es bloß\r\n"
        "niemandem sagen!{Press}\r\n"
        "Mmm... Sieht lecker aus!{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAsksWhyPlayerFollowed[] =
        "{Player}, \r\n"
        "Was machst du hier?{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_PlayerSaysDoorWasOpen[] =
        "Die Tür war offen, da \r\n"
        "bist du hereingekommen.\r\n"
        "Schon ok...{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterExplainsGatheringMushrooms[] =
        "Was ich gemacht habe?{Press}\p"
        "Ich habe nur...hm...etwas\r\n"
        "hier aufgeräumt. {Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAsksPlayerNotToJudge[] =
        "Sieh mich nicht so an!\r\n"
        "OK, ich höre auf zu lügen.{Press}\p"
        "Ich suche nach \r\n"
        "Pilzen, siehst du. {Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterExplainsBackAreaIsGoodForMushrooms[] =
        "Diese Gegend war immer\r\n"
        "gut zum Pilzesuchen.{Press}\p"
        "Im Herbst sprießen die \r\n"
        "Pilze und sogar arme Leute\r\n"
        "wie ich können was {Press}\r\n"
        "Leckeres essen. {Press}\p"
        "Du erzählst doch \r\n"
        "niemandem von dem Platz?{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAsksPlayerToKeepMushroomSpotSecret[] =
        "Hütest du bitte \r\n"
        "mein Geheimnis, \r\n"
        "{Player}? {Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_ChoiceKeepSecret[] =
        "Ja";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_ChoiceRefuseSecret[] =
        "Nein";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterThanksPlayerForKeepingSecret[] =
        "Ich bin dir dankbar. \r\n"
        "Als Dank lasse ich \r\n"
        "um diese Zeit die Hinter-{Press}\r\n"
        "tür immer für dich {Press}\p"
        "offen. Komme und gehe, \r\n"
        "wann du willst. {Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_SharedChoiceOutcomeCarterReturnsToMushrooms[] =
        "Nun zurück zu \r\n"
        "den Pilzen...{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_SharedChoiceOutcomeBackDoorReminder[] =
        "Vergiss nicht die \r\n"
        "Hintertür!{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAcceptsPlayersRefusalToKeepSecret[] =
        "Schätze, du hast Recht...\r\n"
        "Es ist nicht richtig, so \r\n"
        "einen Platz für mich zu {Press}\r\n"
        "behalten. Es ist zu selbst-{Press}\p"
        "süchtig. Ab jetzt lasse ich\r\n"
        "die Hintertür um diese \r\n"
        "Uhrzeit für dich offen.{Press}\p"
        "Komme und gehe, \r\n"
        "wann du willst. {Press}";
};

void EventScript_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice(void)
{
    int var_0;
    ChangeMap(MAP_CHURCH, X(236), Y(95));
    SetEntityPosition(ENTITY_PLAYER, X(185), Y(212), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    if (GetEntityLocation(ENTITY_CARTER) == MAP_CHURCH)
    {
        HideEntity(ENTITY_CARTER);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(100), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    WaitFrames(30);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    WaitFrames(10);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    WaitFrames(30);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    WaitFrames(30);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_PlayerNoticesCarterMissing);
    TalkClose();
    SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityXTo(ENTITY_PLAYER, X(309), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    SetEntityFacing(ENTITY_PLAYER, FACING_UP);
    WaitFrames(30);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(60), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    TalkOpen();
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_PlayerFindsChurchBackDoorOpen);
    TalkClose();
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangeMap(MAP_BEHIND_CHURCH, X(140), Y(115));
    SetEntityPosition(ENTITY_PLAYER, X(140), Y(267), FACING_UP);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_CARTER, X(140), Y(76), FACING_UP);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterEnjoysAutumnMushroomGathering);
    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterWorriesOthersWillDiscoverArea);
    TalkClose();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(135), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    WaitFrames(30);
    StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAsksWhyPlayerFollowed);
    SetTalkPortrait(TALK_PORTRAIT_CARTER_AFRAID);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_PlayerSaysDoorWasOpen);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_QUESTION, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterExplainsGatheringMushrooms);
    TalkClose();
    StartEntityEffect(ENTITY_PLAYER, ENTITY_EMOTE_THINKING, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAsksPlayerNotToJudge);
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterExplainsBackAreaIsGoodForMushrooms);
    SetTalkPortrait(TALK_PORTRAIT_CARTER_AFRAID);
    TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAsksPlayerToKeepMushroomSpotSecret);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_ChoiceKeepSecret, gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_ChoiceRefuseSecret);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_HAPPY, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterThanksPlayerForKeepingSecret);
            SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
            TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_SharedChoiceOutcomeCarterReturnsToMushrooms);
            SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
            TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_SharedChoiceOutcomeBackDoorReminder);
            TalkClose();
            AddNpcFriendship(CHARACTER_CARTER, 20);
            SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_WALK);
            SetEntityFacing(ENTITY_CARTER, FACING_LEFT);
            MoveEntityXTo(ENTITY_CARTER, X(103), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_CARTER);
            SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
            MoveEntityYTo(ENTITY_CARTER, Y(253), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_CARTER);
            HideEntity(ENTITY_CARTER);
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            StartEntityEffect(ENTITY_CARTER, ENTITY_EMOTE_AFRAID, FALSE);
            WaitFrames(60);
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_CARTER_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAcceptsPlayersRefusalToKeepSecret);
            SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
            TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_SharedChoiceOutcomeCarterReturnsToMushrooms);
            SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
            TalkMessage(gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_SharedChoiceOutcomeBackDoorReminder);
            TalkClose();
            AddNpcFriendship(CHARACTER_CARTER, mary_negated_int(-10));
            SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_WALK);
            SetEntityFacing(ENTITY_CARTER, FACING_LEFT);
            MoveEntityXTo(ENTITY_CARTER, X(103), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_CARTER);
            SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
            MoveEntityYTo(ENTITY_CARTER, Y(253), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_CARTER);
            HideEntity(ENTITY_CARTER);
            break;
    }
    PanCameraTo(X(140), Y(135), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    WaitForCameraMovement();
    MarkNpcSpokenTo(CHARACTER_CARTER);
    VarSet(VAR_CARTER_CHURCH_BACK_DOOR_MUSHROOM_SECRET_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
}
