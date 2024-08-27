#include "common.hpp"

#include "tcmalloc.h"
#include "thread_cache.h"

#include <stdlib.h>

namespace tcmalloc {

    void *malloc(size_t size)
    {
        // if size < 256 KB 
        // fetch memory from thread_cahce
        if (size < 256 * 1024 * 8) {
            
        } else {
            // fetch memory from system directly
        }
        return ::malloc(size);
    }

} // namespace tcmalloc
