#include "thread_cache_freelist.h"

namespace tcmalloc {
namespace tcmalloc_internal {

void FreeList::Push(void* mem)
{
  // head insertion
  *(void**)(mem) = NextObj(head_);
  *(void**)(head_) = mem;

  size_++;
}

void FreeList::PushRange(void* start, void* end, size_t size)
{
  NextObj(end) = head_;
  head_ = start;

  size_ += size;
}

void* FreeList::Pop()
{
  // head deletion
  void* ret = head_;
  head_ = NextObj(head_);

  size_--;
  return ret;
}

size_t FreeList::Size()
{
  return size_;
}

} // tcmalloc_internal
} // tcmalloc
