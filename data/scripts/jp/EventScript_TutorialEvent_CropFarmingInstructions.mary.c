#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TutorialEvent_CropFarmingInstructions_ToRaiseCropsFirstUseYour[] =
        "作物を育てるには、\r\n"
        "まずクワを使って地面を耕しま\r\n"
        "しょう。{Press}\p"
        "装備している道具を使うには、\r\n"
        "Ｂボタンを押しましょう。{Press}";

    const char gText_TutorialEvent_CropFarmingInstructions_CannotTillOccupiedGround[] =
        "でも、地面に障害物があると\r\n"
        "耕すことができません。{Press}\p"
        "雑草は、カマを使って刈るか、\r\n"
        "引っこ抜いて捨てることができ\r\n"
        "ます。{Press}";

    const char gText_TutorialEvent_CropFarmingInstructions_UseTheAButtonToPull[] =
        "引っこ抜く場合はＡボタンを\r\n"
        "押しましょう。{Press}";

    const char gText_TutorialEvent_CropFarmingInstructions_UseTheAButtonToThrow[] =
        "持っている物を捨てる場合も\r\n"
        "Ａボタンを押しましょう。{Press}";

    const char gText_TutorialEvent_CropFarmingInstructions_UseAHammerToSmashApart[] =
        "石は、\r\n"
        "ハンマーを使って壊すか、\r\n"
        "持ち上げて捨てられます。{Press}";

    const char gText_TutorialEvent_CropFarmingInstructions_StonesCannotBeDiscarded[] =
        "ただし、\r\n"
        "石は耕作地で捨てることはでき\r\n"
        "ません。{Press}\p"
        "捨てるには水場に持っていきま\r\n"
        "しょう。{Press}";

    const char gText_TutorialEvent_CropFarmingInstructions_YouCannotLiftLargeOrHuge[] =
        "大きい石、岩は\r\n"
        "持ち上げることはできません。{Press}\p"
        "ハンマーを鍛冶屋さんで強く改\r\n"
        "造してもらわないと壊すことは\r\n"
        "できません。{Press}";

    const char gText_TutorialEvent_CropFarmingInstructions_HoldDownTheBButtonTo[] =
        "Ｂボタンをしばらく押し続けて\r\n"
        "からＢボタンを離すとため攻撃\r\n"
        "になります。{Press}\r\n"
        "改造した後でないと、ため攻撃\r\n"
        "はできません。{Press}";

    const char gText_TutorialEvent_CropFarmingInstructions_UseYourAxeToClearAway[] =
        "枝は、\r\n"
        "オノを使って壊すか、\r\n"
        "持ち上げて捨てられます。{Press}";

    const char gText_TutorialEvent_CropFarmingInstructions_YouCannotThrowAwayBranchesOn[] =
        "枝も石と同じく耕作地で捨てる\r\n"
        "ことはできません。{Press}\p"
        "捨てるには水場に持っていきま\r\n"
        "しょう。{Press}";

    const char gText_TutorialEvent_CropFarmingInstructions_YouCannotLiftUpStumpsYou[] =
        "切り株も持ち上げることはでき\r\n"
        "ません。{Press}\p"
        "オノを鍛冶屋さんで強く改造し\r\n"
        "てもらわないと壊すことはでき\r\n"
        "ません。{Press}";

    const char gText_TutorialEvent_CropFarmingInstructions_UseSeedsOnTilledSoilTo[] =
        "耕したマスの上で種を使うと、\r\n"
        "種をまきます。\r\n"
        "主人公中心に３×３マス。{Press}\p"
        "耕してないマスには種をまかな\r\n"
        "いので注意。{Press}";

    const char gText_TutorialEvent_CropFarmingInstructions_YouCanPurchaseSeedsAtThe[] =
        "※種は雑貨屋などで買うことが\r\n"
        "　できます。{Press}";

    const char gText_TutorialEvent_CropFarmingInstructions_UseAWateringCanToWater[] =
        "じょうろを使えば、耕した地面\r\n"
        "に水をまきます。{Press}\p"
        "まずはじょうろに水を補給しま\r\n"
        "しょう。{Press}";

    const char gText_TutorialEvent_CropFarmingInstructions_EquipTheWateringCanThenThe[] =
        "じょうろに水を補給するには、\r\n"
        "じょうろを装備して水場の前で\r\n"
        "Ｂボタンを押しましょう。{Press}";

    const char gText_TutorialEvent_CropFarmingInstructions_YourCropsWillGrowOnlyIf[] =
        "１日１回水をまくのを何日か\r\n"
        "続けると芽が出てきます。{Press}";

    const char gText_TutorialEvent_CropFarmingInstructions_ContinueWateringAndYourCropsWill[] =
        "１日１回水をまくのを何日か\r\n"
        "続けると実がなります。{Press}";

    const char gText_TutorialEvent_CropFarmingInstructions_OnceCropsBloomTheAButton[] =
        "実ができたら、\r\n"
        "Ａボタンで収穫できます。{Press}";

    const char gText_TutorialEvent_CropFarmingInstructions_ToShipHarvestedCropsTheA[] =
        "出荷するときは、\r\n"
        "出荷箱に向かってＡボタンを\r\n"
        "押しましょう。{Press}";
};

void EventScript_TutorialEvent_CropFarmingInstructions(void)
{
    int var_0;
    ChangeMap(MAP_TUTORIAL_ANIMAL_FIELD, X(0), Y(0));
    SetEntityPosition(ENTITY_TUTORIAL_PLAYER, X(104), Y(32), FACING_DOWN);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    NoOpTutorialFieldTile(7, 0, 0, 21, 8);
    NoOpTutorialFieldTile(7, 1, 0, 21, 8);
    NoOpTutorialFieldTile(8, 0, 0, 23, 8);
    NoOpTutorialFieldTile(8, 1, 0, 23, 8);
    NoOpTutorialFieldTile(7, 2, 0, 22, 8);
    NoOpTutorialFieldTile(8, 2, 0, 22, 8);
    NoOpTutorialFieldTile(5, 3, 0, 31, 8);
    NoOpTutorialFieldTile(6, 3, 0, 32, 8);
    NoOpTutorialFieldTile(5, 4, 0, 33, 8);
    NoOpTutorialFieldTile(6, 4, 0, 34, 8);
    NoOpTutorialFieldTile(7, 3, 0, 35, 8);
    NoOpTutorialFieldTile(8, 3, 0, 36, 8);
    NoOpTutorialFieldTile(7, 4, 0, 37, 8);
    NoOpTutorialFieldTile(8, 4, 0, 38, 8);
    NoOpTutorialFieldTile(9, 3, 0, 27, 8);
    NoOpTutorialFieldTile(10, 3, 0, 28, 8);
    NoOpTutorialFieldTile(9, 4, 0, 29, 8);
    NoOpTutorialFieldTile(10, 4, 0, 30, 8);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PlayBGM(AUDIO_START_WEAK, AUDIO_RECORD_GRIFFIN_BLUE);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CropFarmingInstructions_ToRaiseCropsFirstUseYour);
    TalkClose();
    WaitFrames(10);
    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
    ShowPlayerHoldingTool(ITEM_TOOL_HOE_IRON);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HOE_PREPARE);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HOE_SWING);
    PlaySong(AUDIO_START, AUDIO_SFX_HOE_TILL);
    WaitFrames(24 - 1);
    NoOpTutorialFieldTile(6, 0, 1, 0, 0);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HOE_PREPARE);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HOE_SWING);
    PlaySong(AUDIO_START, AUDIO_SFX_HOE_TILL);
    WaitFrames(24);
    NoOpTutorialFieldTile(6, 1, 1, 0, 0);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HOE_PREPARE);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HOE_SWING);
    PlaySong(AUDIO_START, AUDIO_SFX_HOE_TILL);
    WaitFrames(24);
    NoOpTutorialFieldTile(6, 2, 1, 0, 0);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_UP);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) - 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HOE_PREPARE);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HOE_SWING);
    PlaySong(AUDIO_START, AUDIO_SFX_HOE_TILL);
    WaitFrames(14);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CropFarmingInstructions_CannotTillOccupiedGround);
    TalkClose();
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(10);
    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
    ShowPlayerHoldingTool(ITEM_TOOL_SICKLE_IRON);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(10);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_SICKLE_PREPARE);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_SICKLE_SWING);
    PlaySong(AUDIO_START, AUDIO_SFX_SICKLE_CUT);
    WaitFrames(28);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    NoOpTutorialFieldTile(7, 0, 0, 0, 0);
    NoOpTutorialFieldObject(7, 0, 0);
    WaitFrames(20);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    NoOpTutorialFieldTile(7, 1, 0, 0, 0);
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    SetPlayerHeldArticle(ITEM_ARTICLE_WEEDS);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CropFarmingInstructions_UseTheAButtonToPull);
    TalkClose();
    WaitFrames(20);
    PlaySong(AUDIO_START, AUDIO_SFX_THROW_ITEM);
    ThrowPlayerHeldItem();
    WaitFrames(20);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CropFarmingInstructions_UseTheAButtonToThrow);
    TalkClose();
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CropFarmingInstructions_UseAHammerToSmashApart);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
    ShowPlayerHoldingTool(ITEM_TOOL_HAMMER_IRON);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(10);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HAMMER_PREPARE);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HAMMER_SWING);
    PlaySong(AUDIO_START, AUDIO_SFX_HAMMER_SMALL_STONE);
    WaitFrames(24);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    NoOpTutorialFieldTile(7, 2, 0, 0, 0);
    NoOpTutorialFieldObject(7, 2, 3);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    NoOpTutorialFieldTile(8, 2, 0, 0, 0);
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    SetPlayerHeldArticle(ITEM_ARTICLE_STONES);
    WaitFrames(40);
    PlaySong(AUDIO_START, AUDIO_SFX_THROW_ITEM);
    UsePlayerHeldItem();
    NoOpTutorialFieldTile(8, 2, 0, 22, 8);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CropFarmingInstructions_StonesCannotBeDiscarded);
    TalkClose();
    NoOpTutorialFieldTile(8, 2, 0, 0, 0);
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    SetPlayerHeldArticle(ITEM_ARTICLE_STONES);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_RUN_HOLDING_ITEM);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) + 72), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    WaitFrames(20);
    PlaySong(AUDIO_START, AUDIO_SFX_THROW_ITEM);
    ThrowPlayerHeldItem();
    PlaySong(AUDIO_START, AUDIO_SFX_THROWN_ITEM_LANDS);
    WaitFrames(20);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_RUN_EMPTY_HANDED);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) - 88), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HAMMER_PREPARE);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HAMMER_SWING);
    PlaySong(AUDIO_START, AUDIO_SFX_HAMMER_SMALL_STONE);
    WaitFrames(14);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CropFarmingInstructions_YouCannotLiftLargeOrHuge);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
    ShowPlayerHoldingTool(ITEM_TOOL_HAMMER_MYSTRILE);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    var_0 = 0;
    do
    {
        if (var_0 == 1)
        {
            WaitFrames(14);
        }
        else
        {
            WaitFrames(24);
        }
        if (var_0 == 1)
        {
            TalkOpen();
            TalkMessage(gText_TutorialEvent_CropFarmingInstructions_HoldDownTheBButtonTo);
            TalkClose();
        }
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        WaitFrames(10);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HAMMER_PREPARE);
        WaitFrames(20);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HAMMER_CHARGE_STAGE_1);
        WaitFrames(20);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HAMMER_SWING);
        PlaySong(AUDIO_START, AUDIO_SFX_HAMMER_LARGE_STONE);
        var_0 = var_0 + 1;
    }
    while (var_0 < 3);
    WaitFrames(24);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    NoOpTutorialFieldTile(5, 3, 0, 0, 0);
    NoOpTutorialFieldTile(6, 3, 0, 0, 0);
    NoOpTutorialFieldTile(5, 4, 0, 0, 0);
    NoOpTutorialFieldTile(6, 4, 0, 0, 0);
    NoOpTutorialFieldObject(5, 3, 8);
    WaitFrames(20);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    var_0 = 0;
    do
    {
        WaitFrames(24);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        WaitFrames(10);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HAMMER_PREPARE);
        WaitFrames(20);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HAMMER_CHARGE_STAGE_1);
        WaitFrames(20);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HAMMER_CHARGE_STAGE_2);
        WaitFrames(20);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HAMMER_SWING);
        PlaySong(AUDIO_START, AUDIO_SFX_HAMMER_HUGE_STONE);
        var_0 = var_0 + 1;
    }
    while (var_0 < 6);
    WaitFrames(24);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    NoOpTutorialFieldTile(7, 3, 0, 0, 0);
    NoOpTutorialFieldTile(8, 3, 0, 0, 0);
    NoOpTutorialFieldTile(7, 4, 0, 0, 0);
    NoOpTutorialFieldTile(8, 4, 0, 0, 0);
    NoOpTutorialFieldObject(7, 3, 6);
    WaitFrames(20);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_UP);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) - 32), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CropFarmingInstructions_UseYourAxeToClearAway);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
    ShowPlayerHoldingTool(ITEM_TOOL_AXE_IRON);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(10);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_AXE_PREPARE);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_AXE_SWING);
    PlaySong(AUDIO_START, AUDIO_SFX_AXE_BRANCH_CHOP);
    WaitFrames(24);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    NoOpTutorialFieldTile(8, 0, 0, 0, 0);
    NoOpTutorialFieldObject(8, 0, 4);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    NoOpTutorialFieldTile(8, 1, 0, 0, 0);
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    SetPlayerHeldArticle(ITEM_ARTICLE_BRANCHES);
    WaitFrames(20);
    PlaySong(AUDIO_START, AUDIO_SFX_THROW_ITEM);
    UsePlayerHeldItem();
    NoOpTutorialFieldTile(8, 1, 0, 23, 8);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CropFarmingInstructions_YouCannotThrowAwayBranchesOn);
    TalkClose();
    NoOpTutorialFieldTile(8, 1, 0, 0, 0);
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    SetPlayerHeldArticle(ITEM_ARTICLE_BRANCHES);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_RUN_HOLDING_ITEM);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) + 72), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    WaitFrames(20);
    PlaySong(AUDIO_START, AUDIO_SFX_THROW_ITEM);
    ThrowPlayerHeldItem();
    PlaySong(AUDIO_START, AUDIO_SFX_THROWN_ITEM_LANDS);
    WaitFrames(20);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) - 24), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_AXE_PREPARE);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_AXE_SWING);
    PlaySong(AUDIO_START, AUDIO_SFX_AXE_BRANCH_CHOP);
    WaitFrames(14);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CropFarmingInstructions_YouCannotLiftUpStumpsYou);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
    ShowPlayerHoldingTool(ITEM_TOOL_AXE_MYSTRILE);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    var_0 = 0;
    do
    {
        WaitFrames(24);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        WaitFrames(10);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_AXE_PREPARE);
        WaitFrames(20);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_AXE_CHARGE_STAGE_1);
        WaitFrames(20);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_AXE_SWING);
        PlaySong(AUDIO_START, AUDIO_SFX_AXE_STUMP_CHOP);
        var_0 = var_0 + 1;
    }
    while (var_0 < 6);
    WaitFrames(24);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    NoOpTutorialFieldTile(9, 3, 0, 0, 0);
    NoOpTutorialFieldTile(10, 3, 0, 0, 0);
    NoOpTutorialFieldTile(9, 4, 0, 0, 0);
    NoOpTutorialFieldTile(10, 4, 0, 0, 0);
    NoOpTutorialFieldObject(9, 3, 7);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_RUN_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) + 16), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) - 48), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_UP);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(20);
    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
    ShowPlayerHoldingTool(ITEM_TOOL_HOE_IRON);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(10);
    var_0 = 0;
    do
    {
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HOE_PREPARE);
        WaitFrames(20);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HOE_SWING);
        PlaySong(AUDIO_START, AUDIO_SFX_HOE_TILL);
        WaitFrames(24);
        switch (var_0)
        {
            case 0:
                NoOpTutorialFieldTile(7, 2, 1, 0, 0);
                break;
            case 1:
                NoOpTutorialFieldTile(7, 1, 1, 0, 0);
                break;
            case 2:
                NoOpTutorialFieldTile(7, 0, 1, 0, 0);
                break;
        }
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
        MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) - 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
        var_0 = var_0 + 1;
    }
    while (var_0 < 3);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HOE_PREPARE);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HOE_SWING);
    PlaySong(AUDIO_START, AUDIO_SFX_HOE_TILL);
    WaitFrames(24);
    NoOpTutorialFieldTile(8, 0, 1, 0, 0);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HOE_PREPARE);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HOE_SWING);
    PlaySong(AUDIO_START, AUDIO_SFX_HOE_TILL);
    WaitFrames(24);
    NoOpTutorialFieldTile(8, 1, 1, 0, 0);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HOE_PREPARE);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_HOE_SWING);
    PlaySong(AUDIO_START, AUDIO_SFX_HOE_TILL);
    WaitFrames(24);
    NoOpTutorialFieldTile(8, 2, 1, 0, 0);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) - 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(20);
    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
    ShowPlayerHoldingTool(ITEM_TOOL_SEEDS_TURNIP);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_SOW_SEEDS);
    PlaySong(AUDIO_START, AUDIO_SFX_SOW_SEEDS);
    WaitFrames(36);
    NoOpTutorialFieldTile(6, 0, 1, 0, 1);
    NoOpTutorialFieldTile(6, 1, 1, 0, 1);
    NoOpTutorialFieldTile(6, 2, 1, 0, 1);
    NoOpTutorialFieldTile(7, 0, 1, 0, 1);
    NoOpTutorialFieldTile(7, 1, 1, 0, 1);
    NoOpTutorialFieldTile(7, 2, 1, 0, 1);
    NoOpTutorialFieldTile(8, 0, 1, 0, 1);
    NoOpTutorialFieldTile(8, 1, 1, 0, 1);
    NoOpTutorialFieldTile(8, 2, 1, 0, 1);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CropFarmingInstructions_UseSeedsOnTilledSoilTo);
    TalkClose();
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CropFarmingInstructions_YouCanPurchaseSeedsAtThe);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
    ShowPlayerHoldingTool(ITEM_TOOL_WATERING_CAN_IRON);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(10);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CropFarmingInstructions_UseAWateringCanToWater);
    TalkClose();
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_RUN_EMPTY_HANDED);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) + 72), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_REFILL_WATERING_CAN);
    PlaySong(AUDIO_START, AUDIO_SFX_WATER_SPLASH);
    WaitFrames(36);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CropFarmingInstructions_EquipTheWateringCanThenThe);
    TalkClose();
    WaitFrames(10);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_RUN_EMPTY_HANDED);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) - 40), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_UP);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) - 16), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    var_0 = 0;
    do
    {
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_PREPARE);
        WaitFrames(20);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_POUR);
        PlaySong(AUDIO_START, AUDIO_SFX_WATERING_CAN_POUR);
        WaitFrames(48);
        switch (var_0)
        {
            case 0:
                NoOpTutorialFieldTile(8, 0, 2, 0, 1);
                break;
            case 1:
                NoOpTutorialFieldTile(7, 0, 2, 0, 1);
                break;
        }
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
        MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) - 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
        var_0 = var_0 + 1;
    }
    while (var_0 < 2);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_PREPARE);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_POUR);
    PlaySong(AUDIO_START, AUDIO_SFX_WATERING_CAN_POUR);
    WaitFrames(48);
    NoOpTutorialFieldTile(6, 0, 2, 0, 1);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) + 32), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    var_0 = 0;
    do
    {
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_PREPARE);
        WaitFrames(20);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_POUR);
        PlaySong(AUDIO_START, AUDIO_SFX_WATERING_CAN_POUR);
        WaitFrames(48);
        switch (var_0)
        {
            case 0:
                NoOpTutorialFieldTile(8, 1, 2, 0, 1);
                break;
            case 1:
                NoOpTutorialFieldTile(7, 1, 2, 0, 1);
                break;
        }
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
        MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) - 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
        var_0 = var_0 + 1;
    }
    while (var_0 < 2);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_PREPARE);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_POUR);
    PlaySong(AUDIO_START, AUDIO_SFX_WATERING_CAN_POUR);
    WaitFrames(48);
    NoOpTutorialFieldTile(6, 1, 2, 0, 1);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) + 32), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    var_0 = 0;
    do
    {
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_PREPARE);
        WaitFrames(20);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_POUR);
        PlaySong(AUDIO_START, AUDIO_SFX_WATERING_CAN_POUR);
        WaitFrames(48);
        switch (var_0)
        {
            case 0:
                NoOpTutorialFieldTile(8, 2, 2, 0, 1);
                break;
            case 1:
                NoOpTutorialFieldTile(7, 2, 2, 0, 1);
                break;
        }
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
        MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) - 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
        var_0 = var_0 + 1;
    }
    while (var_0 < 2);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_PREPARE);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_POUR);
    PlaySong(AUDIO_START, AUDIO_SFX_WATERING_CAN_POUR);
    WaitFrames(48);
    NoOpTutorialFieldTile(6, 2, 2, 0, 1);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(60);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StopBGM();
    WaitFrames(30);
    SetEntityPosition(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) + 32), Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) - 32), FACING_LEFT);
    NoOpTutorialFieldTile(6, 0, 1, 0, 2);
    NoOpTutorialFieldTile(6, 1, 1, 0, 2);
    NoOpTutorialFieldTile(6, 2, 1, 0, 2);
    NoOpTutorialFieldTile(7, 0, 1, 0, 2);
    NoOpTutorialFieldTile(7, 1, 1, 0, 2);
    NoOpTutorialFieldTile(7, 2, 1, 0, 2);
    NoOpTutorialFieldTile(8, 0, 1, 0, 2);
    NoOpTutorialFieldTile(8, 1, 1, 0, 2);
    NoOpTutorialFieldTile(8, 2, 1, 0, 2);
    PlaySong(AUDIO_START, AUDIO_SFX_TIME_PASSES);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CropFarmingInstructions_YourCropsWillGrowOnlyIf);
    TalkClose();
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PlayBGM(AUDIO_START_WEAK, AUDIO_RECORD_GRIFFIN_BLUE);
    var_0 = 0;
    do
    {
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_PREPARE);
        WaitFrames(20);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_POUR);
        PlaySong(AUDIO_START, AUDIO_SFX_WATERING_CAN_POUR);
        WaitFrames(48);
        switch (var_0)
        {
            case 0:
                NoOpTutorialFieldTile(8, 0, 2, 0, 2);
                break;
            case 1:
                NoOpTutorialFieldTile(8, 1, 2, 0, 2);
                break;
            case 2:
                NoOpTutorialFieldTile(8, 2, 2, 0, 2);
                break;
        }
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
        MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) + 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
        SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
        var_0 = var_0 + 1;
    }
    while (var_0 < 3);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) - 32), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_UP);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_PREPARE);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_POUR);
    PlaySong(AUDIO_START, AUDIO_SFX_WATERING_CAN_POUR);
    WaitFrames(48);
    NoOpTutorialFieldTile(7, 2, 2, 0, 2);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) - 32), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_UP);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) - 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
    var_0 = 0;
    do
    {
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_PREPARE);
        WaitFrames(20);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_POUR);
        PlaySong(AUDIO_START, AUDIO_SFX_WATERING_CAN_POUR);
        WaitFrames(48);
        switch (var_0)
        {
            case 0:
                NoOpTutorialFieldTile(6, 2, 2, 0, 2);
                break;
            case 1:
                NoOpTutorialFieldTile(6, 1, 2, 0, 2);
                break;
            case 2:
                NoOpTutorialFieldTile(6, 0, 2, 0, 2);
                break;
        }
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
        SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_UP);
        SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
        MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) - 16), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
        SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_RIGHT);
        var_0 = var_0 + 1;
    }
    while (var_0 < 3);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) + 32), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_DOWN);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_PREPARE);
    WaitFrames(20);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_WATERING_CAN_POUR);
    PlaySong(AUDIO_START, AUDIO_SFX_WATERING_CAN_POUR);
    WaitFrames(48);
    NoOpTutorialFieldTile(7, 0, 2, 0, 2);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    WaitFrames(60);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StopBGM();
    WaitFrames(30);
    SetEntityPosition(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) + 32), Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) + 16), FACING_LEFT);
    NoOpTutorialFieldTile(6, 0, 1, 0, 5);
    NoOpTutorialFieldTile(6, 1, 1, 0, 5);
    NoOpTutorialFieldTile(6, 2, 1, 0, 5);
    NoOpTutorialFieldTile(7, 0, 1, 0, 5);
    NoOpTutorialFieldTile(7, 1, 1, 0, 2);
    NoOpTutorialFieldTile(7, 2, 1, 0, 5);
    NoOpTutorialFieldTile(8, 0, 1, 0, 5);
    NoOpTutorialFieldTile(8, 1, 1, 0, 5);
    NoOpTutorialFieldTile(8, 2, 1, 0, 5);
    PlaySong(AUDIO_START, AUDIO_SFX_TIME_PASSES);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CropFarmingInstructions_ContinueWateringAndYourCropsWill);
    TalkClose();
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    PlayBGM(AUDIO_START_WEAK, AUDIO_RECORD_GRIFFIN_BLUE);
    NoOpTutorialFieldTile(8, 0, 1, 0, 0);
    PlaySong(AUDIO_START, AUDIO_SFX_PICK_UP_ITEM);
    SetPlayerHeldFood(ITEM_FOOD_TURNIP);
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CropFarmingInstructions_OnceCropsBloomTheAButton);
    TalkClose();
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_UP);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_RUN_HOLDING_ITEM);
    MoveEntityYTo(ENTITY_TUTORIAL_PLAYER, Y(GetEntityY(ENTITY_TUTORIAL_PLAYER) - 24), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityFacing(ENTITY_TUTORIAL_PLAYER, FACING_LEFT);
    MoveEntityXTo(ENTITY_TUTORIAL_PLAYER, X(GetEntityX(ENTITY_TUTORIAL_PLAYER) - 120), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_TUTORIAL_PLAYER);
    SetEntityAnim(ENTITY_TUTORIAL_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    WaitFrames(20);
    PlaySong(AUDIO_START, AUDIO_SFX_THROW_ITEM);
    UsePlayerHeldItem();
    PlaySong(AUDIO_START, AUDIO_SFX_SHIPMENT_DEPOSIT);
    StartShipmentBoxDepositAnimation();
    TalkOpen();
    TalkMessage(gText_TutorialEvent_CropFarmingInstructions_ToShipHarvestedCropsTheA);
    TalkClose();
    WaitFrames(60);
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    StopBGM();
    return;
}
