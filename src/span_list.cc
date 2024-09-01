#include "span_list.h"

namespace tcmalloc {
namespace tcmalloc_internal {

void SpanList::Insert(Span* span) {
  Span* old_next = head_->next;
  
  head_->next = span;

  span->prev = head_;
  span->next = old_next;

  old_next->prev = span;
}

Span* SpanList::PopHead() {
  Span* old_next = head_->next;

  old_next->prev = head_->prev;

  // question : reinit head_ ?
  return head_;
}

bool SpanList::Empty() const {
  return head_ != nullptr;
}

} // namespace tcmalloc_internal
} // namespace tcmalloc
