//
// Created by Leo on 4/23/2020.
//

#ifndef __DALI_APP_H
#define __DALI_APP_H

#include <dali/core.h>
#include <dali/common.h>
#include <dali/window.h>
#include <dali/event.h>
#include <dali/layer.h>
#include <dali/imgui/layer.h>

#include <dali/renderer/shader.h>
#include <dali/renderer/buffer.h>

namespace dali {

    class App {
    public:
        App();

        virtual ~App();

        void run();

        void on_event(Event &e);

        bool on_window_close(WindowCloseEvent &e);

        void push_layer(Layer *layer);

        void push_overlay(Layer *layer);

        Window &get_window() {
            return *m_window;
        }

        static App &get() {
            return *s_instance;
        }

    private:
        std::unique_ptr<Window> m_window;
        ImGuiLayer *m_imgui_layer;
        LayerStack m_layer_stack;
        bool m_running = true;

        /* OpenGL first triangle */
        unsigned int m_vertex_array;

        std::unique_ptr<Shader> m_shader;
        std::unique_ptr<VertexBuffer> m_vbo;
        std::unique_ptr<IndexBuffer> m_ibo;

    private:
        static App *s_instance;
    };

    // This function should be defined in client application
    App *create_app();

}

#endif //__DALI_APP_H
