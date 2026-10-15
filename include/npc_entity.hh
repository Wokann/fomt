#ifndef NPC_ENTITY_HH
#define NPC_ENTITY_HH

#include "entity_actor.hh"

struct Npc;
struct ScheduleInfo;
struct ScheduleEntry;
struct PathPointA;

struct ANpcEntity : public AActorEntity
{
    ANpcEntity(GameObject * game_object, Npc * npc, u32 arg_3, void const * arg_4, u32 anim_id, u32 arg_6, u32 arg_7);
    ~ANpcEntity();

    /* vt+3C */ virtual void vfunc_3C(u32 unk_arg_1);

    /* +30 */ Npc * npc;
    /* +34 */ u32 unk_34;
    /* +38 */ ScheduleInfo const * schedule_info;
    /* +3C */ u8 unk_3C; /* current schedule */
    /* +3D */ u8 unk_3D; /* current path */
    /* +3E */ u8 unk_3E; /* current path point */
    /* +3F */ u8 unk_3F; /* is frozen? */
    /* +40 */ u16 unk_40;
    /* +42 */ u16 unk_42;
    /* +44 */ u16 unk_44; /* moving anim? */
    /* +46 */ u16 unk_46; /* frozen anim? */
};

typedef char NpcEntitySizeCheck[sizeof(ANpcEntity) == 0x48 ? 1 : -1];
typedef char NpcEntityNpcCheck[offsetof(ANpcEntity, npc) == 0x30 ? 1 : -1];
typedef char NpcEntityScheduleCheck[offsetof(ANpcEntity, schedule_info) == 0x38 ? 1 : -1];

EXTERN_C

// Return the first entry strictly later than minute.
// Both existing callers pass zero in r3 and the first stack argument;
// the implementation does not read either word. Their meanings are unknown.
ScheduleEntry const * FindScheduleEntryUpperBound(ScheduleEntry const * first,
    ScheduleEntry const * last, u32 const & minute, u32 unk_r3, u32 unk_stack);

// Same upper-bound rule for the timed path's relative-minute entries.
// The trailing words are likewise zero at the native caller and unread.
PathPointA const * FindTimedPathPointUpperBound(PathPointA const * first,
    PathPointA const * last, u32 const & elapsed_minute, u32 unk_r3, u32 unk_stack);

// Test whether the selected schedule's current path starts outside the farmhouse.
// The character associated with this particular descriptor is not yet named.
bool func_08034C64(void const * context, GameTime const & time);

void func_08034E8C(ANpcEntity & self);
void func_08034EA0(ANpcEntity & self);
void func_08034EB4(ANpcEntity & self);
u32 func_08034EE0(ANpcEntity & self);
void func_08034EF8(ANpcEntity & self, u32 unk_arg_1);
void func_08034F00(ANpcEntity * self, int unk_arg_1);
void func_08035380(ANpcEntity & self);

EXTERN_C_END

#endif // NPC_ENTITY_HH
