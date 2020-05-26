//
// Created by Leo on 4/28/2020.
//

#ifndef __DALI_WINDOW_H
#define __DALI_WINDOW_H

#include <dali/common.h>
#include <dali/core.h>
#include <dali/event/core.h>

namespace dali {
    struct WindowProps {
        std::string title;
        unsigned int width;
        unsigned int height;

        explicit WindowProps(const std::string &p_title = "Dali",
                             unsigned int p_width = 1280,
                             unsigned int p_height = 720)
                : title(p_title), width(p_width), height(p_height) {
        }
    };

    class Window {
    public:
        using EventCallbackFn = std::function<void(Event &)>;

        virtual ~Window() = default;

        virtual void on_update() = 0;

        virtual unsigned int get_width() const = 0;

        virtual unsigned int get_height() const = 0;

        virtual void set_event_callback(const EventCallbackFn &callback) = 0;

        virtual void set_vsync(bool enabled) = 0;

        virtual bool is_vsync() const = 0;

        virtual void *get_native_window() const = 0;

        static Window *create(const WindowProps &props = WindowProps());
    };
}

#endif //__DALI_WINDOW_H
