//
// Created by Leo on 4/28/2020.
//

#include "window.h"

#include <dali/common.h>
#include <dali/core.h>
#include <dali/event.h>

namespace dali {

    static bool s_glfw_initialized = false;

    static void on_glfw_error(int error, const char *description) {
        DALI_CORE_ERROR("GLFW error ({0}): {1}", error, description);
    }

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
            glfwSetErrorCallback(on_glfw_error);
            s_glfw_initialized = true;
        }

        m_window = glfwCreateWindow(props.width, props.height, m_data.title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, &m_data);
        set_vsync(true);

        // Setup window event callbacks
        glfwSetWindowSizeCallback(m_window, [](GLFWwindow *window, int width, int height) {
            WindowData *data = (WindowData *) glfwGetWindowUserPointer(window);
            data->width = width;
            data->height = height;

            WindowResizeEvent event(width, height);
            data->event_callback(event);
        });

        glfwSetWindowCloseCallback(m_window, [](GLFWwindow *window) {
            WindowData *data = (WindowData *) glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data->event_callback(event);
        });

        glfwSetKeyCallback(m_window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
            WindowData *data = (WindowData *) glfwGetWindowUserPointer(window);
            switch (action) {
                case GLFW_PRESS: {
                    KeyPressedEvent event(key, 0);
                    data->event_callback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    KeyReleasedEvent event(key);
                    data->event_callback(event);
                    break;
                }
                case GLFW_REPEAT: {
                    KeyPressedEvent event(key, 1);
                    data->event_callback(event);
                    break;
                }
            }
        });

        glfwSetCharCallback(m_window, [](GLFWwindow *window, unsigned int keycode) {
            WindowData *data = (WindowData *) glfwGetWindowUserPointer(window);

            KeyTypedEvent event(keycode);
            data->event_callback(event);
        });

        glfwSetMouseButtonCallback(m_window, [](GLFWwindow *window, int button, int action, int mods) {
            WindowData *data = (WindowData *) glfwGetWindowUserPointer(window);

            switch (action) {
                case GLFW_PRESS: {
                    MouseButtonPressedEvent event(button);
                    data->event_callback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    MouseButtonReleasedEvent event(button);
                    data->event_callback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_window, [](GLFWwindow *window, double xOffset, double yOffset) {
            WindowData *data = (WindowData *) glfwGetWindowUserPointer(window);

            MouseScrolledEvent event((float) xOffset, (float) yOffset);
            data->event_callback(event);
        });

        glfwSetCursorPosCallback(m_window, [](GLFWwindow *window, double xPos, double yPos) {
            WindowData *data = (WindowData *) glfwGetWindowUserPointer(window);

            MouseMovedEvent event((float) xPos, (float) yPos);
            data->event_callback(event);
        });
    }

    void WindowsWindow::shutdown() {
        glfwDestroyWindow(m_window);
    }
}
