#include "farming_tutorial_script.hh"
#include FOMT_TEXT_INCLUDE(farming_tutorial_script.cc)
#include "data/scripts/fomt_scripts.mary.h"

u16 const gFarmingTutorialScriptIds[] ALIGN(2) = {
    EventScript_1063_TutorialEvent_CropFarmingInstructions,
    EventScript_1059_SystemMenu_SelectAnimalCategory,
};

#include "farming_tutorial.hh"

void FarmingTutorialScene::Push(i32 value)
{
    stack.Push(value);
}
