#include "scene_blacksmith_shop.hh"
#include "scene_blacksmith_upgrade.hh"

SceneOwner BlacksmithShopResultTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(new BlacksmithShopResultScene(SceneTransitionOwner(next), save, has_purchased));
}

// The original cleanup does not reinstall this class's vtable. An explicit
// empty C++ destructor currently adds that store; retain the native member
// until its implicit-definition ownership is recovered.
asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "thumb_func_start _._30BlacksmithShopResultTransition\n"
    "_._30BlacksmithShopResultTransition:\n"
    "push {r4, r5, lr}\n"
    "adds r4, r0, #0\n"
    "adds r5, r1, #0\n"
    "ldr r1, [r4, #4]\n"
    "cmp r1, #0\n"
    "beq .Lblacksmith_transition_base_cleanup\n"
    "ldr r0, [r1]\n"
    "ldr r2, [r0, #8]\n"
    "adds r0, r1, #0\n"
    "movs r1, #3\n"
    "bl _call_via_r2\n"
    ".Lblacksmith_transition_base_cleanup:\n"
    "adds r0, r4, #0\n"
    "adds r1, r5, #0\n"
    "bl _._15SceneTransition\n"
    "pop {r4, r5}\n"
    "pop {r0}\n"
    "bx r0\n"
    ".align 2, 0\n"
);
