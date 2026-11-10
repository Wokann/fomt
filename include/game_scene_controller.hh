#ifndef GAME_SCENE_CONTROLLER_HH
#define GAME_SCENE_CONTROLLER_HH

#include "prelude.h"
#include "game_state_owner.hh"
#include "unknown_types.hh"
#include "scene.hh"
#include "script_engine.hh"
#include "entity_actor.hh"
#include "game_scene_records.hh"
#include "game_scene_script_queue.hh"


// The native clock slot has four-byte storage, unlike the packed GameTime.
// Construction preserves its unknown bits; saving copies only the low halfword.
union GameScenePreservedClock {
    struct Fields {
        u16 clock_hour : 5;
        u16 clock_minute : 6;
        u16 unk_11 : 5;
    } fields;
    u16 encoded;
    GameScenePreservedClock()
    {
        fields.clock_hour = 6;
        fields.clock_minute = 0;
    }
    static unsigned int DecodeHour(u16 const & value)
    {
        return (static_cast<u32>(value) << (32 - 5)) >> (32 - 5);
    }
    unsigned int GetHour() const
    {
        return DecodeHour(encoded);
    }
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
#pragma interface "game_scene_controller.hh"
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

EXTERN_C

extern GameSceneScriptController * gCurrentGameSceneScriptController;

GameSceneControllerActorRecord * GetSceneActorRecords(void);
GameSceneEventIconRecord * GetSceneEventIconRecords(void);
GameSceneScriptQueue<2> * GetSceneScriptQueue0(void);
GameScenePreservedPlayerLocation * GetScenePreservedPlayerLocation(void);
u8 * func_08010138(void);
u32 func_08010148(void);
ScriptEngine * GetSceneScriptEngine(void);

EXTERN_C_END


#endif // GAME_SCENE_CONTROLLER_HH
