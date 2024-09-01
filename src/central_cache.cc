#include "central_cache.h"
#include "page_cache.h"

namespace tcmalloc {
namespace tcmalloc_internal {

CentralCache* CentralCache::inst_ = new CentralCache;

CentralCache::CentralCache()
{
}

void CentralCache::AllocateFreeListNode(size_t index, 
    void*& start, void*& end, size_t size)
{
  mtx_[index].lock();
  
  if (span_lists_[index].Empty()) {
    mtx_[index].unlock();

    FetchOneSpanFromPageCache(index);

    mtx_[index].lock();
  }

  mtx_[index].unlock();
}

void CentralCache::FetchOneSpanFromPageCache(size_t index)
{
  span_lists_[index].InsertHead(PageCache::Instance()->AllocateSpan(index));
}

} // namespace tcmalloc_internal
} // namespace tcmalloc
