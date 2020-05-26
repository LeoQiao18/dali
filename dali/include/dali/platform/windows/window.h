//
// Created by Leo on 4/28/2020.
//

#ifndef __DALI_PLATFORM_WINDOWS_WINDOW_H
#define __DALI_PLATFORM_WINDOWS_WINDOW_H

#include <dali/window.h>
#include <dali/renderer/context.h>

struct GLFWwindow;

namespace dali {
    class WindowsWindow : public Window {
    public:
        WindowsWindow(const WindowProps &props);

        virtual ~WindowsWindow();

        virtual void on_update() override;

        virtual unsigned int get_width() const override {
            return m_data.width;
        }

        virtual unsigned int get_height() const override {
            return m_data.height;
        }

        virtual void set_event_callback(const EventCallbackFn &callback) override {
            m_data.event_callback = callback;
        }

        virtual void set_vsync(bool enabled) override;

        virtual bool is_vsync() const override;

        virtual void *get_native_window() const override {
            return (void *) m_window;
        };

    private:
        virtual void init(const WindowProps &props);

        virtual void shutdown();

    private:
        GLFWwindow *m_window;
        GraphicsContext *m_context;

        struct WindowData {
            std::string title;
            unsigned int width;
            unsigned int height;
            bool vsync;

            EventCallbackFn event_callback;
        };

        WindowData m_data;
    };
}

#endif //__DALI_PLATFORM_WINDOWS_WINDOW_H
