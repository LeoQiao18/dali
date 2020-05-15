//
// Created by Leo on 5/14/2020.
//

#include <dali/platform/windows/input.h>
#include <dali/app.h>

#include <GLFW/glfw3.h>

namespace dali {
    Input *Input::s_instance = new WindowsInput();

    bool WindowsInput::_is_key_pressed(KeyCode key) {
        GLFWwindow *window = static_cast<GLFWwindow *>(App::get().get_window().get_native_window());

        auto state = glfwGetKey(window, static_cast<int32_t>(key));
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WindowsInput::_is_mouse_button_pressed(MouseCode button) {
        GLFWwindow *window = static_cast<GLFWwindow *>(App::get().get_window().get_native_window());

        auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    std::pair<float, float> WindowsInput::_get_mouse_position() {
        double x, y;
        GLFWwindow *window = static_cast<GLFWwindow *>(App::get().get_window().get_native_window());

        glfwGetCursorPos(window, &x, &y);
        return {(float) x, (float) y};
    }

    float dali::WindowsInput::_get_mouse_x() {
        auto[x, y] = _get_mouse_position();
        return x;
    }

    float dali::WindowsInput::_get_mouse_y() {
        auto[x, y] = _get_mouse_position();
        return y;
    }

}