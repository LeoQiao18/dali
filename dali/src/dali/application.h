//
// Created by Leo on 4/23/2020.
//

#ifndef DALI_APPLICATION_H
#define DALI_APPLICATION_H

#include "Core.h"
#include <iostream>

namespace Dali {

    class DALI_API Application {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // This function should be defined in client application
    Application* CreateApplication();

}

#endif //DALI_APPLICATION_H
