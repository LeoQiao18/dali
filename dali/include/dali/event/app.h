//
// Created by Leo on 4/27/2020.
//

#ifndef __DALI_EVENT_APP_H
#define __DALI_EVENT_APP_H

#include <dali/event/core.h>

#include <sstream>

namespace dali {
    class WindowResizeEvent : public Event {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
                : m_width(width), m_height(height) {
        }

        unsigned int get_width() const {
            return m_width;
        }

        unsigned int get_height() const {
            return m_height;
        }

        virtual std::string to_string() const override {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_width << ", " << m_height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)

        EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
        unsigned int m_width;
        unsigned int m_height;
    };

    class WindowCloseEvent : public Event {
    public:
        WindowCloseEvent() = default;

        EVENT_CLASS_TYPE(WindowClose)

        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class AppTickEvent : public Event {
    public:
        AppTickEvent() = default;

        EVENT_CLASS_TYPE(AppTick)

        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };


    class AppUpdateEvent : public Event {
    public:
        AppUpdateEvent() = default;

        EVENT_CLASS_TYPE(AppUpdate)

        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class AppRenderEvent : public Event {
    public:
        AppRenderEvent() = default;

        EVENT_CLASS_TYPE(AppRender)

        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}


#endif //__DALI_EVENT_APP_H
