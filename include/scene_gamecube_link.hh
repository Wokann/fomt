#ifndef SCENE_GAMECUBE_LINK_HH
#define SCENE_GAMECUBE_LINK_HH

#include "scene.hh"
#include "fomt_constants.hh"

struct GameStateSaveImage;
#include "joy_bus.hh"
#include "ui_state.hh"
#include "hardware_context.hh"

// Both protocols use the same virtual interface before their state methods.
// Its data-free base owns the vptr at +0; each protocol's state starts at +4.
struct LinkProtocol {
    virtual void Initialize(u32 local_code, u32 remote_code, u32 * record, void const * outgoing, u32 outgoing_size, void * incoming, u32 incoming_size) = 0;
    virtual void Update() = 0;
    virtual void DispatchStateAction() = 0;
    virtual bool IsFinished() = 0;
    virtual u32 GetResult() = 0;
    virtual u32 GetReceivedRecordValue() = 0;
    virtual void ConfigureGameCodes(u32 local_code, u32 remote_code) = 0;
    virtual void UpdateTransport() = 0;
    virtual void StartTransport() = 0;
    virtual void StopTransport() = 0;
    virtual void BeginHandshake() = 0;
    virtual void ExchangeBuffers(void const * outgoing, u32 outgoing_size, void * incoming, u32 incoming_size) = 0;
    virtual void ExchangeWord(u32 value, u8 mode) = 0;
    virtual void CancelTransfer() = 0;
    virtual bool Unk_40() = 0;
    virtual bool Unk_44() = 0;
    virtual bool Unk_48() = 0;
    virtual u32 GetReceivedWord() = 0;
    virtual bool Unk_50() = 0;
    virtual bool Unk_54() = 0;
    virtual bool Unk_58() = 0;
    virtual bool Unk_5C() = 0;
    virtual ~LinkProtocol() {}
};

struct GameCubeLinkUiCore;

struct GameCubeLinkUiCoreOwner {
    explicit GameCubeLinkUiCoreOwner(GameCubeLinkUiCore * input) : value(input) {}
    ~GameCubeLinkUiCoreOwner();
    GameCubeLinkUiCore * value;
};

#pragma interface "scene_gamecube_link.hh"

// These two native protocols differ in how they exchange their initial
// record: one word at a time, or an eight-byte block. Each state holds
// five real member-function pointers; GCC supplies their ABI encoding.

struct LinkWordProtocol;

struct LinkWordProtocolState {
    void (LinkWordProtocol::*start)();
    void (LinkWordProtocol::*update)(u32 input);
    void (LinkWordProtocol::*enter)();
    u32 (LinkWordProtocol::*poll)();
    void (LinkWordProtocol::*action)();
};

struct LinkWordProtocol : LinkProtocol {
    LinkWordProtocol();
    virtual void Initialize(u32 local_code, u32 remote_code, u32 * record, void const * outgoing, u32 outgoing_size, void * incoming, u32 incoming_size);
    virtual void Update();
    virtual void DispatchStateAction();
    virtual bool IsFinished();
    virtual u32 GetResult();
    virtual u32 GetReceivedRecordValue();
    virtual void ConfigureGameCodes(u32 local_code, u32 remote_code) = 0;
    virtual void UpdateTransport() = 0;
    virtual void StartTransport() = 0;
    virtual void StopTransport() = 0;
    virtual void BeginHandshake() = 0;
    virtual void ExchangeBuffers(void const * outgoing, u32 outgoing_size, void * incoming, u32 incoming_size) = 0;
    virtual void ExchangeWord(u32 value, u8 mode) = 0;
    virtual void CancelTransfer() = 0;
    virtual bool Unk_40() = 0;
    virtual bool Unk_44() = 0;
    virtual bool Unk_48() = 0;
    virtual u32 GetReceivedWord() = 0;
    virtual bool Unk_50() = 0;
    virtual bool Unk_54() = 0;
    virtual bool Unk_58() = 0;
    virtual bool Unk_5C() = 0;
    virtual ~LinkWordProtocol();

    virtual void StartConnect();
    virtual void UpdateConnect(u32 input);
    virtual void EnterConnect();
    virtual u32 PollConnect();
    virtual void ActConnect();

    virtual void StartMetadata();
    virtual void UpdateMetadata(u32 input);
    virtual void EnterMetadata();
    virtual u32 PollMetadata();
    virtual void ActMetadata();

    virtual void StartRecordCheck();
    virtual void UpdateRecordCheck(u32 input);
    virtual void EnterRecordCheck();
    virtual u32 PollRecordCheck();
    virtual void ActRecordCheck();

    virtual void StartConfirmation();
    virtual void UpdateConfirmation(u32 input);
    virtual void EnterConfirmation();
    virtual u32 PollConfirmation();
    virtual void ActConfirmation();

    virtual void StartDecision();
    virtual void UpdateDecision(u32 input);
    virtual void EnterDecision();
    virtual u32 PollDecision();
    virtual void ActDecision();

    virtual void StartPayload();
    virtual void UpdatePayload(u32 input);
    virtual void EnterPayload();
    virtual u32 PollPayload();
    virtual void ActPayload();

    virtual void StartFinished();
    virtual void UpdateFinished(u32 input);
    virtual void EnterFinished();
    virtual u32 PollFinished();
    virtual void ActFinished();

    virtual void StartRetry();
    virtual void UpdateRetry(u32 input);
    virtual void EnterRetry();
    virtual u32 PollRetry();
    virtual void ActRetry();

    LinkWordProtocolState const * current_state;
    LinkWordProtocolState const * next_state;
    bool accepted;
    bool finished;
    u32 result;
    u32 * record;
    void const * outgoing;
    u32 outgoing_size;
    void * incoming;
    u32 incoming_size;
};

typedef char LinkWordProtocolStateSizeCheck[sizeof(LinkWordProtocolState) == 0x28 ? 1 : -1];
typedef char LinkWordProtocolStateCheck[offsetof(LinkWordProtocol, current_state) == 4 ? 1 : -1];
typedef char LinkWordProtocolRecordCheck[offsetof(LinkWordProtocol, record) == 0x14 ? 1 : -1];

struct LinkBlockProtocol;

struct LinkBlockProtocolState {
    void (LinkBlockProtocol::*start)();
    void (LinkBlockProtocol::*update)(u32 input);
    void (LinkBlockProtocol::*enter)();
    u32 (LinkBlockProtocol::*poll)();
    void (LinkBlockProtocol::*action)();
};

struct LinkBlockProtocol : LinkProtocol {
    LinkBlockProtocol();
    virtual void Initialize(u32 local_code, u32 remote_code, u32 * record, void const * outgoing, u32 outgoing_size, void * incoming, u32 incoming_size);
    virtual void Update();
    virtual void DispatchStateAction();
    virtual bool IsFinished();
    virtual u32 GetResult();
    virtual u32 GetReceivedRecordValue();
    virtual void ConfigureGameCodes(u32 local_code, u32 remote_code) = 0;
    virtual void UpdateTransport() = 0;
    virtual void StartTransport() = 0;
    virtual void StopTransport() = 0;
    virtual void BeginHandshake() = 0;
    virtual void ExchangeBuffers(void const * outgoing, u32 outgoing_size, void * incoming, u32 incoming_size) = 0;
    virtual void ExchangeWord(u32 value, u8 mode) = 0;
    virtual void CancelTransfer() = 0;
    virtual bool Unk_40() = 0;
    virtual bool Unk_44() = 0;
    virtual bool Unk_48() = 0;
    virtual u32 GetReceivedWord() = 0;
    virtual bool Unk_50() = 0;
    virtual bool Unk_54() = 0;
    virtual bool Unk_58() = 0;
    virtual bool Unk_5C() = 0;
    virtual ~LinkBlockProtocol();

    virtual void StartConnect();
    virtual void UpdateConnect(u32 input);
    virtual void EnterConnect();
    virtual u32 PollConnect();
    virtual void ActConnect();

    virtual void StartMetadata();
    virtual void UpdateMetadata(u32 input);
    virtual void EnterMetadata();
    virtual u32 PollMetadata();
    virtual void ActMetadata();

    virtual void StartRecordCheck();
    virtual void UpdateRecordCheck(u32 input);
    virtual void EnterRecordCheck();
    virtual u32 PollRecordCheck();
    virtual void ActRecordCheck();

    virtual void StartConfirmation();
    virtual void UpdateConfirmation(u32 input);
    virtual void EnterConfirmation();
    virtual u32 PollConfirmation();
    virtual void ActConfirmation();

    virtual void StartDecision();
    virtual void UpdateDecision(u32 input);
    virtual void EnterDecision();
    virtual u32 PollDecision();
    virtual void ActDecision();

    virtual void StartPayload();
    virtual void UpdatePayload(u32 input);
    virtual void EnterPayload();
    virtual u32 PollPayload();
    virtual void ActPayload();

    virtual void StartFinished();
    virtual void UpdateFinished(u32 input);
    virtual void EnterFinished();
    virtual u32 PollFinished();
    virtual void ActFinished();

    virtual void StartRetry();
    virtual void UpdateRetry(u32 input);
    virtual void EnterRetry();
    virtual u32 PollRetry();
    virtual void ActRetry();

    LinkBlockProtocolState const * current_state;
    LinkBlockProtocolState const * next_state;
    bool accepted;
    bool finished;
    u32 result;
    u32 * record;
    u32 received_record[2];
    void const * outgoing;
    u32 outgoing_size;
    void * incoming;
    u32 incoming_size;
};

typedef char LinkBlockProtocolStateSizeCheck[sizeof(LinkBlockProtocolState) == 0x28 ? 1 : -1];
typedef char LinkBlockProtocolStateCheck[offsetof(LinkBlockProtocol, current_state) == 4 ? 1 : -1];
typedef char LinkBlockProtocolRecordCheck[offsetof(LinkBlockProtocol, record) == 0x14 ? 1 : -1];

typedef char LinkBlockProtocolSizeCheck[sizeof(LinkBlockProtocol) == 0x30 ? 1 : -1];

// Native JoyBus transport used by the GameCube link scene. The protocol
// owns its SDK context; the four mode flags follow that exact context.
#pragma interface "scene_gamecube_link.hh"

struct GameCubeLinkUiScene : AScene {
    GameCubeLinkUiScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~GameCubeLinkUiScene();
    MaryGameCubeLinkResult GetResult();
    virtual SceneTransitionOwner Run();

    GameCubeLinkUiCoreOwner core;
    SceneTransitionOwner continuation;
};

#pragma interface "scene_gamecube_link.hh"
struct JoyBusLinkProtocol : LinkBlockProtocol {
    JoyBusLinkProtocol();
    virtual inline ~JoyBusLinkProtocol();
    virtual inline void ConfigureGameCodes(u32 local_code, u32 remote_code);
    virtual inline void UpdateTransport();
    virtual inline void StartTransport();
    virtual inline void StopTransport();
    virtual inline void BeginHandshake();
    virtual inline void ExchangeBuffers(void const * outgoing, u32 outgoing_size, void * incoming, u32 incoming_size);
    virtual inline void ExchangeWord(u32 value, u8 mode);
    virtual inline void CancelTransfer();
    virtual inline NAKED bool Unk_40();
    virtual inline NAKED bool Unk_44();
    virtual inline NAKED bool Unk_48();
    virtual inline u32 GetReceivedWord();
    virtual inline bool Unk_50();
    virtual inline NAKED bool Unk_54();
    virtual inline bool Unk_58();
    virtual inline bool Unk_5C();
    virtual u32 GetHeldKeys() = 0;
    virtual u32 GetPressedKeys() = 0;
    inline void SetMode(u32 mode);

    JoyBusContext context;
    bool mode_enabled;
    bool unk_1B9;
    bool unk_1BA;
    bool unk_1BB;
};

typedef char JoyBusLinkContextCheck[offsetof(JoyBusLinkProtocol, context) == 0x30 ? 1 : -1];
typedef char JoyBusLinkModeCheck[offsetof(JoyBusLinkProtocol, mode_enabled) == 0x1B8 ? 1 : -1];
typedef char JoyBusLinkProtocolSizeCheck[sizeof(JoyBusLinkProtocol) == 0x1BC ? 1 : -1];

#pragma interface "scene_gamecube_link.hh"

#include "gamecube_link_save.hh"

// HardwareContext is the primary base; the JoyBus interface starts at +8.
// Its second vtable and adjusting entries come from real multiple inheritance.
struct GameCubeLinkUiCore : HardwareContext, JoyBusLinkProtocol {
    GameCubeLinkUiCore(GameStateSaveImage * image);
    virtual ~GameCubeLinkUiCore();
    void Run();
    void MarkPhaseChanged();
    void SetPhase(u32 next);
    virtual inline void ActRetry();
    virtual inline u32 PollRetry();
    virtual inline void EnterRetry();
    virtual inline void ActPayload();
    virtual inline void EnterPayload();
    virtual inline u32 PollDecision();
    virtual inline void EnterDecision();
    virtual inline void ActConfirmation();
    virtual inline u32 PollConfirmation();
    virtual inline void EnterConfirmation();
    virtual inline void EnterRecordCheck();
    virtual inline void EnterMetadata();
    virtual inline u32 PollConnect();
    virtual inline void EnterConnect();
    virtual inline u32 GetPressedKeys();
    virtual inline u32 GetHeldKeys();
    MaryGameCubeLinkResult GetUiResult() const;

    MaryGameCubeLinkResult result;
    GameCubeLinkSaveData * data; // Owned; the native destructor deletes it.
    GameStateSaveImage * save; // Borrowed.
    UiStateOwner ui;
    HardwareMusicPlayerSlot music;
    i32 previous_ui_state;
    i32 ui_state;
    u8 unk_1E0;
    // Unclassified RAM, not ROM padding or a recovered text buffer.
    u8 unk_1E1[0x1FF];
    u32 unk_3E0;
    u32 dialogue_phase;
    u32 phase;
    bool phase_changed;
};

typedef char GameCubeCoreJoyBusBaseCheck[sizeof(HardwareContext) == 8 ? 1 : -1];
typedef char GameCubeCoreResultCheck[offsetof(GameCubeLinkUiCore, result) == 0x1C4 ? 1 : -1];
typedef char GameCubeCoreDataCheck[offsetof(GameCubeLinkUiCore, data) == 0x1C8 ? 1 : -1];
typedef char GameCubeCoreUiCheck[offsetof(GameCubeLinkUiCore, ui) == 0x1D0 ? 1 : -1];
typedef char GameCubeCoreMusicCheck[offsetof(GameCubeLinkUiCore, music) == 0x1D4 ? 1 : -1];
typedef char GameCubeCoreUiStateCheck[offsetof(GameCubeLinkUiCore, ui_state) == 0x1DC ? 1 : -1];
typedef char GameCubeCoreDialogueCheck[offsetof(GameCubeLinkUiCore, dialogue_phase) == 0x3E4 ? 1 : -1];
typedef char GameCubeCorePhaseCheck[offsetof(GameCubeLinkUiCore, phase) == 0x3E8 ? 1 : -1];
typedef char GameCubeCoreChangedCheck[offsetof(GameCubeLinkUiCore, phase_changed) == 0x3EC ? 1 : -1];
typedef char GameCubeCoreSizeCheck[sizeof(GameCubeLinkUiCore) == 0x3F0 ? 1 : -1];

#pragma interface "scene_gamecube_link.hh"

#include "gamecube_link_scene.hh"

#pragma interface "scene_gamecube_link.hh"

typedef char GameCubeLinkUiCoreResultCheck[offsetof(GameCubeLinkUiCore, result) == 0x1C4 ? 1 : -1];
typedef char GameCubeLinkUiSceneSizeCheck[sizeof(GameCubeLinkUiScene) == 12 ? 1 : -1];
typedef char GameCubeLinkUiSceneCoreCheck[offsetof(GameCubeLinkUiScene, core) == 4 ? 1 : -1];
typedef char GameCubeLinkUiSceneContinuationCheck[offsetof(GameCubeLinkUiScene, continuation) == 8 ? 1 : -1];


#pragma interface "scene_gamecube_link.hh"


extern "C" {


extern LinkWordProtocolState const gLinkWordProtocolConnect;
extern LinkWordProtocolState const gLinkWordProtocolMetadata;
extern LinkWordProtocolState const gLinkWordProtocolRecordCheck;
extern LinkWordProtocolState const gLinkWordProtocolConfirmation;
extern LinkWordProtocolState const gLinkWordProtocolDecision;
extern LinkWordProtocolState const gLinkWordProtocolPayload;
extern LinkWordProtocolState const gLinkWordProtocolFinished;
extern LinkWordProtocolState const gLinkWordProtocolRetry;
extern LinkBlockProtocolState const gLinkBlockProtocolConnect;
extern LinkBlockProtocolState const gLinkBlockProtocolMetadata;
extern LinkBlockProtocolState const gLinkBlockProtocolRecordCheck;
extern LinkBlockProtocolState const gLinkBlockProtocolConfirmation;
extern LinkBlockProtocolState const gLinkBlockProtocolDecision;
extern LinkBlockProtocolState const gLinkBlockProtocolPayload;
extern LinkBlockProtocolState const gLinkBlockProtocolFinished;
extern LinkBlockProtocolState const gLinkBlockProtocolRetry;


}

extern char const gText_LinkCommunication_Waiting[];
extern char const gText_LinkCommunication_SendingGameData[];
extern char const gText_LinkCommunication_TestingConnection[];
extern char const gText_LinkCommunication_CannotResendPreviousData[];
extern char const gText_LinkCommunication_ProceedQuestion[];
extern char const gText_LinkCommunication_Yes[];
extern char const gText_LinkCommunication_No[];
extern char const gText_LinkCommunication_WaitingForOtherPlayer[];
extern char const gText_LinkCommunication_NowSendingData[];
extern char const gText_LinkCommunication_DataExchangeFailed[];
extern char const gText_LinkCommunication_QuitCommunication[];
extern char const gText_LinkCommunication_OtherPlayerCanceled[];
extern char const gText_LinkCommunication_IncompatibleGameData[];
extern char const gText_LinkCommunication_ExchangeRestriction[];
extern char const gText_LinkCommunication_ActionQuestion[];
#if defined(REGION_DE)
extern char const gText_LinkCommunication_ActionYes[];
extern char const gText_LinkCommunication_ActionNo[];
#endif
extern char const gText_LinkCommunication_Declined[];
extern char const gText_LinkCommunication_Complete[];


#pragma interface "scene_gamecube_link.hh"

inline JoyBusLinkProtocol::~JoyBusLinkProtocol()
{
    ResetJoyBusLinkRegisters();
}

inline void JoyBusLinkProtocol::SetMode(u32 mode)
{
    switch (mode) {
    case 0:
        mode_enabled = false;
        break;
    case 1:
        mode_enabled = true;
        unk_1B9 = false;
        break;
    case 2:
        mode_enabled = true;
        unk_1B9 = true;
        unk_1BA = true;
        unk_1BB = false;
        break;
    case 3:
        mode_enabled = true;
        unk_1B9 = true;
        unk_1BA = false;
        unk_1BB = true;
        break;
    case 4:
        mode_enabled = true;
        unk_1B9 = true;
        unk_1BA = false;
        unk_1BB = false;
        break;
    }
}

inline void JoyBusLinkProtocol::ConfigureGameCodes(u32 local_code, u32 remote_code)
{
    func_080D0444(local_code, remote_code);
}

inline void JoyBusLinkProtocol::BeginHandshake() { func_080D0454(0); }

inline void JoyBusLinkProtocol::ExchangeBuffers(void const * outgoing, u32 outgoing_size,
    void * incoming, u32 incoming_size)
{
    func_080D0558(outgoing, outgoing_size, incoming, incoming_size);
}

inline void JoyBusLinkProtocol::ExchangeWord(u32 value, u8 mode)
{
    func_080D0644(value, mode);
}

inline u32 JoyBusLinkProtocol::GetReceivedWord() { return func_080D0678(); }

inline void JoyBusLinkProtocol::CancelTransfer() { func_080D06A8(); }

inline NAKED bool JoyBusLinkProtocol::Unk_40()
{
    asm_unified(
        "    push {r4, lr}\n"
        "    adds r4, r0, #0\n"
        "    movs r1, #220\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r4, r1\n"
        "    ldrb r0, [r0, #0]\n"
        "    cmp r0, #0\n"
        "    beq .LJoyBus_status_40_1\n"
        "    ldr r0, [r4, #0]\n"
        "    subs r1, #176\n"
        "    adds r0, r0, r1\n"
        "    ldr r1, [r0, #0]\n"
        "    adds r0, r4, #0\n"
        "    bl _call_via_r1\n"
        "    lsrs r0, r0, #8\n"
        "    movs r1, #1\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    bne .LJoyBus_status_40_0\n"
        "    ldr r0, [r4, #0]\n"
        "    movs r1, #132\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    ldr r1, [r0, #0]\n"
        "    adds r0, r4, #0\n"
        "    bl _call_via_r1\n"
        "    lsrs r0, r0, #8\n"
        "    movs r1, #2\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .LJoyBus_status_40_1\n"
        ".LJoyBus_status_40_0:\n"
        "    movs r0, #1\n"
        "    b .LJoyBus_status_40_2\n"
        ".LJoyBus_status_40_1:\n"
        "    bl func_080D06B4\n"
        "    adds r1, r0, #0\n"
        "    negs r0, r1\n"
        "    orrs r0, r1\n"
        "    lsrs r0, r0, #31\n"
        ".LJoyBus_status_40_2:\n"
        "    pop {r4}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}

inline NAKED bool JoyBusLinkProtocol::Unk_44()
{
    asm_unified(
        "    push {r4, lr}\n"
        "    adds r4, r0, #0\n"
        "    movs r1, #220\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r4, r1\n"
        "    ldrb r0, [r0, #0]\n"
        "    cmp r0, #0\n"
        "    beq .LJoyBus_status_44_0\n"
        "    ldr r0, [r4, #0]\n"
        "    subs r1, #176\n"
        "    adds r0, r0, r1\n"
        "    ldr r1, [r0, #0]\n"
        "    adds r0, r4, #0\n"
        "    bl _call_via_r1\n"
        "    lsrs r0, r0, #8\n"
        "    movs r1, #1\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    bne .LJoyBus_status_44_1\n"
        "    ldr r0, [r4, #0]\n"
        "    movs r1, #132\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    ldr r1, [r0, #0]\n"
        "    adds r0, r4, #0\n"
        "    bl _call_via_r1\n"
        "    lsrs r0, r0, #8\n"
        "    movs r1, #2\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    bne .LJoyBus_status_44_1\n"
        ".LJoyBus_status_44_0:\n"
        "    bl func_080D06D0\n"
        "    cmp r0, #11\n"
        "    beq .LJoyBus_status_44_2\n"
        ".LJoyBus_status_44_1:\n"
        "    movs r0, #0\n"
        "    b .LJoyBus_status_44_3\n"
        ".LJoyBus_status_44_2:\n"
        "    movs r0, #1\n"
        ".LJoyBus_status_44_3:\n"
        "    pop {r4}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .align 2, 0\n"
    );
}

inline NAKED bool JoyBusLinkProtocol::Unk_48()
{
    asm_unified(
        "    push {r4, lr}\n"
        "    adds r4, r0, #0\n"
        "    movs r1, #220\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r4, r1\n"
        "    ldrb r0, [r0, #0]\n"
        "    cmp r0, #0\n"
        "    beq .LJoyBus_status_48_0\n"
        "    ldr r0, [r4, #0]\n"
        "    subs r1, #180\n"
        "    adds r0, r0, r1\n"
        "    ldr r1, [r0, #0]\n"
        "    adds r0, r4, #0\n"
        "    bl _call_via_r1\n"
        "    lsrs r0, r0, #8\n"
        "    movs r1, #1\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    bne .LJoyBus_status_48_1\n"
        "    ldr r0, [r4, #0]\n"
        "    movs r1, #130\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    ldr r1, [r0, #0]\n"
        "    adds r0, r4, #0\n"
        "    bl _call_via_r1\n"
        "    lsrs r0, r0, #8\n"
        "    movs r1, #2\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    bne .LJoyBus_status_48_2\n"
        ".LJoyBus_status_48_0:\n"
        "    bl func_080D06D0\n"
        "    cmp r0, #0\n"
        "    beq .LJoyBus_status_48_1\n"
        "    cmp r0, #11\n"
        "    bne .LJoyBus_status_48_2\n"
        ".LJoyBus_status_48_1:\n"
        "    movs r0, #0\n"
        "    b .LJoyBus_status_48_3\n"
        ".LJoyBus_status_48_2:\n"
        "    movs r0, #1\n"
        ".LJoyBus_status_48_3:\n"
        "    pop {r4}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .align 2, 0\n"
    );
}

inline void JoyBusLinkProtocol::UpdateTransport() { UpdateJoyBusCommunication(); }

inline void JoyBusLinkProtocol::StartTransport() { StartJoyBusCommunication(); }

inline void JoyBusLinkProtocol::StopTransport() { StopJoyBusCommunication(); }

inline bool JoyBusLinkProtocol::Unk_50()
{
    return true;
}

inline NAKED bool JoyBusLinkProtocol::Unk_54()
{
    asm_unified(
        "    push {lr}\n"
        "    adds r2, r0, #0\n"
        "    movs r1, #220\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r2, r1\n"
        "    ldrb r0, [r0, #0]\n"
        "    cmp r0, #0\n"
        "    beq .LJoyBus_status_54_0\n"
        "    adds r1, #1\n"
        "    adds r0, r2, r1\n"
        "    ldrb r0, [r0, #0]\n"
        "    b .LJoyBus_status_54_2\n"
        ".LJoyBus_status_54_0:\n"
        "    ldr r0, [r2, #0]\n"
        "    ldr r1, [r0, #76]\n"
        "    adds r0, r2, #0\n"
        "    bl _call_via_r1\n"
        "    cmp r0, #0\n"
        "    beq .LJoyBus_status_54_1\n"
        "    movs r0, #0\n"
        "    b .LJoyBus_status_54_2\n"
        ".LJoyBus_status_54_1:\n"
        "    movs r0, #1\n"
        ".LJoyBus_status_54_2:\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}

inline bool JoyBusLinkProtocol::Unk_58()
{
    if (mode_enabled)
        return unk_1BA;
    if (record[1] != 0 && record[1] != received_record[0])
        return true;
    return false;
}

inline bool JoyBusLinkProtocol::Unk_5C()
{
    if (mode_enabled) {
        if (unk_1BB)
            return false;
        return true;
    }
    return GetReceivedWord() == 0;
}


#include "scene_gamecube_link_callbacks.hh"

#endif // SCENE_GAMECUBE_LINK_HH
