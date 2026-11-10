#ifndef NAME_ENTRY_HH
#define NAME_ENTRY_HH

#include "scene.hh"
#include "fomt_constants.hh"
#include "name_entry_lifetimes.hh"
#pragma interface "name_entry.hh"

// This body is also inlined by the scene transition factory. Its retained
// standalone entry follows Run in the ordinary name-entry implementation.
inline SavedNameEntryScene::SavedNameEntryScene(SceneTransitionOwner next,
    GameStateSaveImage * image, MaryNameEntryKind input_kind, u8 index)
    : continuation(next), save(image), kind(input_kind), target_index(index) {}


// Directly selected possessive labels for farm entities.  Each literal owns
// its normal C terminator; normal object alignment supplies the spacing.
extern char const gText_Possessive_Horse[];
extern char const gText_Possessive_Cow[];
extern char const gText_Possessive_Sheep[];
extern char const gText_Possessive_Chicken[];
extern char const gText_Possessive_Child[];
extern char const gText_Possessive_Player[];

#endif // NAME_ENTRY_HH
