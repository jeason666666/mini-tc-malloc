#include "common.hpp"

#include "tcmalloc.h"
#include "thread_cache.h"

#include <stdlib.h>

namespace tcmalloc {
namespace tcmalloc_internal {

} // namespace tcmalloc_internal

void* malloc(size_t size)
{
    // if size < 256 KB 
    // fetch memory from thread_cahce
    if (size < 256 * 1024 * 8) {
        return tcmalloc_internal::ThreadCache::Allocate(size);
    } else {
        // fetch memory from system directly
        // TODO : 
    }
    return ::malloc(size);
}

} // namespace tcmalloc
