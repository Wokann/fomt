#include "hardware_blend.hh"

void * operator new(unsigned long);
void operator delete(void *);

HardwareBlendController::HardwareBlendController(HardwareDisplayState * display)
    : state(new HardwareBlendState(display))
{
}

HardwareBlendController::~HardwareBlendController()
{
    delete state;
}

HardwareDisplayState * HardwareBlendController::SetDisplay(HardwareDisplayState * display)
{
    struct HardwareDisplayState * previous = this->state->display;
    this->state->display = display;
    return previous;
}

void BeginHardwareBlend(HardwareBlendController * controller, i16 step, u32 mode, u32 mosaic)
{
    struct HardwareBlendState * state = controller->state;
    i32 magnitude = step < 0 ? -step : step;
    i16 signed_step = -magnitude;
    u8 enabled = mosaic != 0;
    state->step = signed_step;
    state->mode = mode;
    state->mosaic_enabled = enabled;
    state->progress = 0xffff;
}

void EndHardwareBlend(HardwareBlendController * controller, i16 step, u32 mode, u32 mosaic)
{
    struct HardwareBlendState * state = controller->state;
    i32 magnitude = step < 0 ? -step : step;
    u8 enabled = mosaic != 0;
    state->step = magnitude;
    state->mode = mode;
    state->mosaic_enabled = enabled;
    state->progress = 0;
}

i16 HardwareBlendController::SetStep(i16 step)
{
    i16 previous = this->state->step;
    this->state->step = step;
    return previous;
}

NAKED bool HardwareBlendController::Update()
{
    asm_unified(
        ".include \"six/asm/hw/memory.s\"\n"
        ".include \"six/asm/hw/video.s\"\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    ldr r5, [r0]\n"
        "    movs r0, #4\n"
        "    ldrsh r7, [r5, r0]\n"
        "    cmp r7, #0\n"
        "    beq .L0800949C\n"
        "    ldrh r4, [r5, #0xe]\n"
        "    ldr r0, [r5, #8]\n"
        "    cmp r0, #0\n"
        "    beq .L08009422\n"
        "    movs r6, #0\n"
        "    cmp r0, #1\n"
        "    beq .L080093CE\n"
        "    cmp r0, #2\n"
        "    bne .L080093D0\n"
        "    movs r6, #BLD_MODE_BLACK\n"
        "    b .L080093D0\n"
        ".L080093CE:\n"
        "    movs r6, #BLD_MODE_WHITE\n"
        ".L080093D0:\n"
        "    ldr r3, [r5]\n"
        "    cmp r3, #0\n"
        "    beq .L080093DC\n"
        "    adds r2, r3, #0\n"
        "    adds r2, #OFF_BLDCNT\n"
        "    b .L080093DE\n"
        ".L080093DC:\n"
        "    ldr r2, .L080093F4 @ =REG_BLDCNT\n"
        ".L080093DE:\n"
        "    ldrh r1, [r2]\n"
        "    ldr r0, .L080093F8 @ =(0xFFFF & ~(((1 << BF_BLD_MODE_LENGTH) - 1) << BF_BLD_MODE_OFFSET))\n"
        "    ands r0, r1\n"
        "    orrs r0, r6\n"
        "    strh r0, [r2]\n"
        "    cmp r3, #0\n"
        "    beq .L080093FC\n"
        "    adds r1, r3, #0\n"
        "    adds r1, #OFF_BLDCOEFF\n"
        "    b .L080093FE\n"
        "    .align 2, 0\n"
        ".L080093F4: .word REG_BLDCNT\n"
        ".L080093F8: .word (0xFFFF & ~(((1 << BF_BLD_MODE_LENGTH) - 1) << BF_BLD_MODE_OFFSET))\n"
        ".L080093FC:\n"
        "    ldr r1, .L08009408 @ =REG_BLDCOEFF\n"
        ".L080093FE:\n"
        "    ldr r0, .L0800940C @ =0x0000FFFE\n"
        "    cmp r4, r0\n"
        "    bls .L08009410\n"
        "    movs r0, #0x10\n"
        "    b .L08009420\n"
        "    .align 2, 0\n"
        ".L08009408: .word REG_BLDCOEFF\n"
        ".L0800940C: .word 0x0000FFFE\n"
        ".L08009410:\n"
        "    cmp r4, #0\n"
        "    bne .L08009418\n"
        "    movs r0, #0\n"
        "    b .L08009420\n"
        ".L08009418:\n"
        "    lsls r0, r4, #4\n"
        "    subs r0, r0, r4\n"
        "    lsrs r0, r0, #0x10\n"
        "    adds r0, #1\n"
        ".L08009420:\n"
        "    strh r0, [r1]\n"
        ".L08009422:\n"
        "    ldrb r0, [r5, #0xc]\n"
        "    cmp r0, #0\n"
        "    beq .L08009460\n"
        "    ldr r0, .L08009434 @ =0x0000FFFE\n"
        "    cmp r4, r0\n"
        "    bls .L08009438\n"
        "    movs r1, #((1 << BF_MOSAIC_BG_H_LENGTH) - 1)\n"
        "    b .L0800944A\n"
        "    .align 2, 0\n"
        ".L08009434: .word 0x0000FFFE\n"
        ".L08009438:\n"
        "    cmp r4, #0\n"
        "    bne .L08009440\n"
        "    movs r1, #0\n"
        "    b .L0800944A\n"
        ".L08009440:\n"
        "    lsls r0, r4, #3\n"
        "    subs r0, r0, r4\n"
        "    lsls r0, r0, #1\n"
        "    lsrs r0, r0, #0x10\n"
        "    adds r1, r0, #1\n"
        ".L0800944A:\n"
        "    lsls r0, r1, #BF_MOSAIC_BG_V_OFFSET\n"
        "    orrs r1, r0\n"
        "    lsls r0, r1, #BF_MOSAIC_OBJ_H_OFFSET\n"
        "    orrs r1, r0\n"
        "    ldr r0, [r5]\n"
        "    cmp r0, #0\n"
        "    beq .L0800945C\n"
        "    adds r0, #OFF_MOSAIC\n"
        "    b .L0800945E\n"
        ".L0800945C:\n"
        "    ldr r0, .L0800946C @ =REG_MOSAIC\n"
        ".L0800945E:\n"
        "    strh r1, [r0]\n"
        ".L08009460:\n"
        "    cmp r7, #0\n"
        "    blt .L08009474\n"
        "    ldr r0, .L08009470 @ =0x0000FFFF\n"
        "    cmp r4, r0\n"
        "    beq .L08009478\n"
        "    b .L0800947E\n"
        "    .align 2, 0\n"
        ".L0800946C: .word REG_MOSAIC\n"
        ".L08009470: .word 0x0000FFFF\n"
        ".L08009474:\n"
        "    cmp r4, #0\n"
        "    bne .L0800947E\n"
        ".L08009478:\n"
        "    movs r0, #0\n"
        "    strh r0, [r5, #4]\n"
        "    b .L0800949E\n"
        ".L0800947E:\n"
        "    adds r0, r4, r7\n"
        "    cmp r0, #0\n"
        "    bge .L08009488\n"
        "    movs r0, #0\n"
        "    b .L08009490\n"
        ".L08009488:\n"
        "    ldr r1, .L08009498 @ =0x0000FFFF\n"
        "    cmp r0, r1\n"
        "    ble .L08009490\n"
        "    adds r0, r1, #0\n"
        ".L08009490:\n"
        "    strh r0, [r5, #0xe]\n"
        "    movs r0, #1\n"
        "    b .L0800949E\n"
        "    .align 2, 0\n"
        ".L08009498: .word 0x0000FFFF\n"
        ".L0800949C:\n"
        "    movs r0, #0\n"
        ".L0800949E:\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
