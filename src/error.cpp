#include "error.h"
#include "logger.h"

#include <GL/glew.h>
#include <sstream>

void error::clear_errors() {
    while(glGetError() != GL_NO_ERROR);
}

bool error::log_errors(const char *function, const char *file, int line) {
    while (const auto error = glGetError()){
        std::stringstream ss;

        ss << "**OPENGL**" << error << ": " << function << " " << file << ":" << line;
        logger::log(ERROR, ss.str());
        return false;
    }

    return true;
}
