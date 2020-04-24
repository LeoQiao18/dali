//
// Created by Leo on 4/24/2020.
//

#include "log.h"
#include <spdlog/sinks/stdout_color_sinks.h>

void dali::Log::init() {
    spdlog::set_pattern("%^[%T] %n: %v%$");
    s_core_logger = spdlog::stdout_color_mt("DALI");
    s_core_logger->set_level(spdlog::level::trace);
    s_client_logger = spdlog::stdout_color_mt("APP");
    s_client_logger->set_level(spdlog::level::trace);
}

std::shared_ptr<spdlog::logger> &dali::Log::get_core_logger() {
    return s_core_logger;
}

std::shared_ptr<spdlog::logger> &dali::Log::get_client_logger() {
    return s_client_logger;
}
