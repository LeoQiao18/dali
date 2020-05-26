//
// Created by Leo on 4/29/2020.
//

#include <dali/window.h>

#ifdef DALI_PLATFORM_WINDOWS

#include <dali/platform/windows/window.h>

#endif //DALI_PLATFORM_WINDOWS

namespace dali {
    Window *Window::create(const WindowProps &props) {
#ifdef DALI_PLATFORM_WINDOWS
        return new WindowsWindow(props);
#else
        DALI_CORE_ASSERT(false, "Unknown platform!");
        return nullptr;
#endif //DALI_PLATFORM_WINDOWS
    }
}
