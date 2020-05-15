//
// Created by Leo on 5/14/2020.
//

#ifndef __DALI_PLATFORM_WINDOWS_INPUT_H
#define __DALI_PLATFORM_WINDOWS_INPUT_H

#include <dali/input.h>

namespace dali {
    /*
     * Input-polling class for Windows.
     */
    class WindowsInput : public Input {
    protected:
        virtual bool _is_key_pressed(KeyCode key) override;
        virtual bool _is_mouse_button_pressed(MouseCode button) override;
        virtual std::pair<float, float> _get_mouse_position() override;
        virtual float _get_mouse_x() override;
        virtual float _get_mouse_y() override;
    };
}

#endif //__DALI_PLATFORM_WINDOWS_INPUT_H
