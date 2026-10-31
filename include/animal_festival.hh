#ifndef ANIMAL_FESTIVAL_HH
#define ANIMAL_FESTIVAL_HH

#include "prelude.h"

struct AnimalFestivalRandomRangePair
{
    u32 first_minimum;
    u32 first_maximum;
    u32 second_minimum;
    u32 second_maximum;
};

extern AnimalFestivalRandomRangePair const gAnimalFestivalRandomRangePairs[];

enum
{
    ANIMAL_FESTIVAL_LIVESTOCK_CONTESTANT_NAME_COUNT = 40,
    ANIMAL_FESTIVAL_LIVESTOCK_CONTESTANT_NAME_WIDTH = 13,
};

// Direct-indexed fixed-width rows, not a pointer table.
extern char const gCppRuntimeBadAlloc_AnimalFestivalLivestockContestantNames[];
extern char const gText_AnimalFestival_LivestockContestantNames[ANIMAL_FESTIVAL_LIVESTOCK_CONTESTANT_NAME_COUNT][ANIMAL_FESTIVAL_LIVESTOCK_CONTESTANT_NAME_WIDTH];

// Native code indexes each contestant row as four unclassified byte values.
extern u8 const gAnimalFestivalLivestockContestantValues[][4];


#include "game_scene.hh"
#include "hardware_bootstrap.hh"
#include "smart_ptr.hh"
#pragma interface "animal_festival.hh"

// The large native selection core derives from HardwareBootstrap. Its full
// roster and UI storage remain native; only its real base is owned here.
struct FestivalAnimalSelectionScene : AScene {
    FestivalAnimalSelectionScene(SceneTransitionOwner next, GameStateSaveImage * image,
        MaryFestivalAnimalKind kind);
    virtual ~FestivalAnimalSelectionScene();
    virtual SceneTransitionOwner Run();
    SmartPtr<HardwareBootstrap> core;
};
typedef char FestivalAnimalSelectionSceneSizeCheck[sizeof(FestivalAnimalSelectionScene) == 8 ? 1 : -1];
typedef char FestivalAnimalSelectionSceneCoreCheck[offsetof(FestivalAnimalSelectionScene, core) == 4 ? 1 : -1];

struct FestivalAnimalSelectionTransition : SceneTransition {
    FestivalAnimalSelectionTransition(SceneTransitionOwner next, GameStateSaveImage * image,
        MaryFestivalAnimalKind input_kind)
        : continuation(next), save(image), kind(input_kind) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryFestivalAnimalKind kind;
};
typedef char FestivalAnimalSelectionTransitionSizeCheck[sizeof(FestivalAnimalSelectionTransition) == 16 ? 1 : -1];
typedef char FestivalAnimalSelectionTransitionContinuationCheck[offsetof(FestivalAnimalSelectionTransition, continuation) == 4 ? 1 : -1];
typedef char FestivalAnimalSelectionTransitionSaveCheck[offsetof(FestivalAnimalSelectionTransition, save) == 8 ? 1 : -1];
typedef char FestivalAnimalSelectionTransitionKindCheck[offsetof(FestivalAnimalSelectionTransition, kind) == 12 ? 1 : -1];
#pragma implementation

EXTERN_C
SceneTransitionOwner RunFestivalAnimalSelectionCore(HardwareBootstrap * core);
EXTERN_C_END

#endif // ANIMAL_FESTIVAL_HH
