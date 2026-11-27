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



#endif // NAME_ENTRY_LIFETIMES_HH
