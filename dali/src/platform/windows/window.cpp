//
// Created by Leo on 4/28/2020.
//

#include "window.h"

#include <dali/common.h>
#include <dali/core.h>

namespace dali {

    static bool s_glfw_initialized = false;

    Window *Window::create(const WindowProps &props) {
        return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const WindowProps &props) {
        init(props);
    }

    WindowsWindow::~WindowsWindow() {
        shutdown();
    }

    void WindowsWindow::on_update() {
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }


    void WindowsWindow::set_vsync(bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }

        m_data.vsync = enabled;
    }

    bool WindowsWindow::is_vsync() const {
        return m_data.vsync;
    }

    void WindowsWindow::init(const WindowProps &props) {
        m_data.title = props.title;
        m_data.width = props.width;
        m_data.height = props.height;

        DALI_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);
        if (!s_glfw_initialized) {
            int success = glfwInit();
            DALI_CORE_ASSERT(success, "Failed to initialize GLFW!");

            s_glfw_initialized = true;
        }

        m_window = glfwCreateWindow(props.width, props.height, m_data.title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, &m_data);
        set_vsync(true);
    }

    void WindowsWindow::shutdown() {
        glfwDestroyWindow(m_window);
    }
}
