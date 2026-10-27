#ifndef HARDWARE_STATE_ACCESSORS_HH
#define HARDWARE_STATE_ACCESSORS_HH

#include "prelude.h"
#include <stdlib.h>
#include "hardware_display_state.hh"
#include "hardware_sprite_buffer.hh"
#include "hardware_input.hh"
#include "hardware_linked_list.hh"
#include "hardware_manager.hh"
#include "hardware_dma_descriptor.hh"

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

// Layout shared by the four bootstrap constructors and these accessors.
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

void UpdateHardwareInput(void * const * state);
u16 GetHardwareHeldKeys(void * const * state);
// The halfword input field is returned zero-extended in the ARM ABI word.
u32 GetHardwarePressedKeys(void * const * state);
// The native repeated-key mask also returns a zero-extended ABI word.
u32 GetHardwareRepeatedKeys(void * const * state);
struct HardwareCoreState * GetHardwareCoreState(void * const * state);

void SetHardwareRepeatDelay(void * const * state, u16 value);
void SetHardwareRepeatInterval(void * const * state, u16 value);
u16 GetHardwareRepeatDelay(void * const * state);
u16 GetHardwareRepeatInterval(void * const * state);
struct HardwareDmaQueue * GetHardwareDmaQueue(void * const * state);
struct HardwareDisplayState * GetHardwareDisplayState(void * const * state);
struct HardwareSpriteBufferState * GetHardwareSpriteBuffer(void * const * state);
u8 * func_08008928(void * const * state);
struct HardwareDisplayState * func_08008930(void * const * state);
struct HardwareSpriteBufferState * func_08008938(void * const * state);
u8 * GetHardwareCommandList(void * const * state);
u8 * GetHardwareInterruptList(void * const * state);
u8 * func_08008960(void * const * state);
u8 * func_0800896C(void * const * state);

EXTERN_C_END

#endif // HARDWARE_STATE_ACCESSORS_HH
