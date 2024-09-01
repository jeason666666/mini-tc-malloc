#ifndef TCMALLOC_THREAD_CACHE_H
#define TCMALLOC_THREAD_CACHE_H

#include "size_class.h"
#include "thread_cache_freelist.h"

namespace tcmalloc {
namespace tcmalloc_internal {

class ThreadCache
{
public:
  ThreadCache();

public:
  static void* Allocate(size_t size);

public:
  static ThreadCache* Instance() { return inst_; }

private:
  void FetchFromCentralCache(size_t size);

private:
  static thread_local ThreadCache* inst_;

private:
  FreeList free_lists_[SIZE_COUNT];
};

} // namespace tcmalloc_internal
} // namespace tcmalloc

#endif // TCMALLOC_THREAD_CACHE_H
