#include "rucksack.hh"
#include <algorithm>

template <typename T>
T Rucksack::Slots<T>::push_back(T value)
{
    T result((*this)[0]);
    std::copy(begin() + 1, end(), begin());
    (*this)[size() - 1] = value;
    return result;
}

template <typename T>
T Rucksack::Slots<T>::push_front(T value)
{
    T result((*this)[m_size - 1]);
    std::copy_backward(begin(), end() - 1, end());
    (*this)[0] = value;
    return result;
}

template RucksackItem Rucksack::Slots<RucksackItem>::push_back(RucksackItem);
template RucksackItem Rucksack::Slots<RucksackItem>::push_front(RucksackItem);
template ToolStack Rucksack::Slots<ToolStack>::push_back(ToolStack);
template ToolStack Rucksack::Slots<ToolStack>::push_front(ToolStack);
