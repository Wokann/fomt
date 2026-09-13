#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_Shared_MaryAndGrayExchangeGreetings[] =
        "Hallo. {Press}";

    const char gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_MaryThanksGrayForVisitingLibrary[] =
        "Danke fürs Kommen! Die\r\n"
        "anderen in der Stadt \r\n"
        "lesen keine Bücher. {Press}";

    const char gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_GrayPraisesLibraryBookSelection[] =
        "Wirklich? Aber hier\r\n"
        "sind so tolle Bücher! {Press}";

    const char gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_MaryAppreciatesGraysInterestInBooks[] =
        "Sehr nett, dass du \r\n"
        "das sagst.{Press}";

    const char gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_MaryOffersGrayHerNovelAndAsksForOpinion[] =
        "Ich schreibe eigentlich\r\n"
        "einen Roman. Möchtest\r\n"
        "du ihn lesen?{Press}\p"
        "Ich würde gerne deine \r\n"
        "Meinung hören. {Press}";

    const char gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_GrayIsImpressedMaryWritesNovels[] =
        "Du schreibst ein Buch?\r\n"
        "Das ist unglaublich! {Press}";

    const char gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_MaryDownplaysNovelAndRepeatsOffer[] =
        "Keine große Sache.\r\n"
        "Möchtest du es lesen?{Press}";

    const char gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_GrayAcceptsOfferToReadNovel[] =
        "Wenn du wirklich willst,\r\n"
        "dass ich es lese, gerne!{Press}";

    const char gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_MaryPromisesToBringNovelLater[] =
        "Super! Ich bringe \r\n"
        "es dir später. {Press}";

    const char gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_GrayAgrees[] =
        "OK. {Press}";
};

void EventScript_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer(void)
{
    ChangeMap(MAP_LIBRARY_1F, X(120), Y(80));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_RIVAL_EVENT);
    SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_GRAY, X(88), Y(68), FACING_UP);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    SetEntityPosition(ENTITY_MARY, X(218), Y(156), FACING_LEFT);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    MoveEntityXTo(ENTITY_MARY, X(104), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityFacing(ENTITY_MARY, FACING_UP);
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_WALK);
    MoveEntityYTo(ENTITY_MARY, Y(68), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_MARY);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityFacing(ENTITY_MARY, FACING_LEFT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_Shared_MaryAndGrayExchangeGreetings);
    TalkClose();
    StartEntityEffect(ENTITY_GRAY, ENTITY_EMOTE_EXCLAMATION, FALSE);
    WaitFrames(60);
    SetEntityFacing(ENTITY_GRAY, FACING_RIGHT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_Shared_MaryAndGrayExchangeGreetings);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_MaryThanksGrayForVisitingLibrary);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_GrayPraisesLibraryBookSelection);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_MaryAppreciatesGraysInterestInBooks);
    TalkClose();
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_MaryOffersGrayHerNovelAndAsksForOpinion);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_GrayIsImpressedMaryWritesNovels);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_MaryDownplaysNovelAndRepeatsOffer);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_GrayAcceptsOfferToReadNovel);
    TalkClose();
    StartEntityEffect(ENTITY_MARY, ENTITY_EMOTE_HAPPY, FALSE);
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_MaryPromisesToBringNovelLater);
    TalkClose();
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_GrayAgrees);
    TalkClose();
    PanCameraTo(X(120), Y(144), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
    WaitForCameraMovement();
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
    }
    MoveEntityYTo(ENTITY_PLAYER, Y(160), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_MARY, EventScript_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_FollowupMaryDialogue);
    SetEntityEventScript(ENTITY_GRAY, EventScript_RivalEvent_MaryAndGray_02_BlueHeart_LibraryNovelOffer_FollowupGrayDialogue);
    VarSet(VAR_MARY_GRAY_RIVAL_EVENT_2_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    return;
}
