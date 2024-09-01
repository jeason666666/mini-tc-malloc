#include "central_cache.h"
#include "thread_cache.h"

namespace tcmalloc {
namespace tcmalloc_internal {

ThreadCache* ThreadCache::inst_ = new ThreadCache; 

ThreadCache::ThreadCache()
{
}

void* ThreadCache::Allocate(size_t size)
{
  size_t index = g_size_list[size];
  if (inst_->free_lists_[index].Size()) {
    // hit cache
    return inst_->free_lists_[index].Pop();
  } else {
    // fetch from central cache
    ThreadCache::Instance()->FetchFromCentralCache(size);
    return Allocate(size);
  }
}

void ThreadCache::FetchFromCentralCache(size_t size)
{
  size_t count = NumMoveFreeListNode(size);

  void* start = nullptr, *end = nullptr;
  CentralCache::Instance()->AllocateFreeListNode(count, size);
} 

} // namespace tcmalloc_internal
} // namespace tcmalloc
