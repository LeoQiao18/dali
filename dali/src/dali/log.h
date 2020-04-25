//
// Created by Leo on 4/24/2020.
//

#ifndef DALI_LOG_H
#define DALI_LOG_H

#include "core.h"

#include <spdlog/spdlog.h>

namespace dali {
    class DALI_API Log {
    public:
        static void init();

        inline static std::shared_ptr<spdlog::logger>& get_core_logger() {
            return s_core_logger;
        }
        inline static std::shared_ptr<spdlog::logger>& get_client_logger() {
            return s_client_logger;
        }

    private:
        static std::shared_ptr<spdlog::logger> s_core_logger;
        static std::shared_ptr<spdlog::logger> s_client_logger;

    };
}

// Core logging macros
#define DALI_CORE_TRACE(...) dali::Log::get_core_logger()->trace(__VA_ARGS__)
#define DALI_CORE_INFO(...) dali::Log::get_core_logger()->info(__VA_ARGS__)
#define DALI_CORE_WARN(...) dali::Log::get_core_logger()->warn(__VA_ARGS__)
#define DALI_CORE_ERROR(...) dali::Log::get_core_logger()->error(__VA_ARGS__)
#define DALI_CORE_FATAL(...) dali::Log::get_core_logger()->fatal(__VA_ARGS__)

// Client logging macros
#define DALI_CLIENT_TRACE(...) dali::Log::get_client_logger()->trace(__VA_ARGS__)
#define DALI_CLIENT_INFO(...) dali::Log::get_client_logger()->info(__VA_ARGS__)
#define DALI_CLIENT_WARN(...) dali::Log::get_client_logger()->warn(__VA_ARGS__)
#define DALI_CLIENT_ERROR(...) dali::Log::get_client_logger()->error(__VA_ARGS__)
#define DALI_CLIENT_FATAL(...) dali::Log::get_client_logger()->fatal(__VA_ARGS__)

#endif //DALI_LOG_H
