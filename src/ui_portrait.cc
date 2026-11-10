#include <new>
#include "ui_portrait.hh"

static inline IndexedResourceGroupResult LoadUiPortraitGroup(u32 index)
{
    IndexedResourceArchive archive(gPortraitIndexedResourceArchive);
    IndexedResourceProvider const * provider = &archive;
    return provider->GetGroupData(provider->Resolve(index)[0].group_index);
}

UiPortraitGroupOwner::UiPortraitGroupOwner()
    : value(new IndexedResourceGroupResult(0, 0, 0, 0, 0, 0, 0, 0)) {}

UiPortraitGroupOwner::UiPortraitGroupOwner(u32 index)
    : value(new IndexedResourceGroupResult(LoadUiPortraitGroup(index))) {}

UiPortraitGroupOwner::~UiPortraitGroupOwner()
{
    delete value;
}

void UiPortraitGroupOwner::Set(u32 index)
{
    *value = LoadUiPortraitGroup(index);
}

IndexedResourceGroupResult UiPortraitGroupOwner::Get() const
{
    return *value;
}

u32 GetUiPortraitCount()
{
    IndexedResourceArchive archive(gPortraitIndexedResourceArchive);
    return archive.entry_descriptor_count;
}
