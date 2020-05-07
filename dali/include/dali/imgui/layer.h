//
// Created by Leo on 5/3/2020.
//

#ifndef DALI_IMGUI_LAYER_H
#define DALI_IMGUI_LAYER_H

#include <dali/layer.h>
#include <dali/event.h>

namespace dali {
    class DALI_API ImGuiLayer : public Layer {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void on_attach() override;
        void on_detach() override;
        void on_update() override;
        void on_event(Event &e) override;

    private:
        bool on_mouse_button_pressed_event(MouseButtonPressedEvent &e);
        bool on_mouse_button_released_event(MouseButtonReleasedEvent &e);
        bool on_mouse_moved_event(MouseMovedEvent &e);
        bool on_mouse_scrolled_event(MouseScrolledEvent &e);
        bool on_key_pressed_event(KeyPressedEvent &e);
        bool on_key_released_event(KeyReleasedEvent &e);
        bool on_key_typed_event(KeyTypedEvent &e);
        bool on_window_resize_event(WindowResizeEvent &e);
    private:
        float m_time = 0.0f;
    };
}

#endif //DALI_IMGUI_LAYER_H
