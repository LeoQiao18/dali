//
// Created by Leo on 4/25/2020.
//
// This is a blocking event system.
//

#ifndef DALI_EVENT_COMMON_H
#define DALI_EVENT_COMMON_H

#include <dali/core.h>

#include <string>
#include <functional>

namespace dali {
    /*
     * Event types.
     */
    enum class EventType {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    /*
     * Event categories for event types.
     */
    enum EventCategory {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4)
    };


    /*
     * Abstract base class for all events.
     */
    class DALI_API Event {
        friend class EventDispatcher;

    public:
        virtual EventType get_type() const = 0;

        virtual const char *get_name() const = 0;

        virtual int get_categories() const = 0;

        virtual std::string to_string() const {
            return get_name();
        }

        inline bool is_in_category(EventCategory category) {
            return get_categories() & category;
        }

    protected:
        bool m_handled = false;
    };

    /*
     * Helpers for declaring derived Event classes.
     */
#define EVENT_CLASS_TYPE(type) static EventType get_static_type() { return EventType::##type; }\
                               virtual EventType get_type() const override { return get_static_type(); }\
                               virtual const char *get_name() const override { return #type; }
#define EVENT_CLASS_CATEGORY(category) virtual int get_categories() const override { return category; }


    /*
     * Operators for Event class.
     */
    inline std::ostream &operator<<(std::ostream &os, const Event &e) {
        return os << e.to_string();
    }

}

#endif //DALI_EVENT_COMMON_H
