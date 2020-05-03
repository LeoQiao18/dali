//
// Created by Leo on 4/27/2020.
//

#ifndef DALI_MOUSE_H
#define DALI_MOUSE_H

#include <dali/event/core.h>

#include <sstream>

namespace dali {
    class MouseMovedEvent : public Event {
    public:
        MouseMovedEvent(float x, float y)
                : m_x(x), m_y(y) {
        }

        inline float get_x() const {
            return m_x;
        }

        inline float get_y() const {
            return m_y;
        }

        inline std::string to_string() const override {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_x << " ," << m_y;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_x;
        float m_y;
    };

    class MouseScrolledEvent : public Event {
    public:
        MouseScrolledEvent(float x_offset, float y_offset)
                : m_x_offset(x_offset), m_y_offset(y_offset) {
        }

        inline float get_x_offset() const {
            return m_x_offset;
        }

        inline float get_y_offset() const {
            return m_y_offset;
        }

        inline std::string to_string() const override {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << get_x_offset() << ", " << get_y_offset();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_x_offset;
        float m_y_offset;
    };

    /*
     * Base class for MouseButtonPressedEvent and MouseButtonReleasedEvent.
     */
    class MouseButtonEvent : public Event {
    public:
        inline int get_mouse_button() const {
            return m_button;
        }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    protected:
        MouseButtonEvent(int button)
                : m_button(button) {}

        int m_button;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent {
    public:
        MouseButtonPressedEvent(int button)
                : MouseButtonEvent(button) {}

        std::string to_string() const override {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent {
    public:
        MouseButtonReleasedEvent(int button)
                : MouseButtonEvent(button) {}

        std::string to_string() const override {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };

}

#endif //DALI_MOUSE_H
