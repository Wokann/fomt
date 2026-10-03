#ifndef SCENE_HH
#define SCENE_HH

#include "prelude.h"

struct AScene;
struct SceneTransition;
struct SceneOwner;
struct SceneTransitionOwner;

// SceneMain's temporary owner conversions materialize these two-word records.
// They are scene-specific ABI types, not operations on the generic SmartPtr.
struct SceneOwnerTransfer
{
    SceneOwner * source;
    AScene * value;

    SceneOwnerTransfer(SceneOwner * owner, AScene * scene)
        : source(owner), value(scene) {}
    AScene * release();
};

struct SceneTransitionOwnerTransfer
{
    SceneTransitionOwner * source;
    SceneTransition * value;

    SceneTransitionOwnerTransfer(SceneTransitionOwner * owner, SceneTransition * transition)
        : source(owner), value(transition) {}
    SceneTransition * release();
};

// Both owners occupy one word. Their two-word transfer descriptors are
// consumed by the receiving owner; unrelated pointer wrappers do not share
// these scene-specific ownership operations.
struct SceneOwner
{
    AScene * value;

    explicit SceneOwner(AScene * scene = nullptr) : value(scene) {}
    SceneOwner(SceneOwner & other) : value(other.release()) {}
    SceneOwner(SceneOwnerTransfer transfer);
    ~SceneOwner();

    SceneOwner & operator=(SceneOwner & other);
    SceneOwner & operator=(AScene * scene);
    AScene * get() const { return value; }
    AScene * operator->() const { return value; }
    AScene * release()
    {
        AScene * scene = value;
        value = nullptr;
        return scene;
    }
    void reset(AScene * scene = nullptr);
    operator SceneOwnerTransfer()
    {
        return SceneOwnerTransfer(this, value);
    }
};

struct SceneTransitionOwner
{
    SceneTransition * value;

    explicit SceneTransitionOwner(SceneTransition * transition = nullptr) : value(transition) {}
    SceneTransitionOwner(SceneTransitionOwner & other) : value(other.release()) {}
    SceneTransitionOwner(SceneTransitionOwnerTransfer transfer);
    ~SceneTransitionOwner();

    SceneTransition * get() const { return value; }
    SceneTransition * operator->() const { return value; }
    SceneTransition * release()
    {
        SceneTransition * transition = value;
        value = nullptr;
        return transition;
    }
    operator SceneTransitionOwnerTransfer()
    {
        // The descriptor is consumed by the receiving owner, which captures
        // its pointer before clearing the source owner.
        return SceneTransitionOwnerTransfer(this, value);
    }
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

inline AScene * SceneOwnerTransfer::release()
{
    AScene * scene = value;
    source->value = nullptr;
    return scene;
}

inline SceneOwner::SceneOwner(SceneOwnerTransfer transfer)
    : value(transfer.release()) {}

inline SceneOwner & SceneOwner::operator=(SceneOwner & other)
{
    AScene * scene = other.release();
    if (scene != value)
        delete value;
    value = scene;
    return *this;
}

inline SceneOwner & SceneOwner::operator=(AScene * scene)
{
    if (scene != value)
        delete value;
    value = scene;
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

inline SceneTransition * SceneTransitionOwnerTransfer::release()
{
    SceneTransition * transition = value;
    source->value = nullptr;
    return transition;
}

inline SceneTransitionOwner::SceneTransitionOwner(SceneTransitionOwnerTransfer transfer)
    : value(transfer.release()) {}

extern "C" void SceneMain(SceneOwner scene);

// Direct ABI declaration of the compiler-generated base destructor. The
// ABI-compatible derived destroyer forwards its original flags here.
extern "C" void DestroySceneBase(AScene * scene, int flags) asm("_._6AScene");

#endif // SCENE_HH
