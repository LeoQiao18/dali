//
// Created by Leo on 5/14/2020.
//

#ifndef __DALI_KEY_CODE_H
#define __DALI_KEY_CODE_H

namespace dali {
    typedef enum class KeyCode : uint16_t {
        // From glfw3.h
        Space = 32,
        Apostrophe = 39, /* ' */
        Comma = 44, /* , */
        Minus = 45, /* - */
        Period = 46, /* . */
        Slash = 47, /* / */

        D0 = 48, /* 0 */
        D1 = 49, /* 1 */
        D2 = 50, /* 2 */
        D3 = 51, /* 3 */
        D4 = 52, /* 4 */
        D5 = 53, /* 5 */
        D6 = 54, /* 6 */
        D7 = 55, /* 7 */
        D8 = 56, /* 8 */
        D9 = 57, /* 9 */

        Semicolon = 59, /* ; */
        Equal = 61, /* = */

        A = 65,
        B = 66,
        C = 67,
        D = 68,
        E = 69,
        F = 70,
        G = 71,
        H = 72,
        I = 73,
        J = 74,
        K = 75,
        L = 76,
        M = 77,
        N = 78,
        O = 79,
        P = 80,
        Q = 81,
        R = 82,
        S = 83,
        T = 84,
        U = 85,
        V = 86,
        W = 87,
        X = 88,
        Y = 89,
        Z = 90,

        LeftBracket = 91,  /* [ */
        Backslash = 92,  /* \ */
        RightBracket = 93,  /* ] */
        GraveAccent = 96,  /* ` */

        World1 = 161, /* non-US #1 */
        World2 = 162, /* non-US #2 */

        /* Function keys */
        Escape = 256,
        Enter = 257,
        Tab = 258,
        Backspace = 259,
        Insert = 260,
        Delete = 261,
        Right = 262,
        Left = 263,
        Down = 264,
        Up = 265,
        PageUp = 266,
        PageDown = 267,
        Home = 268,
        End = 269,
        CapsLock = 280,
        ScrollLock = 281,
        NumLock = 282,
        PrintScreen = 283,
        Pause = 284,
        F1 = 290,
        F2 = 291,
        F3 = 292,
        F4 = 293,
        F5 = 294,
        F6 = 295,
        F7 = 296,
        F8 = 297,
        F9 = 298,
        F10 = 299,
        F11 = 300,
        F12 = 301,
        F13 = 302,
        F14 = 303,
        F15 = 304,
        F16 = 305,
        F17 = 306,
        F18 = 307,
        F19 = 308,
        F20 = 309,
        F21 = 310,
        F22 = 311,
        F23 = 312,
        F24 = 313,
        F25 = 314,

        /* Keypad */
        KP0 = 320,
        KP1 = 321,
        KP2 = 322,
        KP3 = 323,
        KP4 = 324,
        KP5 = 325,
        KP6 = 326,
        KP7 = 327,
        KP8 = 328,
        KP9 = 329,
        KPDecimal = 330,
        KPDivide = 331,
        KPMultiply = 332,
        KPSubtract = 333,
        KPAdd = 334,
        KPEnter = 335,
        KPEqual = 336,

        LeftShift = 340,
        LeftControl = 341,
        LeftAlt = 342,
        LeftSuper = 343,
        RightShift = 344,
        RightControl = 345,
        RightAlt = 346,
        RightSuper = 347,
        Menu = 348
    } Key;


    inline std::ostream &operator<<(std::ostream &os, KeyCode key_code) {
        os << static_cast<int32_t>(key_code);
        return os;
    }


}

#define DALI_KEY_SPACE           ::dali::Key::Space
#define DALI_KEY_APOSTROPHE      ::dali::Key::Apostrophe    /* ' */
#define DALI_KEY_COMMA           ::dali::Key::Comma         /* , */
#define DALI_KEY_MINUS           ::dali::Key::Minus         /* - */
#define DALI_KEY_PERIOD          ::dali::Key::Period        /* . */
#define DALI_KEY_SLASH           ::dali::Key::Slash         /* / */
#define DALI_KEY_0               ::dali::Key::D0
#define DALI_KEY_1               ::dali::Key::D1
#define DALI_KEY_2               ::dali::Key::D2
#define DALI_KEY_3               ::dali::Key::D3
#define DALI_KEY_4               ::dali::Key::D4
#define DALI_KEY_5               ::dali::Key::D5
#define DALI_KEY_6               ::dali::Key::D6
#define DALI_KEY_7               ::dali::Key::D7
#define DALI_KEY_8               ::dali::Key::D8
#define DALI_KEY_9               ::dali::Key::D9
#define DALI_KEY_SEMICOLON       ::dali::Key::Semicolon     /* ; */
#define DALI_KEY_EQUAL           ::dali::Key::Equal         /* = */
#define DALI_KEY_A               ::dali::Key::A
#define DALI_KEY_B               ::dali::Key::B
#define DALI_KEY_C               ::dali::Key::C
#define DALI_KEY_D               ::dali::Key::D
#define DALI_KEY_E               ::dali::Key::E
#define DALI_KEY_F               ::dali::Key::F
#define DALI_KEY_G               ::dali::Key::G
#define DALI_KEY_H               ::dali::Key::H
#define DALI_KEY_I               ::dali::Key::I
#define DALI_KEY_J               ::dali::Key::J
#define DALI_KEY_K               ::dali::Key::K
#define DALI_KEY_L               ::dali::Key::L
#define DALI_KEY_M               ::dali::Key::M
#define DALI_KEY_N               ::dali::Key::N
#define DALI_KEY_O               ::dali::Key::O
#define DALI_KEY_P               ::dali::Key::P
#define DALI_KEY_Q               ::dali::Key::Q
#define DALI_KEY_R               ::dali::Key::R
#define DALI_KEY_S               ::dali::Key::S
#define DALI_KEY_T               ::dali::Key::T
#define DALI_KEY_U               ::dali::Key::U
#define DALI_KEY_V               ::dali::Key::V
#define DALI_KEY_W               ::dali::Key::W
#define DALI_KEY_X               ::dali::Key::X
#define DALI_KEY_Y               ::dali::Key::Y
#define DALI_KEY_Z               ::dali::Key::Z
#define DALI_KEY_LEFT_BRACKET    ::dali::Key::LeftBracket   /* [ */
#define DALI_KEY_BACKSLASH       ::dali::Key::Backslash     /* \ */
#define DALI_KEY_RIGHT_BRACKET   ::dali::Key::RightBracket  /* ] */
#define DALI_KEY_GRAVE_ACCENT    ::dali::Key::GraveAccent   /* ` */
#define DALI_KEY_WORLD_1         ::dali::Key::World1        /* non-US #1 */
#define DALI_KEY_WORLD_2         ::dali::Key::World2        /* non-US #2 */

/* Function keys */
#define DALI_KEY_ESCAPE          ::dali::Key::Escape
#define DALI_KEY_ENTER           ::dali::Key::Enter
#define DALI_KEY_TAB             ::dali::Key::Tab
#define DALI_KEY_BACKSPACE       ::dali::Key::Backspace
#define DALI_KEY_INSERT          ::dali::Key::Insert
#define DALI_KEY_DELETE          ::dali::Key::Delete
#define DALI_KEY_RIGHT           ::dali::Key::Right
#define DALI_KEY_LEFT            ::dali::Key::Left
#define DALI_KEY_DOWN            ::dali::Key::Down
#define DALI_KEY_UP              ::dali::Key::Up
#define DALI_KEY_PAGE_UP         ::dali::Key::PageUp
#define DALI_KEY_PAGE_DOWN       ::dali::Key::PageDown
#define DALI_KEY_HOME            ::dali::Key::Home
#define DALI_KEY_END             ::dali::Key::End
#define DALI_KEY_CAPS_LOCK       ::dali::Key::CapsLock
#define DALI_KEY_SCROLL_LOCK     ::dali::Key::ScrollLock
#define DALI_KEY_NUM_LOCK        ::dali::Key::NumLock
#define DALI_KEY_PRINT_SCREEN    ::dali::Key::PrintScreen
#define DALI_KEY_PAUSE           ::dali::Key::Pause
#define DALI_KEY_F1              ::dali::Key::F1
#define DALI_KEY_F2              ::dali::Key::F2
#define DALI_KEY_F3              ::dali::Key::F3
#define DALI_KEY_F4              ::dali::Key::F4
#define DALI_KEY_F5              ::dali::Key::F5
#define DALI_KEY_F6              ::dali::Key::F6
#define DALI_KEY_F7              ::dali::Key::F7
#define DALI_KEY_F8              ::dali::Key::F8
#define DALI_KEY_F9              ::dali::Key::F9
#define DALI_KEY_F10             ::dali::Key::F10
#define DALI_KEY_F11             ::dali::Key::F11
#define DALI_KEY_F12             ::dali::Key::F12
#define DALI_KEY_F13             ::dali::Key::F13
#define DALI_KEY_F14             ::dali::Key::F14
#define DALI_KEY_F15             ::dali::Key::F15
#define DALI_KEY_F16             ::dali::Key::F16
#define DALI_KEY_F17             ::dali::Key::F17
#define DALI_KEY_F18             ::dali::Key::F18
#define DALI_KEY_F19             ::dali::Key::F19
#define DALI_KEY_F20             ::dali::Key::F20
#define DALI_KEY_F21             ::dali::Key::F21
#define DALI_KEY_F22             ::dali::Key::F22
#define DALI_KEY_F23             ::dali::Key::F23
#define DALI_KEY_F24             ::dali::Key::F24
#define DALI_KEY_F25             ::dali::Key::F25

/* Keypad */
#define DALI_KEY_KP_0            ::dali::Key::KP0
#define DALI_KEY_KP_1            ::dali::Key::KP1
#define DALI_KEY_KP_2            ::dali::Key::KP2
#define DALI_KEY_KP_3            ::dali::Key::KP3
#define DALI_KEY_KP_4            ::dali::Key::KP4
#define DALI_KEY_KP_5            ::dali::Key::KP5
#define DALI_KEY_KP_6            ::dali::Key::KP6
#define DALI_KEY_KP_7            ::dali::Key::KP7
#define DALI_KEY_KP_8            ::dali::Key::KP8
#define DALI_KEY_KP_9            ::dali::Key::KP9
#define DALI_KEY_KP_DECIMAL      ::dali::Key::KPDecimal
#define DALI_KEY_KP_DIVIDE       ::dali::Key::KPDivide
#define DALI_KEY_KP_MULTIPLY     ::dali::Key::KPMultiply
#define DALI_KEY_KP_SUBTRACT     ::dali::Key::KPSubtract
#define DALI_KEY_KP_ADD          ::dali::Key::KPAdd
#define DALI_KEY_KP_ENTER        ::dali::Key::KPEnter
#define DALI_KEY_KP_EQUAL        ::dali::Key::KPEqual

#define DALI_KEY_LEFT_SHIFT      ::dali::Key::LeftShift
#define DALI_KEY_LEFT_CONTROL    ::dali::Key::LeftControl
#define DALI_KEY_LEFT_ALT        ::dali::Key::LeftAlt
#define DALI_KEY_LEFT_SUPER      ::dali::Key::LeftSuper
#define DALI_KEY_RIGHT_SHIFT     ::dali::Key::RightShift
#define DALI_KEY_RIGHT_CONTROL   ::dali::Key::RightControl
#define DALI_KEY_RIGHT_ALT       ::dali::Key::RightAlt
#define DALI_KEY_RIGHT_SUPER     ::dali::Key::RightSuper
#define DALI_KEY_MENU            ::dali::Key::Menu


#endif //__DALI_KEY_CODE_H