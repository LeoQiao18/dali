//
// Created by Leo on 4/27/2020.
//

#ifndef __DALI_EVENT_KEY_H
#define __DALI_EVENT_KEY_H

#include <dali/event/core.h>
#include <dali/input.h>

#include <sstream>

namespace dali {
    /*
     * All key events should be derived from this class.
     * This class should not be instantiated, because it has a protected constructor.
     */
    class KeyEvent : public Event {
    public:
        KeyCode get_key_code() const {
            return m_key_code;
        }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
        KeyEvent(KeyCode key_code)
                : m_key_code(key_code) {
        }

        KeyCode m_key_code;
    };

    /*
     * KeyPressedEvent takes into account of key repeats.
     */
    class KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(KeyCode key_code, int nrepeat)
                : KeyEvent(key_code), m_nrepeat(nrepeat) {
        }

        int get_nrepeat() const {
            return m_nrepeat;
        }

        std::string to_string() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_key_code << " (" << m_nrepeat << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)

    private:
        int m_nrepeat;
    };

    class KeyReleasedEvent : public KeyEvent {
    public:
        KeyReleasedEvent(KeyCode key_code)
                : KeyEvent(key_code) {
        }

        std::string to_string() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_key_code;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };

    class KeyTypedEvent : public KeyEvent {
    public:
        KeyTypedEvent(KeyCode key_code)
                : KeyEvent(key_code) {
        }

        std::string to_string() const override {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << m_key_code;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyTyped)
    };
}

#endif //__DALI_EVENT_KEY_H
