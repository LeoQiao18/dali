//
// Created by Leo on 5/14/2020.
//

#ifndef DALI_MOUSE_CODE_H
#define DALI_MOUSE_CODE_H

#include <dali/common.h>

typedef enum class MouseCode : uint16_t {
    // From glfw3.h
    Button0 = 0,
    Button1 = 1,
    Button2 = 2,
    Button3 = 3,
    Button4 = 4,
    Button5 = 5,
    Button6 = 6,
    Button7 = 7,

    ButtonLast = Button7,
    ButtonLeft = Button0,
    ButtonRight = Button1,
    ButtonMiddle = Button2
} Mouse;

inline std::ostream &operator<<(std::ostream &os, MouseCode mouse_code) {
    os << static_cast<int32_t>(mouse_code);
    return os;
}

/*
 * Mouse button macros.
 */
#define DALI_MOUSE_BUTTON_0      ::dali::Mouse::Button0
#define DALI_MOUSE_BUTTON_1      ::dali::Mouse::Button1
#define DALI_MOUSE_BUTTON_2      ::dali::Mouse::Button2
#define DALI_MOUSE_BUTTON_3      ::dali::Mouse::Button3
#define DALI_MOUSE_BUTTON_4      ::dali::Mouse::Button4
#define DALI_MOUSE_BUTTON_5      ::dali::Mouse::Button5
#define DALI_MOUSE_BUTTON_6      ::dali::Mouse::Button6
#define DALI_MOUSE_BUTTON_7      ::dali::Mouse::Button7
#define DALI_MOUSE_BUTTON_LAST   ::dali::Mouse::ButtonLast
#define DALI_MOUSE_BUTTON_LEFT   ::dali::Mouse::ButtonLeft
#define DALI_MOUSE_BUTTON_RIGHT  ::dali::Mouse::ButtonRight
#define DALI_MOUSE_BUTTON_MIDDLE ::dali::Mouse::ButtonMiddle

#endif //DALI_MOUSE_CODE_H
