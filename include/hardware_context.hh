#ifndef HARDWARE_CONTEXT_HH
#define HARDWARE_CONTEXT_HH

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

#ifdef __cplusplus
#pragma interface "hardware_context.hh"
#endif
struct HardwareContext {
    struct HardwareCoreState * state;
#ifndef __cplusplus
    void ** vtable;
#endif
#ifdef __cplusplus
    HardwareContext();
    HardwareContext(HardwareInputRepeatParameters const & input);
    HardwareContext(HardwareSpriteBufferParameters const & buffer);
    HardwareContext(HardwareInputRepeatParameters const & input,
        HardwareSpriteBufferParameters const & buffer);
    virtual ~HardwareContext();
#endif
};

// Only the existing free native scene initializers install a table directly.
// GCC 2.9 places this vptr immediately after state; normal C++ construction
// and destruction use the compiler's own table. This is an ABI operation,
// not a separate allocation or a substitute scene constructor.
#ifdef __cplusplus
static inline void InstallHardwareContextNativeVTable(HardwareContext * owner,
    void const * table)
{
    *reinterpret_cast<void const **>(reinterpret_cast<u8 *>(owner) + sizeof(owner->state)) = table;
}
#endif

#ifdef __cplusplus
#pragma interface "hardware_context_commands.hh"
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
    virtual inline bool Run() asm("RunHardwareDisplayCommand");
    // Command construction is inline in the owning frame operation.
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
    virtual inline bool Run() asm("RunHardwareSpriteBufferCommand");
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
    virtual inline bool Run() asm("RunHardwareDmaQueueCommand");
    HardwareDmaQueueCommand(HardwareDmaQueue * state);
#endif
};

#ifdef __cplusplus
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
struct HardwareContext * ConstructHardwareContext(struct HardwareContext * owner) asm("__15HardwareContext");
struct HardwareContext * ConstructHardwareContextWithInput(struct HardwareContext * owner, struct HardwareInputRepeatParameters const * input) asm("__15HardwareContextRC29HardwareInputRepeatParameters");
struct HardwareContext * ConstructHardwareContextWithSpriteBuffer(struct HardwareContext * owner, struct HardwareSpriteBufferParameters const * buffer) asm("__15HardwareContextRC30HardwareSpriteBufferParameters");
struct HardwareContext * ConstructHardwareContextWithInputAndSpriteBuffer(struct HardwareContext * owner, struct HardwareInputRepeatParameters const * input, struct HardwareSpriteBufferParameters const * buffer) asm("__15HardwareContextRC29HardwareInputRepeatParametersRC30HardwareSpriteBufferParameters");
void DestroyHardwareContext(struct HardwareContext * owner, u32 flags) asm("_._15HardwareContext");
// Update the shadow's forced-blank bit and enqueue its VBlank upload.
void EnableHardwareForcedBlank(struct HardwareContext * owner);
void DisableHardwareForcedBlank(struct HardwareContext * owner);
void UpdateHardwareFrame(struct HardwareContext * owner);
u32 RunHardwareDisplayCommand(struct HardwareDisplayCommand * command);
u32 RunHardwareSpriteBufferCommand(struct HardwareSpriteBufferCommand * command);
u32 RunHardwareDmaQueueCommand(struct HardwareDmaQueueCommand * command);

EXTERN_C_END

#ifdef __cplusplus
#pragma interface "hardware_context.hh"
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

typedef char HardwareContext_size_check[sizeof(struct HardwareContext) == 8 ? 1 : -1];
typedef char HardwareContext_state_check[offsetof(struct HardwareContext, state) == 0 ? 1 : -1];
#ifndef __cplusplus
typedef char HardwareContext_vtable_check[offsetof(struct HardwareContext, vtable) == 4 ? 1 : -1];
#endif

#include <stdlib.h>
#include "hardware_display_state.hh"
#include "hardware_sprite_buffer.hh"
#include "hardware_input.hh"
#include "hardware_linked_list.hh"
#include "hardware_manager.hh"
#include "hardware_dma.hh"

#ifdef __cplusplus
#include "utility/container_algorithms.hh"
#endif

// The queue is grown with malloc in descriptor-sized (0x10-byte) steps.
// Its allocator has no state; the allocated range ends at offset +0x0C.
struct HardwareDmaQueueAllocator {
#ifdef __cplusplus
    HardwareDmaQueueAllocator() {}
    HardwareDmaQueueAllocator(HardwareDmaQueueAllocator const &) {}
#else
    u8 unk_00;
#endif
};

struct HardwareDmaQueueAllocation {
    struct HardwareDmaQueueAllocator allocator;
    struct DmaTransferDescriptor * end;
#ifdef __cplusplus
    HardwareDmaQueueAllocation(HardwareDmaQueueAllocator const & value)
        : allocator(value), end(nullptr) {}
#endif
};

struct HardwareDmaQueue {
    struct DmaTransferDescriptor * first;
    struct DmaTransferDescriptor * last;
    struct HardwareDmaQueueAllocation allocation;
#ifdef __cplusplus
private:
    static void * AllocateDmaBytes(u32 bytes);
    static DmaTransferDescriptor * AllocateDmaDescriptors(u32 count);
    static DmaTransferDescriptor * CopyDmaDescriptors(DmaTransferDescriptor const * first,
        DmaTransferDescriptor const * last, DmaTransferDescriptor * result);
    static DmaTransferDescriptor * FillDmaDescriptors(DmaTransferDescriptor * first,
        u32 count, DmaTransferDescriptor const & value);
    void Grow(DmaTransferDescriptor * old_end, u32 count,
        DmaTransferDescriptor const & value);

public:
    void PushBack(DmaTransferDescriptor const & value);

    ~HardwareDmaQueue()
    {
        typedef __type_traits<DmaTransferDescriptor>::has_trivial_destructor TrivialDestructor;
        DmaTransferDescriptor * end = last;
        destroy_range_inl(first, end, TrivialDestructor());
        if (first != nullptr)
            free(first);
    }

    bool IsEmpty() const { return first == last; }
    size_t Size() const { return last - first; }

    DmaTransferDescriptor * Erase(DmaTransferDescriptor * begin, DmaTransferDescriptor * end)
    {
        typedef __type_traits<DmaTransferDescriptor>::has_trivial_assignment_operator TrivialAssignment;
        typedef __type_traits<DmaTransferDescriptor>::has_trivial_destructor TrivialDestructor;
        DmaTransferDescriptor * new_end = copy_ptrs_inl(end, last, begin, TrivialAssignment());
        destroy_range_inl(new_end, last, TrivialDestructor());
        last = new_end;
        return begin;
    }

    void Clear() { Erase(first, last); }

    HardwareDmaQueue(HardwareDmaQueueAllocator const & allocator = HardwareDmaQueueAllocator())
        : first(nullptr), last(nullptr), allocation(allocator) {}
#endif
};

// Runtime layout shared by the four HardwareContext constructors and these accessors.
// Unresolved sprite parameters and display fields retain unknown names.
struct HardwareCoreState {
    struct HardwareInputState input;
    struct HardwareDmaQueue dma_queue;
    struct HardwareDisplayState display;
    struct HardwareSpriteBufferState sprite_buffer;
    struct HardwareManagerOwner manager;
    struct HardwareLinkedList links;
#ifdef __cplusplus
    HardwareCoreState(u16 delay, u16 interval, u8 byte1, u8 byte3)
        : input(delay, interval), dma_queue(), display(),
          sprite_buffer(byte1, byte3), manager(), links() {}
    HardwareCoreState(u16 delay, u16 interval, HardwareSpriteBufferParameters const & buffer)
        : input(delay, interval), dma_queue(), display(),
          sprite_buffer(buffer.byte1, buffer.byte3), manager(), links() {}
#endif
};

typedef char HardwareCoreState_size_check[sizeof(struct HardwareCoreState) == 0x4B0 ? 1 : -1];
typedef char HardwareDmaQueue_size_check[sizeof(struct HardwareDmaQueue) == 0x10 ? 1 : -1];
typedef char HardwareDmaQueue_end_check[offsetof(struct HardwareDmaQueue, allocation.end) == 0x0C ? 1 : -1];
typedef char HardwareCoreState_dma_queue_check[offsetof(struct HardwareCoreState, dma_queue) == 0x24 ? 1 : -1];
typedef char HardwareCoreState_display_check[offsetof(struct HardwareCoreState, display) == 0x34 ? 1 : -1];
typedef char HardwareCoreState_sprite_buffer_check[offsetof(struct HardwareCoreState, sprite_buffer) == 0x8C ? 1 : -1];
typedef char HardwareCoreState_manager_check[offsetof(struct HardwareCoreState, manager) == 0x490 ? 1 : -1];
typedef char HardwareCoreState_links_check[offsetof(struct HardwareCoreState, links) == 0x494 ? 1 : -1];

EXTERN_C

// Several native scene prefixes store the core-state pointer in their first
// word. The ABI accepts that slot, including prefixes not declared as subclasses.
void UpdateHardwareInput(void * const * state_slot);
u32 GetHardwareHeldKeys(void * const * state_slot);
// The halfword input field is returned zero-extended in the ARM ABI word.
u32 GetHardwarePressedKeys(void * const * state_slot);
// The native repeated-key mask also returns a zero-extended ABI word.
u32 GetHardwareRepeatedKeys(void * const * state_slot);
struct HardwareCoreState * GetHardwareCoreState(void * const * state_slot);

void SetHardwareRepeatDelay(void * const * state_slot, u16 value);
void SetHardwareRepeatInterval(void * const * state_slot, u16 value);
u16 GetHardwareRepeatDelay(void * const * state_slot);
u16 GetHardwareRepeatInterval(void * const * state_slot);
struct HardwareDmaQueue * GetHardwareDmaQueue(void * const * state_slot);
struct HardwareDisplayState * GetHardwareDisplayState(void * const * state_slot);
struct HardwareSpriteBufferState * GetHardwareSpriteBuffer(void * const * state_slot);
// Independent native entries return the same members as the three getters
// above. No caller establishes a distinct contract such as a const overload.
struct HardwareDmaQueue * func_08008928(void * const * state_slot);
struct HardwareDisplayState * func_08008930(void * const * state_slot);
struct HardwareSpriteBufferState * func_08008938(void * const * state_slot);
struct HardwareLinkedList * GetHardwareCommandList(void * const * state_slot);
struct HardwareInterruptList * GetHardwareInterruptList(void * const * state_slot);
// The retail binary likewise retains a second entry for each list.
struct HardwareLinkedList * func_08008960(void * const * state_slot);
struct HardwareInterruptList * func_0800896C(void * const * state_slot);

EXTERN_C_END

#ifdef __cplusplus
#include "hardware_context_commands.hh"
#endif

#endif // HARDWARE_CONTEXT_HH
