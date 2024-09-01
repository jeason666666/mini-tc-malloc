#ifndef TCMALLOC_CENTRAL_CACHE_SPAN_H
#define TCMALLOC_CENTRAL_CACHE_SPAN_H

namespace tcmalloc {
namespace tcmalloc_internal {

struct Span
{
  void* head = nullptr;

  size_t page_id = 0;

  int page_num = 0;

  // double linked list
  Span* prev = nullptr;
  Span* next = nullptr;
};

} // namespace tcmalloc_internal
} // namespace tcmalloc

#endif
