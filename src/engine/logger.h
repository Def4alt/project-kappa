#ifndef PROJECT_KAPPA_LOGGER_H
#define PROJECT_KAPPA_LOGGER_H

#include <string>
#include <fstream>
#include <spdlog/spdlog.h>

namespace engine
{
    class Logger
    {
    public:
        static void init();

        inline static std::shared_ptr<spdlog::logger> &get_logger() { return logger_; }

    private:
        static std::shared_ptr<spdlog::logger> logger_;
    };

}

#endif //PROJECT_KAPPA_LOGGER_H
