#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_PlayerNoticesCarterMissing[] =
        "Carter's not here. \r\n"
        "I wonder where he is...?{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_PlayerFindsChurchBackDoorOpen[] =
        "The door's open. \r\n"
        "Might as well go in...{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterEnjoysAutumnMushroomGathering[] =
        "I love Fall, because then \r\n"
        "even I can have a little \r\n"
        "treat...{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterWorriesOthersWillDiscoverArea[] =
        "I just can't let anyone\r\n"
        "find out about this!{Press}\r\n"
        "Mmm...It looks delicious!{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAsksWhyPlayerFollowed[] =
        "{Player}, \r\n"
        "what are you doing here? {Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_PlayerSaysDoorWasOpen[] =
        "The door was open, so you\r\n"
        "just wandered in...\r\n"
        "It’s alright...{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterExplainsGatheringMushrooms[] =
        "What was I doing...?{Press}\p"
        "I was just...um...cleaning\r\n"
        "up around here. {Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAsksPlayerNotToJudge[] =
        "Don't look at me like that!\r\n"
        "OK, I'll stop lying. {Press}\p"
        "I was hunting for \r\n"
        "Mushrooms, you see. {Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterExplainsBackAreaIsGoodForMushrooms[] =
        "This area has always been\r\n"
        "great for Mushroom hunting.{Press}\p"
        "In the Fall the Mushrooms \r\n"
        "come out, and even someone\r\n"
        "like me with no money can {Press}\r\n"
        "have a delicious meal. {Press}\p"
        "You won't tell anybody \r\n"
        "about this spot, will you?{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAsksPlayerToKeepMushroomSpotSecret[] =
        "Will you please keep \r\n"
        "this my secret, \r\n"
        "{Player}? {Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_ChoiceKeepSecret[] =
        "Yes";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_ChoiceRefuseSecret[] =
        "No";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterThanksPlayerForKeepingSecret[] =
        "You have my gratitude. \r\n"
        "As a thanks, I'll leave \r\n"
        "this back door open for you{Press}\r\n"
        "around this time everyday.{Press}\p"
        "Come and go as you please. {Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_SharedChoiceOutcomeCarterReturnsToMushrooms[] =
        "Now back to the \r\n"
        "Mushrooms...{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_SharedChoiceOutcomeBackDoorReminder[] =
        "Don't forget about \r\n"
        "this door!{Press}";

    const char gText_NPCEvent_Carter_ChurchBackDoorMushroomSecretChoice_CarterAcceptsPlayersRefusalToKeepSecret[] =
        "I guess you're right...\r\n"
        "It's not right to keep a \r\n"
        "place like this all to {Press}\r\n"
        "myself. It's too selfish. {Press}\p"
        "From now on, I'll leave \r\n"
        "this back door open for you\r\n"
        "around this time everyday.{Press}\p"
        "Come and go as you please. {Press}";
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
