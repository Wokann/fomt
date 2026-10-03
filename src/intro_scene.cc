#include "intro_scene.hh"
#include "hardware.hh"
#include "hardware_allocator.hh"
#include "hardware_bootstrap.hh"
#include "hardware_blend_object.hh"
#include "hardware_display_output.hh"
#include "hardware_state_accessors.hh"

EXTERN_C

void Unpack(u8 const * source, void * destination);
AScene * func_08004C48(void * scene);
AScene * func_08004B58(void * scene);

EXTERN_C_END

void * operator new(unsigned long);

inline void IntroSceneUnpackedResources::Initialize(u8 const * source)
{
    Unpack(source, bytes);
}

static inline void InitializeIntroSceneResourceState(
    IntroSceneResourceState * state, IndexedResourceArchive * archive, u32 index)
{
    ConstructIndexedResourceHandle(&state->handle,
        reinterpret_cast<IndexedResourceProvider *>(archive), index, 0x100);
    state->unk_18 = 0;
    state->unk_1C = 0;
}

static inline void InitializeIntroSceneHardwareStateHandle(
    IntroSceneHardwareStateHandle * owner, u32 group_index)
{
    func_08007874(owner);
    owner->handle = func_08007B54(owner, group_index);
}

static inline void InitializeIntroSceneHardwarePoolHandle(IntroSceneHardwarePoolHandle * owner)
{
    func_08007128(owner);
    owner->handle = func_0800736C(owner);
}

static inline void InitializeIntroSceneHardwareStateReservation(
    HardwareSharedStateOwner * owner, u32 first, u32 count)
{
    func_08007874(owner);
    owner->Reserve(first, count);
}

IntroSceneCore * ConstructIntroSceneCore(void * object)
{
    IntroSceneCore * core = static_cast<IntroSceneCore *>(object);
    func_08008444(reinterpret_cast<HardwareBootstrap *>(core));
    core->vtable = &vtable_unk_080E5A0C;
    func_08008B54(&core->music_players[0], 0);
    func_08008B54(&core->music_players[1], 1);
    core->unpacked_resources.Initialize(gIntroSceneIndexedArchiveCompressed);
    IndexedResourceArchive * intro = &core->intro_archive;
    ConstructIndexedResourceArchive(intro, core->unpacked_resources.bytes);
    IndexedResourceArchive * small = &core->small_archive;
    ConstructIndexedResourceArchive(small, gIntroSceneSmallIndexedArchive);
    IndexedResourceArchive * actors = &core->actor_archive;
    ConstructIndexedResourceArchive(actors, gActorIndexedResourceArchive);
    InitializeIntroSceneResourceState(&core->resources[0], actors, 0x160);
    InitializeIntroSceneResourceState(&core->resources[1], actors, 0x342);
    InitializeIntroSceneResourceState(&core->resources[2], actors, 0x788);
    InitializeIntroSceneResourceState(&core->resources[3], actors, 0x2B2);
    InitializeIntroSceneResourceState(&core->resources[4], actors, 0x924);
    InitializeIntroSceneResourceState(&core->resources[5], actors, 0x730);
    InitializeIntroSceneResourceState(&core->resources[6], actors, 0x730);
    InitializeIntroSceneResourceState(&core->resources[7], actors, 0x91A);
    InitializeIntroSceneResourceState(&core->resources[8], intro, 0);
#if defined(REGION_JP)
    InitializeIntroSceneResourceState(&core->resources[9], intro, 1);
    InitializeIntroSceneResourceState(&core->resources[10], intro, 2);
    InitializeIntroSceneResourceState(&core->resources[11], intro, 5);
    InitializeIntroSceneResourceState(&core->resources[12], intro, 8);
#else
    InitializeIntroSceneResourceState(&core->resources[9], intro, 0);
    InitializeIntroSceneResourceState(&core->resources[10], intro, 1);
    InitializeIntroSceneResourceState(&core->resources[11], intro, 4);
    InitializeIntroSceneResourceState(&core->resources[12], intro, 7);
#endif
    InitializeIntroSceneResourceState(&core->resources[13], small, 0);
    InitializeIntroSceneHardwareStateReservation(&core->state_reservation, 0, 0x300);
    func_08007128(&core->unk_6C74);
    func_080071BC(&core->unk_6C74, 9, 7);
    InitializeIntroSceneHardwareStateHandle(&core->state_handle_6C78, 4);
    InitializeIntroSceneHardwarePoolHandle(&core->pool_handle_6C80);
    InitializeIntroSceneHardwareStateHandle(&core->state_handle_6C88, 4);
    InitializeIntroSceneHardwarePoolHandle(&core->pool_handle_6C90);
    InitializeIntroSceneHardwareStateHandle(&core->state_handle_6C98, 4);
    InitializeIntroSceneHardwarePoolHandle(&core->pool_handle_6CA0);
    InitializeIntroSceneHardwareStateHandle(&core->state_handle_6CA8, 4);
    InitializeIntroSceneHardwareStateHandle(&core->state_handle_6CB0, 2);
    InitializeIntroSceneHardwarePoolHandle(&core->pool_handle_6CB8);
    InitializeIntroSceneHardwareStateHandle(&core->state_handle_6CC0, 2);
    InitializeIntroSceneHardwarePoolHandle(&core->pool_handle_6CC8);
    InitializeIntroSceneHardwareStateHandle(&core->state_handle_6CD0, 1);
    InitializeIntroSceneHardwareStateHandle(&core->state_handle_6CD8, 1);
    InitializeIntroSceneHardwareStateHandle(&core->state_handle_6CE0, 3);
    InitializeIntroSceneHardwarePoolHandle(&core->pool_handle_6CE8);
    InitializeIntroSceneHardwareStateHandle(&core->state_handle_6CF0, 5);
    InitializeIntroSceneHardwareStateHandle(&core->state_handle_6CF8, 5);
    InitializeIntroSceneHardwarePoolHandle(&core->pool_handle_6D00);
    InitializeIntroSceneHardwareStateHandle(&core->state_handle_6D08, 6);
    InitializeIntroSceneHardwarePoolHandle(&core->pool_handle_6D10);
    InitializeIntroSceneHardwareStateHandle(&core->state_handle_6D18, 2);
    InitializeIntroSceneHardwarePoolHandle(&core->pool_handle_6D20);
    core->run_state = 0;
    core->startup_hold_frames = 0;
    core->unk_6C6D = 0;
    core->continuation = 0;
    return core;
}

GameIntroScene * ConstructGameIntroScene(GameIntroScene * scene)
{
    scene->vtable = vtable_unk_080E5A18;
    scene->core = ConstructIntroSceneCore(::operator new(sizeof(IntroSceneCore)));
    return scene;
}

void DestroyGameIntroScene(GameIntroScene * scene, int flags)
{
    scene->vtable = vtable_unk_080E5A18;
    IntroSceneCore * core = scene->core;
    if (core != nullptr)
        core->vtable->destroy(core, 3);
    DestroySceneBase(reinterpret_cast<AScene *>(scene), flags);
}

SceneTransitionOwner RunGameIntroScene(GameIntroScene * scene)
{
    return RunIntroSceneCore(scene->core);
}

SceneTransitionOwner RunIntroSceneCore(IntroSceneCore * core)
{
    bool finished = false;
    do
    {
        switch (core->run_state)
        {
        case 0:
            StartIntroSceneCore(core);
            core->run_state = 1;
            break;
        case 1:
            if (func_08000FF8(core) == 1)
                goto choose_continuation;
            core->run_state = 0;
            break;
        }
    } while (!finished);

choose_continuation:
    if (core->continuation == 0)
        return SceneTransitionOwner(new IntroNameEntryTransition);
    else
        return SceneTransitionOwner(new IntroMenuTransition);
}

static inline void QueueIntroSceneBlend(IntroSceneCore * core, HardwareBlendOwner const & owner)
{
    u8 * list = func_08008940(reinterpret_cast<void * const *>(core));
    void * const * vtable = *reinterpret_cast<void * const **>(list + 8);
    ((void (*)(u8 *, HardwareBlendObject *))vtable[4])(list, owner.object);
}

void StartIntroSceneCore(IntroSceneCore * core)
{
    func_08008724(reinterpret_cast<HardwareBootstrap *>(core));
    func_08000F5C(core);
    reinterpret_cast<HardwareDisplayState *>(
        func_08008918(reinterpret_cast<void * const *>(core)))->SetBlendControl(0x3F);

    HardwareBlendOwner owner(new HardwareBlendObject(
        func_08008918(reinterpret_cast<void * const *>(core))));
    func_0800934C(&owner.object->blend, 0x889, 1, 0);
    QueueIntroSceneBlend(core, owner);
    core->startup_phase = 0;
    func_08008B6C(core->music_players, 0);

    bool finished = false;
    do
    {
        func_080087C8(reinterpret_cast<HardwareBootstrap *>(core));
        func_080088B8(reinterpret_cast<void * const *>(core));
        switch (core->startup_phase)
        {
        case 0:
            if (!owner.IsQueued())
            {
                core->startup_hold_frames = 120;
                core->startup_phase = 1;
            }
            break;
        case 1:
            --core->startup_hold_frames;
            // START skips the hold, but both fades still run to completion.
            if (static_cast<u16>(func_080088CC(reinterpret_cast<void * const *>(core)) & 8))
                core->startup_hold_frames = 0;
            if (core->startup_hold_frames <= 0)
            {
                func_08009378(&owner.object->blend, 0x889, 1, 0);
                QueueIntroSceneBlend(core, owner);
                core->startup_phase = 2;
            }
            break;
        case 2:
            if (!owner.IsQueued())
                finished = true;
            break;
        }
    } while (!finished);
}

SceneOwner IntroNameEntryTransition::CreateScene()
{
    // The existing constructor installs the name-entry scene's vtable.
    return SceneOwner(func_08004C48(::operator new(4)));
}

SceneOwner IntroMenuTransition::CreateScene()
{
    // The existing menu scene contains a vtable and an owned menu core.
    return SceneOwner(func_08004B58(::operator new(8)));
}
