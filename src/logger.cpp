#include <memory>
#include <iostream>
#include <SDL.h>
#include <sstream>
#include "logger.h"

#include "spdlog/sinks/basic_file_sink.h"

namespace logger {
    std::shared_ptr<spdlog::logger> Logger::logger_;

    void Logger::init() {
        spdlog::set_pattern("[%H:%M:%S.%e] [%l] [%s:%#] %v");
        
		logger_ = spdlog::basic_logger_mt("main", "logs/main.txt", true);
		logger_->set_level(spdlog::level::trace);
        spdlog::set_default_logger(logger_);
    }
}
