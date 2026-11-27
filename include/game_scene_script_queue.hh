#ifndef GAME_SCENE_SCRIPT_QUEUE_HH
#define GAME_SCENE_SCRIPT_QUEUE_HH

#include "prelude.h"
#include "utility/container_algorithms.hh"


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

    ~GameSceneScriptQueue()
    {
        destroy_ptrs(Data(), End());
    }

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

// Member destruction releases the three constructed ranges in reverse
// queue order; unused capacity never contains constructed requests.
struct GameSceneScriptQueues {
    ~GameSceneScriptQueues();

    GameSceneScriptQueue<2> queue_0;
    GameSceneScriptQueue<40> queue_1;
    GameSceneScriptQueue<1> queue_2;
};




#endif // GAME_SCENE_SCRIPT_QUEUE_HH
