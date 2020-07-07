#ifndef PROJECT_KAPPA_LOGGER_H
#define PROJECT_KAPPA_LOGGER_H

#include <string>
#include <fstream>

#define FATAL logger::level::fatal
#define ERROR logger::level::error
#define WARNING logger::level::warning
#define INFO logger::level::info
#define DEBUG logger::level::debug

namespace logger {
    enum class level
    {
        fatal,
        error,
        warning,
        info,
        debug
    };

    void start_log(const std::string& filepath);

    void log(level s, std::__cxx11::basic_string<char> msg);

    void console_log(level s, std::__cxx11::basic_string<char> msg);

    class Logger
    {
    public:
        Logger(const std::string& filepath);
        ~Logger();

        void add_log(level s, std::__cxx11::basic_string<char> msg);

        void add_console_log(level s, std::__cxx11::basic_string<char> msg);

        std::string get_time();

    private:
        std::ofstream logfile_;
        std::string levels_[5] = {"FATAL", "ERROR", "WARNING", "INFO", "DEBUG"};
    };
}

#endif //PROJECT_KAPPA_LOGGER_H
