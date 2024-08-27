#ifndef TCMALLOC_LOG_HPP
#define TCMALLOC_LOG_HPP

#include <fstream>
#include <string>

#include <assert.h>

namespace tcmalloc {
namespace tcmalloc_internal {

void TC_LOG(std::string s)
{
    std::ofstream logFile("./logs/tcmalloc_logs");
    logFile << s << '\n';
}

void TCMALLOC_ASSERT(bool cond)
{
    assert(cond);
}

} // namespace tcmalloc_internal
} // namespace tcmalloc

#endif // TCMALLOC_LOG_HPP
