#ifndef NAME_ENTRY_LIFETIMES_HH
#define NAME_ENTRY_LIFETIMES_HH

#include "prelude.h"
#include "scene.hh"
#include "fomt_constants.hh"

struct GameStateSaveImage;

#pragma interface "name_entry_lifetimes.hh"

// Run edits the selected saved name; cleanup owns only the continuation.
struct SavedNameEntryScene : AScene {
    SavedNameEntryScene(SceneTransitionOwner next, GameStateSaveImage * image,
        MaryNameEntryKind input_kind, u8 index);
    virtual SceneTransitionOwner Run();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryNameEntryKind kind;
    u8 target_index;
};

typedef char SavedNameEntrySceneSizeCheck[sizeof(SavedNameEntryScene) == 20 ? 1 : -1];
typedef char SavedNameEntrySceneContinuationCheck[offsetof(SavedNameEntryScene, continuation) == 4 ? 1 : -1];
typedef char SavedNameEntrySceneSaveCheck[offsetof(SavedNameEntryScene, save) == 8 ? 1 : -1];
typedef char SavedNameEntrySceneKindCheck[offsetof(SavedNameEntryScene, kind) == 12 ? 1 : -1];
typedef char SavedNameEntrySceneIndexCheck[offsetof(SavedNameEntryScene, target_index) == 16 ? 1 : -1];


#endif // NAME_ENTRY_LIFETIMES_HH
