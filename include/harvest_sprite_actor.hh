#ifndef HARVEST_SPRITE_ACTOR_HH
#define HARVEST_SPRITE_ACTOR_HH

#include "entity_actor.hh"
#include "harvest_sprite.hh"

#pragma interface "harvest_sprite_actor.hh"

// Raw native result slot. The helper initializes it; there is no implicit
// saved-target constructor at the caller.
struct EntityUiHarvestSpriteResult
{
    u8 flags;
    u8 unknown_01[7];
};

// The work actor adds one resource sprite to the common two-sprite controller.
// Its drawing path reads signed world coordinates and a frame countdown.
struct HarvestSpriteController : EntitySpriteController {
    HarvestSpriteController(AActorEntity * entity);
    virtual ~HarvestSpriteController();
    virtual void Update();
    virtual void Draw(EntityDrawContext const & context);

    GameSceneIndexedSprite resource_sprite;
    i16 resource_x;
    i16 resource_y;
    u16 duration;
};

// This actor borrows its saved harvest sprite, the seven shared work targets,
// and the farm. Native construction allocates 0x44 bytes and calls AActorEntity.
struct NpcCollection;
struct Farm;
struct HarvestSpriteActor : AActorEntity {
    HarvestSpriteActor(GameObject * world, u32 index, NpcCollection * npcs, Farm * farm);
    virtual ~HarvestSpriteActor();
    virtual void Update(EntityUpdateContext const & context);
    virtual EntityVisualController * CreateVisualController();
    virtual void ResumeNormalUpdates();
    virtual void vfunc_14();
    virtual u32 vfunc_34();

    u8 entry_index;
    HarvestSprite * harvest_sprite;
    HarvestSpriteWorkTarget const * entries;
    Farm * farm;
    u8 unk_40;
    u8 unk_41;
    u8 unk_42;
};

typedef char HarvestSpriteActorSizeCheck[sizeof(HarvestSpriteActor) == 0x44 ? 1 : -1];
typedef char HarvestSpriteActorIndexCheck[offsetof(HarvestSpriteActor, entry_index) == 0x30 ? 1 : -1];
typedef char HarvestSpriteActorSavedSpriteCheck[offsetof(HarvestSpriteActor, harvest_sprite) == 0x34 ? 1 : -1];
typedef char HarvestSpriteActorEntriesCheck[offsetof(HarvestSpriteActor, entries) == 0x38 ? 1 : -1];
typedef char HarvestSpriteActorFarmCheck[offsetof(HarvestSpriteActor, farm) == 0x3C ? 1 : -1];
typedef char HarvestSpriteActorFlag41Check[offsetof(HarvestSpriteActor, unk_41) == 0x41 ? 1 : -1];
typedef char HarvestSpriteActorFlag42Check[offsetof(HarvestSpriteActor, unk_42) == 0x42 ? 1 : -1];

typedef char HarvestSpriteControllerSizeCheck[sizeof(HarvestSpriteController) == 0xD4 ? 1 : -1];
typedef char HarvestSpriteControllerResourceOffsetCheck[offsetof(HarvestSpriteController, resource_sprite) == 0x8C ? 1 : -1];
typedef char HarvestSpriteControllerXOffsetCheck[offsetof(HarvestSpriteController, resource_x) == 0xCC ? 1 : -1];
typedef char HarvestSpriteControllerYOffsetCheck[offsetof(HarvestSpriteController, resource_y) == 0xCE ? 1 : -1];
typedef char HarvestSpriteControllerDurationOffsetCheck[offsetof(HarvestSpriteController, duration) == 0xD0 ? 1 : -1];

extern "C" void func_080330F4(EntityUiHarvestSpriteResult * result,
    Farm * farm, GameObject * game_object, Location const * location,
    HarvestSprite::Task task, HarvestSpriteWorkTarget const * entries);

// Convert task experience to the native fixed-point value; exact use remains unnamed.
extern "C" u32 func_08033914(u32 task_experience);

// Test the selected work entry before and after its shared result calculation.
extern "C" bool func_08033B24(HarvestSpriteActor * state);

// Lookup the animation for the actor's state byte and the supplied selector.
extern "C" u32 func_08034248(HarvestSpriteActor const * state, u32 value);

// The flag at byte 0x41 still has no confirmed game-level meaning.
extern "C" void ClearEntityUiUnknownFlag41(HarvestSpriteActor * state);

// Ignore a missing visual; otherwise forward the table index and both values.
extern "C" void SetEntityUiResource(HarvestSpriteActor * state,
    u32 table_index, u32 first_value, u32 second_value);

// Resolve the resource, store the setup halfwords and reset its duration to 60.
extern "C" void InitializeEntityUiResourceFromTable(HarvestSpriteController * state,
    u32 table_index, u32 first_value, u32 second_value);

extern "C" u32 GetEntityUiResourceTableIndex(HarvestSpriteActor const * state);

extern "C" HarvestSpriteController * GetEntityUiResourceSetup(HarvestSpriteActor const * state);

extern "C" void SetSelectedEntityUiResource(HarvestSpriteActor * state,
    u32 first_value, u32 second_value);


extern "C" u32 const gUnk_080F143C[];
extern "C" u16 const gEntityUiAnimationLookupTable[];
extern "C" u8 const gUnk_080F1496[];
extern "C" u32 const gUnk_080F149C[];
extern "C" u32 const gUnk_080F14B8[];
extern "C" u16 const gUnk_080F14D4[];
extern "C" u16 const gUnk_080F14E2[];
extern "C" u16 const gUnk_080F14F0[];


extern "C" char const gCppRuntimeError_EntityUiAfterOffsets[];

#endif // HARVEST_SPRITE_ACTOR_HH
