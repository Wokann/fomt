#include "config.h"
#include "obj_palette_collection.hh"
#include "prelude.h"
#pragma implementation "scene_gamecube_link_callbacks.hh"
#include "scene_gamecube_link.hh"
#include "game_state.hh"
#include "hardware_blend_owner.hh"
#include "interrupt.h"
#include "interrupt_table.h"
#include "obj_palette_collection.hh"
#include "obj_tile_collection.hh"

GameCubeLinkUiCore::GameCubeLinkUiCore(GameStateSaveImage * image)
    : result(GAMECUBE_LINK_RESULT_CANCELED_OR_FAILED),
      data(new GameCubeLinkSaveData(image)), save(image),
      ui(0, 29, 0, 0, ObjTileCollection(), ObjPaletteCollection()),
      music(1), unk_1E0(0), phase(0), phase_changed(true)
{
}

GameCubeLinkUiCore::~GameCubeLinkUiCore()
{
}


void GameCubeLinkUiCore::Run()
{
    EnableHardwareForcedBlank(this);
    WriteHardwareDisplayFlags(GetHardwareDisplayState(reinterpret_cast<void * const *>(this))->background_control[0], BGCNT_SCREENBASE(29) | BGCNT_MOSAIC);
    WriteHardwareDisplayFlags(GetHardwareDisplayState(reinterpret_cast<void * const *>(this))->background_control[1], BGCNT_SCREENBASE(30) | BGCNT_MOSAIC | BGCNT_PRIORITY(1));
    WriteHardwareDisplayFlags(GetHardwareDisplayState(reinterpret_cast<void * const *>(this))->background_control[2], BGCNT_SCREENBASE(31) | BGCNT_MOSAIC | BGCNT_PRIORITY(2));
    FillHardwareDma3(~0u, reinterpret_cast<void *>(BG_SCREEN_ADDR(30)), BG_SCREEN_SIZE);
    FillHardwareDma3(~0u, reinterpret_cast<void *>(BG_SCREEN_ADDR(31)), BG_SCREEN_SIZE);
    FillHardwareDma3(0, reinterpret_cast<void *>(BG_CHAR_ADDR(2) - 32), 0x8000);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(this))->SetDisplayFlags(DISPCNT_OBJ_1D_MAP | DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_ON);
    CopyHardwareDma3(gUiSharedTiles, reinterpret_cast<void *>(BG_VRAM), gUiSharedTileByteCount);
    FillHardwareDma3(0x00030003, reinterpret_cast<void *>(BG_SCREEN_ADDR(31)), BG_SCREEN_SIZE);
    CopyHardwareDma3(gUiSharedPalette, reinterpret_cast<void *>(BG_PLTT), 32);
    FillHardwareDma3(0x03FF03FF, reinterpret_cast<void *>(BG_SCREEN_ADDR(30)), BG_SCREEN_SIZE);
    func_08050D5C(&ui);
    ui.ShowPortrait(0x38);
    func_08050E68(reinterpret_cast<void * const *>(&ui), save->npcs.GetCharacterName(CHARACTER_HARVEST_GODDESS));
    ExchangeInterruptHandler(7, func_080D0704);
    AcknowledgeAndEnableInterrupts(0x80);
    SetInterruptNestingMask(0, 0x80);
    WriteHardwareDisplayRegister(*GetHardwareDisplayState(reinterpret_cast<void * const *>(this)),
        &HardwareDisplayState::blend_control, BLDCNT_TGT1_ALL);
    HardwareBlendOwner blend(new HardwareBlendObject(GetHardwareDisplayState(reinterpret_cast<void * const *>(this))));
    blend.object->blend.Begin(0x889, 1, 1);
    GetHardwareCommandList(reinterpret_cast<void * const *>(this))->Append(blend.object);
    bool finished = false;
    do {
        UpdateHardwareFrame(this);
        UpdateHardwareInput(reinterpret_cast<void * const *>(this));
        Update();
        previous_ui_state = ui.GetState();
        HardwareCoreState * input = GetHardwareCoreState(reinterpret_cast<void * const *>(this));
        HardwareSpriteBufferState * sprites = GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(this));
        HardwareDisplayState * display = GetHardwareDisplayState(reinterpret_cast<void * const *>(this));
        HardwareLinkedList * links = GetHardwareCommandList(reinterpret_cast<void * const *>(this));
        HardwareInterruptList * interrupts = GetHardwareInterruptList(reinterpret_cast<void * const *>(this));
        HardwareMusicPlayerSlot * player = &music;
        ui_state = ui.Update(&input->input, sprites, display, links, interrupts, player);
        if (phase_changed) {
            phase_changed = false;
            switch (phase) {
            case 0: break;
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6:
                switch (GetResult()) {
                case 0: break;
                case 1:
                    func_08050D8C(reinterpret_cast<void * const *>(&ui), gText_LinkCommunication_QuitCommunication);
                    ui.ShowPortrait(0x38);
                    break;
                case 2:
                    func_08050D8C(reinterpret_cast<void * const *>(&ui), gText_LinkCommunication_OtherPlayerCanceled);
                    ui.ShowPortrait(0x3A);
                    break;
                case 3:
                    func_08050D8C(reinterpret_cast<void * const *>(&ui), gText_LinkCommunication_IncompatibleGameData);
                    ui.ShowPortrait(0x3A);
                    break;
                }
                break;
            case 7: break;
            case 8: break;
            }
        }
        switch (phase) {
        case 0:
            func_08050D8C(reinterpret_cast<void * const *>(&ui), gText_LinkCommunication_ExchangeRestriction);
            ui.ShowPortrait(0x38);
            SetPhase(1);
            break;
        case 1:
            if (ui_state == 3)
                SetPhase(2);
            break;
        case 2:
#if defined(REGION_DE)
            func_08050E30(&ui, gText_LinkCommunication_ActionQuestion,
                gText_LinkCommunication_ActionYes, gText_LinkCommunication_ActionNo, nullptr, nullptr, nullptr);
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
            func_08050E30(&ui, gText_LinkCommunication_ActionQuestion,
                gText_LinkCommunication_Yes, gText_LinkCommunication_No, nullptr, nullptr, nullptr);
#endif
            ui.ShowPortrait(0x39);
            SetPhase(3);
            break;
        case 3:
            if (ui_state == 3) {
                switch (ui.GetChoiceResult()) {
                case 1:
                    SetPhase(4);
                    break;
                case 2:
                    func_08050D8C(reinterpret_cast<void * const *>(&ui), gText_LinkCommunication_Declined);
                    ui.ShowPortrait(0x3A);
                    SetPhase(7);
                    result = GAMECUBE_LINK_RESULT_CANCELED_OR_FAILED;
                    break;
                }
            }
            break;
        case 4: {
            PrepareGameCubeLinkOutgoingData(data.value);
            u32 local_code = GetGameCubeLinkLocalGameCode(data.value);
            u32 remote_code = GetGameCubeLinkRemoteGameCode(data.value);
            u32 * record = GetGameCubeLinkRecordWords(data.value);
            void const * outgoing = GetGameCubeLinkOutgoingPacket(data.value);
            u32 outgoing_size = GetGameCubeLinkOutgoingSize(data.value);
            void * incoming = GetGameCubeLinkIncomingPacket(data.value);
            u32 incoming_size = GetGameCubeLinkIncomingSize(data.value);
            Initialize(local_code, remote_code, record, outgoing, outgoing_size, incoming, incoming_size);
            SetPhase(5);
            break;
        }
        case 5:
            phase_changed = true;
            if (IsFinished()) {
                if (GetResult() == 0) {
                    func_08050D8C(reinterpret_cast<void * const *>(&ui), gText_LinkCommunication_Complete);
                    ui.ShowPortrait(0x39);
                    SetPhase(7);
                    result = GAMECUBE_LINK_RESULT_SUCCESS;
                    save->link_record.SetReceivedRecordValue(GetGameCubeLinkReceivedRecordValue(data.value));
                    save->link_record.SetReceivedMilestones(GetGameCubeLinkReceivedMilestones(data.value));
                    char name0[16];
                    DecodeGameCubeLinkReceivedName0(data.value, name0);
                    save->link_record.name_14 = name0;
                    char name1[16];
                    DecodeGameCubeLinkReceivedName1(data.value, name1);
                    save->link_record.name_24 = name1;
                    char name2[16];
                    DecodeGameCubeLinkReceivedName2(data.value, name2);
                    save->link_record.name_34 = name2;
                } else {
                    SetPhase(6);
                }
            }
            break;
        case 6:
            if (ui.GetState() == 3) {
                switch (GetResult()) {
                case 3:
                    func_08050D8C(reinterpret_cast<void * const *>(&ui), gText_LinkCommunication_QuitCommunication);
                    ui.ShowPortrait(0x38);
                    SetPhase(7);
                    result = GAMECUBE_LINK_RESULT_INCOMPATIBLE_SAVE_DATA;
                    break;
                case 2:
                    func_08050D8C(reinterpret_cast<void * const *>(&ui), gText_LinkCommunication_QuitCommunication);
                    ui.ShowPortrait(0x38);
                    // fall through
                default:
                    SetPhase(7);
                    result = GAMECUBE_LINK_RESULT_CANCELED_OR_FAILED;
                    break;
                }
            }
            break;
        case 7:
            if (ui_state == 3) {
                ResetJoyBusLinkRegisters();
                finished = true;
                {
                    HardwareBlendObject & fade = *blend.object;
                    i16 step = 0x889;
                    fade.blend.End(step, 1, 1);
                }
                GetHardwareCommandList(reinterpret_cast<void * const *>(this))->Append(blend.object);
                SetPhase(8);
            }
            break;
        case 8:
            break;
        }
        DispatchStateAction();
        bool queued = blend.IsQueued();
        if (finished && !queued)
            return;
    } while (true);
}






GameCubeLinkUiScene::GameCubeLinkUiScene(SceneTransitionOwner next, GameStateSaveImage * image)
    : core(new GameCubeLinkUiCore(image)), continuation(next)
{
}

inline GameCubeLinkUiCoreOwner::~GameCubeLinkUiCoreOwner() { delete value; }

GameCubeLinkUiScene::~GameCubeLinkUiScene()
{
}

MaryGameCubeLinkResult GameCubeLinkUiScene::GetResult()
{
    return core.value->result;
}

SceneTransitionOwner GameCubeLinkUiScene::Run()
{
    core.value->Run();
    return continuation;
}

extern "C" void MarkPhaseChanged__18GameCubeLinkUiCore(GameCubeLinkUiCore * core)
{
    core->MarkPhaseChanged();
}

extern "C" void SetPhase__18GameCubeLinkUiCoreUi(GameCubeLinkUiCore * core, u32 next)
{
    core->SetPhase(next);
}

// These are the direct ABI entries. The inline callback bodies also supply
// the compiler-generated entries that adjust the JoyBus base pointer.
extern "C" void ActRetry__18GameCubeLinkUiCore(GameCubeLinkUiCore * core)
{
    core->GameCubeLinkUiCore::ActRetry();
}

extern "C" u32 PollRetry__18GameCubeLinkUiCore(GameCubeLinkUiCore * core)
{
    return core->GameCubeLinkUiCore::PollRetry();
}

extern "C" void EnterRetry__18GameCubeLinkUiCore(GameCubeLinkUiCore * core)
{
    core->GameCubeLinkUiCore::EnterRetry();
}

extern "C" void ActPayload__18GameCubeLinkUiCore(GameCubeLinkUiCore * core)
{
    core->GameCubeLinkUiCore::ActPayload();
}

extern "C" void EnterPayload__18GameCubeLinkUiCore(GameCubeLinkUiCore * core)
{
    core->GameCubeLinkUiCore::EnterPayload();
}

extern "C" u32 PollDecision__18GameCubeLinkUiCore(GameCubeLinkUiCore * core)
{
    u8 pressed = ::GetHardwarePressedKeys(reinterpret_cast<void * const *>(core)) & B_BUTTON;
    if (pressed != 0)
        return 1;
    return 0;
}

extern "C" void EnterDecision__18GameCubeLinkUiCore(GameCubeLinkUiCore * core)
{
    core->GameCubeLinkUiCore::EnterDecision();
}

extern "C" void ActConfirmation__18GameCubeLinkUiCore(GameCubeLinkUiCore * core)
{
    core->GameCubeLinkUiCore::ActConfirmation();
}

extern "C" u32 PollConfirmation__18GameCubeLinkUiCore(GameCubeLinkUiCore * core)
{
    u32 result = 0;
    switch (core->dialogue_phase) {
    case 0:
        if (core->ui.GetState() == 3) {
            core->dialogue_phase = 1;
            func_08050E30(&core->ui, gText_LinkCommunication_ProceedQuestion,
                gText_LinkCommunication_Yes, gText_LinkCommunication_No,
                nullptr, nullptr, nullptr);
        }
        break;
    case 1:
        if (core->ui.GetState() == 3) {
            switch (core->ui.GetChoiceResult()) {
            case 1: result = 2; break;
            case 2: result = 3; break;
            }
        }
        break;
    }
    return result;
}

extern "C" void EnterConfirmation__18GameCubeLinkUiCore(GameCubeLinkUiCore * core)
{
    core->GameCubeLinkUiCore::EnterConfirmation();
}

extern "C" void EnterRecordCheck__18GameCubeLinkUiCore(GameCubeLinkUiCore * core)
{
    core->GameCubeLinkUiCore::EnterRecordCheck();
}

extern "C" void EnterMetadata__18GameCubeLinkUiCore(GameCubeLinkUiCore * core)
{
    core->GameCubeLinkUiCore::EnterMetadata();
}

extern "C" u32 PollConnect__18GameCubeLinkUiCore(GameCubeLinkUiCore * core)
{
    u8 pressed = ::GetHardwarePressedKeys(reinterpret_cast<void * const *>(core)) & B_BUTTON;
    if (pressed != 0)
        return 1;
    return 0;
}

extern "C" void EnterConnect__18GameCubeLinkUiCore(GameCubeLinkUiCore * core)
{
    core->GameCubeLinkUiCore::EnterConnect();
}

extern "C" u32 GetPressedKeys__18GameCubeLinkUiCore(GameCubeLinkUiCore * core)
{
    return core->GameCubeLinkUiCore::GetPressedKeys();
}

extern "C" u32 GetHeldKeys__18GameCubeLinkUiCore(GameCubeLinkUiCore * core)
{
    return core->GameCubeLinkUiCore::GetHeldKeys();
}

MaryGameCubeLinkResult GameCubeLinkUiCore::GetUiResult() const
{
    return result;
}

LinkWordProtocol::LinkWordProtocol()
    : current_state(&gLinkWordProtocolFinished), next_state(nullptr), finished(true)
{
}

LinkWordProtocol::~LinkWordProtocol()
{
}

void LinkWordProtocol::Initialize(u32 local_code, u32 remote_code, u32 * new_record,
    void const * new_outgoing, u32 new_outgoing_size, void * new_incoming, u32 new_incoming_size)
{
    ConfigureGameCodes(local_code, remote_code);
    record = new_record;
    outgoing = new_outgoing;
    outgoing_size = new_outgoing_size;
    incoming = new_incoming;
    incoming_size = new_incoming_size;
    next_state = &gLinkWordProtocolConnect;
    finished = false;
}

void LinkWordProtocol::Update()
{
    UpdateTransport();
    if (next_state != nullptr) {
        current_state = next_state;
        next_state = nullptr;
        (this->*current_state->enter)();
        (this->*current_state->start)();
    }
    u32 input = (this->*current_state->poll)();
    (this->*current_state->update)(input);
}

void LinkWordProtocol::DispatchStateAction()
{
    (this->*current_state->action)();
}

bool LinkWordProtocol::IsFinished()
{
    return finished;
}

i32 LinkWordProtocol::GetResult()
{
    return result;
}

void LinkWordProtocol::StartConnect()
{
    StartTransport();
    BeginHandshake();
}

void LinkWordProtocol::UpdateConnect(u32 input)
{
    if (input == 1)
        CancelTransfer();
    if (Unk_40()) {
        if (Unk_48()) {
            next_state = &gLinkWordProtocolRetry;
        } else if (Unk_44()) {
            result = 1;
            next_state = &gLinkWordProtocolFinished;
        } else {
            next_state = &gLinkWordProtocolMetadata;
        }
    }
}

void LinkWordProtocol::StartMetadata()
{
    ExchangeWord(*record, 0);
}

void LinkWordProtocol::UpdateMetadata(u32 input)
{
    if (Unk_40()) {
        if (Unk_48())
            next_state = &gLinkWordProtocolRetry;
        else
            next_state = &gLinkWordProtocolRecordCheck;
    }
}

void LinkWordProtocol::StartRecordCheck()
{
    record[2] = GetReceivedWord();
    if (Unk_50())
        ExchangeWord(0, 0);
    else
        ExchangeWord(1, 0);
}

void LinkWordProtocol::UpdateRecordCheck(u32 input)
{
    if (Unk_40()) {
        if (Unk_48()) {
            next_state = &gLinkWordProtocolRetry;
        } else if (Unk_54()) {
            if (Unk_58()) {
                next_state = &gLinkWordProtocolConfirmation;
            } else {
                accepted = true;
                next_state = &gLinkWordProtocolDecision;
            }
        } else {
            result = 3;
            next_state = &gLinkWordProtocolFinished;
        }
    }
}

void LinkWordProtocol::StartConfirmation()
{
}

void LinkWordProtocol::UpdateConfirmation(u32 input)
{
    switch (input) {
    case 2:
        accepted = true;
        next_state = &gLinkWordProtocolDecision;
        break;
    case 3:
        accepted = false;
        next_state = &gLinkWordProtocolDecision;
        break;
    }
}

void LinkWordProtocol::StartDecision()
{
    if (accepted)
        ExchangeWord(0, 1);
    else
        ExchangeWord(1, 1);
}

void LinkWordProtocol::UpdateDecision(u32 input)
{
    if (input == 1)
        CancelTransfer();
    if (Unk_40()) {
        if (Unk_48()) {
            next_state = &gLinkWordProtocolRetry;
        } else if (Unk_44()) {
            result = 1;
            next_state = &gLinkWordProtocolFinished;
        } else if (!accepted) {
            result = 1;
            next_state = &gLinkWordProtocolFinished;
        } else if (!Unk_5C()) {
            result = 2;
            next_state = &gLinkWordProtocolFinished;
        } else {
            next_state = &gLinkWordProtocolPayload;
        }
    }
}

void LinkWordProtocol::StartPayload()
{
    ExchangeBuffers(outgoing, outgoing_size, incoming, incoming_size);
}

void LinkWordProtocol::UpdatePayload(u32 input)
{
    if (Unk_40()) {
        if (Unk_48()) {
            next_state = &gLinkWordProtocolRetry;
        } else {
            result = 0;
            next_state = &gLinkWordProtocolFinished;
        }
    }
}

void LinkWordProtocol::StartFinished()
{
    finished = true;
    StopTransport();
}

void LinkWordProtocol::UpdateFinished(u32 input)
{
}

void LinkWordProtocol::StartRetry()
{
}

void LinkWordProtocol::UpdateRetry(u32 input)
{
    switch (input) {
    case 2:
        next_state = &gLinkWordProtocolConnect;
        break;
    case 3:
        result = 1;
        next_state = &gLinkWordProtocolFinished;
        break;
    }
}

LinkBlockProtocol::LinkBlockProtocol()
    : current_state(&gLinkBlockProtocolFinished), next_state(nullptr), finished(true)
{
}

LinkBlockProtocol::~LinkBlockProtocol()
{
}

void LinkBlockProtocol::Initialize(u32 local_code, u32 remote_code, u32 * new_record,
    void const * new_outgoing, u32 new_outgoing_size, void * new_incoming, u32 new_incoming_size)
{
    ConfigureGameCodes(local_code, remote_code);
    record = new_record;
    outgoing = new_outgoing;
    outgoing_size = new_outgoing_size;
    incoming = new_incoming;
    incoming_size = new_incoming_size;
    next_state = &gLinkBlockProtocolConnect;
    finished = false;
}

void LinkBlockProtocol::Update()
{
    UpdateTransport();
    if (next_state != nullptr) {
        current_state = next_state;
        next_state = nullptr;
        (this->*current_state->enter)();
        (this->*current_state->start)();
    }
    u32 input = (this->*current_state->poll)();
    (this->*current_state->update)(input);
}

void LinkBlockProtocol::DispatchStateAction()
{
    (this->*current_state->action)();
}

bool LinkBlockProtocol::IsFinished()
{
    return finished;
}

i32 LinkBlockProtocol::GetResult()
{
    return result;
}

void LinkBlockProtocol::StartConnect()
{
    StartTransport();
    BeginHandshake();
}

void LinkBlockProtocol::UpdateConnect(u32 input)
{
    if (input == 1)
        CancelTransfer();
    if (Unk_40()) {
        if (Unk_48()) {
            next_state = &gLinkBlockProtocolRetry;
        } else if (Unk_44()) {
            result = 1;
            next_state = &gLinkBlockProtocolFinished;
        } else {
            next_state = &gLinkBlockProtocolMetadata;
        }
    }
}

void LinkBlockProtocol::StartMetadata()
{
    ExchangeBuffers(record, sizeof(received_record), received_record, sizeof(received_record));
}

void LinkBlockProtocol::UpdateMetadata(u32 input)
{
    if (Unk_40()) {
        if (Unk_48())
            next_state = &gLinkBlockProtocolRetry;
        else
            next_state = &gLinkBlockProtocolRecordCheck;
    }
}

void LinkBlockProtocol::StartRecordCheck()
{
    record[2] = received_record[0];
    if (Unk_50())
        ExchangeWord(0, 0);
    else
        ExchangeWord(1, 0);
}

void LinkBlockProtocol::UpdateRecordCheck(u32 input)
{
    if (Unk_40()) {
        if (Unk_48()) {
            next_state = &gLinkBlockProtocolRetry;
        } else if (Unk_54()) {
            if (Unk_58()) {
                next_state = &gLinkBlockProtocolConfirmation;
            } else {
                accepted = true;
                next_state = &gLinkBlockProtocolDecision;
            }
        } else {
            result = 3;
            next_state = &gLinkBlockProtocolFinished;
        }
    }
}

void LinkBlockProtocol::StartConfirmation()
{
}

void LinkBlockProtocol::UpdateConfirmation(u32 input)
{
    switch (input) {
    case 2:
        accepted = true;
        next_state = &gLinkBlockProtocolDecision;
        break;
    case 3:
        accepted = false;
        next_state = &gLinkBlockProtocolDecision;
        break;
    }
}

void LinkBlockProtocol::StartDecision()
{
    if (accepted)
        ExchangeWord(0, 1);
    else
        ExchangeWord(1, 1);
}

void LinkBlockProtocol::UpdateDecision(u32 input)
{
    if (input == 1)
        CancelTransfer();
    if (Unk_40()) {
        if (Unk_48()) {
            next_state = &gLinkBlockProtocolRetry;
        } else if (Unk_44()) {
            result = 1;
            next_state = &gLinkBlockProtocolFinished;
        } else if (!accepted) {
            result = 1;
            next_state = &gLinkBlockProtocolFinished;
        } else if (!Unk_5C()) {
            result = 2;
            next_state = &gLinkBlockProtocolFinished;
        } else {
            next_state = &gLinkBlockProtocolPayload;
        }
    }
}

void LinkBlockProtocol::StartPayload()
{
    ExchangeBuffers(outgoing, outgoing_size, incoming, incoming_size);
}

void LinkBlockProtocol::UpdatePayload(u32 input)
{
    if (Unk_40()) {
        if (Unk_48()) {
            next_state = &gLinkBlockProtocolRetry;
        } else {
            result = 0;
            next_state = &gLinkBlockProtocolFinished;
        }
    }
}

void LinkBlockProtocol::StartFinished()
{
    finished = true;
    StopTransport();
}

void LinkBlockProtocol::UpdateFinished(u32 input)
{
}

void LinkBlockProtocol::StartRetry()
{
}

void LinkBlockProtocol::UpdateRetry(u32 input)
{
    switch (input) {
    case 2:
        next_state = &gLinkBlockProtocolConnect;
        break;
    case 3:
        result = 1;
        next_state = &gLinkBlockProtocolFinished;
        break;
    }
}

void LinkBlockProtocol::ActRetry()
{
}

u32 LinkBlockProtocol::PollRetry()
{
    return 0;
}

void LinkBlockProtocol::EnterRetry()
{
}

void LinkBlockProtocol::ActFinished()
{
}

u32 LinkBlockProtocol::PollFinished()
{
    return 0;
}

void LinkBlockProtocol::EnterFinished()
{
}

void LinkBlockProtocol::ActPayload()
{
}

u32 LinkBlockProtocol::PollPayload()
{
    return 0;
}

void LinkBlockProtocol::EnterPayload()
{
}

void LinkBlockProtocol::ActDecision()
{
}

u32 LinkBlockProtocol::PollDecision()
{
    return 0;
}

void LinkBlockProtocol::EnterDecision()
{
}

void LinkBlockProtocol::ActConfirmation()
{
}

u32 LinkBlockProtocol::PollConfirmation()
{
    return 0;
}

void LinkBlockProtocol::EnterConfirmation()
{
}

void LinkBlockProtocol::ActRecordCheck()
{
}

u32 LinkBlockProtocol::PollRecordCheck()
{
    return 0;
}

void LinkBlockProtocol::EnterRecordCheck()
{
}

void LinkBlockProtocol::ActMetadata()
{
}

u32 LinkBlockProtocol::PollMetadata()
{
    return 0;
}

void LinkBlockProtocol::EnterMetadata()
{
}

void LinkBlockProtocol::ActConnect()
{
}

u32 LinkBlockProtocol::PollConnect()
{
    return 0;
}

void LinkBlockProtocol::EnterConnect()
{
}

u32 LinkBlockProtocol::GetReceivedRecordValue()
{
    return record[2];
}

void LinkWordProtocol::ActRetry()
{
}

u32 LinkWordProtocol::PollRetry()
{
    return 0;
}

void LinkWordProtocol::EnterRetry()
{
}

void LinkWordProtocol::ActFinished()
{
}

u32 LinkWordProtocol::PollFinished()
{
    return 0;
}

void LinkWordProtocol::EnterFinished()
{
}

void LinkWordProtocol::ActPayload()
{
}

u32 LinkWordProtocol::PollPayload()
{
    return 0;
}

void LinkWordProtocol::EnterPayload()
{
}

void LinkWordProtocol::ActDecision()
{
}

u32 LinkWordProtocol::PollDecision()
{
    return 0;
}

void LinkWordProtocol::EnterDecision()
{
}

void LinkWordProtocol::ActConfirmation()
{
}

u32 LinkWordProtocol::PollConfirmation()
{
    return 0;
}

void LinkWordProtocol::EnterConfirmation()
{
}

void LinkWordProtocol::ActRecordCheck()
{
}

u32 LinkWordProtocol::PollRecordCheck()
{
    return 0;
}

void LinkWordProtocol::EnterRecordCheck()
{
}

void LinkWordProtocol::ActMetadata()
{
}

u32 LinkWordProtocol::PollMetadata()
{
    return 0;
}

void LinkWordProtocol::EnterMetadata()
{
}

void LinkWordProtocol::ActConnect()
{
}

u32 LinkWordProtocol::PollConnect()
{
    return 0;
}

void LinkWordProtocol::EnterConnect()
{
}

u32 LinkWordProtocol::GetReceivedRecordValue()
{
    return record[2];
}






// Preserve the physical order of this read-only ROM block: regional dialog,
// state descriptors, character codes, protocol identifiers, then runtime strings.
#include FOMT_TEXT_INCLUDE(scene_gamecube_link.cc)

extern "C" {

LinkWordProtocolState const gLinkWordProtocolConnect = {
    &LinkWordProtocol::StartConnect,
    &LinkWordProtocol::UpdateConnect,
    &LinkWordProtocol::EnterConnect,
    &LinkWordProtocol::PollConnect,
    &LinkWordProtocol::ActConnect,
};

LinkWordProtocolState const gLinkWordProtocolMetadata = {
    &LinkWordProtocol::StartMetadata,
    &LinkWordProtocol::UpdateMetadata,
    &LinkWordProtocol::EnterMetadata,
    &LinkWordProtocol::PollMetadata,
    &LinkWordProtocol::ActMetadata,
};

LinkWordProtocolState const gLinkWordProtocolRecordCheck = {
    &LinkWordProtocol::StartRecordCheck,
    &LinkWordProtocol::UpdateRecordCheck,
    &LinkWordProtocol::EnterRecordCheck,
    &LinkWordProtocol::PollRecordCheck,
    &LinkWordProtocol::ActRecordCheck,
};

LinkWordProtocolState const gLinkWordProtocolConfirmation = {
    &LinkWordProtocol::StartConfirmation,
    &LinkWordProtocol::UpdateConfirmation,
    &LinkWordProtocol::EnterConfirmation,
    &LinkWordProtocol::PollConfirmation,
    &LinkWordProtocol::ActConfirmation,
};

LinkWordProtocolState const gLinkWordProtocolDecision = {
    &LinkWordProtocol::StartDecision,
    &LinkWordProtocol::UpdateDecision,
    &LinkWordProtocol::EnterDecision,
    &LinkWordProtocol::PollDecision,
    &LinkWordProtocol::ActDecision,
};

LinkWordProtocolState const gLinkWordProtocolPayload = {
    &LinkWordProtocol::StartPayload,
    &LinkWordProtocol::UpdatePayload,
    &LinkWordProtocol::EnterPayload,
    &LinkWordProtocol::PollPayload,
    &LinkWordProtocol::ActPayload,
};

LinkWordProtocolState const gLinkWordProtocolFinished = {
    &LinkWordProtocol::StartFinished,
    &LinkWordProtocol::UpdateFinished,
    &LinkWordProtocol::EnterFinished,
    &LinkWordProtocol::PollFinished,
    &LinkWordProtocol::ActFinished,
};

LinkWordProtocolState const gLinkWordProtocolRetry = {
    &LinkWordProtocol::StartRetry,
    &LinkWordProtocol::UpdateRetry,
    &LinkWordProtocol::EnterRetry,
    &LinkWordProtocol::PollRetry,
    &LinkWordProtocol::ActRetry,
};

LinkBlockProtocolState const gLinkBlockProtocolConnect = {
    &LinkBlockProtocol::StartConnect,
    &LinkBlockProtocol::UpdateConnect,
    &LinkBlockProtocol::EnterConnect,
    &LinkBlockProtocol::PollConnect,
    &LinkBlockProtocol::ActConnect,
};

LinkBlockProtocolState const gLinkBlockProtocolMetadata = {
    &LinkBlockProtocol::StartMetadata,
    &LinkBlockProtocol::UpdateMetadata,
    &LinkBlockProtocol::EnterMetadata,
    &LinkBlockProtocol::PollMetadata,
    &LinkBlockProtocol::ActMetadata,
};

LinkBlockProtocolState const gLinkBlockProtocolRecordCheck = {
    &LinkBlockProtocol::StartRecordCheck,
    &LinkBlockProtocol::UpdateRecordCheck,
    &LinkBlockProtocol::EnterRecordCheck,
    &LinkBlockProtocol::PollRecordCheck,
    &LinkBlockProtocol::ActRecordCheck,
};

LinkBlockProtocolState const gLinkBlockProtocolConfirmation = {
    &LinkBlockProtocol::StartConfirmation,
    &LinkBlockProtocol::UpdateConfirmation,
    &LinkBlockProtocol::EnterConfirmation,
    &LinkBlockProtocol::PollConfirmation,
    &LinkBlockProtocol::ActConfirmation,
};

LinkBlockProtocolState const gLinkBlockProtocolDecision = {
    &LinkBlockProtocol::StartDecision,
    &LinkBlockProtocol::UpdateDecision,
    &LinkBlockProtocol::EnterDecision,
    &LinkBlockProtocol::PollDecision,
    &LinkBlockProtocol::ActDecision,
};

LinkBlockProtocolState const gLinkBlockProtocolPayload = {
    &LinkBlockProtocol::StartPayload,
    &LinkBlockProtocol::UpdatePayload,
    &LinkBlockProtocol::EnterPayload,
    &LinkBlockProtocol::PollPayload,
    &LinkBlockProtocol::ActPayload,
};

LinkBlockProtocolState const gLinkBlockProtocolFinished = {
    &LinkBlockProtocol::StartFinished,
    &LinkBlockProtocol::UpdateFinished,
    &LinkBlockProtocol::EnterFinished,
    &LinkBlockProtocol::PollFinished,
    &LinkBlockProtocol::ActFinished,
};

LinkBlockProtocolState const gLinkBlockProtocolRetry = {
    &LinkBlockProtocol::StartRetry,
    &LinkBlockProtocol::UpdateRetry,
    &LinkBlockProtocol::EnterRetry,
    &LinkBlockProtocol::PollRetry,
    &LinkBlockProtocol::ActRetry,
};


}
