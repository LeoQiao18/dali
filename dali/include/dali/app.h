//
// Created by Leo on 4/23/2020.
//

#ifndef DALI_APP_H
#define DALI_APP_H

#include <dali/core.h>
#include <iostream>

namespace dali {

    class DALI_API App {
    public:
        App();

        virtual ~App();

        void run();
    };

    // This function should be defined in client application
    App *create_app();

}

#endif //DALI_APP_H
