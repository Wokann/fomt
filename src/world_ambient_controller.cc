#include "world_ambient_sprites.hh"

asm(".include \"asm/macro.inc\"\n");

inline WorldAmbientSpriteController::SpriteOwner * WorldAmbientSpriteController::Data()
{
    return sprites.Data();
}

inline WorldAmbientSpriteController::SpriteOwner * WorldAmbientSpriteController::End()
{
    return sprites.End();
}

void WorldAmbientSpriteController::Draw(EntityDrawContext const & context)
{
    GameObject * world = entity->GetGameObject();
    WorldSpriteDrawBuffer * buffer = context.buffer;
    HardwareDmaQueue * queue = context.queue;
    SpriteOwner * first = Data();
    SpriteOwner * last = End();
    while (first != last) {
        if (first->Get())
            (*first)->Draw(world, buffer, queue);
        ++first;
    }
}

void WorldAmbientSpriteController::Update()
{
    SpriteOwner * first = Data();
    SpriteOwner * last = End();
    while (first != last) {
        if (first->Get())
            (*first)->Update();
        ++first;
    }
}

asm_unified(
    ".text\n"
    "    thumb_func_start _._28WorldAmbientSpriteController\n"
    "_._28WorldAmbientSpriteController:\n"
    "    push {r4, r5, lr}\n"
    "    sub sp, #16\n"
    "    adds r4, r0, #0\n"
    "    adds r5, r1, #0\n"
    "    ldr r0, .Lambient_7_0\n"
    "    str r0, [r4, #4]\n"
    "    ldr r0, [r4, #8]\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, r0, r4\n"
    "    adds r0, #12\n"
    "    str r0, [sp, #4]\n"
    "    adds r0, r4, #0\n"
    "    adds r0, #12\n"
    "    str r0, [sp, #12]\n"
    "    b .Lambient_7_3\n"
    "    .align 2, 0\n"
    ".Lambient_7_0: .word __vt_28WorldAmbientSpriteController\n"
    ".Lambient_7_1:\n"
    "    subs r0, r2, #4\n"
    "    ldr r1, [r0, #0]\n"
    "    cmp r1, #0\n"
    "    beq .Lambient_7_2\n"
    "    ldr r0, [r1, #76]\n"
    "    ldr r2, [r0, #8]\n"
    "    adds r0, r1, #0\n"
    "    movs r1, #3\n"
    "    bl _call_via_r2\n"
    ".Lambient_7_2:\n"
    "    ldr r0, [sp, #4]\n"
    "    subs r0, #4\n"
    "    str r0, [sp, #4]\n"
    ".Lambient_7_3:\n"
    "    ldr r2, [sp, #4]\n"
    "    ldr r0, [sp, #12]\n"
    "    movs r1, #0\n"
    "    cmp r2, r0\n"
    "    bne .Lambient_7_4\n"
    "    movs r1, #1\n"
    ".Lambient_7_4:\n"
    "    cmp r1, #0\n"
    "    beq .Lambient_7_1\n"
    "    ldr r0, .Lambient_7_6\n"
    "    str r0, [r4, #4]\n"
    "    movs r0, #1\n"
    "    ands r0, r5\n"
    "    cmp r0, #0\n"
    "    beq .Lambient_7_5\n"
    "    adds r0, r4, #0\n"
    "    bl __builtin_delete\n"
    ".Lambient_7_5:\n"
    "    add sp, #16\n"
    "    pop {r4, r5}\n"
    "    pop {r0}\n"
    "    bx r0\n"
    ".Lambient_7_6: .word __vt_22EntityVisualController\n"
);
