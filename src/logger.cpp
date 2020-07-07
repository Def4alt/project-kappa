#include <memory>
#include <iostream>
#include <SDL.h>
#include <sstream>
#include "logger.h"

namespace logger {
    std::unique_ptr<Logger> g_log;

    void start_log(const std::string &filepath) {
        g_log = std::make_unique<Logger>(filepath);
        log(level::info, "Started logging");
    }

    void log(logger::level s, std::__cxx11::basic_string<char> msg) {
        g_log->add_log(s, msg);
    }


    void console_log(logger::level s, std::__cxx11::basic_string<char> msg) {
        g_log->add_console_log(s, msg);
    }

    Logger::Logger(const std::string &filepath) {
        logfile_.open(filepath);
    }

    Logger::~Logger() {
        add_log(level::info, "Stopped logging");
        logfile_.close();
    }

    void Logger::add_log(logger::level s, std::__cxx11::basic_string<char> msg) {
        if (logfile_.is_open())
            logfile_ << "[" << get_time() << " " << levels_[(int)s] << "]" << ": " << msg << std::endl;
    }

    void Logger::add_console_log(logger::level s, std::__cxx11::basic_string<char> msg) {
        std::cout << levels_[(int)s] << ": " << msg;
    }

    std::string Logger::get_time() {
        const auto ticks = SDL_GetTicks();

        std::stringstream ss;
        ss << ticks / (1000 * 60 * 60) << ":" << ticks / (1000 * 60) << ":" << ticks / 1000 << "." << ticks;

        return ss.str();
    }
}
