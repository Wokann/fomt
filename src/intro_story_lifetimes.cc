#pragma implementation "intro_story_lifetimes.hh"
#include "intro_story_lifetimes.hh"

UiTextSubstitution IntroStoryTextVariables::Lookup(u32 code)
{
    if (code == 0xFF)
        return UiTextSubstitution(true, FixedStr<31>(player_name));
    return UiTextSubstitution(false, FixedStr<31>());
}

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start _._19IntroStorySceneCore\n"
    "_._19IntroStorySceneCore:\n"
    "    push {r4, r5, lr}\n"
    "    adds r4, r0, #0\n"
    "    adds r5, r1, #0\n"
    "    ldr r0, .Lintro_story_variables_offset\n"
    "    adds r1, r4, r0\n"
    "    ldr r0, .Lintro_story_variable_base_vtable\n"
    "    str r0, [r1, #0]\n"
    "    ldr r0, [r4, #16]\n"
    "    cmp r0, #0\n"
    "    beq .Lintro_story_cleanup_base\n"
    "    movs r1, #3\n"
    "    bl _._12UiStateOwner\n"
    ".Lintro_story_cleanup_base:\n"
    "    adds r0, r4, #0\n"
    "    adds r1, r5, #0\n"
    "    bl _._15HardwareContext\n"
    "    pop {r4, r5}\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
    ".Lintro_story_variables_offset: .word 0x6428\n"
    ".Lintro_story_variable_base_vtable: .word __vt_23ScriptTextVariableStore\n"
);
