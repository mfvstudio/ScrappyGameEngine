//
// Created by mario flores on 11/21/25.
//

#ifndef SCRAPPYGAMEENGINE_LOGGER_H
#define SCRAPPYGAMEENGINE_LOGGER_H
#include "spdlog/spdlog.h"
#include <memory>

namespace Scrappy
{
    class Logger
    {
    public:
        Logger();
        ~Logger();
        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {return s_CoreLogger;}
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {return s_ClientLogger;}
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

#endif //SCRAPPYGAMEENGINE_LOGGER_H

#define Scrappy_ERROR(...)  ::Scrappy::Logger::GetCoreLogger()->error(__VA_ARGS__);
#define Scrappy_WARN(...)   ::Scrappy::Logger::GetCoreLogger()->warn(__VA_ARGS__);
#define Scrappy_INFO(...)   ::Scrappy::Logger::GetCoreLogger()->info(__VA_ARGS__);
#define Scrappy_TRACE(...)  ::Scrappy::Logger::GetCoreLogger()->trace(__VA_ARGS__);
#define Scrappy_FATAL(...)  ::Scrappy::Logger::GetCoreLogger()->fatal(__VA_ARGS__);

#define CLIENT_ERROR(...)  ::Scrappy::Logger::GetClientLogger()->error(__VA_ARGS__);
#define CLIENT_WARN(...)   ::Scrappy::Logger::GetClientLogger()->warn(__VA_ARGS__);
#define CLIENT_INFO(...)   ::Scrappy::Logger::GetClientLogger()->info(__VA_ARGS__);
#define CLIENT_TRACE(...)  ::Scrappy::Logger::GetClientLogger()->trace(__VA_ARGS__);
#define CLIENT_FATAL(...)  ::Scrappy::Logger::GetClientLogger()->fatal(__VA_ARGS__);