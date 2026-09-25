#ifndef SCENE_HH
#define SCENE_HH

#include "prelude.h"

struct AScene;
struct SceneTransition;

// Both owners occupy one word. SceneMain currently implements their moves and
// destruction in ASM; these module-specific types describe that ABI without
// assigning the same unverified ownership semantics to unrelated pointers.
struct SceneOwner
{
    AScene * value;

    explicit SceneOwner(AScene * scene = nullptr) : value(scene) {}
    SceneOwner(SceneOwner & other) : value(other.release()) {}
    ~SceneOwner();

    SceneOwner & operator=(SceneOwner & other);
    AScene * get() const { return value; }
    AScene * operator->() const { return value; }
    AScene * release()
    {
        AScene * scene = value;
        value = nullptr;
        return scene;
    }
    void reset(AScene * scene = nullptr);
};

struct SceneTransitionOwner
{
    SceneTransition * value;

    explicit SceneTransitionOwner(SceneTransition * transition = nullptr) : value(transition) {}
    SceneTransitionOwner(SceneTransitionOwner & other) : value(other.release()) {}
    ~SceneTransitionOwner();

    SceneTransition * get() const { return value; }
    SceneTransition * operator->() const { return value; }
    SceneTransition * release()
    {
        SceneTransition * transition = value;
        value = nullptr;
        return transition;
    }
};

// SceneMain materializes one two-word transfer record for each temporary
// owner. The first word identifies the owner to clear; the second is the
// pointer being handed to the receiving owner.
struct SceneOwnerTransfer
{
    SceneOwner * source;
    AScene * value;
};

struct SceneTransitionOwnerTransfer
{
    SceneTransitionOwner * source;
    SceneTransition * value;
};

struct AScene
{
    virtual ~AScene();
    virtual SceneTransitionOwner Run() = 0;
};

// The second-stage object chooses the next scene through virtual slot +0x0C.
struct SceneTransition
{
    virtual ~SceneTransition();
    virtual SceneOwner CreateScene() = 0;
};

inline SceneOwner::~SceneOwner() { delete value; }

inline SceneOwner & SceneOwner::operator=(SceneOwner & other)
{
    if (value != other.value)
    {
        delete value;
        value = other.release();
    }
    return *this;
}

inline void SceneOwner::reset(AScene * scene)
{
    if (value != scene)
    {
        delete value;
        value = scene;
    }
}

inline SceneTransitionOwner::~SceneTransitionOwner() { delete value; }

void SceneMain(SceneOwner scene);

#endif // SCENE_HH
