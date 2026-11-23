#ifndef GAME_SCENE_HH
#define GAME_SCENE_HH

#include "scene.hh"
#include "fomt_constants.hh"

// Memorial pieces are assembled by this scene and its save-image helper.
extern char const gText_AnimalMemorial_LineBreak[];
extern char const gText_AnimalMemorial_Continue[];
extern char const gText_AnimalMemorial_PageBreak[];
extern char const gText_AnimalMemorial_Header[];
extern char const gText_AnimalMemorial_FarmPrefix[];
extern char const gText_AnimalMemorial_PassedAway[];
extern char const gText_AnimalMemorial_NamesIntro[];
extern char const gText_AnimalMemorial_PrayerIntro[];
extern char const gText_AnimalMemorial_PrayerEnding[];
extern char const gText_AnimalMemorial_PassedNaturalLife[];

struct GameSceneState;
struct GameStateSaveImage;
// The town-map return packet stores a byte flag, a 16-bit map field and
// signed coordinates. Its natural padding remains untouched when unused.
struct GameSceneTownMapSelection {
    bool has_selection;
    MaryMapId map : 16;
    i16 x;
    i16 y;
};
typedef char GameSceneTownMapSelectionSizeCheck[sizeof(GameSceneTownMapSelection) == 8 ? 1 : -1];
typedef char GameSceneTownMapSelectionFlagCheck[offsetof(GameSceneTownMapSelection, has_selection) == 0 ? 1 : -1];
typedef char GameSceneTownMapSelectionXCheck[offsetof(GameSceneTownMapSelection, x) == 4 ? 1 : -1];
typedef char GameSceneTownMapSelectionYCheck[offsetof(GameSceneTownMapSelection, y) == 6 ? 1 : -1];

// The return transition and the native GameScene constructor copy this whole
// three-word record. Only its first word is initialized by the shop commands;
// the remaining payload is not assumed to be zero or given guessed meanings.
struct GameSceneResumeRequest {
    enum Kind {
#if defined(REGION_JP)
        AFTER_SUPERMARKET_SHOP = 9,
        AFTER_SUPERMARKET_PURCHASE = 10,
        AFTER_WON_SHOP = 11,
        AFTER_CARPENTER_SHOP = 12,
        AFTER_BLACKSMITH_SHOP = 13,
        AFTER_CLINIC_SHOP = 14,
        AFTER_BEACH_CAFE_SHOP = 15,
        AFTER_YODEL_RANCH_SHOP = 0x10,
        AFTER_WINERY_SHOP = 0x11,
        AFTER_INN_SHOP = 0x12,
        AFTER_POULTRY_FARM_SHOP = 0x13,
        AFTER_SPECIAL_MERCHANT_SHOP = 0x15,
        AFTER_GIFT_WRAPPING = 0x16,
        AFTER_REFERENCE_PAGE = 0x17,
        AFTER_CALENDAR = 0x18,
        AFTER_TOOL_CHEST = 0x19,
        AFTER_REFRIGERATOR = 0x1A,
        AFTER_SHELF = 0x1B,
        AFTER_CLOCK = 0x1C,
        AFTER_COOKING_MENU = 0x1D,
        AFTER_RECIPE_LIST = 0x1E,
        AFTER_GAMECUBE_LINK = 0x1F,
        AFTER_HARVEST_SPRITE_ANIMALCARE_MINIGAME = 0x20,
        AFTER_HARVEST_SPRITE_HARVESTING_MINIGAME = 0x21,
        AFTER_HARVEST_SPRITE_WATERING_MINIGAME = 0x22,
        AFTER_CHICKEN_FESTIVAL_CONTEST = 0x23,
        AFTER_HORSE_RACE = 0x24,
        AFTER_HORSE_RACE_MEDAL_EXCHANGE = 0x25,
        AFTER_FRISBEE_GAME = 0x26,
        AFTER_FRISBEE_SCOREBOARD = 0x27,
        AFTER_FARM_INHERITANCE_FLASHBACK = 0x28,
        AFTER_TOWN_MAP = 0x29,
        AFTER_RUCKSACK_MENU = 0x2A,
        AFTER_NAME_ENTRY = 0x2B,
        AFTER_FESTIVAL_ANIMAL_SELECTION = 0x2C,
        AFTER_STAFF_CREDITS = 0x2D,
        AFTER_FARMING_TUTORIAL = 0x2E,
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
        AFTER_SUPERMARKET_SHOP = 10,
        AFTER_SUPERMARKET_PURCHASE = 11,
        AFTER_WON_SHOP = 12,
        AFTER_CARPENTER_SHOP = 13,
        AFTER_BLACKSMITH_SHOP = 14,
        AFTER_CLINIC_SHOP = 15,
        AFTER_BEACH_CAFE_SHOP = 16,
        AFTER_YODEL_RANCH_SHOP = 0x11,
        AFTER_WINERY_SHOP = 0x12,
        AFTER_INN_SHOP = 0x13,
        AFTER_POULTRY_FARM_SHOP = 0x14,
        AFTER_SPECIAL_MERCHANT_SHOP = 0x16,
        AFTER_GIFT_WRAPPING = 0x17,
        AFTER_REFERENCE_PAGE = 0x18,
        AFTER_CALENDAR = 0x19,
        AFTER_TOOL_CHEST = 0x1A,
        AFTER_REFRIGERATOR = 0x1B,
        AFTER_SHELF = 0x1C,
        AFTER_CLOCK = 0x1D,
        AFTER_COOKING_MENU = 0x1E,
        AFTER_RECIPE_LIST = 0x1F,
        AFTER_GAMECUBE_LINK = 0x20,
        AFTER_HARVEST_SPRITE_ANIMALCARE_MINIGAME = 0x21,
        AFTER_HARVEST_SPRITE_HARVESTING_MINIGAME = 0x22,
        AFTER_HARVEST_SPRITE_WATERING_MINIGAME = 0x23,
        AFTER_CHICKEN_FESTIVAL_CONTEST = 0x24,
        AFTER_HORSE_RACE = 0x25,
        AFTER_HORSE_RACE_MEDAL_EXCHANGE = 0x26,
        AFTER_FRISBEE_GAME = 0x27,
        AFTER_FRISBEE_SCOREBOARD = 0x28,
        AFTER_FARM_INHERITANCE_FLASHBACK = 0x29,
        AFTER_TOWN_MAP = 0x2A,
        AFTER_RUCKSACK_MENU = 0x2B,
        AFTER_NAME_ENTRY = 0x2C,
        AFTER_FESTIVAL_ANIMAL_SELECTION = 0x2D,
        AFTER_STAFF_CREDITS = 0x2E,
        AFTER_FARMING_TUTORIAL = 0x2F,
#endif
    };
    i32 kind;
    union {
        u8 unk_04[8];
        GameSceneTownMapSelection town_map_selection;
        MaryGameCubeLinkResult gamecube_link_result;
        bool harvest_sprite_minigame_succeeded;
    };

    // Native requests initialize only kind; the remaining payload is opaque.
    GameSceneResumeRequest() {}
    explicit GameSceneResumeRequest(i32 value) : kind(value) {}
    GameSceneResumeRequest(GameSceneResumeRequest const & other)
    {
        *this = other;
    }

};

typedef char GameSceneResumeRequestSizeCheck[sizeof(GameSceneResumeRequest) == 12 ? 1 : -1];
struct GameSceneScriptRequest;
struct GameSceneBgmSettings;
struct GameSceneSongPlayerPool;
struct GameTime;
struct RucksackItem;
struct FishingCatchResult;
struct HardwareSpriteBufferState;

#pragma interface "game_scene.hh"

struct GameScene : AScene {
    GameScene(GameStateSaveImage * image, GameSceneResumeRequest const & request);
#if defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    explicit GameScene(GameStateSaveImage * image);
#endif
    virtual ~GameScene();
    virtual SceneTransitionOwner Run();

    GameSceneState * state;

    void SetEntityPosition(u32 id, i32 x, i32 y, u32 facing);
    void RelocateEntityToMap(i32 entity_id, u32 map, i32 x, i32 y, u32 facing);
    i32 GetEntityX(u32 id);
    i32 GetEntityY(u32 id);
    void SetEntityFacing(u32 id, u32 facing);
    u32 GetEntityFacing(u32 id);
    u32 GetEntityMap(u32 id);
    void SetEntitySpritePriority(u32 id, u32 priority);
    void MoveEntityXTo(u32 id, u32 target, i32 speed_q16);
    void MoveEntityYTo(u32 id, u32 target, i32 speed_q16);
    void WaitForEntityMovement(u32 id);
    void SetEntityAnim(u32 id, u32 animation);
    void NoOp014(i32 unused_value);
    void HideEntity(u32 id);
    void OffsetEntityPosition(u32 id, i32 delta_x, i32 delta_y);
    void StartEntityEffect(u32 id, u32 effect, u32 persistent);
    void StopEntityEffect(u32 id);
    void SetEntityAuxRenderProfile(u32 id, u32 profile);
    void ChangeMap(u32 map, i32 x, i32 y);
    void PanCameraTo(i32 x, i32 y, u32 speed);
    void WaitForCameraMovement();
    void PlayBGM(i32 mode, u32 sequence, GameSceneBgmSettings const & settings);
    void StopBGM();
    void PlaySong(i32 mode, u32 sequence);
    void StopAllSongs();
    void OpenSupermarketShop();
    void OpenSupermarketPurchase(MarySupermarketItemId item);
    void OpenBeachCafeShop();
    void OpenYodelRanchShop();
    void OpenWineryShop();
    void OpenInnShop();
    void OpenPoultryFarmShop();
    void OpenSpecialMerchantShop();
    void OpenGiftWrappingMenu();
    void ShowReferencePage(i32 page_id);
    void OpenBookList();
    void OpenLetterList();
    void OpenCalendar();
    void OpenToolChest();
    void OpenRefrigerator();
    void OpenShelf();
    void OpenClock();
    void OpenCookingMenu();
    void OpenRecipeList();
    void RunGameCubeLink();
    void StartFarmInheritanceFlashback();
    void OpenRucksackMenu();
    void OpenTownMap(u8 allow_teleport);
    void SelectFestivalAnimal(MaryFestivalAnimalKind kind);
    void RunStaffCredits();
    void OpenFarmingTutorial(MaryFarmingTutorialKind kind);
    void OpenNameEntry(MaryNameEntryKind kind, MaryNameEntryTargetIndex target_index);
    void FlashScreenColor(u32 color);
    void RebuildMapEntitiesForNewDay();
    void RunHarvestSpriteAnimalCareMinigame(MaryCharacterId sprite_id);
    void RunHarvestSpriteHarvestingMinigame(MaryCharacterId sprite_id);
    void RunHarvestSpriteWateringMinigame(MaryCharacterId sprite_id);
    void OpenWonShop();
    void OpenCarpenterShop();
    void OpenBlacksmithShop();
    void OpenClinicShop();
    void TalkOpen();
    void TalkResetUi();
    void TalkClose();
    void TalkMessage(char const * text, u32 rate);
    void TalkTelevisionMessage(char const * text);
    void TalkSetNameplateCharacter(u32 id);
    void TalkSetNameplateText(char const * text);
    void TalkClearNameplate();
    void TalkSetPortrait(u32 id);
    void TalkClearPortrait();
    void TalkShowHeartIndicator(u32 id);
    void TalkHideHeartIndicator();
    void TalkPromptChoices(char const * prompt, char const * first, char const * second,
        char const * third, char const * fourth);
    void TalkChoices(char const * first, char const * second, char const * third,
        char const * fourth, char const * fifth, char const * sixth);
    void FadeScreen(u32 style, i32 speed, bool fade_out, bool call_scene_hook);
    void TextVariableSetNumber(u32 slot, i32 value);
    void TextVariableSetString(u32 slot, char const * text);
    void TextVariableSetNumberFieldWidth(u32 slot, i32 value, u32 width);
    void CallScript(i32 script_id, i32 context_value);
    void QueueScript(GameSceneScriptRequest const & request, i32 queue_kind);
    void WaitFrames(i32 frames);
    // The native command borrows the script VM's packed hour/minute value.
    void SetGameTime(GameTime const & time);
    void RunChickenFestivalContest();
    void RunHorseRace(MaryFestivalHorseRaceMode mode);
    void OpenHorseRaceMedalExchange();
    void RunFrisbeeGame(bool contest);
    void ShowFrisbeeScoreboard();
    void PrepareClockMenuTransition();
    void RestoreAfterClockMenu();
    void PrepareCookingMenuTransition();
    void RestoreAfterCookingMenu();
    void PrepareRecipeMenuTransition();
    void RestoreAfterRecipeMenu();
    void RefreshBarnFeedTrough(MaryBarnFeedTroughIndex trough);
    void RefreshChickenFeedTrough(MaryChickenCoopFeedTroughIndex trough);
    void StartShipmentBoxDepositAnimation();
    bool IsPlayerRidingHorse();
    bool TryShipPlayerHeldItem();
    bool SetPlayerHeldItem(RucksackItem const & item, bool wrapped);
    bool GivePlayerBasket();
    void ThrowPlayerHeldItem();
    void UsePlayerHeldItem();
    void ClearPlayerHeldItem();
    MaryItemArticleId RemoveRecordPlayerAlbum();
    MaryItemArticleId SwapRecordPlayerAlbum(MaryItemArticleId article);
    void SetEntityEventScript(u32 entity_id, MaryScriptId script_id);
    void ClearEntityEventScript(u32 entity_id);
    void SetTelevisionProgram(MaryTelevisionProgramId program);
    void EndTelevisionProgram();
    void EnableScriptedNpcControl();
    void DisableScriptedNpcControl();
    void LightFireplaceAtLocation(MaryMapId map);
    void SetVaseArticleId(MaryItemArticleId article);
    void BeginEggIncubation(MaryChickenCoopIncubatorIndex incubator);
    void RefreshAllNpcSchedules();
    void ChangePlayerStaminaAndFatigue(MaryStaminaDelta stamina_delta,
        MaryFatigueDelta fatigue_delta);
    void CreateFarmHorse(MaryBool skip_creation, MaryAnimalHorseAgeStage age_stage,
        MaryMapId map, MaryMapSpaceX x, MaryMapSpaceY y);
    void RemoveFarmHorse(MaryBool skip_removal, i32 unused_value);
    MaryAnimalSlotIndex GetInteractingAnimalIndex();
    bool IsPlayerHoldingTool();
    void BeginHoldingActorGraphic(MaryAnimationId animation_id);
    void ObtainPowerBerry();
    void ObtainMysticBerry();
    bool IsHarvestSpriteDailyWorkComplete(MaryCharacterId sprite_id);
    MaryHeldItemKind GetPresentedItemKind();
    i32 GetPresentedItemId();
    bool IsPresentedItemGiftWrapped();
    FishingCatchResult const * GetCaughtFish();
    bool IsBackgroundMusicActive();
    void StartWorldBackgroundMusic();
    // Returns whether a fade was requested; it does not wait for completion.
    bool FadeOutBackgroundMusic();
    void CreatePlayerChildEntity();
    void SetContestAnimal(MaryAnimalKind animal_kind, MaryAnimalSlotIndex animal_index);
    void ClearContestAnimal(MaryAnimalKind animal_kind);
    MaryAnimalSlotIndex GetContestAnimalIndex(MaryAnimalKind animal_kind);
    void OpenDoor(MaryDoorIndex door_index);
    void CloseDoor(MaryDoorIndex door_index);
    void RedrawRucksackShelfAfterPurchase();
    void RedrawBlueFeatherShelfAfterPurchase();
    void func_08016C10();
    void CreateNewYearSunriseEffect();
    void PlayNewYearSunriseEffect();
    void DestroyNewYearSunriseEffect();
    void PlayStarSparkleEffect();
    void EnterHotSpringBathingState();
    void ExitHotSpringBathingState();
    void RefreshEntity(MaryEntityId entity_id);
    void RemoveEntity(MaryEntityId entity_id);
    void PreservePlayerLocationForNextDay();
    void ClearPreservedPlayerLocation();
    MaryMapId GetPreservedPlayerMapId();
    void EatRandomMeal();
    void PreparePlayerForScriptedAnimation();
    void RestorePlayerAfterScriptedAnimation();
    void CreateEventIcon(MaryEventIconSlot slot, MaryMapSpaceX x, MaryMapSpaceY y,
        MaryEventIconLayer layer, MaryEventIconId icon_id);
    void RemoveEventIcon(MaryEventIconSlot slot);
    void SetPlayerActorUpdateSuspended(MaryBool suspended);
    void ShowPlayerHoldingTool(MaryItemToolId tool_id);
    void CureAllSickLivestock();
};

typedef char GameSceneSizeCheck[sizeof(GameScene) == 8 ? 1 : -1];
typedef char GameSceneStatePointerCheck[offsetof(GameScene, state) == 4 ? 1 : -1];

EXTERN_C

void UpdateGameSceneHardwareFrame(GameSceneState * state, HardwareSpriteBufferState * buffer);
GameSceneSongPlayerPool & GetSceneSongPlayerPool(GameScene & scene);

EXTERN_C_END




#pragma interface "game_scene.hh"


#if defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern char const gText_AnimalMemorial_FarmSuffix[];
#endif
#if defined(REGION_DE)
extern char const gText_AnimalMemorial_DeathHeader[];
extern char const gText_AnimalMemorial_DeathFarmPrefix[];
#endif

#endif // GAME_SCENE_HH
