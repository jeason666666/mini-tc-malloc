#ifndef TCMALLOC_CENTRAL_CACHE_SPAN_LIST_H
#define TCMALLOC_CENTRAL_CACHE_SPAN_LIST_H

#include "span.h"

namespace tcmalloc {
namespace tcmalloc_internal {

// double linked list
class SpanList
{
public:
  // head insertion
  void Insert(Span* span);

  Span* PopHead();

  bool Empty() const;

private:
  Span* head_ = nullptr;
};

} // namespace tcmalloc_internal
} // namespace tcmalloc

#endif
