#ifndef STATUS_SCREEN_TRANSITIONS_HH
#define STATUS_SCREEN_TRANSITIONS_HH

#include "scene.hh"

struct GameStateSaveImage;

#pragma interface "status_screen_transitions.hh"

// The three factories and their tables occupy consecutive native ranges.
// Constructors remain inline in callers; agbcp emits tables in reverse declaration order.
struct FarmStatusScreenTransition : SceneTransition
{
    FarmStatusScreenTransition(SceneTransitionOwner next, GameStateSaveImage * image, u8 argument)
        : continuation(next), save(image), unk_0C(argument) {}
    virtual ~FarmStatusScreenTransition();
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u8 unk_0C;
};

struct RecordsScreenTransition : SceneTransition
{
    RecordsScreenTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual ~RecordsScreenTransition();
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct FarmMapScreenTransition : SceneTransition
{
    FarmMapScreenTransition(GameStateSaveImage * image, SceneTransitionOwner next)
        : save(image), continuation(next) {}
    virtual ~FarmMapScreenTransition();
    virtual SceneOwner CreateScene();
    GameStateSaveImage * save;
    SceneTransitionOwner continuation;
};



#endif // STATUS_SCREEN_TRANSITIONS_HH
