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

        inline static std::shared_ptr<spdlog::logger>& get_core_logger();
        inline static std::shared_ptr<spdlog::logger>& get_client_logger();

    private:
        static std::shared_ptr<spdlog::logger> s_core_logger;
        static std::shared_ptr<spdlog::logger> s_client_logger;

    };
}

#endif //DALI_LOG_H
