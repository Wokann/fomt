#ifndef NPC_ENTITY_HH
#define NPC_ENTITY_HH

#include "entity_actor.hh"
#include "npc_schedule.hh"

struct Npc;

#pragma interface "npc_entity.hh"
struct ANpcEntity : public AActorEntity
{
    ANpcEntity(GameObject * game_object, Npc * npc, u32 arg_3, void const * arg_4, u32 anim_id, u32 arg_6, u32 arg_7);
    ~ANpcEntity();

    virtual void vfunc_14();
    virtual void Update(EntityUpdateContext const & context);
    virtual void ResumeNormalUpdates();
    // The NPC override chooses its explicit script or its default script ID.
    virtual u32 vfunc_34();
    virtual void SetEventScript(MaryScriptId script_id);
    /* vt+3C */ virtual void UpdateSchedule(i32 refresh_kind);

    // Passed to the schedule selector; different NPC types share this slot.
    void const * GetScheduleContext() const;

    /* +30 */ Npc * npc;
    /* +34 */ void const * schedule_context;
    /* +38 */ ScheduleInfo const * schedule_info;
    /* +3C */ u8 unk_3C; /* current schedule */
    /* +3D */ u8 unk_3D; /* current path */
    /* +3E */ u8 unk_3E; /* current path point */
    /* +3F */ u8 unk_3F; /* is frozen? */
    /* +40 */ u16 unk_40;
    /* +42 */ u16 unk_42;
    /* +44 */ u16 unk_44; /* default/idle animation */
    /* +46 */ u16 unk_46; /* walking animation */
};

// Concrete scheduled actors follow their native construction order.
// The world factory allocates 0x48 bytes for these actors, except Child's 0x4C.
// Those native allocation sizes remain fixed until that factory is recovered.
struct LilliaNpcActor : ANpcEntity {
    LilliaNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct RickNpcActor : ANpcEntity {
    RickNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct PopuriNpcActor : ANpcEntity {
    PopuriNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
    virtual void UpdateSchedule(i32 refresh_kind);
};

struct BarleyNpcActor : ANpcEntity {
    BarleyNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct MayNpcActor : ANpcEntity {
    MayNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct SaibaraNpcActor : ANpcEntity {
    SaibaraNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct GrayNpcActor : ANpcEntity {
    GrayNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct DukeNpcActor : ANpcEntity {
    DukeNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct MannaNpcActor : ANpcEntity {
    MannaNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct BasilNpcActor : ANpcEntity {
    BasilNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct AnnaNpcActor : ANpcEntity {
    AnnaNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct MaryNpcActor : ANpcEntity {
    MaryNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
    virtual void UpdateSchedule(i32 refresh_kind);
};

struct ThomasNpcActor : ANpcEntity {
    ThomasNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct HarrisNpcActor : ANpcEntity {
    HarrisNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct EllenNpcActor : ANpcEntity {
    EllenNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct StuNpcActor : ANpcEntity {
    StuNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct JeffNpcActor : ANpcEntity {
    JeffNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct SashaNpcActor : ANpcEntity {
    SashaNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct KarenNpcActor : ANpcEntity {
    KarenNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
    virtual void UpdateSchedule(i32 refresh_kind);
};

struct DoctorNpcActor : ANpcEntity {
    DoctorNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct ElliNpcActor : ANpcEntity {
    ElliNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
    virtual void UpdateSchedule(i32 refresh_kind);
};

struct CarterNpcActor : ANpcEntity {
    CarterNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct CliffNpcActor : ANpcEntity {
    CliffNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
    virtual void UpdateSchedule(i32 refresh_kind);
};

struct DougNpcActor : ANpcEntity {
    DougNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct LouOrRubyNpcActor : ANpcEntity {
    LouOrRubyNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct AnnNpcActor : ANpcEntity {
    AnnNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
    virtual void UpdateSchedule(i32 refresh_kind);
};

struct KaiNpcActor : ANpcEntity {
    KaiNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct GotzNpcActor : ANpcEntity {
    GotzNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
    virtual void UpdateSchedule(i32 refresh_kind);
};

struct ZackNpcActor : ANpcEntity {
    ZackNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
    virtual void Update(EntityUpdateContext const & context);
    virtual void UpdateSchedule(i32 refresh_kind);
};

struct WonNpcActor : ANpcEntity {
    WonNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct GourmetNpcActor : ANpcEntity {
    GourmetNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct HarvestGoddessNpcActor : ANpcEntity {
    HarvestGoddessNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct KappaNpcActor : ANpcEntity {
    KappaNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

struct VanNpcActor : ANpcEntity {
    VanNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
};

// Native child update copies four choices and selects by cumulative weight
// from rand() % 100. The byte at +1 is natural halfword-alignment padding.
struct ChildIdleAnimationChoice {
    u8 weight;
    u16 animation;
};


struct ChildNpcActor : ANpcEntity {
    ChildNpcActor(GameObject * world, Npc * npc, u32 context);
    virtual EntityVisualController * CreateVisualController();
    virtual void Update(EntityUpdateContext const & context);
    virtual void UpdateSchedule(i32 refresh_kind);

    // Counts down between the child's random idle-animation selections.
    u16 idle_animation_countdown;
};




EXTERN_C

// Test whether the selected schedule's current path starts outside the farmhouse.
bool IsChildScheduleOutsideFarmhouse(void const * context, GameTime const & time);

void func_08035380(ANpcEntity & self);
void RefreshCliffNpcAnimations(ANpcEntity & self);

// Replace a configured animation; update the live animation only while it
// still uses the previous value and IsNormalUpdateSuspended is false. Inputs remain u32;
// only the stored configuration truncates to the native halfword.
void SetNpcIdleAnimation(ANpcEntity & self, u32 animation);
void SetNpcWalkingAnimation(ANpcEntity & self, u32 animation);

// Still-native predicate: timed-path counter or the following schedule time.
bool IsNpcScheduleTransitionDue(ANpcEntity & self);

// Pause a nearby NPC only when the native path predicate and IsNormalUpdateSuspended allow it.
void PauseNpcNearLocation(ANpcEntity & self, Location const & other);
// The original animation selector distinguishes the farmhouse strip at Y <= 55.
bool IsNpcInUpperFarmhouseStrip(ANpcEntity & self);

EXTERN_C_END

extern "C" ChildIdleAnimationChoice const gChildIdleAnimationChoices[];


extern "C" char const gCppRuntimeError_EntityUiFirst[];

#endif // NPC_ENTITY_HH
