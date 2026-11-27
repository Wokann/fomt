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
