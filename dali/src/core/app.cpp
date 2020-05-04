//
// Created by Leo on 4/23/2020.
//

#include <dali/app.h>
#include <dali/common.h>
#include <dali/event.h>

#include <glad/glad.h>

namespace dali {

    App::App() {
        m_window = std::unique_ptr<Window>(Window::create());
        m_window->set_event_callback(std::bind(&App::on_event, this, std::placeholders::_1));
    }

    App::~App() {

    }

    void App::run() {
        while (m_running) {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            for (Layer *layer : m_layer_stack) {
                layer->on_update();
            }

            m_window->on_update();
        }
    }

    void App::on_event(Event &e) {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<WindowCloseEvent>(std::bind(&App::on_window_close, this, std::placeholders::_1));

        for (auto it = m_layer_stack.rbegin(); it != m_layer_stack.rend(); ++it) {
            (*it)->on_event(e);

            if (e.m_handled) {
                break;
            }
        }
    }

    bool App::on_window_close(WindowCloseEvent &e) {
        m_running = false;
        return true;
    }

    void App::push_layer(Layer *layer) {
        m_layer_stack.push_layer(layer);
    }

    void App::push_overlay(Layer *layer) {
        m_layer_stack.push_overlay(layer);
    }

}
