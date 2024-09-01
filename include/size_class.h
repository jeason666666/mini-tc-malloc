#ifndef TCMALLOC_SIZE_CLASS_H
#define TCMALLOC_SIZE_CLASS_H

#include <cstddef>

namespace tcmalloc {
namespace tcmalloc_internal {

#define SIZE_COUNT 128

#define MAX_PAGE_COUNT 128

#define ONE_PAGE_SIZE (1 << 16)

unsigned int g_size_list[SIZE_COUNT] = {
  
  // TODO
};

size_t RoundUp(size_t size);

size_t NumMoveFreeListNode(size_t size);

size_t NumMovePage(size_t size);

} // namespace tcmalloc_internal
} // namespace tcmalloc

#endif
