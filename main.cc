// this file just for test new function

#include "tcmalloc.h"

int main()
{
    void* buf = tcmalloc::malloc(10);
    return 0;
}