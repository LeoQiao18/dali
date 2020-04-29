//
// Created by Leo on 4/23/2020.
//

#include <dali/app.h>
#include <dali/common.h>

#include <GLFW/glfw3.h>

namespace dali {

    App::App() {
        m_window = std::unique_ptr<Window>(Window::create());
    }

    App::~App() {

    }

    void App::run() {
        while (m_running) {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_window->on_update();
        }
    }

}
