
#include "npc_entity.hh"
extern "C" void func_08036E70(void * actor);

#include "npc.hh"
#include "game_state_types.hh"
#include "npc_schedule.hh"
#include "npc_schedule_rick.hh"
#include "npc_schedule_popuri.hh"
#include "npc_schedule_lillia.hh"
#include "npc_schedule_child.hh"
#include "npc_schedule_cliff.hh"
#include "npc_schedule_zack.hh"
#include "npc_schedule_doctor.hh"
#include "npc_schedule_ellen.hh"
#include "npc_schedule_jeff.hh"
#include "npc_schedule_karen.hh"
#include "npc_schedule_sasha.hh"
#include "npc_schedule_doug.hh"
#include "npc_schedule_ann.hh"
#include "npc_schedule_lou.hh"
#include "npc_schedule_basil.hh"
#include "npc_schedule_mary.hh"
#include "npc_schedule_anna.hh"
#include "npc_schedule_won.hh"
#include "npc_schedule_thomas.hh"
#include "npc_schedule_elli.hh"
#include "npc_schedule_stu.hh"
#include "npc_schedule_duke.hh"
#include "npc_schedule_manna.hh"
#include "npc_schedule_van.hh"
#include "npc_schedule_harris.hh"
#include "npc_schedule_carter.hh"
#include "npc_schedule_kai.hh"
#include "npc_schedule_gray.hh"
#include "npc_schedule_saibara.hh"
#include "npc_schedule_gotz.hh"
#include "npc_schedule_may.hh"
#include "npc_schedule_barley.hh"
#include <algorithm>

// The shared search instance is defined in npc_schedule_search.cc.
extern template ScheduleEntry const * std::__upper_bound<
    ScheduleEntry const *, u32, NpcScheduleTimeCompare, ptrdiff_t>(
    ScheduleEntry const *, ScheduleEntry const *, u32 const &,
    NpcScheduleTimeCompare, ptrdiff_t *);

#include "data/scripts/fomt_scripts.mary.h"

#include FOMT_TEXT_INCLUDE(npc_entity.cc)


static inline void TMP_ChangeAnim(ANpcEntity & self, u32 new_anim_id)
{
    if (self.anim_id != new_anim_id)
    {
        self.SetAnim(new_anim_id);
    }
}

static inline u32 TMP_GetAnim(ANpcEntity & self)
{
    return self.anim_id;
}

EC bool IsChildScheduleOutsideFarmhouse(void const * context, GameTime const & time)
{
    ScheduleInfo const & info = gChildScheduleData.descriptor;
    Schedule const * schedule = info.schedules[info.select_schedule(context)];
    if (schedule != nullptr) {
        i32 hour = time.clock_hour - 6;
        if (hour < 0)
            hour += 24;
        u32 minute = hour * 60 + time.clock_minute;
        ScheduleEntry const * first = schedule->time_entries;
        u32 index = std::__upper_bound(first, first + schedule->num_time_entries,
            minute, NpcScheduleTimeCompare(), static_cast<ptrdiff_t *>(0)) - first - 1;
        if (index < schedule->num_time_entries) {
            PathInfo const * path = schedule->time_entries[index].path;
            if (path != nullptr)
                return path->location_start != MAP_FARMHOUSE;
        }
    }
    return false;
}

ANpcEntity::ANpcEntity(GameObject * game_object, Npc * npc, u32 arg_3, void const * arg_4, u32 anim_id, u32 arg_6, u32 arg_7)
    : AActorEntity(game_object, npc->GetLocation(), 2, npc->anim_id == NO_ANIM ? anim_id : npc->anim_id),
      npc(npc),
      schedule_context(reinterpret_cast<void const *>(arg_3)),
      schedule_info(static_cast<ScheduleInfo const *>(arg_4)),
      unk_3C(npc->unk_0C_0),
      unk_3D(npc->unk_0C_5),
      unk_3E(npc->unk_0D_2),
      unk_3F(0),
      unk_40(npc->unk_0D_7),
      unk_42(arg_7),
      unk_44(anim_id),
      unk_46(arg_6)
{
    if (this->npc->anim_id == NO_ANIM)
    {
        ANpcEntity::UpdateSchedule(true);
    }
    else
    {
        normal_update_suspended = true;
        TMP_ChangeAnim(*this, npc->anim_id);
    }
}

ANpcEntity::~ANpcEntity()
{
    npc->SetLocation(GetLocation());

    if (normal_update_suspended)
    {
        npc->anim_id = TMP_GetAnim(*this);
    }
    else
    {
        npc->anim_id = NO_ANIM;
    }

    if (schedule_info != nullptr)
    {
        npc->unk_0C_0 = unk_3C;
        npc->unk_0C_5 = unk_3D;
        npc->unk_0D_2 = unk_3E;
        npc->unk_0D_7 = unk_40;
    }
}

void ANpcEntity::vfunc_14()
{
    AActorEntity::vfunc_14();
    npc->SetChangedLocation();
}

void ANpcEntity::ResumeNormalUpdates()
{
    normal_update_suspended = false;
    UpdateSchedule(1);
}

void ANpcEntity::Update(EntityUpdateContext const & context)
{
    func_08035380(*this);

    if (animation_countdown != 0)
        animation_countdown--;
    else
        animation_countdown = animation_reload;

    if (unk_10.Get() != nullptr)
        unk_10->Update();
}

u32 ANpcEntity::vfunc_34()
{
    if (npc->unk_10 == 0)
        return unk_42;

    return npc->unk_10;
}

void ANpcEntity::SetEventScript(MaryScriptId script_id)
{
    npc->unk_10 = script_id;
}

NAKED void ANpcEntity::UpdateSchedule(i32 refresh_kind)
{
    // https://decomp.me/scratch/hL2sP

    asm_unified("\
        push {r4, r5, r6, r7, lr}\n\
        mov r7, sl\n\
        mov r6, sb\n\
        mov r5, r8\n\
        push {r5, r6, r7}\n\
        sub sp, #0x34\n\
        adds r6, r0, #0\n\
        str r1, [sp, #0x14]\n\
        cmp r1, #0\n\
        bgt .L08034F16\n\
        b .L08035370\n\
    .L08034F16:\n\
        ldr r1, [r6, #0x38]\n\
        movs r0, #0x3c\n\
        adds r0, r0, r6\n\
        mov r8, r0\n\
        adds r2, r6, #0\n\
        adds r2, #0x3d\n\
        str r2, [sp, #0x30]\n\
        cmp r1, #0\n\
        bne .L08034F2A\n\
        b .L08035312\n\
    .L08034F2A:\n\
        ldr r3, [sp, #0x14]\n\
        cmp r3, #2\n\
        ble .L08034F3C\n\
        ldr r0, [r6, #0x34]\n\
        ldr r1, [r1]\n\
        bl _call_via_r1\n\
        mov r4, r8\n\
        strb r0, [r4]\n\
    .L08034F3C:\n\
        ldr r0, [r6, #0x38]\n\
        mov r2, r8\n\
        ldrb r1, [r2]\n\
        ldr r0, [r0, #8]\n\
        lsls r1, r1, #2\n\
        adds r1, r1, r0\n\
        ldr r7, [r1]\n\
        cmp r7, #0\n\
        bne .L08034F50\n\
        b .L08035312\n\
    .L08034F50:\n\
        ldr r0, [r6]\n\
        ldr r1, [r0]\n\
        movs r3, #0xa2\n\
        lsls r3, r3, #1\n\
        adds r1, r1, r3\n\
        ldr r1, [r1]\n\
        bl _call_via_r1\n\
        ldrh r3, [r0, #0xa]\n\
        lsls r0, r3, #0x1b\n\
        lsrs r0, r0, #0x1b\n\
        subs r2, r0, #6\n\
        cmp r2, #0\n\
        bge .L08034F6E\n\
        adds r2, #0x18\n\
    .L08034F6E:\n\
        lsls r1, r2, #4\n\
        subs r1, r1, r2\n\
        lsls r1, r1, #2\n\
        lsls r0, r3, #0x15\n\
        lsrs r0, r0, #0x1a\n\
        adds r1, r1, r0\n\
        mov sl, r1\n\
        ldr r4, [sp, #0x14]\n\
        cmp r4, #2\n\
        ble .L08034FAA\n\
        str r1, [sp, #0xc]\n\
        ldr r4, [r7, #4]\n\
        ldrh r1, [r7]\n\
        lsls r1, r1, #3\n\
        adds r1, r4, r1\n\
        add r2, sp, #0xc\n\
        movs r5, #0\n\
        str r5, [sp]\n\
        adds r0, r4, #0\n\
        movs r3, #0\n\
        bl __upper_bound__H4ZPC13ScheduleEntryZUiZ22NpcScheduleTimeCompareZl_X01T0RCX11X21PX31_X01\n\
        subs r0, r0, r4\n\
        asrs r0, r0, #3\n\
        subs r0, #1\n\
        ldr r1, [sp, #0x30]\n\
        strb r0, [r1]\n\
        adds r0, r6, #0\n\
        adds r0, #0x3e\n\
        strb r5, [r0]\n\
    .L08034FAA:\n\
        ldr r2, [sp, #0x30]\n\
        ldrb r1, [r2]\n\
        ldrh r3, [r7]\n\
        cmp r1, r3\n\
        blo .L08034FB6\n\
        b .L08035312\n\
    .L08034FB6:\n\
        lsls r1, r1, #3\n\
        ldr r0, [r7, #4]\n\
        adds r3, r0, r1\n\
        ldr r4, [r3, #4]\n\
        str r4, [sp, #0x18]\n\
        cmp r4, #0\n\
        bne .L08034FC6\n\
        b .L08035312\n\
    .L08034FC6:\n\
        movs r0, #0\n\
        str r0, [sp, #0x1c]\n\
        ldr r4, [r4]\n\
        cmp r4, #0\n\
        bne .L08034FD2\n\
        b .L08035290\n\
    .L08034FD2:\n\
        ldr r2, [sp, #0x18]\n\
        ldrh r1, [r2, #4]\n\
        cmp r1, #0\n\
        bne .L08034FDC\n\
        b .L08035290\n\
    .L08034FDC:\n\
        adds r0, r6, #0\n\
        adds r0, #0x3e\n\
        ldrb r2, [r0]\n\
        mov sb, r0\n\
        cmp r2, r1\n\
        blo .L08034FEA\n\
        b .L08035312\n\
    .L08034FEA:\n\
        ldr r0, [sp, #0x18]\n\
        movs r1, #6\n\
        ldrsh r7, [r0, r1]\n\
        movs r1, #8\n\
        ldrsh r0, [r0, r1]\n\
        mov r8, r0\n\
        ldr r1, [sp, #0x18]\n\
        ldrb r0, [r1, #0xb]\n\
        lsls r1, r0, #0x1c\n\
        lsrs r5, r1, #0x1e\n\
        lsls r0, r0, #0x1b\n\
        cmp r0, #0\n\
        bge .L08035006\n\
        b .L08035184\n\
    .L08035006:\n\
        str r4, [sp, #0x20]\n\
        ldrh r0, [r3]\n\
        movs r1, #0\n\
        cmp sl, r0\n\
        blo .L08035014\n\
        mov r2, sl\n\
        subs r1, r2, r0\n\
    .L08035014:\n\
        str r1, [sp, #0x10]\n\
        ldr r3, [sp, #0x14]\n\
        cmp r3, #2\n\
        ble .L08035048\n\
        ldr r0, [sp, #0x18]\n\
        ldrh r1, [r0, #4]\n\
        lsls r1, r1, #3\n\
        adds r1, r4, r1\n\
        add r2, sp, #0x10\n\
        ldr r3, [sp, #0x1c]\n\
        str r3, [sp]\n\
        adds r0, r4, #0\n\
        movs r3, #0\n\
        bl __upper_bound__H4ZPC10PathPointAZUiZ18NpcPathTimeCompareZl_X01T0RCX11X21PX31_X01\n\
        subs r0, r0, r4\n\
        asrs r0, r0, #3\n\
        mov r4, sb\n\
        strb r0, [r4]\n\
        ldr r0, [sp, #0x18]\n\
        ldrh r1, [r0, #4]\n\
        ldrb r0, [r4]\n\
        cmp r0, r1\n\
        blo .L08035048\n\
        subs r0, r1, #1\n\
        strb r0, [r4]\n\
    .L08035048:\n\
        mov r1, sb\n\
        ldrb r0, [r1]\n\
        lsls r0, r0, #3\n\
        ldr r2, [sp, #0x20]\n\
        adds r4, r2, r0\n\
        movs r3, #0\n\
        str r3, [sp, #0x24]\n\
        adds r0, r6, #0\n\
        adds r0, #0x20\n\
        str r0, [sp, #0x2c]\n\
        cmp r2, r4\n\
        beq .L08035094\n\
    .L08035060:\n\
        ldrh r1, [r2]\n\
        str r1, [sp, #0x24]\n\
        movs r3, #2\n\
        ldrsh r1, [r2, r3]\n\
        ldrb r0, [r2, #4]\n\
        lsls r0, r0, #0x1f\n\
        cmp r0, #0\n\
        bne .L08035080\n\
        cmp r7, r1\n\
        beq .L0803508E\n\
        movs r5, #3\n\
        cmp r7, r1\n\
        ble .L0803507C\n\
        movs r5, #2\n\
    .L0803507C:\n\
        adds r7, r1, #0\n\
        b .L0803508E\n\
    .L08035080:\n\
        cmp r8, r1\n\
        beq .L0803508E\n\
        movs r5, #0\n\
        cmp r8, r1\n\
        ble .L0803508C\n\
        movs r5, #1\n\
    .L0803508C:\n\
        mov r8, r1\n\
    .L0803508E:\n\
        adds r2, #8\n\
        cmp r2, r4\n\
        bne .L08035060\n\
    .L08035094:\n\
        movs r1, #0\n\
        ldrb r0, [r4, #4]\n\
        lsls r0, r0, #0x1f\n\
        cmp r0, #0\n\
        bne .L080350A0\n\
        movs r1, #1\n\
    .L080350A0:\n\
        mov sb, r1\n\
        movs r1, #2\n\
        ldrsh r0, [r4, r1]\n\
        mov r3, r8\n\
        subs r2, r0, r3\n\
        mov r1, sb\n\
        cmp r1, #0\n\
        beq .L080350B2\n\
        subs r2, r0, r7\n\
    .L080350B2:\n\
        str r2, [sp, #0x28]\n\
        cmp r2, #0\n\
        beq .L0803510E\n\
        ldrh r0, [r4]\n\
        ldr r3, [sp, #0x24]\n\
        subs r0, r0, r3\n\
        movs r1, #0x19\n\
        adds r3, r0, #0\n\
        muls r3, r1, r3\n\
        adds r0, r6, #0\n\
        adds r0, #0x3f\n\
        ldrb r1, [r0]\n\
        mov sl, r0\n\
        cmp r1, #0\n\
        bne .L080350DA\n\
        lsls r0, r2, #0x10\n\
        adds r1, r3, #0\n\
        bl __divsi3\n\
        b .L080350DC\n\
    .L080350DA:\n\
        movs r0, #0\n\
    .L080350DC:\n\
        mov r2, sb\n\
        cmp r2, #0\n\
        beq .L080350F2\n\
        movs r5, #3\n\
        ldr r3, [sp, #0x28]\n\
        cmp r3, #0\n\
        bge .L080350EC\n\
        movs r5, #2\n\
    .L080350EC:\n\
        str r0, [r6, #0x18]\n\
        movs r0, #0\n\
        b .L080350FA\n\
    .L080350F2:\n\
        ldr r1, [sp, #0x28]\n\
        lsrs r5, r1, #0x1f\n\
        mov r2, sb\n\
        str r2, [r6, #0x18]\n\
    .L080350FA:\n\
        str r0, [r6, #0x1c]\n\
        movs r3, #0\n\
        str r3, [sp, #0x1c]\n\
        mov r1, sl\n\
        ldrb r0, [r1]\n\
        cmp r0, #0\n\
        bne .L08035112\n\
        movs r2, #1\n\
        str r2, [sp, #0x1c]\n\
        b .L08035112\n\
    .L0803510E:\n\
        str r2, [r6, #0x18]\n\
        str r2, [r6, #0x1c]\n\
    .L08035112:\n\
        ldr r3, [sp, #0x14]\n\
        cmp r3, #2\n\
        ble .L08035168\n\
        adds r1, r6, #0\n\
        adds r1, #0x40\n\
        movs r0, #0\n\
        strh r0, [r1]\n\
        mov r0, sb\n\
        cmp r0, #0\n\
        beq .L08035146\n\
        ldr r0, [sp, #0x10]\n\
        ldrh r1, [r4]\n\
        cmp r0, r1\n\
        bhs .L08035140\n\
        ldr r1, [r6, #0x18]\n\
        ldr r2, [sp, #0x24]\n\
        subs r0, r0, r2\n\
        movs r3, #0x19\n\
        muls r0, r3, r0\n\
        muls r0, r1, r0\n\
        asrs r0, r0, #0x10\n\
        adds r7, r7, r0\n\
        b .L08035266\n\
    .L08035140:\n\
        movs r0, #2\n\
        ldrsh r7, [r4, r0]\n\
        b .L08035266\n\
    .L08035146:\n\
        ldr r0, [sp, #0x10]\n\
        ldrh r1, [r4]\n\
        cmp r0, r1\n\
        bhs .L08035160\n\
        ldr r1, [r6, #0x1c]\n\
        ldr r2, [sp, #0x24]\n\
        subs r0, r0, r2\n\
        movs r3, #0x19\n\
        muls r0, r3, r0\n\
        muls r0, r1, r0\n\
        asrs r0, r0, #0x10\n\
        add r8, r0\n\
        b .L08035266\n\
    .L08035160:\n\
        movs r1, #2\n\
        ldrsh r0, [r4, r1]\n\
        mov r8, r0\n\
        b .L08035266\n\
    .L08035168:\n\
        ldr r2, [sp, #0x14]\n\
        cmp r2, #1\n\
        bgt .L08035170\n\
        b .L0803527E\n\
    .L08035170:\n\
        ldr r0, [sp, #0x10]\n\
        ldr r3, [sp, #0x24]\n\
        subs r0, r0, r3\n\
        movs r4, #0x19\n\
        adds r1, r0, #0\n\
        muls r1, r4, r1\n\
        adds r0, r6, #0\n\
        adds r0, #0x40\n\
        strh r1, [r0]\n\
        b .L08035266\n\
    .L08035184:\n\
        lsls r0, r2, #3\n\
        adds r3, r4, r0\n\
        adds r1, r4, #0\n\
        movs r0, #0x40\n\
        adds r0, r0, r6\n\
        mov sb, r0\n\
        adds r2, r6, #0\n\
        adds r2, #0x20\n\
        str r2, [sp, #0x2c]\n\
        cmp r1, r3\n\
        beq .L080351BC\n\
    .L0803519A:\n\
        movs r4, #0\n\
        ldrsh r2, [r1, r4]\n\
        ldrb r0, [r1, #6]\n\
        lsls r0, r0, #0x1d\n\
        cmp r0, #0\n\
        blt .L080351AE\n\
        cmp r7, r2\n\
        beq .L080351B4\n\
        adds r7, r2, #0\n\
        b .L080351B4\n\
    .L080351AE:\n\
        cmp r8, r2\n\
        beq .L080351B4\n\
        mov r8, r2\n\
    .L080351B4:\n\
        ldrh r0, [r1, #4]\n\
        adds r1, #8\n\
        cmp r1, r3\n\
        bne .L0803519A\n\
    .L080351BC:\n\
        ldr r0, [sp, #0x14]\n\
        cmp r0, #1\n\
        ble .L080351C8\n\
        movs r0, #0\n\
        mov r1, sb\n\
        strh r0, [r1]\n\
    .L080351C8:\n\
        movs r1, #0\n\
        ldrb r0, [r3, #6]\n\
        lsls r0, r0, #0x1d\n\
        cmp r0, #0\n\
        blt .L080351D4\n\
        movs r1, #1\n\
    .L080351D4:\n\
        adds r5, r1, #0\n\
        movs r2, #0\n\
        ldrsh r0, [r3, r2]\n\
        mov r1, r8\n\
        subs r4, r0, r1\n\
        cmp r5, #0\n\
        beq .L080351E4\n\
        subs r4, r0, r7\n\
    .L080351E4:\n\
        mov r2, sb\n\
        ldrh r0, [r2]\n\
        cmp r0, #0\n\
        bne .L0803524A\n\
        cmp r4, #0\n\
        beq .L0803524A\n\
        adds r0, r6, #0\n\
        adds r0, #0x3f\n\
        ldrb r1, [r0]\n\
        movs r2, #0\n\
        mov sl, r0\n\
        cmp r1, #0\n\
        bne .L08035202\n\
        movs r2, #0x80\n\
        lsls r2, r2, #8\n\
    .L08035202:\n\
        ldrh r0, [r3, #2]\n\
        cmp r0, #0\n\
        beq .L0803520A\n\
        muls r2, r0, r2\n\
    .L0803520A:\n\
        cmp r5, #0\n\
        beq .L08035224\n\
        cmp r4, #0\n\
        bge .L0803521A\n\
        movs r5, #2\n\
        rsbs r0, r2, #0\n\
        str r0, [r6, #0x18]\n\
        b .L0803521E\n\
    .L0803521A:\n\
        movs r5, #3\n\
        str r2, [r6, #0x18]\n\
    .L0803521E:\n\
        movs r0, #0\n\
        str r0, [r6, #0x1c]\n\
        b .L08035238\n\
    .L08035224:\n\
        cmp r4, #0\n\
        bge .L08035230\n\
        movs r5, #1\n\
        rsbs r0, r2, #0\n\
        str r0, [r6, #0x1c]\n\
        b .L08035234\n\
    .L08035230:\n\
        movs r5, #0\n\
        str r2, [r6, #0x1c]\n\
    .L08035234:\n\
        movs r0, #0\n\
        str r0, [r6, #0x18]\n\
    .L08035238:\n\
        movs r3, #0\n\
        str r3, [sp, #0x1c]\n\
        mov r4, sl\n\
        ldrb r0, [r4]\n\
        cmp r0, #0\n\
        bne .L08035266\n\
        movs r0, #1\n\
        str r0, [sp, #0x1c]\n\
        b .L08035266\n\
    .L0803524A:\n\
        cmp r5, #0\n\
        beq .L08035254\n\
        movs r1, #0\n\
        ldrsh r7, [r3, r1]\n\
        b .L0803525A\n\
    .L08035254:\n\
        movs r4, #0\n\
        ldrsh r2, [r3, r4]\n\
        mov r8, r2\n\
    .L0803525A:\n\
        movs r0, #0\n\
        str r0, [r6, #0x18]\n\
        str r0, [r6, #0x1c]\n\
        ldrb r0, [r3, #6]\n\
        lsls r0, r0, #0x1e\n\
        lsrs r5, r0, #0x1e\n\
    .L08035266:\n\
        ldr r0, [sp, #0x14]\n\
        cmp r0, #1\n\
        ble .L0803527E\n\
        ldr r2, [sp, #0x18]\n\
        ldrh r1, [r2, #0xa]\n\
        lsls r1, r1, #0x16\n\
        lsrs r1, r1, #0x16\n\
        adds r0, r6, #0\n\
        adds r2, r7, #0\n\
        mov r3, r8\n\
        bl SetLocation__7AEntityUiii\n\
    .L0803527E:\n\
        ldr r3, [sp, #0x2c]\n\
        ldrb r0, [r3]\n\
        cmp r0, r5\n\
        beq .L080352CA\n\
        adds r0, r6, #0\n\
        adds r1, r5, #0\n\
        bl SetAnimFacing__12AActorEntityUi\n\
        b .L080352CA\n\
    .L08035290:\n\
        ldr r4, [sp, #0x14]\n\
        cmp r4, #1\n\
        ble .L080352AC\n\
        ldr r0, [sp, #0x18]\n\
        ldrh r1, [r0, #0xa]\n\
        lsls r1, r1, #0x16\n\
        lsrs r1, r1, #0x16\n\
        movs r3, #6\n\
        ldrsh r2, [r0, r3]\n\
        movs r4, #8\n\
        ldrsh r3, [r0, r4]\n\
        adds r0, r6, #0\n\
        bl SetLocation__7AEntityUiii\n\
    .L080352AC:\n\
        ldr r1, [sp, #0x18]\n\
        ldrb r0, [r1, #0xb]\n\
        lsls r0, r0, #0x1c\n\
        lsrs r1, r0, #0x1e\n\
        adds r0, r6, #0\n\
        adds r0, #0x20\n\
        ldrb r0, [r0]\n\
        cmp r0, r1\n\
        beq .L080352C4\n\
        adds r0, r6, #0\n\
        bl SetAnimFacing__12AActorEntityUi\n\
    .L080352C4:\n\
        movs r0, #0\n\
        str r0, [r6, #0x18]\n\
        str r0, [r6, #0x1c]\n\
    .L080352CA:\n\
        ldr r2, [sp, #0x14]\n\
        cmp r2, #1\n\
        ble .L080352E2\n\
        ldr r4, [r6, #0x30]\n\
        add r0, sp, #4\n\
        adds r1, r6, #0\n\
        bl GetLocation__C12AActorEntity\n\
        adds r0, r4, #0\n\
        add r1, sp, #4\n\
        bl SetLocation__3NpcRC13ActorLocation\n\
    .L080352E2:\n\
        ldr r3, [sp, #0x1c]\n\
        cmp r3, #0\n\
        beq .L080352F8\n\
        ldr r0, [r6, #0x14]\n\
        ldr r1, [r0, #0x28]\n\
        adds r0, r6, #0\n\
        bl _call_via_r1\n\
        lsls r0, r0, #0x18\n\
        cmp r0, #0\n\
        beq .L080352FE\n\
    .L080352F8:\n\
        adds r0, r6, #0\n\
        adds r0, #0x44\n\
        b .L08035302\n\
    .L080352FE:\n\
        adds r0, r6, #0\n\
        adds r0, #0x46\n\
    .L08035302:\n\
        ldrh r1, [r0]\n\
        ldrh r0, [r6, #0x22]\n\
        cmp r0, r1\n\
        beq .L08035370\n\
        adds r0, r6, #0\n\
        bl SetAnim__12AActorEntityUi\n\
        b .L08035370\n\
    .L08035312:\n\
        ldr r4, [sp, #0x14]\n\
        cmp r4, #1\n\
        ble .L08035334\n\
        adds r0, r6, #0\n\
        movs r1, #0x8d\n\
        lsls r1, r1, #2\n\
        bl SetMap__7AEntityUi\n\
        ldr r4, [r6, #0x30]\n\
        add r0, sp, #4\n\
        adds r1, r6, #0\n\
        bl GetLocation__C12AActorEntity\n\
        adds r0, r4, #0\n\
        add r1, sp, #4\n\
        bl SetLocation__3NpcRC13ActorLocation\n\
    .L08035334:\n\
        adds r0, r6, #0\n\
        adds r0, #0x20\n\
        ldrb r0, [r0]\n\
        cmp r0, #0\n\
        beq .L08035346\n\
        adds r0, r6, #0\n\
        movs r1, #0\n\
        bl SetAnimFacing__12AActorEntityUi\n\
    .L08035346:\n\
        movs r4, #0\n\
        str r4, [r6, #0x18]\n\
        str r4, [r6, #0x1c]\n\
        adds r0, r6, #0\n\
        adds r0, #0x44\n\
        ldrh r1, [r0]\n\
        ldrh r0, [r6, #0x22]\n\
        cmp r0, r1\n\
        beq .L0803535E\n\
        adds r0, r6, #0\n\
        bl SetAnim__12AActorEntityUi\n\
    .L0803535E:\n\
        mov r0, r8\n\
        strb r4, [r0]\n\
        ldr r1, [sp, #0x30]\n\
        strb r4, [r1]\n\
        adds r0, r6, #0\n\
        adds r0, #0x3e\n\
        strb r4, [r0]\n\
        adds r0, #2\n\
        strh r4, [r0]\n\
    .L08035370:\n\
        add sp, #0x34\n\
        pop {r3, r4, r5}\n\
        mov r8, r3\n\
        mov sb, r4\n\
        mov sl, r5\n\
        pop {r4, r5, r6, r7}\n\
        pop {r0}\n\
        bx r0\n\
    ");
}

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
#if defined(REGION_JP)
    "    .align 2, 0\n"
    "\n"
    "    .global func_08035380\n"
    "    .thumb_func\n"
    "func_08035380:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, sl\n"
    "    mov\tr6, r9\n"
    "    mov\tr5, r8\n"
    "    push\t{r5, r6, r7}\n"
    "    sub\tsp, #188\t@ 0xbc\n"
    "    adds\tr6, r0, #0\n"
    "    ldr\tr5, [r6, #0]\n"
    "    ldr\tr1, [r6, #56]\t@ 0x38\n"
    "    cmp\tr1, #0\n"
    "    bne .Ljp_0803512C\n"
    "    b .Ljp_0803568C\n"
    ".Ljp_0803512C:\n"
    "    adds\tr0, #60\t@ 0x3c\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    ldr\tr1, [r1, #8]\n"
    "    lsls\tr0, r0, #2\n"
    "    adds\tr0, r0, r1\n"
    "    ldr\tr0, [r0, #0]\n"
    "    str\tr0, [sp, #112]\t@ 0x70\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_08035140\n"
    "    b .Ljp_0803568C\n"
    ".Ljp_08035140:\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #61\t@ 0x3d\n"
    "    ldrb\tr1, [r0, #0]\n"
    "    str\tr0, [sp, #176]\t@ 0xb0\n"
    "    ldr\tr0, [sp, #112]\t@ 0x70\n"
    "    ldrh\tr0, [r0, #0]\n"
    "    cmp\tr1, r0\n"
    "    bcc .Ljp_08035152\n"
    "    b .Ljp_0803568C\n"
    ".Ljp_08035152:\n"
    "    lsls\tr1, r1, #3\n"
    "    ldr\tr2, [sp, #112]\t@ 0x70\n"
    "    ldr\tr0, [r2, #4]\n"
    "    adds\tr7, r0, r1\n"
    "    ldr\tr3, [r7, #4]\n"
    "    str\tr3, [sp, #116]\t@ 0x74\n"
    "    cmp\tr3, #0\n"
    "    bne .Ljp_08035164\n"
    "    b .Ljp_0803568C\n"
    ".Ljp_08035164:\n"
    "    ldr\tr0, [r5, #0]\n"
    "    movs\tr4, #162\t@ 0xa2\n"
    "    lsls\tr4, r4, #1\n"
    "    adds\tr0, r0, r4\n"
    "    ldr\tr1, [r0, #0]\n"
    "    adds\tr0, r5, #0\n"
    "    bl _call_via_r1\n"
    "    ldrh\tr3, [r0, #10]\n"
    "    lsls\tr0, r3, #27\n"
    "    lsrs\tr0, r0, #27\n"
    "    subs\tr2, r0, #6\n"
    "    cmp\tr2, #0\n"
    "    bge .Ljp_08035182\n"
    "    adds\tr2, #24\n"
    ".Ljp_08035182:\n"
    "    lsls\tr1, r2, #4\n"
    "    subs\tr1, r1, r2\n"
    "    lsls\tr1, r1, #2\n"
    "    lsls\tr0, r3, #21\n"
    "    lsrs\tr0, r0, #26\n"
    "    adds\tr1, r1, r0\n"
    "    movs\tr0, #0\n"
    "    str\tr0, [sp, #120]\t@ 0x78\n"
    "    ldr\tr2, [sp, #116]\t@ 0x74\n"
    "    ldr\tr3, [r2, #0]\n"
    "    cmp\tr3, #0\n"
    "    bne .Ljp_0803519C\n"
    "    b .Ljp_08035654\n"
    ".Ljp_0803519C:\n"
    "    ldrh\tr4, [r2, #4]\n"
    "    cmp\tr4, #0\n"
    "    bne .Ljp_080351A4\n"
    "    b .Ljp_08035654\n"
    ".Ljp_080351A4:\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #62\t@ 0x3e\n"
    "    ldrb\tr2, [r0, #0]\n"
    "    str\tr0, [sp, #180]\t@ 0xb4\n"
    "    cmp\tr2, r4\n"
    "    bcc .Ljp_080351B2\n"
    "    b .Ljp_0803568C\n"
    ".Ljp_080351B2:\n"
    "    ldr\tr4, [sp, #116]\t@ 0x74\n"
    "    ldrb\tr0, [r4, #11]\n"
    "    lsls\tr0, r0, #27\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_080351BE\n"
    "    b .Ljp_080353CC\n"
    ".Ljp_080351BE:\n"
    "    lsls\tr0, r2, #3\n"
    "    adds\tr3, r3, r0\n"
    "    str\tr3, [sp, #124]\t@ 0x7c\n"
    "    movs\tr1, #0\n"
    "    ldrb\tr0, [r3, #4]\n"
    "    lsls\tr0, r0, #31\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_080351D0\n"
    "    movs\tr1, #1\n"
    ".Ljp_080351D0:\n"
    "    mov\tr8, r1\n"
    "    ldr\tr0, [r6, #8]\n"
    "    str\tr0, [sp, #0]\n"
    "    ldr\tr0, [r6, #12]\n"
    "    str\tr0, [sp, #8]\n"
    "    ldr\tr0, [r6, #24]\n"
    "    str\tr0, [sp, #4]\n"
    "    ldr\tr0, [r6, #28]\n"
    "    str\tr0, [sp, #12]\n"
    "    cmp\tr1, #0\n"
    "    beq .Ljp_080351F0\n"
    "    mov\tsl, sp\n"
    "    mov\tr7, sp\n"
    "    adds\tr7, #4\n"
    "    str\tr7, [sp, #128]\t@ 0x80\n"
    "    b .Ljp_080351FA\n"
    ".Ljp_080351F0:\n"
    "    add\tr0, sp, #8\n"
    "    mov\tsl, r0\n"
    "    mov\tr1, sp\n"
    "    adds\tr1, #12\n"
    "    str\tr1, [sp, #128]\t@ 0x80\n"
    ".Ljp_080351FA:\n"
    "    mov\tr2, sl\n"
    "    ldr\tr1, [r2, #0]\n"
    "    asrs\tr3, r1, #16\n"
    "    str\tr3, [sp, #132]\t@ 0x84\n"
    "    ldr\tr4, [sp, #128]\t@ 0x80\n"
    "    ldr\tr0, [r4, #0]\n"
    "    adds\tr1, r1, r0\n"
    "    str\tr1, [sp, #136]\t@ 0x88\n"
    "    asrs\tr7, r1, #16\n"
    "    str\tr7, [sp, #140]\t@ 0x8c\n"
    "    subs\tr7, r7, r3\n"
    "    movs\tr3, #0\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #64\t@ 0x40\n"
    "    ldrh\tr2, [r0, #0]\n"
    "    ldr r1, .Ljp_08035240\n"
    "    str\tr0, [sp, #184]\t@ 0xb8\n"
    "    cmp\tr2, r1\n"
    "    blt .Ljp_08035222\n"
    "    movs\tr3, #1\n"
    ".Ljp_08035222:\n"
    "    movs\tr0, #1\n"
    "    str\tr0, [sp, #144]\t@ 0x90\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #63\t@ 0x3f\n"
    "    ldrb\tr2, [r0, #0]\n"
    "    adds\tr1, r0, #0\n"
    "    cmp\tr2, #0\n"
    "    beq .Ljp_08035252\n"
    "    movs\tr4, #0\n"
    "    str\tr4, [sp, #144]\t@ 0x90\n"
    "    cmp\tr3, #0\n"
    "    beq .Ljp_08035244\n"
    "    strb\tr4, [r1, #0]\n"
    "    b .Ljp_08035248\n"
    "    .align 2, 0\n"
    ".Ljp_08035240:\n"
    "    .word 0x000002EE\n"
    ".Ljp_08035244:\n"
    "    subs\tr0, r2, #1\n"
    "    strb\tr0, [r1, #0]\n"
    ".Ljp_08035248:\n"
    "    ldrb\tr0, [r1, #0]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_08035252\n"
    "    movs\tr1, #1\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    ".Ljp_08035252:\n"
    "    cmp\tr3, #0\n"
    "    bne .Ljp_08035334\n"
    "    cmp\tr7, #0\n"
    "    beq .Ljp_08035334\n"
    "    ldr\tr0, [r5, #0]\n"
    "    ldr\tr2, [r0, #64]\t@ 0x40\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr1, #0\n"
    "    bl _call_via_r2\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_08035334\n"
    "    ldrh\tr0, [r4, #4]\n"
    "    ldrh\tr2, [r6, #4]\n"
    "    cmp\tr0, r2\n"
    "    bne .Ljp_08035334\n"
    "    ldr\tr1, [r6, #20]\n"
    "    add\tr0, sp, #16\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r6, #0\n"
    "    bl _call_via_r2\n"
    "    ldr\tr0, [sp, #16]\n"
    "    ldr\tr1, [sp, #20]\n"
    "    str\tr0, [sp, #24]\n"
    "    str\tr1, [sp, #28]\n"
    "    add\tr5, sp, #24\n"
    "    ldr\tr1, [r4, #20]\n"
    "    add\tr0, sp, #32\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r4, #0\n"
    "    bl _call_via_r2\n"
    "    ldr\tr0, [sp, #32]\n"
    "    ldr\tr1, [sp, #36]\t@ 0x24\n"
    "    str\tr0, [sp, #40]\t@ 0x28\n"
    "    str\tr1, [sp, #44]\t@ 0x2c\n"
    "    add\tr4, sp, #40\t@ 0x28\n"
    "    mov\tr3, r8\n"
    "    cmp\tr3, #0\n"
    "    beq .Ljp_080352AC\n"
    "    adds\tr2, r7, #0\n"
    "    movs\tr7, #0\n"
    "    b .Ljp_080352AE\n"
    ".Ljp_080352AC:\n"
    "    movs\tr2, #0\n"
    ".Ljp_080352AE:\n"
    "    mov\tr9, r7\n"
    "    movs\tr1, #0\n"
    "    ldrsh\tr0, [r5, r1]\n"
    "    mov\tip, r0\n"
    "    movs\tr3, #4\n"
    "    ldrsh\tr1, [r4, r3]\n"
    "    subs\tr1, r0, r1\n"
    "    movs\tr7, #0\n"
    "    ldrsh\tr0, [r4, r7]\n"
    "    movs\tr7, #4\n"
    "    ldrsh\tr3, [r5, r7]\n"
    "    mov\tr8, r3\n"
    "    subs\tr0, r0, r3\n"
    "    ands\tr1, r0\n"
    "    movs\tr0, #2\n"
    "    ldrsh\tr7, [r5, r0]\n"
    "    movs\tr3, #6\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    subs\tr0, r7, r0\n"
    "    ands\tr1, r0\n"
    "    movs\tr3, #2\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    movs\tr3, #6\n"
    "    ldrsh\tr5, [r5, r3]\n"
    "    subs\tr0, r0, r5\n"
    "    ands\tr1, r0\n"
    "    cmp\tr1, #0\n"
    "    blt .Ljp_08035334\n"
    "    add\tr3, sp, #48\t@ 0x30\n"
    "    mov\tr1, ip\n"
    "    adds\tr0, r2, r1\n"
    "    strh\tr0, [r3, #0]\n"
    "    mov\tr1, r9\n"
    "    adds\tr0, r1, r7\n"
    "    strh\tr0, [r3, #2]\n"
    "    mov\tr7, r8\n"
    "    adds\tr0, r2, r7\n"
    "    strh\tr0, [r3, #4]\n"
    "    adds\tr0, r1, r5\n"
    "    strh\tr0, [r3, #6]\n"
    "    movs\tr0, #0\n"
    "    ldrsh\tr1, [r3, r0]\n"
    "    movs\tr2, #4\n"
    "    ldrsh\tr0, [r4, r2]\n"
    "    subs\tr1, r1, r0\n"
    "    movs\tr5, #0\n"
    "    ldrsh\tr0, [r4, r5]\n"
    "    movs\tr7, #4\n"
    "    ldrsh\tr2, [r3, r7]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    movs\tr2, #2\n"
    "    ldrsh\tr0, [r3, r2]\n"
    "    movs\tr5, #6\n"
    "    ldrsh\tr2, [r4, r5]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    movs\tr7, #2\n"
    "    ldrsh\tr0, [r4, r7]\n"
    "    movs\tr4, #6\n"
    "    ldrsh\tr2, [r3, r4]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    cmp\tr1, #0\n"
    "    bge .Ljp_08035334\n"
    "    movs\tr5, #0\n"
    "    str\tr5, [sp, #144]\t@ 0x90\n"
    ".Ljp_08035334:\n"
    "    ldr\tr7, [sp, #144]\t@ 0x90\n"
    "    cmp\tr7, #0\n"
    "    beq .Ljp_080353C2\n"
    "    ldr\tr1, [sp, #124]\t@ 0x7c\n"
    "    movs\tr2, #2\n"
    "    ldrsh\tr0, [r1, r2]\n"
    "    ldr\tr3, [sp, #132]\t@ 0x84\n"
    "    cmp\tr3, r0\n"
    "    beq .Ljp_08035364\n"
    "    ldr\tr4, [sp, #140]\t@ 0x8c\n"
    "    cmp\tr4, r0\n"
    "    beq .Ljp_08035364\n"
    "    movs\tr1, #0\n"
    "    cmp\tr0, r3\n"
    "    bge .Ljp_08035354\n"
    "    movs\tr1, #1\n"
    ".Ljp_08035354:\n"
    "    ldr\tr5, [sp, #140]\t@ 0x8c\n"
    "    cmp\tr0, r5\n"
    "    bge .Ljp_08035360\n"
    "    cmp\tr1, #0\n"
    "    beq .Ljp_08035364\n"
    "    b .Ljp_080353AA\n"
    ".Ljp_08035360:\n"
    "    cmp\tr1, #0\n"
    "    beq .Ljp_080353AA\n"
    ".Ljp_08035364:\n"
    "    lsls\tr0, r0, #16\n"
    "    mov\tr7, sl\n"
    "    str\tr0, [r7, #0]\n"
    "    movs\tr1, #0\n"
    "    ldr\tr0, [sp, #128]\t@ 0x80\n"
    "    str\tr1, [r0, #0]\n"
    "    ldr\tr2, [sp, #180]\t@ 0xb4\n"
    "    ldrb\tr0, [r2, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r2, #0]\n"
    "    lsls\tr0, r0, #24\n"
    "    lsrs\tr0, r0, #24\n"
    "    ldr\tr3, [sp, #116]\t@ 0x74\n"
    "    ldrh\tr3, [r3, #4]\n"
    "    cmp\tr0, r3\n"
    "    bcs .Ljp_0803538A\n"
    "    movs\tr4, #1\n"
    "    str\tr4, [sp, #120]\t@ 0x78\n"
    "    b .Ljp_080353B0\n"
    ".Ljp_0803538A:\n"
    "    ldr\tr5, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r5, #0]\n"
    "    adds\tr0, #1\n"
    "    ldr\tr7, [sp, #112]\t@ 0x70\n"
    "    ldrh\tr7, [r7, #0]\n"
    "    cmp\tr0, r7\n"
    "    blt .Ljp_0803539A\n"
    "    b .Ljp_0803568C\n"
    ".Ljp_0803539A:\n"
    "    ldr\tr0, [sp, #180]\t@ 0xb4\n"
    "    strb\tr1, [r0, #0]\n"
    "    ldrb\tr0, [r5, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r5, #0]\n"
    "    movs\tr1, #2\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    "    b .Ljp_080353B0\n"
    ".Ljp_080353AA:\n"
    "    ldr\tr2, [sp, #136]\t@ 0x88\n"
    "    mov\tr3, sl\n"
    "    str\tr2, [r3, #0]\n"
    ".Ljp_080353B0:\n"
    "    ldr\tr0, [sp, #0]\n"
    "    str\tr0, [r6, #8]\n"
    "    ldr\tr0, [sp, #8]\n"
    "    str\tr0, [r6, #12]\n"
    "    ldr\tr0, [sp, #4]\n"
    "    str\tr0, [r6, #24]\n"
    "    ldr\tr0, [sp, #12]\n"
    "    str\tr0, [r6, #28]\n"
    "    b .Ljp_0803567A\n"
    ".Ljp_080353C2:\n"
    "    ldr\tr4, [sp, #184]\t@ 0xb8\n"
    "    ldrh\tr0, [r4, #0]\n"
    "    adds\tr0, #1\n"
    "    strh\tr0, [r4, #0]\n"
    "    b .Ljp_0803567A\n"
    ".Ljp_080353CC:\n"
    "    lsls\tr0, r2, #3\n"
    "    adds\tr3, r3, r0\n"
    "    str\tr3, [sp, #148]\t@ 0x94\n"
    "    movs\tr2, #0\n"
    "    ldrb\tr0, [r3, #6]\n"
    "    lsls\tr0, r0, #29\n"
    "    cmp\tr0, #0\n"
    "    blt .Ljp_080353DE\n"
    "    movs\tr2, #1\n"
    ".Ljp_080353DE:\n"
    "    mov\tr8, r2\n"
    "    movs\tr2, #0\n"
    "    ldr\tr3, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r3, #0]\n"
    "    adds\tr0, #1\n"
    "    ldr\tr4, [sp, #112]\t@ 0x70\n"
    "    ldrh\tr4, [r4, #0]\n"
    "    cmp\tr0, r4\n"
    "    bge .Ljp_080353F8\n"
    "    ldrh\tr7, [r7, #8]\n"
    "    cmp\tr1, r7\n"
    "    bcc .Ljp_080353F8\n"
    "    movs\tr2, #1\n"
    ".Ljp_080353F8:\n"
    "    mov\tsl, r2\n"
    "    cmp\tr2, #0\n"
    "    beq .Ljp_08035416\n"
    "    ldrh\tr4, [r6, #4]\n"
    "    ldr\tr0, [r5, #0]\n"
    "    ldr\tr1, [r0, #20]\n"
    "    adds\tr0, r5, #0\n"
    "    bl _call_via_r1\n"
    "    cmp\tr4, r0\n"
    "    beq .Ljp_08035416\n"
    "    movs\tr0, #0\n"
    "    ldr\tr5, [sp, #180]\t@ 0xb4\n"
    "    strb\tr0, [r5, #0]\n"
    "    b .Ljp_08035640\n"
    ".Ljp_08035416:\n"
    "    adds\tr1, r6, #0\n"
    "    adds\tr1, #64\t@ 0x40\n"
    "    ldrh\tr0, [r1, #0]\n"
    "    str\tr1, [sp, #184]\t@ 0xb8\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_08035424\n"
    "    b .Ljp_08035608\n"
    ".Ljp_08035424:\n"
    "    ldr\tr0, [r6, #8]\n"
    "    str\tr0, [sp, #56]\t@ 0x38\n"
    "    ldr\tr0, [r6, #12]\n"
    "    str\tr0, [sp, #64]\t@ 0x40\n"
    "    ldr\tr0, [r6, #24]\n"
    "    str\tr0, [sp, #60]\t@ 0x3c\n"
    "    ldr\tr0, [r6, #28]\n"
    "    str\tr0, [sp, #68]\t@ 0x44\n"
    "    mov\tr1, r8\n"
    "    cmp\tr1, #0\n"
    "    beq .Ljp_08035448\n"
    "    mov\tr2, sp\n"
    "    adds\tr2, #56\t@ 0x38\n"
    "    str\tr2, [sp, #152]\t@ 0x98\n"
    "    mov\tr3, sp\n"
    "    adds\tr3, #60\t@ 0x3c\n"
    "    str\tr3, [sp, #156]\t@ 0x9c\n"
    "    b .Ljp_08035454\n"
    ".Ljp_08035448:\n"
    "    mov\tr4, sp\n"
    "    adds\tr4, #64\t@ 0x40\n"
    "    str\tr4, [sp, #152]\t@ 0x98\n"
    "    mov\tr7, sp\n"
    "    adds\tr7, #68\t@ 0x44\n"
    "    str\tr7, [sp, #156]\t@ 0x9c\n"
    ".Ljp_08035454:\n"
    "    ldr\tr1, [sp, #152]\t@ 0x98\n"
    "    ldr\tr0, [r1, #0]\n"
    "    asrs\tr2, r0, #16\n"
    "    str\tr2, [sp, #160]\t@ 0xa0\n"
    "    ldr\tr3, [sp, #156]\t@ 0x9c\n"
    "    ldr\tr1, [r3, #0]\n"
    "    adds\tr0, r0, r1\n"
    "    str\tr0, [sp, #164]\t@ 0xa4\n"
    "    asrs\tr4, r0, #16\n"
    "    str\tr4, [sp, #168]\t@ 0xa8\n"
    "    subs\tr7, r4, r2\n"
    "    movs\tr0, #1\n"
    "    str\tr0, [sp, #172]\t@ 0xac\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #63\t@ 0x3f\n"
    "    ldrb\tr2, [r0, #0]\n"
    "    adds\tr1, r0, #0\n"
    "    cmp\tr2, #0\n"
    "    beq .Ljp_08035496\n"
    "    movs\tr3, #0\n"
    "    str\tr3, [sp, #172]\t@ 0xac\n"
    "    mov\tr4, sl\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_08035488\n"
    "    strb\tr3, [r1, #0]\n"
    "    b .Ljp_0803548C\n"
    ".Ljp_08035488:\n"
    "    subs\tr0, r2, #1\n"
    "    strb\tr0, [r1, #0]\n"
    ".Ljp_0803548C:\n"
    "    ldrb\tr0, [r1, #0]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_08035496\n"
    "    movs\tr1, #1\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    ".Ljp_08035496:\n"
    "    mov\tr2, sl\n"
    "    cmp\tr2, #0\n"
    "    bne .Ljp_0803557C\n"
    "    cmp\tr7, #0\n"
    "    beq .Ljp_0803557C\n"
    "    ldr\tr0, [r5, #0]\n"
    "    ldr\tr2, [r0, #64]\t@ 0x40\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr1, #0\n"
    "    bl _call_via_r2\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, #0\n"
    "    beq .Ljp_0803557C\n"
    "    ldrh\tr0, [r4, #4]\n"
    "    ldrh\tr3, [r6, #4]\n"
    "    cmp\tr0, r3\n"
    "    bne .Ljp_0803557C\n"
    "    ldr\tr1, [r6, #20]\n"
    "    add\tr0, sp, #72\t@ 0x48\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r6, #0\n"
    "    bl _call_via_r2\n"
    "    ldr\tr0, [sp, #72]\t@ 0x48\n"
    "    ldr\tr1, [sp, #76]\t@ 0x4c\n"
    "    str\tr0, [sp, #80]\t@ 0x50\n"
    "    str\tr1, [sp, #84]\t@ 0x54\n"
    "    add\tr5, sp, #80\t@ 0x50\n"
    "    ldr\tr1, [r4, #20]\n"
    "    add\tr0, sp, #88\t@ 0x58\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r4, #0\n"
    "    bl _call_via_r2\n"
    "    ldr\tr0, [sp, #88]\t@ 0x58\n"
    "    ldr\tr1, [sp, #92]\t@ 0x5c\n"
    "    str\tr0, [sp, #96]\t@ 0x60\n"
    "    str\tr1, [sp, #100]\t@ 0x64\n"
    "    add\tr4, sp, #96\t@ 0x60\n"
    "    mov\tr0, r8\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_080354F4\n"
    "    adds\tr2, r7, #0\n"
    "    movs\tr1, #0\n"
    "    mov\tr9, r1\n"
    "    b .Ljp_080354F8\n"
    ".Ljp_080354F4:\n"
    "    movs\tr2, #0\n"
    "    mov\tr9, r7\n"
    ".Ljp_080354F8:\n"
    "    movs\tr7, #0\n"
    "    ldrsh\tr3, [r5, r7]\n"
    "    mov\tr8, r3\n"
    "    movs\tr0, #4\n"
    "    ldrsh\tr1, [r4, r0]\n"
    "    subs\tr1, r3, r1\n"
    "    movs\tr3, #0\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    movs\tr3, #4\n"
    "    ldrsh\tr7, [r5, r3]\n"
    "    mov\tip, r7\n"
    "    subs\tr0, r0, r7\n"
    "    ands\tr1, r0\n"
    "    movs\tr0, #2\n"
    "    ldrsh\tr7, [r5, r0]\n"
    "    movs\tr3, #6\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    subs\tr0, r7, r0\n"
    "    ands\tr1, r0\n"
    "    movs\tr3, #2\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    movs\tr3, #6\n"
    "    ldrsh\tr5, [r5, r3]\n"
    "    subs\tr0, r0, r5\n"
    "    ands\tr1, r0\n"
    "    cmp\tr1, #0\n"
    "    blt .Ljp_0803557C\n"
    "    add\tr3, sp, #104\t@ 0x68\n"
    "    mov\tr1, r8\n"
    "    adds\tr0, r2, r1\n"
    "    strh\tr0, [r3, #0]\n"
    "    mov\tr1, r9\n"
    "    adds\tr0, r1, r7\n"
    "    strh\tr0, [r3, #2]\n"
    "    mov\tr7, ip\n"
    "    adds\tr0, r2, r7\n"
    "    strh\tr0, [r3, #4]\n"
    "    adds\tr0, r1, r5\n"
    "    strh\tr0, [r3, #6]\n"
    "    movs\tr0, #0\n"
    "    ldrsh\tr1, [r3, r0]\n"
    "    movs\tr2, #4\n"
    "    ldrsh\tr0, [r4, r2]\n"
    "    subs\tr1, r1, r0\n"
    "    movs\tr5, #0\n"
    "    ldrsh\tr0, [r4, r5]\n"
    "    movs\tr7, #4\n"
    "    ldrsh\tr2, [r3, r7]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    movs\tr2, #2\n"
    "    ldrsh\tr0, [r3, r2]\n"
    "    movs\tr5, #6\n"
    "    ldrsh\tr2, [r4, r5]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    movs\tr7, #2\n"
    "    ldrsh\tr0, [r4, r7]\n"
    "    movs\tr4, #6\n"
    "    ldrsh\tr2, [r3, r4]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    cmp\tr1, #0\n"
    "    bge .Ljp_0803557C\n"
    "    movs\tr5, #0\n"
    "    str\tr5, [sp, #172]\t@ 0xac\n"
    ".Ljp_0803557C:\n"
    "    ldr\tr7, [sp, #172]\t@ 0xac\n"
    "    cmp\tr7, #0\n"
    "    beq .Ljp_0803567A\n"
    "    ldr\tr0, [sp, #148]\t@ 0x94\n"
    "    movs\tr1, #0\n"
    "    ldrsh\tr2, [r0, r1]\n"
    "    ldr\tr3, [sp, #168]\t@ 0xa8\n"
    "    cmp\tr3, r2\n"
    "    beq .Ljp_0803559A\n"
    "    ldr\tr4, [sp, #160]\t@ 0xa0\n"
    "    subs\tr0, r2, r4\n"
    "    subs\tr1, r2, r3\n"
    "    eors\tr0, r1\n"
    "    cmp\tr0, #0\n"
    "    bge .Ljp_080355F0\n"
    ".Ljp_0803559A:\n"
    "    lsls\tr0, r2, #16\n"
    "    ldr\tr5, [sp, #152]\t@ 0x98\n"
    "    str\tr0, [r5, #0]\n"
    "    movs\tr1, #0\n"
    "    ldr\tr7, [sp, #156]\t@ 0x9c\n"
    "    str\tr1, [r7, #0]\n"
    "    mov\tr0, sl\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_080355B4\n"
    "    ldr\tr2, [sp, #148]\t@ 0x94\n"
    "    ldrh\tr0, [r2, #4]\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_080355E4\n"
    ".Ljp_080355B4:\n"
    "    ldr\tr3, [sp, #180]\t@ 0xb4\n"
    "    ldrb\tr0, [r3, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r3, #0]\n"
    "    lsls\tr0, r0, #24\n"
    "    lsrs\tr0, r0, #24\n"
    "    ldr\tr4, [sp, #116]\t@ 0x74\n"
    "    ldrh\tr4, [r4, #4]\n"
    "    cmp\tr0, r4\n"
    "    bcc .Ljp_080355DE\n"
    "    strb\tr1, [r3, #0]\n"
    "    mov\tr5, sl\n"
    "    cmp\tr5, #0\n"
    "    beq .Ljp_080355D8\n"
    "    ldr\tr7, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r7, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r7, #0]\n"
    ".Ljp_080355D8:\n"
    "    movs\tr0, #2\n"
    "    str\tr0, [sp, #120]\t@ 0x78\n"
    "    b .Ljp_080355F6\n"
    ".Ljp_080355DE:\n"
    "    movs\tr1, #1\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    "    b .Ljp_080355F6\n"
    ".Ljp_080355E4:\n"
    "    movs\tr0, #1\n"
    "    ldr\tr2, [sp, #184]\t@ 0xb8\n"
    "    strh\tr0, [r2, #0]\n"
    "    movs\tr3, #1\n"
    "    str\tr3, [sp, #120]\t@ 0x78\n"
    "    b .Ljp_080355F6\n"
    ".Ljp_080355F0:\n"
    "    ldr\tr4, [sp, #164]\t@ 0xa4\n"
    "    ldr\tr5, [sp, #152]\t@ 0x98\n"
    "    str\tr4, [r5, #0]\n"
    ".Ljp_080355F6:\n"
    "    ldr\tr0, [sp, #56]\t@ 0x38\n"
    "    str\tr0, [r6, #8]\n"
    "    ldr\tr0, [sp, #64]\t@ 0x40\n"
    "    str\tr0, [r6, #12]\n"
    "    ldr\tr0, [sp, #60]\t@ 0x3c\n"
    "    str\tr0, [r6, #24]\n"
    "    ldr\tr0, [sp, #68]\t@ 0x44\n"
    "    str\tr0, [r6, #28]\n"
    "    b .Ljp_0803567A\n"
    ".Ljp_08035608:\n"
    "    mov\tr7, sl\n"
    "    cmp\tr7, #0\n"
    "    bne .Ljp_0803561E\n"
    "    adds\tr0, #1\n"
    "    strh\tr0, [r1, #0]\n"
    "    lsls\tr0, r0, #16\n"
    "    lsrs\tr0, r0, #16\n"
    "    ldr\tr2, [sp, #148]\t@ 0x94\n"
    "    ldrh\tr2, [r2, #4]\n"
    "    cmp\tr0, r2\n"
    "    bls .Ljp_0803567A\n"
    ".Ljp_0803561E:\n"
    "    movs\tr0, #0\n"
    "    strh\tr0, [r1, #0]\n"
    "    ldr\tr3, [sp, #180]\t@ 0xb4\n"
    "    ldrb\tr0, [r3, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r3, #0]\n"
    "    lsls\tr0, r0, #24\n"
    "    lsrs\tr0, r0, #24\n"
    "    ldr\tr4, [sp, #116]\t@ 0x74\n"
    "    ldrh\tr4, [r4, #4]\n"
    "    cmp\tr0, r4\n"
    "    bcc .Ljp_0803564E\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r3, #0]\n"
    "    mov\tr5, sl\n"
    "    cmp\tr5, #0\n"
    "    beq .Ljp_08035648\n"
    ".Ljp_08035640:\n"
    "    ldr\tr7, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r7, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r7, #0]\n"
    ".Ljp_08035648:\n"
    "    movs\tr0, #2\n"
    "    str\tr0, [sp, #120]\t@ 0x78\n"
    "    b .Ljp_08035680\n"
    ".Ljp_0803564E:\n"
    "    movs\tr1, #1\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    "    b .Ljp_08035680\n"
    ".Ljp_08035654:\n"
    "    ldr\tr2, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r2, #0]\n"
    "    adds\tr0, #1\n"
    "    ldr\tr3, [sp, #112]\t@ 0x70\n"
    "    ldrh\tr3, [r3, #0]\n"
    "    cmp\tr0, r3\n"
    "    bge .Ljp_0803567A\n"
    "    ldrh\tr7, [r7, #8]\n"
    "    cmp\tr1, r7\n"
    "    bcc .Ljp_0803567A\n"
    "    adds\tr1, r6, #0\n"
    "    adds\tr1, #62\t@ 0x3e\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    "    ldrb\tr0, [r2, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r2, #0]\n"
    "    movs\tr4, #2\n"
    "    str\tr4, [sp, #120]\t@ 0x78\n"
    ".Ljp_0803567A:\n"
    "    ldr\tr5, [sp, #120]\t@ 0x78\n"
    "    cmp\tr5, #0\n"
    "    ble .Ljp_0803568C\n"
    ".Ljp_08035680:\n"
    "    ldr\tr0, [r6, #20]\n"
    "    ldr\tr2, [r0, #60]\t@ 0x3c\n"
    "    adds\tr0, r6, #0\n"
    "    ldr\tr1, [sp, #120]\t@ 0x78\n"
    "    bl _call_via_r2\n"
    ".Ljp_0803568C:\n"
    "    add\tsp, #188\t@ 0xbc\n"
    "    pop\t{r3, r4, r5}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    mov\tsl, r5\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r0}\n"
    "    bx\tr0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
#if defined(REGION_EU)
    "    .align 2, 0\n"
    "\n"
    "    .global func_08035380\n"
    "    .thumb_func\n"
    "func_08035380:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, sl\n"
    "    mov\tr6, r9\n"
    "    mov\tr5, r8\n"
    "    push\t{r5, r6, r7}\n"
    "    sub\tsp, #188\t@ 0xbc\n"
    "    adds\tr6, r0, #0\n"
    "    ldr\tr5, [r6, #0]\n"
    "    ldr\tr1, [r6, #56]\t@ 0x38\n"
    "    cmp\tr1, #0\n"
    "    bne .Leu_080353AC\n"
    "    b .Leu_0803590C\n"
    ".Leu_080353AC:\n"
    "    adds\tr0, #60\t@ 0x3c\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    ldr\tr1, [r1, #8]\n"
    "    lsls\tr0, r0, #2\n"
    "    adds\tr0, r0, r1\n"
    "    ldr\tr0, [r0, #0]\n"
    "    str\tr0, [sp, #112]\t@ 0x70\n"
    "    cmp\tr0, #0\n"
    "    bne .Leu_080353C0\n"
    "    b .Leu_0803590C\n"
    ".Leu_080353C0:\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #61\t@ 0x3d\n"
    "    ldrb\tr1, [r0, #0]\n"
    "    str\tr0, [sp, #176]\t@ 0xb0\n"
    "    ldr\tr0, [sp, #112]\t@ 0x70\n"
    "    ldrh\tr0, [r0, #0]\n"
    "    cmp\tr1, r0\n"
    "    bcc .Leu_080353D2\n"
    "    b .Leu_0803590C\n"
    ".Leu_080353D2:\n"
    "    lsls\tr1, r1, #3\n"
    "    ldr\tr2, [sp, #112]\t@ 0x70\n"
    "    ldr\tr0, [r2, #4]\n"
    "    adds\tr7, r0, r1\n"
    "    ldr\tr3, [r7, #4]\n"
    "    str\tr3, [sp, #116]\t@ 0x74\n"
    "    cmp\tr3, #0\n"
    "    bne .Leu_080353E4\n"
    "    b .Leu_0803590C\n"
    ".Leu_080353E4:\n"
    "    ldr\tr0, [r5, #0]\n"
    "    movs\tr4, #162\t@ 0xa2\n"
    "    lsls\tr4, r4, #1\n"
    "    adds\tr0, r0, r4\n"
    "    ldr\tr1, [r0, #0]\n"
    "    adds\tr0, r5, #0\n"
    "    bl _call_via_r1\n"
    "    ldrh\tr3, [r0, #10]\n"
    "    lsls\tr0, r3, #27\n"
    "    lsrs\tr0, r0, #27\n"
    "    subs\tr2, r0, #6\n"
    "    cmp\tr2, #0\n"
    "    bge .Leu_08035402\n"
    "    adds\tr2, #24\n"
    ".Leu_08035402:\n"
    "    lsls\tr1, r2, #4\n"
    "    subs\tr1, r1, r2\n"
    "    lsls\tr1, r1, #2\n"
    "    lsls\tr0, r3, #21\n"
    "    lsrs\tr0, r0, #26\n"
    "    adds\tr1, r1, r0\n"
    "    movs\tr0, #0\n"
    "    str\tr0, [sp, #120]\t@ 0x78\n"
    "    ldr\tr2, [sp, #116]\t@ 0x74\n"
    "    ldr\tr3, [r2, #0]\n"
    "    cmp\tr3, #0\n"
    "    bne .Leu_0803541C\n"
    "    b .Leu_080358D4\n"
    ".Leu_0803541C:\n"
    "    ldrh\tr4, [r2, #4]\n"
    "    cmp\tr4, #0\n"
    "    bne .Leu_08035424\n"
    "    b .Leu_080358D4\n"
    ".Leu_08035424:\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #62\t@ 0x3e\n"
    "    ldrb\tr2, [r0, #0]\n"
    "    str\tr0, [sp, #180]\t@ 0xb4\n"
    "    cmp\tr2, r4\n"
    "    bcc .Leu_08035432\n"
    "    b .Leu_0803590C\n"
    ".Leu_08035432:\n"
    "    ldr\tr4, [sp, #116]\t@ 0x74\n"
    "    ldrb\tr0, [r4, #11]\n"
    "    lsls\tr0, r0, #27\n"
    "    cmp\tr0, #0\n"
    "    bge .Leu_0803543E\n"
    "    b .Leu_0803564C\n"
    ".Leu_0803543E:\n"
    "    lsls\tr0, r2, #3\n"
    "    adds\tr3, r3, r0\n"
    "    str\tr3, [sp, #124]\t@ 0x7c\n"
    "    movs\tr1, #0\n"
    "    ldrb\tr0, [r3, #4]\n"
    "    lsls\tr0, r0, #31\n"
    "    cmp\tr0, #0\n"
    "    bne .Leu_08035450\n"
    "    movs\tr1, #1\n"
    ".Leu_08035450:\n"
    "    mov\tr8, r1\n"
    "    ldr\tr0, [r6, #8]\n"
    "    str\tr0, [sp, #0]\n"
    "    ldr\tr0, [r6, #12]\n"
    "    str\tr0, [sp, #8]\n"
    "    ldr\tr0, [r6, #24]\n"
    "    str\tr0, [sp, #4]\n"
    "    ldr\tr0, [r6, #28]\n"
    "    str\tr0, [sp, #12]\n"
    "    cmp\tr1, #0\n"
    "    beq .Leu_08035470\n"
    "    mov\tsl, sp\n"
    "    mov\tr7, sp\n"
    "    adds\tr7, #4\n"
    "    str\tr7, [sp, #128]\t@ 0x80\n"
    "    b .Leu_0803547A\n"
    ".Leu_08035470:\n"
    "    add\tr0, sp, #8\n"
    "    mov\tsl, r0\n"
    "    mov\tr1, sp\n"
    "    adds\tr1, #12\n"
    "    str\tr1, [sp, #128]\t@ 0x80\n"
    ".Leu_0803547A:\n"
    "    mov\tr2, sl\n"
    "    ldr\tr1, [r2, #0]\n"
    "    asrs\tr3, r1, #16\n"
    "    str\tr3, [sp, #132]\t@ 0x84\n"
    "    ldr\tr4, [sp, #128]\t@ 0x80\n"
    "    ldr\tr0, [r4, #0]\n"
    "    adds\tr1, r1, r0\n"
    "    str\tr1, [sp, #136]\t@ 0x88\n"
    "    asrs\tr7, r1, #16\n"
    "    str\tr7, [sp, #140]\t@ 0x8c\n"
    "    subs\tr7, r7, r3\n"
    "    movs\tr3, #0\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #64\t@ 0x40\n"
    "    ldrh\tr2, [r0, #0]\n"
    "    ldr r1, .Leu_080354C0\n"
    "    str\tr0, [sp, #184]\t@ 0xb8\n"
    "    cmp\tr2, r1\n"
    "    blt .Leu_080354A2\n"
    "    movs\tr3, #1\n"
    ".Leu_080354A2:\n"
    "    movs\tr0, #1\n"
    "    str\tr0, [sp, #144]\t@ 0x90\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #63\t@ 0x3f\n"
    "    ldrb\tr2, [r0, #0]\n"
    "    adds\tr1, r0, #0\n"
    "    cmp\tr2, #0\n"
    "    beq .Leu_080354D2\n"
    "    movs\tr4, #0\n"
    "    str\tr4, [sp, #144]\t@ 0x90\n"
    "    cmp\tr3, #0\n"
    "    beq .Leu_080354C4\n"
    "    strb\tr4, [r1, #0]\n"
    "    b .Leu_080354C8\n"
    "    .align 2, 0\n"
    ".Leu_080354C0:\n"
    "    .word 0x000002EE\n"
    ".Leu_080354C4:\n"
    "    subs\tr0, r2, #1\n"
    "    strb\tr0, [r1, #0]\n"
    ".Leu_080354C8:\n"
    "    ldrb\tr0, [r1, #0]\n"
    "    cmp\tr0, #0\n"
    "    bne .Leu_080354D2\n"
    "    movs\tr1, #1\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    ".Leu_080354D2:\n"
    "    cmp\tr3, #0\n"
    "    bne .Leu_080355B4\n"
    "    cmp\tr7, #0\n"
    "    beq .Leu_080355B4\n"
    "    ldr\tr0, [r5, #0]\n"
    "    ldr\tr2, [r0, #64]\t@ 0x40\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr1, #0\n"
    "    bl _call_via_r2\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, #0\n"
    "    beq .Leu_080355B4\n"
    "    ldrh\tr0, [r4, #4]\n"
    "    ldrh\tr2, [r6, #4]\n"
    "    cmp\tr0, r2\n"
    "    bne .Leu_080355B4\n"
    "    ldr\tr1, [r6, #20]\n"
    "    add\tr0, sp, #16\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r6, #0\n"
    "    bl _call_via_r2\n"
    "    ldr\tr0, [sp, #16]\n"
    "    ldr\tr1, [sp, #20]\n"
    "    str\tr0, [sp, #24]\n"
    "    str\tr1, [sp, #28]\n"
    "    add\tr5, sp, #24\n"
    "    ldr\tr1, [r4, #20]\n"
    "    add\tr0, sp, #32\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r4, #0\n"
    "    bl _call_via_r2\n"
    "    ldr\tr0, [sp, #32]\n"
    "    ldr\tr1, [sp, #36]\t@ 0x24\n"
    "    str\tr0, [sp, #40]\t@ 0x28\n"
    "    str\tr1, [sp, #44]\t@ 0x2c\n"
    "    add\tr4, sp, #40\t@ 0x28\n"
    "    mov\tr3, r8\n"
    "    cmp\tr3, #0\n"
    "    beq .Leu_0803552C\n"
    "    adds\tr2, r7, #0\n"
    "    movs\tr7, #0\n"
    "    b .Leu_0803552E\n"
    ".Leu_0803552C:\n"
    "    movs\tr2, #0\n"
    ".Leu_0803552E:\n"
    "    mov\tr9, r7\n"
    "    movs\tr1, #0\n"
    "    ldrsh\tr0, [r5, r1]\n"
    "    mov\tip, r0\n"
    "    movs\tr3, #4\n"
    "    ldrsh\tr1, [r4, r3]\n"
    "    subs\tr1, r0, r1\n"
    "    movs\tr7, #0\n"
    "    ldrsh\tr0, [r4, r7]\n"
    "    movs\tr7, #4\n"
    "    ldrsh\tr3, [r5, r7]\n"
    "    mov\tr8, r3\n"
    "    subs\tr0, r0, r3\n"
    "    ands\tr1, r0\n"
    "    movs\tr0, #2\n"
    "    ldrsh\tr7, [r5, r0]\n"
    "    movs\tr3, #6\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    subs\tr0, r7, r0\n"
    "    ands\tr1, r0\n"
    "    movs\tr3, #2\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    movs\tr3, #6\n"
    "    ldrsh\tr5, [r5, r3]\n"
    "    subs\tr0, r0, r5\n"
    "    ands\tr1, r0\n"
    "    cmp\tr1, #0\n"
    "    blt .Leu_080355B4\n"
    "    add\tr3, sp, #48\t@ 0x30\n"
    "    mov\tr1, ip\n"
    "    adds\tr0, r2, r1\n"
    "    strh\tr0, [r3, #0]\n"
    "    mov\tr1, r9\n"
    "    adds\tr0, r1, r7\n"
    "    strh\tr0, [r3, #2]\n"
    "    mov\tr7, r8\n"
    "    adds\tr0, r2, r7\n"
    "    strh\tr0, [r3, #4]\n"
    "    adds\tr0, r1, r5\n"
    "    strh\tr0, [r3, #6]\n"
    "    movs\tr0, #0\n"
    "    ldrsh\tr1, [r3, r0]\n"
    "    movs\tr2, #4\n"
    "    ldrsh\tr0, [r4, r2]\n"
    "    subs\tr1, r1, r0\n"
    "    movs\tr5, #0\n"
    "    ldrsh\tr0, [r4, r5]\n"
    "    movs\tr7, #4\n"
    "    ldrsh\tr2, [r3, r7]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    movs\tr2, #2\n"
    "    ldrsh\tr0, [r3, r2]\n"
    "    movs\tr5, #6\n"
    "    ldrsh\tr2, [r4, r5]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    movs\tr7, #2\n"
    "    ldrsh\tr0, [r4, r7]\n"
    "    movs\tr4, #6\n"
    "    ldrsh\tr2, [r3, r4]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    cmp\tr1, #0\n"
    "    bge .Leu_080355B4\n"
    "    movs\tr5, #0\n"
    "    str\tr5, [sp, #144]\t@ 0x90\n"
    ".Leu_080355B4:\n"
    "    ldr\tr7, [sp, #144]\t@ 0x90\n"
    "    cmp\tr7, #0\n"
    "    beq .Leu_08035642\n"
    "    ldr\tr1, [sp, #124]\t@ 0x7c\n"
    "    movs\tr2, #2\n"
    "    ldrsh\tr0, [r1, r2]\n"
    "    ldr\tr3, [sp, #132]\t@ 0x84\n"
    "    cmp\tr3, r0\n"
    "    beq .Leu_080355E4\n"
    "    ldr\tr4, [sp, #140]\t@ 0x8c\n"
    "    cmp\tr4, r0\n"
    "    beq .Leu_080355E4\n"
    "    movs\tr1, #0\n"
    "    cmp\tr0, r3\n"
    "    bge .Leu_080355D4\n"
    "    movs\tr1, #1\n"
    ".Leu_080355D4:\n"
    "    ldr\tr5, [sp, #140]\t@ 0x8c\n"
    "    cmp\tr0, r5\n"
    "    bge .Leu_080355E0\n"
    "    cmp\tr1, #0\n"
    "    beq .Leu_080355E4\n"
    "    b .Leu_0803562A\n"
    ".Leu_080355E0:\n"
    "    cmp\tr1, #0\n"
    "    beq .Leu_0803562A\n"
    ".Leu_080355E4:\n"
    "    lsls\tr0, r0, #16\n"
    "    mov\tr7, sl\n"
    "    str\tr0, [r7, #0]\n"
    "    movs\tr1, #0\n"
    "    ldr\tr0, [sp, #128]\t@ 0x80\n"
    "    str\tr1, [r0, #0]\n"
    "    ldr\tr2, [sp, #180]\t@ 0xb4\n"
    "    ldrb\tr0, [r2, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r2, #0]\n"
    "    lsls\tr0, r0, #24\n"
    "    lsrs\tr0, r0, #24\n"
    "    ldr\tr3, [sp, #116]\t@ 0x74\n"
    "    ldrh\tr3, [r3, #4]\n"
    "    cmp\tr0, r3\n"
    "    bcs .Leu_0803560A\n"
    "    movs\tr4, #1\n"
    "    str\tr4, [sp, #120]\t@ 0x78\n"
    "    b .Leu_08035630\n"
    ".Leu_0803560A:\n"
    "    ldr\tr5, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r5, #0]\n"
    "    adds\tr0, #1\n"
    "    ldr\tr7, [sp, #112]\t@ 0x70\n"
    "    ldrh\tr7, [r7, #0]\n"
    "    cmp\tr0, r7\n"
    "    blt .Leu_0803561A\n"
    "    b .Leu_0803590C\n"
    ".Leu_0803561A:\n"
    "    ldr\tr0, [sp, #180]\t@ 0xb4\n"
    "    strb\tr1, [r0, #0]\n"
    "    ldrb\tr0, [r5, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r5, #0]\n"
    "    movs\tr1, #2\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    "    b .Leu_08035630\n"
    ".Leu_0803562A:\n"
    "    ldr\tr2, [sp, #136]\t@ 0x88\n"
    "    mov\tr3, sl\n"
    "    str\tr2, [r3, #0]\n"
    ".Leu_08035630:\n"
    "    ldr\tr0, [sp, #0]\n"
    "    str\tr0, [r6, #8]\n"
    "    ldr\tr0, [sp, #8]\n"
    "    str\tr0, [r6, #12]\n"
    "    ldr\tr0, [sp, #4]\n"
    "    str\tr0, [r6, #24]\n"
    "    ldr\tr0, [sp, #12]\n"
    "    str\tr0, [r6, #28]\n"
    "    b .Leu_080358FA\n"
    ".Leu_08035642:\n"
    "    ldr\tr4, [sp, #184]\t@ 0xb8\n"
    "    ldrh\tr0, [r4, #0]\n"
    "    adds\tr0, #1\n"
    "    strh\tr0, [r4, #0]\n"
    "    b .Leu_080358FA\n"
    ".Leu_0803564C:\n"
    "    lsls\tr0, r2, #3\n"
    "    adds\tr3, r3, r0\n"
    "    str\tr3, [sp, #148]\t@ 0x94\n"
    "    movs\tr2, #0\n"
    "    ldrb\tr0, [r3, #6]\n"
    "    lsls\tr0, r0, #29\n"
    "    cmp\tr0, #0\n"
    "    blt .Leu_0803565E\n"
    "    movs\tr2, #1\n"
    ".Leu_0803565E:\n"
    "    mov\tr8, r2\n"
    "    movs\tr2, #0\n"
    "    ldr\tr3, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r3, #0]\n"
    "    adds\tr0, #1\n"
    "    ldr\tr4, [sp, #112]\t@ 0x70\n"
    "    ldrh\tr4, [r4, #0]\n"
    "    cmp\tr0, r4\n"
    "    bge .Leu_08035678\n"
    "    ldrh\tr7, [r7, #8]\n"
    "    cmp\tr1, r7\n"
    "    bcc .Leu_08035678\n"
    "    movs\tr2, #1\n"
    ".Leu_08035678:\n"
    "    mov\tsl, r2\n"
    "    cmp\tr2, #0\n"
    "    beq .Leu_08035696\n"
    "    ldrh\tr4, [r6, #4]\n"
    "    ldr\tr0, [r5, #0]\n"
    "    ldr\tr1, [r0, #20]\n"
    "    adds\tr0, r5, #0\n"
    "    bl _call_via_r1\n"
    "    cmp\tr4, r0\n"
    "    beq .Leu_08035696\n"
    "    movs\tr0, #0\n"
    "    ldr\tr5, [sp, #180]\t@ 0xb4\n"
    "    strb\tr0, [r5, #0]\n"
    "    b .Leu_080358C0\n"
    ".Leu_08035696:\n"
    "    adds\tr1, r6, #0\n"
    "    adds\tr1, #64\t@ 0x40\n"
    "    ldrh\tr0, [r1, #0]\n"
    "    str\tr1, [sp, #184]\t@ 0xb8\n"
    "    cmp\tr0, #0\n"
    "    beq .Leu_080356A4\n"
    "    b .Leu_08035888\n"
    ".Leu_080356A4:\n"
    "    ldr\tr0, [r6, #8]\n"
    "    str\tr0, [sp, #56]\t@ 0x38\n"
    "    ldr\tr0, [r6, #12]\n"
    "    str\tr0, [sp, #64]\t@ 0x40\n"
    "    ldr\tr0, [r6, #24]\n"
    "    str\tr0, [sp, #60]\t@ 0x3c\n"
    "    ldr\tr0, [r6, #28]\n"
    "    str\tr0, [sp, #68]\t@ 0x44\n"
    "    mov\tr1, r8\n"
    "    cmp\tr1, #0\n"
    "    beq .Leu_080356C8\n"
    "    mov\tr2, sp\n"
    "    adds\tr2, #56\t@ 0x38\n"
    "    str\tr2, [sp, #152]\t@ 0x98\n"
    "    mov\tr3, sp\n"
    "    adds\tr3, #60\t@ 0x3c\n"
    "    str\tr3, [sp, #156]\t@ 0x9c\n"
    "    b .Leu_080356D4\n"
    ".Leu_080356C8:\n"
    "    mov\tr4, sp\n"
    "    adds\tr4, #64\t@ 0x40\n"
    "    str\tr4, [sp, #152]\t@ 0x98\n"
    "    mov\tr7, sp\n"
    "    adds\tr7, #68\t@ 0x44\n"
    "    str\tr7, [sp, #156]\t@ 0x9c\n"
    ".Leu_080356D4:\n"
    "    ldr\tr1, [sp, #152]\t@ 0x98\n"
    "    ldr\tr0, [r1, #0]\n"
    "    asrs\tr2, r0, #16\n"
    "    str\tr2, [sp, #160]\t@ 0xa0\n"
    "    ldr\tr3, [sp, #156]\t@ 0x9c\n"
    "    ldr\tr1, [r3, #0]\n"
    "    adds\tr0, r0, r1\n"
    "    str\tr0, [sp, #164]\t@ 0xa4\n"
    "    asrs\tr4, r0, #16\n"
    "    str\tr4, [sp, #168]\t@ 0xa8\n"
    "    subs\tr7, r4, r2\n"
    "    movs\tr0, #1\n"
    "    str\tr0, [sp, #172]\t@ 0xac\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #63\t@ 0x3f\n"
    "    ldrb\tr2, [r0, #0]\n"
    "    adds\tr1, r0, #0\n"
    "    cmp\tr2, #0\n"
    "    beq .Leu_08035716\n"
    "    movs\tr3, #0\n"
    "    str\tr3, [sp, #172]\t@ 0xac\n"
    "    mov\tr4, sl\n"
    "    cmp\tr4, #0\n"
    "    beq .Leu_08035708\n"
    "    strb\tr3, [r1, #0]\n"
    "    b .Leu_0803570C\n"
    ".Leu_08035708:\n"
    "    subs\tr0, r2, #1\n"
    "    strb\tr0, [r1, #0]\n"
    ".Leu_0803570C:\n"
    "    ldrb\tr0, [r1, #0]\n"
    "    cmp\tr0, #0\n"
    "    bne .Leu_08035716\n"
    "    movs\tr1, #1\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    ".Leu_08035716:\n"
    "    mov\tr2, sl\n"
    "    cmp\tr2, #0\n"
    "    bne .Leu_080357FC\n"
    "    cmp\tr7, #0\n"
    "    beq .Leu_080357FC\n"
    "    ldr\tr0, [r5, #0]\n"
    "    ldr\tr2, [r0, #64]\t@ 0x40\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr1, #0\n"
    "    bl _call_via_r2\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, #0\n"
    "    beq .Leu_080357FC\n"
    "    ldrh\tr0, [r4, #4]\n"
    "    ldrh\tr3, [r6, #4]\n"
    "    cmp\tr0, r3\n"
    "    bne .Leu_080357FC\n"
    "    ldr\tr1, [r6, #20]\n"
    "    add\tr0, sp, #72\t@ 0x48\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r6, #0\n"
    "    bl _call_via_r2\n"
    "    ldr\tr0, [sp, #72]\t@ 0x48\n"
    "    ldr\tr1, [sp, #76]\t@ 0x4c\n"
    "    str\tr0, [sp, #80]\t@ 0x50\n"
    "    str\tr1, [sp, #84]\t@ 0x54\n"
    "    add\tr5, sp, #80\t@ 0x50\n"
    "    ldr\tr1, [r4, #20]\n"
    "    add\tr0, sp, #88\t@ 0x58\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r4, #0\n"
    "    bl _call_via_r2\n"
    "    ldr\tr0, [sp, #88]\t@ 0x58\n"
    "    ldr\tr1, [sp, #92]\t@ 0x5c\n"
    "    str\tr0, [sp, #96]\t@ 0x60\n"
    "    str\tr1, [sp, #100]\t@ 0x64\n"
    "    add\tr4, sp, #96\t@ 0x60\n"
    "    mov\tr0, r8\n"
    "    cmp\tr0, #0\n"
    "    beq .Leu_08035774\n"
    "    adds\tr2, r7, #0\n"
    "    movs\tr1, #0\n"
    "    mov\tr9, r1\n"
    "    b .Leu_08035778\n"
    ".Leu_08035774:\n"
    "    movs\tr2, #0\n"
    "    mov\tr9, r7\n"
    ".Leu_08035778:\n"
    "    movs\tr7, #0\n"
    "    ldrsh\tr3, [r5, r7]\n"
    "    mov\tr8, r3\n"
    "    movs\tr0, #4\n"
    "    ldrsh\tr1, [r4, r0]\n"
    "    subs\tr1, r3, r1\n"
    "    movs\tr3, #0\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    movs\tr3, #4\n"
    "    ldrsh\tr7, [r5, r3]\n"
    "    mov\tip, r7\n"
    "    subs\tr0, r0, r7\n"
    "    ands\tr1, r0\n"
    "    movs\tr0, #2\n"
    "    ldrsh\tr7, [r5, r0]\n"
    "    movs\tr3, #6\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    subs\tr0, r7, r0\n"
    "    ands\tr1, r0\n"
    "    movs\tr3, #2\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    movs\tr3, #6\n"
    "    ldrsh\tr5, [r5, r3]\n"
    "    subs\tr0, r0, r5\n"
    "    ands\tr1, r0\n"
    "    cmp\tr1, #0\n"
    "    blt .Leu_080357FC\n"
    "    add\tr3, sp, #104\t@ 0x68\n"
    "    mov\tr1, r8\n"
    "    adds\tr0, r2, r1\n"
    "    strh\tr0, [r3, #0]\n"
    "    mov\tr1, r9\n"
    "    adds\tr0, r1, r7\n"
    "    strh\tr0, [r3, #2]\n"
    "    mov\tr7, ip\n"
    "    adds\tr0, r2, r7\n"
    "    strh\tr0, [r3, #4]\n"
    "    adds\tr0, r1, r5\n"
    "    strh\tr0, [r3, #6]\n"
    "    movs\tr0, #0\n"
    "    ldrsh\tr1, [r3, r0]\n"
    "    movs\tr2, #4\n"
    "    ldrsh\tr0, [r4, r2]\n"
    "    subs\tr1, r1, r0\n"
    "    movs\tr5, #0\n"
    "    ldrsh\tr0, [r4, r5]\n"
    "    movs\tr7, #4\n"
    "    ldrsh\tr2, [r3, r7]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    movs\tr2, #2\n"
    "    ldrsh\tr0, [r3, r2]\n"
    "    movs\tr5, #6\n"
    "    ldrsh\tr2, [r4, r5]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    movs\tr7, #2\n"
    "    ldrsh\tr0, [r4, r7]\n"
    "    movs\tr4, #6\n"
    "    ldrsh\tr2, [r3, r4]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    cmp\tr1, #0\n"
    "    bge .Leu_080357FC\n"
    "    movs\tr5, #0\n"
    "    str\tr5, [sp, #172]\t@ 0xac\n"
    ".Leu_080357FC:\n"
    "    ldr\tr7, [sp, #172]\t@ 0xac\n"
    "    cmp\tr7, #0\n"
    "    beq .Leu_080358FA\n"
    "    ldr\tr0, [sp, #148]\t@ 0x94\n"
    "    movs\tr1, #0\n"
    "    ldrsh\tr2, [r0, r1]\n"
    "    ldr\tr3, [sp, #168]\t@ 0xa8\n"
    "    cmp\tr3, r2\n"
    "    beq .Leu_0803581A\n"
    "    ldr\tr4, [sp, #160]\t@ 0xa0\n"
    "    subs\tr0, r2, r4\n"
    "    subs\tr1, r2, r3\n"
    "    eors\tr0, r1\n"
    "    cmp\tr0, #0\n"
    "    bge .Leu_08035870\n"
    ".Leu_0803581A:\n"
    "    lsls\tr0, r2, #16\n"
    "    ldr\tr5, [sp, #152]\t@ 0x98\n"
    "    str\tr0, [r5, #0]\n"
    "    movs\tr1, #0\n"
    "    ldr\tr7, [sp, #156]\t@ 0x9c\n"
    "    str\tr1, [r7, #0]\n"
    "    mov\tr0, sl\n"
    "    cmp\tr0, #0\n"
    "    bne .Leu_08035834\n"
    "    ldr\tr2, [sp, #148]\t@ 0x94\n"
    "    ldrh\tr0, [r2, #4]\n"
    "    cmp\tr0, #0\n"
    "    bne .Leu_08035864\n"
    ".Leu_08035834:\n"
    "    ldr\tr3, [sp, #180]\t@ 0xb4\n"
    "    ldrb\tr0, [r3, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r3, #0]\n"
    "    lsls\tr0, r0, #24\n"
    "    lsrs\tr0, r0, #24\n"
    "    ldr\tr4, [sp, #116]\t@ 0x74\n"
    "    ldrh\tr4, [r4, #4]\n"
    "    cmp\tr0, r4\n"
    "    bcc .Leu_0803585E\n"
    "    strb\tr1, [r3, #0]\n"
    "    mov\tr5, sl\n"
    "    cmp\tr5, #0\n"
    "    beq .Leu_08035858\n"
    "    ldr\tr7, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r7, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r7, #0]\n"
    ".Leu_08035858:\n"
    "    movs\tr0, #2\n"
    "    str\tr0, [sp, #120]\t@ 0x78\n"
    "    b .Leu_08035876\n"
    ".Leu_0803585E:\n"
    "    movs\tr1, #1\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    "    b .Leu_08035876\n"
    ".Leu_08035864:\n"
    "    movs\tr0, #1\n"
    "    ldr\tr2, [sp, #184]\t@ 0xb8\n"
    "    strh\tr0, [r2, #0]\n"
    "    movs\tr3, #1\n"
    "    str\tr3, [sp, #120]\t@ 0x78\n"
    "    b .Leu_08035876\n"
    ".Leu_08035870:\n"
    "    ldr\tr4, [sp, #164]\t@ 0xa4\n"
    "    ldr\tr5, [sp, #152]\t@ 0x98\n"
    "    str\tr4, [r5, #0]\n"
    ".Leu_08035876:\n"
    "    ldr\tr0, [sp, #56]\t@ 0x38\n"
    "    str\tr0, [r6, #8]\n"
    "    ldr\tr0, [sp, #64]\t@ 0x40\n"
    "    str\tr0, [r6, #12]\n"
    "    ldr\tr0, [sp, #60]\t@ 0x3c\n"
    "    str\tr0, [r6, #24]\n"
    "    ldr\tr0, [sp, #68]\t@ 0x44\n"
    "    str\tr0, [r6, #28]\n"
    "    b .Leu_080358FA\n"
    ".Leu_08035888:\n"
    "    mov\tr7, sl\n"
    "    cmp\tr7, #0\n"
    "    bne .Leu_0803589E\n"
    "    adds\tr0, #1\n"
    "    strh\tr0, [r1, #0]\n"
    "    lsls\tr0, r0, #16\n"
    "    lsrs\tr0, r0, #16\n"
    "    ldr\tr2, [sp, #148]\t@ 0x94\n"
    "    ldrh\tr2, [r2, #4]\n"
    "    cmp\tr0, r2\n"
    "    bls .Leu_080358FA\n"
    ".Leu_0803589E:\n"
    "    movs\tr0, #0\n"
    "    strh\tr0, [r1, #0]\n"
    "    ldr\tr3, [sp, #180]\t@ 0xb4\n"
    "    ldrb\tr0, [r3, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r3, #0]\n"
    "    lsls\tr0, r0, #24\n"
    "    lsrs\tr0, r0, #24\n"
    "    ldr\tr4, [sp, #116]\t@ 0x74\n"
    "    ldrh\tr4, [r4, #4]\n"
    "    cmp\tr0, r4\n"
    "    bcc .Leu_080358CE\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r3, #0]\n"
    "    mov\tr5, sl\n"
    "    cmp\tr5, #0\n"
    "    beq .Leu_080358C8\n"
    ".Leu_080358C0:\n"
    "    ldr\tr7, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r7, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r7, #0]\n"
    ".Leu_080358C8:\n"
    "    movs\tr0, #2\n"
    "    str\tr0, [sp, #120]\t@ 0x78\n"
    "    b .Leu_08035900\n"
    ".Leu_080358CE:\n"
    "    movs\tr1, #1\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    "    b .Leu_08035900\n"
    ".Leu_080358D4:\n"
    "    ldr\tr2, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r2, #0]\n"
    "    adds\tr0, #1\n"
    "    ldr\tr3, [sp, #112]\t@ 0x70\n"
    "    ldrh\tr3, [r3, #0]\n"
    "    cmp\tr0, r3\n"
    "    bge .Leu_080358FA\n"
    "    ldrh\tr7, [r7, #8]\n"
    "    cmp\tr1, r7\n"
    "    bcc .Leu_080358FA\n"
    "    adds\tr1, r6, #0\n"
    "    adds\tr1, #62\t@ 0x3e\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    "    ldrb\tr0, [r2, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r2, #0]\n"
    "    movs\tr4, #2\n"
    "    str\tr4, [sp, #120]\t@ 0x78\n"
    ".Leu_080358FA:\n"
    "    ldr\tr5, [sp, #120]\t@ 0x78\n"
    "    cmp\tr5, #0\n"
    "    ble .Leu_0803590C\n"
    ".Leu_08035900:\n"
    "    ldr\tr0, [r6, #20]\n"
    "    ldr\tr2, [r0, #60]\t@ 0x3c\n"
    "    adds\tr0, r6, #0\n"
    "    ldr\tr1, [sp, #120]\t@ 0x78\n"
    "    bl _call_via_r2\n"
    ".Leu_0803590C:\n"
    "    add\tsp, #188\t@ 0xbc\n"
    "    pop\t{r3, r4, r5}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    mov\tsl, r5\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r0}\n"
    "    bx\tr0\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_DE)
#if defined(REGION_DE)
    "    .align 2, 0\n"
    "\n"
    "    .global func_08035380\n"
    "    .thumb_func\n"
    "func_08035380:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, sl\n"
    "    mov\tr6, r9\n"
    "    mov\tr5, r8\n"
    "    push\t{r5, r6, r7}\n"
    "    sub\tsp, #188\t@ 0xbc\n"
    "    adds\tr6, r0, #0\n"
    "    ldr\tr5, [r6, #0]\n"
    "    ldr\tr1, [r6, #56]\t@ 0x38\n"
    "    cmp\tr1, #0\n"
    "    bne .Lde_080352AC\n"
    "    b .Lde_0803580C\n"
    ".Lde_080352AC:\n"
    "    adds\tr0, #60\t@ 0x3c\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    ldr\tr1, [r1, #8]\n"
    "    lsls\tr0, r0, #2\n"
    "    adds\tr0, r0, r1\n"
    "    ldr\tr0, [r0, #0]\n"
    "    str\tr0, [sp, #112]\t@ 0x70\n"
    "    cmp\tr0, #0\n"
    "    bne .Lde_080352C0\n"
    "    b .Lde_0803580C\n"
    ".Lde_080352C0:\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #61\t@ 0x3d\n"
    "    ldrb\tr1, [r0, #0]\n"
    "    str\tr0, [sp, #176]\t@ 0xb0\n"
    "    ldr\tr0, [sp, #112]\t@ 0x70\n"
    "    ldrh\tr0, [r0, #0]\n"
    "    cmp\tr1, r0\n"
    "    bcc .Lde_080352D2\n"
    "    b .Lde_0803580C\n"
    ".Lde_080352D2:\n"
    "    lsls\tr1, r1, #3\n"
    "    ldr\tr2, [sp, #112]\t@ 0x70\n"
    "    ldr\tr0, [r2, #4]\n"
    "    adds\tr7, r0, r1\n"
    "    ldr\tr3, [r7, #4]\n"
    "    str\tr3, [sp, #116]\t@ 0x74\n"
    "    cmp\tr3, #0\n"
    "    bne .Lde_080352E4\n"
    "    b .Lde_0803580C\n"
    ".Lde_080352E4:\n"
    "    ldr\tr0, [r5, #0]\n"
    "    movs\tr4, #162\t@ 0xa2\n"
    "    lsls\tr4, r4, #1\n"
    "    adds\tr0, r0, r4\n"
    "    ldr\tr1, [r0, #0]\n"
    "    adds\tr0, r5, #0\n"
    "    bl _call_via_r1\n"
    "    ldrh\tr3, [r0, #10]\n"
    "    lsls\tr0, r3, #27\n"
    "    lsrs\tr0, r0, #27\n"
    "    subs\tr2, r0, #6\n"
    "    cmp\tr2, #0\n"
    "    bge .Lde_08035302\n"
    "    adds\tr2, #24\n"
    ".Lde_08035302:\n"
    "    lsls\tr1, r2, #4\n"
    "    subs\tr1, r1, r2\n"
    "    lsls\tr1, r1, #2\n"
    "    lsls\tr0, r3, #21\n"
    "    lsrs\tr0, r0, #26\n"
    "    adds\tr1, r1, r0\n"
    "    movs\tr0, #0\n"
    "    str\tr0, [sp, #120]\t@ 0x78\n"
    "    ldr\tr2, [sp, #116]\t@ 0x74\n"
    "    ldr\tr3, [r2, #0]\n"
    "    cmp\tr3, #0\n"
    "    bne .Lde_0803531C\n"
    "    b .Lde_080357D4\n"
    ".Lde_0803531C:\n"
    "    ldrh\tr4, [r2, #4]\n"
    "    cmp\tr4, #0\n"
    "    bne .Lde_08035324\n"
    "    b .Lde_080357D4\n"
    ".Lde_08035324:\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #62\t@ 0x3e\n"
    "    ldrb\tr2, [r0, #0]\n"
    "    str\tr0, [sp, #180]\t@ 0xb4\n"
    "    cmp\tr2, r4\n"
    "    bcc .Lde_08035332\n"
    "    b .Lde_0803580C\n"
    ".Lde_08035332:\n"
    "    ldr\tr4, [sp, #116]\t@ 0x74\n"
    "    ldrb\tr0, [r4, #11]\n"
    "    lsls\tr0, r0, #27\n"
    "    cmp\tr0, #0\n"
    "    bge .Lde_0803533E\n"
    "    b .Lde_0803554C\n"
    ".Lde_0803533E:\n"
    "    lsls\tr0, r2, #3\n"
    "    adds\tr3, r3, r0\n"
    "    str\tr3, [sp, #124]\t@ 0x7c\n"
    "    movs\tr1, #0\n"
    "    ldrb\tr0, [r3, #4]\n"
    "    lsls\tr0, r0, #31\n"
    "    cmp\tr0, #0\n"
    "    bne .Lde_08035350\n"
    "    movs\tr1, #1\n"
    ".Lde_08035350:\n"
    "    mov\tr8, r1\n"
    "    ldr\tr0, [r6, #8]\n"
    "    str\tr0, [sp, #0]\n"
    "    ldr\tr0, [r6, #12]\n"
    "    str\tr0, [sp, #8]\n"
    "    ldr\tr0, [r6, #24]\n"
    "    str\tr0, [sp, #4]\n"
    "    ldr\tr0, [r6, #28]\n"
    "    str\tr0, [sp, #12]\n"
    "    cmp\tr1, #0\n"
    "    beq .Lde_08035370\n"
    "    mov\tsl, sp\n"
    "    mov\tr7, sp\n"
    "    adds\tr7, #4\n"
    "    str\tr7, [sp, #128]\t@ 0x80\n"
    "    b .Lde_0803537A\n"
    ".Lde_08035370:\n"
    "    add\tr0, sp, #8\n"
    "    mov\tsl, r0\n"
    "    mov\tr1, sp\n"
    "    adds\tr1, #12\n"
    "    str\tr1, [sp, #128]\t@ 0x80\n"
    ".Lde_0803537A:\n"
    "    mov\tr2, sl\n"
    "    ldr\tr1, [r2, #0]\n"
    "    asrs\tr3, r1, #16\n"
    "    str\tr3, [sp, #132]\t@ 0x84\n"
    "    ldr\tr4, [sp, #128]\t@ 0x80\n"
    "    ldr\tr0, [r4, #0]\n"
    "    adds\tr1, r1, r0\n"
    "    str\tr1, [sp, #136]\t@ 0x88\n"
    "    asrs\tr7, r1, #16\n"
    "    str\tr7, [sp, #140]\t@ 0x8c\n"
    "    subs\tr7, r7, r3\n"
    "    movs\tr3, #0\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #64\t@ 0x40\n"
    "    ldrh\tr2, [r0, #0]\n"
    "    ldr r1, .Lde_080353C0\n"
    "    str\tr0, [sp, #184]\t@ 0xb8\n"
    "    cmp\tr2, r1\n"
    "    blt .Lde_080353A2\n"
    "    movs\tr3, #1\n"
    ".Lde_080353A2:\n"
    "    movs\tr0, #1\n"
    "    str\tr0, [sp, #144]\t@ 0x90\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #63\t@ 0x3f\n"
    "    ldrb\tr2, [r0, #0]\n"
    "    adds\tr1, r0, #0\n"
    "    cmp\tr2, #0\n"
    "    beq .Lde_080353D2\n"
    "    movs\tr4, #0\n"
    "    str\tr4, [sp, #144]\t@ 0x90\n"
    "    cmp\tr3, #0\n"
    "    beq .Lde_080353C4\n"
    "    strb\tr4, [r1, #0]\n"
    "    b .Lde_080353C8\n"
    "    .align 2, 0\n"
    ".Lde_080353C0:\n"
    "    .word 0x000002EE\n"
    ".Lde_080353C4:\n"
    "    subs\tr0, r2, #1\n"
    "    strb\tr0, [r1, #0]\n"
    ".Lde_080353C8:\n"
    "    ldrb\tr0, [r1, #0]\n"
    "    cmp\tr0, #0\n"
    "    bne .Lde_080353D2\n"
    "    movs\tr1, #1\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    ".Lde_080353D2:\n"
    "    cmp\tr3, #0\n"
    "    bne .Lde_080354B4\n"
    "    cmp\tr7, #0\n"
    "    beq .Lde_080354B4\n"
    "    ldr\tr0, [r5, #0]\n"
    "    ldr\tr2, [r0, #64]\t@ 0x40\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr1, #0\n"
    "    bl _call_via_r2\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, #0\n"
    "    beq .Lde_080354B4\n"
    "    ldrh\tr0, [r4, #4]\n"
    "    ldrh\tr2, [r6, #4]\n"
    "    cmp\tr0, r2\n"
    "    bne .Lde_080354B4\n"
    "    ldr\tr1, [r6, #20]\n"
    "    add\tr0, sp, #16\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r6, #0\n"
    "    bl _call_via_r2\n"
    "    ldr\tr0, [sp, #16]\n"
    "    ldr\tr1, [sp, #20]\n"
    "    str\tr0, [sp, #24]\n"
    "    str\tr1, [sp, #28]\n"
    "    add\tr5, sp, #24\n"
    "    ldr\tr1, [r4, #20]\n"
    "    add\tr0, sp, #32\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r4, #0\n"
    "    bl _call_via_r2\n"
    "    ldr\tr0, [sp, #32]\n"
    "    ldr\tr1, [sp, #36]\t@ 0x24\n"
    "    str\tr0, [sp, #40]\t@ 0x28\n"
    "    str\tr1, [sp, #44]\t@ 0x2c\n"
    "    add\tr4, sp, #40\t@ 0x28\n"
    "    mov\tr3, r8\n"
    "    cmp\tr3, #0\n"
    "    beq .Lde_0803542C\n"
    "    adds\tr2, r7, #0\n"
    "    movs\tr7, #0\n"
    "    b .Lde_0803542E\n"
    ".Lde_0803542C:\n"
    "    movs\tr2, #0\n"
    ".Lde_0803542E:\n"
    "    mov\tr9, r7\n"
    "    movs\tr1, #0\n"
    "    ldrsh\tr0, [r5, r1]\n"
    "    mov\tip, r0\n"
    "    movs\tr3, #4\n"
    "    ldrsh\tr1, [r4, r3]\n"
    "    subs\tr1, r0, r1\n"
    "    movs\tr7, #0\n"
    "    ldrsh\tr0, [r4, r7]\n"
    "    movs\tr7, #4\n"
    "    ldrsh\tr3, [r5, r7]\n"
    "    mov\tr8, r3\n"
    "    subs\tr0, r0, r3\n"
    "    ands\tr1, r0\n"
    "    movs\tr0, #2\n"
    "    ldrsh\tr7, [r5, r0]\n"
    "    movs\tr3, #6\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    subs\tr0, r7, r0\n"
    "    ands\tr1, r0\n"
    "    movs\tr3, #2\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    movs\tr3, #6\n"
    "    ldrsh\tr5, [r5, r3]\n"
    "    subs\tr0, r0, r5\n"
    "    ands\tr1, r0\n"
    "    cmp\tr1, #0\n"
    "    blt .Lde_080354B4\n"
    "    add\tr3, sp, #48\t@ 0x30\n"
    "    mov\tr1, ip\n"
    "    adds\tr0, r2, r1\n"
    "    strh\tr0, [r3, #0]\n"
    "    mov\tr1, r9\n"
    "    adds\tr0, r1, r7\n"
    "    strh\tr0, [r3, #2]\n"
    "    mov\tr7, r8\n"
    "    adds\tr0, r2, r7\n"
    "    strh\tr0, [r3, #4]\n"
    "    adds\tr0, r1, r5\n"
    "    strh\tr0, [r3, #6]\n"
    "    movs\tr0, #0\n"
    "    ldrsh\tr1, [r3, r0]\n"
    "    movs\tr2, #4\n"
    "    ldrsh\tr0, [r4, r2]\n"
    "    subs\tr1, r1, r0\n"
    "    movs\tr5, #0\n"
    "    ldrsh\tr0, [r4, r5]\n"
    "    movs\tr7, #4\n"
    "    ldrsh\tr2, [r3, r7]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    movs\tr2, #2\n"
    "    ldrsh\tr0, [r3, r2]\n"
    "    movs\tr5, #6\n"
    "    ldrsh\tr2, [r4, r5]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    movs\tr7, #2\n"
    "    ldrsh\tr0, [r4, r7]\n"
    "    movs\tr4, #6\n"
    "    ldrsh\tr2, [r3, r4]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    cmp\tr1, #0\n"
    "    bge .Lde_080354B4\n"
    "    movs\tr5, #0\n"
    "    str\tr5, [sp, #144]\t@ 0x90\n"
    ".Lde_080354B4:\n"
    "    ldr\tr7, [sp, #144]\t@ 0x90\n"
    "    cmp\tr7, #0\n"
    "    beq .Lde_08035542\n"
    "    ldr\tr1, [sp, #124]\t@ 0x7c\n"
    "    movs\tr2, #2\n"
    "    ldrsh\tr0, [r1, r2]\n"
    "    ldr\tr3, [sp, #132]\t@ 0x84\n"
    "    cmp\tr3, r0\n"
    "    beq .Lde_080354E4\n"
    "    ldr\tr4, [sp, #140]\t@ 0x8c\n"
    "    cmp\tr4, r0\n"
    "    beq .Lde_080354E4\n"
    "    movs\tr1, #0\n"
    "    cmp\tr0, r3\n"
    "    bge .Lde_080354D4\n"
    "    movs\tr1, #1\n"
    ".Lde_080354D4:\n"
    "    ldr\tr5, [sp, #140]\t@ 0x8c\n"
    "    cmp\tr0, r5\n"
    "    bge .Lde_080354E0\n"
    "    cmp\tr1, #0\n"
    "    beq .Lde_080354E4\n"
    "    b .Lde_0803552A\n"
    ".Lde_080354E0:\n"
    "    cmp\tr1, #0\n"
    "    beq .Lde_0803552A\n"
    ".Lde_080354E4:\n"
    "    lsls\tr0, r0, #16\n"
    "    mov\tr7, sl\n"
    "    str\tr0, [r7, #0]\n"
    "    movs\tr1, #0\n"
    "    ldr\tr0, [sp, #128]\t@ 0x80\n"
    "    str\tr1, [r0, #0]\n"
    "    ldr\tr2, [sp, #180]\t@ 0xb4\n"
    "    ldrb\tr0, [r2, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r2, #0]\n"
    "    lsls\tr0, r0, #24\n"
    "    lsrs\tr0, r0, #24\n"
    "    ldr\tr3, [sp, #116]\t@ 0x74\n"
    "    ldrh\tr3, [r3, #4]\n"
    "    cmp\tr0, r3\n"
    "    bcs .Lde_0803550A\n"
    "    movs\tr4, #1\n"
    "    str\tr4, [sp, #120]\t@ 0x78\n"
    "    b .Lde_08035530\n"
    ".Lde_0803550A:\n"
    "    ldr\tr5, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r5, #0]\n"
    "    adds\tr0, #1\n"
    "    ldr\tr7, [sp, #112]\t@ 0x70\n"
    "    ldrh\tr7, [r7, #0]\n"
    "    cmp\tr0, r7\n"
    "    blt .Lde_0803551A\n"
    "    b .Lde_0803580C\n"
    ".Lde_0803551A:\n"
    "    ldr\tr0, [sp, #180]\t@ 0xb4\n"
    "    strb\tr1, [r0, #0]\n"
    "    ldrb\tr0, [r5, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r5, #0]\n"
    "    movs\tr1, #2\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    "    b .Lde_08035530\n"
    ".Lde_0803552A:\n"
    "    ldr\tr2, [sp, #136]\t@ 0x88\n"
    "    mov\tr3, sl\n"
    "    str\tr2, [r3, #0]\n"
    ".Lde_08035530:\n"
    "    ldr\tr0, [sp, #0]\n"
    "    str\tr0, [r6, #8]\n"
    "    ldr\tr0, [sp, #8]\n"
    "    str\tr0, [r6, #12]\n"
    "    ldr\tr0, [sp, #4]\n"
    "    str\tr0, [r6, #24]\n"
    "    ldr\tr0, [sp, #12]\n"
    "    str\tr0, [r6, #28]\n"
    "    b .Lde_080357FA\n"
    ".Lde_08035542:\n"
    "    ldr\tr4, [sp, #184]\t@ 0xb8\n"
    "    ldrh\tr0, [r4, #0]\n"
    "    adds\tr0, #1\n"
    "    strh\tr0, [r4, #0]\n"
    "    b .Lde_080357FA\n"
    ".Lde_0803554C:\n"
    "    lsls\tr0, r2, #3\n"
    "    adds\tr3, r3, r0\n"
    "    str\tr3, [sp, #148]\t@ 0x94\n"
    "    movs\tr2, #0\n"
    "    ldrb\tr0, [r3, #6]\n"
    "    lsls\tr0, r0, #29\n"
    "    cmp\tr0, #0\n"
    "    blt .Lde_0803555E\n"
    "    movs\tr2, #1\n"
    ".Lde_0803555E:\n"
    "    mov\tr8, r2\n"
    "    movs\tr2, #0\n"
    "    ldr\tr3, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r3, #0]\n"
    "    adds\tr0, #1\n"
    "    ldr\tr4, [sp, #112]\t@ 0x70\n"
    "    ldrh\tr4, [r4, #0]\n"
    "    cmp\tr0, r4\n"
    "    bge .Lde_08035578\n"
    "    ldrh\tr7, [r7, #8]\n"
    "    cmp\tr1, r7\n"
    "    bcc .Lde_08035578\n"
    "    movs\tr2, #1\n"
    ".Lde_08035578:\n"
    "    mov\tsl, r2\n"
    "    cmp\tr2, #0\n"
    "    beq .Lde_08035596\n"
    "    ldrh\tr4, [r6, #4]\n"
    "    ldr\tr0, [r5, #0]\n"
    "    ldr\tr1, [r0, #20]\n"
    "    adds\tr0, r5, #0\n"
    "    bl _call_via_r1\n"
    "    cmp\tr4, r0\n"
    "    beq .Lde_08035596\n"
    "    movs\tr0, #0\n"
    "    ldr\tr5, [sp, #180]\t@ 0xb4\n"
    "    strb\tr0, [r5, #0]\n"
    "    b .Lde_080357C0\n"
    ".Lde_08035596:\n"
    "    adds\tr1, r6, #0\n"
    "    adds\tr1, #64\t@ 0x40\n"
    "    ldrh\tr0, [r1, #0]\n"
    "    str\tr1, [sp, #184]\t@ 0xb8\n"
    "    cmp\tr0, #0\n"
    "    beq .Lde_080355A4\n"
    "    b .Lde_08035788\n"
    ".Lde_080355A4:\n"
    "    ldr\tr0, [r6, #8]\n"
    "    str\tr0, [sp, #56]\t@ 0x38\n"
    "    ldr\tr0, [r6, #12]\n"
    "    str\tr0, [sp, #64]\t@ 0x40\n"
    "    ldr\tr0, [r6, #24]\n"
    "    str\tr0, [sp, #60]\t@ 0x3c\n"
    "    ldr\tr0, [r6, #28]\n"
    "    str\tr0, [sp, #68]\t@ 0x44\n"
    "    mov\tr1, r8\n"
    "    cmp\tr1, #0\n"
    "    beq .Lde_080355C8\n"
    "    mov\tr2, sp\n"
    "    adds\tr2, #56\t@ 0x38\n"
    "    str\tr2, [sp, #152]\t@ 0x98\n"
    "    mov\tr3, sp\n"
    "    adds\tr3, #60\t@ 0x3c\n"
    "    str\tr3, [sp, #156]\t@ 0x9c\n"
    "    b .Lde_080355D4\n"
    ".Lde_080355C8:\n"
    "    mov\tr4, sp\n"
    "    adds\tr4, #64\t@ 0x40\n"
    "    str\tr4, [sp, #152]\t@ 0x98\n"
    "    mov\tr7, sp\n"
    "    adds\tr7, #68\t@ 0x44\n"
    "    str\tr7, [sp, #156]\t@ 0x9c\n"
    ".Lde_080355D4:\n"
    "    ldr\tr1, [sp, #152]\t@ 0x98\n"
    "    ldr\tr0, [r1, #0]\n"
    "    asrs\tr2, r0, #16\n"
    "    str\tr2, [sp, #160]\t@ 0xa0\n"
    "    ldr\tr3, [sp, #156]\t@ 0x9c\n"
    "    ldr\tr1, [r3, #0]\n"
    "    adds\tr0, r0, r1\n"
    "    str\tr0, [sp, #164]\t@ 0xa4\n"
    "    asrs\tr4, r0, #16\n"
    "    str\tr4, [sp, #168]\t@ 0xa8\n"
    "    subs\tr7, r4, r2\n"
    "    movs\tr0, #1\n"
    "    str\tr0, [sp, #172]\t@ 0xac\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #63\t@ 0x3f\n"
    "    ldrb\tr2, [r0, #0]\n"
    "    adds\tr1, r0, #0\n"
    "    cmp\tr2, #0\n"
    "    beq .Lde_08035616\n"
    "    movs\tr3, #0\n"
    "    str\tr3, [sp, #172]\t@ 0xac\n"
    "    mov\tr4, sl\n"
    "    cmp\tr4, #0\n"
    "    beq .Lde_08035608\n"
    "    strb\tr3, [r1, #0]\n"
    "    b .Lde_0803560C\n"
    ".Lde_08035608:\n"
    "    subs\tr0, r2, #1\n"
    "    strb\tr0, [r1, #0]\n"
    ".Lde_0803560C:\n"
    "    ldrb\tr0, [r1, #0]\n"
    "    cmp\tr0, #0\n"
    "    bne .Lde_08035616\n"
    "    movs\tr1, #1\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    ".Lde_08035616:\n"
    "    mov\tr2, sl\n"
    "    cmp\tr2, #0\n"
    "    bne .Lde_080356FC\n"
    "    cmp\tr7, #0\n"
    "    beq .Lde_080356FC\n"
    "    ldr\tr0, [r5, #0]\n"
    "    ldr\tr2, [r0, #64]\t@ 0x40\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr1, #0\n"
    "    bl _call_via_r2\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, #0\n"
    "    beq .Lde_080356FC\n"
    "    ldrh\tr0, [r4, #4]\n"
    "    ldrh\tr3, [r6, #4]\n"
    "    cmp\tr0, r3\n"
    "    bne .Lde_080356FC\n"
    "    ldr\tr1, [r6, #20]\n"
    "    add\tr0, sp, #72\t@ 0x48\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r6, #0\n"
    "    bl _call_via_r2\n"
    "    ldr\tr0, [sp, #72]\t@ 0x48\n"
    "    ldr\tr1, [sp, #76]\t@ 0x4c\n"
    "    str\tr0, [sp, #80]\t@ 0x50\n"
    "    str\tr1, [sp, #84]\t@ 0x54\n"
    "    add\tr5, sp, #80\t@ 0x50\n"
    "    ldr\tr1, [r4, #20]\n"
    "    add\tr0, sp, #88\t@ 0x58\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r4, #0\n"
    "    bl _call_via_r2\n"
    "    ldr\tr0, [sp, #88]\t@ 0x58\n"
    "    ldr\tr1, [sp, #92]\t@ 0x5c\n"
    "    str\tr0, [sp, #96]\t@ 0x60\n"
    "    str\tr1, [sp, #100]\t@ 0x64\n"
    "    add\tr4, sp, #96\t@ 0x60\n"
    "    mov\tr0, r8\n"
    "    cmp\tr0, #0\n"
    "    beq .Lde_08035674\n"
    "    adds\tr2, r7, #0\n"
    "    movs\tr1, #0\n"
    "    mov\tr9, r1\n"
    "    b .Lde_08035678\n"
    ".Lde_08035674:\n"
    "    movs\tr2, #0\n"
    "    mov\tr9, r7\n"
    ".Lde_08035678:\n"
    "    movs\tr7, #0\n"
    "    ldrsh\tr3, [r5, r7]\n"
    "    mov\tr8, r3\n"
    "    movs\tr0, #4\n"
    "    ldrsh\tr1, [r4, r0]\n"
    "    subs\tr1, r3, r1\n"
    "    movs\tr3, #0\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    movs\tr3, #4\n"
    "    ldrsh\tr7, [r5, r3]\n"
    "    mov\tip, r7\n"
    "    subs\tr0, r0, r7\n"
    "    ands\tr1, r0\n"
    "    movs\tr0, #2\n"
    "    ldrsh\tr7, [r5, r0]\n"
    "    movs\tr3, #6\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    subs\tr0, r7, r0\n"
    "    ands\tr1, r0\n"
    "    movs\tr3, #2\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    movs\tr3, #6\n"
    "    ldrsh\tr5, [r5, r3]\n"
    "    subs\tr0, r0, r5\n"
    "    ands\tr1, r0\n"
    "    cmp\tr1, #0\n"
    "    blt .Lde_080356FC\n"
    "    add\tr3, sp, #104\t@ 0x68\n"
    "    mov\tr1, r8\n"
    "    adds\tr0, r2, r1\n"
    "    strh\tr0, [r3, #0]\n"
    "    mov\tr1, r9\n"
    "    adds\tr0, r1, r7\n"
    "    strh\tr0, [r3, #2]\n"
    "    mov\tr7, ip\n"
    "    adds\tr0, r2, r7\n"
    "    strh\tr0, [r3, #4]\n"
    "    adds\tr0, r1, r5\n"
    "    strh\tr0, [r3, #6]\n"
    "    movs\tr0, #0\n"
    "    ldrsh\tr1, [r3, r0]\n"
    "    movs\tr2, #4\n"
    "    ldrsh\tr0, [r4, r2]\n"
    "    subs\tr1, r1, r0\n"
    "    movs\tr5, #0\n"
    "    ldrsh\tr0, [r4, r5]\n"
    "    movs\tr7, #4\n"
    "    ldrsh\tr2, [r3, r7]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    movs\tr2, #2\n"
    "    ldrsh\tr0, [r3, r2]\n"
    "    movs\tr5, #6\n"
    "    ldrsh\tr2, [r4, r5]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    movs\tr7, #2\n"
    "    ldrsh\tr0, [r4, r7]\n"
    "    movs\tr4, #6\n"
    "    ldrsh\tr2, [r3, r4]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    cmp\tr1, #0\n"
    "    bge .Lde_080356FC\n"
    "    movs\tr5, #0\n"
    "    str\tr5, [sp, #172]\t@ 0xac\n"
    ".Lde_080356FC:\n"
    "    ldr\tr7, [sp, #172]\t@ 0xac\n"
    "    cmp\tr7, #0\n"
    "    beq .Lde_080357FA\n"
    "    ldr\tr0, [sp, #148]\t@ 0x94\n"
    "    movs\tr1, #0\n"
    "    ldrsh\tr2, [r0, r1]\n"
    "    ldr\tr3, [sp, #168]\t@ 0xa8\n"
    "    cmp\tr3, r2\n"
    "    beq .Lde_0803571A\n"
    "    ldr\tr4, [sp, #160]\t@ 0xa0\n"
    "    subs\tr0, r2, r4\n"
    "    subs\tr1, r2, r3\n"
    "    eors\tr0, r1\n"
    "    cmp\tr0, #0\n"
    "    bge .Lde_08035770\n"
    ".Lde_0803571A:\n"
    "    lsls\tr0, r2, #16\n"
    "    ldr\tr5, [sp, #152]\t@ 0x98\n"
    "    str\tr0, [r5, #0]\n"
    "    movs\tr1, #0\n"
    "    ldr\tr7, [sp, #156]\t@ 0x9c\n"
    "    str\tr1, [r7, #0]\n"
    "    mov\tr0, sl\n"
    "    cmp\tr0, #0\n"
    "    bne .Lde_08035734\n"
    "    ldr\tr2, [sp, #148]\t@ 0x94\n"
    "    ldrh\tr0, [r2, #4]\n"
    "    cmp\tr0, #0\n"
    "    bne .Lde_08035764\n"
    ".Lde_08035734:\n"
    "    ldr\tr3, [sp, #180]\t@ 0xb4\n"
    "    ldrb\tr0, [r3, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r3, #0]\n"
    "    lsls\tr0, r0, #24\n"
    "    lsrs\tr0, r0, #24\n"
    "    ldr\tr4, [sp, #116]\t@ 0x74\n"
    "    ldrh\tr4, [r4, #4]\n"
    "    cmp\tr0, r4\n"
    "    bcc .Lde_0803575E\n"
    "    strb\tr1, [r3, #0]\n"
    "    mov\tr5, sl\n"
    "    cmp\tr5, #0\n"
    "    beq .Lde_08035758\n"
    "    ldr\tr7, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r7, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r7, #0]\n"
    ".Lde_08035758:\n"
    "    movs\tr0, #2\n"
    "    str\tr0, [sp, #120]\t@ 0x78\n"
    "    b .Lde_08035776\n"
    ".Lde_0803575E:\n"
    "    movs\tr1, #1\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    "    b .Lde_08035776\n"
    ".Lde_08035764:\n"
    "    movs\tr0, #1\n"
    "    ldr\tr2, [sp, #184]\t@ 0xb8\n"
    "    strh\tr0, [r2, #0]\n"
    "    movs\tr3, #1\n"
    "    str\tr3, [sp, #120]\t@ 0x78\n"
    "    b .Lde_08035776\n"
    ".Lde_08035770:\n"
    "    ldr\tr4, [sp, #164]\t@ 0xa4\n"
    "    ldr\tr5, [sp, #152]\t@ 0x98\n"
    "    str\tr4, [r5, #0]\n"
    ".Lde_08035776:\n"
    "    ldr\tr0, [sp, #56]\t@ 0x38\n"
    "    str\tr0, [r6, #8]\n"
    "    ldr\tr0, [sp, #64]\t@ 0x40\n"
    "    str\tr0, [r6, #12]\n"
    "    ldr\tr0, [sp, #60]\t@ 0x3c\n"
    "    str\tr0, [r6, #24]\n"
    "    ldr\tr0, [sp, #68]\t@ 0x44\n"
    "    str\tr0, [r6, #28]\n"
    "    b .Lde_080357FA\n"
    ".Lde_08035788:\n"
    "    mov\tr7, sl\n"
    "    cmp\tr7, #0\n"
    "    bne .Lde_0803579E\n"
    "    adds\tr0, #1\n"
    "    strh\tr0, [r1, #0]\n"
    "    lsls\tr0, r0, #16\n"
    "    lsrs\tr0, r0, #16\n"
    "    ldr\tr2, [sp, #148]\t@ 0x94\n"
    "    ldrh\tr2, [r2, #4]\n"
    "    cmp\tr0, r2\n"
    "    bls .Lde_080357FA\n"
    ".Lde_0803579E:\n"
    "    movs\tr0, #0\n"
    "    strh\tr0, [r1, #0]\n"
    "    ldr\tr3, [sp, #180]\t@ 0xb4\n"
    "    ldrb\tr0, [r3, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r3, #0]\n"
    "    lsls\tr0, r0, #24\n"
    "    lsrs\tr0, r0, #24\n"
    "    ldr\tr4, [sp, #116]\t@ 0x74\n"
    "    ldrh\tr4, [r4, #4]\n"
    "    cmp\tr0, r4\n"
    "    bcc .Lde_080357CE\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r3, #0]\n"
    "    mov\tr5, sl\n"
    "    cmp\tr5, #0\n"
    "    beq .Lde_080357C8\n"
    ".Lde_080357C0:\n"
    "    ldr\tr7, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r7, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r7, #0]\n"
    ".Lde_080357C8:\n"
    "    movs\tr0, #2\n"
    "    str\tr0, [sp, #120]\t@ 0x78\n"
    "    b .Lde_08035800\n"
    ".Lde_080357CE:\n"
    "    movs\tr1, #1\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    "    b .Lde_08035800\n"
    ".Lde_080357D4:\n"
    "    ldr\tr2, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r2, #0]\n"
    "    adds\tr0, #1\n"
    "    ldr\tr3, [sp, #112]\t@ 0x70\n"
    "    ldrh\tr3, [r3, #0]\n"
    "    cmp\tr0, r3\n"
    "    bge .Lde_080357FA\n"
    "    ldrh\tr7, [r7, #8]\n"
    "    cmp\tr1, r7\n"
    "    bcc .Lde_080357FA\n"
    "    adds\tr1, r6, #0\n"
    "    adds\tr1, #62\t@ 0x3e\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    "    ldrb\tr0, [r2, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r2, #0]\n"
    "    movs\tr4, #2\n"
    "    str\tr4, [sp, #120]\t@ 0x78\n"
    ".Lde_080357FA:\n"
    "    ldr\tr5, [sp, #120]\t@ 0x78\n"
    "    cmp\tr5, #0\n"
    "    ble .Lde_0803580C\n"
    ".Lde_08035800:\n"
    "    ldr\tr0, [r6, #20]\n"
    "    ldr\tr2, [r0, #60]\t@ 0x3c\n"
    "    adds\tr0, r6, #0\n"
    "    ldr\tr1, [sp, #120]\t@ 0x78\n"
    "    bl _call_via_r2\n"
    ".Lde_0803580C:\n"
    "    add\tsp, #188\t@ 0xbc\n"
    "    pop\t{r3, r4, r5}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    mov\tsl, r5\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r0}\n"
    "    bx\tr0\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    .align 2, 0\n"
    "\n"
    "    .global func_08035380\n"
    "    .thumb_func\n"
    "func_08035380:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, sl\n"
    "    mov\tr6, r9\n"
    "    mov\tr5, r8\n"
    "    push\t{r5, r6, r7}\n"
    "    sub\tsp, #188\t@ 0xbc\n"
    "    adds\tr6, r0, #0\n"
    "    ldr\tr5, [r6, #0]\n"
    "    ldr\tr1, [r6, #56]\t@ 0x38\n"
    "    cmp\tr1, #0\n"
    "    bne .Lus_08035398\n"
    "    b .Lus_080358F8\n"
    ".Lus_08035398:\n"
    "    adds\tr0, #60\t@ 0x3c\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    ldr\tr1, [r1, #8]\n"
    "    lsls\tr0, r0, #2\n"
    "    adds\tr0, r0, r1\n"
    "    ldr\tr0, [r0, #0]\n"
    "    str\tr0, [sp, #112]\t@ 0x70\n"
    "    cmp\tr0, #0\n"
    "    bne .Lus_080353AC\n"
    "    b .Lus_080358F8\n"
    ".Lus_080353AC:\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #61\t@ 0x3d\n"
    "    ldrb\tr1, [r0, #0]\n"
    "    str\tr0, [sp, #176]\t@ 0xb0\n"
    "    ldr\tr0, [sp, #112]\t@ 0x70\n"
    "    ldrh\tr0, [r0, #0]\n"
    "    cmp\tr1, r0\n"
    "    bcc .Lus_080353BE\n"
    "    b .Lus_080358F8\n"
    ".Lus_080353BE:\n"
    "    lsls\tr1, r1, #3\n"
    "    ldr\tr2, [sp, #112]\t@ 0x70\n"
    "    ldr\tr0, [r2, #4]\n"
    "    adds\tr7, r0, r1\n"
    "    ldr\tr3, [r7, #4]\n"
    "    str\tr3, [sp, #116]\t@ 0x74\n"
    "    cmp\tr3, #0\n"
    "    bne .Lus_080353D0\n"
    "    b .Lus_080358F8\n"
    ".Lus_080353D0:\n"
    "    ldr\tr0, [r5, #0]\n"
    "    movs\tr4, #162\t@ 0xa2\n"
    "    lsls\tr4, r4, #1\n"
    "    adds\tr0, r0, r4\n"
    "    ldr\tr1, [r0, #0]\n"
    "    adds\tr0, r5, #0\n"
    "    bl _call_via_r1\n"
    "    ldrh\tr3, [r0, #10]\n"
    "    lsls\tr0, r3, #27\n"
    "    lsrs\tr0, r0, #27\n"
    "    subs\tr2, r0, #6\n"
    "    cmp\tr2, #0\n"
    "    bge .Lus_080353EE\n"
    "    adds\tr2, #24\n"
    ".Lus_080353EE:\n"
    "    lsls\tr1, r2, #4\n"
    "    subs\tr1, r1, r2\n"
    "    lsls\tr1, r1, #2\n"
    "    lsls\tr0, r3, #21\n"
    "    lsrs\tr0, r0, #26\n"
    "    adds\tr1, r1, r0\n"
    "    movs\tr0, #0\n"
    "    str\tr0, [sp, #120]\t@ 0x78\n"
    "    ldr\tr2, [sp, #116]\t@ 0x74\n"
    "    ldr\tr3, [r2, #0]\n"
    "    cmp\tr3, #0\n"
    "    bne .Lus_08035408\n"
    "    b .Lus_080358C0\n"
    ".Lus_08035408:\n"
    "    ldrh\tr4, [r2, #4]\n"
    "    cmp\tr4, #0\n"
    "    bne .Lus_08035410\n"
    "    b .Lus_080358C0\n"
    ".Lus_08035410:\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #62\t@ 0x3e\n"
    "    ldrb\tr2, [r0, #0]\n"
    "    str\tr0, [sp, #180]\t@ 0xb4\n"
    "    cmp\tr2, r4\n"
    "    bcc .Lus_0803541E\n"
    "    b .Lus_080358F8\n"
    ".Lus_0803541E:\n"
    "    ldr\tr4, [sp, #116]\t@ 0x74\n"
    "    ldrb\tr0, [r4, #11]\n"
    "    lsls\tr0, r0, #27\n"
    "    cmp\tr0, #0\n"
    "    bge .Lus_0803542A\n"
    "    b .Lus_08035638\n"
    ".Lus_0803542A:\n"
    "    lsls\tr0, r2, #3\n"
    "    adds\tr3, r3, r0\n"
    "    str\tr3, [sp, #124]\t@ 0x7c\n"
    "    movs\tr1, #0\n"
    "    ldrb\tr0, [r3, #4]\n"
    "    lsls\tr0, r0, #31\n"
    "    cmp\tr0, #0\n"
    "    bne .Lus_0803543C\n"
    "    movs\tr1, #1\n"
    ".Lus_0803543C:\n"
    "    mov\tr8, r1\n"
    "    ldr\tr0, [r6, #8]\n"
    "    str\tr0, [sp, #0]\n"
    "    ldr\tr0, [r6, #12]\n"
    "    str\tr0, [sp, #8]\n"
    "    ldr\tr0, [r6, #24]\n"
    "    str\tr0, [sp, #4]\n"
    "    ldr\tr0, [r6, #28]\n"
    "    str\tr0, [sp, #12]\n"
    "    cmp\tr1, #0\n"
    "    beq .Lus_0803545C\n"
    "    mov\tsl, sp\n"
    "    mov\tr7, sp\n"
    "    adds\tr7, #4\n"
    "    str\tr7, [sp, #128]\t@ 0x80\n"
    "    b .Lus_08035466\n"
    ".Lus_0803545C:\n"
    "    add\tr0, sp, #8\n"
    "    mov\tsl, r0\n"
    "    mov\tr1, sp\n"
    "    adds\tr1, #12\n"
    "    str\tr1, [sp, #128]\t@ 0x80\n"
    ".Lus_08035466:\n"
    "    mov\tr2, sl\n"
    "    ldr\tr1, [r2, #0]\n"
    "    asrs\tr3, r1, #16\n"
    "    str\tr3, [sp, #132]\t@ 0x84\n"
    "    ldr\tr4, [sp, #128]\t@ 0x80\n"
    "    ldr\tr0, [r4, #0]\n"
    "    adds\tr1, r1, r0\n"
    "    str\tr1, [sp, #136]\t@ 0x88\n"
    "    asrs\tr7, r1, #16\n"
    "    str\tr7, [sp, #140]\t@ 0x8c\n"
    "    subs\tr7, r7, r3\n"
    "    movs\tr3, #0\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #64\t@ 0x40\n"
    "    ldrh\tr2, [r0, #0]\n"
    "    ldr r1, .Lus_080354AC\n"
    "    str\tr0, [sp, #184]\t@ 0xb8\n"
    "    cmp\tr2, r1\n"
    "    blt .Lus_0803548E\n"
    "    movs\tr3, #1\n"
    ".Lus_0803548E:\n"
    "    movs\tr0, #1\n"
    "    str\tr0, [sp, #144]\t@ 0x90\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #63\t@ 0x3f\n"
    "    ldrb\tr2, [r0, #0]\n"
    "    adds\tr1, r0, #0\n"
    "    cmp\tr2, #0\n"
    "    beq .Lus_080354BE\n"
    "    movs\tr4, #0\n"
    "    str\tr4, [sp, #144]\t@ 0x90\n"
    "    cmp\tr3, #0\n"
    "    beq .Lus_080354B0\n"
    "    strb\tr4, [r1, #0]\n"
    "    b .Lus_080354B4\n"
    "    .align 2, 0\n"
    ".Lus_080354AC:\n"
    "    .word 0x000002EE\n"
    ".Lus_080354B0:\n"
    "    subs\tr0, r2, #1\n"
    "    strb\tr0, [r1, #0]\n"
    ".Lus_080354B4:\n"
    "    ldrb\tr0, [r1, #0]\n"
    "    cmp\tr0, #0\n"
    "    bne .Lus_080354BE\n"
    "    movs\tr1, #1\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    ".Lus_080354BE:\n"
    "    cmp\tr3, #0\n"
    "    bne .Lus_080355A0\n"
    "    cmp\tr7, #0\n"
    "    beq .Lus_080355A0\n"
    "    ldr\tr0, [r5, #0]\n"
    "    ldr\tr2, [r0, #64]\t@ 0x40\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr1, #0\n"
    "    bl _call_via_r2\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, #0\n"
    "    beq .Lus_080355A0\n"
    "    ldrh\tr0, [r4, #4]\n"
    "    ldrh\tr2, [r6, #4]\n"
    "    cmp\tr0, r2\n"
    "    bne .Lus_080355A0\n"
    "    ldr\tr1, [r6, #20]\n"
    "    add\tr0, sp, #16\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r6, #0\n"
    "    bl _call_via_r2\n"
    "    ldr\tr0, [sp, #16]\n"
    "    ldr\tr1, [sp, #20]\n"
    "    str\tr0, [sp, #24]\n"
    "    str\tr1, [sp, #28]\n"
    "    add\tr5, sp, #24\n"
    "    ldr\tr1, [r4, #20]\n"
    "    add\tr0, sp, #32\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r4, #0\n"
    "    bl _call_via_r2\n"
    "    ldr\tr0, [sp, #32]\n"
    "    ldr\tr1, [sp, #36]\t@ 0x24\n"
    "    str\tr0, [sp, #40]\t@ 0x28\n"
    "    str\tr1, [sp, #44]\t@ 0x2c\n"
    "    add\tr4, sp, #40\t@ 0x28\n"
    "    mov\tr3, r8\n"
    "    cmp\tr3, #0\n"
    "    beq .Lus_08035518\n"
    "    adds\tr2, r7, #0\n"
    "    movs\tr7, #0\n"
    "    b .Lus_0803551A\n"
    ".Lus_08035518:\n"
    "    movs\tr2, #0\n"
    ".Lus_0803551A:\n"
    "    mov\tr9, r7\n"
    "    movs\tr1, #0\n"
    "    ldrsh\tr0, [r5, r1]\n"
    "    mov\tip, r0\n"
    "    movs\tr3, #4\n"
    "    ldrsh\tr1, [r4, r3]\n"
    "    subs\tr1, r0, r1\n"
    "    movs\tr7, #0\n"
    "    ldrsh\tr0, [r4, r7]\n"
    "    movs\tr7, #4\n"
    "    ldrsh\tr3, [r5, r7]\n"
    "    mov\tr8, r3\n"
    "    subs\tr0, r0, r3\n"
    "    ands\tr1, r0\n"
    "    movs\tr0, #2\n"
    "    ldrsh\tr7, [r5, r0]\n"
    "    movs\tr3, #6\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    subs\tr0, r7, r0\n"
    "    ands\tr1, r0\n"
    "    movs\tr3, #2\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    movs\tr3, #6\n"
    "    ldrsh\tr5, [r5, r3]\n"
    "    subs\tr0, r0, r5\n"
    "    ands\tr1, r0\n"
    "    cmp\tr1, #0\n"
    "    blt .Lus_080355A0\n"
    "    add\tr3, sp, #48\t@ 0x30\n"
    "    mov\tr1, ip\n"
    "    adds\tr0, r2, r1\n"
    "    strh\tr0, [r3, #0]\n"
    "    mov\tr1, r9\n"
    "    adds\tr0, r1, r7\n"
    "    strh\tr0, [r3, #2]\n"
    "    mov\tr7, r8\n"
    "    adds\tr0, r2, r7\n"
    "    strh\tr0, [r3, #4]\n"
    "    adds\tr0, r1, r5\n"
    "    strh\tr0, [r3, #6]\n"
    "    movs\tr0, #0\n"
    "    ldrsh\tr1, [r3, r0]\n"
    "    movs\tr2, #4\n"
    "    ldrsh\tr0, [r4, r2]\n"
    "    subs\tr1, r1, r0\n"
    "    movs\tr5, #0\n"
    "    ldrsh\tr0, [r4, r5]\n"
    "    movs\tr7, #4\n"
    "    ldrsh\tr2, [r3, r7]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    movs\tr2, #2\n"
    "    ldrsh\tr0, [r3, r2]\n"
    "    movs\tr5, #6\n"
    "    ldrsh\tr2, [r4, r5]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    movs\tr7, #2\n"
    "    ldrsh\tr0, [r4, r7]\n"
    "    movs\tr4, #6\n"
    "    ldrsh\tr2, [r3, r4]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    cmp\tr1, #0\n"
    "    bge .Lus_080355A0\n"
    "    movs\tr5, #0\n"
    "    str\tr5, [sp, #144]\t@ 0x90\n"
    ".Lus_080355A0:\n"
    "    ldr\tr7, [sp, #144]\t@ 0x90\n"
    "    cmp\tr7, #0\n"
    "    beq .Lus_0803562E\n"
    "    ldr\tr1, [sp, #124]\t@ 0x7c\n"
    "    movs\tr2, #2\n"
    "    ldrsh\tr0, [r1, r2]\n"
    "    ldr\tr3, [sp, #132]\t@ 0x84\n"
    "    cmp\tr3, r0\n"
    "    beq .Lus_080355D0\n"
    "    ldr\tr4, [sp, #140]\t@ 0x8c\n"
    "    cmp\tr4, r0\n"
    "    beq .Lus_080355D0\n"
    "    movs\tr1, #0\n"
    "    cmp\tr0, r3\n"
    "    bge .Lus_080355C0\n"
    "    movs\tr1, #1\n"
    ".Lus_080355C0:\n"
    "    ldr\tr5, [sp, #140]\t@ 0x8c\n"
    "    cmp\tr0, r5\n"
    "    bge .Lus_080355CC\n"
    "    cmp\tr1, #0\n"
    "    beq .Lus_080355D0\n"
    "    b .Lus_08035616\n"
    ".Lus_080355CC:\n"
    "    cmp\tr1, #0\n"
    "    beq .Lus_08035616\n"
    ".Lus_080355D0:\n"
    "    lsls\tr0, r0, #16\n"
    "    mov\tr7, sl\n"
    "    str\tr0, [r7, #0]\n"
    "    movs\tr1, #0\n"
    "    ldr\tr0, [sp, #128]\t@ 0x80\n"
    "    str\tr1, [r0, #0]\n"
    "    ldr\tr2, [sp, #180]\t@ 0xb4\n"
    "    ldrb\tr0, [r2, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r2, #0]\n"
    "    lsls\tr0, r0, #24\n"
    "    lsrs\tr0, r0, #24\n"
    "    ldr\tr3, [sp, #116]\t@ 0x74\n"
    "    ldrh\tr3, [r3, #4]\n"
    "    cmp\tr0, r3\n"
    "    bcs .Lus_080355F6\n"
    "    movs\tr4, #1\n"
    "    str\tr4, [sp, #120]\t@ 0x78\n"
    "    b .Lus_0803561C\n"
    ".Lus_080355F6:\n"
    "    ldr\tr5, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r5, #0]\n"
    "    adds\tr0, #1\n"
    "    ldr\tr7, [sp, #112]\t@ 0x70\n"
    "    ldrh\tr7, [r7, #0]\n"
    "    cmp\tr0, r7\n"
    "    blt .Lus_08035606\n"
    "    b .Lus_080358F8\n"
    ".Lus_08035606:\n"
    "    ldr\tr0, [sp, #180]\t@ 0xb4\n"
    "    strb\tr1, [r0, #0]\n"
    "    ldrb\tr0, [r5, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r5, #0]\n"
    "    movs\tr1, #2\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    "    b .Lus_0803561C\n"
    ".Lus_08035616:\n"
    "    ldr\tr2, [sp, #136]\t@ 0x88\n"
    "    mov\tr3, sl\n"
    "    str\tr2, [r3, #0]\n"
    ".Lus_0803561C:\n"
    "    ldr\tr0, [sp, #0]\n"
    "    str\tr0, [r6, #8]\n"
    "    ldr\tr0, [sp, #8]\n"
    "    str\tr0, [r6, #12]\n"
    "    ldr\tr0, [sp, #4]\n"
    "    str\tr0, [r6, #24]\n"
    "    ldr\tr0, [sp, #12]\n"
    "    str\tr0, [r6, #28]\n"
    "    b .Lus_080358E6\n"
    ".Lus_0803562E:\n"
    "    ldr\tr4, [sp, #184]\t@ 0xb8\n"
    "    ldrh\tr0, [r4, #0]\n"
    "    adds\tr0, #1\n"
    "    strh\tr0, [r4, #0]\n"
    "    b .Lus_080358E6\n"
    ".Lus_08035638:\n"
    "    lsls\tr0, r2, #3\n"
    "    adds\tr3, r3, r0\n"
    "    str\tr3, [sp, #148]\t@ 0x94\n"
    "    movs\tr2, #0\n"
    "    ldrb\tr0, [r3, #6]\n"
    "    lsls\tr0, r0, #29\n"
    "    cmp\tr0, #0\n"
    "    blt .Lus_0803564A\n"
    "    movs\tr2, #1\n"
    ".Lus_0803564A:\n"
    "    mov\tr8, r2\n"
    "    movs\tr2, #0\n"
    "    ldr\tr3, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r3, #0]\n"
    "    adds\tr0, #1\n"
    "    ldr\tr4, [sp, #112]\t@ 0x70\n"
    "    ldrh\tr4, [r4, #0]\n"
    "    cmp\tr0, r4\n"
    "    bge .Lus_08035664\n"
    "    ldrh\tr7, [r7, #8]\n"
    "    cmp\tr1, r7\n"
    "    bcc .Lus_08035664\n"
    "    movs\tr2, #1\n"
    ".Lus_08035664:\n"
    "    mov\tsl, r2\n"
    "    cmp\tr2, #0\n"
    "    beq .Lus_08035682\n"
    "    ldrh\tr4, [r6, #4]\n"
    "    ldr\tr0, [r5, #0]\n"
    "    ldr\tr1, [r0, #20]\n"
    "    adds\tr0, r5, #0\n"
    "    bl _call_via_r1\n"
    "    cmp\tr4, r0\n"
    "    beq .Lus_08035682\n"
    "    movs\tr0, #0\n"
    "    ldr\tr5, [sp, #180]\t@ 0xb4\n"
    "    strb\tr0, [r5, #0]\n"
    "    b .Lus_080358AC\n"
    ".Lus_08035682:\n"
    "    adds\tr1, r6, #0\n"
    "    adds\tr1, #64\t@ 0x40\n"
    "    ldrh\tr0, [r1, #0]\n"
    "    str\tr1, [sp, #184]\t@ 0xb8\n"
    "    cmp\tr0, #0\n"
    "    beq .Lus_08035690\n"
    "    b .Lus_08035874\n"
    ".Lus_08035690:\n"
    "    ldr\tr0, [r6, #8]\n"
    "    str\tr0, [sp, #56]\t@ 0x38\n"
    "    ldr\tr0, [r6, #12]\n"
    "    str\tr0, [sp, #64]\t@ 0x40\n"
    "    ldr\tr0, [r6, #24]\n"
    "    str\tr0, [sp, #60]\t@ 0x3c\n"
    "    ldr\tr0, [r6, #28]\n"
    "    str\tr0, [sp, #68]\t@ 0x44\n"
    "    mov\tr1, r8\n"
    "    cmp\tr1, #0\n"
    "    beq .Lus_080356B4\n"
    "    mov\tr2, sp\n"
    "    adds\tr2, #56\t@ 0x38\n"
    "    str\tr2, [sp, #152]\t@ 0x98\n"
    "    mov\tr3, sp\n"
    "    adds\tr3, #60\t@ 0x3c\n"
    "    str\tr3, [sp, #156]\t@ 0x9c\n"
    "    b .Lus_080356C0\n"
    ".Lus_080356B4:\n"
    "    mov\tr4, sp\n"
    "    adds\tr4, #64\t@ 0x40\n"
    "    str\tr4, [sp, #152]\t@ 0x98\n"
    "    mov\tr7, sp\n"
    "    adds\tr7, #68\t@ 0x44\n"
    "    str\tr7, [sp, #156]\t@ 0x9c\n"
    ".Lus_080356C0:\n"
    "    ldr\tr1, [sp, #152]\t@ 0x98\n"
    "    ldr\tr0, [r1, #0]\n"
    "    asrs\tr2, r0, #16\n"
    "    str\tr2, [sp, #160]\t@ 0xa0\n"
    "    ldr\tr3, [sp, #156]\t@ 0x9c\n"
    "    ldr\tr1, [r3, #0]\n"
    "    adds\tr0, r0, r1\n"
    "    str\tr0, [sp, #164]\t@ 0xa4\n"
    "    asrs\tr4, r0, #16\n"
    "    str\tr4, [sp, #168]\t@ 0xa8\n"
    "    subs\tr7, r4, r2\n"
    "    movs\tr0, #1\n"
    "    str\tr0, [sp, #172]\t@ 0xac\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #63\t@ 0x3f\n"
    "    ldrb\tr2, [r0, #0]\n"
    "    adds\tr1, r0, #0\n"
    "    cmp\tr2, #0\n"
    "    beq .Lus_08035702\n"
    "    movs\tr3, #0\n"
    "    str\tr3, [sp, #172]\t@ 0xac\n"
    "    mov\tr4, sl\n"
    "    cmp\tr4, #0\n"
    "    beq .Lus_080356F4\n"
    "    strb\tr3, [r1, #0]\n"
    "    b .Lus_080356F8\n"
    ".Lus_080356F4:\n"
    "    subs\tr0, r2, #1\n"
    "    strb\tr0, [r1, #0]\n"
    ".Lus_080356F8:\n"
    "    ldrb\tr0, [r1, #0]\n"
    "    cmp\tr0, #0\n"
    "    bne .Lus_08035702\n"
    "    movs\tr1, #1\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    ".Lus_08035702:\n"
    "    mov\tr2, sl\n"
    "    cmp\tr2, #0\n"
    "    bne .Lus_080357E8\n"
    "    cmp\tr7, #0\n"
    "    beq .Lus_080357E8\n"
    "    ldr\tr0, [r5, #0]\n"
    "    ldr\tr2, [r0, #64]\t@ 0x40\n"
    "    adds\tr0, r5, #0\n"
    "    movs\tr1, #0\n"
    "    bl _call_via_r2\n"
    "    adds\tr4, r0, #0\n"
    "    cmp\tr4, #0\n"
    "    beq .Lus_080357E8\n"
    "    ldrh\tr0, [r4, #4]\n"
    "    ldrh\tr3, [r6, #4]\n"
    "    cmp\tr0, r3\n"
    "    bne .Lus_080357E8\n"
    "    ldr\tr1, [r6, #20]\n"
    "    add\tr0, sp, #72\t@ 0x48\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r6, #0\n"
    "    bl _call_via_r2\n"
    "    ldr\tr0, [sp, #72]\t@ 0x48\n"
    "    ldr\tr1, [sp, #76]\t@ 0x4c\n"
    "    str\tr0, [sp, #80]\t@ 0x50\n"
    "    str\tr1, [sp, #84]\t@ 0x54\n"
    "    add\tr5, sp, #80\t@ 0x50\n"
    "    ldr\tr1, [r4, #20]\n"
    "    add\tr0, sp, #88\t@ 0x58\n"
    "    ldr\tr2, [r1, #12]\n"
    "    adds\tr1, r4, #0\n"
    "    bl _call_via_r2\n"
    "    ldr\tr0, [sp, #88]\t@ 0x58\n"
    "    ldr\tr1, [sp, #92]\t@ 0x5c\n"
    "    str\tr0, [sp, #96]\t@ 0x60\n"
    "    str\tr1, [sp, #100]\t@ 0x64\n"
    "    add\tr4, sp, #96\t@ 0x60\n"
    "    mov\tr0, r8\n"
    "    cmp\tr0, #0\n"
    "    beq .Lus_08035760\n"
    "    adds\tr2, r7, #0\n"
    "    movs\tr1, #0\n"
    "    mov\tr9, r1\n"
    "    b .Lus_08035764\n"
    ".Lus_08035760:\n"
    "    movs\tr2, #0\n"
    "    mov\tr9, r7\n"
    ".Lus_08035764:\n"
    "    movs\tr7, #0\n"
    "    ldrsh\tr3, [r5, r7]\n"
    "    mov\tr8, r3\n"
    "    movs\tr0, #4\n"
    "    ldrsh\tr1, [r4, r0]\n"
    "    subs\tr1, r3, r1\n"
    "    movs\tr3, #0\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    movs\tr3, #4\n"
    "    ldrsh\tr7, [r5, r3]\n"
    "    mov\tip, r7\n"
    "    subs\tr0, r0, r7\n"
    "    ands\tr1, r0\n"
    "    movs\tr0, #2\n"
    "    ldrsh\tr7, [r5, r0]\n"
    "    movs\tr3, #6\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    subs\tr0, r7, r0\n"
    "    ands\tr1, r0\n"
    "    movs\tr3, #2\n"
    "    ldrsh\tr0, [r4, r3]\n"
    "    movs\tr3, #6\n"
    "    ldrsh\tr5, [r5, r3]\n"
    "    subs\tr0, r0, r5\n"
    "    ands\tr1, r0\n"
    "    cmp\tr1, #0\n"
    "    blt .Lus_080357E8\n"
    "    add\tr3, sp, #104\t@ 0x68\n"
    "    mov\tr1, r8\n"
    "    adds\tr0, r2, r1\n"
    "    strh\tr0, [r3, #0]\n"
    "    mov\tr1, r9\n"
    "    adds\tr0, r1, r7\n"
    "    strh\tr0, [r3, #2]\n"
    "    mov\tr7, ip\n"
    "    adds\tr0, r2, r7\n"
    "    strh\tr0, [r3, #4]\n"
    "    adds\tr0, r1, r5\n"
    "    strh\tr0, [r3, #6]\n"
    "    movs\tr0, #0\n"
    "    ldrsh\tr1, [r3, r0]\n"
    "    movs\tr2, #4\n"
    "    ldrsh\tr0, [r4, r2]\n"
    "    subs\tr1, r1, r0\n"
    "    movs\tr5, #0\n"
    "    ldrsh\tr0, [r4, r5]\n"
    "    movs\tr7, #4\n"
    "    ldrsh\tr2, [r3, r7]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    movs\tr2, #2\n"
    "    ldrsh\tr0, [r3, r2]\n"
    "    movs\tr5, #6\n"
    "    ldrsh\tr2, [r4, r5]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    movs\tr7, #2\n"
    "    ldrsh\tr0, [r4, r7]\n"
    "    movs\tr4, #6\n"
    "    ldrsh\tr2, [r3, r4]\n"
    "    subs\tr0, r0, r2\n"
    "    ands\tr1, r0\n"
    "    cmp\tr1, #0\n"
    "    bge .Lus_080357E8\n"
    "    movs\tr5, #0\n"
    "    str\tr5, [sp, #172]\t@ 0xac\n"
    ".Lus_080357E8:\n"
    "    ldr\tr7, [sp, #172]\t@ 0xac\n"
    "    cmp\tr7, #0\n"
    "    beq .Lus_080358E6\n"
    "    ldr\tr0, [sp, #148]\t@ 0x94\n"
    "    movs\tr1, #0\n"
    "    ldrsh\tr2, [r0, r1]\n"
    "    ldr\tr3, [sp, #168]\t@ 0xa8\n"
    "    cmp\tr3, r2\n"
    "    beq .Lus_08035806\n"
    "    ldr\tr4, [sp, #160]\t@ 0xa0\n"
    "    subs\tr0, r2, r4\n"
    "    subs\tr1, r2, r3\n"
    "    eors\tr0, r1\n"
    "    cmp\tr0, #0\n"
    "    bge .Lus_0803585C\n"
    ".Lus_08035806:\n"
    "    lsls\tr0, r2, #16\n"
    "    ldr\tr5, [sp, #152]\t@ 0x98\n"
    "    str\tr0, [r5, #0]\n"
    "    movs\tr1, #0\n"
    "    ldr\tr7, [sp, #156]\t@ 0x9c\n"
    "    str\tr1, [r7, #0]\n"
    "    mov\tr0, sl\n"
    "    cmp\tr0, #0\n"
    "    bne .Lus_08035820\n"
    "    ldr\tr2, [sp, #148]\t@ 0x94\n"
    "    ldrh\tr0, [r2, #4]\n"
    "    cmp\tr0, #0\n"
    "    bne .Lus_08035850\n"
    ".Lus_08035820:\n"
    "    ldr\tr3, [sp, #180]\t@ 0xb4\n"
    "    ldrb\tr0, [r3, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r3, #0]\n"
    "    lsls\tr0, r0, #24\n"
    "    lsrs\tr0, r0, #24\n"
    "    ldr\tr4, [sp, #116]\t@ 0x74\n"
    "    ldrh\tr4, [r4, #4]\n"
    "    cmp\tr0, r4\n"
    "    bcc .Lus_0803584A\n"
    "    strb\tr1, [r3, #0]\n"
    "    mov\tr5, sl\n"
    "    cmp\tr5, #0\n"
    "    beq .Lus_08035844\n"
    "    ldr\tr7, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r7, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r7, #0]\n"
    ".Lus_08035844:\n"
    "    movs\tr0, #2\n"
    "    str\tr0, [sp, #120]\t@ 0x78\n"
    "    b .Lus_08035862\n"
    ".Lus_0803584A:\n"
    "    movs\tr1, #1\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    "    b .Lus_08035862\n"
    ".Lus_08035850:\n"
    "    movs\tr0, #1\n"
    "    ldr\tr2, [sp, #184]\t@ 0xb8\n"
    "    strh\tr0, [r2, #0]\n"
    "    movs\tr3, #1\n"
    "    str\tr3, [sp, #120]\t@ 0x78\n"
    "    b .Lus_08035862\n"
    ".Lus_0803585C:\n"
    "    ldr\tr4, [sp, #164]\t@ 0xa4\n"
    "    ldr\tr5, [sp, #152]\t@ 0x98\n"
    "    str\tr4, [r5, #0]\n"
    ".Lus_08035862:\n"
    "    ldr\tr0, [sp, #56]\t@ 0x38\n"
    "    str\tr0, [r6, #8]\n"
    "    ldr\tr0, [sp, #64]\t@ 0x40\n"
    "    str\tr0, [r6, #12]\n"
    "    ldr\tr0, [sp, #60]\t@ 0x3c\n"
    "    str\tr0, [r6, #24]\n"
    "    ldr\tr0, [sp, #68]\t@ 0x44\n"
    "    str\tr0, [r6, #28]\n"
    "    b .Lus_080358E6\n"
    ".Lus_08035874:\n"
    "    mov\tr7, sl\n"
    "    cmp\tr7, #0\n"
    "    bne .Lus_0803588A\n"
    "    adds\tr0, #1\n"
    "    strh\tr0, [r1, #0]\n"
    "    lsls\tr0, r0, #16\n"
    "    lsrs\tr0, r0, #16\n"
    "    ldr\tr2, [sp, #148]\t@ 0x94\n"
    "    ldrh\tr2, [r2, #4]\n"
    "    cmp\tr0, r2\n"
    "    bls .Lus_080358E6\n"
    ".Lus_0803588A:\n"
    "    movs\tr0, #0\n"
    "    strh\tr0, [r1, #0]\n"
    "    ldr\tr3, [sp, #180]\t@ 0xb4\n"
    "    ldrb\tr0, [r3, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r3, #0]\n"
    "    lsls\tr0, r0, #24\n"
    "    lsrs\tr0, r0, #24\n"
    "    ldr\tr4, [sp, #116]\t@ 0x74\n"
    "    ldrh\tr4, [r4, #4]\n"
    "    cmp\tr0, r4\n"
    "    bcc .Lus_080358BA\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r3, #0]\n"
    "    mov\tr5, sl\n"
    "    cmp\tr5, #0\n"
    "    beq .Lus_080358B4\n"
    ".Lus_080358AC:\n"
    "    ldr\tr7, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r7, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r7, #0]\n"
    ".Lus_080358B4:\n"
    "    movs\tr0, #2\n"
    "    str\tr0, [sp, #120]\t@ 0x78\n"
    "    b .Lus_080358EC\n"
    ".Lus_080358BA:\n"
    "    movs\tr1, #1\n"
    "    str\tr1, [sp, #120]\t@ 0x78\n"
    "    b .Lus_080358EC\n"
    ".Lus_080358C0:\n"
    "    ldr\tr2, [sp, #176]\t@ 0xb0\n"
    "    ldrb\tr0, [r2, #0]\n"
    "    adds\tr0, #1\n"
    "    ldr\tr3, [sp, #112]\t@ 0x70\n"
    "    ldrh\tr3, [r3, #0]\n"
    "    cmp\tr0, r3\n"
    "    bge .Lus_080358E6\n"
    "    ldrh\tr7, [r7, #8]\n"
    "    cmp\tr1, r7\n"
    "    bcc .Lus_080358E6\n"
    "    adds\tr1, r6, #0\n"
    "    adds\tr1, #62\t@ 0x3e\n"
    "    movs\tr0, #0\n"
    "    strb\tr0, [r1, #0]\n"
    "    ldrb\tr0, [r2, #0]\n"
    "    adds\tr0, #1\n"
    "    strb\tr0, [r2, #0]\n"
    "    movs\tr4, #2\n"
    "    str\tr4, [sp, #120]\t@ 0x78\n"
    ".Lus_080358E6:\n"
    "    ldr\tr5, [sp, #120]\t@ 0x78\n"
    "    cmp\tr5, #0\n"
    "    ble .Lus_080358F8\n"
    ".Lus_080358EC:\n"
    "    ldr\tr0, [r6, #20]\n"
    "    ldr\tr2, [r0, #60]\t@ 0x3c\n"
    "    adds\tr0, r6, #0\n"
    "    ldr\tr1, [sp, #120]\t@ 0x78\n"
    "    bl _call_via_r2\n"
    ".Lus_080358F8:\n"
    "    add\tsp, #188\t@ 0xbc\n"
    "    pop\t{r3, r4, r5}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    mov\tsl, r5\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r0}\n"
    "    bx\tr0\n"
#endif
#endif
#endif
);

EC void SetNpcIdleAnimation(ANpcEntity & self, u32 animation)
{
    u32 old_animation = self.unk_44;
    if (animation != old_animation) {
        self.unk_44 = animation;
        if (!self.IsNormalUpdateSuspended() && self.anim_id == old_animation) {
            if (self.anim_id != animation)
                self.SetAnim(animation);
        }
    }
}

EC void SetNpcWalkingAnimation(ANpcEntity & self, u32 animation)
{
    u32 old_animation = self.unk_46;
    if (animation != old_animation) {
        self.unk_46 = animation;
        if (!self.IsNormalUpdateSuspended() && self.anim_id == old_animation) {
            if (self.anim_id != animation)
                self.SetAnim(animation);
        }
    }
}

asm_unified(
    ".text\n"
#if defined(REGION_JP)
    "    .align 2, 0\n"
    "\n"
    "    .global IsNpcScheduleTransitionDue\n"
    "    .thumb_func\n"
    "IsNpcScheduleTransitionDue:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, r8\n"
    "    push\t{r7}\n"
    "    adds\tr4, r0, #0\n"
    "    ldr\tr0, [r4, #20]\n"
    "    ldr\tr1, [r0, #40]\t@ 0x28\n"
    "    adds\tr0, r4, #0\n"
    "    bl _call_via_r1\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Ljp_080357CE\n"
    "    ldr\tr1, [r4, #56]\t@ 0x38\n"
    "    cmp\tr1, #0\n"
    "    beq .Ljp_080357CE\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr0, #60\t@ 0x3c\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    ldr\tr1, [r1, #8]\n"
    "    lsls\tr0, r0, #2\n"
    "    adds\tr0, r0, r1\n"
    "    ldr\tr6, [r0, #0]\n"
    "    cmp\tr6, #0\n"
    "    beq .Ljp_080357CE\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr0, #61\t@ 0x3d\n"
    "    ldrb\tr1, [r0, #0]\n"
    "    mov\tr8, r0\n"
    "    ldrh\tr0, [r6, #0]\n"
    "    cmp\tr1, r0\n"
    "    bcs .Ljp_080357CE\n"
    "    lsls\tr1, r1, #3\n"
    "    ldr\tr0, [r6, #4]\n"
    "    adds\tr7, r0, r1\n"
    "    ldr\tr5, [r7, #4]\n"
    "    cmp\tr5, #0\n"
    "    beq .Ljp_080357CE\n"
    "    ldr\tr0, [r4, #0]\n"
    "    ldr\tr1, [r0, #0]\n"
    "    movs\tr2, #162\t@ 0xa2\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr1, r1, r2\n"
    "    ldr\tr1, [r1, #0]\n"
    "    bl _call_via_r1\n"
    "    ldrh\tr1, [r0, #10]\n"
    "    lsls\tr0, r1, #27\n"
    "    lsrs\tr0, r0, #27\n"
    "    subs\tr2, r0, #6\n"
    "    cmp\tr2, #0\n"
    "    bge .Ljp_08035774\n"
    "    adds\tr2, #24\n"
    ".Ljp_08035774:\n"
    "    lsls\tr0, r2, #4\n"
    "    subs\tr0, r0, r2\n"
    "    lsls\tr0, r0, #2\n"
    "    lsls\tr1, r1, #21\n"
    "    lsrs\tr1, r1, #26\n"
    "    adds\tr1, r0, r1\n"
    "    ldr\tr0, [r5, #0]\n"
    "    cmp\tr0, #0\n"
    "    beq .Ljp_080357B4\n"
    "    ldrh\tr2, [r5, #4]\n"
    "    cmp\tr2, #0\n"
    "    beq .Ljp_080357B4\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr0, #62\t@ 0x3e\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    cmp\tr0, r2\n"
    "    bcs .Ljp_080357CE\n"
    "    ldrb\tr0, [r5, #11]\n"
    "    lsls\tr0, r0, #27\n"
    "    cmp\tr0, #0\n"
    "    blt .Ljp_080357B4\n"
    "    movs\tr2, #0\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr0, #64\t@ 0x40\n"
    "    ldrh\tr1, [r0, #0]\n"
    "    ldr r0, .Ljp_080357B0\n"
    "    cmp\tr1, r0\n"
    "    blt .Ljp_080357CA\n"
    "    b .Ljp_080357C8\n"
    "    .align 2, 0\n"
    ".Ljp_080357B0:\n"
    "    .word 0x000002EE\n"
    ".Ljp_080357B4:\n"
    "    movs\tr2, #0\n"
    "    mov\tr3, r8\n"
    "    ldrb\tr0, [r3, #0]\n"
    "    adds\tr0, #1\n"
    "    ldrh\tr6, [r6, #0]\n"
    "    cmp\tr0, r6\n"
    "    bge .Ljp_080357CA\n"
    "    ldrh\tr7, [r7, #8]\n"
    "    cmp\tr1, r7\n"
    "    bcc .Ljp_080357CA\n"
    ".Ljp_080357C8:\n"
    "    movs\tr2, #1\n"
    ".Ljp_080357CA:\n"
    "    adds\tr0, r2, #0\n"
    "    b .Ljp_080357D0\n"
    ".Ljp_080357CE:\n"
    "    movs\tr0, #0\n"
    ".Ljp_080357D0:\n"
    "    pop\t{r3}\n"
    "    mov\tr8, r3\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
#if defined(REGION_EU)
    "    .align 2, 0\n"
    "\n"
    "    .global IsNpcScheduleTransitionDue\n"
    "    .thumb_func\n"
    "IsNpcScheduleTransitionDue:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, r8\n"
    "    push\t{r7}\n"
    "    adds\tr4, r0, #0\n"
    "    ldr\tr0, [r4, #20]\n"
    "    ldr\tr1, [r0, #40]\t@ 0x28\n"
    "    adds\tr0, r4, #0\n"
    "    bl _call_via_r1\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Leu_08035A4E\n"
    "    ldr\tr1, [r4, #56]\t@ 0x38\n"
    "    cmp\tr1, #0\n"
    "    beq .Leu_08035A4E\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr0, #60\t@ 0x3c\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    ldr\tr1, [r1, #8]\n"
    "    lsls\tr0, r0, #2\n"
    "    adds\tr0, r0, r1\n"
    "    ldr\tr6, [r0, #0]\n"
    "    cmp\tr6, #0\n"
    "    beq .Leu_08035A4E\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr0, #61\t@ 0x3d\n"
    "    ldrb\tr1, [r0, #0]\n"
    "    mov\tr8, r0\n"
    "    ldrh\tr0, [r6, #0]\n"
    "    cmp\tr1, r0\n"
    "    bcs .Leu_08035A4E\n"
    "    lsls\tr1, r1, #3\n"
    "    ldr\tr0, [r6, #4]\n"
    "    adds\tr7, r0, r1\n"
    "    ldr\tr5, [r7, #4]\n"
    "    cmp\tr5, #0\n"
    "    beq .Leu_08035A4E\n"
    "    ldr\tr0, [r4, #0]\n"
    "    ldr\tr1, [r0, #0]\n"
    "    movs\tr2, #162\t@ 0xa2\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr1, r1, r2\n"
    "    ldr\tr1, [r1, #0]\n"
    "    bl _call_via_r1\n"
    "    ldrh\tr1, [r0, #10]\n"
    "    lsls\tr0, r1, #27\n"
    "    lsrs\tr0, r0, #27\n"
    "    subs\tr2, r0, #6\n"
    "    cmp\tr2, #0\n"
    "    bge .Leu_080359F4\n"
    "    adds\tr2, #24\n"
    ".Leu_080359F4:\n"
    "    lsls\tr0, r2, #4\n"
    "    subs\tr0, r0, r2\n"
    "    lsls\tr0, r0, #2\n"
    "    lsls\tr1, r1, #21\n"
    "    lsrs\tr1, r1, #26\n"
    "    adds\tr1, r0, r1\n"
    "    ldr\tr0, [r5, #0]\n"
    "    cmp\tr0, #0\n"
    "    beq .Leu_08035A34\n"
    "    ldrh\tr2, [r5, #4]\n"
    "    cmp\tr2, #0\n"
    "    beq .Leu_08035A34\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr0, #62\t@ 0x3e\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    cmp\tr0, r2\n"
    "    bcs .Leu_08035A4E\n"
    "    ldrb\tr0, [r5, #11]\n"
    "    lsls\tr0, r0, #27\n"
    "    cmp\tr0, #0\n"
    "    blt .Leu_08035A34\n"
    "    movs\tr2, #0\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr0, #64\t@ 0x40\n"
    "    ldrh\tr1, [r0, #0]\n"
    "    ldr r0, .Leu_08035A30\n"
    "    cmp\tr1, r0\n"
    "    blt .Leu_08035A4A\n"
    "    b .Leu_08035A48\n"
    "    .align 2, 0\n"
    ".Leu_08035A30:\n"
    "    .word 0x000002EE\n"
    ".Leu_08035A34:\n"
    "    movs\tr2, #0\n"
    "    mov\tr3, r8\n"
    "    ldrb\tr0, [r3, #0]\n"
    "    adds\tr0, #1\n"
    "    ldrh\tr6, [r6, #0]\n"
    "    cmp\tr0, r6\n"
    "    bge .Leu_08035A4A\n"
    "    ldrh\tr7, [r7, #8]\n"
    "    cmp\tr1, r7\n"
    "    bcc .Leu_08035A4A\n"
    ".Leu_08035A48:\n"
    "    movs\tr2, #1\n"
    ".Leu_08035A4A:\n"
    "    adds\tr0, r2, #0\n"
    "    b .Leu_08035A50\n"
    ".Leu_08035A4E:\n"
    "    movs\tr0, #0\n"
    ".Leu_08035A50:\n"
    "    pop\t{r3}\n"
    "    mov\tr8, r3\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    movs\tr0, r0\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_DE)
#if defined(REGION_DE)
    "    .align 2, 0\n"
    "\n"
    "    .global IsNpcScheduleTransitionDue\n"
    "    .thumb_func\n"
    "IsNpcScheduleTransitionDue:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, r8\n"
    "    push\t{r7}\n"
    "    adds\tr4, r0, #0\n"
    "    ldr\tr0, [r4, #20]\n"
    "    ldr\tr1, [r0, #40]\t@ 0x28\n"
    "    adds\tr0, r4, #0\n"
    "    bl _call_via_r1\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Lde_0803594E\n"
    "    ldr\tr1, [r4, #56]\t@ 0x38\n"
    "    cmp\tr1, #0\n"
    "    beq .Lde_0803594E\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr0, #60\t@ 0x3c\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    ldr\tr1, [r1, #8]\n"
    "    lsls\tr0, r0, #2\n"
    "    adds\tr0, r0, r1\n"
    "    ldr\tr6, [r0, #0]\n"
    "    cmp\tr6, #0\n"
    "    beq .Lde_0803594E\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr0, #61\t@ 0x3d\n"
    "    ldrb\tr1, [r0, #0]\n"
    "    mov\tr8, r0\n"
    "    ldrh\tr0, [r6, #0]\n"
    "    cmp\tr1, r0\n"
    "    bcs .Lde_0803594E\n"
    "    lsls\tr1, r1, #3\n"
    "    ldr\tr0, [r6, #4]\n"
    "    adds\tr7, r0, r1\n"
    "    ldr\tr5, [r7, #4]\n"
    "    cmp\tr5, #0\n"
    "    beq .Lde_0803594E\n"
    "    ldr\tr0, [r4, #0]\n"
    "    ldr\tr1, [r0, #0]\n"
    "    movs\tr2, #162\t@ 0xa2\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr1, r1, r2\n"
    "    ldr\tr1, [r1, #0]\n"
    "    bl _call_via_r1\n"
    "    ldrh\tr1, [r0, #10]\n"
    "    lsls\tr0, r1, #27\n"
    "    lsrs\tr0, r0, #27\n"
    "    subs\tr2, r0, #6\n"
    "    cmp\tr2, #0\n"
    "    bge .Lde_080358F4\n"
    "    adds\tr2, #24\n"
    ".Lde_080358F4:\n"
    "    lsls\tr0, r2, #4\n"
    "    subs\tr0, r0, r2\n"
    "    lsls\tr0, r0, #2\n"
    "    lsls\tr1, r1, #21\n"
    "    lsrs\tr1, r1, #26\n"
    "    adds\tr1, r0, r1\n"
    "    ldr\tr0, [r5, #0]\n"
    "    cmp\tr0, #0\n"
    "    beq .Lde_08035934\n"
    "    ldrh\tr2, [r5, #4]\n"
    "    cmp\tr2, #0\n"
    "    beq .Lde_08035934\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr0, #62\t@ 0x3e\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    cmp\tr0, r2\n"
    "    bcs .Lde_0803594E\n"
    "    ldrb\tr0, [r5, #11]\n"
    "    lsls\tr0, r0, #27\n"
    "    cmp\tr0, #0\n"
    "    blt .Lde_08035934\n"
    "    movs\tr2, #0\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr0, #64\t@ 0x40\n"
    "    ldrh\tr1, [r0, #0]\n"
    "    ldr r0, .Lde_08035930\n"
    "    cmp\tr1, r0\n"
    "    blt .Lde_0803594A\n"
    "    b .Lde_08035948\n"
    "    .align 2, 0\n"
    ".Lde_08035930:\n"
    "    .word 0x000002EE\n"
    ".Lde_08035934:\n"
    "    movs\tr2, #0\n"
    "    mov\tr3, r8\n"
    "    ldrb\tr0, [r3, #0]\n"
    "    adds\tr0, #1\n"
    "    ldrh\tr6, [r6, #0]\n"
    "    cmp\tr0, r6\n"
    "    bge .Lde_0803594A\n"
    "    ldrh\tr7, [r7, #8]\n"
    "    cmp\tr1, r7\n"
    "    bcc .Lde_0803594A\n"
    ".Lde_08035948:\n"
    "    movs\tr2, #1\n"
    ".Lde_0803594A:\n"
    "    adds\tr0, r2, #0\n"
    "    b .Lde_08035950\n"
    ".Lde_0803594E:\n"
    "    movs\tr0, #0\n"
    ".Lde_08035950:\n"
    "    pop\t{r3}\n"
    "    mov\tr8, r3\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    "    .align 2, 0\n"
    "\n"
    "    .global IsNpcScheduleTransitionDue\n"
    "    .thumb_func\n"
    "IsNpcScheduleTransitionDue:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, r8\n"
    "    push\t{r7}\n"
    "    adds\tr4, r0, #0\n"
    "    ldr\tr0, [r4, #20]\n"
    "    ldr\tr1, [r0, #40]\t@ 0x28\n"
    "    adds\tr0, r4, #0\n"
    "    bl _call_via_r1\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Lus_08035A3A\n"
    "    ldr\tr1, [r4, #56]\t@ 0x38\n"
    "    cmp\tr1, #0\n"
    "    beq .Lus_08035A3A\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr0, #60\t@ 0x3c\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    ldr\tr1, [r1, #8]\n"
    "    lsls\tr0, r0, #2\n"
    "    adds\tr0, r0, r1\n"
    "    ldr\tr6, [r0, #0]\n"
    "    cmp\tr6, #0\n"
    "    beq .Lus_08035A3A\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr0, #61\t@ 0x3d\n"
    "    ldrb\tr1, [r0, #0]\n"
    "    mov\tr8, r0\n"
    "    ldrh\tr0, [r6, #0]\n"
    "    cmp\tr1, r0\n"
    "    bcs .Lus_08035A3A\n"
    "    lsls\tr1, r1, #3\n"
    "    ldr\tr0, [r6, #4]\n"
    "    adds\tr7, r0, r1\n"
    "    ldr\tr5, [r7, #4]\n"
    "    cmp\tr5, #0\n"
    "    beq .Lus_08035A3A\n"
    "    ldr\tr0, [r4, #0]\n"
    "    ldr\tr1, [r0, #0]\n"
    "    movs\tr2, #162\t@ 0xa2\n"
    "    lsls\tr2, r2, #1\n"
    "    adds\tr1, r1, r2\n"
    "    ldr\tr1, [r1, #0]\n"
    "    bl _call_via_r1\n"
    "    ldrh\tr1, [r0, #10]\n"
    "    lsls\tr0, r1, #27\n"
    "    lsrs\tr0, r0, #27\n"
    "    subs\tr2, r0, #6\n"
    "    cmp\tr2, #0\n"
    "    bge .Lus_080359E0\n"
    "    adds\tr2, #24\n"
    ".Lus_080359E0:\n"
    "    lsls\tr0, r2, #4\n"
    "    subs\tr0, r0, r2\n"
    "    lsls\tr0, r0, #2\n"
    "    lsls\tr1, r1, #21\n"
    "    lsrs\tr1, r1, #26\n"
    "    adds\tr1, r0, r1\n"
    "    ldr\tr0, [r5, #0]\n"
    "    cmp\tr0, #0\n"
    "    beq .Lus_08035A20\n"
    "    ldrh\tr2, [r5, #4]\n"
    "    cmp\tr2, #0\n"
    "    beq .Lus_08035A20\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr0, #62\t@ 0x3e\n"
    "    ldrb\tr0, [r0, #0]\n"
    "    cmp\tr0, r2\n"
    "    bcs .Lus_08035A3A\n"
    "    ldrb\tr0, [r5, #11]\n"
    "    lsls\tr0, r0, #27\n"
    "    cmp\tr0, #0\n"
    "    blt .Lus_08035A20\n"
    "    movs\tr2, #0\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr0, #64\t@ 0x40\n"
    "    ldrh\tr1, [r0, #0]\n"
    "    ldr r0, .Lus_08035A1C\n"
    "    cmp\tr1, r0\n"
    "    blt .Lus_08035A36\n"
    "    b .Lus_08035A34\n"
    "    .align 2, 0\n"
    ".Lus_08035A1C:\n"
    "    .word 0x000002EE\n"
    ".Lus_08035A20:\n"
    "    movs\tr2, #0\n"
    "    mov\tr3, r8\n"
    "    ldrb\tr0, [r3, #0]\n"
    "    adds\tr0, #1\n"
    "    ldrh\tr6, [r6, #0]\n"
    "    cmp\tr0, r6\n"
    "    bge .Lus_08035A36\n"
    "    ldrh\tr7, [r7, #8]\n"
    "    cmp\tr1, r7\n"
    "    bcc .Lus_08035A36\n"
    ".Lus_08035A34:\n"
    "    movs\tr2, #1\n"
    ".Lus_08035A36:\n"
    "    adds\tr0, r2, #0\n"
    "    b .Lus_08035A3C\n"
    ".Lus_08035A3A:\n"
    "    movs\tr0, #0\n"
    ".Lus_08035A3C:\n"
    "    pop\t{r3}\n"
    "    mov\tr8, r3\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
#endif
#endif
#endif
);

EC void PauseNpcNearLocation(ANpcEntity & self, Location const & other)
{
    u32 map = self.location_map;
    if (map != other.map)
        return;
    i32 x = self.x_q16 >> 16;
    i32 dx = other.x - x;
    if (dx < 0)
        dx = -dx;
    if (dx > 151)
        return;
    i32 y = self.y_q16 >> 16;
    i32 dy = other.y - y;
    if (dy < 0)
        dy = -dy;
    if (dy > 111)
        return;
    if (!IsNpcScheduleTransitionDue(self) && !self.IsNormalUpdateSuspended()) {
        StartActorSpriteEffect(self, ENTITY_EMOTE_EXCLAMATION, false);
        self.unk_3F = 120;
        self.UpdateSchedule(1);
    }
}

EC bool IsNpcInUpperFarmhouseStrip(ANpcEntity & self)
{
    bool result = false;
    if (self.location_map == MAP_FARMHOUSE && (self.y_q16 >> 16) <= 55)
        result = true;
    return result;
}

asm_unified(
    ".text\n"
);

LilliaNpcActor::LilliaNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gLilliaScheduleData.descriptor,
        607, 611, EventScript_0994_NPCEvent_Lillia_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * LilliaNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 0, 0, false);
}

RickNpcActor::RickNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gRickScheduleData.descriptor,
        531, 535, EventScript_0992_NPCEvent_Rick_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * RickNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 0, 0, false);
}

PopuriNpcActor::PopuriNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gPopuriScheduleData.descriptor,
        559, 563, EventScript_0993_NPCEvent_Popuri_DialogueAndGiftResponses)
{
}

EC void RefreshPopuriNpcAnimations(ANpcEntity & self)
{
    u32 idle = ANIMATION_POPURI_IDLE;
    u32 walk = ANIMATION_POPURI_WALK;
    GameStateSaveImage const * game = static_cast<GameStateSaveImage const *>(self.schedule_context);
    NpcCollection const & npcs = game->npcs;
    if (npcs.GetSpouseCharacterId() == CHARACTER_POPURI && self.location_map == MAP_FARMHOUSE) {
        if (IsNpcInUpperFarmhouseStrip(self) || game->event_state.popuri_spouse_collapse_event_state == 1) {
            idle = ANIMATION_POPURI_IN_BED;
        } else {
            Child const * child = npcs.GetChild();
            if (child != nullptr && child->GetAgeDays() < CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START) {
                if (IsChildScheduleOutsideFarmhouse(game, self.game_object->GetClock()->calendar.time)) {
                    idle = ANIMATION_POPURI_WITH_NEWBORN;
                    walk = ANIMATION_ID_0587;
                }
            }
        }
    }
    SetNpcIdleAnimation(self, idle);
    SetNpcWalkingAnimation(self, walk);
}

void PopuriNpcActor::UpdateSchedule(i32 time)
{
    ANpcEntity::UpdateSchedule(time);
    if (time > 1)
        RefreshPopuriNpcAnimations(*this);
}

EntityVisualController * PopuriNpcActor::CreateVisualController()
{
    RefreshPopuriNpcAnimations(*this);
    return new EntitySpriteController(this, 5, 27, 1, 0, 0, false);
}

BarleyNpcActor::BarleyNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gBarleyScheduleData,
        2543, 2547, EventScript_1030_NPCEvent_Barley_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * BarleyNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 3, 0, false);
}

MayNpcActor::MayNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gMayScheduleData,
        2535, 2539, EventScript_1029_NPCEvent_May_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * MayNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 1, 0, false);
}

SaibaraNpcActor::SaibaraNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gSaibaraScheduleData,
        2465, 2469, EventScript_1027_NPCEvent_Saibara_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * SaibaraNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 0, 0, false);
}

GrayNpcActor::GrayNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gGrayScheduleData,
        2441, 2445, EventScript_1026_NPCEvent_Gray_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * GrayNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 2, 0, false);
}

DukeNpcActor::DukeNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gDukeScheduleData,
        2240, 2244, EventScript_1020_NPCEvent_Duke_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * DukeNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 0, 0, false);
}

MannaNpcActor::MannaNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gMannaScheduleData,
        2256, 2260, EventScript_1021_NPCEvent_Manna_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * MannaNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 0, 0, false);
}

BasilNpcActor::BasilNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gBasilScheduleData,
        2059, 2063, EventScript_1013_NPCEvent_Basil_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * BasilNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 2, 0, false);
}

AnnaNpcActor::AnnaNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gAnnaScheduleData,
        2123, 2127, EventScript_1015_NPCEvent_Anna_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * AnnaNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 0, 0, false);
}

MaryNpcActor::MaryNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gMaryScheduleData,
        2067, 2071, EventScript_1014_NPCEvent_Mary_DialogueAndGiftResponses)
{
}

EC void RefreshMaryNpcAnimations(ANpcEntity & self)
{
    u32 idle = ANIMATION_MARY_IDLE;
    u32 walk = ANIMATION_MARY_WALK;
    GameStateSaveImage const * game = static_cast<GameStateSaveImage const *>(self.schedule_context);
    NpcCollection const & npcs = game->npcs;
    if (npcs.GetSpouseCharacterId() == CHARACTER_MARY && self.location_map == MAP_FARMHOUSE) {
        if (IsNpcInUpperFarmhouseStrip(self) || game->event_state.mary_spouse_collapse_event_state == 1) {
            idle = ANIMATION_MARY_IN_BED;
        } else {
            Child const * child = npcs.GetChild();
            if (child != nullptr && child->GetAgeDays() < CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START) {
                if (IsChildScheduleOutsideFarmhouse(game, self.game_object->GetClock()->calendar.time)) {
                    idle = ANIMATION_MARY_WITH_NEWBORN;
                    walk = ANIMATION_ID_2099;
                }
            }
        }
    }
    SetNpcIdleAnimation(self, idle);
    SetNpcWalkingAnimation(self, walk);
}

void MaryNpcActor::UpdateSchedule(i32 time)
{
    ANpcEntity::UpdateSchedule(time);
    if (time > 1)
        RefreshMaryNpcAnimations(*this);
}

EntityVisualController * MaryNpcActor::CreateVisualController()
{
    RefreshMaryNpcAnimations(*this);
    return new EntitySpriteController(this, 5, 27, 1, 0, 0, false);
}

ThomasNpcActor::ThomasNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gThomasScheduleData,
        2143, 2147, EventScript_1017_NPCEvent_Thomas_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * ThomasNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 0, 0, false);
}

HarrisNpcActor::HarrisNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gHarrisScheduleData,
        2276, 2280, EventScript_1023_NPCEvent_Harris_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * HarrisNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 2, 0, false);
}

EllenNpcActor::EllenNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gEllenScheduleData,
        1669, 1669, EventScript_1006_NPCEvent_Ellen_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * EllenNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 2, 0, false);
}

StuNpcActor::StuNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gStuScheduleData,
        2232, 2236, EventScript_1019_NPCEvent_Stu_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * StuNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 1, 0, false);
}

JeffNpcActor::JeffNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gJeffScheduleData,
        1673, 1677, EventScript_1007_NPCEvent_Jeff_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * JeffNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 0, 0, false);
}

SashaNpcActor::SashaNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gSashaScheduleData,
        1733, 1737, EventScript_1009_NPCEvent_Sasha_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * SashaNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 0, 0, false);
}

KarenNpcActor::KarenNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gKarenScheduleData,
        1681, 1685, EventScript_1008_NPCEvent_Karen_DialogueAndGiftResponses)
{
}

EC void RefreshKarenNpcAnimations(ANpcEntity & self)
{
    u32 idle = ANIMATION_KAREN_IDLE;
    u32 walk = ANIMATION_KAREN_WALK;
    GameStateSaveImage const * game = static_cast<GameStateSaveImage const *>(self.schedule_context);
    NpcCollection const & npcs = game->npcs;
    if (npcs.GetSpouseCharacterId() == CHARACTER_KAREN && self.location_map == MAP_FARMHOUSE) {
        if (IsNpcInUpperFarmhouseStrip(self) || game->event_state.karen_spouse_collapse_event_state == 1) {
            idle = ANIMATION_KAREN_IN_BED;
        } else {
            Child const * child = npcs.GetChild();
            if (child != nullptr && child->GetAgeDays() < CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START) {
                if (IsChildScheduleOutsideFarmhouse(game, self.game_object->GetClock()->calendar.time)) {
                    idle = ANIMATION_KAREN_WITH_NEWBORN;
                    walk = ANIMATION_ID_1713;
                }
            }
        }
    }
    SetNpcIdleAnimation(self, idle);
    SetNpcWalkingAnimation(self, walk);
}

void KarenNpcActor::UpdateSchedule(i32 time)
{
    ANpcEntity::UpdateSchedule(time);
    if (time > 1)
        RefreshKarenNpcAnimations(*this);
}

EntityVisualController * KarenNpcActor::CreateVisualController()
{
    RefreshKarenNpcAnimations(*this);
    return new EntitySpriteController(this, 5, 27, 1, 0, 0, false);
}

DoctorNpcActor::DoctorNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gDoctorScheduleData.descriptor,
        800, 804, EventScript_0998_NPCEvent_Doctor_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * DoctorNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 0, 0, false);
}

ElliNpcActor::ElliNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gElliScheduleData,
        2180, 2184, EventScript_1018_NPCEvent_Elli_DialogueAndGiftResponses)
{
}

EC void RefreshElliNpcAnimations(ANpcEntity & self)
{
    u32 idle = ANIMATION_ELLI_IDLE;
    u32 walk = ANIMATION_ELLI_WALK;
    GameStateSaveImage const * game = static_cast<GameStateSaveImage const *>(self.schedule_context);
    NpcCollection const & npcs = game->npcs;
    if (npcs.GetSpouseCharacterId() == CHARACTER_ELLI && self.location_map == MAP_FARMHOUSE) {
        if (IsNpcInUpperFarmhouseStrip(self) || game->event_state.elli_spouse_collapse_event_state == 1) {
            idle = ANIMATION_ELLI_IN_BED;
        } else {
            Child const * child = npcs.GetChild();
            if (child != nullptr && child->GetAgeDays() < CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START) {
                if (IsChildScheduleOutsideFarmhouse(game, self.game_object->GetClock()->calendar.time)) {
                    idle = ANIMATION_ELLI_WITH_NEWBORN;
                    walk = ANIMATION_ID_2200;
                }
            }
        }
    }
    SetNpcIdleAnimation(self, idle);
    SetNpcWalkingAnimation(self, walk);
}

void ElliNpcActor::UpdateSchedule(i32 time)
{
    ANpcEntity::UpdateSchedule(time);
    if (time > 1)
        RefreshElliNpcAnimations(*this);
}

EntityVisualController * ElliNpcActor::CreateVisualController()
{
    RefreshElliNpcAnimations(*this);
    return new EntitySpriteController(this, 5, 27, 1, 0, 0, false);
}

CarterNpcActor::CarterNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gCarterScheduleData,
        2284, 2288, EventScript_1024_NPCEvent_Carter_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * CarterNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 0, 0, false);
}

CliffNpcActor::CliffNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gCliffScheduleData.descriptor,
        635, 639, EventScript_0996_NPCEvent_Cliff_DialogueAndGiftResponses)
{
}

EC void RefreshCliffNpcAnimations(ANpcEntity & self)
{
    u32 idle = ANIMATION_CLIFF_IDLE;
    u32 walk = ANIMATION_CLIFF_WALK;
    u32 priority = 2;
    GameStateSaveImage const * game = static_cast<GameStateSaveImage const *>(self.schedule_context);
    if (game->event_state.cliff_collapse_followup_event_state == EVENT_LIFECYCLE_IN_PROGRESS) {
        idle = ANIMATION_CLIFF_HOSPITAL_BED_IDLE;
        priority = 1;
    }
    SetNpcIdleAnimation(self, idle);
    SetNpcWalkingAnimation(self, walk);
    self.SetObjPriority(priority);
}

void CliffNpcActor::UpdateSchedule(i32 time)
{
    ANpcEntity::UpdateSchedule(time);
    if (time > 1)
        RefreshCliffNpcAnimations(*this);
}

EntityVisualController * CliffNpcActor::CreateVisualController()
{
    RefreshCliffNpcAnimations(*this);
    return new EntitySpriteController(this, 5, 27, 1, 0, 0, false);
}

DougNpcActor::DougNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gDougScheduleData,
        1970, 1974, EventScript_1010_NPCEvent_Doug_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * DougNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 0, 0, false);
}

LouOrRubyNpcActor::LouOrRubyNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gLouScheduleData,
        2034, 2038, EventScript_1012_NPCEvent_LouOrRuby_DailyDialogueAndCookingRecipes)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * LouOrRubyNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 0, 0, false);
}

AnnNpcActor::AnnNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gAnnScheduleData,
        1982, 1986, EventScript_1011_NPCEvent_Ann_DialogueAndGiftResponses)
{
}

EC void RefreshAnnNpcAnimations(ANpcEntity & self)
{
    u32 idle = ANIMATION_ANN_IDLE;
    u32 walk = ANIMATION_ANN_WALK;
    GameStateSaveImage const * game = static_cast<GameStateSaveImage const *>(self.schedule_context);
    NpcCollection const & npcs = game->npcs;
    if (npcs.GetSpouseCharacterId() == CHARACTER_ANN && self.location_map == MAP_FARMHOUSE) {
        if (IsNpcInUpperFarmhouseStrip(self) || game->event_state.ann_spouse_collapse_event_state == 1) {
            idle = ANIMATION_ANN_IN_BED;
        } else {
            Child const * child = npcs.GetChild();
            if (child != nullptr && child->GetAgeDays() < CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START) {
                if (IsChildScheduleOutsideFarmhouse(game, self.game_object->GetClock()->calendar.time)) {
                    idle = ANIMATION_ANN_WITH_NEWBORN;
                    walk = ANIMATION_ID_1998;
                }
            }
        }
    }
    SetNpcIdleAnimation(self, idle);
    SetNpcWalkingAnimation(self, walk);
}

void AnnNpcActor::UpdateSchedule(i32 time)
{
    ANpcEntity::UpdateSchedule(time);
    if (time > 1)
        RefreshAnnNpcAnimations(*this);
}

EntityVisualController * AnnNpcActor::CreateVisualController()
{
    RefreshAnnNpcAnimations(*this);
    return new EntitySpriteController(this, 5, 27, 1, 0, 0, false);
}

KaiNpcActor::KaiNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gKaiScheduleData,
        2306, 2310, EventScript_1025_NPCEvent_Kai_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * KaiNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 0, 0, false);
}

GotzNpcActor::GotzNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gGotzScheduleData,
        2515, 2519, EventScript_1028_NPCEvent_Gotz_DialogueAndGiftResponses)
{
}

EC void RefreshGotzNpcAnimations(ANpcEntity & self)
{
    u32 idle = ANIMATION_GOTZ_IDLE;
    u32 walk = ANIMATION_GOTZ_WALK;
    switch (static_cast<i32>(self.GetMap())) {
    case MAP_SOUTH_SIDE_TOWN:
    case MAP_CHICKEN_COOP:
    case MAP_FARMHOUSE:
    case MAP_BARN:
        idle = ANIMATION_ID_2527;
        walk = ANIMATION_ID_2531;
        break;
    }
    SetNpcIdleAnimation(self, idle);
    SetNpcWalkingAnimation(self, walk);
}

void GotzNpcActor::UpdateSchedule(i32 time)
{
    ANpcEntity::UpdateSchedule(time);
    if (time > 1)
        RefreshGotzNpcAnimations(*this);
}

EntityVisualController * GotzNpcActor::CreateVisualController()
{
    RefreshGotzNpcAnimations(*this);
    return new EntitySpriteController(this, 5, 27, 1, 0, 0, false);
}

ZackNpcActor::ZackNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gZackScheduleData.descriptor,
        792, 796, EventScript_0997_NPCEvent_Zack_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * ZackNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 2, 0, false);
}

void ZackNpcActor::Update(EntityUpdateContext const & context)
{
    i32 old_x = GetQ16X() >> 16;
    i32 old_y = GetQ16Y() >> 16;
    ANpcEntity::Update(context);
    if (location_map == MAP_FARM && (old_x != 244 || old_y != 171)) {
        i32 x = GetQ16X() >> 16;
        i32 y = GetQ16Y() >> 16;
        if (x == 244 && y == 171)
            game_object->vfunc_114();
    }
}

void ZackNpcActor::UpdateSchedule(i32 refresh_kind)
{
    i32 old_x = GetQ16X() >> 16;
    i32 old_y = GetQ16Y() >> 16;
    ANpcEntity::UpdateSchedule(refresh_kind);
    if (refresh_kind > 1 && location_map == MAP_FARM
        && (old_x != 244 || old_y != 171)) {
        i32 x = GetQ16X() >> 16;
        i32 y = GetQ16Y() >> 16;
        if (x == 244 && y == 171)
            game_object->vfunc_114();
    }
}

WonNpcActor::WonNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gWonScheduleData,
        2135, 2139, EventScript_1016_NPCEvent_Won_DialogueAndGiftResponses)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * WonNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 0, 0, false);
}

GourmetNpcActor::GourmetNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        nullptr,
        1657, 1661, EventScript_None)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * GourmetNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 2, 0, false);
}

HarvestGoddessNpcActor::HarvestGoddessNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        nullptr,
        1641, 1645, EventScript_None)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * HarvestGoddessNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 0, 0, false);
}

KappaNpcActor::KappaNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        nullptr,
        2046, 2046, EventScript_None)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * KappaNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 0, 0, false);
}

VanNpcActor::VanNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gVanScheduleData,
        2264, 2268, EventScript_1022_NPCEvent_Van_DialogueGiftAndGameCubeAlbumUnlock)
{
}

asm_unified(
    ".text\n"
);

EntityVisualController * VanNpcActor::CreateVisualController()
{
    return new EntitySpriteController(this, 4, 27, 1, 0, 0, false);
}

ChildNpcActor::ChildNpcActor(GameObject * world, Npc * npc, u32 context)
    : ANpcEntity(world, npc, context,
        &gChildScheduleData.descriptor,
        615, 623, EventScript_0995_NPCEvent_Baby_DialogueAndInteractions),
      idle_animation_countdown(0)
{
}

asm_unified(
    ".text\n"
    ".global func_08036E70\n"
    "    .thumb_func\n"
    "func_08036E70:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    adds\tr4, r0, #0\n"
    "    ldr\tr0, [r4, #52]\t@ 0x34\n"
    "    ldr r1, .Lus_08036EA0\n"
    "    adds\tr0, r0, r1\n"
    "    bl GetChild__C13NpcCollection\n"
    "    adds\tr6, r0, #0\n"
    "    cmp\tr0, #0\n"
    "    beq .Lus_08036EE0\n"
    "    ldr r5, .Lus_08036EA4\n"
    "    ldr r7, .Lus_08036EA8\n"
    "    bl GetAgeDays__C5Child\n"
    "    cmp\tr0, #59\t@ 0x3b\n"
    "    bhi .Lus_08036EAC\n"
    "    adds\tr0, r4, #0\n"
    "    bl IsNpcInUpperFarmhouseStrip\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Lus_08036ED0\n"
    "    movs\tr5, #12\n"
    "    b .Lus_08036ED0\n"
    ".Lus_08036EA0:\n"
    "    .word 0x00001CD4\n"
    ".Lus_08036EA4:\n"
    "    .word 0x00000267\n"
    ".Lus_08036EA8:\n"
    "    .word 0x0000026F\n"
    ".Lus_08036EAC:\n"
    "    adds\tr0, r4, #0\n"
    "    bl IsNpcInUpperFarmhouseStrip\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    beq .Lus_08036EC0\n"
    "    ldr r5, .Lus_08036EBC\n"
    "    b .Lus_08036ED0\n"
    ".Lus_08036EBC:\n"
    "    .word 0x00000277\n"
    ".Lus_08036EC0:\n"
    "    adds\tr0, r6, #0\n"
    "    bl CanWalk__C5Child\n"
    "    lsls\tr0, r0, #24\n"
    "    cmp\tr0, #0\n"
    "    bne .Lus_08036ED0\n"
    "    ldr r5, .Lus_08036EE8\n"
    "    ldr r7, .Lus_08036EEC\n"
    ".Lus_08036ED0:\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr1, r5, #0\n"
    "    bl SetNpcIdleAnimation\n"
    "    adds\tr0, r4, #0\n"
    "    adds\tr1, r7, #0\n"
    "    bl SetNpcWalkingAnimation\n"
    ".Lus_08036EE0:\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r0}\n"
    "    bx\tr0\n"
    "    .align 2, 0\n"
    ".Lus_08036EE8:\n"
    "    .word 0x0000026B\n"
    ".Lus_08036EEC:\n"
    "    .word 0x00000273\n"
);

void ChildNpcActor::UpdateSchedule(i32 time)
{
    ANpcEntity::UpdateSchedule(time);
    if (time > 1)
        func_08036E70(this);
}

EntityVisualController * ChildNpcActor::CreateVisualController()
{
    GameStateSaveImage const * game = static_cast<GameStateSaveImage const *>(schedule_context);
    Child const * child = game->npcs.GetChild();
    if (child != nullptr) {
        func_08036E70(this);
        u32 effect_offset_kind = child->CanWalk() ? 4 : 1;
        return new EntitySpriteController(this, 4, 27, 0, effect_offset_kind, 0, false);
    }
    return nullptr;
}

void ChildNpcActor::Update(EntityUpdateContext const & context)
{
    if (unk_10.Get() != nullptr) {
        GameStateSaveImage const * game = static_cast<GameStateSaveImage const *>(schedule_context);
        Child const * child = game->npcs.GetChild();
        if (child != nullptr && child->GetAgeDays() < 60 && IsNpcInUpperFarmhouseStrip(*this)) {
            if (idle_animation_countdown != 0) {
                --idle_animation_countdown;
            } else {
                ChildIdleAnimationChoice choices[] = {
                    { 50, ANIMATION_CHILD_INFANT_SLEEPING },
                    { 20, ANIMATION_CHILD_NEWBORN },
                    { 20, ANIMATION_ID_0004 },
                    { 10, ANIMATION_ID_0000 },
                };
                u32 draw = rand() % 100;
                for (u32 index = 0; index < ARRAY_COUNT(choices); ++index) {
                    if (draw < choices[index].weight) {
                        SetNpcIdleAnimation(*this, choices[index].animation);
                        break;
                    }
                    draw -= choices[index].weight;
                }
                idle_animation_countdown = rand() % 120 + 120;
            }
        }
    }
    ANpcEntity::Update(context);
}


// This getter has its own native return boundary after the child actor update.
void const * ANpcEntity::GetScheduleContext() const
{
    return schedule_context;
}
