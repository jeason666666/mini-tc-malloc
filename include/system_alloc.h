#ifndef TCMALLOC_SYSTEM_ALLOC_H
#define TCMALLOC_SYSTEM_ALLOC_H

#include <cstddef>

namespace tcmalloc {
namespace tcmalloc_internal {

void* system_alloc(size_t page_size);

} // namespace tcmalloc_internal
} // namespace tcmalloc

#endif // TCMALLOC_SYSTEM_ALLOC_H
