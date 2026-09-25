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
};

struct SceneTransitionOwnerTransfer
{
    SceneTransitionOwner * source;
    SceneTransition * value;

    SceneTransitionOwnerTransfer(SceneTransitionOwner * owner, SceneTransition * transition)
        : source(owner), value(transition) {}
};

// Both owners occupy one word. SceneMain currently implements their moves and
// destruction in ASM; these module-specific types describe that ABI without
// assigning the same unverified ownership semantics to unrelated pointers.
struct SceneOwner
{
    AScene * value;

    explicit SceneOwner(AScene * scene = nullptr) : value(scene) {}
    SceneOwner(SceneOwner & other) : value(other.release()) {}
    SceneOwner(SceneOwnerTransfer transfer) : value(transfer.value) {}
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
        SceneOwnerTransfer transfer(this, value);
        transfer.source->value = nullptr;
        return transfer;
    }
};

struct SceneTransitionOwner
{
    SceneTransition * value;

    explicit SceneTransitionOwner(SceneTransition * transition = nullptr) : value(transition) {}
    SceneTransitionOwner(SceneTransitionOwner & other) : value(other.release()) {}
    SceneTransitionOwner(SceneTransitionOwnerTransfer transfer) : value(transfer.value) {}
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
        SceneTransitionOwnerTransfer transfer(this, value);
        transfer.source->value = nullptr;
        return transfer;
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

inline SceneOwner & SceneOwner::operator=(SceneOwner & other)
{
    AScene * scene = other.release();
    if (value != scene)
    {
        delete value;
        value = scene;
    }
    return *this;
}

inline SceneOwner & SceneOwner::operator=(AScene * scene)
{
    if (value != scene)
    {
        if (value != nullptr)
            delete value;
        value = scene;
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
