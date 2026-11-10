#ifndef GAME_SCENE_STATE_HH
#define GAME_SCENE_STATE_HH


#include "prelude.h"
#include <stdlib.h>
#include "allocation_failure.hh"
#include "scene.hh"
#include "entity_actor.hh"
#include "ui_state.hh"
#include "main_menu_widget.hh"
#include "hardware_display_state.hh"
#include "hardware_sprite_buffer.hh"
#include "script_engine.hh"
#include "fomt_constants.hh"
#include "utility/vec2.hh"
#include "resource_handle.hh"
#include "obj_palette_collection.hh"
#include "obj_tile_collection.hh"
#include "hardware_context.hh"
#include "hardware_blend.hh"
#include "hardware_sound.hh"
#include "time_of_day_types.hh"
#include "field_render_farm_house_data.hh"
#include "game_world.hh"
#include "player_actor.hh"
#include "animal_actor.hh"

#include "scene_text_variables.hh"
#include "scene_clock.hh"



#include "utility/container_algorithms.hh"
struct GameStateSaveImage;

// Shared load-status strings and the four direct help-menu UI labels.
extern char const gText_LoadError[];
extern char const gText_LoadErrorFallbackNone[];
extern char const gCppRuntimeError_LoadError[];

// These are passed as four direct pointers to the help-menu constructor.
extern char const gText_HelpMenu_Crops[];
extern char const gText_HelpMenu_Animals[];
extern char const gText_HelpMenu_UsefulTips[];
extern char const gText_HelpMenu_Exit[];

struct GameScene;

struct GameScenePauseMenuOwner {
    MainMenuWidget * value;

    GameScenePauseMenuOwner() : value(nullptr) {}
    explicit GameScenePauseMenuOwner(MainMenuWidget * input) : value(input) {}
    ~GameScenePauseMenuOwner() { delete value; }
    GameScenePauseMenuOwner & operator=(MainMenuWidget * next)
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

    void Grow(HardwareMusicPlayerSlot ** old_end, u32 count,
        HardwareMusicPlayerSlot * const & value)
    {
        u32 old_size = old_end - begin;
        u32 capacity = old_size + max_ref_inl(old_size, count);
        HardwareMusicPlayerSlot ** replacement = nullptr;
        if (capacity != 0) {
            u32 bytes = capacity * sizeof(*replacement);
            replacement = static_cast<HardwareMusicPlayerSlot **>(malloc(bytes));
            if (replacement == nullptr)
                replacement = static_cast<HardwareMusicPlayerSlot **>(RetryMemoryAllocation(bytes));
        }
        HardwareMusicPlayerSlot ** current = copy_ptrs_inl(begin, old_end, replacement, __true_type());
        for (u32 remaining = count; remaining != 0; --remaining)
            *current++ = value;
        if (begin != nullptr)
            free(begin);
        begin = replacement;
        end = current;
        allocation.end = replacement + capacity;
    }

    inline void PushBack(HardwareMusicPlayerSlot * const & value);

};

#include "game_scene.hh"

struct GameSceneBlendOwner {
    HardwareBlendController * value;
    explicit GameSceneBlendOwner(HardwareBlendController * input = nullptr) : value(input) {}
    ~GameSceneBlendOwner() { delete value; }
    GameSceneBlendOwner & operator=(HardwareBlendController * next)
    {
        if (next != value)
            delete value;
        value = next;
        return *this;
    }
};

struct GameSceneWorldOwner {
    GameObject * value;
    explicit GameSceneWorldOwner(GameObject * input = nullptr) : value(input) {}
    GameSceneWorldOwner(GameSceneWorldOwnerTransfer other) : value(other.release()) {}
    ~GameSceneWorldOwner() { delete value; }
    GameSceneWorldOwner & operator=(GameObject * world)
    {
        if (world != value)
            delete value;
        value = world;
        return *this;
    }
    GameSceneWorldOwner & operator=(GameSceneWorldOwnerTransfer other)
    {
        GameObject * world = other.release();
        if (world != value)
            delete value;
        value = world;
        return *this;
    }
};

typedef char GameSceneWorldOwnerSizeCheck[sizeof(GameSceneWorldOwner) == 4 ? 1 : -1];

struct GameSceneTextVariablesOwner {
    GameSceneTextVariables * value;
    explicit GameSceneTextVariablesOwner(GameSceneTextVariables * input = nullptr) : value(input) {}
    ~GameSceneTextVariablesOwner() { delete value; }
};

// The native constructor allocates 0xF8 bytes and places its vptr at +0xF4.
// The display shadow at +0x10 is constructed as HardwareDisplayState.
// Other fields are typed only where native construction or use proves them.
#pragma interface "game_scene_state.hh"
struct GameSceneState {
    GameStateSaveImage * GetSave() const { return save; }
    inline GameSceneState(GameScene * owner, GameStateSaveImage * image,
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
    GameScenePauseMenuOwner pause_menu_selector;
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
    u8 screen_flash_active;
    u16 screen_flash_color;
    u8 screen_flash_strength;
    u8 screen_flash_frame;
    void * unk_F0;
    virtual ~GameSceneState();
};

typedef char GameScenePauseMenuOwnerSizeCheck[sizeof(GameScenePauseMenuOwner) == 4 ? 1 : -1];
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
typedef char GameSceneStateScreenFlashActiveCheck[offsetof(GameSceneState, screen_flash_active) == 0xEA ? 1 : -1];
typedef char GameSceneStateScreenFlashColorCheck[offsetof(GameSceneState, screen_flash_color) == 0xEC ? 1 : -1];
typedef char GameSceneStateScreenFlashStrengthCheck[offsetof(GameSceneState, screen_flash_strength) == 0xEE ? 1 : -1];
typedef char GameSceneStateScreenFlashFrameCheck[offsetof(GameSceneState, screen_flash_frame) == 0xEF ? 1 : -1];
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

inline GameSceneState::GameSceneState(GameScene * owner, GameStateSaveImage * image,
    GameSceneResumeRequest const & request)
    : scene(owner), save(image), resume_request(request), screen_blend(nullptr),
      game_object(nullptr), text_variables(nullptr), bgm_player(0), music_player_1(1),
      music_player_2(2), music_player_3(3), music_player_4(4)
{
    unk_E8 = 0;
    screen_flash_active = 0;
    unk_F0 = nullptr;
}



EXTERN_C

// Recovered state callbacks retain address names where semantics are unresolved.
void func_080D7F08(GameSceneState * state);
// Pause the world while the controller runs its active event script.
void SuspendSceneWorldForScript(GameSceneState * state);

// The native scene runner still owns the underlying update loop.
SceneTransitionOwner sub_080D8178(GameSceneState * state);

void HideSceneDialogueHeartIndicator(GameSceneState * state);
void ClearSceneDialoguePortrait(GameSceneState * state);
void ClearSceneDialogueNameplate(GameSceneState * state);

EXTERN_C_END

// The native state-level entry used by current-map position updates.
// Actor IDs through slot 73 also update facing; other IDs use AEntity location.
// Coordinates narrow to signed 16 bits and the stored map narrows to 10 bits.
void RelocateEntityToMap(GameSceneState * current, i32 entity_id, u32 map,
    i32 x, i32 y, u32 facing);

#endif // GAME_SCENE_STATE_HH
