#ifndef GAME_SCENE_HH
#define GAME_SCENE_HH

#include "prelude.h"
#include "scene.hh"
#include "ui_state.hh"
#include "hardware_display_output.hh"
#include "script_engine.hh"
#include "fomt_constants.hh"
#include <new>

struct AActorEntity;
struct GameObject;
struct GameStateSaveImage;
struct MusicPlayer;
struct HardwareBlendController;

// Only the shared destruction prefix is recovered. The concrete Time Window
// and pause-menu selector payloads and their destructors remain native.
struct GameSceneUiComponent {
    u32 unk_00;
    virtual ~GameSceneUiComponent();
};

struct GameSceneUiComponentOwner {
    GameSceneUiComponent * value;

    GameSceneUiComponentOwner() : value(nullptr) {}
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
    u16 tempo;
    u16 volume;
    i16 pitch;
    i8 pan;
    u8 modulation_depth;
    u8 lfo_speed;
};

// Entries point to the scene's MusicPlayer pointer wrappers, not directly
// to m4a players. The allocation paths place capacity_end at +0x0C.
struct GameSceneSongPlayerPool {
    MusicPlayer *** begin;
    MusicPlayer *** end;
    u32 unk_08;
    MusicPlayer *** capacity_end;
};

// Each pending request is passed unchanged to LoadById(id, context).
struct GameSceneScriptRequest {
    i32 script_id;
    i32 context_value;
};

template <u32 Capacity>
struct GameSceneScriptQueue {
    u32 count;
    GameSceneScriptRequest entries[Capacity];

    GameSceneScriptRequest * End() { return &entries[count]; }

    // Native insertion drops a full queue; it does not grow or overwrite it.
    void Push(GameSceneScriptRequest const & request)
    {
        if (count < Capacity) {
            new (End()) GameSceneScriptRequest(request);
            ++count;
        }
    }
};

// Only the verified controller prefix through its three queues is modeled.
// The native owner, fields outside this prefix and lifecycle stay in assembly.
struct GameSceneScriptControllerPrefix {
    u8 unk_00[8];
    ScriptEngine script_engine;
    u8 unk_364[0x14];
    GameSceneScriptQueue<2> queue_0;
    GameSceneScriptQueue<40> queue_1;
    GameSceneScriptQueue<1> queue_2;
};

typedef char GameSceneScriptRequestSizeCheck[sizeof(GameSceneScriptRequest) == 8 ? 1 : -1];
typedef char GameSceneControllerEngineCheck[offsetof(GameSceneScriptControllerPrefix, script_engine) == 8 ? 1 : -1];
typedef char GameSceneControllerQueue0Check[offsetof(GameSceneScriptControllerPrefix, queue_0) == 0x378 ? 1 : -1];
typedef char GameSceneControllerQueue1Check[offsetof(GameSceneScriptControllerPrefix, queue_1) == 0x38C ? 1 : -1];
typedef char GameSceneControllerQueue2Check[offsetof(GameSceneScriptControllerPrefix, queue_2) == 0x4D0 ? 1 : -1];
typedef char GameSceneControllerPrefixSizeCheck[sizeof(GameSceneScriptControllerPrefix) == 0x4DC ? 1 : -1];

// The return transition and the native GameScene constructor copy this whole
// three-word record. Only its first word is initialized by the shop commands;
// the remaining payload is not assumed to be zero or given guessed meanings.
struct GameSceneResumeRequest {
    i32 kind;
    u8 unk_04[8];
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

// Native destructors remain the first virtuals in these classes. Their
// existing ROM tables now call the recovered CreateScene members directly;
// no duplicate compiler vtables or aliases are introduced.
struct SupermarketPurchaseTransition : SceneTransition {
    virtual ~SupermarketPurchaseTransition();
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MarySupermarketItemId item_id;
};

struct SupermarketTransition : SceneTransition {
    virtual ~SupermarketTransition();
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct ReturnToGameScene : SceneTransition {
    virtual ~ReturnToGameScene();
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

// The native constructor allocates 0xF8 bytes and places its vptr at +0xF4.
// The display shadow at +0x10 is constructed as HardwareDisplayState.
// Other fields are typed only where native construction or use proves them.
struct GameSceneState {
    u8 unk_00[0x10];
    HardwareDisplayState display;
    u8 unk_68[0x24];
    GameStateSaveImage * save;
    GameSceneResumeRequest resume_request;
    u32 script_state;
    HardwareBlendController * screen_blend;
    SceneTransitionOwner pending_transition;
    GameObject * game_object;
    GameSceneTalkWindowOwner talk_window;
    ScriptTextVariableStore * text_variables;
    GameSceneUiComponentOwner time_window;
    GameSceneUiComponentOwner pause_menu_selector;
    MusicPlayer * bgm_player;
    u8 unk_C0[0x10];
    GameSceneSongPlayerPool song_players;
    u16 wait_frames;
    u16 unk_E2;
    AActorEntity * waiting_entity;
    u8 unk_E8;
    u8 unk_E9;
    u8 unk_EA[0xA];
    virtual ~GameSceneState();
};

struct GameScene : AScene {
    virtual ~GameScene();
    virtual SceneTransitionOwner Run();

    GameSceneState * state;

    void SetEntityPosition(u32 id, i32 x, i32 y, u32 facing);
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
};

typedef char GameSceneUiComponentPrefixCheck[sizeof(GameSceneUiComponent) == 8 ? 1 : -1];
typedef char GameSceneUiComponentOwnerSizeCheck[sizeof(GameSceneUiComponentOwner) == 4 ? 1 : -1];
typedef char GameSceneTalkWindowOwnerSizeCheck[sizeof(GameSceneTalkWindowOwner) == 4 ? 1 : -1];
typedef char GameSceneBgmSettingsSizeCheck[sizeof(GameSceneBgmSettings) == 12 ? 1 : -1];
typedef char GameSceneBgmSettingsPitchCheck[offsetof(GameSceneBgmSettings, pitch) == 4 ? 1 : -1];
typedef char GameSceneBgmSettingsLfoCheck[offsetof(GameSceneBgmSettings, lfo_speed) == 8 ? 1 : -1];
typedef char GameSceneSongPlayerPoolSizeCheck[sizeof(GameSceneSongPlayerPool) == 16 ? 1 : -1];
typedef char GameSceneSongPlayerPoolCapacityCheck[offsetof(GameSceneSongPlayerPool, capacity_end) == 12 ? 1 : -1];
typedef char GameSceneStateSizeCheck[sizeof(GameSceneState) == 0xF8 ? 1 : -1];
typedef char GameSceneStateDisplayCheck[offsetof(GameSceneState, display) == 0x10 ? 1 : -1];
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
typedef char GameSceneStateSongPlayersCheck[offsetof(GameSceneState, song_players) == 0xD0 ? 1 : -1];
typedef char GameSceneStateWaitFramesCheck[offsetof(GameSceneState, wait_frames) == 0xE0 ? 1 : -1];
typedef char GameSceneStateWaitingEntityCheck[offsetof(GameSceneState, waiting_entity) == 0xE4 ? 1 : -1];
typedef char GameSceneSizeCheck[sizeof(GameScene) == 8 ? 1 : -1];
typedef char GameSceneStatePointerCheck[offsetof(GameScene, state) == 4 ? 1 : -1];

EXTERN_C

// Native construction ABI: the scene factories pass the original allocation
// and the continuation address. Each shop constructor consumes *continuation.
GameScene * func_08011DC4(void * object, GameStateSaveImage * save,
    GameSceneResumeRequest const * request);
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

// The global controller and its subobjects are not yet fully recovered.
extern u8 * gUnk_0300040C;

u8 * func_080100F0(void);
u8 * func_08010104(void);
GameSceneScriptQueue<2> * func_08010118(void);
u8 * func_08010128(void);
u8 * func_08010138(void);
u32 func_08010148(void);
ScriptEngine * func_0801014C(void);

// The native post-map-change state callback remains in assembly.
void func_080D7F08(GameSceneState * state);
void func_080D7F9C(GameSceneState * state, u32 id, u32 map, i32 x, i32 y,
    u32 facing);

// Native text-variable storage keeps its original byte-based truncation.
// The scene wrappers do not add a slot check or width clamp.
void func_0803B6B8(ScriptTextVariableStore * variables, u32 slot, char const * text);

void func_080D7F3C(GameSceneState * state);

// Native per-window cleanup helpers used by the close transition.
void func_080D7F60(GameSceneState * state);
void func_080D7F74(GameSceneState * state);
void func_080D7F88(GameSceneState * state);

// The native scene runner still owns the underlying update loop.
SceneTransitionOwner sub_080D8178(GameSceneState * state);

EXTERN_C_END

#endif // GAME_SCENE_HH
