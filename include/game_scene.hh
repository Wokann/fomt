#ifndef GAME_SCENE_HH
#define GAME_SCENE_HH
#include "shop_common.hh"

#include "prelude.h"
#include <stdlib.h>
#include "game_state.hh"
#include "scene.hh"
#include "entity_actor.hh"
#include "ui_state.hh"
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

// Only the shared destruction prefix is recovered. The concrete Time Window
// and pause-menu selector payloads and their destructors remain native.
struct GameSceneUiComponent {
    u32 unk_00;
    // Actual existing bootstrap lifecycle ABI; these declarations emit no code.
    GameSceneUiComponent() asm("func_08008444");
    virtual ~GameSceneUiComponent() asm("func_080086BC");
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
    i32 kind;
    u8 unk_04[8];

    // Native requests initialize only kind; the remaining payload is opaque.
    GameSceneResumeRequest() {}
    explicit GameSceneResumeRequest(i32 value) : kind(value) {}
};

struct SupermarketSceneCore;
struct SupermarketPurchaseSceneCore;

// These two native scene constructors create an owned UI core at +4 and
// consume the continuation at +8. Their UI cores and lifecycle remain native.
struct SupermarketScene : AScene {
    virtual ~SupermarketScene();
    virtual SceneTransitionOwner Run();

    SupermarketSceneCore * core;
    SceneTransitionOwner continuation;
};

struct SupermarketPurchaseScene : AScene {
    virtual ~SupermarketPurchaseScene();
    virtual SceneTransitionOwner Run();

    SupermarketPurchaseSceneCore * core;
    SceneTransitionOwner continuation;
};

// Scene wrappers retain their native cleanup; recovered transition records use
// implicit cleanup of their continuation owner and SceneTransition base.
// Existing native-format tables reference these real methods and CreateScene.
struct SupermarketPurchaseTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MarySupermarketItemId item_id;
};

struct SupermarketTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct ReturnToGameScene : SceneTransition {
    virtual SceneOwner CreateScene();

    GameStateSaveImage * save;
    GameSceneResumeRequest request;
};

typedef char GameSceneResumeRequestSizeCheck[sizeof(GameSceneResumeRequest) == 12 ? 1 : -1];
typedef char SupermarketSceneSizeCheck[sizeof(SupermarketScene) == 12 ? 1 : -1];
typedef char SupermarketSceneCoreCheck[offsetof(SupermarketScene, core) == 4 ? 1 : -1];
typedef char SupermarketSceneContinuationCheck[offsetof(SupermarketScene, continuation) == 8 ? 1 : -1];
typedef char SupermarketPurchaseSceneSizeCheck[sizeof(SupermarketPurchaseScene) == 12 ? 1 : -1];
typedef char SupermarketPurchaseSceneCoreCheck[offsetof(SupermarketPurchaseScene, core) == 4 ? 1 : -1];
typedef char SupermarketPurchaseSceneContinuationCheck[offsetof(SupermarketPurchaseScene, continuation) == 8 ? 1 : -1];
typedef char SupermarketPurchaseTransitionSizeCheck[sizeof(SupermarketPurchaseTransition) == 16 ? 1 : -1];
typedef char SupermarketPurchaseTransitionItemCheck[offsetof(SupermarketPurchaseTransition, item_id) == 12 ? 1 : -1];
typedef char SupermarketTransitionSizeCheck[sizeof(SupermarketTransition) == 12 ? 1 : -1];
typedef char ReturnToGameSceneSizeCheck[sizeof(ReturnToGameScene) == 20 ? 1 : -1];
typedef char ReturnToGameSceneRequestCheck[offsetof(ReturnToGameScene, request) == 8 ? 1 : -1];

// Verified modal scene wrappers and transitions, in native factory order.
struct CalendarSceneCore;
struct CalendarScene : AScene {
    virtual ~CalendarScene();
    virtual SceneTransitionOwner Run();

    CalendarSceneCore * core;
    SceneTransitionOwner continuation;
};

struct CalendarTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char CalendarSceneSizeCheck[sizeof(CalendarScene) == 12 ? 1 : -1];
typedef char CalendarSceneCoreCheck[offsetof(CalendarScene, core) == 4 ? 1 : -1];
typedef char CalendarSceneContinuationCheck[offsetof(CalendarScene, continuation) == 8 ? 1 : -1];
typedef char CalendarTransitionSizeCheck[sizeof(CalendarTransition) == 12 ? 1 : -1];

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

struct ShelfSceneCore;
struct ShelfScene : AScene {
    virtual ~ShelfScene();
    virtual SceneTransitionOwner Run();

    ShelfSceneCore * core;
    SceneTransitionOwner continuation;
};

struct ShelfTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char ShelfSceneSizeCheck[sizeof(ShelfScene) == 12 ? 1 : -1];
typedef char ShelfSceneCoreCheck[offsetof(ShelfScene, core) == 4 ? 1 : -1];
typedef char ShelfSceneContinuationCheck[offsetof(ShelfScene, continuation) == 8 ? 1 : -1];
typedef char ShelfTransitionSizeCheck[sizeof(ShelfTransition) == 12 ? 1 : -1];

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

struct ReferencePageSceneCore;
struct ReferencePageScene : AScene {
    virtual ~ReferencePageScene();
    virtual SceneTransitionOwner Run();

    ReferencePageSceneCore * core;
    SceneTransitionOwner continuation;
};

struct ReferencePageTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    i32 page_id;
};

typedef char ReferencePageSceneSizeCheck[sizeof(ReferencePageScene) == 12 ? 1 : -1];
typedef char ReferencePageSceneCoreCheck[offsetof(ReferencePageScene, core) == 4 ? 1 : -1];
typedef char ReferencePageSceneContinuationCheck[offsetof(ReferencePageScene, continuation) == 8 ? 1 : -1];
typedef char ReferencePageTransitionSizeCheck[sizeof(ReferencePageTransition) == 16 ? 1 : -1];

struct SpecialMerchantShopSceneCore;
struct SpecialMerchantShopScene : AScene {
    virtual ~SpecialMerchantShopScene();
    virtual SceneTransitionOwner Run();

    SpecialMerchantShopSceneCore * core;
    SceneTransitionOwner continuation;
};

struct SpecialMerchantShopTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char SpecialMerchantShopSceneSizeCheck[sizeof(SpecialMerchantShopScene) == 12 ? 1 : -1];
typedef char SpecialMerchantShopSceneCoreCheck[offsetof(SpecialMerchantShopScene, core) == 4 ? 1 : -1];
typedef char SpecialMerchantShopSceneContinuationCheck[offsetof(SpecialMerchantShopScene, continuation) == 8 ? 1 : -1];
typedef char SpecialMerchantShopTransitionSizeCheck[sizeof(SpecialMerchantShopTransition) == 12 ? 1 : -1];

struct GiftWrappingSceneCore;
struct GiftWrappingScene : AScene {
    virtual ~GiftWrappingScene();
    virtual SceneTransitionOwner Run();

    GiftWrappingSceneCore * core;
    SceneTransitionOwner continuation;
};

struct GiftWrappingTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char GiftWrappingSceneSizeCheck[sizeof(GiftWrappingScene) == 12 ? 1 : -1];
typedef char GiftWrappingSceneCoreCheck[offsetof(GiftWrappingScene, core) == 4 ? 1 : -1];
typedef char GiftWrappingSceneContinuationCheck[offsetof(GiftWrappingScene, continuation) == 8 ? 1 : -1];
typedef char GiftWrappingTransitionSizeCheck[sizeof(GiftWrappingTransition) == 12 ? 1 : -1];

struct WineryShopSceneCore;
struct WineryShopScene : AScene {
    virtual ~WineryShopScene();
    virtual SceneTransitionOwner Run();

    WineryShopSceneCore * core;
    SceneTransitionOwner continuation;
};

struct WineryShopTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char WineryShopSceneSizeCheck[sizeof(WineryShopScene) == 12 ? 1 : -1];
typedef char WineryShopSceneCoreCheck[offsetof(WineryShopScene, core) == 4 ? 1 : -1];
typedef char WineryShopSceneContinuationCheck[offsetof(WineryShopScene, continuation) == 8 ? 1 : -1];
typedef char WineryShopTransitionSizeCheck[sizeof(WineryShopTransition) == 12 ? 1 : -1];

struct InnShopSceneCore;
struct InnShopScene : AScene {
    virtual ~InnShopScene();
    virtual SceneTransitionOwner Run();

    InnShopSceneCore * core;
    SceneTransitionOwner continuation;
};

struct InnShopTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char InnShopSceneSizeCheck[sizeof(InnShopScene) == 12 ? 1 : -1];
typedef char InnShopSceneCoreCheck[offsetof(InnShopScene, core) == 4 ? 1 : -1];
typedef char InnShopSceneContinuationCheck[offsetof(InnShopScene, continuation) == 8 ? 1 : -1];
typedef char InnShopTransitionSizeCheck[sizeof(InnShopTransition) == 12 ? 1 : -1];

struct BeachCafeShopSceneCore;
struct BeachCafeShopScene : AScene {
    virtual ~BeachCafeShopScene();
    virtual SceneTransitionOwner Run();

    BeachCafeShopSceneCore * core;
    SceneTransitionOwner continuation;
};

struct BeachCafeShopTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char BeachCafeShopSceneSizeCheck[sizeof(BeachCafeShopScene) == 12 ? 1 : -1];
typedef char BeachCafeShopSceneCoreCheck[offsetof(BeachCafeShopScene, core) == 4 ? 1 : -1];
typedef char BeachCafeShopSceneContinuationCheck[offsetof(BeachCafeShopScene, continuation) == 8 ? 1 : -1];
typedef char BeachCafeShopTransitionSizeCheck[sizeof(BeachCafeShopTransition) == 12 ? 1 : -1];

struct WonShopSceneCore;
struct WonShopScene : AScene {
    virtual ~WonShopScene();
    virtual SceneTransitionOwner Run();

    WonShopSceneCore * core;
    SceneTransitionOwner continuation;
};

struct WonShopTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char WonShopSceneSizeCheck[sizeof(WonShopScene) == 12 ? 1 : -1];
typedef char WonShopSceneCoreCheck[offsetof(WonShopScene, core) == 4 ? 1 : -1];
typedef char WonShopSceneContinuationCheck[offsetof(WonShopScene, continuation) == 8 ? 1 : -1];
typedef char WonShopTransitionSizeCheck[sizeof(WonShopTransition) == 12 ? 1 : -1];

struct CarpenterShopSceneCore;
struct CarpenterShopScene : AScene {
    virtual ~CarpenterShopScene();
    virtual SceneTransitionOwner Run();

    CarpenterShopSceneCore * core;
    SceneTransitionOwner continuation;
};

struct CarpenterShopTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char CarpenterShopSceneSizeCheck[sizeof(CarpenterShopScene) == 12 ? 1 : -1];
typedef char CarpenterShopSceneCoreCheck[offsetof(CarpenterShopScene, core) == 4 ? 1 : -1];
typedef char CarpenterShopSceneContinuationCheck[offsetof(CarpenterShopScene, continuation) == 8 ? 1 : -1];
typedef char CarpenterShopTransitionSizeCheck[sizeof(CarpenterShopTransition) == 12 ? 1 : -1];

struct ClinicShopSceneCore;
struct ClinicShopScene : AScene {
    virtual ~ClinicShopScene();
    virtual SceneTransitionOwner Run();

    ClinicShopSceneCore * core;
    SceneTransitionOwner continuation;
};

struct ClinicShopTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char ClinicShopSceneSizeCheck[sizeof(ClinicShopScene) == 12 ? 1 : -1];
typedef char ClinicShopSceneCoreCheck[offsetof(ClinicShopScene, core) == 4 ? 1 : -1];
typedef char ClinicShopSceneContinuationCheck[offsetof(ClinicShopScene, continuation) == 8 ? 1 : -1];
typedef char ClinicShopTransitionSizeCheck[sizeof(ClinicShopTransition) == 12 ? 1 : -1];

// Verified nonuniform scene layouts; unknown scalar semantics stay unnamed.
struct YodelRanchShopSceneCore;
struct YodelRanchShopScene : AScene {
    virtual ~YodelRanchShopScene();
    virtual SceneTransitionOwner Run();
    YodelRanchShopSceneCore * core;
    SceneTransitionOwner continuation;
    u32 unk_0C;
    GameStateSaveImage * save;
};

struct YodelRanchShopTransition : SceneTransition {
    YodelRanchShopTransition(SceneTransitionOwner next, GameStateSaveImage * image, u32 input)
        : continuation(next), save(image), unk_0C(input) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u32 unk_0C;
};
typedef char YodelRanchShopSceneSizeCheck[sizeof(YodelRanchShopScene) == 20 ? 1 : -1];
typedef char YodelRanchShopSceneSaveCheck[offsetof(YodelRanchShopScene, save) == 16 ? 1 : -1];
typedef char YodelRanchShopTransitionSizeCheck[sizeof(YodelRanchShopTransition) == 16 ? 1 : -1];

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

struct PoultryFarmShopSceneCore;
struct PoultryFarmShopScene : AScene {
    virtual ~PoultryFarmShopScene();
    virtual SceneTransitionOwner Run();
    PoultryFarmShopSceneCore * core;
    SceneTransitionOwner continuation;
    u32 unk_0C;
    GameStateSaveImage * save;
};

struct PoultryFarmShopTransition : SceneTransition {
    PoultryFarmShopTransition(SceneTransitionOwner next, GameStateSaveImage * image, u32 input)
        : continuation(next), save(image), unk_0C(input) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u32 unk_0C;
};
typedef char PoultryFarmShopSceneSizeCheck[sizeof(PoultryFarmShopScene) == 20 ? 1 : -1];
typedef char PoultryFarmShopSceneSaveCheck[offsetof(PoultryFarmShopScene, save) == 16 ? 1 : -1];
typedef char PoultryFarmShopTransitionSizeCheck[sizeof(PoultryFarmShopTransition) == 16 ? 1 : -1];

struct BlacksmithShopSceneCore;
struct BlacksmithShopScene : AScene {
    virtual ~BlacksmithShopScene();
    virtual SceneTransitionOwner Run();
    BlacksmithShopSceneCore * core;
    SceneTransitionOwner continuation;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    GameStateSaveImage * save;
};

struct BlacksmithShopTransition : SceneTransition {
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u8 unk_1C;
};
typedef char BlacksmithShopSceneSizeCheck[sizeof(BlacksmithShopScene) == 32 ? 1 : -1];
typedef char BlacksmithShopSceneSaveCheck[offsetof(BlacksmithShopScene, save) == 28 ? 1 : -1];
typedef char BlacksmithShopTransitionSizeCheck[sizeof(BlacksmithShopTransition) == 32 ? 1 : -1];
typedef char BlacksmithShopTransitionByteCheck[offsetof(BlacksmithShopTransition, unk_1C) == 28 ? 1 : -1];

// This is the verified native destruction-prefix view, not the full core hierarchy.
// The concrete core constructor, Run and destructor bodies remain native.
struct BlacksmithShopResultSceneCore : GameSceneUiComponent {
    u8 unk_008[0x108];
    SceneTransitionOwner continuation;
    u8 unk_114;
    u8 unk_115[0xA3];
};
typedef char BlacksmithShopResultSceneCoreSizeCheck[sizeof(BlacksmithShopResultSceneCore) == 0x1B8 ? 1 : -1];
typedef char BlacksmithShopResultSceneCorePayloadCheck[offsetof(BlacksmithShopResultSceneCore, unk_008) == 8 ? 1 : -1];
typedef char BlacksmithShopResultSceneCoreContinuationCheck[offsetof(BlacksmithShopResultSceneCore, continuation) == 0x110 ? 1 : -1];
typedef char BlacksmithShopResultSceneCoreByteCheck[offsetof(BlacksmithShopResultSceneCore, unk_114) == 0x114 ? 1 : -1];

struct BlacksmithShopResultScene : AScene {
    BlacksmithShopResultScene(SceneTransitionOwner next, GameStateSaveImage * image, u8 input);
    virtual ~BlacksmithShopResultScene();
    virtual SceneTransitionOwner Run();
    GameSceneUiComponentOwner core;
    SceneTransitionOwner continuation;
};

// This result transition is not the 32-byte shop-opening transition above.
// Its byte is passed unchanged to the native result-scene constructor.
struct BlacksmithShopResultTransition : SceneTransition {
    BlacksmithShopResultTransition(SceneTransitionOwner next, GameStateSaveImage * image, u8 input)
        : continuation(next), save(image), unk_0C(input) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u8 unk_0C;
};
typedef char BlacksmithShopResultSceneSizeCheck[sizeof(BlacksmithShopResultScene) == 12 ? 1 : -1];
typedef char BlacksmithShopResultSceneCoreCheck[offsetof(BlacksmithShopResultScene, core) == 4 ? 1 : -1];
typedef char BlacksmithShopResultSceneContinuationCheck[offsetof(BlacksmithShopResultScene, continuation) == 8 ? 1 : -1];
typedef char BlacksmithShopResultTransitionSizeCheck[sizeof(BlacksmithShopResultTransition) == 16 ? 1 : -1];
typedef char BlacksmithShopResultTransitionContinuationCheck[offsetof(BlacksmithShopResultTransition, continuation) == 4 ? 1 : -1];
typedef char BlacksmithShopResultTransitionSaveCheck[offsetof(BlacksmithShopResultTransition, save) == 8 ? 1 : -1];
typedef char BlacksmithShopResultTransitionByteCheck[offsetof(BlacksmithShopResultTransition, unk_0C) == 12 ? 1 : -1];

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
    GameSceneUiComponentOwner time_window;
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
    u32 IsBackgroundMusicActive();
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
void func_0807CD80(SupermarketSceneCore * core);
#else
void func_0807D218(SupermarketSceneCore * core);
#endif
void func_0807DE3C(SupermarketPurchaseSceneCore * core);
SceneTransitionOwner func_080A25B0(CalendarSceneCore * core);
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
void func_08090960(ShelfSceneCore * core);
#if defined(REGION_JP)
SceneTransitionOwner func_08094A40(CookingSceneCore * core);
#else
SceneTransitionOwner func_08094F6C(CookingSceneCore * core);
#endif
SceneTransitionOwner func_080790E4(ReferencePageSceneCore * core);
#if defined(REGION_JP)
void func_08080CC4(SpecialMerchantShopSceneCore * core);
#else
void func_0808114C(SpecialMerchantShopSceneCore * core);
#endif
void func_08092D64(GiftWrappingSceneCore * core);
#if defined(REGION_JP)
void func_080800A8(WineryShopSceneCore * core);
#else
void func_08080540(WineryShopSceneCore * core);
#endif
#if defined(REGION_JP)
void func_0807EAF8(InnShopSceneCore * core);
#else
void func_0807EF90(InnShopSceneCore * core);
#endif
#if defined(REGION_JP)
void func_08081734(BeachCafeShopSceneCore * core);
#else
void func_08081BBC(BeachCafeShopSceneCore * core);
#endif
#if defined(REGION_JP)
void func_0807F430(WonShopSceneCore * core);
#else
void func_0807F8C8(WonShopSceneCore * core);
#endif
void func_08084228(CarpenterShopSceneCore * core);
#if defined(REGION_JP)
void func_0807E0C0(ClinicShopSceneCore * core);
#else
void func_0807E558(ClinicShopSceneCore * core);
#endif

// The core still has its native constructor and regional owning Run ABI.
u32 func_08082CEC(BlacksmithShopSceneCore * core);
BlacksmithShopResultSceneCore * func_08090EE0(void *, SceneTransitionOwner, GameStateSaveImage *, u8);
#if defined(REGION_JP)
SceneTransitionOwner func_0809106C(BlacksmithShopResultSceneCore * core);
#else
SceneTransitionOwner func_0809152C(BlacksmithShopResultSceneCore * core);
#endif

// Ranch Run returns the purchased target slot or -1; the second core
// query selects the existing cow/sheep naming branch.
i32 func_08086A08(YodelRanchShopSceneCore * core);
u32 func_08085EEC(YodelRanchShopSceneCore * core);

// The poultry core returns a signed target slot, with -1 meaning no purchase.
#if defined(REGION_JP)
i32 func_0807BA6C(PoultryFarmShopSceneCore * core);
#else
i32 func_0807BEC8(PoultryFarmShopSceneCore * core);
#endif

// Native shop construction ABI: each constructor consumes *continuation.
#if defined(REGION_JP)
SupermarketScene * func_0807D8A0(void * object, SceneTransition ** continuation,
    GameStateSaveImage * save);
SupermarketPurchaseScene * func_0807DFA0(void * object, SceneTransition ** continuation,
    GameStateSaveImage * save, MarySupermarketItemId item_id);
#else
SupermarketScene * func_0807DD38(void * object, SceneTransition ** continuation,
    GameStateSaveImage * save);
SupermarketPurchaseScene * func_0807E438(void * object, SceneTransition ** continuation,
    GameStateSaveImage * save, MarySupermarketItemId item_id);
#endif

CalendarScene * func_080A3744(void *, SceneTransition **, GameStateSaveImage *);

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

ShelfScene * func_08090E54(void *, SceneTransition **, GameStateSaveImage *);

#if defined(REGION_JP)
CookingScene * func_08099F0C(void *, SceneTransition **, GameStateSaveImage *, u8);
#else
CookingScene * func_0809A4D4(void *, SceneTransition **, GameStateSaveImage *, u8);
#endif

ReferencePageScene * func_0807B038(void *, SceneTransition **, GameStateSaveImage *, i32);

#if defined(REGION_JP)
SpecialMerchantShopScene * func_080815B8(void *, SceneTransition **, GameStateSaveImage *);
#else
SpecialMerchantShopScene * func_08081A40(void *, SceneTransition **, GameStateSaveImage *);
#endif

#if defined(REGION_JP)
GiftWrappingScene * loc_08092C7C(void *, SceneTransition **, GameStateSaveImage *);
#else
GiftWrappingScene * func_080931B0(void *, SceneTransition **, GameStateSaveImage *);
#endif

#if defined(REGION_JP)
WineryShopScene * func_0808090C(void *, SceneTransition **, GameStateSaveImage *);
#else
WineryShopScene * func_08080D94(void *, SceneTransition **, GameStateSaveImage *);
#endif

#if defined(REGION_JP)
InnShopScene * func_0807F0E8(void *, SceneTransition **, GameStateSaveImage *);
#else
InnShopScene * func_0807F580(void *, SceneTransition **, GameStateSaveImage *);
#endif

#if defined(REGION_JP)
BeachCafeShopScene * func_08081C8C(void *, SceneTransition **, GameStateSaveImage *);
#else
BeachCafeShopScene * func_08082114(void *, SceneTransition **, GameStateSaveImage *);
#endif

#if defined(REGION_JP)
WonShopScene * loc_0807FFC4(void *, SceneTransition **, GameStateSaveImage *);
#else
WonShopScene * func_0808045C(void *, SceneTransition **, GameStateSaveImage *);
#endif

#if defined(REGION_JP)
CarpenterShopScene * loc_0808506C(void *, SceneTransition **, GameStateSaveImage *);
#else
CarpenterShopScene * func_080854F4(void *, SceneTransition **, GameStateSaveImage *);
#endif

#if defined(REGION_JP)
ClinicShopScene * func_0807E97C(void *, SceneTransition **, GameStateSaveImage *);
#else
ClinicShopScene * func_0807EE14(void *, SceneTransition **, GameStateSaveImage *);
#endif

#if defined(REGION_JP)
YodelRanchShopScene * loc_08087CA8(void *, SceneTransition **, GameStateSaveImage *, u32);
#else
YodelRanchShopScene * func_08088168(void *, SceneTransition **, GameStateSaveImage *, u32);
#endif
#if defined(REGION_JP)
PoultryFarmShopScene * func_0807CBD8(void *, SceneTransition **, GameStateSaveImage *, u32);
#else
PoultryFarmShopScene * func_0807D070(void *, SceneTransition **, GameStateSaveImage *, u32);
#endif
BlacksmithShopScene * func_08083A7C(void *, SceneTransition **, GameStateSaveImage *, u8, u32, u32, u32, u32);

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
void func_080D7F60(GameSceneState * state);
void func_080D7F74(GameSceneState * state);
void func_080D7F88(GameSceneState * state);

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
