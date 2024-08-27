#include "thread_cache.h"

namespace tcmalloc {
namespace tcmalloc_internal {

ThreadCache* ThreadCache::thread_cache_ = nullptr; 

ThreadCache::ThreadCache()
{
    thread_cache_ = new ThreadCache;
}

ThreadCache* ThreadCache::GetInstance()
{
    return thread_cache_;
}

void* ThreadCache::Allocate(size_t size)
{
    
}

} // namespace tcmalloc_internal
} // namespace tcmalloc
