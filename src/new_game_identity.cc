#include "prelude.h"
#pragma implementation "new_game_identity.hh"
#include "new_game_identity.hh"
#include "hardware_display_commands.hh"
#include "new_game_data.hh"
#include "hardware_state_accessors.hh"
#include "hardware_blend_object.hh"
#include "hardware_music_player.hh"
#include "hardware_song.hh"
#include "fomt_constants.hh"
#include "gbaio.h"
#include "font.hh"
#include "time_of_day.hh"
#include <string.h>
#pragma implementation

void * operator new(unsigned long);
void operator delete(void *);
inline void * operator new(unsigned long, void * storage) { return storage; }
inline void * operator new[](unsigned long, void * storage) { return storage; }

static inline void AppendIdentityField(FixedStr<15> & field, char const * text)
{
    char * start = &field[0];
    u32 size = strlen(start);
    char * end = start + size;
    u32 available = 15 - size;
    if (available != 0) {
        u32 length = strlen(text);
        if (length > available)
            length = available;
        memcpy(end, text, length);
        end[length] = '\0';
    }
}

NewGameIdentityCore * InitializeNewGameIdentityCore(NewGameIdentityCore * core,
    char const * player_name, GameDate birthday, char const * farm_name,
    char const * dog_name)
{
    ConstructHardwareBootstrap(core);
    InstallHardwareBootstrapNativeVTable(core, __vt_19NewGameIdentityCore);
#if defined(REGION_JP)
    new (core->buffers) NewGameTextTileBuffer<12>[8];
#else
    new (core->value_buffers) NewGameTextTileBuffer<12>[4];
    new (core->label_buffers) NewGameTextTileBuffer<14>[4];
#endif
    core->unk_1A28 = 2;
    UiStateOwner * storage = static_cast<UiStateOwner *>(::operator new(sizeof(UiStateOwner)));
    {
        HardwareStateOwner shared;
        HardwareResource resources;
        UiStateOwner * ui = new (storage) UiStateOwner(0, 28, 4, 0, shared, resources);
        core->ui_state = ui;
    }
    // Borrow the player assigned to this SFX for the confirmation UI.
    core->music = GetHardwareSongPlayerSlot(AUDIO_SFX_KAPPA_SURPRISE);
    new (core->fields) FixedStr<15>[NEW_GAME_IDENTITY_FIELD_COUNT];
    core->confirmed = 0;
    core->fields[NEW_GAME_IDENTITY_PLAYER_NAME] = player_name;

    char day[16];
#if defined(REGION_JP)
    FormatFullWidthDecimal(birthday.GetDay() + 1, day, 2);
#else
    FormatSignedDecimal(birthday.GetDay() + 1, day, 2);
#endif
    CalendarSeasonLabel season_name = GetCalendarSeasonLabel(birthday.GetSeason());
    FixedStr<15> & date = core->fields[NEW_GAME_IDENTITY_BIRTHDAY];
    AppendIdentityField(date, season_name);
#if defined(REGION_JP)
    AppendIdentityField(date, gText_NewGameIdentity_BirthMonthSuffix);
#endif
    AppendIdentityField(date, day);
#if defined(REGION_JP)
    AppendIdentityField(date, gText_NewGameIdentity_BirthDaySuffix);
#endif
    core->fields[NEW_GAME_IDENTITY_FARM_NAME] = farm_name;
    core->fields[NEW_GAME_IDENTITY_DOG_NAME] = dog_name;
    return core;
}

static inline void QueueIdentityBlend(HardwareBootstrap * core, HardwareBlendOwner const & owner)
{
    HardwareLinkedList * list =
        GetHardwareCommandList(reinterpret_cast<void * const *>(core));
    list->Append(owner.object);
}

NewGameIdentityCore::~NewGameIdentityCore()
{
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
    HardwareDisplayRegisterValue control(BLDCNT_TGT1_ALL);
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
    EnableHardwareForcedBlank(core);
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
    HardwareLinkedList * links = GetHardwareCommandList(reinterpret_cast<void * const *>(core));
    HardwareInterruptList * manager = GetHardwareInterruptList(reinterpret_cast<void * const *>(core));
    HardwareMusicPlayerSlot * music = &core->music;
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
            switch (core->ui_state->GetChoiceResult())
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
    delete core;
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
