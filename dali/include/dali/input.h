//
// Created by Leo on 5/14/2020.
//

#ifndef __DALI_INPUT_H
#define __DALI_INPUT_H

#include <dali/common.h>
#include <dali/core.h>
#include <dali/key_code.h>
#include <dali/mouse_code.h>

namespace dali {
    /*
     * Input-polling.
     *
     * This is a singleton class. This class should be accessed by the static methods, which internally calls the
     * virtual methods that should be inherited by platform-specific Input classes.
     */
    class DALI_API Input {
    public:
        static inline bool is_key_pressed(KeyCode key) {
            return s_instance->_is_key_pressed(key);
        }

        static inline bool is_mouse_button_pressed(MouseCode button) {
            return s_instance->_is_mouse_button_pressed(button);
        }

        static inline std::pair<float, float> get_mouse_position() {
            return s_instance->_get_mouse_position();
        }

        static inline float get_mouse_x() {
            return s_instance->_get_mouse_x();
        }

        static inline float get_mouse_y() {
            return s_instance->_get_mouse_y();
        }

    protected:
        virtual bool _is_key_pressed(KeyCode key) = 0;

        virtual bool _is_mouse_button_pressed(MouseCode key) = 0;

        virtual std::pair<float, float> _get_mouse_position() = 0;

        virtual float _get_mouse_x() = 0;

        virtual float _get_mouse_y() = 0;

    private:
        static Input *s_instance;
    };
};

#endif //__DALI_INPUT_H
