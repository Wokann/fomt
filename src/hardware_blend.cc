#include "hardware_blend.hh"
#include "gbaio.h"

#include <new>

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

template<u32 Maximum>
inline u32 ScaleHardwareBlendProgress(u32 progress)
{
    if (progress >= 0xFFFF)
        return Maximum;
    if (progress == 0)
        return 0;
    return ((progress * (Maximum - 1)) >> 16) + 1;
}

bool HardwareBlendController::Update()
{
    HardwareBlendState * state = this->state;
    i32 step = state->step;
    if (step != 0)
    {
        u16 progress = state->progress;
        if (state->mode != 0)
        {
            u32 effect = 0;
            if (state->mode != 1)
            {
                if (state->mode == 2)
                    effect = BLDCNT_EFFECT_DARKEN;
            }
            else
                effect = BLDCNT_EFFECT_LIGHTEN;

            HardwareDisplayState * display = state->display;
            // The optional shadow has the same register offsets as MMIO.
            volatile u16 * control;
            if (display != 0)
            {
                control = reinterpret_cast<volatile u16 *>(display);
                control = reinterpret_cast<volatile u16 *>(reinterpret_cast<volatile u8 *>(control)
                    + offsetof(HardwareDisplayState, blend_control));
            }
            else
                control = &REG_BLDCNT;
            *control = (*control & ~BLDCNT_EFFECT_MASK) | effect;

            volatile u16 * brightness;
            if (display != 0)
            {
                brightness = reinterpret_cast<volatile u16 *>(display);
                brightness = reinterpret_cast<volatile u16 *>(reinterpret_cast<volatile u8 *>(brightness)
                    + offsetof(HardwareDisplayState, blend_brightness));
            }
            else
                brightness = &REG_BLDY;
            *brightness = ScaleHardwareBlendProgress<16>(progress);
        }

        if (state->mosaic_enabled)
        {
            u32 size = ScaleHardwareBlendProgress<15>(progress);
            size |= size << 4;
            size |= size << 8;
            volatile u16 * mosaic;
            if (state->display != 0)
            {
                mosaic = reinterpret_cast<volatile u16 *>(state->display);
                mosaic = reinterpret_cast<volatile u16 *>(reinterpret_cast<volatile u8 *>(mosaic)
                    + offsetof(HardwareDisplayState, mosaic));
            }
            else
                mosaic = &REG_MOSAIC;
            *mosaic = size;
        }

        if ((step >= 0 && progress == 0xFFFF) || (step < 0 && progress == 0))
        {
            state->step = 0;
            return false;
        }
        i32 next = progress + step;
        if (next < 0)
            next = 0;
        else if (next > 0xFFFF)
            next = 0xFFFF;
        state->progress = next;
        return true;
    }
    return false;
}

i16 HardwareBlendController::GetStep() const
{
    return this->state->step;
}

bool HardwareBlendObject::Run()
{
    return blend.Update();
}

HardwareBlendObject::~HardwareBlendObject()
{
}

u32 HardwareBlendObject::IsActive() const
{
    return blend.GetStep() != 0;
}

i16 HardwareBlendObject::GetStep() const
{
    return blend.GetStep();
}

i16 HardwareBlendObject::SetStep(i16 step)
{
    return blend.SetStep(step);
}

void HardwareBlendObject::End(i16 step, u32 mode, u32 mosaic)
{
    EndHardwareBlend(&blend, step, mode, mosaic);
}

void HardwareBlendObject::Begin(i16 step, u32 mode, u32 mosaic)
{
    BeginHardwareBlend(&blend, step, mode, mosaic);
}

HardwareDisplayState * HardwareBlendObject::SetDisplay(HardwareDisplayState * display)
{
    return blend.SetDisplay(display);
}

asm_unified(
    ".pushsection .iwram, \"ax\", %progbits\n"
    ".include \"asm/macro.inc\"\n"
    "arm_func_start BlendRgb5PaletteBank\n"
    "BlendRgb5PaletteBank:\n"
    "    push {r4, r5, r6, r7, r8, sb, sl, fp, lr}\n"
    "    and sb, r3, #0x1f\n"
    "    add r8, sb, #1\n"
    "    lsr r3, r3, #5\n"
    "    and r3, r3, #0x1f\n"
    "    add r6, r3, #1\n"
    "    add sl, r0, #0x20\n"
    "    mov r5, #0x7c000000\n"
    "    add r5, r5, #0x1f0000\n"
    "    lsr r4, r5, #0x10\n"
    "    .Lauto_03000C54:\n"
    "    ldr r7, [r2], #4\n"
    "    and sb, r7, r5\n"
    "    and r3, r7, #0x3e00000\n"
    "    orr r3, r3, sb, lsr #16\n"
    "    mul ip, r6, r3\n"
    "    ldr fp, [r1], #4\n"
    "    and sb, fp, r5\n"
    "    and r3, fp, #0x3e00000\n"
    "    orr lr, r3, sb, lsr #16\n"
    "    and r3, r7, r4\n"
    "    and r7, r7, #0x3e0\n"
    "    orr r3, r3, r7, lsl #16\n"
    "    mul sb, r6, r3\n"
    "    mla ip, r8, lr, ip\n"
    "    and r3, fp, r4\n"
    "    and fp, fp, #0x3e0\n"
    "    orr lr, r3, fp, lsl #16\n"
    "    and r7, r5, ip, lsl #11\n"
    "    lsr r3, ip, #5\n"
    "    mla ip, r8, lr, sb\n"
    "    and r3, r3, #0x3e00000\n"
    "    orr r7, r7, r3\n"
    "    and sb, r4, ip, lsr #5\n"
    "    lsr r3, ip, #0x15\n"
    "    and r3, r3, #0x3e0\n"
    "    orr sb, sb, r3\n"
    "    orr r7, r7, sb\n"
    "    str r7, [r0], #4\n"
    "    cmp r0, sl\n"
    "    bne .Lauto_03000C54\n"
    "    pop {r4, r5, r6, r7, r8, sb, sl, fp, lr}\n"
    "    bx lr\n"
    ".popsection\n"
    ".thumb\n"
);
