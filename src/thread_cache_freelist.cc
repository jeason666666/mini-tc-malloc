#include "thread_cache_freelist.h"

namespace tcmalloc {
namespace tcmalloc_internal {

void FreeList::Push(void* mem)
{
    // insert after head point
    void* nxt = NextObj(head_);
}

void FreeList::Pop()
{

}

void* FreeList::NextObj(void* current)
{
    // because of the platform version,
    // C point may be 4 bytes or 8 bytes
    // so we first convert 'current' to a 'void**'
    // then we defrefrence 'void**' to 'void*' thich
    // must have a correct size in this platform
    return *((void**)current);
}

} // tcmalloc_internal
} // tcmalloc
