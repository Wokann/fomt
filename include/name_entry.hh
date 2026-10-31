#ifndef NAME_ENTRY_HH
#define NAME_ENTRY_HH

#include "prelude.h"
#include "scene.hh"
#include "fomt_constants.hh"
#pragma interface "name_entry.hh"

struct GameStateSaveImage;

// This saved-target naming operation is distinct from the reusable keyboard.
// Run handles the six NAME_ENTRY_* cases and edits the save image.
struct SavedNameEntryScene : AScene {
    SavedNameEntryScene(SceneTransitionOwner next, GameStateSaveImage * image,
        MaryNameEntryKind input_kind, u8 index)
        : continuation(next), save(image), kind(input_kind), target_index(index) {}
    virtual SceneTransitionOwner Run();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryNameEntryKind kind;
    u8 target_index;
};

struct SavedNameEntryTransition : SceneTransition {
    SavedNameEntryTransition(SceneTransitionOwner next, GameStateSaveImage * image,
        MaryNameEntryKind input_kind, u8 index)
        : continuation(next), save(image), kind(input_kind), target_index(index) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryNameEntryKind kind;
    u8 target_index;
};
typedef char SavedNameEntrySceneSizeCheck[sizeof(SavedNameEntryScene) == 20 ? 1 : -1];
typedef char SavedNameEntryTransitionSizeCheck[sizeof(SavedNameEntryTransition) == 20 ? 1 : -1];
typedef char SavedNameEntrySceneContinuationCheck[offsetof(SavedNameEntryScene, continuation) == 4 ? 1 : -1];
typedef char SavedNameEntrySceneSaveCheck[offsetof(SavedNameEntryScene, save) == 8 ? 1 : -1];
typedef char SavedNameEntrySceneKindCheck[offsetof(SavedNameEntryScene, kind) == 12 ? 1 : -1];
typedef char SavedNameEntryTransitionContinuationCheck[offsetof(SavedNameEntryTransition, continuation) == 4 ? 1 : -1];
typedef char SavedNameEntryTransitionSaveCheck[offsetof(SavedNameEntryTransition, save) == 8 ? 1 : -1];
typedef char SavedNameEntryTransitionKindCheck[offsetof(SavedNameEntryTransition, kind) == 12 ? 1 : -1];
typedef char SavedNameEntrySceneIndexCheck[offsetof(SavedNameEntryScene, target_index) == 16 ? 1 : -1];
typedef char SavedNameEntryTransitionIndexCheck[offsetof(SavedNameEntryTransition, target_index) == 16 ? 1 : -1];

// Directly selected possessive labels for farm entities.  Each literal owns
// its normal C terminator; normal object alignment supplies the spacing.
extern char const gText_Possessive_Horse[];
extern char const gText_Possessive_Cow[];
extern char const gText_Possessive_Sheep[];
extern char const gText_Possessive_Chicken[];
extern char const gText_Possessive_Child[];
extern char const gText_Possessive_Player[];
extern char const gCppRuntimeBadAlloc_PossessiveLabelsTrailer[];

#endif // NAME_ENTRY_HH
