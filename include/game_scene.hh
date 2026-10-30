#ifndef GAME_SCENE_HH
#define GAME_SCENE_HH
#include "shop_common.hh"

#include "prelude.h"
#include <stdlib.h>
#include "game_state.hh"
#include "scene.hh"
#include "entity_actor.hh"
#include "ui_state.hh"
#include "scene_dialogue.hh"
#include "hardware_display_state.hh"
#include "hardware_sprite_buffer.hh"
#include "script_engine.hh"
#include "fomt_constants.hh"
#include "utility/vec2.hh"
#include "resource_handle.hh"
#include "hardware_resource.hh"
#include "hardware_state_clear.hh"
#include "hardware_state_accessors.hh"
#include "hardware_blend.hh"
#include "hardware_music_player.hh"
#include "time_of_day.hh"
#include "field_render_farm_house_data.hh"
#include "game_world.hh"
#include "player_actor.hh"
#include "livestock_actor.hh"

#include "scene_text_variables.hh"
#include "scene_clock.hh"

#pragma interface "game_scene.hh"

struct GameObject;
struct GameScene;
struct GameStateSaveImage;
struct MusicPlayer;
struct GameSceneIndexedSprite;
struct HardwareBlendController;
struct FieldRenderRectDescriptor;
struct FieldRenderTileAttributes;
struct HardwareDmaQueue;

// Unrecovered scene UI components keep their shared destruction prefix.
// The time window uses the real MapClockStatusHudWidget owner in scene_clock.hh.
struct GameSceneUiComponent {
    u32 unk_00;
    // Actual existing bootstrap lifecycle ABI; these declarations emit no code.
    GameSceneUiComponent() asm("__17HardwareBootstrap");
    virtual ~GameSceneUiComponent() asm("_._17HardwareBootstrap");
};

struct GameSceneUiComponentOwner {
    GameSceneUiComponent * value;

    GameSceneUiComponentOwner() : value(nullptr) {}
    explicit GameSceneUiComponentOwner(GameSceneUiComponent * input) : value(input) {}
    ~GameSceneUiComponentOwner() { delete value; }
    GameSceneUiComponentOwner & operator=(GameSceneUiComponent * next)
    {
        if (next != value)
            delete value;
        value = next;
        return *this;
    }
};

struct GameSceneTalkWindowOwner {
    UiStateOwner * value;

    GameSceneTalkWindowOwner() : value(nullptr) {}
    ~GameSceneTalkWindowOwner() { delete value; }
    UiStateOwner * Get() const { return value; }
    GameSceneTalkWindowOwner & operator=(UiStateOwner * next)
    {
        if (next != value)
            delete value;
        value = next;
        return *this;
    }
};

struct GameSceneBgmSettings {
    GameSceneBgmSettings()
        : tempo(0x100), volume(0x100), pitch(0), pan(0),
          modulation_depth(0), lfo_speed(0) {}

    u16 tempo;
    u16 volume;
    i16 pitch;
    i8 pan;
    u8 modulation_depth;
    u8 lfo_speed;
};

// Entries point to the scene's pointer slots, not directly to m4a players.
// The empty allocator occupies a word before the capacity pointer at +0x0C.
struct GameSceneSongPlayerPool {
    struct Allocator {
        Allocator() {}
        Allocator(Allocator const &) {}
    };
    struct Allocation {
        Allocator allocator;
        HardwareMusicPlayerSlot ** end;
        Allocation(Allocator const & input) : allocator(input), end(nullptr) {}
    };
    HardwareMusicPlayerSlot ** begin;
    HardwareMusicPlayerSlot ** end;
    Allocation allocation;

    ~GameSceneSongPlayerPool()
    {
        if (begin != nullptr)
            free(begin);
    }

    GameSceneSongPlayerPool(Allocator const & input = Allocator())
        : begin(nullptr), end(nullptr), allocation(input) {}
};

// Each pending request is passed unchanged to LoadById(id, context).
struct GameSceneScriptRequest {
    GameSceneScriptRequest() {}
    GameSceneScriptRequest(i32 script, i32 context)
        : script_id(script), context_value(context) {}

    i32 script_id;
    i32 context_value;
};

template <u32 Capacity>
struct GameSceneScriptQueue {
    GameSceneScriptQueue() : count(0) {}

    u32 count;
    // Only [Data(), End()) contains constructed requests. Native construction
    // leaves the remaining capacity untouched; insertion uses placement new.
    u32 storage[Capacity * 2];

    GameSceneScriptRequest * Data()
    {
        return reinterpret_cast<GameSceneScriptRequest *>(storage);
    }
    GameSceneScriptRequest * End()
    {
        return &reinterpret_cast<GameSceneScriptRequest *>(storage)[count];
    }

    // Native insertion drops a full queue; it does not grow or overwrite it.
    inline void Push(GameSceneScriptRequest const & request);
};

// The native cleanup owns all three adjacent queues and destroys them in
// reverse order. Its out-of-line destructor still has a native implementation.
struct GameSceneScriptQueues {
    ~GameSceneScriptQueues();

    GameSceneScriptQueue<2> queue_0;
    GameSceneScriptQueue<40> queue_1;
    GameSceneScriptQueue<1> queue_2;
};

typedef char GameSceneScriptQueuesSizeCheck[sizeof(GameSceneScriptQueues) == 0x164 ? 1 : -1];
typedef char GameSceneScriptQueuesFirstCheck[offsetof(GameSceneScriptQueues, queue_0) == 0 ? 1 : -1];
typedef char GameSceneScriptQueuesSecondCheck[offsetof(GameSceneScriptQueues, queue_1) == 0x14 ? 1 : -1];
typedef char GameSceneScriptQueuesThirdCheck[offsetof(GameSceneScriptQueues, queue_2) == 0x158 ? 1 : -1];

// The four reusable records back entity slots 70-73, not particular NPCs.
// Actors write their location and animation back here when destroyed; the
// independently stored event-script halfword is read by their script hook.
// See docs/mary-native-audit/entities/entity_event_script_audit.md.
struct GameSceneControllerActorRecord {
    GameSceneControllerActorRecord();

    ActorLocation location;
    u16 animation;
    u16 event_script;
};

// Six event-local icon slots, in map-local pixels rather than screen pixels.
// Native creation stores layer & 3 and a u16 icon ID; neither entry checks slots.
// Construction initializes only state and location, preserving all other bits.
// See docs/mary-native-audit/entities/event_icon_callables.md.
struct GameSceneEventIconRecord {
    GameSceneEventIconRecord();

    u8 state : 2;
    u8 layer : 2;
    u8 unk_00_04 : 4;
    u8 unk_01;
    Location location;
    u16 icon_id;
    u8 unk_0A[2];
};

typedef char GameSceneControllerActorRecordSizeCheck[sizeof(GameSceneControllerActorRecord) == 12 ? 1 : -1];
typedef char GameSceneControllerActorAnimationCheck[offsetof(GameSceneControllerActorRecord, animation) == 8 ? 1 : -1];
typedef char GameSceneControllerActorScriptCheck[offsetof(GameSceneControllerActorRecord, event_script) == 10 ? 1 : -1];
typedef char GameSceneEventIconRecordSizeCheck[sizeof(GameSceneEventIconRecord) == 12 ? 1 : -1];
typedef char GameSceneEventIconLocationOffsetCheck[offsetof(GameSceneEventIconRecord, location) == 2 ? 1 : -1];
typedef char GameSceneEventIconIdOffsetCheck[offsetof(GameSceneEventIconRecord, icon_id) == 8 ? 1 : -1];

// The native clock slot has four-byte storage, unlike the packed GameTime.
// Construction preserves its unknown bits; saving copies only the low halfword.
struct GameScenePreservedClock {
    u16 clock_hour : 5;
    u16 clock_minute : 6;
    u16 unk_11 : 5;

    GameScenePreservedClock() : clock_hour(6), clock_minute(0) {}
};

// This native overnight record saves the map and clock, not coordinates.
struct GameScenePreservedPlayerLocation {
    u8 active;
    u8 unk_01[3];
    MaryMapId map;
    GameScenePreservedClock time;

    MaryMapId GetMapId() const { return map; }

    GameScenePreservedPlayerLocation()
        : active(0), map(MAP_FARMHOUSE) {}
};

// Startup controller, distinct from the eight-byte GameScene wrapper. Both
// constructors, Run and destruction are recovered. The first word is AScene's
// actual inherited vptr, not manually written payload.
struct GameSceneScriptController : AScene {
    GameSceneScriptController(GameStateSaveImageOwner save);
    GameSceneScriptController(char const * farm_name, char const * player_name,
        GameDate birthday, char const * dog_name);
    virtual ~GameSceneScriptController();
    virtual SceneTransitionOwner Run();

    GameStateSaveImageOwner save;
    ScriptEngine script_engine;
    u8 unk_364;
    u8 unk_365[3];
    u32 unk_368;
    GameScenePreservedPlayerLocation preserved_player_location;
    GameSceneScriptQueues queues;
    GameSceneEventIconRecord event_icon_records[6];
    GameSceneControllerActorRecord actor_records[4];
};

typedef char GameSceneScriptRequestSizeCheck[sizeof(GameSceneScriptRequest) == 8 ? 1 : -1];
typedef char GameSceneControllerSaveCheck[offsetof(GameSceneScriptController, save) == 4 ? 1 : -1];
typedef char GameSceneControllerEngineCheck[offsetof(GameSceneScriptController, script_engine) == 8 ? 1 : -1];
typedef char GameSceneControllerUnk364Check[offsetof(GameSceneScriptController, unk_364) == 0x364 ? 1 : -1];
typedef char GameSceneControllerUnk368Check[offsetof(GameSceneScriptController, unk_368) == 0x368 ? 1 : -1];
typedef char GameSceneControllerPreservedLocationCheck[offsetof(GameSceneScriptController, preserved_player_location) == 0x36C ? 1 : -1];
typedef char GameSceneControllerPreservedLocationSizeCheck[sizeof(GameScenePreservedPlayerLocation) == 12 ? 1 : -1];
typedef char GameSceneControllerPreservedClockSizeCheck[sizeof(GameScenePreservedClock) == 4 ? 1 : -1];
typedef char GameSceneControllerPreservedFlagCheck[offsetof(GameScenePreservedPlayerLocation, active) == 0 ? 1 : -1];
typedef char GameSceneControllerPreservedMapCheck[offsetof(GameScenePreservedPlayerLocation, map) == 4 ? 1 : -1];
typedef char GameSceneControllerPreservedTimeCheck[offsetof(GameScenePreservedPlayerLocation, time) == 8 ? 1 : -1];
typedef char GameSceneControllerQueuesCheck[offsetof(GameSceneScriptController, queues) == 0x378 ? 1 : -1];
typedef char GameSceneControllerQueue0Check[offsetof(GameSceneScriptController, queues.queue_0) == 0x378 ? 1 : -1];
typedef char GameSceneControllerQueue1Check[offsetof(GameSceneScriptController, queues.queue_1) == 0x38C ? 1 : -1];
typedef char GameSceneControllerQueue2Check[offsetof(GameSceneScriptController, queues.queue_2) == 0x4D0 ? 1 : -1];
typedef char GameSceneControllerEventIconArrayCheck[offsetof(GameSceneScriptController, event_icon_records) == 0x4DC ? 1 : -1];
typedef char GameSceneControllerActorArrayCheck[offsetof(GameSceneScriptController, actor_records) == 0x524 ? 1 : -1];
typedef char GameSceneControllerSizeCheck[sizeof(GameSceneScriptController) == 0x554 ? 1 : -1];

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
        AFTER_SHELF = 0x19,
        AFTER_CHICKEN_FESTIVAL_CONTEST = 0x23,
        AFTER_HORSE_RACE = 0x24,
        AFTER_HORSE_RACE_MEDAL_EXCHANGE = 0x25,
        AFTER_FRISBEE_GAME = 0x26,
        AFTER_FRISBEE_SCOREBOARD = 0x27,
#else
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
        AFTER_SHELF = 0x1A,
        AFTER_CHICKEN_FESTIVAL_CONTEST = 0x24,
        AFTER_HORSE_RACE = 0x25,
        AFTER_HORSE_RACE_MEDAL_EXCHANGE = 0x26,
        AFTER_FRISBEE_GAME = 0x27,
        AFTER_FRISBEE_SCOREBOARD = 0x28,
#endif
    };
    i32 kind;
    u8 unk_04[8];

    // Native requests initialize only kind; the remaining payload is opaque.
    GameSceneResumeRequest() {}
    explicit GameSceneResumeRequest(i32 value) : kind(value) {}
    GameSceneResumeRequest(GameSceneResumeRequest const & other)
    {
        *this = other;
    }

};

#include "scene_supermarket.hh"
#pragma interface "game_scene.hh"

struct ReturnToGameScene : SceneTransition {
    ReturnToGameScene(GameStateSaveImage * image, GameSceneResumeRequest value)
        : save(image), request(value) {}
    virtual SceneOwner CreateScene();

    GameStateSaveImage * save;
    GameSceneResumeRequest request;
};

typedef char GameSceneResumeRequestSizeCheck[sizeof(GameSceneResumeRequest) == 12 ? 1 : -1];
typedef char ReturnToGameSceneSizeCheck[sizeof(ReturnToGameScene) == 20 ? 1 : -1];
typedef char ReturnToGameSceneRequestCheck[offsetof(ReturnToGameScene, request) == 8 ? 1 : -1];

// Verified modal scene wrappers and transitions, in native factory order.
#include "scene_calendar.hh"
#pragma interface "game_scene.hh"

struct ToolChestSceneCore;
struct ToolChestScene : AScene {
    virtual ~ToolChestScene();
    virtual SceneTransitionOwner Run();

    ToolChestSceneCore * core;
    SceneTransitionOwner continuation;
};

struct ToolChestTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char ToolChestSceneSizeCheck[sizeof(ToolChestScene) == 12 ? 1 : -1];
typedef char ToolChestSceneCoreCheck[offsetof(ToolChestScene, core) == 4 ? 1 : -1];
typedef char ToolChestSceneContinuationCheck[offsetof(ToolChestScene, continuation) == 8 ? 1 : -1];
typedef char ToolChestTransitionSizeCheck[sizeof(ToolChestTransition) == 12 ? 1 : -1];

struct RefrigeratorSceneCore;
struct RefrigeratorScene : AScene {
    virtual ~RefrigeratorScene();
    virtual SceneTransitionOwner Run();

    RefrigeratorSceneCore * core;
    SceneTransitionOwner continuation;
};

struct RefrigeratorTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char RefrigeratorSceneSizeCheck[sizeof(RefrigeratorScene) == 12 ? 1 : -1];
typedef char RefrigeratorSceneCoreCheck[offsetof(RefrigeratorScene, core) == 4 ? 1 : -1];
typedef char RefrigeratorSceneContinuationCheck[offsetof(RefrigeratorScene, continuation) == 8 ? 1 : -1];
typedef char RefrigeratorTransitionSizeCheck[sizeof(RefrigeratorTransition) == 12 ? 1 : -1];

#include "scene_shelf.hh"
#pragma interface "game_scene.hh"

struct CookingSceneCore;
struct CookingScene : AScene {
    virtual ~CookingScene();
    virtual SceneTransitionOwner Run();

    CookingSceneCore * core;
    SceneTransitionOwner continuation;
};

struct CookingTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u8 recipe_list;
};

typedef char CookingSceneSizeCheck[sizeof(CookingScene) == 12 ? 1 : -1];
typedef char CookingSceneCoreCheck[offsetof(CookingScene, core) == 4 ? 1 : -1];
typedef char CookingSceneContinuationCheck[offsetof(CookingScene, continuation) == 8 ? 1 : -1];
typedef char CookingTransitionSizeCheck[sizeof(CookingTransition) == 16 ? 1 : -1];

#include "scene_reference_page.hh"
#pragma interface "game_scene.hh"

#include "scene_special_merchant_shop.hh"
#pragma interface "game_scene.hh"

#include "scene_gift_wrapping.hh"
#pragma interface "game_scene.hh"

#include "scene_winery_shop.hh"
#pragma interface "game_scene.hh"

#include "scene_inn_shop.hh"
#pragma interface "game_scene.hh"

#include "scene_beach_cafe_shop.hh"
#pragma interface "game_scene.hh"

#include "scene_won_shop.hh"
#pragma interface "game_scene.hh"



#include "scene_carpenter_shop.hh"
#pragma interface "game_scene.hh"



#include "scene_yodel_ranch_shop.hh"
#pragma interface "game_scene.hh"

// This saved-target naming operation is distinct from the reusable keyboard.
// The native Run handles the six NAME_ENTRY_* cases and edits the save image.
struct SavedNameEntryScene : AScene {
    SavedNameEntryScene(SceneTransitionOwner next, GameStateSaveImage * image,
        MaryNameEntryKind input_kind, u8 index)
        : continuation(next), save(image), kind(input_kind), target_index(index) {}
    virtual SceneTransitionOwner Run();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryNameEntryKind kind;
    u8 target_index;
};

struct SavedNameEntryTransition : SceneTransition {
    SavedNameEntryTransition(SceneTransitionOwner next, GameStateSaveImage * image,
        MaryNameEntryKind input_kind, u8 index)
        : continuation(next), save(image), kind(input_kind), target_index(index) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryNameEntryKind kind;
    u8 target_index;
};
typedef char SavedNameEntrySceneSizeCheck[sizeof(SavedNameEntryScene) == 20 ? 1 : -1];
typedef char SavedNameEntryTransitionSizeCheck[sizeof(SavedNameEntryTransition) == 20 ? 1 : -1];
typedef char SavedNameEntrySceneContinuationCheck[offsetof(SavedNameEntryScene, continuation) == 4 ? 1 : -1];
typedef char SavedNameEntrySceneSaveCheck[offsetof(SavedNameEntryScene, save) == 8 ? 1 : -1];
typedef char SavedNameEntrySceneKindCheck[offsetof(SavedNameEntryScene, kind) == 12 ? 1 : -1];
typedef char SavedNameEntryTransitionContinuationCheck[offsetof(SavedNameEntryTransition, continuation) == 4 ? 1 : -1];
typedef char SavedNameEntryTransitionSaveCheck[offsetof(SavedNameEntryTransition, save) == 8 ? 1 : -1];
typedef char SavedNameEntryTransitionKindCheck[offsetof(SavedNameEntryTransition, kind) == 12 ? 1 : -1];
typedef char SavedNameEntrySceneIndexCheck[offsetof(SavedNameEntryScene, target_index) == 16 ? 1 : -1];
typedef char SavedNameEntryTransitionIndexCheck[offsetof(SavedNameEntryTransition, target_index) == 16 ? 1 : -1];

#include "scene_poultry_farm_shop.hh"
#pragma interface "game_scene.hh"

struct ClockTransition : SceneTransition {
    virtual SceneOwner CreateScene();
    GameStateSaveImage * save;
    SceneTransitionOwner continuation;
};
typedef char ClockTransitionSizeCheck[sizeof(ClockTransition) == 12 ? 1 : -1];
typedef char ClockTransitionOwnerCheck[offsetof(ClockTransition, continuation) == 8 ? 1 : -1];

struct GameSceneBlendOwner {
    HardwareBlendController * value;
    explicit GameSceneBlendOwner(HardwareBlendController * input = nullptr) : value(input) {}
    ~GameSceneBlendOwner() { delete value; }
};

struct GameSceneWorldOwner {
    GameObject * value;
    explicit GameSceneWorldOwner(GameObject * input = nullptr) : value(input) {}
    ~GameSceneWorldOwner() { delete value; }
};

struct GameSceneTextVariablesOwner {
    GameSceneTextVariables * value;
    explicit GameSceneTextVariablesOwner(GameSceneTextVariables * input = nullptr) : value(input) {}
    ~GameSceneTextVariablesOwner() { delete value; }
};

// The native constructor allocates 0xF8 bytes and places its vptr at +0xF4.
// The display shadow at +0x10 is constructed as HardwareDisplayState.
// Other fields are typed only where native construction or use proves them.
#pragma interface "game_scene.hh"
struct GameSceneState {
    GameStateSaveImage * GetSave() const { return save; }
    GameSceneState(GameScene * owner, GameStateSaveImage * image,
        GameSceneResumeRequest const & request);
    HardwareDmaQueue dma_queue;
    HardwareDisplayState display;
    HardwareManagerOwner manager;
    HardwareLinkedList links;
    GameScene * scene;
    GameStateSaveImage * save;
    GameSceneResumeRequest resume_request;
    u32 script_state;
    GameSceneBlendOwner screen_blend;
    SceneTransitionOwner pending_transition;
    GameSceneWorldOwner game_object;
    GameSceneTalkWindowOwner talk_window;
    GameSceneTextVariablesOwner text_variables;
    GameSceneClockWindowOwner time_window;
    GameSceneUiComponentOwner pause_menu_selector;
    HardwareMusicPlayerSlot bgm_player;
    HardwareMusicPlayerSlot music_player_1;
    HardwareMusicPlayerSlot music_player_2;
    HardwareMusicPlayerSlot music_player_3;
    HardwareMusicPlayerSlot music_player_4;
    GameSceneSongPlayerPool song_players;
    u16 wait_frames;
    u16 unk_E2;
    AActorEntity * waiting_entity;
    u8 unk_E8;
    u8 unk_E9;
    u8 unk_EA[6];
    void * unk_F0;
    virtual ~GameSceneState();
};

struct GameScene : AScene {
    GameScene(GameStateSaveImage * image, GameSceneResumeRequest const & request);
#if !defined(REGION_JP)
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
    void OpenShelf();
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
    GameSceneCaughtFish const * GetCaughtFish();
    bool IsBackgroundMusicActive();
    void StartWorldBackgroundMusic();
    // Returns whether a fade was requested; it does not wait for completion.
    bool FadeOutBackgroundMusic();
    void CreatePlayerChildEntity();
    void SetContestAnimal(MaryAnimalKind animal_kind, MaryAnimalSlotIndex animal_index);
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

typedef char GameSceneUiComponentPrefixCheck[sizeof(GameSceneUiComponent) == 8 ? 1 : -1];
typedef char GameSceneUiComponentOwnerSizeCheck[sizeof(GameSceneUiComponentOwner) == 4 ? 1 : -1];
typedef char GameSceneTalkWindowOwnerSizeCheck[sizeof(GameSceneTalkWindowOwner) == 4 ? 1 : -1];
typedef char GameSceneBgmSettingsSizeCheck[sizeof(GameSceneBgmSettings) == 12 ? 1 : -1];
typedef char GameSceneBgmSettingsPitchCheck[offsetof(GameSceneBgmSettings, pitch) == 4 ? 1 : -1];
typedef char GameSceneBgmSettingsLfoCheck[offsetof(GameSceneBgmSettings, lfo_speed) == 8 ? 1 : -1];
typedef char GameSceneSongPlayerPoolSizeCheck[sizeof(GameSceneSongPlayerPool) == 16 ? 1 : -1];
typedef char GameSceneSongPlayerPoolCapacityCheck[offsetof(GameSceneSongPlayerPool, allocation.end) == 12 ? 1 : -1];
typedef char GameSceneStateSizeCheck[sizeof(GameSceneState) == 0xF8 ? 1 : -1];
typedef char GameSceneStateBgmPlayerOffsetCheck[offsetof(GameSceneState, bgm_player) == 0xBC ? 1 : -1];
typedef char GameSceneStateSongPlayersOffsetCheck[offsetof(GameSceneState, song_players) == 0xD0 ? 1 : -1];
typedef char GameSceneStateDmaQueueCheck[offsetof(GameSceneState, dma_queue) == 0 ? 1 : -1];
typedef char GameSceneStateDisplayCheck[offsetof(GameSceneState, display) == 0x10 ? 1 : -1];
typedef char GameSceneStateManagerCheck[offsetof(GameSceneState, manager) == 0x68 ? 1 : -1];
typedef char GameSceneStateLinksCheck[offsetof(GameSceneState, links) == 0x6C ? 1 : -1];
typedef char GameSceneStateSceneCheck[offsetof(GameSceneState, scene) == 0x88 ? 1 : -1];
typedef char GameSceneStateBlendControlCheck[offsetof(GameSceneState, display) +
    offsetof(HardwareDisplayState, blend_control) == 0x60 ? 1 : -1];
typedef char GameSceneStateScreenBlendCheck[offsetof(GameSceneState, screen_blend) == 0xA0 ? 1 : -1];
typedef char GameSceneStateFadeByteE8Check[offsetof(GameSceneState, unk_E8) == 0xE8 ? 1 : -1];
typedef char GameSceneStateFadeByteE9Check[offsetof(GameSceneState, unk_E9) == 0xE9 ? 1 : -1];
typedef char GameSceneStateSaveCheck[offsetof(GameSceneState, save) == 0x8C ? 1 : -1];
typedef char GameSceneStateResumeRequestCheck[offsetof(GameSceneState, resume_request) == 0x90 ? 1 : -1];
typedef char GameSceneStateScriptStateCheck[offsetof(GameSceneState, script_state) == 0x9C ? 1 : -1];
typedef char GameSceneStatePendingTransitionCheck[offsetof(GameSceneState, pending_transition) == 0xA4 ? 1 : -1];
typedef char GameSceneStateGameObjectCheck[offsetof(GameSceneState, game_object) == 0xA8 ? 1 : -1];
typedef char GameSceneStateTalkWindowCheck[offsetof(GameSceneState, talk_window) == 0xAC ? 1 : -1];
typedef char GameSceneStateTalkContextCheck[offsetof(GameSceneState, text_variables) == 0xB0 ? 1 : -1];
typedef char GameSceneStateTimeWindowCheck[offsetof(GameSceneState, time_window) == 0xB4 ? 1 : -1];
typedef char GameSceneStateMenuSelectorCheck[offsetof(GameSceneState, pause_menu_selector) == 0xB8 ? 1 : -1];
typedef char GameSceneStateBgmPlayerCheck[offsetof(GameSceneState, bgm_player) == 0xBC ? 1 : -1];
typedef char GameSceneStateMusicPlayer1Check[offsetof(GameSceneState, music_player_1) == 0xC0 ? 1 : -1];
typedef char GameSceneStateMusicPlayer4Check[offsetof(GameSceneState, music_player_4) == 0xCC ? 1 : -1];
typedef char GameSceneStateSongPlayersCheck[offsetof(GameSceneState, song_players) == 0xD0 ? 1 : -1];
typedef char GameSceneStateWaitFramesCheck[offsetof(GameSceneState, wait_frames) == 0xE0 ? 1 : -1];
typedef char GameSceneStateWaitingEntityCheck[offsetof(GameSceneState, waiting_entity) == 0xE4 ? 1 : -1];
typedef char GameSceneStateUnknownPointerCheck[offsetof(GameSceneState, unk_F0) == 0xF0 ? 1 : -1];
typedef char GameSceneSizeCheck[sizeof(GameScene) == 8 ? 1 : -1];
typedef char GameSceneStatePointerCheck[offsetof(GameScene, state) == 4 ? 1 : -1];

EXTERN_C

// Native modal cores remain opaque here. Calendar, cooking and guide cores
// return a temporary transition owner that the scene must destroy before
// handing back its own continuation; the other listed calls return void.
#if defined(REGION_JP)
void func_0808A09C(ToolChestSceneCore * core);
#else
void func_0808A55C(ToolChestSceneCore * core);
#endif
#if defined(REGION_JP)
void func_0808E23C(RefrigeratorSceneCore * core);
#else
void func_0808E6FC(RefrigeratorSceneCore * core);
#endif
#if defined(REGION_JP)
SceneTransitionOwner func_08094A40(CookingSceneCore * core);
#else
SceneTransitionOwner func_08094F6C(CookingSceneCore * core);
#endif


// The poultry core returns a signed target slot, with -1 meaning no purchase.

// Native shop construction ABI: each constructor consumes *continuation.


#if defined(REGION_JP)
ToolChestScene * loc_0808A678(void *, SceneTransition **, GameStateSaveImage *);
#else
ToolChestScene * func_0808AB38(void *, SceneTransition **, GameStateSaveImage *);
#endif

#if defined(REGION_JP)
RefrigeratorScene * loc_0808E818(void *, SceneTransition **, GameStateSaveImage *);
#else
RefrigeratorScene * func_0808ECD8(void *, SceneTransition **, GameStateSaveImage *);
#endif


#if defined(REGION_JP)
CookingScene * func_08099F0C(void *, SceneTransition **, GameStateSaveImage *, u8);
#else
CookingScene * func_0809A4D4(void *, SceneTransition **, GameStateSaveImage *, u8);
#endif











// The global controller and its subobjects are not yet fully recovered.
extern u8 * gUnk_0300040C;

GameSceneControllerActorRecord * GetSceneActorRecords(void);
GameSceneEventIconRecord * GetSceneEventIconRecords(void);
GameSceneScriptQueue<2> * GetSceneScriptQueue0(void);
GameScenePreservedPlayerLocation * GetScenePreservedPlayerLocation(void);
u8 * func_08010138(void);
u32 func_08010148(void);
ScriptEngine * GetSceneScriptEngine(void);

// Recovered state callbacks retain address names where semantics are unresolved.
void func_080D7F08(GameSceneState * state);
void func_080D7F3C(GameSceneState * state);

// The native scene runner still owns the underlying update loop.
SceneTransitionOwner sub_080D8178(GameSceneState * state);

void UpdateGameSceneHardwareFrame(GameSceneState * state, HardwareSpriteBufferState * buffer);

EXTERN_C_END

inline GameSceneScriptController::GameSceneScriptController(GameStateSaveImageOwner input)
    : save(input.release()), script_engine(save.get()), unk_364(0)
{
    gUnk_0300040C = reinterpret_cast<u8 *>(this);
}

inline GameSceneScriptController::GameSceneScriptController(char const * farm_name,
    char const * player_name, GameDate birthday, char const * dog_name)
    : save(new GameStateSaveImage(farm_name, player_name, birthday, dog_name)),
      script_engine(save.get()), unk_364(1), unk_368(0xAB)
{
    gUnk_0300040C = reinterpret_cast<u8 *>(this);
}

#endif // GAME_SCENE_HH
