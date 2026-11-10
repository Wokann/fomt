#pragma implementation "scene_minigames.cc"
#include "prelude.h"
#include "scene_minigames.hh"
#include "game_scene.hh"
#include "game_state.hh"
#include "game_scene_return.hh"
#include "scene_animal_care_minigame.hh"
#include "scene_harvesting_minigame.hh"
#include "scene_watering_minigame.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    .align 2, 0\n"
    "\n"
    "\tthumb_func_start Run__27ChickenFestivalContestScene\n"
    "Run__27ChickenFestivalContestScene: @ 0x080A37A8\n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tmov r7, sl\n"
    "\tmov r6, sb\n"
    "\tmov r5, r8\n"
    "\tpush {r5, r6, r7}\n"
    "\tsub sp, #0x40\n"
    "\tmov sl, r0\n"
    "\tadds r5, r1, #0\n"
    "\tldr r0, [r5, #8]\n"
    "\tmovs r1, #0x82\n"
    "\tlsls r1, r1, #3\n"
    "\tadds r0, r0, r1\n"
    "\tbl GetUnkEnt__C4Coop\n"
    "\tadds r1, r0, #0\n"
    "\tmovs r0, #1\n"
    "\trsbs r0, r0, #0\n"
    "\tcmp r1, r0\n"
    "\tbne .L080A37E4\n"
    "\tldr r0, [r5, #4]\n"
    "\tmovs r2, #0\n"
    "\tstr r2, [r5, #4]\n"
    "\tstr r0, [sp]\n"
    "\tmov r1, sp\n"
    "\tstr r1, [sp, #0x20]\n"
    "\tstr r0, [sp, #0x24]\n"
    "\tstr r2, [r1]\n"
    "\tmov r2, sl\n"
    "\tstr r0, [r2]\n"
    "\tb .L080A380A\n"
    ".L080A37E4:\n"
    "\tldr r0, [r5, #8]\n"
    "\tmovs r2, #0x82\n"
    "\tlsls r2, r2, #3\n"
    "\tadds r0, r0, r2\n"
    "\tbl GetChicken__4CoopUi\n"
    "\tmov r8, r0\n"
    "\tcmp r0, #0\n"
    "\tbne .L080A381E\n"
    "\tldr r1, [r5, #4]\n"
    "\tstr r0, [r5, #4]\n"
    "\tstr r1, [sp]\n"
    "\tmov r0, sp\n"
    "\tstr r0, [sp, #0x28]\n"
    "\tstr r1, [sp, #0x2c]\n"
    "\tmov r2, r8\n"
    "\tstr r2, [r0]\n"
    "\tmov r0, sl\n"
    "\tstr r1, [r0]\n"
    ".L080A380A:\n"
    "\tldr r1, [sp]\n"
    "\tcmp r1, #0\n"
    "\tbeq .L080A38EC\n"
    "\tldr r0, [r1]\n"
    "\tldr r2, [r0, #8]\n"
    "\tadds r0, r1, #0\n"
    "\tmovs r1, #3\n"
    "\tbl _call_via_r2\n"
    "\tb .L080A38EC\n"
    ".L080A381E:\n"
    "\tadd r7, sp, #4\n"
    "\tadds r0, r7, #0\n"
    "\tbl __22ChickenFestivalEntrant\n"
    "\tldr r0, [r5, #8]\n"
    "\tmovs r3, #0xc8\n"
    "\tstr r3, [sp, #0x30]\n"
    "\tldrb r0, [r0, #0x10]\n"
    "\tlsrs r2, r0, #3\n"
    "\tlsls r1, r2, #3\n"
    "\tsubs r1, r1, r2\n"
    "\tlsls r0, r0, #0x1d\n"
    "\tlsrs r0, r0, #0x1d\n"
    "\tadds r1, r1, r0\n"
    "\tstr r1, [sp, #0x34]\n"
    "\tadd r2, sp, #0x34\n"
    "\tadd r0, sp, #0x30\n"
    "\tcmp r3, r1\n"
    "\tbls .L080A3846\n"
    "\tadds r0, r2, #0\n"
    ".L080A3846:\n"
    "\tldr r0, [r0]\n"
    "\tmovs r1, #0\n"
    "\tmov sb, r1\n"
    "\tstrb r0, [r7, #0x10]\n"
    "\tmov r0, r8\n"
    "\tbl GetName__C6Animal\n"
    "\tadds r6, r0, #0\n"
    "\tbl strlen\n"
    "\tadds r4, r0, #0\n"
    "\tcmp r4, #0xc\n"
    "\tbls .L080A3862\n"
    "\tmovs r4, #0xc\n"
    ".L080A3862:\n"
    "\tadds r0, r7, #0\n"
    "\tadds r1, r6, #0\n"
    "\tadds r2, r4, #0\n"
    "\tbl memcpy\n"
    "\tadds r0, r7, r4\n"
    "\tmov r2, sb\n"
    "\tstrb r2, [r0]\n"
    "\tmov r0, r8\n"
    "\tbl GetAffection__C6Animal\n"
    "\tstrb r0, [r7, #0x11]\n"
    "\tadd r6, sp, #0x18\n"
    "\tadds r0, r6, #0\n"
    "\tadds r1, r7, #0\n"
    "\tbl __28ChickenFestivalMinigameSceneRC22ChickenFestivalEntrant\n"
    "\tmov r0, sp\n"
    "\tadds r1, r6, #0\n"
    "\tbl Run__28ChickenFestivalMinigameScene\n"
    "\tldr r1, [sp]\n"
    "\tcmp r1, #0\n"
    "\tbeq .L080A389E\n"
    "\tldr r0, [r1]\n"
    "\tldr r2, [r0, #8]\n"
    "\tadds r0, r1, #0\n"
    "\tmovs r1, #3\n"
    "\tbl _call_via_r2\n"
    ".L080A389E:\n"
    "\tadds r0, r6, #0\n"
    "\tbl HasWon__C28ChickenFestivalMinigameScene\n"
    "\tlsls r0, r0, #0x18\n"
    "\tcmp r0, #0\n"
    "\tbeq .L080A38B0\n"
    "\tmov r0, r8\n"
    "\tbl SetFestivalWinner__6Animal\n"
    ".L080A38B0:\n"
    "\tldr r4, [r5, #4]\n"
    "\tadds r0, r6, #0\n"
    "\tbl HasWon__C28ChickenFestivalMinigameScene\n"
    "\tstrb r0, [r4, #0xc]\n"
    "\tldr r1, [r5, #4]\n"
    "\tmov r0, sb\n"
    "\tstr r0, [r5, #4]\n"
    "\tstr r1, [sp]\n"
    "\tmov r2, sp\n"
    "\tstr r2, [sp, #0x38]\n"
    "\tstr r1, [sp, #0x3c]\n"
    "\tadds r0, r2, #0\n"
    "\tmov r2, sb\n"
    "\tstr r2, [r0]\n"
    "\tmov r0, sl\n"
    "\tstr r1, [r0]\n"
    "\tldr r1, [sp]\n"
    "\tcmp r1, #0\n"
    "\tbeq .L080A38E4\n"
    "\tldr r0, [r1]\n"
    "\tldr r2, [r0, #8]\n"
    "\tadds r0, r1, #0\n"
    "\tmovs r1, #3\n"
    "\tbl _call_via_r2\n"
    ".L080A38E4:\n"
    "\tadds r0, r6, #0\n"
    "\tmovs r1, #2\n"
    "\tbl _._28ChickenFestivalMinigameScene\n"
    ".L080A38EC:\n"
    "\tmov r0, sl\n"
    "\tadd sp, #0x40\n"
    "\tpop {r3, r4, r5}\n"
    "\tmov r8, r3\n"
    "\tmov sb, r4\n"
    "\tmov sl, r5\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    "\t.align 2, 0\n"
    "\n"
);

SceneTransitionOwner HarvestSpriteAnimalCareScene::Run()
{
    HarvestSpriteAnimalCareSetup setup;
    switch (sprite_id)
    {
    case CHARACTER_STAID: setup.sprite_variant = 0; break;
    case CHARACTER_NAPPY: setup.sprite_variant = 2; break;
    case CHARACTER_BOLD: setup.sprite_variant = 3; break;
    case CHARACTER_CHEF: setup.sprite_variant = 4; break;
    case CHARACTER_AQUA: setup.sprite_variant = 5; break;
    case CHARACTER_HOGGY: setup.sprite_variant = 6; break;
    case CHARACTER_TIMID: setup.sprite_variant = 1; break;
    }
    HarvestSprite * sprite = save->npcs.GetHarvestSpriteByCharacterId(sprite_id);
    setup.experience = sprite->GetMinigameExp(HarvestSprite::TASK_ANIMALS);
    HarvestSpriteAnimalCareUiScene ui(setup);
    ui.Run();
    bool succeeded = ui.Succeeded();
    sprite->SetPlayedMinigame(HarvestSprite::TASK_ANIMALS, succeeded);
    static_cast<ReturnToGameScene *>(continuation.get())->SetHarvestSpriteMinigameResult(succeeded);
    save->UpdateUnknown18(ui.GetUnkRecordValue());
    return SceneTransitionOwner(continuation.release());
}

SceneTransitionOwner HarvestSpriteHarvestingScene::Run()
{
    HarvestSpriteHarvestingSetup setup;
    switch (sprite_id)
    {
    case CHARACTER_STAID: setup.sprite_variant = 0; break;
    case CHARACTER_NAPPY: setup.sprite_variant = 2; break;
    case CHARACTER_BOLD: setup.sprite_variant = 3; break;
    case CHARACTER_CHEF: setup.sprite_variant = 4; break;
    case CHARACTER_AQUA: setup.sprite_variant = 5; break;
    case CHARACTER_HOGGY: setup.sprite_variant = 6; break;
    case CHARACTER_TIMID: setup.sprite_variant = 1; break;
    }
    HarvestSprite * sprite = save->npcs.GetHarvestSpriteByCharacterId(sprite_id);
    setup.experience = sprite->GetMinigameExp(HarvestSprite::TASK_HARVEST);
    HarvestSpriteHarvestingUiScene ui(setup);
    ui.Run();
    bool succeeded = ui.Succeeded();
    sprite->SetPlayedMinigame(HarvestSprite::TASK_HARVEST, succeeded);
    static_cast<ReturnToGameScene *>(continuation.get())->SetHarvestSpriteMinigameResult(succeeded);
    save->UpdateUnknown13(ui.GetUnkRecordValue());
    return SceneTransitionOwner(continuation.release());
}

SceneTransitionOwner HarvestSpriteWateringScene::Run()
{
    HarvestSpriteWateringSetup setup;
    switch (sprite_id)
    {
    case CHARACTER_STAID: setup.sprite_variant = 0; break;
    case CHARACTER_NAPPY: setup.sprite_variant = 2; break;
    case CHARACTER_BOLD: setup.sprite_variant = 3; break;
    case CHARACTER_CHEF: setup.sprite_variant = 4; break;
    case CHARACTER_AQUA: setup.sprite_variant = 5; break;
    case CHARACTER_HOGGY: setup.sprite_variant = 6; break;
    case CHARACTER_TIMID: setup.sprite_variant = 1; break;
    }
    HarvestSprite * sprite = save->npcs.GetHarvestSpriteByCharacterId(sprite_id);
    setup.experience = sprite->GetMinigameExp(HarvestSprite::TASK_WATER);
    HarvestSpriteWateringUiScene ui(setup);
    ui.Run();
    bool succeeded = ui.Succeeded();
    sprite->SetPlayedMinigame(HarvestSprite::TASK_WATER, succeeded);
    static_cast<ReturnToGameScene *>(continuation.get())->SetHarvestSpriteMinigameResult(succeeded);
    save->UpdateUnknown25(ui.GetUnkRecordValue());
    return SceneTransitionOwner(continuation.release());
}
