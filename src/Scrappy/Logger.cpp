//
// Created by mario flores on 11/21/25.
//

#include "Logger.h"
#include "spdlog/sinks/stdout_color_sinks-inl.h"

namespace Scrappy
{
    std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;
    Logger::Logger()
    {

    }
    Logger::~Logger()
    {

    }
    void Logger::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_CoreLogger = spdlog::stdout_color_mt("SCRAPPY");
        s_CoreLogger->set_level(spdlog::level::trace);
        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }

}