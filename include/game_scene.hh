#ifndef GAME_SCENE_HH
#define GAME_SCENE_HH

#include "prelude.h"
#include "scene.hh"
#include "ui_state.hh"

struct AActorEntity;
struct GameObject;
struct GameStateSaveImage;
struct MusicPlayer;

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

// The native constructor allocates 0xF8 bytes and places its vptr at +0xF4.
// Only fields used by the recovered commands are named here; the
// other state remains opaque rather than acquiring speculative meanings.
struct GameSceneState {
    u8 unk_00[0x10];
    u16 flags_10;
    u8 unk_12[0x7A];
    GameStateSaveImage * save;
    u8 unk_90[0xC];
    u32 script_state;
    u32 unk_A0[2];
    GameObject * game_object;
    GameSceneTalkWindowOwner talk_window;
    ScriptTextVariableStore * text_variables;
    GameSceneUiComponentOwner time_window;
    GameSceneUiComponentOwner pause_menu_selector;
    MusicPlayer * bgm_player;
    u8 unk_C0[0x10];
    GameSceneSongPlayerPool song_players;
    u8 unk_E0[4];
    AActorEntity * waiting_entity;
    u8 unk_E8[0xC];
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
    void TextVariableSetNumber(u32 slot, i32 value);
    void TextVariableSetString(u32 slot, char const * text);
    void TextVariableSetNumberFieldWidth(u32 slot, i32 value, u32 width);
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
typedef char GameSceneStateFlagsCheck[offsetof(GameSceneState, flags_10) == 0x10 ? 1 : -1];
typedef char GameSceneStateSaveCheck[offsetof(GameSceneState, save) == 0x8C ? 1 : -1];
typedef char GameSceneStateScriptStateCheck[offsetof(GameSceneState, script_state) == 0x9C ? 1 : -1];
typedef char GameSceneStateGameObjectCheck[offsetof(GameSceneState, game_object) == 0xA8 ? 1 : -1];
typedef char GameSceneStateTalkWindowCheck[offsetof(GameSceneState, talk_window) == 0xAC ? 1 : -1];
typedef char GameSceneStateTalkContextCheck[offsetof(GameSceneState, text_variables) == 0xB0 ? 1 : -1];
typedef char GameSceneStateTimeWindowCheck[offsetof(GameSceneState, time_window) == 0xB4 ? 1 : -1];
typedef char GameSceneStateMenuSelectorCheck[offsetof(GameSceneState, pause_menu_selector) == 0xB8 ? 1 : -1];
typedef char GameSceneStateBgmPlayerCheck[offsetof(GameSceneState, bgm_player) == 0xBC ? 1 : -1];
typedef char GameSceneStateSongPlayersCheck[offsetof(GameSceneState, song_players) == 0xD0 ? 1 : -1];
typedef char GameSceneStateWaitingEntityCheck[offsetof(GameSceneState, waiting_entity) == 0xE4 ? 1 : -1];
typedef char GameSceneSizeCheck[sizeof(GameScene) == 8 ? 1 : -1];
typedef char GameSceneStatePointerCheck[offsetof(GameScene, state) == 4 ? 1 : -1];

EXTERN_C

// The global controller and its subobjects are not yet fully recovered.
extern u8 * gUnk_0300040C;

u8 * func_080100F0(void);
u8 * func_08010104(void);
u8 * func_08010118(void);
u8 * func_08010128(void);
u8 * func_08010138(void);
u32 func_08010148(void);
u8 * func_0801014C(void);

// The native post-map-change state callback remains in assembly.
void func_080D7F08(GameSceneState * state);
void func_080D7F9C(GameSceneState * state, u32 id, u32 map, i32 x, i32 y,
    u32 facing);

// Native text-variable storage keeps its original byte-based truncation.
// The scene wrappers do not add a slot check or width clamp.
void func_0803B6B8(ScriptTextVariableStore * variables, u32 slot, char const * text);

// Native per-window cleanup helpers used by the close transition.
void func_080D7F60(GameSceneState * state);
void func_080D7F74(GameSceneState * state);
void func_080D7F88(GameSceneState * state);

// The native scene runner still owns the underlying update loop.
SceneTransitionOwner sub_080D8178(GameSceneState * state);

EXTERN_C_END

#endif // GAME_SCENE_HH
