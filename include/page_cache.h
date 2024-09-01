#ifndef TCMALLOC_PAGE_CACHE_H
#define TCMALLOC_PAGE_CACHE_H

#include "size_class.h"
#include "span_list.h"

#include <mutex>

namespace tcmalloc {
namespace tcmalloc_internal {

class PageCache
{
public:
  PageCache();

public:
  static PageCache* Instance() { return inst_; }

  Span* AllocateSpan(size_t page_size);

private:
  static PageCache* inst_;

  SpanList* span_lists_[MAX_PAGE_COUNT];

  std::recursive_mutex page_cache_lock_;
};

} // namespace tcmalloc_internal
} // namespace tcmalloc

#endif // TCMALLOC_PAGE_CACHE_H
