#ifndef WORLD_SPRITE_BUFFER_HH
#define WORLD_SPRITE_BUFFER_HH

#include "hardware_sprite_buffer.hh"
#include <memory>

// Each key uses seven low bits for the OAM-record index and 25 for sorting.
struct WorldSpritePriorityQueue {
    WorldSpritePriorityQueue() : count(0) {}
    u32 * Begin() { return keys; }
    u32 * End() { return keys + count; }
    ~WorldSpritePriorityQueue() { std::destroy(Begin(), End()); }

    u32 count;
    u32 keys[128];
};

// Four source-priority buckets share one array of collected OAM records.
// WriteSprites sorts keys and copies only the six attribute bytes, retaining
// the destination's affine coefficient. Its body is still native assembly.
struct WorldSpriteDrawBuffer {
    WorldSpriteDrawBuffer() : count(0) {}
    void WriteSprites(HardwareSpriteBufferState & destination);

    u8 count;
    WorldSpritePriorityQueue priorities[4];
    HardwareSpriteOamRecord sprites[128];
};

typedef char WorldSpritePriorityQueueSizeCheck[sizeof(WorldSpritePriorityQueue) == 0x204 ? 1 : -1];
typedef char WorldSpriteDrawQueuesCheck[offsetof(WorldSpriteDrawBuffer, priorities) == 4 ? 1 : -1];
typedef char WorldSpriteDrawRecordsCheck[offsetof(WorldSpriteDrawBuffer, sprites) == 0x814 ? 1 : -1];
typedef char WorldSpriteDrawBufferSizeCheck[sizeof(WorldSpriteDrawBuffer) == 0xC14 ? 1 : -1];

#endif // WORLD_SPRITE_BUFFER_HH
