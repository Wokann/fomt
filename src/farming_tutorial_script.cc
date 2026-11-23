#include "farming_tutorial_script.hh"
#include FOMT_TEXT_INCLUDE(farming_tutorial_script.cc)
#if defined(REGION_JP)
#include "data/scripts/jp/fomt_scripts.mary.h"
#elif defined(REGION_EU)
#include "data/scripts/eu/fomt_scripts.mary.h"
#elif defined(REGION_DE)
#include "data/scripts/de/fomt_scripts.mary.h"
#else
#include "data/scripts/us/fomt_scripts.mary.h"
#endif

u16 const gFarmingTutorialScriptIds[] ALIGN(2) = {
    EventScript_1063_TutorialEvent_CropFarmingInstructions,
    EventScript_1059_SystemMenu_SelectAnimalCategory,
};

#include "farming_tutorial.hh"

void FarmingTutorialScene::Push(i32 value)
{
    stack.Push(value);
}
