#ifndef RUCKSACK_HH
#define RUCKSACK_HH

#include "prelude.h"

#include "rucksack_item.hh"
#include <iterator>

struct Rucksack
{
    // Both native lists have eight slots. Only the first size() slots contain
    // constructed items; inactive save storage must not be initialized.
    template <typename T>
    struct Slots {
        typedef T value_type;
        typedef value_type * pointer;
        typedef value_type const * const_pointer;
        typedef value_type * iterator;
        typedef value_type const * const_iterator;
        typedef value_type & reference;
        typedef value_type const & const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator;

        Slots() : m_size(0) {}
        inline Slots(u32 size, T const & value);

        iterator begin() { return reinterpret_cast<T *>(m_data); }
        const_iterator begin() const { return reinterpret_cast<T const *>(m_data); }
        iterator end() { return reinterpret_cast<T *>(m_data) + m_size; }
        const_iterator end() const { return reinterpret_cast<T const *>(m_data) + m_size; }
        reverse_iterator rbegin() { return reverse_iterator(end()); }
        const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
        reverse_iterator rend() { return reverse_iterator(begin()); }
        const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
        size_type size() const { return m_size; }
        size_type max_size() const { return 8; }
        size_type capacity() const { return 8; }
        bool empty() const { return m_size == 0; }
        reference operator[](size_type idx) { return reinterpret_cast<T *>(m_data)[idx]; }
        const_reference operator[](size_type idx) const { return reinterpret_cast<T const *>(m_data)[idx]; }
        T push_back(T value);
        T push_front(T value);

    private:
        u32 m_size;
        u32 m_data[(sizeof(T) * 8 + sizeof(u32) - 1) / sizeof(u32)];
    };

    enum
    {
        LEVEL_0,
        LEVEL_1,
        LEVEL_2,
    };

    Rucksack();

    u32 GetUpgradeLevel() const;
    u32 GetSize() const;
    RucksackItem const & GetItemAt(u32 idx) const;
    bool HasNoItems() const;
    u32 GetFirstFreeItemSlot() const;
    u32 GetLastFreeItemSlot() const;
    u32 GetFirstSlotWithFood(u32 food_id) const;
    u32 GetFirstSlotWithArticle(u32 article_id) const;
    u32 GetEmptyItemSlotCount() const;
    u32 GetAmountOfFood(u32 food_id) const;
    u32 GetAmountOfArticles(u32 article_id) const;
    ToolStack const & GetToolAt(u32 idx) const;
    bool HasNoTools() const;
    u32 GetFirstFreeToolSlot() const;
    u32 GetLastFreeToolSlot() const;
    u32 GetFirstSlotWithTool(u32 tool_id) const;
    u32 GetAvailableSpaceForTool(u32 tool_id) const;
    u32 GetAmountOfTool(u32 tool_id) const;
    void Upgrade();
    RucksackItem & GetItemAt(u32 idx);
    RucksackItem ExtractItemAt(u32 idx);
    RucksackItem CycleItemBack(RucksackItem item);
    RucksackItem CycleItemFront(RucksackItem item);
    u32 AddAmountOfFood(u32 food_id, u32 amount);
    u32 AddAmountOfArticle(u32 article_id, u32 amount);
    ToolStack & GetToolAt(u32 idx);
    ToolStack ExtractToolAt(u32 idx);
    ToolStack CycleToolBack(ToolStack tool_stack);
    ToolStack CycleToolFront(ToolStack tool_stack);
    u32 AddAmountOfTool(u32 tool_id, u32 amount);

    /* +00 */ Slots<RucksackItem> items;
    /* +24 */ Slots<ToolStack> tools;
};

typedef char RucksackItemsSizeCheck[sizeof(Rucksack::Slots<RucksackItem>) == 0x24 ? 1 : -1];
typedef char RucksackToolsSizeCheck[sizeof(Rucksack::Slots<ToolStack>) == 0x14 ? 1 : -1];
typedef char RucksackSizeCheck[sizeof(Rucksack) == 0x38 ? 1 : -1];

#endif // RUCKSACK_HH
