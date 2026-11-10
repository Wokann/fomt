#ifndef GAME_SCENE_RECORDS_HH
#define GAME_SCENE_RECORDS_HH

#include "actor.hh"

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
    u32 State() const { return state; }
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

#endif // GAME_SCENE_RECORDS_HH
