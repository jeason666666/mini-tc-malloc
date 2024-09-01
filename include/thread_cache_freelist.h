#ifndef TCMALLOC_THREAD_CACHE_FREELIST_H
#define TCMALLOC_THREAD_CACHE_FREELIST_H

#include <cstddef>

namespace tcmalloc {
namespace tcmalloc_internal {

// get next reference of current
inline void*& NextObj(void* obj)
{
  // C point may be 4 bytes or 8 bytes in different platform
  return *((void**)obj);
}

class FreeList {
public:
	// head insertion
	void Push(void* mem);

	// head insertion
	void PushRange(void* start, void* end, size_t size);

	// get and pop head point
	void* Pop();

	size_t Size();

private:
	void* head_ = nullptr;

	// count of free list node
	size_t size_ = 0;
};
    

} // namespace tcmalloc_internal
} // namespace tcmalloc

#endif // TCMALLOC_THREAD_CACHE_FREELIST_H
