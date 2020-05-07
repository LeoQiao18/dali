//
// Created by Leo on 5/3/2020.
//

#include <dali/imgui/layer.h>
#include <dali/app.h>
#include <dali/event.h>
#include <dali/platform/opengl/imgui.h>

#include <imgui.h>
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace dali {
    ImGuiLayer::ImGuiLayer()
            : Layer("ImGuiLayer") {

    }

    ImGuiLayer::~ImGuiLayer() {

    }

    void ImGuiLayer::on_attach() {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO &io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

        // Keyboard mapping. ImGui will use those indices to peek into the io.KeysDown[] array.
        io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
        io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
        io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
        io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
        io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
        io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
        io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
        io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
        io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
        io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
        io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
        io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
        io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
        io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
        io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
        io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
        io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
        io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
        io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
        io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
        io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
        io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

        ImGui_ImplOpenGL3_Init("#version 410 core");
    }

    void ImGuiLayer::on_detach() {

    }

    void ImGuiLayer::on_update() {
        ImGuiIO &io = ImGui::GetIO();
        App &app = App::get();
        io.DisplaySize = ImVec2(app.get_window().get_width(), app.get_window().get_height());

        float time = (float) glfwGetTime();
        io.DeltaTime = m_time > 0.0f ? (time - m_time) : (1.0f / 60.0f);
        m_time = time;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static bool show = true;
        ImGui::ShowDemoWindow(&show);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    }

    void ImGuiLayer::on_event(Event &e) {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<MouseButtonPressedEvent>(
                std::bind(&ImGuiLayer::on_mouse_button_pressed_event, this, std::placeholders::_1));
        dispatcher.dispatch<MouseButtonReleasedEvent>(
                std::bind(&ImGuiLayer::on_mouse_button_released_event, this, std::placeholders::_1));
        dispatcher.dispatch<MouseMovedEvent>(std::bind(&ImGuiLayer::on_mouse_moved_event, this, std::placeholders::_1));
        dispatcher.dispatch<MouseScrolledEvent>(
                std::bind(&ImGuiLayer::on_mouse_scrolled_event, this, std::placeholders::_1));
        dispatcher.dispatch<KeyPressedEvent>(std::bind(&ImGuiLayer::on_key_pressed_event, this, std::placeholders::_1));
        dispatcher.dispatch<KeyReleasedEvent>(
                std::bind(&ImGuiLayer::on_key_released_event, this, std::placeholders::_1));
        dispatcher.dispatch<KeyTypedEvent>(
                std::bind(&ImGuiLayer::on_key_typed_event, this, std::placeholders::_1));
        dispatcher.dispatch<WindowResizeEvent>(
                std::bind(&ImGuiLayer::on_window_resize_event, this, std::placeholders::_1));
    }

    bool ImGuiLayer::on_mouse_button_pressed_event(MouseButtonPressedEvent &e) {
        ImGuiIO &io = ImGui::GetIO();
        io.MouseDown[e.get_mouse_button()] = true;
        return false;
    }

    bool ImGuiLayer::on_mouse_button_released_event(MouseButtonReleasedEvent &e) {
        ImGuiIO &io = ImGui::GetIO();
        io.MouseDown[e.get_mouse_button()] = false;
        return false;
    }

    bool ImGuiLayer::on_mouse_moved_event(MouseMovedEvent &e) {
        ImGuiIO &io = ImGui::GetIO();
        io.MousePos = ImVec2(e.get_x(), e.get_y());
        return false;
    }

    bool ImGuiLayer::on_mouse_scrolled_event(MouseScrolledEvent &e) {
        ImGuiIO &io = ImGui::GetIO();
        io.MouseWheelH += e.get_x_offset();
        io.MouseWheel += e.get_y_offset();
        return false;
    }

    bool ImGuiLayer::on_key_pressed_event(KeyPressedEvent &e) {
        ImGuiIO &io = ImGui::GetIO();
        io.KeysDown[e.get_key_code()] = true;

        io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
        io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
        io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
        io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
        return false;
    }

    bool ImGuiLayer::on_key_released_event(KeyReleasedEvent &e) {
        ImGuiIO &io = ImGui::GetIO();
        io.KeysDown[e.get_key_code()] = false;

        return false;
    }

    bool ImGuiLayer::on_key_typed_event(KeyTypedEvent &e) {
        ImGuiIO& io = ImGui::GetIO();
        int keycode = e.get_key_code();

        if (keycode > 0 && keycode < 0x10000) {
            io.AddInputCharacter((unsigned short) keycode);
        }
        return false;
    }

    bool ImGuiLayer::on_window_resize_event(WindowResizeEvent &e) {
        ImGuiIO &io = ImGui::GetIO();
        io.DisplaySize = ImVec2(e.get_width(), e.get_height());
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        glViewport(0, 0, e.get_width(), e.get_height());
        return false;
    }
}