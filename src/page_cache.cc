#include "page_cache.h"
#include "system_alloc.h"

namespace tcmalloc {
namespace tcmalloc_internal {

PageCache* PageCache::inst_ = new PageCache;

PageCache::PageCache() {

}

Span* PageCache::AllocateSpan(size_t page_size) {
  Span* ret_span = nullptr;
  page_cache_lock_.lock();
  if (!span_lists_[page_size]->Empty()) {
    ret_span = span_lists_[page_size]->PopHead();
  } else {
    for (size_t i = page_size; i <= MAX_PAGE_COUNT; i++) {
      if (!span_lists_[i]->Empty()) {
        // slice lager span
        Span* larger_span = span_lists_[i]->PopHead();
        ret_span = new Span;
        ret_span->head = larger_span->head;
        ret_span->page_num = page_size;
        
        larger_span->page_num = i - page_size;
        larger_span->head += ONE_PAGE_SIZE * page_size;
        span_lists_[i - page_size]->InsertHead(larger_span);

      } else if (i == MAX_PAGE_COUNT) {
        // no satisfied span, alloc from system
        void* sys_memory = system_alloc(MAX_PAGE_COUNT);

        Span* new_span = new Span;
        new_span->head = sys_memory;
        new_span->page_num = MAX_PAGE_COUNT;
        span_lists_[MAX_PAGE_COUNT]->InsertHead(new_span);
        
        ret_span = AllocateSpan(page_size);
      }
    }
  }
  page_cache_lock_.unlock();
  return ret_span;
}

} // namespace tcmalloc_internal
} // namespace tcmalloc
