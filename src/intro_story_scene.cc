#include "obj_palette_collection.hh"
#include "intro_story_scene.hh"
#include "game_scene.hh"

#include "hardware_context.hh"
#include "hardware_input.hh"
#include "hardware_display_state.hh"
#include "hardware_dma.hh"
#include "compression.hh"
#include "gbaio.h"
#include "game_state.hh"

#include <new>

inline IntroStoryUiOwner::IntroStoryUiOwner(u32 const & flags)
{
    void * storage = ::operator new(sizeof(UiStateOwner));
    ObjTileCollection shared;
    ObjPaletteCollection resources;
    value = new (storage) UiStateOwner(0, 31, 15, flags, shared, resources);
}

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "thumb_func_start __19IntroStorySceneCoreP18GameStateSaveImage\n"
    "__19IntroStorySceneCoreP18GameStateSaveImage:\n"
    "    push {r4, r5, r6, lr}\n"
    "    mov r6, r8\n"
    "    push {r6}\n"
    "    sub sp, #24\n"
    "    adds r4, r0, #0\n"
    "    adds r5, r1, #0\n"
    "    add r1, sp, #20\n"
    "    movs r0, #30\n"
    "    movs r2, #1\n"
    "    movs r3, #0\n"
    "    mov r8, r3\n"
    "    strh r0, [r1, #0]\n"
    "    strh r2, [r1, #2]\n"
    "    adds r0, r4, #0\n"
    "    bl __15HardwareContextRC29HardwareInputRepeatParameters\n"
    "    ldr r0, .Lscalar_0_0\n"
    "    str r0, [r4, #4]\n"
    "    str r5, [r4, #8]\n"
    "    mov r0, r8\n"
    "    str r0, [r4, #12]\n"
    "    movs r0, #4\n"
    "    bl __builtin_new\n"
    "    adds r6, r0, #0\n"
    "    add r0, sp, #12\n"
    "    bl __17ObjTileCollection\n"
    "    add r5, sp, #16\n"
    "    adds r0, r5, #0\n"
    "    bl __20ObjPaletteCollection\n"
    "    ldr r0, [r4, #12]\n"
    "    str r0, [sp, #0]\n"
    "    add r1, sp, #12\n"
    "    str r1, [sp, #4]\n"
    "    str r5, [sp, #8]\n"
    "    adds r0, r6, #0\n"
    "    movs r1, #0\n"
    "    movs r2, #31\n"
    "    movs r3, #15\n"
    "    bl __12UiStateOwnerUiUiUiUiRC17ObjTileCollectionRC20ObjPaletteCollection\n"
    "    str r0, [r4, #16]\n"
    "    adds r0, r5, #0\n"
    "    movs r1, #2\n"
    "    bl _._20ObjPaletteCollection\n"
    "    add r0, sp, #12\n"
    "    movs r1, #2\n"
    "    bl _._17ObjTileCollection\n"
    "    adds r0, r4, #0\n"
    "    adds r0, #20\n"
    "    movs r1, #1\n"
    "    bl __23HardwareMusicPlayerSlotUc\n"
    "    adds r0, r4, #0\n"
    "    adds r0, #24\n"
    "    movs r1, #0\n"
    "    bl __23HardwareMusicPlayerSlotUc\n"
    "    adds r0, r4, #0\n"
    "    adds r0, #28\n"
    "    movs r1, #2\n"
    "    bl __23HardwareMusicPlayerSlotUc\n"
    "    ldr r2, .Lscalar_0_1\n"
    "    adds r1, r4, r2\n"
    "    ldr r0, .Lscalar_0_2\n"
    "    str r0, [r1, #0]\n"
    "    mov r3, r8\n"
    "    str r3, [r1, #4]\n"
    "    ldr r0, [r4, #16]\n"
    "    movs r1, #11\n"
    "    bl func_08050E98\n"
    "    ldr r1, .Lscalar_0_3\n"
    "    adds r0, r4, r1\n"
    "    mov r2, r8\n"
    "    strh r2, [r0, #0]\n"
    "    ldr r3, .Lscalar_0_4\n"
    "    adds r0, r4, r3\n"
    "    strh r2, [r0, #0]\n"
    "    ldr r0, .Lscalar_0_5\n"
    "    adds r1, r4, r0\n"
    "    movs r0, #2\n"
    "    strh r0, [r1, #0]\n"
    "    ldr r1, .Lscalar_0_6\n"
    "    adds r0, r4, r1\n"
    "    strh r2, [r0, #0]\n"
    "    ldr r0, [r4, #8]\n"
    "    ldr r2, .Lscalar_0_7\n"
    "    adds r0, r0, r2\n"
    "    bl GetName__C6Farmer\n"
    "    ldr r3, .Lscalar_0_8\n"
    "    adds r1, r4, r3\n"
    "    str r0, [r1, #0]\n"
    "    adds r0, r4, #0\n"
    "    add sp, #24\n"
    "    pop {r3}\n"
    "    mov r8, r3\n"
    "    pop {r4, r5, r6}\n"
    "    pop {r1}\n"
    "    bx r1\n"
    ".Lscalar_0_0: .word __vt_19IntroStorySceneCore\n"
    ".Lscalar_0_1: .word 0x00006428\n"
    ".Lscalar_0_2: .word __vt_23IntroStoryTextVariables\n"
    ".Lscalar_0_3: .word 0x00006420\n"
    ".Lscalar_0_4: .word 0x00006422\n"
    ".Lscalar_0_5: .word 0x00006426\n"
    ".Lscalar_0_6: .word 0x00006424\n"
    ".Lscalar_0_7: .word 0x00001bd8\n"
    ".Lscalar_0_8: .word 0x0000642c\n"
);

asm_unified(
    ".text\n"
    ".include \"asm/gba.inc\"\n"
    ".align 2, 0\n"
    "\n"
    "    @ Core animation and graphics still retain their real native code.\n"
    "    @ All regions use these instructions with their actual symbolic resources.\n"
    "\tthumb_func_start RunIntroStorySceneCore\n"
    "RunIntroStorySceneCore: @ 0x0805EE44\n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tmov r7, sl\n"
    "\tmov r6, sb\n"
    "\tmov r5, r8\n"
    "\tpush {r5, r6, r7}\n"
    "\tsub sp, #0x50\n"
    "\tstr r0, [sp, #0x30]\n"
    "\tadds r5, r1, #0\n"
    "\tmovs r0, #0\n"
    "\tstr r0, [sp, #0x34]\n"
    "\tmovs r1, #0\n"
    "\tstr r1, [sp, #0x38]\n"
    "\tadds r0, r5, #0\n"
    "\tbl EnableHardwareForcedBlank\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tmov r1, sp\n"
    "\tmovs r2, #0x3f\n"
    "\tstrh r2, [r1]\n"
    "\tadds r0, #0x50\n"
    "\tstrh r2, [r0]\n"
    "\tmovs r0, #0x10\n"
    "\tbl __builtin_new\n"
    "\tadds r4, r0, #0\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadds r1, r0, #0\n"
    "\tldr r2, [sp, #0x38]\n"
    "\tstr r2, [r4]\n"
    "\tstr r2, [r4, #4]\n"
    "\tldr r0, .L0805EF00 @ =__vt_19HardwareBlendObject\n"
    "\tstr r0, [r4, #8]\n"
    "\tadds r0, r4, #0\n"
    "\tadds r0, #0xc\n"
    "\tbl __23HardwareBlendControllerP20HardwareDisplayState\n"
    "\tstr r4, [sp, #4]\n"
    "\tadds r0, r5, #0\n"
    "\tbl InitializeIntroStoryGraphics\n"
    "\tadds r0, r5, #0\n"
    "\tadds r0, #0x18\n"
    "\tmovs r1, #0x25\n"
    "\tbl Start__23HardwareMusicPlayerSlotUs\n"
    "\tldr r0, [sp, #4]\n"
    "\tldr r1, .L0805EF04 @ =0x00000889\n"
    "\tadds r0, #0xc\n"
    "\tmovs r2, #1\n"
    "\tmovs r3, #0\n"
    "\tbl BeginHardwareBlend\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareCommandList\n"
    "\tldr r2, [r0, #8]\n"
    "\tldr r1, [sp, #4]\n"
    "\tldr r2, [r2, #0x10]\n"
    "\tbl _call_via_r2\n"
    "\tldr r3, .L0805EF08 @ =0x00006422\n"
    "\tadds r1, r5, r3\n"
    "\tmovs r0, #4\n"
    "\tstrh r0, [r1]\n"
    "\tmov r4, sp\n"
    "\tadds r4, #8\n"
    "\tstr r4, [sp, #0x40]\n"
    "\tmov r7, sp\n"
    "\tadds r7, #0x28\n"
    "\tstr r7, [sp, #0x44]\n"
    ".L0805EED8:\n"
    "\tadds r0, r5, #0\n"
    "\tbl UpdateHardwareFrame\n"
    "\tadds r0, r5, #0\n"
    "\tbl UpdateHardwareInput\n"
    "\tldr r1, .L0805EF08 @ =0x00006422\n"
    "\tadds r0, r5, r1\n"
    "\tldrh r0, [r0]\n"
    "\tsubs r0, #1\n"
    "\tlsls r0, r0, #0x10\n"
    "\tasrs r0, r0, #0x10\n"
    "\tcmp r0, #9\n"
    "\tbls .L0805EEF6\n"
    "\tb .L0805F59E\n"
    ".L0805EEF6:\n"
    "\tlsls r0, r0, #2\n"
    "\tldr r1, .L0805EF0C @ =.L0805EF10\n"
    "\tadds r0, r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
    ".L0805EF00: .word __vt_19HardwareBlendObject\n"
    ".L0805EF04: .word 0x00000889\n"
    ".L0805EF08: .word 0x00006422\n"
    ".L0805EF0C: .word .L0805EF10\n"
    ".L0805EF10: @ jump table\n"
    "\t.word .L0805EF38 @ case 0\n"
    "\t.word .L0805EF64 @ case 1\n"
    "\t.word .L0805EF88 @ case 2\n"
    "\t.word .L0805EFB4 @ case 3\n"
    "\t.word .L0805EFF6 @ case 4\n"
    "\t.word .L0805F11C @ case 5\n"
    "\t.word .L0805F138 @ case 6\n"
    "\t.word .L0805F15C @ case 7\n"
    "\t.word .L0805F1FA @ case 8\n"
    "\t.word .L0805F58E @ case 9\n"
    ".L0805EF38:\n"
    "\tldr r0, [sp, #4]\n"
    "\tldr r1, .L0805EF5C @ =0x00000889\n"
    "\tadds r0, #0xc\n"
    "\tmovs r2, #2\n"
    "\tmovs r3, #0\n"
    "\tbl BeginHardwareBlend\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareCommandList\n"
    "\tldr r2, [r0, #8]\n"
    "\tldr r1, [sp, #4]\n"
    "\tldr r2, [r2, #0x10]\n"
    "\tbl _call_via_r2\n"
    "\tldr r2, .L0805EF60 @ =0x00006422\n"
    "\tadds r1, r5, r2\n"
    "\tb .L0805F090\n"
    "\t.align 2, 0\n"
    ".L0805EF5C: .word 0x00000889\n"
    ".L0805EF60: .word 0x00006422\n"
    ".L0805EF64:\n"
    "\tldr r3, [sp, #0x34]\n"
    "\tlsls r0, r3, #0x10\n"
    "\tldr r4, .L0805EF80 @ =0xFFFF0000\n"
    "\tadds r0, r0, r4\n"
    "\tlsrs r7, r0, #0x10\n"
    "\tstr r7, [sp, #0x34]\n"
    "\tcmp r0, #0\n"
    "\tblt .L0805EF76\n"
    "\tb .L0805F59E\n"
    ".L0805EF76:\n"
    "\tldr r0, .L0805EF84 @ =0x00006422\n"
    "\tadds r1, r5, r0\n"
    "\tmovs r0, #3\n"
    "\tstrh r0, [r1]\n"
    "\tb .L0805F59E\n"
    "\t.align 2, 0\n"
    ".L0805EF80: .word 0xFFFF0000\n"
    ".L0805EF84: .word 0x00006422\n"
    ".L0805EF88:\n"
    "\tldr r0, [sp, #4]\n"
    "\tldr r1, .L0805EFAC @ =0x00000889\n"
    "\tadds r0, #0xc\n"
    "\tmovs r2, #1\n"
    "\tmovs r3, #0\n"
    "\tbl BeginHardwareBlend\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareCommandList\n"
    "\tldr r2, [r0, #8]\n"
    "\tldr r1, [sp, #4]\n"
    "\tldr r2, [r2, #0x10]\n"
    "\tbl _call_via_r2\n"
    "\tldr r2, .L0805EFB0 @ =0x00006422\n"
    "\tadds r1, r5, r2\n"
    "\tb .L0805F090\n"
    "\t.align 2, 0\n"
    ".L0805EFAC: .word 0x00000889\n"
    ".L0805EFB0: .word 0x00006422\n"
    ".L0805EFB4:\n"
    "\tldr r0, [sp, #4]\n"
    "\tldr r1, [r0]\n"
    "\trsbs r0, r1, #0\n"
    "\torrs r0, r1\n"
    "\tcmp r0, #0\n"
    "\tbge .L0805EFC2\n"
    "\tb .L0805F59E\n"
    ".L0805EFC2:\n"
    "\tldr r3, .L0805EFE8 @ =0x00006422\n"
    "\tadds r0, r5, r3\n"
    "\tmovs r1, #5\n"
    "\tstrh r1, [r0]\n"
    "\tldr r4, .L0805EFEC @ =0x00006420\n"
    "\tadds r0, r5, r4\n"
    "\tmovs r7, #0\n"
    "\tldrsh r0, [r0, r7]\n"
    "\tcmp r0, #1\n"
    "\tbeq .L0805EFE2\n"
    "\tcmp r0, #1\n"
    "\tblt .L0805EFF0\n"
    "\tcmp r0, #0xc\n"
    "\tbgt .L0805EFF0\n"
    "\tcmp r0, #0xb\n"
    "\tblt .L0805EFF0\n"
    ".L0805EFE2:\n"
    "\tmovs r0, #0x3c\n"
    "\tstr r0, [sp, #0x34]\n"
    "\tb .L0805F59E\n"
    "\t.align 2, 0\n"
    ".L0805EFE8: .word 0x00006422\n"
    ".L0805EFEC: .word 0x00006420\n"
    ".L0805EFF0:\n"
    "\tmovs r1, #0\n"
    "\tstr r1, [sp, #0x34]\n"
    "\tb .L0805F59E\n"
    ".L0805EFF6:\n"
    "\tldr r2, [sp, #0x34]\n"
    "\tlsls r0, r2, #0x10\n"
    "\tldr r3, .L0805F030 @ =0xFFFF0000\n"
    "\tadds r0, r0, r3\n"
    "\tlsrs r4, r0, #0x10\n"
    "\tstr r4, [sp, #0x34]\n"
    "\tcmp r0, #0\n"
    "\tblt .L0805F008\n"
    "\tb .L0805F59E\n"
    ".L0805F008:\n"
    "\tldr r7, .L0805F034 @ =0x00006422\n"
    "\tadds r1, r5, r7\n"
    "\tmovs r2, #0\n"
    "\tmovs r0, #6\n"
    "\tstrh r0, [r1]\n"
    "\tldr r1, .L0805F038 @ =0x00006426\n"
    "\tadds r0, r5, r1\n"
    "\tstrh r2, [r0]\n"
    "\tldr r2, .L0805F03C @ =0x00006420\n"
    "\tadds r0, r5, r2\n"
    "\tmovs r3, #0\n"
    "\tldrsh r0, [r0, r3]\n"
    "\tcmp r0, #0xd\n"
    "\tbhi .L0805F0FC\n"
    "\tlsls r0, r0, #2\n"
    "\tldr r1, .L0805F040 @ =.L0805F044\n"
    "\tadds r0, r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
    ".L0805F030: .word 0xFFFF0000\n"
    ".L0805F034: .word 0x00006422\n"
    ".L0805F038: .word 0x00006426\n"
    ".L0805F03C: .word 0x00006420\n"
    ".L0805F040: .word .L0805F044\n"
    ".L0805F044: @ jump table\n"
    "\t.word .L0805F07C @ case 0\n"
    "\t.word .L0805F08C @ case 1\n"
    "\t.word .L0805F09C @ case 2\n"
    "\t.word .L0805F0FC @ case 3\n"
    "\t.word .L0805F0FC @ case 4\n"
    "\t.word .L0805F0FC @ case 5\n"
    "\t.word .L0805F0FC @ case 6\n"
    "\t.word .L0805F0FC @ case 7\n"
    "\t.word .L0805F0FC @ case 8\n"
    "\t.word .L0805F0AC @ case 9\n"
    "\t.word .L0805F0BC @ case 10\n"
    "\t.word .L0805F0CC @ case 11\n"
    "\t.word .L0805F0DC @ case 12\n"
    "\t.word .L0805F0EC @ case 13\n"
    ".L0805F07C:\n"
    "\tldr r4, .L0805F088 @ =0x00006424\n"
    "\tadds r1, r5, r4\n"
    "\tmovs r0, #0\n"
    "\tstrh r0, [r1]\n"
    "\tb .L0805F59E\n"
    "\t.align 2, 0\n"
    ".L0805F088: .word 0x00006424\n"
    ".L0805F08C:\n"
    "\tldr r7, .L0805F098 @ =0x00006424\n"
    "\tadds r1, r5, r7\n"
    ".L0805F090:\n"
    "\tmovs r0, #4\n"
    "\tstrh r0, [r1]\n"
    "\tb .L0805F59E\n"
    "\t.align 2, 0\n"
    ".L0805F098: .word 0x00006424\n"
    ".L0805F09C:\n"
    "\tldr r0, .L0805F0A8 @ =0x00006424\n"
    "\tadds r1, r5, r0\n"
    "\tmovs r0, #5\n"
    "\tstrh r0, [r1]\n"
    "\tb .L0805F59E\n"
    "\t.align 2, 0\n"
    ".L0805F0A8: .word 0x00006424\n"
    ".L0805F0AC:\n"
    "\tldr r2, .L0805F0B8 @ =0x00006424\n"
    "\tadds r1, r5, r2\n"
    "\tmovs r0, #0xe\n"
    "\tstrh r0, [r1]\n"
    "\tb .L0805F59E\n"
    "\t.align 2, 0\n"
    ".L0805F0B8: .word 0x00006424\n"
    ".L0805F0BC:\n"
    "\tldr r3, .L0805F0C8 @ =0x00006424\n"
    "\tadds r1, r5, r3\n"
    "\tmovs r0, #0x10\n"
    "\tstrh r0, [r1]\n"
    "\tb .L0805F59E\n"
    "\t.align 2, 0\n"
    ".L0805F0C8: .word 0x00006424\n"
    ".L0805F0CC:\n"
    "\tldr r4, .L0805F0D8 @ =0x00006424\n"
    "\tadds r1, r5, r4\n"
    "\tmovs r0, #0x13\n"
    "\tstrh r0, [r1]\n"
    "\tb .L0805F59E\n"
    "\t.align 2, 0\n"
    ".L0805F0D8: .word 0x00006424\n"
    ".L0805F0DC:\n"
    "\tldr r7, .L0805F0E8 @ =0x00006424\n"
    "\tadds r1, r5, r7\n"
    "\tmovs r0, #0x16\n"
    "\tstrh r0, [r1]\n"
    "\tb .L0805F59E\n"
    "\t.align 2, 0\n"
    ".L0805F0E8: .word 0x00006424\n"
    ".L0805F0EC:\n"
    "\tldr r0, .L0805F0F8 @ =0x00006424\n"
    "\tadds r1, r5, r0\n"
    "\tmovs r0, #0x19\n"
    "\tstrh r0, [r1]\n"
    "\tb .L0805F59E\n"
    "\t.align 2, 0\n"
    ".L0805F0F8: .word 0x00006424\n"
    ".L0805F0FC:\n"
    "\tmovs r1, #0xb4\n"
    "\tstr r1, [sp, #0x34]\n"
    "\tldr r2, .L0805F114 @ =0x00006426\n"
    "\tadds r1, r5, r2\n"
    "\tmovs r0, #2\n"
    "\tstrh r0, [r1]\n"
    "\tldr r3, .L0805F118 @ =0x00006422\n"
    "\tadds r1, r5, r3\n"
    "\tmovs r0, #7\n"
    "\tstrh r0, [r1]\n"
    "\tb .L0805F59E\n"
    "\t.align 2, 0\n"
    ".L0805F114: .word 0x00006426\n"
    ".L0805F118: .word 0x00006422\n"
    ".L0805F11C:\n"
    "\tldr r4, .L0805F130 @ =0x00006426\n"
    "\tadds r0, r5, r4\n"
    "\tmovs r7, #0\n"
    "\tldrsh r0, [r0, r7]\n"
    "\tcmp r0, #2\n"
    "\tbeq .L0805F12A\n"
    "\tb .L0805F59E\n"
    ".L0805F12A:\n"
    "\tldr r0, .L0805F134 @ =0x00006422\n"
    "\tadds r1, r5, r0\n"
    "\tb .L0805F14E\n"
    "\t.align 2, 0\n"
    ".L0805F130: .word 0x00006426\n"
    ".L0805F134: .word 0x00006422\n"
    ".L0805F138:\n"
    "\tldr r1, [sp, #0x34]\n"
    "\tlsls r0, r1, #0x10\n"
    "\tldr r2, .L0805F154 @ =0xFFFF0000\n"
    "\tadds r0, r0, r2\n"
    "\tlsrs r3, r0, #0x10\n"
    "\tstr r3, [sp, #0x34]\n"
    "\tcmp r0, #0\n"
    "\tblt .L0805F14A\n"
    "\tb .L0805F59E\n"
    ".L0805F14A:\n"
    "\tldr r4, .L0805F158 @ =0x00006422\n"
    "\tadds r1, r5, r4\n"
    ".L0805F14E:\n"
    "\tmovs r0, #8\n"
    "\tstrh r0, [r1]\n"
    "\tb .L0805F59E\n"
    "\t.align 2, 0\n"
    ".L0805F154: .word 0xFFFF0000\n"
    ".L0805F158: .word 0x00006422\n"
    ".L0805F15C:\n"
    "\tldr r7, .L0805F19C @ =0x00006420\n"
    "\tadds r1, r5, r7\n"
    "\tldrh r2, [r1]\n"
    "\tadds r0, r2, #1\n"
    "\tstrh r0, [r1]\n"
    "\tlsls r0, r0, #0x10\n"
    "\tasrs r0, r0, #0x10\n"
    "\tcmp r0, #0xd\n"
    "\tbgt .L0805F1D4\n"
    "\tadds r0, r2, #0\n"
    "\tsubs r0, #8\n"
    "\tlsls r0, r0, #0x10\n"
    "\tlsrs r0, r0, #0x10\n"
    "\tcmp r0, #2\n"
    "\tbhi .L0805F1A4\n"
    "\tldr r0, [sp, #4]\n"
    "\tldr r1, .L0805F1A0 @ =0x00000889\n"
    "\tadds r0, #0xc\n"
    "\tmovs r2, #1\n"
    "\tmovs r3, #0\n"
    "\tbl EndHardwareBlend\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareCommandList\n"
    "\tldr r2, [r0, #8]\n"
    "\tldr r1, [sp, #4]\n"
    "\tldr r2, [r2, #0x10]\n"
    "\tbl _call_via_r2\n"
    "\tb .L0805F1C2\n"
    "\t.align 2, 0\n"
    ".L0805F19C: .word 0x00006420\n"
    ".L0805F1A0: .word 0x00000889\n"
    ".L0805F1A4:\n"
    "\tldr r0, [sp, #4]\n"
    "\tldr r1, .L0805F1CC @ =0x00000889\n"
    "\tadds r0, #0xc\n"
    "\tmovs r2, #2\n"
    "\tmovs r3, #0\n"
    "\tbl EndHardwareBlend\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareCommandList\n"
    "\tldr r2, [r0, #8]\n"
    "\tldr r1, [sp, #4]\n"
    "\tldr r2, [r2, #0x10]\n"
    "\tbl _call_via_r2\n"
    ".L0805F1C2:\n"
    "\tldr r0, .L0805F1D0 @ =0x00006422\n"
    "\tadds r1, r5, r0\n"
    "\tmovs r0, #9\n"
    "\tb .L0805F1F8\n"
    "\t.align 2, 0\n"
    ".L0805F1CC: .word 0x00000889\n"
    ".L0805F1D0: .word 0x00006422\n"
    ".L0805F1D4:\n"
    "\tldr r0, [sp, #4]\n"
    "\tldr r1, .L0805F22C @ =0x00000889\n"
    "\tadds r0, #0xc\n"
    "\tmovs r2, #1\n"
    "\tmovs r3, #1\n"
    "\tbl EndHardwareBlend\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareCommandList\n"
    "\tldr r2, [r0, #8]\n"
    "\tldr r1, [sp, #4]\n"
    "\tldr r2, [r2, #0x10]\n"
    "\tbl _call_via_r2\n"
    "\tldr r2, .L0805F230 @ =0x00006422\n"
    "\tadds r1, r5, r2\n"
    "\tmovs r0, #0xa\n"
    ".L0805F1F8:\n"
    "\tstrh r0, [r1]\n"
    ".L0805F1FA:\n"
    "\tldr r0, [sp, #4]\n"
    "\tldr r1, [r0]\n"
    "\trsbs r0, r1, #0\n"
    "\torrs r0, r1\n"
    "\tcmp r0, #0\n"
    "\tbge .L0805F208\n"
    "\tb .L0805F59E\n"
    ".L0805F208:\n"
    "\tmovs r3, #1\n"
    "\trsbs r3, r3, #0\n"
    "\tmov sl, r3\n"
    "\tldr r4, .L0805F234 @ =0x00006420\n"
    "\tadds r0, r5, r4\n"
    "\tldrh r0, [r0]\n"
    "\tsubs r0, #1\n"
    "\tlsls r0, r0, #0x10\n"
    "\tasrs r0, r0, #0x10\n"
    "\tcmp r0, #0xc\n"
    "\tbls .L0805F220\n"
    "\tb .L0805F32E\n"
    ".L0805F220:\n"
    "\tlsls r0, r0, #2\n"
    "\tldr r1, .L0805F238 @ =.L0805F23C\n"
    "\tadds r0, r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
    ".L0805F22C: .word 0x00000889\n"
    ".L0805F230: .word 0x00006422\n"
    ".L0805F234: .word 0x00006420\n"
    ".L0805F238: .word .L0805F23C\n"
    ".L0805F23C: @ jump table\n"
    "\t.word .L0805F270 @ case 0\n"
    "\t.word .L0805F280 @ case 1\n"
    "\t.word .L0805F2BC @ case 2\n"
    "\t.word .L0805F2BC @ case 3\n"
    "\t.word .L0805F2BC @ case 4\n"
    "\t.word .L0805F2BC @ case 5\n"
    "\t.word .L0805F2BC @ case 6\n"
    "\t.word .L0805F2BC @ case 7\n"
    "\t.word .L0805F29C @ case 8\n"
    "\t.word .L0805F2DC @ case 9\n"
    "\t.word .L0805F2F8 @ case 10\n"
    "\t.word .L0805F318 @ case 11\n"
    "\t.word .L0805F280 @ case 12\n"
    ".L0805F270:\n"
    "\tmovs r7, #0\n"
    "\tmov sl, r7\n"
    "\tldr r0, .L0805F27C @ =0x00006422\n"
    "\tadds r1, r5, r0\n"
    "\tb .L0805F2CE\n"
    "\t.align 2, 0\n"
    ".L0805F27C: .word 0x00006422\n"
    ".L0805F280:\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tmov r2, sp\n"
    "\tmovs r3, #0x92\n"
    "\tlsls r3, r3, #5\n"
    "\tadds r1, r3, #0\n"
    "\tstrh r1, [r2]\n"
    "\tstrh r1, [r0]\n"
    "\tldr r4, .L0805F298 @ =0x00006422\n"
    "\tadds r1, r5, r4\n"
    "\tb .L0805F2CE\n"
    "\t.align 2, 0\n"
    ".L0805F298: .word 0x00006422\n"
    ".L0805F29C:\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tmov r2, sp\n"
    "\tmovs r7, #0x82\n"
    "\tlsls r7, r7, #5\n"
    "\tadds r1, r7, #0\n"
    "\tstrh r1, [r2]\n"
    "\tstrh r1, [r0]\n"
    "\tldr r0, .L0805F2B8 @ =0x00006422\n"
    "\tadds r1, r5, r0\n"
    "\tmovs r0, #3\n"
    "\tstrh r0, [r1]\n"
    "\tb .L0805F32E\n"
    "\t.align 2, 0\n"
    ".L0805F2B8: .word 0x00006422\n"
    ".L0805F2BC:\n"
    "\tldr r1, .L0805F2D4 @ =0x00006420\n"
    "\tadds r0, r5, r1\n"
    "\tmovs r2, #0\n"
    "\tldrsh r0, [r0, r2]\n"
    "\tsubs r0, #2\n"
    "\tlsls r0, r0, #1\n"
    "\tmov sl, r0\n"
    "\tldr r3, .L0805F2D8 @ =0x00006422\n"
    "\tadds r1, r5, r3\n"
    ".L0805F2CE:\n"
    "\tmovs r0, #1\n"
    "\tstrh r0, [r1]\n"
    "\tb .L0805F32E\n"
    "\t.align 2, 0\n"
    ".L0805F2D4: .word 0x00006420\n"
    ".L0805F2D8: .word 0x00006422\n"
    ".L0805F2DC:\n"
    "\tldr r4, .L0805F2F0 @ =0x00006422\n"
    "\tadds r1, r5, r4\n"
    "\tmovs r0, #3\n"
    "\tstrh r0, [r1]\n"
    "\tldr r7, .L0805F2F4 @ =0x00006420\n"
    "\tadds r0, r5, r7\n"
    "\tmovs r1, #0\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tb .L0805F328\n"
    "\t.align 2, 0\n"
    ".L0805F2F0: .word 0x00006422\n"
    ".L0805F2F4: .word 0x00006420\n"
    ".L0805F2F8:\n"
    "\tmovs r2, #0x78\n"
    "\tstr r2, [sp, #0x34]\n"
    "\tldr r3, .L0805F310 @ =0x00006422\n"
    "\tadds r1, r5, r3\n"
    "\tmovs r0, #2\n"
    "\tstrh r0, [r1]\n"
    "\tldr r4, .L0805F314 @ =0x00006420\n"
    "\tadds r0, r5, r4\n"
    "\tmovs r7, #0\n"
    "\tldrsh r0, [r0, r7]\n"
    "\tb .L0805F328\n"
    "\t.align 2, 0\n"
    ".L0805F310: .word 0x00006422\n"
    ".L0805F314: .word 0x00006420\n"
    ".L0805F318:\n"
    "\tldr r0, .L0805F380 @ =0x00006422\n"
    "\tadds r1, r5, r0\n"
    "\tmovs r0, #1\n"
    "\tstrh r0, [r1]\n"
    "\tldr r1, .L0805F384 @ =0x00006420\n"
    "\tadds r0, r5, r1\n"
    "\tmovs r2, #0\n"
    "\tldrsh r0, [r0, r2]\n"
    ".L0805F328:\n"
    "\tsubs r0, #3\n"
    "\tlsls r0, r0, #1\n"
    "\tmov sl, r0\n"
    ".L0805F32E:\n"
    "\tmovs r0, #1\n"
    "\trsbs r0, r0, #0\n"
    "\tcmp sl, r0\n"
    "\tbne .L0805F338\n"
    "\tb .L0805F59E\n"
    ".L0805F338:\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareDmaQueue\n"
    "\tadds r6, r0, #0\n"
    "\tmov r3, sl\n"
    "\tlsls r4, r3, #2\n"
    "\tadds r1, r4, r3\n"
    "\tlsls r1, r1, #8\n"
    "\tadds r1, r1, r5\n"
    "\tadds r1, #0x20\n"
    "\tadd r0, sp, #8\n"
    "\tldr r2, .L0805F388\n"
    "\tmovs r3, #0xa0\n"
    "\tlsls r3, r3, #3\n"
    "\tbl __21DmaTransferDescriptorPCvPvUi\n"
    "\tldr r7, [sp, #0x40]\n"
    "\tstr r7, [sp, #0x3c]\n"
    "\tldr r1, [r6, #4]\n"
    "\tldr r0, [r6, #0xc]\n"
    "\tstr r4, [sp, #0x48]\n"
    "\tcmp r1, r0\n"
    "\tbeq .L0805F38C\n"
    "\tcmp r1, #0\n"
    "\tbeq .L0805F376\n"
    "\tadds r0, r1, #0\n"
    "\tadds r1, r7, #0\n"
    "\tldm r1!, {r2, r3, r4}\n"
    "\tstm r0!, {r2, r3, r4}\n"
    "\tldr r1, [r1]\n"
    "\tstr r1, [r0]\n"
    ".L0805F376:\n"
    "\tldr r0, [r6, #4]\n"
    "\tadds r0, #0x10\n"
    "\tstr r0, [r6, #4]\n"
    "\tb .L0805F460\n"
    "\t.align 2, 0\n"
    ".L0805F380: .word 0x00006422\n"
    ".L0805F384: .word 0x00006420\n"
    ".L0805F388: .word VRAM + 30 * BG_SCREEN_SIZE\n"
    ".L0805F38C:\n"
    "\tstr r1, [sp, #0x4c]\n"
    "\tmovs r0, #1\n"
    "\tstr r0, [sp, #0x1c]\n"
    "\tldr r1, [r6]\n"
    "\tldr r7, [sp, #0x4c]\n"
    "\tsubs r0, r7, r1\n"
    "\tasrs r4, r0, #4\n"
    "\tstr r4, [sp, #0x18]\n"
    "\tadd r2, sp, #0x1c\n"
    "\tadd r0, sp, #0x18\n"
    "\tcmp r4, #1\n"
    "\tbhs .L0805F3A6\n"
    "\tadds r0, r2, #0\n"
    ".L0805F3A6:\n"
    "\tldr r0, [r0]\n"
    "\tadds r0, r4, r0\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0805F3C6\n"
    "\tlsls r4, r0, #4\n"
    "\tadds r0, r4, #0\n"
    "\tbl malloc\n"
    "\tmov sb, r4\n"
    "\tcmp r0, #0\n"
    "\tbne .L0805F3C2\n"
    "\tmov r0, sb\n"
    "\tbl RetryMemoryAllocation\n"
    ".L0805F3C2:\n"
    "\tldr r1, [r6]\n"
    "\tb .L0805F3CA\n"
    ".L0805F3C6:\n"
    "\tmovs r0, #0\n"
    "\tmov sb, r0\n"
    ".L0805F3CA:\n"
    "\tadds r4, r0, #0\n"
    "\tmov r8, r4\n"
    "\tadds r2, r1, #0\n"
    "\tmov ip, r8\n"
    "\tldr r0, [sp, #0x4c]\n"
    "\tcmp r2, r0\n"
    "\tbeq .L0805F3F6\n"
    ".L0805F3D8:\n"
    "\tmov r1, ip\n"
    "\tcmp r1, #0\n"
    "\tbeq .L0805F3EA\n"
    "\tmov r0, ip\n"
    "\tadds r1, r2, #0\n"
    "\tldm r1!, {r3, r4, r7}\n"
    "\tstm r0!, {r3, r4, r7}\n"
    "\tldr r1, [r1]\n"
    "\tstr r1, [r0]\n"
    ".L0805F3EA:\n"
    "\tadds r2, #0x10\n"
    "\tmovs r0, #0x10\n"
    "\tadd ip, r0\n"
    "\tldr r1, [sp, #0x4c]\n"
    "\tcmp r2, r1\n"
    "\tbne .L0805F3D8\n"
    ".L0805F3F6:\n"
    "\tmov r4, ip\n"
    "\tldr r0, [sp, #0x1c]\n"
    "\tcmp r0, #1\n"
    "\tbne .L0805F412\n"
    "\tcmp r4, #0\n"
    "\tbeq .L0805F40E\n"
    "\tadds r0, r4, #0\n"
    "\tldr r1, [sp, #0x3c]\n"
    "\tldm r1!, {r2, r3, r7}\n"
    "\tstm r0!, {r2, r3, r7}\n"
    "\tldr r1, [r1]\n"
    "\tstr r1, [r0]\n"
    ".L0805F40E:\n"
    "\tadds r4, #0x10\n"
    "\tb .L0805F43A\n"
    ".L0805F412:\n"
    "\tmov ip, r0\n"
    "\tadds r2, r4, #0\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0805F438\n"
    ".L0805F41A:\n"
    "\tcmp r2, #0\n"
    "\tbeq .L0805F42A\n"
    "\tadds r0, r2, #0\n"
    "\tldr r1, [sp, #0x3c]\n"
    "\tldm r1!, {r3, r4, r7}\n"
    "\tstm r0!, {r3, r4, r7}\n"
    "\tldr r1, [r1]\n"
    "\tstr r1, [r0]\n"
    ".L0805F42A:\n"
    "\tmovs r0, #1\n"
    "\trsbs r0, r0, #0\n"
    "\tadd ip, r0\n"
    "\tadds r2, #0x10\n"
    "\tmov r1, ip\n"
    "\tcmp r1, #0\n"
    "\tbne .L0805F41A\n"
    ".L0805F438:\n"
    "\tadds r4, r2, #0\n"
    ".L0805F43A:\n"
    "\tldr r2, [r6, #4]\n"
    "\tldr r1, [r6]\n"
    "\tadds r0, r1, #0\n"
    "\tcmp r1, r2\n"
    "\tbeq .L0805F44A\n"
    ".L0805F444:\n"
    "\tadds r0, #0x10\n"
    "\tcmp r0, r2\n"
    "\tbne .L0805F444\n"
    ".L0805F44A:\n"
    "\tcmp r1, #0\n"
    "\tbeq .L0805F454\n"
    "\tadds r0, r1, #0\n"
    "\tbl free\n"
    ".L0805F454:\n"
    "\tmov r0, sb\n"
    "\tadd r0, r8\n"
    "\tmov r2, r8\n"
    "\tstr r2, [r6]\n"
    "\tstr r4, [r6, #4]\n"
    "\tstr r0, [r6, #0xc]\n"
    ".L0805F460:\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareDmaQueue\n"
    "\tadds r6, r0, #0\n"
    "\tldr r1, [sp, #0x48]\n"
    "\tadd r1, sl\n"
    "\tlsls r1, r1, #8\n"
    "\tadds r1, r1, r5\n"
    "\tmovs r3, #0xa4\n"
    "\tlsls r3, r3, #3\n"
    "\tadds r1, r1, r3\n"
    "\tadd r0, sp, #8\n"
    "\tldr r2, .L0805F4A4\n"
    "\tsubs r3, #0x20\n"
    "\tbl __21DmaTransferDescriptorPCvPvUi\n"
    "\tldr r4, [sp, #0x40]\n"
    "\tmov sl, r4\n"
    "\tldr r1, [r6, #4]\n"
    "\tldr r0, [r6, #0xc]\n"
    "\tcmp r1, r0\n"
    "\tbeq .L0805F4A8\n"
    "\tcmp r1, #0\n"
    "\tbeq .L0805F49C\n"
    "\tadds r0, r1, #0\n"
    "\tadds r1, r4, #0\n"
    "\tldm r1!, {r2, r3, r7}\n"
    "\tstm r0!, {r2, r3, r7}\n"
    "\tldr r1, [r1]\n"
    "\tstr r1, [r0]\n"
    ".L0805F49C:\n"
    "\tldr r0, [r6, #4]\n"
    "\tadds r0, #0x10\n"
    "\tstr r0, [r6, #4]\n"
    "\tb .L0805F57A\n"
    "\t.align 2, 0\n"
    ".L0805F4A4: .word VRAM + 29 * BG_SCREEN_SIZE\n"
    ".L0805F4A8:\n"
    "\tstr r1, [sp, #0x4c]\n"
    "\tmovs r0, #1\n"
    "\tstr r0, [sp, #0x24]\n"
    "\tldr r1, [r6]\n"
    "\tldr r4, [sp, #0x4c]\n"
    "\tsubs r0, r4, r1\n"
    "\tasrs r4, r0, #4\n"
    "\tstr r4, [sp, #0x20]\n"
    "\tadd r2, sp, #0x24\n"
    "\tadd r0, sp, #0x20\n"
    "\tcmp r4, #1\n"
    "\tbhs .L0805F4C2\n"
    "\tadds r0, r2, #0\n"
    ".L0805F4C2:\n"
    "\tldr r0, [r0]\n"
    "\tadds r0, r4, r0\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0805F4E2\n"
    "\tlsls r4, r0, #4\n"
    "\tadds r0, r4, #0\n"
    "\tbl malloc\n"
    "\tmov sb, r4\n"
    "\tcmp r0, #0\n"
    "\tbne .L0805F4DE\n"
    "\tmov r0, sb\n"
    "\tbl RetryMemoryAllocation\n"
    ".L0805F4DE:\n"
    "\tldr r1, [r6]\n"
    "\tb .L0805F4E6\n"
    ".L0805F4E2:\n"
    "\tmovs r0, #0\n"
    "\tmov sb, r0\n"
    ".L0805F4E6:\n"
    "\tadds r4, r0, #0\n"
    "\tmov r8, r4\n"
    "\tadds r2, r1, #0\n"
    "\tmov ip, r8\n"
    "\tldr r7, [sp, #0x4c]\n"
    "\tcmp r2, r7\n"
    "\tbeq .L0805F510\n"
    ".L0805F4F4:\n"
    "\tmov r0, ip\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0805F504\n"
    "\tadds r1, r2, #0\n"
    "\tldm r1!, {r3, r4, r7}\n"
    "\tstm r0!, {r3, r4, r7}\n"
    "\tldr r1, [r1]\n"
    "\tstr r1, [r0]\n"
    ".L0805F504:\n"
    "\tadds r2, #0x10\n"
    "\tmovs r0, #0x10\n"
    "\tadd ip, r0\n"
    "\tldr r1, [sp, #0x4c]\n"
    "\tcmp r2, r1\n"
    "\tbne .L0805F4F4\n"
    ".L0805F510:\n"
    "\tmov r4, ip\n"
    "\tldr r0, [sp, #0x24]\n"
    "\tcmp r0, #1\n"
    "\tbne .L0805F52C\n"
    "\tcmp r4, #0\n"
    "\tbeq .L0805F528\n"
    "\tadds r0, r4, #0\n"
    "\tmov r1, sl\n"
    "\tldm r1!, {r2, r3, r7}\n"
    "\tstm r0!, {r2, r3, r7}\n"
    "\tldr r1, [r1]\n"
    "\tstr r1, [r0]\n"
    ".L0805F528:\n"
    "\tadds r4, #0x10\n"
    "\tb .L0805F554\n"
    ".L0805F52C:\n"
    "\tmov ip, r0\n"
    "\tadds r2, r4, #0\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0805F552\n"
    ".L0805F534:\n"
    "\tcmp r2, #0\n"
    "\tbeq .L0805F544\n"
    "\tadds r0, r2, #0\n"
    "\tmov r1, sl\n"
    "\tldm r1!, {r3, r4, r7}\n"
    "\tstm r0!, {r3, r4, r7}\n"
    "\tldr r1, [r1]\n"
    "\tstr r1, [r0]\n"
    ".L0805F544:\n"
    "\tmovs r0, #1\n"
    "\trsbs r0, r0, #0\n"
    "\tadd ip, r0\n"
    "\tadds r2, #0x10\n"
    "\tmov r1, ip\n"
    "\tcmp r1, #0\n"
    "\tbne .L0805F534\n"
    ".L0805F552:\n"
    "\tadds r4, r2, #0\n"
    ".L0805F554:\n"
    "\tldr r2, [r6, #4]\n"
    "\tldr r1, [r6]\n"
    "\tadds r0, r1, #0\n"
    "\tcmp r1, r2\n"
    "\tbeq .L0805F564\n"
    ".L0805F55E:\n"
    "\tadds r0, #0x10\n"
    "\tcmp r0, r2\n"
    "\tbne .L0805F55E\n"
    ".L0805F564:\n"
    "\tcmp r1, #0\n"
    "\tbeq .L0805F56E\n"
    "\tadds r0, r1, #0\n"
    "\tbl free\n"
    ".L0805F56E:\n"
    "\tmov r0, sb\n"
    "\tadd r0, r8\n"
    "\tmov r2, r8\n"
    "\tstr r2, [r6]\n"
    "\tstr r4, [r6, #4]\n"
    "\tstr r0, [r6, #0xc]\n"
    ".L0805F57A:\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tmov r2, sp\n"
    "\tmovs r3, #0xe2\n"
    "\tlsls r3, r3, #5\n"
    "\tadds r1, r3, #0\n"
    "\tstrh r1, [r2]\n"
    "\tstrh r1, [r0]\n"
    "\tb .L0805F59E\n"
    ".L0805F58E:\n"
    "\tldr r0, [sp, #4]\n"
    "\tldr r1, [r0]\n"
    "\trsbs r0, r1, #0\n"
    "\torrs r0, r1\n"
    "\tcmp r0, #0\n"
    "\tblt .L0805F59E\n"
    "\tmovs r4, #1\n"
    "\tstr r4, [sp, #0x38]\n"
    ".L0805F59E:\n"
    "\tadds r0, r5, #0\n"
    "\tbl UpdateIntroStoryUi\n"
    "\tldr r7, [sp, #0x38]\n"
    "\tcmp r7, #0\n"
    "\tbne .L0805F5AC\n"
    "\tb .L0805EED8\n"
    ".L0805F5AC:\n"
    "\tmovs r0, #0\n"
    "\tstr r0, [sp, #8]\n"
    "\tldr r1, [sp, #0x40]\n"
    "\tstr r1, [sp, #0x28]\n"
    "\tldr r2, [sp, #0x44]\n"
    "\tstr r0, [r2, #4]\n"
    "\tstr r0, [r1]\n"
    "\tldr r3, [sp, #0x30]\n"
    "\tstr r0, [r3]\n"
    "\tldr r1, [sp, #8]\n"
    "\tcmp r1, #0\n"
    "\tbeq .L0805F5D0\n"
    "\tldr r0, [r1]\n"
    "\tldr r2, [r0, #8]\n"
    "\tadds r0, r1, #0\n"
    "\tmovs r1, #3\n"
    "\tbl _call_via_r2\n"
    ".L0805F5D0:\n"
    "\tldr r1, [sp, #4]\n"
    "\tcmp r1, #0\n"
    "\tbeq .L0805F5E2\n"
    "\tldr r0, [r1, #8]\n"
    "\tldr r2, [r0, #0xc]\n"
    "\tadds r0, r1, #0\n"
    "\tmovs r1, #3\n"
    "\tbl _call_via_r2\n"
    ".L0805F5E2:\n"
    "\tldr r0, [sp, #0x30]\n"
    "\tadd sp, #0x50\n"
    "\tpop {r3, r4, r5}\n"
    "\tmov r8, r3\n"
    "\tmov sb, r4\n"
    "\tmov sl, r5\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
);


void UpdateIntroStoryUi(IntroStorySceneCore * core)
{
    UiStateOwner * ui = core->ui_state.value;
    HardwareCoreState * state = static_cast<HardwareCoreState *>(GetHardwareCoreState(reinterpret_cast<void * const *>(core)));
    HardwareSpriteBufferState * sprites = GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
    HardwareDisplayState * display = GetHardwareDisplayState(reinterpret_cast<void * const *>(core));
    HardwareLinkedList * links = GetHardwareCommandList(reinterpret_cast<void * const *>(core));
    HardwareInterruptList * manager = GetHardwareInterruptList(reinterpret_cast<void * const *>(core));
    HardwareMusicPlayerSlot * music = &core->music_player_1;
    switch (ui->Update(&state->input, sprites, display, links, manager, music))
    {
    case 0:
        if (core->dialogue_state == 0)
        {
            func_08050E74(reinterpret_cast<void * const *>(core->ui_state.value));
            func_08050D5C(core->ui_state.value);
            core->dialogue_state = 3;
        }
        else if (core->dialogue_state == 6)
            core->dialogue_state = 0;
        else
            core->dialogue_state = 2;
        break;
    case 1:
    case 2:
        break;
    case 3:
        if (core->dialogue_state == 5)
        {
            func_08050D74(reinterpret_cast<void * const *>(core->ui_state.value));
            core->dialogue_state = 1;
        }
        else if (core->dialogue_state == 6)
            func_08050D74(reinterpret_cast<void * const *>(core->ui_state.value));
        else if (core->dialogue_state == 3)
        {
            core->dialogue_state = 5;
            switch (core->story_step)
            {
            case 0:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_MotherName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_MotherTravelGreeting, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 1;
                break;
            case 1:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_FatherName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_FatherFishingInvitation, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 2;
                break;
            case 2:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_MotherName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_MotherCannotFindPlayer, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 3;
                break;
            case 3:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_FatherName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_PlayerResponseWhat, &core->variables);
                break;
            case 4:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_OldManName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_OldManFindsPlayer, &core->variables);
                break;
            case 5:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_MotherName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_MotherThanksOldMan, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 6;
                break;
            case 6:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_FatherName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_FatherExplainsVacation, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 7;
                break;
            case 7:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_OldManName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_OldManOffersStay, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 9;
                break;
            case 8:
                break;
            case 9:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_FatherName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_FatherAsksAboutStay, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 10;
                break;
            case 10:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_OldManName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_OldManWelcomesFamily, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 11;
                break;
            case 11:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_MotherName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_MotherTellsPlayerToPlay, &core->variables);
                break;
            case 12:
                break;
            case 13:
                break;
            case 14:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_UnknownName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_UnknownCallsPlayer, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 15;
                break;
            case 15:
                func_08050DA0(core->ui_state.value, gText_IntroScene_UnknownFindsPlayer, &core->variables);
                break;
            case 16:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_GirlName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_GirlThinksPlayerDead, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 17;
                break;
            case 17:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_GirlName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_GirlInvitesPlayerToPlay, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 18;
                break;
            case 18:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_GirlName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_GirlAsksPlayerStory, &core->variables);
                break;
            case 19:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_OldManName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_OldManFarewell, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 20;
                break;
            case 20:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_OldManName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_OldManRequestsLetter, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 21;
                break;
            case 21:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_OldManName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_OldManGivesAddress, &core->variables);
                break;
            case 22:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_GirlName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_GirlSaysGoodbye, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 23;
                break;
            case 23:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_GirlName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_GirlAsksPlayerToReturn, &core->variables);
                core->dialogue_state = 6;
                core->story_step = 24;
                break;
            case 24:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_OldManName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_OldManNotesFriend, &core->variables);
                break;
            case 25:
                func_08050E68(reinterpret_cast<void * const *>(core->ui_state.value), gText_IntroScene_OldManName);
                func_08050DA0(core->ui_state.value, gText_IntroScene_OldManWaitsForLetter, &core->variables);
                break;
            }
        }
        break;
    case 4:
    case 5:
    case 6:
        break;
    }
}

extern u8 const gUnk_08743058[];
extern u8 const gUnk_08747A14[];

void InitializeIntroStoryGraphics(IntroStorySceneCore * core)
{
    FillHardwareDma3(0, reinterpret_cast<void *>(VRAM + 1023 * TILE_SIZE_4BPP), TILE_SIZE_4BPP);
    FillHardwareDma3(0x10661066, reinterpret_cast<void *>(BG_SCREEN_ADDR(28)), BG_SCREEN_SIZE);
    FillHardwareDma3(0x10661066, reinterpret_cast<void *>(BG_SCREEN_ADDR(29)), BG_SCREEN_SIZE);
    FillHardwareDma3(0x10661066, reinterpret_cast<void *>(BG_SCREEN_ADDR(30)), BG_SCREEN_SIZE);
    Unpack(gUnk_08743058, reinterpret_cast<void *>(BG_CHAR_ADDR(0)));
    CopyHardwareDma3(gUnk_08747A14, reinterpret_cast<void *>(BG_PLTT), 2 * PLTT_SIZE_4BPP);
    *reinterpret_cast<volatile u16 *>(BG_PLTT) = RGB(31, 31, 31);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetDisplayFlags(
        DISPCNT_OBJ_1D_MAP | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetBackgroundFlags(3,
        BGCNT_PRIORITY(3) | BGCNT_MOSAIC | BGCNT_SCREENBASE(30));
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetBackgroundFlags(2,
        BGCNT_PRIORITY(2) | BGCNT_MOSAIC | BGCNT_SCREENBASE(29));
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetBackgroundFlags(1,
        BGCNT_PRIORITY(1) | BGCNT_MOSAIC | BGCNT_SCREENBASE(28));
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetHorizontalOffset(2, 0);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetVerticalOffset(2, 0);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetHorizontalOffset(3, 0);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetVerticalOffset(3, 0);
    for (i32 i = 0; i < static_cast<i32>(ARRAY_COUNT(gIntroStoryTilemapSources)); ++i)
        Unpack(gIntroStoryTilemapSources[i], core->background_tilemaps[i]);
}

inline IntroStoryCoreOwner::IntroStoryCoreOwner(GameStateSaveImage * saved)
    : value(new IntroStorySceneCore(saved)) {}

inline IntroStoryCoreOwner::~IntroStoryCoreOwner()
{
    delete value;
}

static inline SceneTransition * TakeIntroStoryContinuation(SceneTransition *& next)
{
    SceneTransition * result = next;
    next = nullptr;
    return result;
}

IntroStoryScene::IntroStoryScene(SceneTransition *& next, GameStateSaveImage * saved)
    : core(saved), continuation(TakeIntroStoryContinuation(next)) {}

IntroStoryScene::~IntroStoryScene() {}

SceneTransitionOwner IntroStoryScene::Run()
{
    RunIntroStorySceneCore(core.value);
    return continuation;
}

EXTERN_C

// Ten pairs of compressed 32x20 BG tilemaps, in the loader's exact order.
// They are map entries, not 4bpp pixels or OAM descriptors.
u8 const * const gIntroStoryTilemapSources[20] = {
    gIntroStoryFrame00Bg3Tilemap, gIntroStoryFrame00Bg2Tilemap,
    gIntroStoryFrame01Bg3Tilemap, gIntroStoryFrame01Bg2Tilemap,
    gIntroStoryFrame02Bg3Tilemap, gIntroStoryFrame02Bg2Tilemap,
    gIntroStoryFrame03Bg3Tilemap, gIntroStoryFrame03Bg2Tilemap,
    gIntroStoryFrame04Bg3Tilemap, gIntroStoryFrame04Bg2Tilemap,
    gIntroStoryFrame05Bg3Tilemap, gIntroStoryFrame05Bg2Tilemap,
    gIntroStoryFrame06Bg3Tilemap, gIntroStoryFrame06Bg2Tilemap,
    gIntroStoryFrame07Bg3Tilemap, gIntroStoryFrame07Bg2Tilemap,
    gIntroStoryFrame08Bg3Tilemap, gIntroStoryFrame08Bg2Tilemap,
    gIntroStoryFrame09Bg3Tilemap, gIntroStoryFrame09Bg2Tilemap,
};

EXTERN_C_END

#include FOMT_TEXT_INCLUDE(intro_story_scene.cc)
