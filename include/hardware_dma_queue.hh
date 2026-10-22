#ifndef HARDWARE_DMA_QUEUE_HH
#define HARDWARE_DMA_QUEUE_HH

// Shared inline operations for the real DMA descriptor queue. Keep allocation
// and construction headers scoped to consumers, not the general core layout.
#include "hardware_state_accessors.hh"
#include "new.hh"
#include <memory>
#include <algorithm>

inline void * HardwareDmaQueue::AllocateDmaBytes(u32 bytes)
{
    void * result = malloc(bytes);
    if (result == nullptr)
        result = RetryMemoryAllocation(bytes);
    return result;
}

inline DmaTransferDescriptor * HardwareDmaQueue::AllocateDmaDescriptors(u32 count)
{
    return count != 0
        ? static_cast<DmaTransferDescriptor *>(AllocateDmaBytes(count * sizeof(DmaTransferDescriptor)))
        : nullptr;
}

inline DmaTransferDescriptor * HardwareDmaQueue::CopyDmaDescriptors(DmaTransferDescriptor const * first,
    DmaTransferDescriptor const * last, DmaTransferDescriptor * result)
{
    DmaTransferDescriptor * current = result;
    for (; first != last; ++first, ++current)
        std::construct(current, *first);
    return current;
}

inline DmaTransferDescriptor * HardwareDmaQueue::FillDmaDescriptors(DmaTransferDescriptor * first,
    u32 count, DmaTransferDescriptor const & value)
{
    DmaTransferDescriptor * current = first;
    for (; count != 0; --count, ++current)
        std::construct(current, value);
    return current;
}

inline void HardwareDmaQueue::Grow(DmaTransferDescriptor * old_end, u32 count,
    DmaTransferDescriptor const & value)
{
    u32 old_size = old_end - first;
    u32 new_size = old_size + std::max(old_size, count);
    DmaTransferDescriptor * replacement = AllocateDmaDescriptors(new_size);
    DmaTransferDescriptor * end = replacement;
    end = CopyDmaDescriptors(first, old_end, end);
    if (count == 1) {
        std::construct(end, value);
        ++end;
    } else {
        end = FillDmaDescriptors(end, count, value);
    }
    std::destroy(first, last);
    if (first != nullptr)
        free(first);
    DmaTransferDescriptor * capacity_end = replacement + new_size;
    first = replacement;
    last = end;
    allocation.end = capacity_end;
}

inline void HardwareDmaQueue::PushBack(DmaTransferDescriptor const & value)
{
    if (last != allocation.end) {
        std::construct(last, value);
        ++last;
    } else {
        Grow(last, 1, value);
    }
}

#endif // HARDWARE_DMA_QUEUE_HH
