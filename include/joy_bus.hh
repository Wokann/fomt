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
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 read_index;
    u32 write_index;
    JoyBusCommand commands[JOY_BUS_COMMAND_SLOT_COUNT];
    u32 unk_17C;
    u32 result;
    u32 unk_184;
};

typedef char JoyBusCommandSizeCheck[sizeof(JoyBusCommand) == 0x20 ? 1 : -1];
typedef char JoyBusReadIndexCheck[offsetof(JoyBusContext, read_index) == 0x34 ? 1 : -1];
typedef char JoyBusWriteIndexCheck[offsetof(JoyBusContext, write_index) == 0x38 ? 1 : -1];
typedef char JoyBusCommandsCheck[offsetof(JoyBusContext, commands) == 0x3C ? 1 : -1];
typedef char JoyBusResultCheck[offsetof(JoyBusContext, result) == 0x180 ? 1 : -1];
typedef char JoyBusLastKnownFieldCheck[offsetof(JoyBusContext, unk_184) == 0x184 ? 1 : -1];

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

// These hardware/protocol routines still use their original assembly bodies.
// Link-register reset is a no-op in JP/US, with real writes in EU/DE.
void ResetJoyBusLinkRegisters(void);
u32 UpdateJoyBusCommunication(void);
void ConfigureJoyBusRegisters(u32 reset_serial, u32 set_status_flags);

EXTERN_C_END

#endif // JOY_BUS_HH
