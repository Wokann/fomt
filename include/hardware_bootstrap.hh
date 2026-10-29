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
#ifndef __cplusplus
    void ** vtable;
#endif
#ifdef __cplusplus
    HardwareBootstrap();
    HardwareBootstrap(HardwareInputRepeatParameters const & input);
    HardwareBootstrap(HardwareSpriteBufferParameters const & buffer);
    HardwareBootstrap(HardwareInputRepeatParameters const & input,
        HardwareSpriteBufferParameters const & buffer);
    virtual ~HardwareBootstrap();
#endif
};

// Only the existing free native scene initializers install a table directly.
// GCC 2.9 places this vptr immediately after state; normal C++ construction
// and destruction use the compiler's own table. This is an ABI operation,
// not a separate allocation or a substitute scene constructor.
#ifdef __cplusplus
static inline void InstallHardwareBootstrapNativeVTable(HardwareBootstrap * owner,
    void const * table)
{
    *reinterpret_cast<void const **>(reinterpret_cast<u8 *>(owner) + sizeof(owner->state)) = table;
}
#endif

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
    virtual bool Run() asm("RunHardwareDisplayCommand") SECTION(".text.hardware_frame_commands");
    // The retail callers inline these constructors. Keep any emitted fallback
    // bodies separate from the module's original out-of-line entries.
    HardwareDisplayCommand(HardwareDisplayState * state)
        SECTION(".text.hardware_frame_command_constructors");
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
    virtual bool Run() asm("RunHardwareSpriteBufferCommand") SECTION(".text.hardware_frame_commands");
    HardwareSpriteBufferCommand(HardwareSpriteBufferState * state)
        SECTION(".text.hardware_frame_command_constructors");
#endif
};

#ifdef __cplusplus
// Keep the command's key virtual method with the bootstrap implementation.
#pragma interface "hardware_bootstrap.hh"
#endif
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
    virtual bool Run() asm("RunHardwareDmaQueueCommand") SECTION(".text.hardware_dma_command");
    HardwareDmaQueueCommand(HardwareDmaQueue * state)
        SECTION(".text.hardware_frame_command_constructors");
#endif
};

#ifdef __cplusplus
#pragma implementation
#endif

EXTERN_C

#ifndef __cplusplus
// These are the compiler-owned tables, also referenced by native C callers.
extern struct HardwareDisplayCommandVTable const __vt_22HardwareDisplayCommand;
extern struct HardwareSpriteBufferCommandVTable const __vt_27HardwareSpriteBufferCommand;
extern struct HardwareDmaQueueCommandVTable const __vt_23HardwareDmaQueueCommand;
#endif

// Direct declarations of the actual member ABI for the scene classes whose
// complete lifecycles are still being recovered. Each asm label names the
// one compiler-defined constructor/destructor; no wrapper or alias is emitted.
struct HardwareBootstrap * ConstructHardwareBootstrap(struct HardwareBootstrap * owner) asm("__17HardwareBootstrap");
struct HardwareBootstrap * ConstructHardwareBootstrapWithInput(struct HardwareBootstrap * owner, struct HardwareInputRepeatParameters const * input) asm("__17HardwareBootstrapRC29HardwareInputRepeatParameters");
struct HardwareBootstrap * ConstructHardwareBootstrapWithSpriteBuffer(struct HardwareBootstrap * owner, struct HardwareSpriteBufferParameters const * buffer) asm("__17HardwareBootstrapRC30HardwareSpriteBufferParameters");
struct HardwareBootstrap * ConstructHardwareBootstrapWithInputAndSpriteBuffer(struct HardwareBootstrap * owner, struct HardwareInputRepeatParameters const * input, struct HardwareSpriteBufferParameters const * buffer) asm("__17HardwareBootstrapRC29HardwareInputRepeatParametersRC30HardwareSpriteBufferParameters");
void DestroyHardwareBootstrap(struct HardwareBootstrap * owner, u32 flags) asm("_._17HardwareBootstrap");
void UpdateHardwareFrame(struct HardwareBootstrap * owner) SECTION(".text.hardware_frame_update");
u32 RunHardwareDisplayCommand(struct HardwareDisplayCommand * command) SECTION(".text.hardware_frame_commands");
u32 RunHardwareSpriteBufferCommand(struct HardwareSpriteBufferCommand * command) SECTION(".text.hardware_frame_commands");
u32 RunHardwareDmaQueueCommand(struct HardwareDmaQueueCommand * command) SECTION(".text.hardware_dma_command");

EXTERN_C_END

#ifdef __cplusplus
inline HardwareDisplayCommand::HardwareDisplayCommand(HardwareDisplayState * state)
    : HardwareLinkBase()
{
    display = state;
}

inline HardwareSpriteBufferCommand::HardwareSpriteBufferCommand(HardwareSpriteBufferState * state)
    : HardwareLinkBase()
{
    buffer = state;
}

inline HardwareDmaQueueCommand::HardwareDmaQueueCommand(HardwareDmaQueue * state)
    : HardwareLinkBase()
{
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

typedef char HardwareBootstrap_size_check[sizeof(struct HardwareBootstrap) == 8 ? 1 : -1];
typedef char HardwareBootstrap_state_check[offsetof(struct HardwareBootstrap, state) == 0 ? 1 : -1];
#ifndef __cplusplus
typedef char HardwareBootstrap_vtable_check[offsetof(struct HardwareBootstrap, vtable) == 4 ? 1 : -1];
#endif

#endif // HARDWARE_BOOTSTRAP_HH
