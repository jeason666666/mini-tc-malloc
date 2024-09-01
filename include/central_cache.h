#ifndef TCMALLOC_CENTRAL_CACHE_H
#define TCMALLOC_CENTRAL_CACHE_H

#include <mutex>

#include "span_list.h"
#include "size_class.h"

namespace tcmalloc {
namespace tcmalloc_internal {

// there is only one singleton globally
class CentralCache
{
public:
  CentralCache();

public:
  static CentralCache* Instance() { return inst_; }

  void AllocateFreeListNode(size_t index, 
      void*& start, void*&end, size_t size);

  void FetchOneSpanFromPageCache(size_t index);

private:
  static CentralCache* inst_;

  SpanList span_lists_[SIZE_COUNT];
  std::mutex mtx_[SIZE_COUNT];
};

} // tcmalloc_internal
} // tcmalloc

#endif // TCMAMLLOC_CENTRAL_CACHE_H
