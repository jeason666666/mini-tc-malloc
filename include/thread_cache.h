#ifndef TCMALLOC_THREAD_CACHE_H
#define TCMALLOC_THREAD_CACHE_H

#include "thread_cache_freelist.h"

namespace tcmalloc {
namespace tcmalloc_internal {

class ThreadCache
{
public:
    ThreadCache();

public:
    void* Allocate(size_t size);

public:
    static ThreadCache* GetInstance();

private:
    static thread_local ThreadCache* thread_cache_;

private:
    FreeList free_lists_[128];
};

} // namespace tcmalloc_internal
} // namespace tcmalloc

#endif // TCMALLOC_THREAD_CACHE_H
