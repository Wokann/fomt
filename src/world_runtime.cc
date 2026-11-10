#include "prelude.h"
#include <algorithm>
#include "entity_actor.hh"
#include "world_runtime.hh"
#include "game_world.hh"
#include "entity_auxiliary_sprites.hh"
#include "world_sprite_effects.hh"
#include "scene_sprite.hh"

inline GameSceneWorldUnk1028::GameSceneWorldUnk1028()
    : unk_04(0, 0), unk_09(0) {}

GameSceneWorldData::GameSceneWorldData(GameSceneWorldMapOwner source)
    : map(source), unk_194(0), actor_archive(gActorIndexedResourceArchive),
#if defined(REGION_JP)
      unk_DE0(gUnk_083ED9FC),
      unk_E10(gUnk_084A5068),
      unk_E40(gUnk_08480BDC),
      unk_E70(gUnk_084A3678),
      unk_EA0(gUnk_084A4F3C),
      unk_ED0(gUnk_084A4E14),
      unk_F00(gUnk_083ED1BC),
      unk_F30(gUnk_084ADBDC),
      unk_F60(gUnk_084ACE34),
      unk_F90(gUnk_084AD4D0),
      unk_FC0(gUnk_084ABF08),
      unk_FF0(gUnk_08479108)
#else
      unk_DE0(gUnk_086678A0),
      unk_E10(gUnk_0871EF00),
      unk_E40(gUnk_086FAA80),
      unk_E70(gUnk_0871D51C),
      unk_EA0(gUnk_0871EDD4),
      unk_ED0(gUnk_0871ECAC),
      unk_F00(gUnk_08667060),
      unk_F30(gUnk_08727A74),
      unk_F60(gUnk_08726CCC),
      unk_F90(gUnk_08727368),
      unk_FC0(gUnk_08725DA0),
      unk_FF0(gUnk_086F2FAC)
#endif
{
    std::fill(entities, EntitiesEnd(), static_cast<AEntity *>(nullptr));
}

GameSceneWorldData::~GameSceneWorldData()
{
    u32 index = 0;
    AEntity ** current = entities;
    for (; index < ARRAY_COUNT(entities); ++index) {
        delete *current;
        ++current;
    }
}

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    .cpu arm7tdmi\n"
    "\n"
    "    @ Native retained OBJ palette-bank acquisition.\n"
    "\n"
    "\n"
    "    .global AcquirePaletteBank__21GameScenePaletteCacheUi\n"
    "    .type AcquirePaletteBank__21GameScenePaletteCacheUi, %function\n"
    "    .thumb_func\n"
    "AcquirePaletteBank__21GameScenePaletteCacheUi:\n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tadds r4, r0, #0\n"
    "\tadds r5, r1, #0\n"
    "\tlsls r0, r5, #5\n"
    "\tadds r0, r0, r5\n"
    "\tlsls r0, r0, #2\n"
    "\tadds r0, r4, r0\n"
    "\tadds r6, r0, #0\n"
    "\tadds r6, #0xa0\n"
    "\tldrb r0, [r6]\n"
    "\tmvns r0, r0\n"
    "\tlsls r0, r0, #0x18\n"
    "\tlsrs r7, r0, #0x1f\n"
    "\tcmp r7, #0\n"
    "\tbeq .L080AC9A4\n"
    "\tmovs r2, #0\n"
    "\tldrsb r2, [r6, r2]\n"
    "\tldr r0, .L080AC9A0 @ =0x00000B78\n"
    "\tadds r1, r4, r0\n"
    "\tlsls r0, r2, #1\n"
    "\tadds r0, r0, r2\n"
    "\tlsls r0, r0, #2\n"
    "\tadds r1, r1, r0\n"
    ".L080AC99A:\n"
    "\tldrb r0, [r1, #8]\n"
    "\tb .L080AC9E4\n"
    "\t.align 2, 0\n"
    ".L080AC9A0: .word 0x00000B78\n"
    ".L080AC9A4:\n"
    "\tldr r0, .L080AC9D8 @ =0x00000C14\n"
    "\tadds r2, r4, r0\n"
    "\tldrb r3, [r2]\n"
    "\tcmp r3, #0xd\n"
    "\tbhs .L080AC9E0\n"
    "\tadds r1, r3, #0\n"
    "\tadds r0, r1, #1\n"
    "\tstrb r0, [r2]\n"
    "\tldr r0, .L080AC9DC @ =0x00000B78\n"
    "\tadds r2, r4, r0\n"
    "\tlsls r0, r1, #1\n"
    "\tadds r0, r0, r1\n"
    "\tlsls r0, r0, #2\n"
    "\tadds r1, r2, r0\n"
    "\tmovs r0, #9\n"
    "\tldrsb r0, [r1, r0]\n"
    "\tcmp r0, r5\n"
    "\tbeq .L080AC9CC\n"
    "\tstrb r5, [r1, #9]\n"
    "\tstrb r7, [r1, #0xa]\n"
    ".L080AC9CC:\n"
    "\tmovs r0, #0\n"
    "\tldrsb r0, [r6, r0]\n"
    "\tcmp r0, r3\n"
    "\tbeq .L080AC99A\n"
    "\tstrb r3, [r6]\n"
    "\tb .L080AC99A\n"
    "\t.align 2, 0\n"
    ".L080AC9D8: .word 0x00000C14\n"
    ".L080AC9DC: .word 0x00000B78\n"
    ".L080AC9E0:\n"
    "\tmovs r0, #1\n"
    "\trsbs r0, r0, #0\n"
    ".L080AC9E4:\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    "\t.align 2, 0\n"
);
