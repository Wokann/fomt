#ifndef RESOURCE_ARCHIVE_PROVIDER_HH
#define RESOURCE_ARCHIVE_PROVIDER_HH

#include "prelude.h"

struct IndexedResourceResult;
struct IndexedResourceGroupResult;

#pragma interface "resource_archive_provider.hh"

struct IndexedResourceProvider
{
    virtual inline ~IndexedResourceProvider();
    virtual IndexedResourceResult Resolve(u32 index) const = 0;
    virtual IndexedResourceGroupResult GetGroupData(u32 index) const = 0;
};

inline IndexedResourceProvider::~IndexedResourceProvider() {}


#endif // RESOURCE_ARCHIVE_PROVIDER_HH
