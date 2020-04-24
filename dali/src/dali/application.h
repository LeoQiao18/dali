//
// Created by Leo on 4/23/2020.
//

#ifndef DALI_APPLICATION_H
#define DALI_APPLICATION_H

#include "core.h"
#include <iostream>

namespace dali {

    class DALI_API Application {
    public:
        Application();
        virtual ~Application();

        void run();
    };

    // This function should be defined in client application
    Application* create_application();

}

#endif //DALI_APPLICATION_H
