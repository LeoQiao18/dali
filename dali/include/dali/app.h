//
// Created by Leo on 4/23/2020.
//

#ifndef DALI_APP_H
#define DALI_APP_H

#include <dali/core.h>
#include <dali/common.h>
#include <dali/window.h>
#include <dali/event.h>
#include <dali/layer.h>

namespace dali {

    class DALI_API App {
    public:
        App();

        virtual ~App();

        void run();

        void on_event(Event &e);

        bool on_window_close(WindowCloseEvent &e);

        void push_layer(Layer *layer);

        void push_overlay(Layer *layer);

    private:
        std::unique_ptr<Window> m_window;
        LayerStack m_layer_stack;
        bool m_running = true;
    };

    // This function should be defined in client application
    App *create_app();

}

#endif //DALI_APP_H
