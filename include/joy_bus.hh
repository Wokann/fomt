#ifndef JOY_BUS_HH
#define JOY_BUS_HH

#include "prelude.h"

enum { JOY_BUS_COMMAND_SLOT_COUNT = 10 };

typedef struct JoyBusCommand JoyBusCommand;
typedef struct JoyBusContext JoyBusContext;

struct JoyBusCommand {
    u32 kind;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C[5];
};

// Verified SDK view through +0x184, not a declaration of the enclosing scene.
// Undecoded protocol fields keep their offsets rather than guessed meanings.
struct JoyBusContext {
    u32 state;
    u32 local_code;
    u32 remote_code;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    /* +28 */ u8 unk_28[4];   // byte-ordered command payload
    u8 unk_2C[4];             // byte-ordered response payload
    u32 unk_30;
    u32 read_index;
    u32 write_index;
    JoyBusCommand commands[JOY_BUS_COMMAND_SLOT_COUNT];
    u32 unk_17C;
    u32 result;
    u32 unk_184;
};

EXTERN_C

extern JoyBusCommand * gCurrentJoyBusCommand;
extern JoyBusContext * gJoyBusContext;

void InitializeJoyBusContext(JoyBusContext * context);
void StartJoyBusCommunication(void);
void StopJoyBusCommunication(void);
void FinishJoyBusCommand(u32 result);
void ResetJoyBusCommandResult(void);
void EnableJoyBusInterrupt(void);
void DisableJoyBusInterrupt(void);
void ResetJoyBusCommandQueue(void);

// The native ring has ten slots, but does not test for a full queue here.
// Enqueue also clears unk_04/unk_08 in the caller's command before copying it.
void EnqueueJoyBusCommand(JoyBusCommand * command);
void AdvanceJoyBusCommandQueue(void);
u32 IsJoyBusCommandQueueEmpty(void);
void ClearJoyBusCommandQueue(void);

// Link-register reset is a no-op in JP/US, with real writes in EU/DE.
void ResetJoyBusLinkRegisters(void);
void HandleJoyBusResetSignal(void);
u32 UpdateJoyBusCommunication(void);
void ConfigureJoyBusRegisters(u32 reset_serial, u32 set_status_flags);

// Native transport entry points used by the protocol adapter.
void func_080D0444(u32 local_code, u32 remote_code);
void func_080D0454(u32 mode);
void func_080D0558(void const * outgoing, u32 outgoing_size, void * incoming, u32 incoming_size);
void func_080D0644(u32 value, u32 mode);
u32 func_080D0678(void);
void func_080D06A8(void);
u32 func_080D06B4(void);
u32 func_080D06D0(void);
void func_080D0704(void);

EXTERN_C_END

#endif // JOY_BUS_HH
