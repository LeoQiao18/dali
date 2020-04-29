//
// Created by Leo on 4/23/2020.
//

#ifndef DALI_APP_H
#define DALI_APP_H

#include <dali/core.h>
#include <dali/common.h>
#include <dali/window.h>

namespace dali {

    class DALI_API App {
    public:
        App();

        virtual ~App();

        void run();

    private:
        std::unique_ptr<Window> m_window;
        bool m_running = true;
    };

    // This function should be defined in client application
    App *create_app();

}

#endif //DALI_APP_H
