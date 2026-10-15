#ifndef GAME_SCENE_HH
#define GAME_SCENE_HH

#include "prelude.h"
#include "scene.hh"

struct AActorEntity;
struct GameObject;

// The native constructor allocates 0xF8 bytes and places its vptr at +0xF4.
// Only fields used by the recovered entity commands are named here; the
// other state remains opaque rather than acquiring speculative meanings.
struct GameSceneState {
    u8 unk_00[0x9C];
    u32 script_state;
    u32 unk_A0[2];
    GameObject * game_object;
    u8 unk_AC[0x38];
    AActorEntity * waiting_entity;
    u8 unk_E8[0xC];
    virtual ~GameSceneState();
};

struct GameScene : AScene {
    GameSceneState * state;

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
};

typedef char GameSceneStateSizeCheck[sizeof(GameSceneState) == 0xF8 ? 1 : -1];
typedef char GameSceneStateScriptStateCheck[offsetof(GameSceneState, script_state) == 0x9C ? 1 : -1];
typedef char GameSceneStateGameObjectCheck[offsetof(GameSceneState, game_object) == 0xA8 ? 1 : -1];
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

EXTERN_C_END

#endif // GAME_SCENE_HH
