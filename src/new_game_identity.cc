#include "new_game_identity.hh"
#include "new_game_data.hh"
#include "hardware_state_accessors.hh"
#include "hardware_blend_object.hh"
#include "hardware_music_player.hh"
#pragma implementation

extern NewGameSceneVTableFunction const gNewGameIdentityCoreVTable[] = {
    nullptr, nullptr,
    reinterpret_cast<NewGameSceneVTableFunction>(DestroyNewGameIdentityCore),
};
NewGameNativeVTableEntry __vt_20NewGameIdentityScene[4] = {
    nullptr, nullptr,
    reinterpret_cast<NewGameNativeVTableEntry>(DestroyNewGameIdentityScene),
    reinterpret_cast<NewGameNativeVTableEntry>(RunNewGameIdentityScene),
};

void * operator new(unsigned long);
void operator delete(void *);

static inline void QueueIdentityBlend(HardwareBootstrap * core, HardwareBlendOwner const & owner)
{
    HardwareLinkedList * list = reinterpret_cast<HardwareLinkedList *>(
        GetHardwareCommandList(reinterpret_cast<void * const *>(core)));
    list->Append(owner.object);
}

NewGameIdentityCore::~NewGameIdentityCore()
{
    vtable = reinterpret_cast<void **>(
        const_cast<NewGameSceneVTableFunction *>(gNewGameIdentityCoreVTable));
    if (ui_state != nullptr)
        delete ui_state;
}

SceneTransitionOwner RunNewGameIdentityCore(NewGameIdentityCore * core)
{
    BlankNewGameIdentityDisplay(core);
    ResetNewGameIdentityControl(core);
    InitializeNewGameIdentityScreen(core);

    HardwareDisplayState * display =
        GetHardwareDisplayState(reinterpret_cast<void * const *>(core));
    HardwareDisplayRegisterValue control(0x3F);
    display->SetBlendControl(control);

    HardwareBlendOwner owner(new HardwareBlendObject(
        GetHardwareDisplayState(reinterpret_cast<void * const *>(core))));
    BeginHardwareBlend(&owner.object->blend, 0x889, 1, 1);
    QueueIdentityBlend(core, owner);

    i16 phase = 0;
    bool finished = false;
    do
    {
        UpdateHardwareFrame(core);
        UpdateHardwareInput(reinterpret_cast<void * const *>(core));
        GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(core));
        switch (phase)
        {
        case 0:
            if (!owner.IsQueued())
                phase = 1;
            break;
        case 1:
            UpdateNewGameIdentityDialog(core);
            if (core->unk_1A74 != 0)
                phase = 2;
            break;
        case 2:
            EndHardwareBlend(&owner.object->blend, 0x889, 1, 1);
            QueueIdentityBlend(core, owner);
            phase = 3;
            break;
        case 3:
            if (!owner.IsQueued())
                finished = true;
            break;
        }
    } while (!finished);
    return SceneTransitionOwner();
}

void BlankNewGameIdentityDisplay(NewGameIdentityCore * core)
{
    func_08008724(core);
}

void ResetNewGameIdentityControl(NewGameIdentityCore * core)
{
    core->unk_1A75 = 0;
    core->unk_1A74 = 0;
}

void UpdateNewGameIdentityDialog(NewGameIdentityCore * core)
{
    int state = core->ui_state->GetState();
    UiStateOwner * owner = core->ui_state;
    HardwareCoreState * hardware = static_cast<HardwareCoreState *>(
        GetHardwareCoreState(reinterpret_cast<void * const *>(core)));
    HardwareSpriteBufferState * sprites =
        GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
    HardwareDisplayState * display =
        GetHardwareDisplayState(reinterpret_cast<void * const *>(core));
    u8 * links = GetHardwareCommandList(reinterpret_cast<void * const *>(core));
    u8 * manager = GetHardwareInterruptList(reinterpret_cast<void * const *>(core));
    MusicPlayer ** music = &core->music;
    int action = owner->Update(hardware, sprites, display, links, manager, music);

    switch (action)
    {
    case 0:
        if (core->unk_1A75 != 0)
            core->unk_1A74 = 1;
        func_08050D5C(core->ui_state);
        break;
    case 3:
        switch (state)
        {
        case 4:
        case 5:
            break;
        default:
            func_08050D74(reinterpret_cast<void * const *>(core->ui_state));
            break;
        case 1:
            func_08050E30(core->ui_state,
                gText_NewGameIdentity_Confirm, gText_NewGameIdentity_Yes,
                gText_NewGameIdentity_No, nullptr, nullptr, nullptr);
            break;
        case 6:
            // This form reads the adapter's address-sized result as a choice.
            switch (reinterpret_cast<u32>(func_08050DF0(
                reinterpret_cast<void * const *>(core->ui_state))))
            {
            case 1:
                core->unk_1A75 = 1;
                core->confirmed = 1;
                break;
            case 2:
                core->unk_1A75 = 1;
                core->confirmed = 0;
                break;
            case 0:
            case 3:
            case 4:
            case 5:
            case 6:
                break;
            }
            break;
        }
        break;
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
        break;
    }
}

NewGameIdentityScene::NewGameIdentityScene(char const * player_name,
    GameDate birthday, char const * farm_name, char const * dog_name)
{
    core = InitializeNewGameIdentityCore(static_cast<NewGameIdentityCore *>(
        ::operator new(sizeof(NewGameIdentityCore))), player_name, birthday, farm_name, dog_name);
}

NewGameIdentityScene::~NewGameIdentityScene()
{
    NewGameIdentityCore * object = core;
    if (object != nullptr)
        ((void (*)(NewGameIdentityCore *, int))object->vtable[2])(object, 3);
}

SceneTransitionOwner NewGameIdentityScene::Run()
{
    return RunNewGameIdentityCore(core);
}

u8 NewGameIdentityScene::GetConfirmed() const
{
    return core->confirmed;
}

u8 GetNewGameIdentityCoreConfirmed(NewGameIdentityCore const * core)
{
    return core->confirmed;
}
