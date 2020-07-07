#ifndef PROJECT_KAPPA_ERROR_H
#define PROJECT_KAPPA_ERROR_H

#if defined(_MSC_VER)

#define DEBUG_BREAK __debugbreak()

#elif defined(__GNUC__)

#define DEBUG_BREAK __builtin_trap()

#elif defined(__clang__) && defined(__has_builtin(__builtin_debugtrap))

#define DEBUG_BREAK __builtin_debugtrap()

#else

#include <signal.h>
#define DEBUG_BREAK raise(SIGABRT)

#endif

#define ASSERT(x) if (!(x)) DEBUG_BREAK;

#define GL_WRAP(x) error::clear_errors();\
    x;\
    ASSERT(error::log_errors(#x, __FILE__, __LINE__));

namespace error {
    void clear_errors();
    bool log_errors(const char* function, const char* file, int line);
}


#endif //PROJECT_KAPPA_ERROR_H
