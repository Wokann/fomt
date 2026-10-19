#ifndef SCENE_HH
#define SCENE_HH

#include "prelude.h"

struct AScene;
struct SceneTransition;
struct SceneOwner;
struct SceneTransitionOwner;

// The two-word conversion record holds a reference to the erased pointer slot
// and a cached typed value. Clearing the source does not discard that value.
// These are scene ownership types, not operations on the generic SmartPtr.
struct SceneOwnerTransfer
{
    void * & source;
    AScene * value;

    SceneOwnerTransfer(void * & owner, AScene * scene)
        : source(owner), value(scene) {}
    AScene * release() const;
};

struct SceneTransitionOwnerTransfer
{
    void * & source;
    SceneTransition * value;

    SceneTransitionOwnerTransfer(void * & owner, SceneTransition * transition)
        : source(owner), value(transition) {}
    SceneTransition * release() const;
};

// Each owner stores one erased pointer word and exposes a typed interface.
// The transfer record refers to this word, not to the surrounding owner.
struct SceneOwner
{
    void * value;

    // Define the helper before its use by the transfer-copy constructor so
    // the old compiler can inline that constructor without an outlined call.
    AScene * release()
    {
        AScene * scene = static_cast<AScene *>(value);
        value = nullptr;
        return scene;
    }

    explicit SceneOwner(AScene * scene = nullptr) : value(scene) {}
    SceneOwner(SceneOwner & other) : value(other.release()) {}
    SceneOwner(SceneOwnerTransfer transfer);
    ~SceneOwner();

    SceneOwner & operator=(SceneOwner & other);
    SceneOwner & operator=(AScene * scene);
    AScene * get() const { return static_cast<AScene *>(value); }
    AScene * operator->() const { return static_cast<AScene *>(value); }
    void reset(AScene * scene = nullptr);
    operator SceneOwnerTransfer()
    {
        return SceneOwnerTransfer(value, static_cast<AScene *>(value));
    }
};

struct SceneTransitionOwner
{
    void * value;

    // As with SceneOwner, define the release helper before the transfer-copy
    // constructor so the old compiler can inline that ordinary copy.
    SceneTransition * release()
    {
        SceneTransition * transition = static_cast<SceneTransition *>(value);
        value = nullptr;
        return transition;
    }

    explicit SceneTransitionOwner(SceneTransition * transition = nullptr) : value(transition) {}
    SceneTransitionOwner(SceneTransitionOwner & other) : value(other.release()) {}
    SceneTransitionOwner(SceneTransitionOwnerTransfer transfer);
    ~SceneTransitionOwner();

    SceneTransition * get() const { return static_cast<SceneTransition *>(value); }
    SceneTransition * operator->() const { return static_cast<SceneTransition *>(value); }
    operator SceneTransitionOwnerTransfer()
    {
        return SceneTransitionOwnerTransfer(value, static_cast<SceneTransition *>(value));
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

inline SceneOwner::~SceneOwner() { delete static_cast<AScene *>(value); }

inline AScene * SceneOwnerTransfer::release() const
{
    source = nullptr;
    return value;
}

inline SceneOwner::SceneOwner(SceneOwnerTransfer transfer)
    : value(transfer.release()) {}

inline SceneOwner & SceneOwner::operator=(SceneOwner & other)
{
    AScene * scene = other.release();
    if (scene != value)
        delete static_cast<AScene *>(value);
    value = scene;
    return *this;
}

inline SceneOwner & SceneOwner::operator=(AScene * scene)
{
    if (scene != value)
        delete static_cast<AScene *>(value);
    value = scene;
    return *this;
}

inline void SceneOwner::reset(AScene * scene)
{
    if (value != scene)
    {
        delete static_cast<AScene *>(value);
        value = scene;
    }
}

inline SceneTransitionOwner::~SceneTransitionOwner() { delete static_cast<SceneTransition *>(value); }

inline SceneTransition * SceneTransitionOwnerTransfer::release() const
{
    source = nullptr;
    return value;
}

inline SceneTransitionOwner::SceneTransitionOwner(SceneTransitionOwnerTransfer transfer)
    : value(transfer.release()) {}

typedef char SceneOwnerSizeCheck[sizeof(SceneOwner) == 4 ? 1 : -1];
typedef char SceneTransitionOwnerSizeCheck[sizeof(SceneTransitionOwner) == 4 ? 1 : -1];
typedef char SceneOwnerTransferSizeCheck[sizeof(SceneOwnerTransfer) == 8 ? 1 : -1];
typedef char SceneTransitionOwnerTransferSizeCheck[sizeof(SceneTransitionOwnerTransfer) == 8 ? 1 : -1];
typedef char SceneOwnerTransferValueOffsetCheck[offsetof(SceneOwnerTransfer, value) == 4 ? 1 : -1];
typedef char SceneTransitionOwnerTransferValueOffsetCheck[offsetof(SceneTransitionOwnerTransfer, value) == 4 ? 1 : -1];

extern "C" void SceneMain(SceneOwner scene);

// Direct ABI declaration of the compiler-generated base destructor. The
// ABI-compatible derived destroyer forwards its original flags here.
extern "C" void DestroySceneBase(AScene * scene, int flags) asm("_._6AScene");

// Direct declaration of the existing transition-base destructor ABI. Native
// transition callbacks forward the caller's original destruction flags here.
extern "C" void DestroySceneTransitionBase(SceneTransition * transition, int flags)
    asm("_._15SceneTransition");

#endif // SCENE_HH
