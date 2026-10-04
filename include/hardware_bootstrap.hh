#ifndef HARDWARE_BOOTSTRAP_HH
#define HARDWARE_BOOTSTRAP_HH

#include "prelude.h"
#include "hardware_linked_list.hh"

struct HardwareCoreState;
struct HardwareInputRepeatParameters;
struct HardwareSpriteBufferParameters;
struct HardwareDisplayState;
struct HardwareSpriteBufferState;
struct HardwareDmaQueue;
struct HardwareLink;
struct HardwareDisplayCommand;
struct HardwareSpriteBufferCommand;
struct HardwareDmaQueueCommand;

// GCC 2.9 command tables have two metadata words before the run and
// destruction callbacks. Preserve the words without guessing their meaning.
struct HardwareDisplayCommandVTable {
    void const * metadata[2];
    u32 (*run)(struct HardwareDisplayCommand *);
    void (*destroy)(struct HardwareDisplayCommand *, u32);
};

struct HardwareSpriteBufferCommandVTable {
    void const * metadata[2];
    u32 (*run)(struct HardwareSpriteBufferCommand *);
    void (*destroy)(struct HardwareSpriteBufferCommand *, u32);
};

struct HardwareDmaQueueCommandVTable {
    void const * metadata[2];
    u32 (*run)(struct HardwareDmaQueueCommand *);
    void (*destroy)(struct HardwareDmaQueueCommand *, u32);
};

struct HardwareBootstrap {
    struct HardwareCoreState * state;
    void ** vtable;
};

struct HardwareDisplayCommand
#ifdef __cplusplus
    : HardwareLinkBase
#endif
{
#ifndef __cplusplus
    struct HardwareLink ** previous_slot;
    struct HardwareLink * next;
    struct HardwareDisplayCommandVTable const * vtable;
#endif
    struct HardwareDisplayState * display;
#ifdef __cplusplus
    // The display-control paths fill this command's fields explicitly.
    HardwareDisplayCommand();
    HardwareDisplayCommand(HardwareDisplayState * state);
#endif
};

struct HardwareSpriteBufferCommand
#ifdef __cplusplus
    : HardwareLinkBase
#endif
{
#ifndef __cplusplus
    struct HardwareLink ** previous_slot;
    struct HardwareLink * next;
    struct HardwareSpriteBufferCommandVTable const * vtable;
#endif
    struct HardwareSpriteBufferState * buffer;
#ifdef __cplusplus
    HardwareSpriteBufferCommand(HardwareSpriteBufferState * state);
#endif
};

struct HardwareDmaQueueCommand
#ifdef __cplusplus
    : HardwareLinkBase
#endif
{
#ifndef __cplusplus
    struct HardwareLink ** previous_slot;
    struct HardwareLink * next;
    struct HardwareDmaQueueCommandVTable const * vtable;
#endif
    struct HardwareDmaQueue * queue;
#ifdef __cplusplus
    HardwareDmaQueueCommand(HardwareDmaQueue * state);
#endif
};

EXTERN_C

extern struct HardwareDisplayCommandVTable const gHardwareDisplayCommandVTable;
extern struct HardwareSpriteBufferCommandVTable const gHardwareSpriteBufferCommandVTable;
extern struct HardwareDmaQueueCommandVTable const gHardwareDmaQueueCommandVTable;

struct HardwareBootstrap * func_08008444(struct HardwareBootstrap * owner);
struct HardwareBootstrap * func_080084DC(struct HardwareBootstrap * owner, struct HardwareInputRepeatParameters const * input);
struct HardwareBootstrap * func_08008574(struct HardwareBootstrap * owner, struct HardwareSpriteBufferParameters const * buffer);
struct HardwareBootstrap * func_08008618(struct HardwareBootstrap * owner, struct HardwareInputRepeatParameters const * input, struct HardwareSpriteBufferParameters const * buffer);
void func_080086BC(struct HardwareBootstrap * owner, u32 flags);
void func_08008724(struct HardwareBootstrap * owner);
void func_08008774(struct HardwareBootstrap * owner);
void UpdateHardwareFrame(struct HardwareBootstrap * owner);
u32 RunHardwareDisplayCommand(struct HardwareDisplayCommand * command) SECTION(".text.hardware_frame_commands");
u32 RunHardwareSpriteBufferCommand(struct HardwareSpriteBufferCommand * command) SECTION(".text.hardware_frame_commands");
u32 RunHardwareDmaQueueCommand(struct HardwareDmaQueueCommand * command); // Still Thumb assembly.
void DestroyHardwareDmaQueueCommand(struct HardwareDmaQueueCommand * command, u32 flags) SECTION(".text.hardware_frame_command_cleanup");
void DestroyHardwareSpriteBufferCommand(struct HardwareSpriteBufferCommand * command, u32 flags) SECTION(".text.hardware_frame_command_cleanup");
void DestroyHardwareDisplayCommand(struct HardwareDisplayCommand * command, u32 flags) SECTION(".text.hardware_frame_command_cleanup");

EXTERN_C_END

#ifdef __cplusplus
inline HardwareDisplayCommand::HardwareDisplayCommand()
    : HardwareLinkBase()
{
}

inline HardwareDisplayCommand::HardwareDisplayCommand(HardwareDisplayState * state)
    : HardwareLinkBase()
{
    vtable = (void **)&gHardwareDisplayCommandVTable;
    display = state;
}

inline HardwareSpriteBufferCommand::HardwareSpriteBufferCommand(HardwareSpriteBufferState * state)
    : HardwareLinkBase()
{
    vtable = (void **)&gHardwareSpriteBufferCommandVTable;
    buffer = state;
}

inline HardwareDmaQueueCommand::HardwareDmaQueueCommand(HardwareDmaQueue * state)
    : HardwareLinkBase()
{
    vtable = (void **)&gHardwareDmaQueueCommandVTable;
    queue = state;
}
#endif

typedef char HardwareDisplayCommand_size_check[sizeof(struct HardwareDisplayCommand) == 0x10 ? 1 : -1];
typedef char HardwareSpriteBufferCommand_size_check[sizeof(struct HardwareSpriteBufferCommand) == 0x10 ? 1 : -1];
typedef char HardwareDmaQueueCommand_size_check[sizeof(struct HardwareDmaQueueCommand) == 0x10 ? 1 : -1];
typedef char HardwareDisplayCommand_payload_check[offsetof(struct HardwareDisplayCommand, display) == 0x0C ? 1 : -1];
typedef char HardwareSpriteBufferCommand_payload_check[offsetof(struct HardwareSpriteBufferCommand, buffer) == 0x0C ? 1 : -1];
typedef char HardwareDmaQueueCommand_payload_check[offsetof(struct HardwareDmaQueueCommand, queue) == 0x0C ? 1 : -1];
typedef char HardwareDisplayCommandVTable_size_check[sizeof(struct HardwareDisplayCommandVTable) == 0x10 ? 1 : -1];
typedef char HardwareSpriteBufferCommandVTable_size_check[sizeof(struct HardwareSpriteBufferCommandVTable) == 0x10 ? 1 : -1];
typedef char HardwareDmaQueueCommandVTable_size_check[sizeof(struct HardwareDmaQueueCommandVTable) == 0x10 ? 1 : -1];

#endif // HARDWARE_BOOTSTRAP_HH
