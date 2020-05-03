//
// Created by Leo on 4/27/2020.
//

#ifndef DALI_EVENT_H
#define DALI_EVENT_H

#include <dali/event/core.h>
#include <dali/event/app.h>
#include <dali/event/key.h>
#include <dali/event/mouse.h>

#include <functional>

namespace dali {
    /*
     * Helper class for dispatching events based on event type.
     */
    class EventDispatcher {
        template<typename T>
        using EventFn = std::function<bool(T &)>;

    public:
        EventDispatcher(Event &event)
                : m_event(event) {
        }

        template<typename T>
        bool dispatch(EventFn<T> func) {
            // dispatch only when m_event type matches T
            if (T::get_static_type() == m_event.get_type()) {
                m_event.m_handled = func(*(T *) &m_event); // cast to base class T
                return true;
            }
            return false;
        }

    private:
        Event &m_event;
    };

}
#endif //DALI_EVENT_H
