#ifndef TCMALLOC_THREAD_CACHE_FREELIST_H
#define TCMALLOC_THREAD_CACHE_FREELIST_H

#include <cstddef>

namespace tcmalloc {
namespace tcmalloc_internal {

class FreeList {
public:
    void Push(void* mem);

    void Pop();

public:
    // get the next object of cur point
    static void* NextObj(void* current);

private:
    void* head_ = nullptr;

    size_t size_ = 0;
};
    

} // namespace tcmalloc_internal
} // namespace tcmalloc

#endif // TCMALLOC_THREAD_CACHE_FREELIST_H
