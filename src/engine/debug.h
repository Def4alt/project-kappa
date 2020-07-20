#ifndef PROJECT_KAPPA_DEBUG_H
#define PROJECT_KAPPA_DEBUG_H

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

#include "GL/glew.h"

namespace engine {
    class Debug {
    public:
        static void enable_gl_debugging();
        static void open_gl_log_message(
            GLenum source, GLenum type, GLuint id,
            GLenum severity, GLsizei length, const GLchar *message,
            const void *userParam);
    };
}


#endif //PROJECT_KAPPA_DEBUG_H
