#include "debug.h"
#include "logger.h"

#include <GL/glew.h>
#include <sstream>

void engine::Debug::open_gl_log_message(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
{
    switch (severity)
    {
    case GL_DEBUG_SEVERITY_HIGH:
        SPDLOG_ERROR("[OpenGL Debug HIGH] {0}", message);
        break;
    case GL_DEBUG_SEVERITY_MEDIUM:
        SPDLOG_WARN("[OpenGL Debug MEDIUM] {0}", message);
        break;
    case GL_DEBUG_SEVERITY_LOW:
        SPDLOG_INFO("[OpenGL Debug LOW] {0}", message);
        break;
    case GL_DEBUG_SEVERITY_NOTIFICATION:
        SPDLOG_TRACE("[OpenGL Debug NOTIFICATION] {0}", message);
        break;
    }
}

void engine::Debug::enable_gl_debugging()
{
    glDebugMessageCallback(open_gl_log_message, nullptr);
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
}